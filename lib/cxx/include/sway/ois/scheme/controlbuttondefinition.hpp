#ifndef SWAY_OIS_SCHEME_CONTROLBUTTONDEFINITION_HPP
#define SWAY_OIS_SCHEME_CONTROLBUTTONDEFINITION_HPP

#include <sway/core.hpp>
#include <sway/ois/scheme/controlbutton.hpp>

#include <string>

namespace sway::ois {

struct ControlButtonDefinition {
  Equalable<u32_t>::SharedPtr_t button;
  std::string description;
};

}  // namespace sway::ois

#endif  // SWAY_OIS_SCHEME_CONTROLBUTTONDEFINITION_HPP
