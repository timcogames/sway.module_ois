#include <sway/ois/events/keyevent.hpp>
#include <sway/ois/inputactionstates.hpp>
#include <sway/ois/inputactiontypes.hpp>
#include <sway/ois/inputdevicemanager.hpp>
#include <sway/ois/web/emskeyboard.hpp>

#include <algorithm>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

EMSKeyboard::EMSKeyboard(InputDeviceManager *mngr)
    : mngr_(mngr) {
#ifdef EMSCRIPTEN_PLATFORM
  const EM_BOOL toUseCapture = EM_FALSE;

  emscripten_set_keydown_callback(
      EMSCRIPTEN_EVENT_TARGET_DOCUMENT, this, toUseCapture, [](int, const EmscriptenKeyboardEvent *evt, void *data) {
        return EM_BOOL(static_cast<EMSKeyboard *>(data)->handleKeyDown(*evt));
      });

  emscripten_set_keyup_callback(
      EMSCRIPTEN_EVENT_TARGET_DOCUMENT, this, toUseCapture, [](int, const EmscriptenKeyboardEvent *evt, void *data) {
        return EM_BOOL(static_cast<EMSKeyboard *>(data)->handleKeyUp(*evt));
      });

  emscripten_set_keypress_callback(
      EMSCRIPTEN_EVENT_TARGET_DOCUMENT, this, toUseCapture, [](int, const EmscriptenKeyboardEvent *evt, void *data) {
        return EM_BOOL(static_cast<EMSKeyboard *>(data)->handleKeyPress(*evt));
      });
#endif
}

void EMSKeyboard::setListener(InputListener *listener) {
  onKeyDown_ = std::bind(&InputListener::onKeyDown, listener, std::placeholders::_1);
  onKeyUp_ = std::bind(&InputListener::onKeyUp, listener, std::placeholders::_1);
  onKeyPress_ = std::bind(&InputListener::onKeyPress, listener, std::placeholders::_1);
}

void EMSKeyboard::setInputEventListener(InputEventListener *listener) {
  actionCallback_ = std::bind(&InputEventListener::processInputEvent, listener, std::placeholders::_1);
}

auto EMSKeyboard::handleKeyDown(const EmscKeyboardEvent_t &evt) -> bool {
  auto *eventdata = new KeyEventData();
  eventdata->keycode = evt.keyCode;
  eventdata->state = core::detail::toUnderlying(InputActionState::PRESSED);

  auto event = std::make_unique<KeyEvent>(core::detail::toUnderlying(InputActionType::KEY), eventdata);
  mngr_->getEventBus()->addToQueue(std::move(event));

  if (onKeyDown_) {
    onKeyDown_(KeyboardEventParams(evt.keyCode));
  }

  // if (actionCallback_) {
  //   actionCallback_(new KeyboardEventParams(evt.keyCode));
  // }

  return true;
}

auto EMSKeyboard::handleKeyUp(const EmscKeyboardEvent_t &evt) -> bool {
  auto *eventdata = new KeyEventData();
  eventdata->keycode = evt.keyCode;
  eventdata->state = core::detail::toUnderlying(InputActionState::RELEASED);

  auto event = std::make_unique<KeyEvent>(core::detail::toUnderlying(InputActionType::KEY), eventdata);
  mngr_->getEventBus()->addToQueue(std::move(event));

  if (onKeyUp_) {
    onKeyUp_(KeyboardEventParams(evt.keyCode));
  }

  return true;
}

auto EMSKeyboard::handleKeyPress(const EmscKeyboardEvent_t &evt) -> bool {
  if (onKeyPress_) {
    onKeyPress_(KeyboardEventParams(evt.keyCode));
  }

  return true;
}

NAMESPACE_END(ois)
NAMESPACE_END(sway)
