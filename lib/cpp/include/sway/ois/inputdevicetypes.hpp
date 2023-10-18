#ifndef SWAY_OIS_INPUTDEVICETYPES_HPP
#define SWAY_OIS_INPUTDEVICETYPES_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/**
 * @brief Перечисление типов устройств ввода.
 */
enum class InputDeviceType : u32_t {
  UNDEFINED,
  KEYBOARD,  // Клавиатура.
  MOUSE  // Мышка.
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTDEVICETYPES_HPP
