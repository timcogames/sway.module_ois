#ifndef SWAY_OIS_INPUTACTIONTYPES_HPP
#define SWAY_OIS_INPUTACTIONTYPES_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

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

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTACTIONTYPES_HPP