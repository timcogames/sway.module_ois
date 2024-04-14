#ifndef SWAY_OIS_MOUSEFILTERS_HPP
#define SWAY_OIS_MOUSEFILTERS_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

enum class MouseFilter { IGNORE, STOP, PASS, Latest };

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_MOUSEFILTERS_HPP
