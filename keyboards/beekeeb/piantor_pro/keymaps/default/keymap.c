#include QMK_KEYBOARD_H
#include "keymap_norwegian.h"
#include "sendstring_norwegian.h"
#include <stdio.h>
#include "features/achordion.h"

// bool process_record_user(uint16_t keycode, keyrecord_t* record) {
//   if (!process_achordion(keycode, record)) { return false; }
//   // Your macros ...
//
//   return true;
// }
//
// void matrix_scan_user(void) {
//   achordion_task();
// }

enum unicode_names {
    U_O_LOWER,
    U_O_UPPER,
    U_AE_LOWER,
    U_AE_UPPER,
    U_A_LOWER,
    U_A_UPPER,
};

const uint32_t unicode_map[] PROGMEM = {
    [U_O_LOWER]  = 0x00F8, // ß
    [U_AE_LOWER] = 0x00E6, // ẞ
    [U_A_LOWER]  = 0x00E5, // ñ
    [U_O_UPPER]  = 0x00D8, // ß
    [U_AE_UPPER] = 0x00C6, // ẞ
    [U_A_UPPER]  = 0x00C5, // ñ
};

// ß and ẞ keycode.
#define U_O XP(U_O_LOWER, U_O_UPPER)
// ñ and Ñ keycode.
#define U_AE XP(U_AE_LOWER, U_AE_UPPER)
// ç and Ç keycode.
#define U_A XP(U_A_LOWER, U_A_UPPER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │GUI├───┐           ┌───┤Alt│
     *               └───┤Bsp├───┐   ┌───┤Ent├───┘
     *                   └───┤   │   │   ├───┘
     *                       └───┘   └───┘
     */
    [0] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC, KC_LCTL, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, LT(1, KC_TAB), LT(2, KC_SPC), LT(2, KC_ESC), LT(1, KC_BSPC), LT(2, KC_ENT), LT(1, KC_DEL)),
    [1] = LAYOUT_split_3x6_3(KC_TRNS, KC_TRNS, KC_PERC, KC_ASTR, KC_HASH, KC_TRNS, KC_CIRC, KC_LPRN, KC_RPRN, KC_TILD, KC_DQUO, KC_TRNS, KC_GRV, KC_DLR, KC_EXLM, KC_PLUS, KC_EQL, KC_PIPE, KC_AMPR, KC_LCBR, KC_RCBR, KC_QUOT, KC_GRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_AT, KC_MINS, KC_UNDS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_CIRC, KC_BSLS, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [2] = LAYOUT_split_3x6_3(KC_GRV, QK_BOOT, KC_7, KC_8, KC_9, KC_NO, KC_TRNS, U_AE, U_O, U_A, KC_NO, KC_TRNS, KC_F1, KC_LGUI, LALT_T(KC_4), LCTL_T(KC_5), LSFT_T(KC_6), KC_F6, KC_LEFT, RSFT_T(KC_DOWN), RCTL_T(KC_UP), RALT_T(KC_RGHT), KC_RGUI, KC_NO, KC_F7, KC_0, KC_1, KC_2, KC_3, KC_F12, KC_PLUS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_0, CW_TOGG, CW_TOGG, KC_TRNS, KC_TRNS)};

// bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
//     return achordion_opposite_hands(tap_hold_record, other_record);
// }
