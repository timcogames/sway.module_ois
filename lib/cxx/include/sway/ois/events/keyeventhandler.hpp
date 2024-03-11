#ifndef SWAY_OIS_KEYEVENTHANDLER_HPP
#define SWAY_OIS_KEYEVENTHANDLER_HPP

#include <sway/core.hpp>
#include <sway/ois/events/inputevent.hpp>
#include <sway/ois/events/keyevent.hpp>
#include <sway/ois/events/mouseevent.hpp>
#include <sway/ois/inputeventparams.hpp>

#include <list>
#include <memory>
#include <queue>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

struct InputEventUtil {
  static auto isKeyEvent(const std::unique_ptr<core::foundation::Event> &event) -> bool {
    return event->type() == core::detail::toUnderlying(InputActionType::KEY);
  }

  static auto asKeyEvent(const std::unique_ptr<core::foundation::Event> &event) -> KeyEvent * {
    return static_cast<KeyEvent *>(event.get());
  }

  static auto isMouseEvent(const std::unique_ptr<core::foundation::Event> &event) -> bool {
    return event->type() == core::detail::toUnderlying(InputActionType::MOUSE_BUTTON);
  }

  static auto asMouseEvent(const std::unique_ptr<core::foundation::Event> &event) -> MouseEvent * {
    return static_cast<MouseEvent *>(event.get());
  }
};

struct KeyEventHandler : public core::evts::EventHandler {
  KeyEventHandler()
      : core::evts::EventHandler() {}

  ~KeyEventHandler() override = default;

  // clang-format off
  MTHD_OVERRIDE(auto invoke(const std::unique_ptr<core::foundation::Event> &event) -> bool) final {  // clang-format on
    if (InputEventUtil::isKeyEvent(event)) {
      onKeyEvent(InputEventUtil::asKeyEvent(event));
    }

    return true;
  }

  void onKeyEvent(KeyEvent *event) { printf("type %i\n", event->type()); }

  // void onKeyDown(const KeyboardEventParams &params) {}

  // void onKeyUp(const KeyboardEventParams &params) {}

  // void onKeyPress(const KeyboardEventParams &params) {}
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYEVENTHANDLER_HPP
