#ifndef SWAY_OIS_KEYMODIFIERS_HPP
#define SWAY_OIS_KEYMODIFIERS_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

enum class KeyModifier : u32_t { CTRL = (1 << 0), SHIFT = (1 << 1), ALT = (1 << 2) };

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYMODIFIERS_HPP
