#include <sway/ois/inputdevicemanager.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

InputDeviceManager::InputDeviceManager(void *display, u32_t window)
    : display_(static_cast<Display *>(display))
    , window_(static_cast<Window>(window))
    , keyboardUsed_(false)
    , mouseUsed_(false) {
  // Empty
}

InputDeviceManager::~InputDeviceManager() {
  // Empty
}

bool InputDeviceManager::hasFreeDevice(InputDeviceType_t type) {
  switch (type) {
    case InputDeviceType_t::kKeyboard:
      return keyboardUsed_;
    case InputDeviceType_t::kMouse:
      return mouseUsed_;
    default:
      return 0;
  }
}

void InputDeviceManager::setKeyboardUsed(bool used) { keyboardUsed_ = used; }

void InputDeviceManager::setMouseUsed(bool used) { mouseUsed_ = used; }

Display *InputDeviceManager::getDisplay() const { return display_; }

Window InputDeviceManager::getWindowHandle() const { return window_; }

NAMESPACE_END(ois)
NAMESPACE_END(sway)
