#ifndef SWAY_OIS_KEYEVENT_HPP
#define SWAY_OIS_KEYEVENT_HPP

#include <sway/core.hpp>
#include <sway/ois/events/inputevent.hpp>
#include <sway/ois/typedefs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class KeyEvent : public InputEvent {
  DECLARE_CLASS_POINTER_ALIASES(KeyEvent)

public:
  explicit KeyEvent(u32_t type, core::foundation::EventData::Ptr_t data)
      : InputEvent(type, data) {}

  ~KeyEvent() = default;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYEVENT_HPP
