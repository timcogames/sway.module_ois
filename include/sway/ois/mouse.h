#ifndef SWAY_OIS_MOUSE_H
#define SWAY_OIS_MOUSE_H

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
 *    Представляет устройство мыши.
 */
class Mouse : public InputDeviceBase {
  DECLARE_INPUTDEVICE_TYPE(InputDeviceType_t::kMouse)

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
  Mouse(InputDeviceManager *manager);

  /*!
   * \brief
   *    Деструктор класса.
   *
   *    Освобождает захваченные ресурсы.
   */
  virtual ~Mouse();

  /*!
   * \brief
   *    Устанавливает слушатель событий.
   *
   * \param[in] listener
   *    Слушатель событий мышки.
   */
  virtual void setListener(InputListener *listener);

  void notifyMouseMove(const XEvent &event);

  void notifyMouseButtonDown(const XEvent &event);

  void notifyMouseButtonUp(const XEvent &event);

private:
  /*!
   * \brief
   *    Инициализация устройства.
   *
   * \note
   *    Внутренний метод, вызывается в конструкторе.
   */
  void initialize_();

private:
  InputDeviceManager *manager_; /*!< Указатель на менеджер ввода. */
  MouseEventCallbackFunc_t onMouseButtonDown_;
  MouseEventCallbackFunc_t onMouseButtonUp_;
  MouseEventCallbackFunc_t onMouseMove_;
  bool mouseGrabbed_;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_MOUSE_H
