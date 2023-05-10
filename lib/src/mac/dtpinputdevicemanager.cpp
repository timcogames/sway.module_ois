#include <sway/ois/mac/dtpinputdevicemanager.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

DTPInputDeviceManager::DTPInputDeviceManager(void *display, u32_t window)
    : display_(static_cast<Display *>(display))
    , window_(static_cast<Window>(window))
    , keyboardUsed_(false)
    , mouseUsed_(false) {
  // Empty
}

auto DTPInputDeviceManager::hasFreeDevice(InputDeviceType type) -> bool {
  switch (type) {
    case InputDeviceType::KEYBOARD:
      return keyboardUsed_;
    case InputDeviceType::MOUSE:
      return mouseUsed_;
    default:
      return 0;
  }
}

void DTPInputDeviceManager::setKeyboardUsed(bool used) { keyboardUsed_ = used; }

void DTPInputDeviceManager::setMouseUsed(bool used) { mouseUsed_ = used; }

auto DTPInputDeviceManager::getDisplay() const -> Display * { return display_; }

auto DTPInputDeviceManager::getWindowHandle() const -> Window { return window_; }

NAMESPACE_END(ois)
NAMESPACE_END(sway)
