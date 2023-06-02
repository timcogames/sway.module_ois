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
  emscripten_set_mousedown_callback(canvasId /* EMSCRIPTEN_EVENT_TARGET_WINDOW */, this, toUseCapture, onMouseDown);
  emscripten_set_mouseup_callback(canvasId, this, toUseCapture, onMouseUp);
  emscripten_set_mousemove_callback(
      canvasId, this, toUseCapture, [](int, const EmscriptenMouseEvent *event, void *userData) {
        return EM_BOOL(static_cast<EMSMouse *>(userData)->injectMouseMove(*event));
      });
  emscripten_set_wheel_callback(
      canvasId, this, toUseCapture, [](int, const EmscriptenWheelEvent *event, void *userData) {
        return EM_BOOL(static_cast<EMSMouse *>(userData)->injectWheel(*event));
      });
}

void EMSMouse::setListener(InputListener *listener) {
  onMouseButtonDown_ = std::bind(&InputListener::onMouseButtonDown, listener, std::placeholders::_1);
  // onMouseButtonUp_ = std::bind(&InputListener::onMouseButtonUp, listener, std::placeholders::_1);
  onMouseMoved_ = std::bind(&InputListener::onMouseMoved, listener, std::placeholders::_1);
  onMouseWheeled_ = std::bind(&InputListener::onMouseWheeled, listener, std::placeholders::_1);
}

EM_BOOL EMSMouse::onMouseDown(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
  auto *self = static_cast<EMSMouse *>(userData);

  MouseEventArgs args;
  args.position = math::point2f_t((f32_t)mouseEvent->targetX, (f32_t)mouseEvent->targetY);
  args.button = mouseEvent->button;

  if (self->onMouseButtonDown_) {
    self->onMouseButtonDown_(args);
  }

  return EM_TRUE;
}

EM_BOOL EMSMouse::onMouseUp(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
  auto *self = static_cast<EMSMouse *>(userData);

  return EM_TRUE;
}

auto EMSMouse::injectMouseMove(const EmscriptenMouseEvent &mouseEvent) -> bool {
  // TODO: math::point2f_t(300.0F, 150.0F) <- CANVAS SIZE
  std::cout << std::clamp<f32_t>(f32_t(mouseEvent.targetX), 0.0F, 300.0F) << std::endl;
  cursor_ = math::point2f_t(std::clamp<f32_t>(f32_t(mouseEvent.targetX), 0.0F, 300.0F),
      std::clamp<f32_t>(f32_t(mouseEvent.targetY), 0.0F, 150.0F));

  MouseEventArgs args;
  args.position = cursor_;
  args.offset = math::vec2f_t((f32_t)mouseEvent.movementX, (f32_t)mouseEvent.movementY);

  if (onMouseMoved_) {
    onMouseMoved_(args);
  }

  return true;
}

auto EMSMouse::injectWheel(const EmscriptenWheelEvent &wheelEvent) -> bool {
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
