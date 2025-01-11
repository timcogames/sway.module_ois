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

namespace sway::ois {

struct KeyEventHandler : public core::EventHandler {
  KeyEventHandler()
      : core::EventHandler(nullptr) {}

  ~KeyEventHandler() override = default;

#pragma region "Override EventHandler methods"

  MTHD_OVERRIDE(auto invoke(const core::EventTypedefs::UniquePtr_t &evt) -> bool) final {
    if (InputEventUtil::isKeyEvent(evt)) {
      onKeyEvent(InputEventUtil::asKeyEvent(evt));
    }

    return true;
  }

#pragma endregion

  void onKeyEvent(KeyEvent *evt) { printf("type %i\n", evt->getType()); }

  // void onKeyDown(const KeyboardEventParams &params) {}

  // void onKeyUp(const KeyboardEventParams &params) {}

  // void onKeyPress(const KeyboardEventParams &params) {}
};

}  // namespace sway::ois

#endif  // SWAY_OIS_KEYEVENTHANDLER_HPP
