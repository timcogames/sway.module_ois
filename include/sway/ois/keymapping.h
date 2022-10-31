#ifndef SWAY_OIS_KEYMAPPING_H
#define SWAY_OIS_KEYMAPPING_H

#include <sway/ois/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

struct KeyMapping {
  KeySym keysym;
  u32_t keycode;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYMAPPING_H
