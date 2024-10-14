#ifndef SWAY_OIS_TYPEDEFS_HPP
#define SWAY_OIS_TYPEDEFS_HPP

#include <sway/core.hpp>

#include <functional>
#include <unordered_map>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

DECLARE_PTR_TYPES(InputDevice)
DECLARE_PTR_TYPES(InputDeviceManager)
DECLARE_PTR_TYPES(InputEventListener)
DECLARE_PTR_TYPES(InputListener)
DECLARE_PTR_TYPES(KeyEvent)
DECLARE_PTR_TYPES(MouseEvent)
DECLARE_PTR_TYPES(DTPKeyboard)
DECLARE_PTR_TYPES(DTPMouse)

using InputDeviceCreator_t = std::function<InputDeviceSharedPtr_t()>;
using InputDeviceFactory_t = std::unordered_map<u32_t, InputDeviceCreator_t>;

using KeyboardEventCallbackFunc_t = std::function<void(const struct KeyboardEventParams &)>;
using MouseEventCallbackFunc_t = std::function<void(const struct MouseEventParams &)>;

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_TYPEDEFS_HPP
