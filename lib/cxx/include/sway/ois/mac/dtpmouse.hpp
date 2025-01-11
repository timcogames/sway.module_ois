#ifndef SWAY_OIS_MAC_DTPMOUSE_HPP
#define SWAY_OIS_MAC_DTPMOUSE_HPP

#include <sway/ois/_stdafx.hpp>
#include <sway/ois/inputdevice.hpp>
#include <sway/ois/inputdevicemacros.hpp>
#include <sway/ois/inputdevicetypes.hpp>
#include <sway/ois/inputeventparams.hpp>
#include <sway/ois/inputlistener.hpp>
#include <sway/ois/typedefs.hpp>

namespace sway::ois {

/**
 * @brief \~english Represents mouse device. \~russian Представляет устройство мыши.
 */
class DTPMouse : public InputDevice {
  DECLARE_INPUTDEVICE_TYPE(InputDeviceType::MOUSE)

public:
#pragma region "Ctors/Dtor"

  /**
   * \~english
   * @brief Constructor class. Initializes new instance of class.
   * @param[in] mngr Pointer to input device manager.
   *
   * \~russian
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса.
   * @param[in] mngr Указатель на менеджер ввода.
   */
  DTPMouse(typedefs::InputDeviceManagerPtr_t mngr);

  /**
   * @brief \~english Destructor class. Releases captured resources. \~russian Деструктор класса. Освобождает
   * захваченные ресурсы.
   */
  virtual ~DTPMouse();

#pragma endregion

#pragma region "Override InputDevice methods"

  /**
   * \~english
   * @brief Sets listener for events.
   * @param[in] listener Listener for events.
   *
   * \~russian
   * @brief Устанавливает слушатель событий.
   * @param[in] listener Слушатель событий мышки.
   */
  MTHD_OVERRIDE(void setListener(typedefs::InputListenerPtr_t listener));

  MTHD_OVERRIDE(void setInputEventListener(typedefs::InputEventListenerPtr_t listener)) {}

#pragma endregion

  void notifyMouseMove(const XEvent &event);

  void notifyMouseButtonDown(const XEvent &event);

  void notifyMouseButtonUp(const XEvent &event);

private:
#pragma mark - Private methods

  /**
   * \~english
   * @brief Initializes device.
   * @note Internal method, called in constructor.
   *
   * \~russian
   * @brief Инициализация устройства.
   * @note Внутренний метод, вызывается в конструкторе.
   */
  void initialize_();

#pragma mark - Private variables

  typedefs::InputDeviceManagerPtr_t manager_; /*!< \~english Pointer to input device manager.
    \~russian Указатель на менеджер ввода. */
  MouseEventCallbackFunc_t onMouseButtonDown_;
  MouseEventCallbackFunc_t onMouseButtonUp_;
  MouseEventCallbackFunc_t onMouseMove_;
  bool mouseGrabbed_;
};

}  // namespace sway::ois

#endif  // SWAY_OIS_MAC_DTPMOUSE_HPP
