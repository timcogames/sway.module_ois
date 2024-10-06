#ifndef SWAY_OIS_MOUSEBUTTONCODES_HPP
#define SWAY_OIS_MOUSEBUTTONCODES_HPP

#include <sway/core.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

enum class MouseButtonCode { LMB, RMB, MMB, MB4, MB5, OTHER, Latest };

#define NUM_MOUSE_BTNS (core::detail::toBase(MouseButtonCode::Latest) - 1)

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_MOUSEBUTTONCODES_HPP
