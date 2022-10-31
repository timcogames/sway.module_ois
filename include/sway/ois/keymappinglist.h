#ifndef SWAY_OIS_KEYMAPPINGLIST_H
#define SWAY_OIS_KEYMAPPINGLIST_H

#include <sway/namespacemacros.h>
#include <sway/ois/keycodes.h>
#include <sway/ois/keymapping.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(ois)

static const KeyMapping XtoKeycode[] = {{XK_a, kKeyCode_A}, {XK_b, kKeyCode_B}, {XK_c, kKeyCode_C}, {XK_d, kKeyCode_D},
    {XK_e, kKeyCode_E}, {XK_f, kKeyCode_F}, {XK_g, kKeyCode_G}, {XK_h, kKeyCode_H}, {XK_i, kKeyCode_I},
    {XK_j, kKeyCode_J}, {XK_k, kKeyCode_K}, {XK_l, kKeyCode_L}, {XK_m, kKeyCode_M}, {XK_n, kKeyCode_N},
    {XK_o, kKeyCode_O}, {XK_p, kKeyCode_P}, {XK_q, kKeyCode_Q}, {XK_r, kKeyCode_R}, {XK_s, kKeyCode_S},
    {XK_t, kKeyCode_T}, {XK_u, kKeyCode_U}, {XK_v, kKeyCode_V}, {XK_w, kKeyCode_W}, {XK_x, kKeyCode_X},
    {XK_y, kKeyCode_Y}, {XK_z, kKeyCode_Z}};

NAMESPACE_END(ois)
NAMESPACE_END(sway)

#endif  // SWAY_OIS_KEYMAPPINGLIST_H
