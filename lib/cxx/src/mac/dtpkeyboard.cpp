#include <sway/ois/inputdevicemanager.hpp>
#include <sway/ois/keyboardeventargs.hpp>
#include <sway/ois/mac/dtpkeyboard.hpp>
#include <sway/ois/mac/dtpkeymappinglist.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

DTPKeyboard::DTPKeyboard(InputDeviceManager *mngr)
    : manager_(mngr)
    , listener_(nullptr)
    , keyboardGrabbed_(false) {
  initialize_();
}

DTPKeyboard::~DTPKeyboard() {
  // enableSystemKeys_();
  manager_->setKeyboardUsed(false);
}

void DTPKeyboard::initialize_() {
  // disableSystemKeys_();
  manager_->setKeyboardUsed(true);
}

void DTPKeyboard::disableSystemKeys_() {
  // int const err = XGrabKeyboard(
  //     manager_->getDisplay(), manager_->getWindowHandle(), True, GrabModeAsync, GrabModeAsync, CurrentTime);
  // if (err != GrabSuccess) {
  //   keyboardGrabbed_ = true;
  // }
}

void DTPKeyboard::enableSystemKeys_() {
  // if (keyboardGrabbed_) {
  //   XUngrabKeyboard(manager_->getDisplay(), CurrentTime);
  //   keyboardGrabbed_ = false;
  // }
}

void DTPKeyboard::setListener(InputListener *listener) { listener_ = listener; }

void DTPKeyboard::notifyKeyPressed(const XEvent &evt) {
  if (listener_ == nullptr) {
    return;
  }

  KeySym sym = NoSymbol;
  XLookupString((XKeyEvent *)&evt.xkey, 0, 0, &sym, 0);

  for (const KeyMapping &mapping : XtoKeyCode) {
    if (mapping.symbol == sym) {
      // listener_->onKeyPressed(KeyboardEventArgs(core::detail::toUnderlying(mapping.code)));
    }
  }
}

void DTPKeyboard::notifyKeyReleased(const XEvent &evt) {
  if (listener_ == nullptr) {
    return;
  }

  KeySym sym = NoSymbol;
  XLookupString((XKeyEvent *)&evt.xkey, 0, 0, &sym, 0);

  for (const KeyMapping &mapping : XtoKeyCode) {
    if (mapping.symbol == sym) {
      // listener_->onKeyReleased(KeyboardEventArgs(core::detail::toUnderlying(mapping.code)));
    }
  }
}

NAMESPACE_END(ois)
NAMESPACE_END(sway)
