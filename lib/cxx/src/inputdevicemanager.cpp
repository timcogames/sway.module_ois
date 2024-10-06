#include <sway/ois/inputdevicemanager.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

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

auto createInputDeviceManager() -> InputDeviceManager::JavaScriptPtr_t {
  return InputDeviceManager::toJs(new InputDeviceManager());
}

#endif

NS_END()  // namespace ois
NS_END()  // namespace sway
