#ifndef SWAY_OIS_KEYEVENTDATA_HPP
#define SWAY_OIS_KEYEVENTDATA_HPP

#include <sway/core.hpp>

#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

struct KeyEventData : core::foundation::EventData {
  u32_t keyCode;
  u32_t state;

#pragma region "Override EventData methods"

  MTHD_OVERRIDE(auto serialize() const -> std::string) { return ""; }

  MTHD_OVERRIDE(void deserialize(const std::string &jdata)) {}

#pragma endregion
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYEVENTDATA_HPP
