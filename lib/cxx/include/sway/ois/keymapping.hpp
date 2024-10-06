#ifndef SWAY_OIS_KEYMAPPING_HPP
#define SWAY_OIS_KEYMAPPING_HPP

#include <sway/ois/keycodes.hpp>
#include <sway/ois/prereqs.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

struct KeyMapping {
  KeySym symbol;
  KeyCode code;
};

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_KEYMAPPING_HPP
