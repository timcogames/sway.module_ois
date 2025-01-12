#ifndef SWAY_OIS_KEYEVENTDATA_HPP
#define SWAY_OIS_KEYEVENTDATA_HPP

#include <sway/core.hpp>
#include <sway/ois/_stdafx.hpp>

namespace sway::ois {

struct KeyEventData : core::EventData {
  u32_t keyCode;
  u32_t state;

#pragma region "Override EventData methods"

  // MTHD_OVERRIDE(auto serialize() const -> std::string) { return ""; }

  // MTHD_OVERRIDE(void deserialize(const std::string &jdata)) {}

#pragma endregion
};

}  // namespace sway::ois

#endif  // SWAY_OIS_KEYEVENTDATA_HPP
