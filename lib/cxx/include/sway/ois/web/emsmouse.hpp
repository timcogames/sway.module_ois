#ifndef SWAY_OIS_WEB_EMSMOUSE_HPP
#define SWAY_OIS_WEB_EMSMOUSE_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois/_stdafx.hpp>
#include <sway/ois/_typedefs.hpp>
#include <sway/ois/inputdevice.hpp>
#include <sway/ois/inputdevicemacros.hpp>
#include <sway/ois/inputdevicetypes.hpp>
#include <sway/ois/inputeventparams.hpp>
#include <sway/ois/mouseeventparams.hpp>
#include <sway/ois/web/emsmouseevent.hpp>
#include <sway/ois/web/emswheelevent.hpp>
#include <sway/oismacros.hpp>

namespace sway::ois {

#define MOUSE_LBTN 0
#define MOUSE_MBTN 1
#define MOUSE_RBTN 2

class InputDeviceManager;

class EMSMouse : public InputDevice, public core::Emscripteable<EMSMouse> {
  DECLARE_INPUTDEVICE_TYPE(InputDeviceType::MOUSE);

public:
#pragma region "Static methods"

  static auto getTimestamp() -> double {
    static auto start = std::chrono::steady_clock::now();
    return std::chrono::duration<double>(std::chrono::steady_clock::now() - start).count();
  }

#pragma endregion

#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  EMSMouse(typedefs::InputDeviceManagerPtr_t mngr);

  ~EMSMouse() = default;

  /** @} */
#pragma endregion

  void registerEventHandlers();

  void unregisterEventHandlers();

  void pointerLock();

  void pointerUnlock();

  auto isPointerLocked() -> bool;

  auto handleMouseButtonDown(const EMSMouseEvent &evt) -> bool;

  auto handleMouseButtonUp(const EMSMouseEvent &evt) -> bool;

  auto handleMouseMove(const EMSMouseEvent &evt) -> bool;

  auto handleWheel(const EMSWheelEvent &evt) -> bool;

#pragma region "Override InputDevice methods"

  /**
   * \~english
   * @brief Sets listener for events.
   * @param[in] listener Listener for events.
   *
   * \~russian
   * @brief Устанавливает слушатель событий.
   * @param[in] listener Слушатель событий клавиатуры.
   */
  MTHD_OVERRIDE(void setListener(typedefs::InputListenerPtr_t listener));

  MTHD_OVERRIDE(void setInputEventListener(typedefs::InputEventListenerPtr_t listener)) {}

#pragma endregion

  void setCanvasId(lpcstr_t canvasId) { canvasId_ = canvasId; }

  void setBoundingBox(const math::bbox2f_t &bounds) { bounds_ = bounds; }

  typedef void (*callback_t)(int, int);
  void setMotionFunc(callback_t fn);

private:
  typedefs::InputDeviceManagerPtr_t mngr_;

  MouseEventCallbackFunc_t onMouseButtonDown_;
  MouseEventCallbackFunc_t onMouseDblClick_;
  MouseEventCallbackFunc_t onMouseButtonUp_;
  MouseEventCallbackFunc_t onMouseMoved_;
  MouseEventCallbackFunc_t onMouseWheeled_;

  std::function<void(int, int)> onMotion_;

  std::string canvasId_;
  math::bbox2f_t bounds_;

  MouseEventParams eventParams_;
  double prevMouseDownTime_ = 0.0;
  bool firstClick_ = false;
};

#if (defined EMSCRIPTEN_PLATFORM && !defined EMSCRIPTEN_USE_BINDINGS)
EXTERN_C_BEGIN

D_MODULE_OIS_INTERFACE_EXPORT_API void registerMouseDevice(iptr_t mngr);

D_MODULE_OIS_INTERFACE_EXPORT_API void registerMouseEventHandlers(iptr_t device);

D_MODULE_OIS_INTERFACE_EXPORT_API void unregisterMouseEventHandlers(iptr_t device);

D_MODULE_OIS_INTERFACE_EXPORT_API auto getMouseDevice(iptr_t mngr) -> iptr_t;

D_MODULE_OIS_INTERFACE_EXPORT_API void setMouseCanvasId(iptr_t device, lpcstr_t canvasId);

D_MODULE_OIS_INTERFACE_EXPORT_API void setMouseBoundingBox(iptr_t device, int w, int h);

D_MODULE_OIS_INTERFACE_EXPORT_API void onMotionCallback(iptr_t device, void (*callback)(int, int));

EXTERN_C_END
#endif

}  // namespace sway::ois

#endif  // SWAY_OIS_WEB_EMSMOUSE_HPP
