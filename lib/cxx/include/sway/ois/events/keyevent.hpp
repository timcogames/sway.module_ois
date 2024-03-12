#ifndef SWAY_OIS_KEYEVENT_HPP
#define SWAY_OIS_KEYEVENT_HPP

#include <sway/core.hpp>
#include <sway/ois/events/inputevent.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

struct KeyEventData : core::foundation::EventData {
  u32_t keyCode;
  u32_t state;

  // clang-format off
  MTHD_OVERRIDE(auto serialize() const -> std::string) {  // clang-format on
    return "";
  }

  MTHD_OVERRIDE(void deserialize(const std::string &jdata)) {}
};

class KeyEvent : public InputEvent {
public:
  explicit KeyEvent(u32_t type, core::foundation::EventData *data)
      : InputEvent(type, data) {}

  ~KeyEvent() = default;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYEVENT_HPP
