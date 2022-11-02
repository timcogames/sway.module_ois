#ifndef SWAY_OIS_KEYMAPPING_HPP
#define SWAY_OIS_KEYMAPPING_HPP

#include <sway/ois/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

struct KeyMapping {
  KeySym keysym;
  u32_t keycode;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYMAPPING_HPP
