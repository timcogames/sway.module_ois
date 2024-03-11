#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois.hpp>
#include <sway/ois/events/keyevent.hpp>

#undef Bool
#undef None

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>

using namespace sway;

class StupInputEventListener : public ois::InputEventListener {
public:
  StupInputEventListener(core::evts::EventBus *evtbus)
      : evtbus_(evtbus) {}

  MTHD_OVERRIDE(void processInputEvent(ois::InputEventParams *params)) {
    auto eventData = new ois::KeyEventData();
    auto event = std::make_unique<ois::KeyEvent>(core::detail::toUnderlying(ois::InputActionType::KEY), eventData);
    evtbus_->addToQueue(std::move(event));
  }

private:
  core::evts::EventBus *evtbus_;
};

class FakeInputDevice : public ois::InputDevice {
public:
  MTHD_OVERRIDE(void setListener(ois::InputListener *)) {
    // DEPRECATED
  }

  MTHD_OVERRIDE(void setInputEventListener(ois::InputEventListener *listener)) {
    handleEvent_ = std::bind(&ois::InputEventListener::processInputEvent, listener, std::placeholders::_1);
  }

  auto imitateKeyPress(ois::KeyboardEventParams *params) -> bool {
    if (handleEvent_) {
      handleEvent_(std::move(params));
      return true;
    }

    return false;
  }

private:
  std::function<void(ois::InputEventParams *)> handleEvent_;
};

TEST(InputEventListener, Test) {
  core::evts::EventBus *evtbus = new core::evts::EventBus();

  FakeInputDevice device;
  device.setInputEventListener(new StupInputEventListener(evtbus));

  auto *params = new ois::KeyboardEventParams(12);
  // params->code;
  // params->state = ois::InputActionState::PRESSED;
  // params->text;
  // params->modifiers
  device.imitateKeyPress(params);

  evtbus->process();
}
