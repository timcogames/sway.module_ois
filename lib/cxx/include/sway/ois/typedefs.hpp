#ifndef SWAY_OIS_TYPEDEFS_HPP
#define SWAY_OIS_TYPEDEFS_HPP

#include <sway/core.hpp>

#include <functional>  // std::function
#include <memory>  // std::shared_ptr
#include <unordered_map>  // std::unordered_map

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

using InputDeviceManagerRef_t = std::shared_ptr<class DTPInputDeviceManager>;
using InputDeviceRef_t = std::shared_ptr<class InputDevice>;
using KeyboardRef_t = std::shared_ptr<class DTPKeyboard>;
using MouseRef_t = std::shared_ptr<class DTPMouse>;

using InputDeviceCreator_t = std::function<InputDeviceRef_t()>;
using InputDeviceFactory_t = std::unordered_map<u32_t, InputDeviceCreator_t>;

using KeyboardEventCallbackFunc_t = std::function<void(const struct KeyboardEventParams &)>;
using MouseEventCallbackFunc_t = std::function<void(const struct MouseEventParams &)>;

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_TYPEDEFS_HPP
