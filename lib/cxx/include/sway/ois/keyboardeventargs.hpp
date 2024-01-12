#ifndef SWAY_OIS_KEYBOARDEVENTARGS_HPP
#define SWAY_OIS_KEYBOARDEVENTARGS_HPP

#include <sway/core.hpp>
#include <sway/ois/inputeventargs.hpp>
#include <sway/ois/keycodes.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/**
 * @brief Предоставляет данные для событий, связанных с клавиатуры.
 */
struct KeyboardEventArgs : public InputEventArgs {
  KeyboardEventArgs(u32_t code)
      : keycode(code) {}

  u32_t keycode;  // Код клавиши клавиатуры.
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYBOARDEVENTARGS_HPP
