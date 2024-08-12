#ifndef SWAY_OIS_MOUSEEVENT_HPP
#define SWAY_OIS_MOUSEEVENT_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois/events/inputevent.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class MouseEvent : public InputEvent {
public:
  using Ptr_t = MouseEvent *;

  explicit MouseEvent(u32_t type, core::foundation::EventData::Ptr_t data)
      : InputEvent(type, data) {}

  ~MouseEvent() = default;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_MOUSEEVENT_HPP
