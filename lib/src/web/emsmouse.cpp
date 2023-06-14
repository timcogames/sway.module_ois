#include <sway/ois/inputdevicemanager.hpp>
#include <sway/ois/inputevents.hpp>
#include <sway/ois/web/emsmouse.hpp>

#include <algorithm>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

#define canvasId "#canvas"

EMSMouse::EMSMouse(InputDeviceManager *mngr)
    : mngr_(mngr) {
  const EM_BOOL toUseCapture = EM_TRUE;

  emscripten_set_mousedown_callback(canvasId, this, toUseCapture, [](int, const EmscriptenMouseEvent *evt, void *data) {
    return EM_BOOL(static_cast<EMSMouse *>(data)->onMouseButtonDown(*evt));
  });

  emscripten_set_mouseup_callback(canvasId, this, toUseCapture, [](int, const EmscriptenMouseEvent *evt, void *data) {
    return EM_BOOL(static_cast<EMSMouse *>(data)->onMouseButtonUp(*evt));
  });

  emscripten_set_mousemove_callback(canvasId, this, toUseCapture, [](int, const EmscriptenMouseEvent *evt, void *data) {
    return EM_BOOL(static_cast<EMSMouse *>(data)->onMouseMove(*evt));
  });

  emscripten_set_wheel_callback(canvasId, this, toUseCapture, [](int, const EmscriptenWheelEvent *evt, void *data) {
    return EM_BOOL(static_cast<EMSMouse *>(data)->onWheel(*evt));
  });
}

void EMSMouse::setListener(InputListener *listener) {
  onMouseButtonDown_ = std::bind(&InputListener::onMouseButtonDown, listener, std::placeholders::_1);
  onMouseButtonUp_ = std::bind(&InputListener::onMouseButtonUp, listener, std::placeholders::_1);
  onMouseMoved_ = std::bind(&InputListener::onMouseMoved, listener, std::placeholders::_1);
  onMouseWheeled_ = std::bind(&InputListener::onMouseWheeled, listener, std::placeholders::_1);
}

auto EMSMouse::onMouseButtonDown(const EmscriptenMouseEvent &evt) -> bool {
  MouseEventArgs args;
  args.position = math::point2f_t((f32_t)evt.targetX, (f32_t)evt.targetY);
  args.button = evt.button;

  if (onMouseButtonDown_) {
    onMouseButtonDown_(args);
  }

  return true;
}

auto EMSMouse::onMouseButtonUp(const EmscriptenMouseEvent &evt) -> bool {
  MouseEventArgs args;
  args.position = math::point2f_t((f32_t)evt.targetX, (f32_t)evt.targetY);
  args.button = evt.button;

  if (onMouseButtonUp_) {
    onMouseButtonUp_(args);
  }

  return true;
}

auto EMSMouse::onMouseMove(const EmscriptenMouseEvent &evt) -> bool {
  // TODO: math::point2f_t(300.0F, 150.0F) <- CANVAS SIZE
  cursor_ = math::point2f_t(
      std::clamp<f32_t>(f32_t(evt.targetX), 0.0F, 300.0F), std::clamp<f32_t>(f32_t(evt.targetY), 0.0F, 150.0F));

  MouseEventArgs args;
  args.position = cursor_;
  args.offset = math::vec2f_t((f32_t)evt.movementX, (f32_t)evt.movementY);

  if (onMouseMoved_) {
    onMouseMoved_(args);
  }

  return true;
}

auto EMSMouse::onWheel(const EmscriptenWheelEvent &wheelEvent) -> bool {
  MouseEventArgs args;
  args.position = cursor_;
  args.deltaZ = -wheelEvent.deltaY;

  if (onMouseWheeled_) {
    onMouseWheeled_(args);
  }

  return true;
}

NAMESPACE_END(ois)
NAMESPACE_END(sway)
