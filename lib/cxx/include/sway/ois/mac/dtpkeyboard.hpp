#ifndef SWAY_OIS_MAC_DTPKEYBOARD_HPP
#define SWAY_OIS_MAC_DTPKEYBOARD_HPP

#include <sway/ois/inputdevice.hpp>
#include <sway/ois/inputdevicemacros.hpp>
#include <sway/ois/inputdevicetypes.hpp>
#include <sway/ois/inputlistener.hpp>
#include <sway/ois/prereqs.hpp>
#include <sway/ois/typedefs.hpp>

namespace sway::ois {

/**
 * @brief Представляет устройство клавиатуры.
 */
class DTPKeyboard : public InputDevice {
  DECLARE_INPUTDEVICE_TYPE(InputDeviceType::KEYBOARD)

public:
#pragma region "Ctors/Dtor"
  /** \~english @name Constructor & Destructor */ /** \~russian @name Конструктор и Деструктор */
  /** @{ */

  /**
   * \~english
   * @brief Constructor class. Initializes new instance of class.
   * @param[in] mngr Pointer to input device manager.
   *
   * \~russian
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса.
   * @param[in] mngr Указатель на менеджер ввода.
   */
  DTPKeyboard(typedefs::InputDeviceManagerPtr_t mngr);

  /**
   * @brief \~english Destructor class. Releases captured resources. \~russian Деструктор класса. Освобождает
   * захваченные ресурсы.
   */
  virtual ~DTPKeyboard();

  /** @} */
#pragma endregion

#pragma region "Override InputDevice methods"

  /**
   * \~english
   * @brief Sets a listener for keyboard events.
   * @details This method allows a listener to subscribe to keyboard events and receive notifications when such events
   * occur.
   * @param[in] listener A pointer to the keyboard event listener.
   *
   * \~russian
   * @brief Устанавливает слушатель событий клавиатуры.
   * @details Этот метод позволяет слушателю подписаться на события клавиатуры и получать уведомления по их
   * возникновению.
   * @param[in] listener Указатель на слушатель событий клавиатуры.
   */
  MTHD_OVERRIDE(void setListener(typedefs::InputListenerPtr_t listener));

  MTHD_OVERRIDE(void setInputEventListener(typedefs::InputEventListenerPtr_t listener)) {}

#pragma endregion

  /**
   * @brief Уведомляет об нажатии на клавишу.
   *
   * @param[in] evt Хранилище события.
   */
  void notifyKeyPressed(const XEvent &evt);

  /**
   * @brief Уведомляет об отпускании клавиши.
   *
   * @param[in] evt Хранилище события.
   */
  void notifyKeyReleased(const XEvent &evt);

private:
  /**
   * @brief Инициализация устройства.
   *
   * @note Внутренний метод, вызывается в конструкторе.
   */
  void initialize_();

  void disableSystemKeys_();

  void enableSystemKeys_();

  typedefs::InputDeviceManagerPtr_t manager_;  // Указатель на менеджер ввода.
  typedefs::InputListenerPtr_t listener_;
  bool keyboardGrabbed_;
};

}  // namespace sway::ois

#endif  // SWAY_OIS_MAC_DTPKEYBOARD_HPP
