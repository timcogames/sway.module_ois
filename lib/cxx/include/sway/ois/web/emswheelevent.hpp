#ifndef SWAY_OIS_WEB_EMSWHEELEVENT_HPP
#define SWAY_OIS_WEB_EMSWHEELEVENT_HPP

#include <sway/core.hpp>
#include <sway/ois/_stdafx.hpp>

namespace sway::ois {

#ifdef EMSCRIPTEN_PLATFORM

using EMSWheelEvent = EmscriptenWheelEvent;

#else

struct EMSWheelEvent {
  f64_t deltaY;
};

#endif

}  // namespace sway::ois

#endif  // SWAY_OIS_WEB_EMSWHEELEVENT_HPP
