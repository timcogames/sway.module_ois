#ifndef SWAY_OIS_MOUSEEVENT_HPP
#define SWAY_OIS_MOUSEEVENT_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois/events/inputevent.hpp>

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

  // clang-format off
  MTHD_OVERRIDE(auto serialize() const -> std::string) {  // clang-format on
    return "";
  }

  MTHD_OVERRIDE(void deserialize(const std::string &jdata)) {}
};

class MouseEvent : public InputEvent {
public:
  explicit MouseEvent(u32_t type, core::foundation::EventData *data)
      : InputEvent(type, data) {}

  ~MouseEvent() = default;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_MOUSEEVENT_HPP
