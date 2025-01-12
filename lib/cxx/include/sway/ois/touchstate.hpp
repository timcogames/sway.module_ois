#ifndef SWAY_OIS_TOUCHSTATE_HPP
#define SWAY_OIS_TOUCHSTATE_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>

namespace sway::ois {

struct TouchState {
  uptr_t id;
  math::vec2f_t pos;
  math::vec2f_t dpos;
  InputActionState state;
};

}  // namespace sway::ois

#endif  // SWAY_OIS_TOUCHSTATE_HPP
