#include <sway/ois/inputdevicemanager.hpp>
#include <sway/ois/inputevents.hpp>
#include <sway/ois/web/emsmouse.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

#define canvasId "#canvas"

EMSMouse::EMSMouse(InputDeviceManager *mngr)
    : mngr_(mngr) {
  const EM_BOOL toUseCapture = EM_TRUE;
  emscripten_set_mousedown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, this, toUseCapture, onMouseDown);
  emscripten_set_mouseup_callback(canvasId, this, toUseCapture, onMouseUp);
  emscripten_set_mousemove_callback(canvasId, this, toUseCapture, onMouseMove);
}

void EMSMouse::setListener(InputListener *listener) {
  onMouseButtonDown_ = std::bind(&InputListener::onMouseButtonDown, listener, std::placeholders::_1);
  // onMouseButtonUp_ = std::bind(&InputListener::onMouseButtonUp, listener, std::placeholders::_1);
  // onMouseMove_ = std::bind(&InputListener::onMouseMove, listener, std::placeholders::_1);
}

EM_BOOL EMSMouse::onMouseDown(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
  auto *self = static_cast<EMSMouse *>(userData);

  MouseEventArgs args;
  args.x = (f32_t)mouseEvent->movementX;
  args.y = (f32_t)mouseEvent->movementY;
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

EM_BOOL EMSMouse::onMouseMove(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
  auto *self = static_cast<EMSMouse *>(userData);

  return EM_TRUE;
}

NAMESPACE_END(ois)
NAMESPACE_END(sway)
