#ifndef SWAY_OIS_INPUTDEVICETYPES_HPP
#define SWAY_OIS_INPUTDEVICETYPES_HPP

#include <sway/core.hpp>

namespace sway::ois {

/**
 * @brief Перечисление типов устройств ввода.
 */
enum class InputDeviceType : i32_t {
  UNDEFINED = -1,
  KEYBOARD = 0,  // Клавиатура.
  MOUSE,  // Мышка.
  Latest
};

}  // namespace sway::ois

#endif  // SWAY_OIS_INPUTDEVICETYPES_HPP
