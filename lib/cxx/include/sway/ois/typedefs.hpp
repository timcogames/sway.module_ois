#ifndef SWAY_OIS_TYPEDEFS_HPP
#define SWAY_OIS_TYPEDEFS_HPP

#include <sway/core.hpp>

#include <functional>
#include <unordered_map>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

DECLARE_CLASS_POINTER_TYPES(InputDevice)
DECLARE_CLASS_POINTER_TYPES(InputDeviceManager)
DECLARE_CLASS_POINTER_TYPES(InputEventListener)
DECLARE_CLASS_POINTER_TYPES(InputListener)
DECLARE_CLASS_POINTER_TYPES(KeyEvent)
DECLARE_CLASS_POINTER_TYPES(MouseEvent)
DECLARE_CLASS_POINTER_TYPES(DTPKeyboard)
DECLARE_CLASS_POINTER_TYPES(DTPMouse)

using InputDeviceCreator_t = std::function<InputDeviceSharedPtr_t()>;
using InputDeviceFactory_t = std::unordered_map<u32_t, InputDeviceCreator_t>;

using KeyboardEventCallbackFunc_t = std::function<void(const struct KeyboardEventParams &)>;
using MouseEventCallbackFunc_t = std::function<void(const struct MouseEventParams &)>;

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_TYPEDEFS_HPP
