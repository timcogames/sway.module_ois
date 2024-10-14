#ifndef SWAY_OIS_MOUSEEVENT_HPP
#define SWAY_OIS_MOUSEEVENT_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois/events/inputevent.hpp>
#include <sway/ois/typedefs.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

class MouseEvent : public InputEvent {
  DECLARE_PTR_ALIASES(MouseEvent)

public:
  explicit MouseEvent(u32_t type, core::foundation::EventData::Ptr_t data)
      : InputEvent(type, data) {}

  ~MouseEvent() = default;
};

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_MOUSEEVENT_HPP
