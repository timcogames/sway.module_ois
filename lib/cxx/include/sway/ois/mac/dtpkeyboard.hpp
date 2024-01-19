#ifndef SWAY_OIS_MAC_DTPKEYBOARD_HPP
#define SWAY_OIS_MAC_DTPKEYBOARD_HPP

#include <sway/ois/inputdevice.hpp>
#include <sway/ois/inputdevicemacros.hpp>
#include <sway/ois/inputdevicetypes.hpp>
#include <sway/ois/inputlistener.hpp>
#include <sway/ois/prereqs.hpp>
#include <sway/ois/typedefs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputDeviceManager;

/**
 * @brief Представляет устройство клавиатуры.
 */
class DTPKeyboard : public InputDevice {
public:
  DECLARE_INPUTDEVICE_TYPE(InputDeviceType::KEYBOARD)

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   *
   * @param[in] mngr Указатель на менеджер ввода.
   */
  DTPKeyboard(InputDeviceManager *mngr);

  /**
   * @brief Деструктор класса. Освобождает захваченные ресурсы.
   */
  virtual ~DTPKeyboard();

  /**
   * @brief Устанавливает слушатель событий.
   *
   * @param[in] listener Слушатель событий клавиатуры.
   */
  MTHD_OVERRIDE(void setListener(InputListener *listener));

  MTHD_OVERRIDE(void setInputEventListener(InputEventListener *listener)) {}

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

  InputDeviceManager *manager_;  // Указатель на менеджер ввода.
  InputListener *listener_;
  bool keyboardGrabbed_;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_MAC_DTPKEYBOARD_HPP
