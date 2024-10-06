#ifndef SWAY_OIS_INPUTACTIONSTATES_HPP
#define SWAY_OIS_INPUTACTIONSTATES_HPP

#include <sway/core.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

enum class InputActionState : u32_t { PRESSED, RELEASED };

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_INPUTACTIONSTATES_HPP
