#ifndef SWAY_OIS_KEYEVENTHANDLER_HPP
#define SWAY_OIS_KEYEVENTHANDLER_HPP

#include <sway/core.hpp>
#include <sway/ois/events/inputevent.hpp>
#include <sway/ois/events/inputeventutil.hpp>
#include <sway/ois/events/keyevent.hpp>
#include <sway/ois/events/mouseevent.hpp>
#include <sway/ois/inputeventparams.hpp>

#include <list>
#include <memory>
#include <queue>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

struct KeyEventHandler : public core::evts::EventHandler {
  KeyEventHandler()
      : core::evts::EventHandler() {}

  ~KeyEventHandler() override = default;

#pragma region "Override EventHandler methods"

  MTHD_OVERRIDE(auto invoke(const core::foundation::Event::UniquePtr_t &evt) -> bool) final {
    if (InputEventUtil::isKeyEvent(evt)) {
      onKeyEvent(InputEventUtil::asKeyEvent(evt));
    }

    return true;
  }

#pragma endregion

  void onKeyEvent(KeyEvent *evt) { printf("type %i\n", evt->type()); }

  // void onKeyDown(const KeyboardEventParams &params) {}

  // void onKeyUp(const KeyboardEventParams &params) {}

  // void onKeyPress(const KeyboardEventParams &params) {}
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYEVENTHANDLER_HPP
