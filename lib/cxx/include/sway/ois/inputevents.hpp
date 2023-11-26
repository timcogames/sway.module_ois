#ifndef SWAY_OIS_INPUTEVENTS_HPP
#define SWAY_OIS_INPUTEVENTS_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois/keycodes.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/**
 * @brief Предоставляет данные для связанных входных событий.
 */
struct EventArgs {
  // Empty
};

// clang-format off
enum class KeyModifier : u32_t {
  CTRL = (1 << 0),
  SHIFT = (1 << 1),
  ALT = (1 << 2)
};
// clang-format on

enum class BtnState : u32_t { PRESSED, RELEASED };
enum class MouseBtn { NONE, LEFT, RIGHT, MIDDLE, Latest };
#define NUM_MOUSE_BTNS core::detail::toUnderlying(MouseBtn::Latest)

struct TouchState {
  uintptr_t id;
  math::vec2f_t pos;
  math::vec2f_t dpos;
  BtnState state;
};

/**
 * @brief Предоставляет данные для событий, связанных с мышью.
 */
struct MouseEventArgs : public EventArgs {
  math::point2f_t position;  // Координаты позиции курсора.
  math::vec2f_t offset;
  math::vec2f_t drag;
  u32_t modifiers;
  s32_t button;  // Код кнопок мыши.
  f32_t deltaZ;
  bool entered;
  BtnState states[NUM_MOUSE_BTNS];
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTEVENTS_HPP
