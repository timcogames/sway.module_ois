#ifndef SWAY_OIS_KEYMAPPING_HPP
#define SWAY_OIS_KEYMAPPING_HPP

#include <sway/ois/_stdafx.hpp>
#include <sway/ois/keycodes.hpp>

namespace sway::ois {

struct KeyMapping {
  KeySym symbol;
  KeyCode code;
};

}  // namespace sway::ois

#endif  // SWAY_OIS_KEYMAPPING_HPP
