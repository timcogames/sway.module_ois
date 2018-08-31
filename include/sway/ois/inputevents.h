#ifndef SWAY_OIS_INPUTEVENTS_H
#define SWAY_OIS_INPUTEVENTS_H

#include <sway/namespacemacros.h>
#include <sway/types.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/*!
 * \brief
 *    Предоставляет данные для связанных входных событий.
 */
struct EventArgs {
	// Empty
};

/*!
 * \brief
 *    Предоставляет данные для событий, связанных с клавиатуры.
 */
struct KeyboardEventArgs : public EventArgs {
	u32_t keycode; /*!< Код клавиши клавиатуры. */
};

/*!
 * \brief
 *    Предоставляет данные для событий, связанных с мышью.
 */
struct MouseEventArgs : public EventArgs {
	s32_t x, y; /*!< Координаты позиции курсора. */
	s32_t button; /*!< Код кнопок мыши. */
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif // SWAY_OIS_INPUTEVENTS_H
