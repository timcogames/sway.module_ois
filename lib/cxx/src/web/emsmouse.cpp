#include <sway/ois/events/mouseevent.hpp>
#include <sway/ois/inputactionstates.hpp>
#include <sway/ois/inputdevicemanager.hpp>
#include <sway/ois/keymodifiers.hpp>
#include <sway/ois/web/emsmouse.hpp>

#include <algorithm>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

#define CANVAS_ID "#canvas"

EMSMouse::EMSMouse(InputDeviceManager *mngr)
    : mngr_(mngr)
    , canvasId_(CANVAS_ID)
    , bounds_(math::BoundingBox<f32_t, 2>(math::vec2f_zero, math::Vector2<f32_t>(300.0F, 240.0F))) {
  registerEventHandlers();
}

void EMSMouse::registerEventHandlers() {
#ifdef EMSCRIPTEN_PLATFORM
  const EM_BOOL toUseCapture = EM_TRUE;

  // clang-format off
  emscripten_set_mousedown_callback(canvasId_.c_str(), this, toUseCapture, [](int, const EmscriptenMouseEvent *evt, void *data) {
    return EM_BOOL(static_cast<EMSMouse *>(data)->handleMouseButtonDown(*evt));
  });  // clang-format on

  // clang-format off
  emscripten_set_mouseup_callback(EMSCRIPTEN_EVENT_TARGET_DOCUMENT, this, toUseCapture, [](int, const EmscriptenMouseEvent *evt, void *data) {
    return EM_BOOL(static_cast<EMSMouse *>(data)->handleMouseButtonUp(*evt));
  });  // clang-format on

  // clang-format off
  emscripten_set_mousemove_callback(canvasId_.c_str(), this, toUseCapture, [](int, const EmscriptenMouseEvent *evt, void *data) {
    return EM_BOOL(static_cast<EMSMouse *>(data)->handleMouseMove(*evt));
  });  // clang-format on

  // clang-format off
  emscripten_set_wheel_callback(canvasId_.c_str(), this, toUseCapture, [](int, const EmscriptenWheelEvent *evt, void *data) {
    return EM_BOOL(static_cast<EMSMouse *>(data)->handleWheel(*evt));
  });  // clang-format on
#endif
}

void EMSMouse::unregisterEventHandlers() {
#ifdef EMSCRIPTEN_PLATFORM
  emscripten_set_mousedown_callback(canvasId_.c_str(), nullptr, 0, nullptr);
  emscripten_set_mouseup_callback(EMSCRIPTEN_EVENT_TARGET_DOCUMENT, nullptr, 0, nullptr);
  emscripten_set_mousemove_callback(canvasId_.c_str(), nullptr, 0, nullptr);
  emscripten_set_wheel_callback(canvasId_.c_str(), nullptr, 0, nullptr);
#endif
}

void EMSMouse::setListener(InputListener *listener) {
  onMouseButtonDown_ = std::bind(&InputListener::onMouseButtonDown, listener, std::placeholders::_1);
  onMouseDblClick_ = std::bind(&InputListener::onMouseDblClick, listener, std::placeholders::_1);
  onMouseButtonUp_ = std::bind(&InputListener::onMouseButtonUp, listener, std::placeholders::_1);
  onMouseMoved_ = std::bind(&InputListener::onMouseMoved, listener, std::placeholders::_1);
  onMouseWheeled_ = std::bind(&InputListener::onMouseWheeled, listener, std::placeholders::_1);
}

auto EMSMouse::handleMouseButtonDown(const EmscMouseEvent_t &evt) -> bool {
  auto modifiers = 0;

  if (bool(evt.ctrlKey)) {
    modifiers |= core::detail::toUnderlying(KeyModifier::CTRL);
  }
  if (bool(evt.shiftKey)) {
    modifiers |= core::detail::toUnderlying(KeyModifier::SHIFT);
  }
  if (bool(evt.altKey)) {
    modifiers |= core::detail::toUnderlying(KeyModifier::ALT);
  }

  eventParams_.position = math::point2f_t(std::clamp<f32_t>((f32_t)evt.targetX, 0.0F, bounds_.max[0]),
      std::clamp<f32_t>((f32_t)evt.targetY, 0.0F, bounds_.max[1]));
  eventParams_.drag = eventParams_.position.toVec();
  eventParams_.modifiers = modifiers;
  eventParams_.button = evt.button;  // deprecated
  eventParams_.entered = true;  // deprecated
  eventParams_.states[evt.button] = InputActionState::PRESSED;

  auto *eventdata = new MouseEventData();
  eventdata->point = eventParams_.position;
  eventdata->btncode = eventParams_.button;
  eventdata->state = core::detail::toUnderlying(InputActionState::PRESSED);

  auto event = std::make_unique<MouseEvent>(core::detail::toUnderlying(InputActionType::MOUSE_BUTTON), eventdata);
  mngr_->getEventBus()->addToQueue(std::move(event));

  const auto timestamp = EMSMouse::getTimestamp();
  const auto timeDiff = timestamp - prevMouseDownTime_;

  if (firstClick_ && timeDiff < 0.3) {
    firstClick_ = false;

    if (onMouseDblClick_) {
      onMouseDblClick_(eventParams_);
    }
  } else {
    firstClick_ = true;

    if (onMouseButtonDown_) {
      onMouseButtonDown_(eventParams_);
    }
  }

  prevMouseDownTime_ = timestamp;

  return true;
}

auto EMSMouse::handleMouseButtonUp(const EmscMouseEvent_t &evt) -> bool {
  eventParams_.button = evt.button;  // deprecated
  eventParams_.entered = false;  // deprecated
  eventParams_.states[evt.button] = InputActionState::RELEASED;

  if (onMouseButtonUp_) {
    onMouseButtonUp_(eventParams_);
  }

  return true;
}

void EMSMouse::pointerLock() {
#ifdef EMSCRIPTEN_PLATFORM
  emscripten_request_pointerlock(canvasId_.c_str(), false);
#endif
}

void EMSMouse::pointerUnlock() {
#ifdef EMSCRIPTEN_PLATFORM
  emscripten_exit_pointerlock();
#endif
}

auto EMSMouse::isPointerLocked() -> bool {
#ifdef EMSCRIPTEN_PLATFORM
  // clang-format off
  EmscriptenPointerlockChangeEvent status;
  return (emscripten_get_pointerlock_status(&status) == EMSCRIPTEN_RESULT_SUCCESS)
    ? bool(status.isActive) : false;  // clang-format on
#else
  return true;
#endif
}

auto EMSMouse::handleMouseMove(const EmscMouseEvent_t &evt) -> bool {
  // clang-format off
  if (!isPointerLocked()) {
    eventParams_.position = math::point2f_t(
      std::clamp<f32_t>((f32_t)evt.targetX, 0.0F, bounds_.max[0]),
      std::clamp<f32_t>((f32_t)evt.targetY, 0.0F, bounds_.max[1]));
  } else {
    eventParams_.position = math::point2f_t(
      std::clamp<f32_t>((f32_t)evt.targetX + (f32_t)evt.movementX, 0.0F, bounds_.max[0]),
      std::clamp<f32_t>((f32_t)evt.targetY + (f32_t)evt.movementY, 0.0F, bounds_.max[1]));
  }
  // clang-format on

  eventParams_.offset = math::vec2f_t((f32_t)evt.movementX, (f32_t)evt.movementY);
  eventParams_.drag = eventParams_.position.toVec();

  if (onMouseMoved_) {
    onMouseMoved_(eventParams_);
  }

  if (onMotion_) {
    onMotion_(eventParams_.position.getX(), eventParams_.position.getY());
  }

  return true;
}

auto EMSMouse::handleWheel(const EmscWheelEvent_t &evt) -> bool {
  eventParams_.deltaZ = -evt.deltaY;

  if (onMouseWheeled_) {
    onMouseWheeled_(eventParams_);
  }

  return true;
}

void EMSMouse::setMotionFunc(callback_t cb) { onMotion_ = std::function<void(int, int)>(cb); }

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)

void registerMouseDevice(InputDeviceManager::JsPtr_t mngr) {
  auto obj = InputDeviceManager::fromJs(mngr);
  if (!obj) {
    // TODO
  }

  obj->registerDevice<EMSMouse>();
}

void registerMouseEventHandlers(EMSMouse::JsPtr_t device) {
  auto obj = EMSMouse::fromJs(device);
  if (!obj) {
    // TODO
  }

  obj->registerEventHandlers();
}

void unregisterMouseEventHandlers(EMSMouse::JsPtr_t device) {
  auto obj = EMSMouse::fromJs(device);
  if (!obj) {
    // TODO
  }

  obj->unregisterEventHandlers();
}

auto getMouseDevice(InputDeviceManager::JsPtr_t mngr) -> EMSMouse::JsPtr_t {
  auto obj = InputDeviceManager::fromJs(mngr);
  if (!obj) {
    // TODO
  }

  return EMSMouse::toJs(obj->getDevice<EMSMouse>().get());
}

void setMouseCanvasId(EMSMouse::JsPtr_t device, lpcstr_t canvasId) {
  auto obj = EMSMouse::fromJs(device);
  if (!obj) {
    // TODO
  }

  // EM_ASM(console.log('Canvas Id: ' + UTF8ToString($0)), canvasId);
  obj->setCanvasId(canvasId);
}

void setMouseBoundingBox(EMSMouse::JsPtr_t device, int w, int h) {
  auto obj = EMSMouse::fromJs(device);
  if (!obj) {
    // TODO
  }

  obj->setBoundingBox(math::BoundingBox<f32_t, 2>(math::vec2f_zero, math::Vector2<f32_t>((f32_t)w, (f32_t)h)));
}

void onMotionCallback(EMSMouse::JsPtr_t device, void (*callback)(int, int)) {
  auto obj = EMSMouse::fromJs(device);
  if (!obj) {
    // TODO
  }

  obj->setMotionFunc(callback);
}

#endif

NAMESPACE_END(ois)
NAMESPACE_END(sway)
