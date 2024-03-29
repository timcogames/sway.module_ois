#ifndef SWAY_OIS_WEB_EMSMOUSE_HPP
#define SWAY_OIS_WEB_EMSMOUSE_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois/inputdevicemacros.hpp>
#include <sway/ois/inputevents.hpp>

#include <chrono>  // std::chrono
#include <emscripten/html5.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

#define MOUSE_LBTN 0
#define MOUSE_MBTN 1
#define MOUSE_RBTN 2

class InputDeviceManager;

class EMSMouse : public InputDevice {
public:
  DECLARE_EMSCRIPTEN(EMSMouse)
  DECLARE_INPUTDEVICE_TYPE(InputDeviceType::MOUSE);

  static auto getTimestamp() -> double {
    static auto start = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(std::chrono::steady_clock::now() - start).count();
  }

  EMSMouse(InputDeviceManager *mngr);

  ~EMSMouse() = default;

  void registerEventHandlers();

  void unregisterEventHandlers();

  void pointerLock();

  void pointerUnlock();

  auto isPointerLocked() -> bool;

  auto handleMouseButtonDown(const EmscriptenMouseEvent &evt) -> bool;

  auto handleMouseButtonUp(const EmscriptenMouseEvent &evt) -> bool;

  auto handleMouseMove(const EmscriptenMouseEvent &evt) -> bool;

  auto handleWheel(const EmscriptenWheelEvent &evt) -> bool;

  /**
   * @brief Устанавливает слушатель событий.
   *
   * @param[in] listener Слушатель событий клавиатуры.
   */
  MTHD_OVERRIDE(void setListener(InputListener *listener));

  void setCanvasId(lpcstr_t canvasId) { canvasId_ = canvasId; }

  void setBoundingBox(const math::bbox2f_t &bounds) { bounds_ = bounds; }

  typedef void (*callback_t)(int, int);
  void setMotionFunc(callback_t fn);

private:
  InputDeviceManager *mngr_;

  std::function<void(const struct MouseEventArgs &)> onMouseButtonDown_;
  std::function<void(const struct MouseEventArgs &)> onMouseDblClick_;
  std::function<void(const struct MouseEventArgs &)> onMouseButtonUp_;
  std::function<void(const struct MouseEventArgs &)> onMouseMoved_;
  std::function<void(const struct MouseEventArgs &)> onMouseWheeled_;

  std::function<void(int, int)> onMotion_;

  std::string canvasId_;
  math::bbox2f_t bounds_;

  MouseEventArgs evtArgs_;
  double prevMouseDownTime_ = 0.0;
  bool firstClick_ = false;
};

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)
EXTERN_C_BEGIN

EXPORT_API void registerMouseDevice(InputDeviceManager::JsPtr_t mngr);

EXPORT_API void registerMouseEventHandlers(EMSMouse::JsPtr_t device);

EXPORT_API void unregisterMouseEventHandlers(EMSMouse::JsPtr_t device);

EXPORT_API auto getMouseDevice(InputDeviceManager::JsPtr_t mngr) -> EMSMouse::JsPtr_t;

EXPORT_API void setMouseCanvasId(EMSMouse::JsPtr_t device, lpcstr_t canvasId);

EXPORT_API void setMouseBoundingBox(EMSMouse::JsPtr_t device, int w, int h);

EXPORT_API void onMotionCallback(EMSMouse::JsPtr_t device, void (*callback)(int, int));

EXTERN_C_END
#endif

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_WEB_EMSMOUSE_HPP
