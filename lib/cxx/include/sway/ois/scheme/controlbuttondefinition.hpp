#ifndef SWAY_OIS_SCHEME_CONTROLBUTTONDEFINITION_HPP
#define SWAY_OIS_SCHEME_CONTROLBUTTONDEFINITION_HPP

#include <sway/core.hpp>
#include <sway/ois/scheme/controlbutton.hpp>

#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

struct ControlButtonDefinition {
  Equalable<u32_t>::SharedPtr_t button;
  std::string description;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_SCHEME_CONTROLBUTTONDEFINITION_HPP
