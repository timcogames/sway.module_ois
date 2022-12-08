#ifndef SWAY_OIS_MOUSE_HPP
#define SWAY_OIS_MOUSE_HPP

#include <sway/ois/inputdevice.hpp>
#include <sway/ois/inputdevicemacros.hpp>
#include <sway/ois/inputevents.hpp>
#include <sway/ois/inputlistener.hpp>
#include <sway/ois/prereqs.hpp>
#include <sway/ois/typedefs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputDeviceManager;

/**
 * @brief Представляет устройство мыши.
 */
class Mouse : public InputDevice {
public:
  DECLARE_INPUTDEVICE_TYPE(InputDeviceType_t::Mouse)

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   *
   * @param[in] manager Указатель на менеджер ввода.
   */
  Mouse(InputDeviceManager *manager);

  /**
   * @brief Деструктор класса. Освобождает захваченные ресурсы.
   */
  virtual ~Mouse();

  /**
   * @brief Устанавливает слушатель событий.
   *
   * @param[in] listener Слушатель событий мышки.
   */
  MTHD_OVERRIDE(void setListener(InputListener *listener));

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

  InputDeviceManager *manager_;  // Указатель на менеджер ввода.
  MouseEventCallbackFunc_t onMouseButtonDown_;
  MouseEventCallbackFunc_t onMouseButtonUp_;
  MouseEventCallbackFunc_t onMouseMove_;
  bool mouseGrabbed_;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_MOUSE_HPP
