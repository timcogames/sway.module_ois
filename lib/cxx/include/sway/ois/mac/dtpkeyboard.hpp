#ifndef SWAY_OIS_MAC_DTPKEYBOARD_HPP
#define SWAY_OIS_MAC_DTPKEYBOARD_HPP

#include <sway/ois/inputdevice.hpp>
#include <sway/ois/inputdevicemacros.hpp>
#include <sway/ois/inputdevicetypes.hpp>
#include <sway/ois/inputlistener.hpp>
#include <sway/ois/prereqs.hpp>
#include <sway/ois/typedefs.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

/**
 * @brief Представляет устройство клавиатуры.
 */
class DTPKeyboard : public InputDevice {
  DECLARE_CLASS_POINTER_ALIASES(DTPKeyboard)
  DECLARE_INPUTDEVICE_TYPE(InputDeviceType::KEYBOARD)

public:
#pragma region "Ctors/Dtor"

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   *
   * @param[in] mngr Указатель на менеджер ввода.
   */
  DTPKeyboard(InputDeviceManagerPtr_t mngr);

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
  MTHD_OVERRIDE(void setListener(InputListener::Ptr_t listener));

  MTHD_OVERRIDE(void setInputEventListener(InputEventListener::Ptr_t listener)) {}

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

  InputDeviceManagerPtr_t manager_;  // Указатель на менеджер ввода.
  InputListener::Ptr_t listener_;
  bool keyboardGrabbed_;
};

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_MAC_DTPKEYBOARD_HPP
