#ifndef SWAY_OIS_KEYMODIFIERS_HPP
#define SWAY_OIS_KEYMODIFIERS_HPP

#include <sway/core.hpp>

namespace sway::ois {

enum class KeyModifier : u32_t { CTRL = (1 << 0), SHIFT = (1 << 1), ALT = (1 << 2) };

}  // namespace sway::ois

#endif  // SWAY_OIS_KEYMODIFIERS_HPP
