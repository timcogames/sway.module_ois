#ifndef SWAY_OIS_KEYMAPPING_HPP
#define SWAY_OIS_KEYMAPPING_HPP

#include <sway/ois/keycodes.hpp>
#include <sway/ois/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

struct KeyMapping {
  KeySym symbol;
  KeyCode code;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYMAPPING_HPP
