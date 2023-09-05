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

/**
 * @brief Предоставляет данные для событий, связанных с мышью.
 */
struct MouseEventArgs : public EventArgs {
  math::point2f_t position;  // Координаты позиции курсора.
  math::vec2f_t offset;
  math::vec2f_t drag;
  s32_t button;  // Код кнопок мыши.
  f32_t deltaZ;
  bool entered;
};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_INPUTEVENTS_HPP
