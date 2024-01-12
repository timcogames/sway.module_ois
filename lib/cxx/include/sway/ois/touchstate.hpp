#ifndef SWAY_OIS_TOUCHSTATE_HPP
#define SWAY_OIS_TOUCHSTATE_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

struct TouchState {
  uintptr_t id;
  math::vec2f_t pos;
  math::vec2f_t dpos;
  InputButtonState state;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_TOUCHSTATE_HPP
