#ifndef SWAY_OIS_INPUTACTIONTYPES_HPP
#define SWAY_OIS_INPUTACTIONTYPES_HPP

#include <sway/core.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

enum class InputActionType : u32_t {
  UNKNOWN = 0,
  KEY,
  MOUSE_BUTTON,
  MOUSE_DRAGGED,
  MOUSE_MOVED,
  MOUSE_ENTERED,
  MOUSE_EXITED,
  MOUSE_WHEEL,
  Latest
};

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_INPUTACTIONTYPES_HPP
