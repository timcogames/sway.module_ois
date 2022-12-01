#include <sway/core.hpp>
#include <sway/ois.hpp>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <memory>  // std::shared_ptr, std::make_shared

using namespace sway;

class KeyboardInputListener : public ois::InputListener {
public:
  KeyboardInputListener() = default;

  virtual ~KeyboardInputListener() = default;

  MTHD_OVERRIDE(void onKeyPressed(const ois::KeyboardEventArgs &evt)) { std::cout << evt.keycode << std::endl; }

  MTHD_OVERRIDE(void onKeyReleased(const ois::KeyboardEventArgs &evt)) {}
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  auto inputDeviceManager = std::make_shared<ois::InputDeviceManager>(nullptr, 0);
  inputDeviceManager->registerDevice<ois::Keyboard>();

  auto keyboardInputListener = std::make_shared<KeyboardInputListener>();
  auto keyboardInputDevice = inputDeviceManager->getDevice<ois::Keyboard>();
  keyboardInputDevice->setListener(keyboardInputListener.get());

  Display *dpy = XOpenDisplay(NULL);
  if (dpy == NULL) {
    fprintf(stderr, "Cannot open display\n");
    exit(1);
  }

  int scr = DefaultScreen(dpy);
  Window win =
      XCreateSimpleWindow(dpy, RootWindow(dpy, scr), 10, 10, 660, 200, 1, BlackPixel(dpy, scr), WhitePixel(dpy, scr));
  XSelectInput(dpy, win, ExposureMask | KeyPressMask);
  XMapWindow(dpy, win);

  XStoreName(dpy, win, "sway.module_ois-x11");

  Atom WM_DELETE_WINDOW = XInternAtom(dpy, "WM_DELETE_WINDOW", False);
  XSetWMProtocols(dpy, win, &WM_DELETE_WINDOW, 1);

  XEvent evt;
  while (1) {
    XNextEvent(dpy, &evt);
    if (evt.type == Expose) {
      int x_offset = 10;
      int y_offset = 20;

      lpcstr_t heading = "Keyboard Input Device";
      XDrawString(dpy, win, DefaultGC(dpy, scr), x_offset, y_offset, heading, strlen(heading));
      y_offset += 20;  // next
    }

    if (evt.type == KeyPress) {
      keyboardInputDevice->notifyKeyPressed(evt);
    }

    if (evt.type == KeyRelease) {
      keyboardInputDevice->notifyKeyReleased(evt);
    }

    if ((evt.type == ClientMessage) && (static_cast<u32_t>(evt.xclient.data.l[0]) == WM_DELETE_WINDOW)) {
      break;
    }
  }

  XDestroyWindow(dpy, win);
  XCloseDisplay(dpy);
  return 0;
}
