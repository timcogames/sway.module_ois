#ifndef SWAY_OIS_MOUSEFILTERS_HPP
#define SWAY_OIS_MOUSEFILTERS_HPP

#include <sway/core.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

enum class MouseFilter { IGNORE, STOP, PASS, Latest };

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_MOUSEFILTERS_HPP
