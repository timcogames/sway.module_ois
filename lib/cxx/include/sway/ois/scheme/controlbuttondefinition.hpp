#ifndef SWAY_OIS_SCHEME_CONTROLBUTTONDEFINITION_HPP
#define SWAY_OIS_SCHEME_CONTROLBUTTONDEFINITION_HPP

#include <sway/core.hpp>
#include <sway/ois/scheme/controlbutton.hpp>

#include <string>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

struct ControlButtonDefinition {
  Equalable<u32_t>::SharedPtr_t button;
  std::string description;
};

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_SCHEME_CONTROLBUTTONDEFINITION_HPP
