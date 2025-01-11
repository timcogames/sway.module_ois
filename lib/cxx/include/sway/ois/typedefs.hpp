#ifndef SWAY_OIS_TYPEDEFS_HPP
#define SWAY_OIS_TYPEDEFS_HPP

#include <sway/core.hpp>

#include <functional>
#include <unordered_map>

namespace sway::ois {

class InputDevice;

class InputDeviceManager;

class InputListener;

class InputEventListener;

class KeyEvent;

class MouseEvent;

namespace typedefs {

using InputDeviceSharedPtr_t = std::shared_ptr<InputDevice>;

using InputDeviceContainer_t = std::unordered_map<u32_t, InputDeviceSharedPtr_t>;

using InputDeviceManagerPtr_t = InputDeviceManager *;

using InputDeviceManagerSharedPtr_t = std::shared_ptr<InputDeviceManager>;

using InputListenerPtr_t = InputListener *;

using InputEventListenerPtr_t = InputEventListener *;

using KeyEventPtr_t = KeyEvent *;

using MouseEventPtr_t = MouseEvent *;

}  // namespace typedefs

using InputDeviceCreator_t = std::function<typedefs::InputDeviceSharedPtr_t()>;

using InputDeviceFactory_t = std::unordered_map<u32_t, InputDeviceCreator_t>;

using KeyboardEventCallbackFunc_t = std::function<void(const struct KeyboardEventParams &)>;

using MouseEventCallbackFunc_t = std::function<void(const struct MouseEventParams &)>;

}  // namespace sway::ois

#endif  // SWAY_OIS_TYPEDEFS_HPP
