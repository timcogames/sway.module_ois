#ifndef SWAY_OIS_TOUCHSTATE_HPP
#define SWAY_OIS_TOUCHSTATE_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

struct TouchState {
  uintptr_t id;
  math::vec2f_t pos;
  math::vec2f_t dpos;
  InputActionState state;
};

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_TOUCHSTATE_HPP
