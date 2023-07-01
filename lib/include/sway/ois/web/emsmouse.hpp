#ifndef SWAY_OIS_WEB_EMSMOUSE_HPP
#define SWAY_OIS_WEB_EMSMOUSE_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois/inputdevicemacros.hpp>
#include <sway/ois/inputevents.hpp>

#include <emscripten/html5.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

#define MOUSE_LBTN 0
#define MOUSE_MBTN 1
#define MOUSE_RBTN 2

class InputDeviceManager;

class EMSMouse : public InputDevice {
public:
  DECLARE_INPUTDEVICE_TYPE(InputDeviceType::MOUSE);

  EMSMouse(InputDeviceManager *mngr);

  ~EMSMouse() = default;

  auto onMouseButtonDown(const EmscriptenMouseEvent &evt) -> bool;

  auto onMouseButtonUp(const EmscriptenMouseEvent &evt) -> bool;

  auto onMouseMove(const EmscriptenMouseEvent &evt) -> bool;

  auto onWheel(const EmscriptenWheelEvent &evt) -> bool;

  /**
   * @brief Устанавливает слушатель событий.
   *
   * @param[in] listener Слушатель событий клавиатуры.
   */
  MTHD_OVERRIDE(void setListener(InputListener *listener));

private:
  InputDeviceManager *mngr_;
  std::function<void(const struct MouseEventArgs &)> onMouseButtonDown_;
  std::function<void(const struct MouseEventArgs &)> onMouseButtonUp_;
  std::function<void(const struct MouseEventArgs &)> onMouseMoved_;
  std::function<void(const struct MouseEventArgs &)> onMouseWheeled_;
  math::point2f_t cursor_;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_WEB_EMSMOUSE_HPP