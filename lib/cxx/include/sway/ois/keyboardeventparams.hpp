#ifndef SWAY_OIS_KEYBOARDEVENTPARAMS_HPP
#define SWAY_OIS_KEYBOARDEVENTPARAMS_HPP

#include <sway/core.hpp>
#include <sway/ois/inputactionstates.hpp>
#include <sway/ois/inputeventparams.hpp>
#include <sway/ois/keycodes.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/**
 * @brief Предоставляет данные для событий, связанных с клавиатуры.
 */
struct KeyboardEventParams : public InputEventParams {
  KeyboardEventParams(u32_t code)
      : keyCode(code) {}

  u32_t keyCode;  // Код клавиши клавиатуры.
  // InputActionState state;
  // std::string text;
  // std::bitset<KeyModifier> modifiers;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYBOARDEVENTPARAMS_HPP
