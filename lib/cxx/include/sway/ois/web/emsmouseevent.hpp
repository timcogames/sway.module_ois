#ifndef SWAY_OIS_WEB_EMSMOUSEEVENT_HPP
#define SWAY_OIS_WEB_EMSMOUSEEVENT_HPP

#include <sway/core.hpp>
#include <sway/ois/_stdafx.hpp>

namespace sway::ois {

#ifdef EMSCRIPTEN_PLATFORM

using EMSMouseEvent = EmscriptenMouseEvent;

#else

struct EMSMouseEvent {
  u16_t button;
  i64_t targetX;
  i64_t targetY;
  i64_t movementX;
  i64_t movementY;
  i32_t ctrlKey;
  i32_t shiftKey;
  i32_t altKey;
};

#endif

}  // namespace sway::ois

#endif  // SWAY_OIS_WEB_EMSMOUSEEVENT_HPP
