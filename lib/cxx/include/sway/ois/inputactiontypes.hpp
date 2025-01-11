#ifndef SWAY_OIS_INPUTACTIONTYPES_HPP
#define SWAY_OIS_INPUTACTIONTYPES_HPP

#include <sway/core.hpp>

namespace sway::ois {

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

}  // namespace sway::ois

#endif  // SWAY_OIS_INPUTACTIONTYPES_HPP
