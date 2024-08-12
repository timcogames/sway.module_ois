#ifndef SWAY_OIS_KEYEVENT_HPP
#define SWAY_OIS_KEYEVENT_HPP

#include <sway/core.hpp>
#include <sway/ois/events/inputevent.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class KeyEvent : public InputEvent {
public:
  using Ptr_t = KeyEvent *;

  explicit KeyEvent(u32_t type, core::foundation::EventData::Ptr_t data)
      : InputEvent(type, data) {}

  ~KeyEvent() = default;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYEVENT_HPP
