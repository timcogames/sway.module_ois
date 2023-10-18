#include <sway/ois/inputdevicemanager.hpp>
#include <sway/ois/web/emsmouse.hpp>

#include <algorithm>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

#define CANVAS_ID "#canvas"

EMSMouse::EMSMouse(InputDeviceManager *mngr)
    : mngr_(mngr)
    , screenDims_({300, 150}) {
  const EM_BOOL toUseCapture = EM_TRUE;

  // clang-format off
  emscripten_set_mousedown_callback(CANVAS_ID, this, toUseCapture, [](int, const EmscriptenMouseEvent *evt, void *data) {
    return EM_BOOL(static_cast<EMSMouse *>(data)->onMouseButtonDown(*evt));
  });

  emscripten_set_mouseup_callback(CANVAS_ID, this, toUseCapture, [](int, const EmscriptenMouseEvent *evt, void *data) {
    return EM_BOOL(static_cast<EMSMouse *>(data)->onMouseButtonUp(*evt));
  });

  emscripten_set_mousemove_callback(CANVAS_ID, this, toUseCapture, [](int, const EmscriptenMouseEvent *evt, void *data) {
    return EM_BOOL(static_cast<EMSMouse *>(data)->onMouseMove(*evt));
  });

  emscripten_set_wheel_callback(CANVAS_ID, this, toUseCapture, [](int, const EmscriptenWheelEvent *evt, void *data) {
    return EM_BOOL(static_cast<EMSMouse *>(data)->onWheel(*evt));
  });
  // clang-format on
}

void EMSMouse::setListener(InputListener *listener) {
  onMouseButtonDown_ = std::bind(&InputListener::onMouseButtonDown, listener, std::placeholders::_1);
  onMouseDblClick_ = std::bind(&InputListener::onMouseDblClick, listener, std::placeholders::_1);
  onMouseButtonUp_ = std::bind(&InputListener::onMouseButtonUp, listener, std::placeholders::_1);
  onMouseMoved_ = std::bind(&InputListener::onMouseMoved, listener, std::placeholders::_1);
  onMouseWheeled_ = std::bind(&InputListener::onMouseWheeled, listener, std::placeholders::_1);
}

auto EMSMouse::onMouseButtonDown(const EmscriptenMouseEvent &evt) -> bool {
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

  evtArgs_.position = math::point2f_t(std::clamp<f32_t>((f32_t)evt.targetX, 0.0F, (f32_t)screenDims_.getW()),
      std::clamp<f32_t>((f32_t)evt.targetY, 0.0F, (f32_t)screenDims_.getH()));
  evtArgs_.drag = evtArgs_.position.toVec();
  evtArgs_.modifiers = modifiers;
  evtArgs_.button = evt.button;
  evtArgs_.entered = true;

  const auto timestamp = EMSMouse::getTimestamp();
  const auto timeDiff = timestamp - prevMouseDownTime_;

  if (firstClick_ && timeDiff < 0.3) {
    firstClick_ = false;

    if (onMouseDblClick_) {
      onMouseDblClick_(evtArgs_);
    }
  } else {
    firstClick_ = true;

    if (onMouseButtonDown_) {
      onMouseButtonDown_(evtArgs_);
    }
  }

  prevMouseDownTime_ = timestamp;

  return true;
}

auto EMSMouse::onMouseButtonUp(const EmscriptenMouseEvent &evt) -> bool {
  evtArgs_.button = evt.button;
  evtArgs_.entered = false;

  if (onMouseButtonUp_) {
    onMouseButtonUp_(evtArgs_);
  }

  return true;
}

void EMSMouse::pointerLock() { emscripten_request_pointerlock(CANVAS_ID, false); }

void EMSMouse::pointerUnlock() { emscripten_exit_pointerlock(); }

auto EMSMouse::isPointerLocked() -> bool {
  // clang-format off
  EmscriptenPointerlockChangeEvent status;
  return (emscripten_get_pointerlock_status(&status) == EMSCRIPTEN_RESULT_SUCCESS)
    ? bool(status.isActive) : false;
  // clang-format on
}

auto EMSMouse::onMouseMove(const EmscriptenMouseEvent &evt) -> bool {
  // clang-format off
  if (!isPointerLocked()) {
    evtArgs_.position = math::point2f_t(
      std::clamp<f32_t>((f32_t)evt.targetX, 0.0F, (f32_t)screenDims_.getW()),
      std::clamp<f32_t>((f32_t)evt.targetY, 0.0F, (f32_t)screenDims_.getH()));
  } else {
    evtArgs_.position = math::point2f_t(
      std::clamp<f32_t>((f32_t)evt.targetX + (f32_t)evt.movementX, 0.0F, (f32_t)screenDims_.getW()),
      std::clamp<f32_t>((f32_t)evt.targetY + (f32_t)evt.movementY, 0.0F, (f32_t)screenDims_.getH()));
  }
  // clang-format on

  evtArgs_.offset = math::vec2f_t((f32_t)evt.movementX, (f32_t)evt.movementY);
  evtArgs_.drag = evtArgs_.position.toVec();

  if (onMouseMoved_) {
    onMouseMoved_(evtArgs_);
  }

  if (onMotion_) {
    onMotion_(evtArgs_.position.getX(), evtArgs_.position.getY());
  }

  return true;
}

auto EMSMouse::onWheel(const EmscriptenWheelEvent &evt) -> bool {
  evtArgs_.deltaZ = -evt.deltaY;

  if (onMouseWheeled_) {
    onMouseWheeled_(evtArgs_);
  }

  return true;
}

void EMSMouse::setMotionFunc(callback_t cb) { onMotion_ = std::function<void(int, int)>(cb); }

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)

void registerMouseDevice(InputDeviceManager::InputDeviceManagerPtr mngr) {
  auto obj = InputDeviceManager::fromJs(mngr);
  if (!obj) {
    // TODO
  }

  obj->registerDevice<EMSMouse>();
}

auto getMouseDevice(InputDeviceManager::InputDeviceManagerPtr mngr) -> EMSMouse::EMSMousePtr {
  auto obj = InputDeviceManager::fromJs(mngr);
  if (!obj) {
    // TODO
  }

  return EMSMouse::toJs(obj->getDevice<EMSMouse>().get());
}

void onMotionCallback(EMSMouse::EMSMousePtr device, void (*callback)(int, int)) {
  auto obj = EMSMouse::fromJs(device);
  if (!obj) {
    // TODO
  }

  obj->setMotionFunc(callback);
}

#endif

NAMESPACE_END(ois)
NAMESPACE_END(sway)
