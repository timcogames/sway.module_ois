#ifndef SWAY_OIS_INPUTDEVICEBASE_H
#define SWAY_OIS_INPUTDEVICEBASE_H

#include <sway/ois/inputdevicetypes.h>
#include <sway/ois/inputlistener.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputDeviceBase {
public:
  /*!
   * \brief
   *    Конструктор класса.
   */
  InputDeviceBase() {
    // Empty
  }

  /*!
   * \brief
   *    Деструктор класса.
   */
  virtual ~InputDeviceBase() = default;

  /*!
   * \brief
   *    Устанавливает слушатель событий.
   *
   * \param[in] listener
   *    Слушатель событий клавиатуры.
   */
  virtual void setListener(InputListener *listener) = 0;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTDEVICEBASE_H
