#ifndef SWAY_OIS_MOUSEEVENTDATA_HPP
#define SWAY_OIS_MOUSEEVENTDATA_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois/_stdafx.hpp>

namespace sway::ois {

struct MouseEventData : core::EventData {
  math::point2f_t point;  // Координаты позиции курсора.
  math::vec2f_t offset;
  math::vec2f_t drag;
  f32_t deltaZ;
  u32_t modifiers;
  u32_t btnCode;  // Код кнопок мыши.
  u32_t state;

  MouseEventData()
      : modifiers(0) {}

#pragma region "Override EventData methods"

  // MTHD_OVERRIDE(auto serialize() const -> std::string) { return ""; }

  // MTHD_OVERRIDE(void deserialize(const std::string &jdata)) {}

#pragma endregion
};

}  // namespace sway::ois

#endif  // SWAY_OIS_MOUSEEVENTDATA_HPP
