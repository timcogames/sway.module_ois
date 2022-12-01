#include <sway/ois/inputdevicemanager.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

InputDeviceManager::InputDeviceManager(void *display, u32_t window)
    : display_(static_cast<Display *>(display))
    , window_(static_cast<Window>(window))
    , keyboardUsed_(false)
    , mouseUsed_(false) {
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

auto InputDeviceManager::getDisplay() const -> Display * { return display_; }

auto InputDeviceManager::getWindowHandle() const -> Window { return window_; }

NAMESPACE_END(ois)
NAMESPACE_END(sway)
