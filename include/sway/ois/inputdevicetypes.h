#ifndef SWAY_OIS_INPUTDEVICETYPES_H
#define SWAY_OIS_INPUTDEVICETYPES_H

#include <sway/namespacemacros.h>
#include <sway/types.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/*!
 * \brief
 *   Перечисление типов устройств ввода.
 */
enum class InputDeviceType_t : u32_t {
  kUndefined,
  kKeyboard, /*!< Клавиатура. */
  kMouse /*!< Мышка. */
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTDEVICETYPES_H
