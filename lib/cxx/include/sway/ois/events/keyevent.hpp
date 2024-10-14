#ifndef SWAY_OIS_KEYEVENT_HPP
#define SWAY_OIS_KEYEVENT_HPP

#include <sway/core.hpp>
#include <sway/ois/events/inputevent.hpp>
#include <sway/ois/typedefs.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

class KeyEvent : public InputEvent {
  DECLARE_PTR_ALIASES(KeyEvent)

public:
  explicit KeyEvent(u32_t type, core::foundation::EventData::Ptr_t data)
      : InputEvent(type, data) {}

  ~KeyEvent() = default;
};

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_KEYEVENT_HPP
