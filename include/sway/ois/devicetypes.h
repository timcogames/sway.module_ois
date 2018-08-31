#ifndef SWAY_OIS_DEVICETYPES_H
#define SWAY_OIS_DEVICETYPES_H

#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/*!
 * \brief
 *   Перечисление типов устройств ввода.
 */
enum class DeviceType_t {
	kKeyboard, /*!< Клавиатура. */
	kMouse /*!< Мышка. */
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif // SWAY_OIS_DEVICETYPES_H
