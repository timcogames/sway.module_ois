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

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   *
   * @param[in] mngr Указатель на менеджер ввода.
   */
  DTPKeyboard(typedefs::InputDeviceManagerPtr_t mngr);

  /**
   * @brief Деструктор класса. Освобождает захваченные ресурсы.
   */
  virtual ~DTPKeyboard();

#pragma endregion

#pragma region "Override InputDevice methods"

  /**
   * @brief Устанавливает слушатель событий.
   *
   * @param[in] listener Слушатель событий клавиатуры.
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
