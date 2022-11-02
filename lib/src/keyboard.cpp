#include <sway/ois/inputdevicemanager.hpp>
#include <sway/ois/keyboard.hpp>
#include <sway/ois/keyboardeventargs.hpp>
#include <sway/ois/keymappinglist.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

Keyboard::Keyboard(InputDeviceManager *manager)
    : manager_(manager)
    , listener_(NULL)
    , keyboardGrabbed_(false) {
  initialize_();
}

Keyboard::~Keyboard() {
  // enableSystemKeys_();
  manager_->setKeyboardUsed(false);
}

void Keyboard::initialize_() {
  // disableSystemKeys_();
  manager_->setKeyboardUsed(true);
}

void Keyboard::disableSystemKeys_() {
  int err = XGrabKeyboard(
      manager_->getDisplay(), manager_->getWindowHandle(), True, GrabModeAsync, GrabModeAsync, CurrentTime);
  if (err != GrabSuccess) {
    keyboardGrabbed_ = true;
  }
}

void Keyboard::enableSystemKeys_() {
  if (keyboardGrabbed_) {
    XUngrabKeyboard(manager_->getDisplay(), CurrentTime);
    keyboardGrabbed_ = false;
  }
}

void Keyboard::setListener(InputListener *listener) { listener_ = listener; }

void Keyboard::notifyKeyPressed(const XEvent &event) {
  if (!listener_) {
    return;
  }

  KeySym key = NoSymbol;
  XLookupString((XKeyEvent *)&event.xkey, 0, 0, &key, 0);

  for (const KeyMapping &mapping : XtoKeycode) {
    if (mapping.keysym == key) {
      listener_->onKeyPressed(KeyboardEventArgs(mapping.keycode));
    }
  }
}

void Keyboard::notifyKeyReleased(const XEvent &event) {
  if (!listener_) {
    return;
  }

  KeySym key = NoSymbol;
  XLookupString((XKeyEvent *)&event.xkey, 0, 0, &key, 0);

  for (const KeyMapping &mapping : XtoKeycode) {
    if (mapping.keysym == key) {
      listener_->onKeyReleased(KeyboardEventArgs(mapping.keycode));
    }
  }
}

NAMESPACE_END(ois)
NAMESPACE_END(sway)
