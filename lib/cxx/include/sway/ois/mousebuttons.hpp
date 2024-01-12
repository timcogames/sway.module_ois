#ifndef SWAY_OIS_MOUSEBUTTONS_HPP
#define SWAY_OIS_MOUSEBUTTONS_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

enum class MouseButton { LEFT, RIGHT, MIDDLE, BACK, FORWARD, OTHER, Latest };

#define NUM_MOUSE_BTNS (core::detail::toUnderlying(MouseButton::Latest) - 1)

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_MOUSEBUTTONS_HPP
