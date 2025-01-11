#ifndef SWAY_OIS_MOUSEBUTTONCODES_HPP
#define SWAY_OIS_MOUSEBUTTONCODES_HPP

#include <sway/core.hpp>

namespace sway::ois {

enum class MouseButtonCode { LMB, RMB, MMB, MB4, MB5, OTHER, Latest };

#define NUM_MOUSE_BTNS (core::toBase(MouseButtonCode::Latest) - 1)

}  // namespace sway::ois

#endif  // SWAY_OIS_MOUSEBUTTONCODES_HPP
