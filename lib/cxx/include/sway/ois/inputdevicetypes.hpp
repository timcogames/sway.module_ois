#ifndef SWAY_OIS_INPUTDEVICETYPES_HPP
#define SWAY_OIS_INPUTDEVICETYPES_HPP

#include <sway/core.hpp>

namespace sway::ois {

/**
 * @brief \~english Enumeration of input device types. \~russian Перечисление типов устройств ввода.
 */
enum class InputDeviceType : i32_t {
  UNDEFINED = -1,
  KEYBOARD = 0,  //!< \~english Keyboard. \~russian Клавиатура.
  MOUSE,  //!< \~english Mouse. \~russian Мышка.
  Latest
};

}  // namespace sway::ois

#endif  // SWAY_OIS_INPUTDEVICETYPES_HPP
