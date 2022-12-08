#ifndef SWAY_OIS_INPUTDEVICETYPES_HPP
#define SWAY_OIS_INPUTDEVICETYPES_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/**
 * @brief Перечисление типов устройств ввода.
 */
enum class InputDeviceType_t : u32_t {
  Undefined,
  Keyboard,  // Клавиатура.
  Mouse  // Мышка.
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTDEVICETYPES_HPP
