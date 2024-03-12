#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois.hpp>
#include <sway/ois/mac/dtpkeyboard.hpp>
#include <sway/ois/mac/dtpkeymappinglist.hpp>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <memory>  // std::shared_ptr, std::make_shared

using namespace sway;

class KeyboardInputListener : public ois::InputListener {
public:
  KeyboardInputListener() = default;

  virtual ~KeyboardInputListener() = default;

  MTHD_VIRTUAL(void onKeyPressed(const ois::KeyboardEventParams &params)) { std::cout << params.keyCode << std::endl; }

  MTHD_VIRTUAL(void onKeyReleased(const ois::KeyboardEventParams &params)) {}
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  auto inputDeviceMngr = std::make_shared<ois::InputDeviceManager>(/*nullptr, 0*/);
  inputDeviceMngr->registerDevice<ois::DTPKeyboard>();

  auto keyboardInputListener = std::make_shared<KeyboardInputListener>();
  auto keyboardInputDevice = inputDeviceMngr->getDevice<ois::DTPKeyboard>();
  keyboardInputDevice->setListener(keyboardInputListener.get());

  Display *dpy = XOpenDisplay(nullptr);
  if (dpy == nullptr) {
    fprintf(stderr, "Cannot open display\n");
    exit(1);
  }

  auto scr = DefaultScreen(dpy);
  auto win =
      XCreateSimpleWindow(dpy, RootWindow(dpy, scr), 10, 10, 660, 200, 1, BlackPixel(dpy, scr), WhitePixel(dpy, scr));
  XSelectInput(dpy, win, ExposureMask | KeyPressMask);
  XMapWindow(dpy, win);

  XStoreName(dpy, win, "sway.module_ois-x11");

  auto WM_DELETE_WINDOW = XInternAtom(dpy, "WM_DELETE_WINDOW", False);
  XSetWMProtocols(dpy, win, &WM_DELETE_WINDOW, 1);

  XEvent evt;
  while (1) {
    XNextEvent(dpy, &evt);
    XClearWindow(dpy, win);

    // if (evt.type == Expose || evt.type == LeaveNotify) {
    auto offset = math::point2i_t(10, 20);

    lpcstr_t heading = "Keyboard Input Device";
    XDrawString(dpy, win, DefaultGC(dpy, scr), offset.getX(), offset.getY(), heading, strlen(heading));
    offset.setY(offset.getY() + 20);  // next

    lpcstr_t kcHeading = "Key code";
    XDrawString(dpy, win, DefaultGC(dpy, scr), offset.getX(), offset.getY(), kcHeading, strlen(kcHeading));
    // }

    if (evt.type == KeyPress) {
      lpcstr_t kc = "";
      offset = math::point2i_t(80, offset.getY());

      keyboardInputDevice->notifyKeyPressed(evt);

      KeySym sym = NoSymbol;
      XLookupString((XKeyEvent *)&evt.xkey, 0, 0, &sym, 0);

      for (const ois::KeyMapping &mapping : ois::XtoKeyCode) {
        if (mapping.symbol == sym) {
          kc = std::to_string(core::detail::toUnderlying(mapping.code)).c_str();
          XDrawString(dpy, win, DefaultGC(dpy, scr), offset.getX(), offset.getY(), kc, strlen(kc));
          XSync(dpy, False);
        }
      }
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
