#ifndef SWAY_OIS_INPUTDEVICETYPES_HPP
#define SWAY_OIS_INPUTDEVICETYPES_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/**
 * @brief Перечисление типов устройств ввода.
 */
enum class InputDeviceType : s32_t {
  UNDEFINED = -1,
  KEYBOARD = 0,  // Клавиатура.
  MOUSE,  // Мышка.
  Latest
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTDEVICETYPES_HPP
