#ifndef SWAY_OIS_MOUSEBUTTONCODES_HPP
#define SWAY_OIS_MOUSEBUTTONCODES_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

enum class MouseButtonCode { LMB, RMB, MMB, MB4, MB5, OTHER, Latest };

#define NUM_MOUSE_BTNS (core::detail::toUnderlying(MouseButtonCode::Latest) - 1)

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_MOUSEBUTTONCODES_HPP
