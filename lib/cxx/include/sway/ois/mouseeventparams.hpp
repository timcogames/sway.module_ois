#ifndef SWAY_OIS_MOUSEEVENTPARAMS_HPP
#define SWAY_OIS_MOUSEEVENTPARAMS_HPP

#include <sway/core.hpp>
#include <sway/math.hpp>
#include <sway/ois/inputactionstates.hpp>
#include <sway/ois/inputeventparams.hpp>
#include <sway/ois/mousebuttoncodes.hpp>

namespace sway::ois {

struct MouseButtonEventParams {
  i32_t button;
};

struct MouseMoveEventParams {
  math::point2f_t location;
};

struct MouseWheelEventParams {
  f32_t delta;
};

/**
 * @brief \~english Provides data for mouse events. \~russian Предоставляет данные для событий, связанных с мышью.
 */
struct MouseEventParams : public InputEventParams {
  math::point2f_t position;  //!< \~english Cursor position. \~russian Координаты позиции курсора.
  math::vec2f_t offset;
  math::vec2f_t drag;
  u32_t modifiers;
  i32_t button;  //!< \~english Button code. \~russian Код кнопок мыши.
  f32_t deltaZ;
  bool entered;
  InputActionState states[NUM_MOUSE_BTNS];
};

}  // namespace sway::ois

#endif  // SWAY_OIS_MOUSEEVENTPARAMS_HPP
