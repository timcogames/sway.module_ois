#ifndef SWAY_OIS_WEB_EMSMOUSE_HPP
#define SWAY_OIS_WEB_EMSMOUSE_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois/inputdevicemacros.hpp>
#include <sway/ois/inputevents.hpp>

#include <emscripten/html5.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputDeviceManager;

class EMSMouse : public InputDevice {
public:
  DECLARE_INPUTDEVICE_TYPE(InputDeviceType::MOUSE);

  EMSMouse(InputDeviceManager *mngr);

  ~EMSMouse() = default;

  static EM_BOOL onMouseDown(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);

  static EM_BOOL onMouseUp(int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData);

  auto injectMouseMove(const EmscriptenMouseEvent &mouseEvent) -> bool;

  auto injectWheel(const EmscriptenWheelEvent &mouseEvent) -> bool;

  /**
   * @brief Устанавливает слушатель событий.
   *
   * @param[in] listener Слушатель событий клавиатуры.
   */
  MTHD_OVERRIDE(void setListener(InputListener *listener));

private:
  InputDeviceManager *mngr_;
  std::function<void(const struct MouseEventArgs &)> onMouseButtonDown_;
  std::function<void(const struct MouseEventArgs &)> onMouseMoved_;
  std::function<void(const struct MouseEventArgs &)> onMouseWheeled_;
  math::point2f_t cursor_;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_WEB_EMSMOUSE_HPP
