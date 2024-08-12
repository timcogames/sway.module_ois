#ifndef SWAY_OIS_MOUSEEVENTDATA_HPP
#define SWAY_OIS_MOUSEEVENTDATA_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>

#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

struct MouseEventData : core::foundation::EventData {
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

  MTHD_OVERRIDE(auto serialize() const -> std::string) { return ""; }

  MTHD_OVERRIDE(void deserialize(const std::string &jdata)) {}

#pragma endregion
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_MOUSEEVENTDATA_HPP
