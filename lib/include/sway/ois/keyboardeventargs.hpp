#ifndef SWAY_OIS_KEYBOARDEVENTARGS_HPP
#define SWAY_OIS_KEYBOARDEVENTARGS_HPP

#include <sway/namespacemacros.hpp>
#include <sway/ois/inputevents.hpp>
#include <sway/ois/keycodes.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/**
 * @brief Предоставляет данные для событий, связанных с клавиатуры.
 */
struct KeyboardEventArgs : public EventArgs {
  KeyboardEventArgs(u32_t code)
      : keycode(code) {}

  u32_t keycode;  // Код клавиши клавиатуры.
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYBOARDEVENTARGS_HPP
