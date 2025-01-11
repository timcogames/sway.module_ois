#ifndef SWAY_OIS_MOUSEEVENT_HPP
#define SWAY_OIS_MOUSEEVENT_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois/events/inputevent.hpp>
#include <sway/ois/typedefs.hpp>

namespace sway::ois {

class MouseEvent : public InputEvent {
public:
  explicit MouseEvent(u32_t type, core::EventDataTypedefs::Ptr_t data)
      : InputEvent(type, data) {}

  ~MouseEvent() = default;
};

}  // namespace sway::ois

#endif  // SWAY_OIS_MOUSEEVENT_HPP
