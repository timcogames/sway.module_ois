#ifndef SWAY_OIS_MOUSEEVENTARGS_HPP
#define SWAY_OIS_MOUSEEVENTARGS_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois/inputbuttonstates.hpp>
#include <sway/ois/inputeventargs.hpp>
#include <sway/ois/mousebuttons.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

/**
 * @brief Предоставляет данные для событий, связанных с мышью.
 */
struct MouseEventArgs : public InputEventArgs {
  math::point2f_t position;  // Координаты позиции курсора.
  math::vec2f_t offset;
  math::vec2f_t drag;
  u32_t modifiers;
  s32_t button;  // Код кнопок мыши.
  f32_t deltaZ;
  bool entered;
  InputButtonState states[NUM_MOUSE_BTNS];
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_MOUSEEVENTARGS_HPP
