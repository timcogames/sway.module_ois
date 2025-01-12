#ifndef SWAY_OIS_KEYBOARDEVENTPARAMS_HPP
#define SWAY_OIS_KEYBOARDEVENTPARAMS_HPP

#include <sway/core.hpp>
#include <sway/ois/inputactionstates.hpp>
#include <sway/ois/inputeventparams.hpp>
#include <sway/ois/keycodes.hpp>

namespace sway::ois {

/**
 * @brief \~english Provides data for keyboard events. \~russian Предоставляет данные для событий, связанных с
 * клавиатуры.
 */
struct KeyboardEventParams : public InputEventParams {
  KeyboardEventParams(u32_t code)
      : keyCode(code) {}

  u32_t keyCode;  //!< \~english Keyboard key code. \~russian Код клавиши клавиатуры.

  // InputActionState state;
  // std::string text;
  // std::bitset<KeyModifier> modifiers;
};

}  // namespace sway::ois

#endif  // SWAY_OIS_KEYBOARDEVENTPARAMS_HPP
