#ifndef SWAY_OIS_INPUTEVENTUTIL_HPP
#define SWAY_OIS_INPUTEVENTUTIL_HPP

#include <sway/core.hpp>
#include <sway/ois/_stdafx.hpp>
#include <sway/ois/events/inputevent.hpp>
#include <sway/ois/events/keyevent.hpp>
#include <sway/ois/events/mouseevent.hpp>
#include <sway/ois/inputeventparams.hpp>

namespace sway::ois {

struct InputEventUtil {
  static auto isKeyEvent(const core::EventTypedefs::UniquePtr_t &evt) -> bool {
    return evt->getType() == core::toBase(InputActionType::KEY);
  }

  static auto asKeyEvent(const core::EventTypedefs::UniquePtr_t &evt) -> typedefs::KeyEventPtr_t {
    return static_cast<typedefs::KeyEventPtr_t>(evt.get());
  }

  static auto isMouseEvent(const core::EventTypedefs::UniquePtr_t &evt) -> bool {
    return evt->getType() == core::toBase(InputActionType::MOUSE_BUTTON) ||
           evt->getType() == core::toBase(InputActionType::MOUSE_MOVED);
  }

  static auto asMouseEvent(const core::EventTypedefs::UniquePtr_t &evt) -> typedefs::MouseEventPtr_t {
    return static_cast<typedefs::MouseEventPtr_t>(evt.get());
  }
};

}  // namespace sway::ois

#endif  // SWAY_OIS_INPUTEVENTUTIL_HPP
