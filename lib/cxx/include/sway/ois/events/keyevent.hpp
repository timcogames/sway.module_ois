#ifndef SWAY_OIS_KEYEVENT_HPP
#define SWAY_OIS_KEYEVENT_HPP

#include <sway/core.hpp>
#include <sway/ois/_typedefs.hpp>
#include <sway/ois/events/inputevent.hpp>

namespace sway::ois {

class KeyEvent : public InputEvent {
public:
  explicit KeyEvent(u32_t type, core::EventDataTypedefs::Ptr_t data)
      : InputEvent(type, data) {}

  ~KeyEvent() = default;
};

}  // namespace sway::ois

#endif  // SWAY_OIS_KEYEVENT_HPP
