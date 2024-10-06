#ifndef SWAY_OIS_INPUTDEVICETYPES_HPP
#define SWAY_OIS_INPUTDEVICETYPES_HPP

#include <sway/core.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(ois)

/**
 * @brief Перечисление типов устройств ввода.
 */
enum class InputDeviceType : i32_t {
  UNDEFINED = -1,
  KEYBOARD = 0,  // Клавиатура.
  MOUSE,  // Мышка.
  Latest
};

NS_END()  // namespace ois
NS_END()  // namespace sway

#endif  // SWAY_OIS_INPUTDEVICETYPES_HPP
