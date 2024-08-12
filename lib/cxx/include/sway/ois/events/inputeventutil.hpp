#ifndef SWAY_OIS_INPUTEVENTUTIL_HPP
#define SWAY_OIS_INPUTEVENTUTIL_HPP

#include <sway/core.hpp>
#include <sway/ois/events/inputevent.hpp>
#include <sway/ois/events/keyevent.hpp>
#include <sway/ois/events/mouseevent.hpp>
#include <sway/ois/inputeventparams.hpp>

#include <memory>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

struct InputEventUtil {
  static auto isKeyEvent(const core::foundation::Event::UniquePtr_t &evt) -> bool {
    return evt->type() == core::detail::toBase(InputActionType::KEY);
  }

  static auto asKeyEvent(const core::foundation::Event::UniquePtr_t &evt) -> KeyEvent::Ptr_t {
    return static_cast<KeyEvent::Ptr_t>(evt.get());
  }

  static auto isMouseEvent(const core::foundation::Event::UniquePtr_t &evt) -> bool {
    return evt->type() == core::detail::toBase(InputActionType::MOUSE_BUTTON) ||
           evt->type() == core::detail::toBase(InputActionType::MOUSE_MOVED);
  }

  static auto asMouseEvent(const core::foundation::Event::UniquePtr_t &evt) -> MouseEvent::Ptr_t {
    return static_cast<MouseEvent::Ptr_t>(evt.get());
  }
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTEVENTUTIL_HPP
