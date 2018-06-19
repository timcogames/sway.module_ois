#ifndef SWAY_OIS_INPUTEVENTS_H
#define SWAY_OIS_INPUTEVENTS_H

#include <sway/namespacemacros.h>
#include <sway/types.h>

#include <boost/function.hpp> // boost::function

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

struct EventArgs {
	// Empty
};

/*!
 * \brief
 *    Структура хранит аргументы событий клавиатуры.
 */
struct KeyboardEventArgs : public EventArgs {
	u32_t keycode; /*!< Код клавиши клавиатуры. */
};

/*!
 * \brief
 *    Структура хранит аргументы событий мышки.
 */
struct MouseEventArgs : public EventArgs {
	s32_t x, y; /*!< Координаты позиции курсора. */
	s32_t button; /*!< Код клавиши мышки. */
};

typedef boost::function<void (const KeyboardEventArgs &)> KeyboardEventCallbackFunc_t;
typedef boost::function<void (const MouseEventArgs &)> MouseEventCallbackFunc_t;

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif // SWAY_OIS_INPUTEVENTS_H
