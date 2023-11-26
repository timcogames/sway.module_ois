#ifndef SWAY_OIS_MAC_DTPKEYMAPPINGLIST_HPP
#define SWAY_OIS_MAC_DTPKEYMAPPINGLIST_HPP

#include <sway/namespacemacros.hpp>
#include <sway/ois/keycodes.hpp>
#include <sway/ois/keymapping.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

// clang-format off
static const KeyMapping XtoKeyCode[] = {
  {XK_a, KeyCode::KC_A},
  {XK_b, KeyCode::KC_B},
  {XK_c, KeyCode::KC_C},
  {XK_d, KeyCode::KC_D},
  {XK_e, KeyCode::KC_E},
  {XK_f, KeyCode::KC_F},
  {XK_g, KeyCode::KC_G},
  {XK_h, KeyCode::KC_H},
  {XK_i, KeyCode::KC_I},
  {XK_j, KeyCode::KC_J},
  {XK_k, KeyCode::KC_K},
  {XK_l, KeyCode::KC_L},
  {XK_m, KeyCode::KC_M},
  {XK_n, KeyCode::KC_N},
  {XK_o, KeyCode::KC_O},
  {XK_p, KeyCode::KC_P},
  {XK_q, KeyCode::KC_Q},
  {XK_r, KeyCode::KC_R},
  {XK_s, KeyCode::KC_S},
  {XK_t, KeyCode::KC_T},
  {XK_u, KeyCode::KC_U},
  {XK_v, KeyCode::KC_V},
  {XK_w, KeyCode::KC_W},
  {XK_x, KeyCode::KC_X},
  {XK_y, KeyCode::KC_Y},
  {XK_z, KeyCode::KC_Z}
};  // clang-format on

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_MAC_DTPKEYMAPPINGLIST_HPP
