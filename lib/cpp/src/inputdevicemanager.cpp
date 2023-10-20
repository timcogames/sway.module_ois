#include <sway/ois/inputdevicemanager.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

InputDeviceManager::InputDeviceManager()
    : keyboardUsed_(false)
    , mouseUsed_(false) {}

auto InputDeviceManager::hasFreeDevice(InputDeviceType type) -> bool {
  switch (type) {
    case InputDeviceType::KEYBOARD:
      return keyboardUsed_;
    case InputDeviceType::MOUSE:
      return mouseUsed_;
    default:
      return 0;
  }
}

void InputDeviceManager::setKeyboardUsed(bool used) { keyboardUsed_ = used; }

void InputDeviceManager::setMouseUsed(bool used) { mouseUsed_ = used; }

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)

auto createInputDeviceManager() -> InputDeviceManager::JsPtr_t {
  return InputDeviceManager::toJs(new InputDeviceManager());
}

#endif

NAMESPACE_END(ois)
NAMESPACE_END(sway)
