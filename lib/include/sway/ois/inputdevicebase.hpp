#ifndef SWAY_OIS_INPUTDEVICEBASE_HPP
#define SWAY_OIS_INPUTDEVICEBASE_HPP

#include <sway/ois/inputdevicetypes.hpp>
#include <sway/ois/inputlistener.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputDeviceBase {
public:
  /**
   * @brief Конструктор класса.
   *
   */
  InputDeviceBase() {
    // Empty
  }

  /**
   * @brief Деструктор класса.
   *
   */
  virtual ~InputDeviceBase() = default;

  /**
   * @brief Устанавливает слушатель событий.
   *
   * @param[in] listener Слушатель событий клавиатуры.
   *
   */
  virtual void setListener(InputListener *listener) = 0;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTDEVICEBASE_HPP
