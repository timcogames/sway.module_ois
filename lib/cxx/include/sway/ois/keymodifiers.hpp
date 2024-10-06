#ifndef SWAY_OIS_KEYMODIFIERS_HPP
#define SWAY_OIS_KEYMODIFIERS_HPP

#include <sway/core.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

enum class KeyModifier : u32_t { CTRL = (1 << 0), SHIFT = (1 << 1), ALT = (1 << 2) };

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_KEYMODIFIERS_HPP
