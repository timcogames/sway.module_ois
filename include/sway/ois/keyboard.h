#ifndef SWAY_OIS_KEYBOARD_H
#define SWAY_OIS_KEYBOARD_H

#include <sway/ois/inputdevicebase.h>
#include <sway/ois/inputdevicemacros.h>
#include <sway/ois/inputevents.h>
#include <sway/ois/inputlistener.h>
#include <sway/ois/prereqs.h>
#include <sway/ois/typedefs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputDeviceManager;

/*!
 * \brief
 *    Представляет устройство клавиатуры.
 */
class Keyboard : public InputDeviceBase {
  DECLARE_INPUTDEVICE_TYPE(InputDeviceType_t::kKeyboard)

public:
  /*!
   * \brief
   *    Конструктор класса.
   *
   *    Выполняет инициализацию нового экземпляра класса.
   *
   * \param[in] manager
   *    Указатель на менеджер ввода.
   */
  Keyboard(InputDeviceManager *manager);

  /*!
   * \brief
   *    Деструктор класса.
   *
   *    Освобождает захваченные ресурсы.
   */
  virtual ~Keyboard();

  /*!
   * \brief
   *    Устанавливает слушатель событий.
   *
   * \param[in] listener
   *    Слушатель событий клавиатуры.
   */
  virtual void setListener(InputListener *listener);

  /*!
   * \brief
   *    Уведомляет об нажатии на клавишу.
   *
   * \param[in] event
   *    Хранилище события.
   */
  void notifyKeyPressed(const XEvent &event);

  /*!
   * \brief
   *    Уведомляет об отпускании клавиши.
   *
   * \param[in] event
   *    Хранилище события.
   */
  void notifyKeyReleased(const XEvent &event);

private:
  /*!
   * \brief
   *    Инициализация устройства.
   *
   * \note
   *    Внутренний метод, вызывается в конструкторе.
   */
  void initialize_();

  void disableSystemKeys_();

  void enableSystemKeys_();

private:
  InputDeviceManager *manager_; /*!< Указатель на менеджер ввода. */
  InputListener *listener_;
  bool keyboardGrabbed_;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYBOARD_H
