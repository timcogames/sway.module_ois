#ifndef SWAY_OIS_INPUTDEVICE_HPP
#define SWAY_OIS_INPUTDEVICE_HPP

#include <sway/core.hpp>
#include <sway/ois/inputlistener.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

class InputDevice {
public:
  virtual ~InputDevice() = default;

  /**
   * @brief Устанавливает слушатель событий.
   *
   * @param[in] listener Слушатель событий клавиатуры.
   */
  PURE_VIRTUAL(void setListener(InputListener *listener));

  PURE_VIRTUAL(void setInputEventListener(InputEventListener *listener));
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTDEVICE_HPP
