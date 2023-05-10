#ifndef SWAY_OIS_WEB_EMSMOUSE_HPP
#define SWAY_OIS_WEB_EMSMOUSE_HPP

#include <sway/core.hpp>

#include <emscripten/html5.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class EMSMouse {
public:
  EMSMouse();

  ~EMSMouse() = default;

  static EM_BOOL onMouseDown(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);

  static EM_BOOL onMouseUp(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);

  static EM_BOOL onMouseMove(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);

private:
  MouseEventCallbackFunc_t onMouseButtonDown_;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_WEB_EMSMOUSE_HPP
