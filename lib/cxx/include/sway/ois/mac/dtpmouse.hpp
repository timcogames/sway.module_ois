#ifndef SWAY_OIS_MAC_DTPMOUSE_HPP
#define SWAY_OIS_MAC_DTPMOUSE_HPP

#include <sway/ois/inputdevice.hpp>
#include <sway/ois/inputdevicemacros.hpp>
#include <sway/ois/inputdevicetypes.hpp>
#include <sway/ois/inputeventparams.hpp>
#include <sway/ois/inputlistener.hpp>
#include <sway/ois/prereqs.hpp>
#include <sway/ois/typedefs.hpp>

namespace sway::ois {

/**
 * @brief Представляет устройство мыши.
 */
class DTPMouse : public InputDevice {
  DECLARE_INPUTDEVICE_TYPE(InputDeviceType::MOUSE)

public:
#pragma region "Ctors/Dtor"

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   *
   * @param[in] mngr Указатель на менеджер ввода.
   */
  DTPMouse(typedefs::InputDeviceManagerPtr_t mngr);

  /**
   * @brief Деструктор класса. Освобождает захваченные ресурсы.
   */
  virtual ~DTPMouse();

#pragma endregion

#pragma region "Override InputDevice methods"

  /**
   * @brief Устанавливает слушатель событий.
   *
   * @param[in] listener Слушатель событий мышки.
   */
  MTHD_OVERRIDE(void setListener(typedefs::InputListenerPtr_t listener));

  MTHD_OVERRIDE(void setInputEventListener(typedefs::InputEventListenerPtr_t listener)) {}

#pragma endregion

  void notifyMouseMove(const XEvent &event);

  void notifyMouseButtonDown(const XEvent &event);

  void notifyMouseButtonUp(const XEvent &event);

private:
  /**
   * @brief Инициализация устройства.
   *
   * @note Внутренний метод, вызывается в конструкторе.
   */
  void initialize_();

  typedefs::InputDeviceManagerPtr_t manager_;  // Указатель на менеджер ввода.
  MouseEventCallbackFunc_t onMouseButtonDown_;
  MouseEventCallbackFunc_t onMouseButtonUp_;
  MouseEventCallbackFunc_t onMouseMove_;
  bool mouseGrabbed_;
};

}  // namespace sway::ois

#endif  // SWAY_OIS_MAC_DTPMOUSE_HPP
