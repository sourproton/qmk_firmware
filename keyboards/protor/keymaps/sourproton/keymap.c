// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// To flash:
// qmk flash -bl dfu-util-split-left
// qmk flash -bl dfu-util-split-right

#include QMK_KEYBOARD_H

#define _BASE    0
#define _NUM     1
#define _SYM     2
#define _FUN     3
#define _NAV     4
#define _MEDIA   5
#define _MOUSE   6
#define _BUT     7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * BASE LAYER
     * ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
     * │   Q   │   W   │   F   │   P   │   B   │       │   J   │   L   │   U   │   Y   │  '|"  │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │   A   │   R   │   S   │   T   │   G   │       │   M   │   N   │   E   │   I   │   O   │
     * │ SUPER │  ALT  │ CTRL  │ SHIFT │       │       │       │ SHIFT │ CTRL  │  ALT  │ SUPER │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │   Z   │   X   │   C   │   D   │   V   │       │   K   │   H   │  ,|<  │  .|>  │  /|?  │
     * │ [BUT] │ ALTGR │       │       │       │       │       │       │       │ ALTGR │ [BUT] │
     * └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
     *
     *                 ┌───────┐                                       ┌───────┐
     *                 │  ESC  │                                       │  DEL  │
     *                 │[MEDIA]├───────┐                       ┌───────┤ [FUN] │
     *                 └───────┤  SPC  │                       │  BSP  ├───────┘
     *                         │ [NAV] ├───────┐       ┌───────┤ [NUM] │
     *                         └───────┤  TAB  │       │  ENT  ├───────┘
     *                                 │[MOUSE]│       │ [SYM] │
     *                                 └───────┘       └───────┘
     */
    [_BASE] = LAYOUT(
        KC_Q, KC_W, KC_F, KC_P, KC_B,
        KC_J, KC_L, KC_U, KC_Y, KC_QUOTE,
        LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,
        KC_M, RSFT_T(KC_N), RCTL_T(KC_E), LALT_T(KC_I), RGUI_T(KC_O),
        LT(_BUT, KC_Z), RALT_T(KC_X), KC_C, KC_D, KC_V,
        KC_K, KC_H, KC_COMMA, RALT_T(KC_DOT), LT(_BUT, KC_SLASH),
        LT(_MEDIA, KC_ESCAPE), LT(_NAV, KC_SPACE), LT(_MOUSE, KC_TAB),
        LT(_SYM, KC_ENTER), LT(_NUM, KC_BACKSPACE), LT(_FUN, KC_DELETE)
    ),

    /*
     * NUM LAYER
     * ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
     * │   1   │   2   │   3   │   4   │   5   │       │       │       │       │       │       │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │   6   │   7   │   8   │   9   │   0   │       │       │ SHIFT │ CTRL  │  ALT  │ SUPER │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │   -   │   =   │   ;   │   [   │   ]   │       │       │       │       │ ALTGR │       │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
     *
     *                 ┌───────┐                                       ┌───────┐
     *                 │   `   │                                       │       │
     *                 │       ├───────┐                       ┌───────┤       │
     *                 └───────┤  SPC  │                       │///////├───────┘
     *                         │       ├───────┐       ┌───────┤///////│
     *                         └───────┤   \   │       │       ├───────┘
     *                                 │       │       │       │
     *                                 └───────┘       └───────┘
     */
    [_NUM] = LAYOUT(
        KC_1, KC_2, KC_3, KC_4, KC_5,
        _______, _______, _______, _______, _______,
        KC_6, KC_7, KC_8, KC_9, KC_0,
        _______, KC_LEFT_SHIFT, KC_LEFT_CTRL, KC_LEFT_ALT, KC_LEFT_GUI,
        KC_MINUS, KC_EQUAL, KC_SEMICOLON, KC_LEFT_BRACKET, KC_RIGHT_BRACKET,
        _______, _______, _______, KC_RIGHT_ALT, _______,
        KC_GRAVE, KC_SPACE, KC_BACKSLASH,
        _______, _______, _______
    ),

    /*
     * SYM LAYER
     * ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
     * │   !   │   @   │   #   │   $   │   %   │       │       │       │       │       │       │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │   ^   │   &   │   *   │   (   │   )   │       │       │ SHIFT │ CTRL  │  ALT  │ SUPER │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │   _   │   +   │   :   │   {   │   }   │       │       │       │       │ ALTGR │       │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
     *
     *                 ┌───────┐                                       ┌───────┐
     *                 │   ~   │                                       │       │
     *                 │       ├───────┐                       ┌───────┤       │
     *                 └───────┤  SPC  │                       │       ├───────┘
     *                         │       ├───────┐       ┌───────┤       │
     *                         └───────┤   |   │       │///////├───────┘
     *                                 │       │       │///////│
     *                                 └───────┘       └───────┘
     */
    [_SYM] = LAYOUT(
        LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),
        _______, _______, _______, _______, _______,
        LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),
        _______, KC_LEFT_SHIFT, KC_LEFT_CTRL, KC_LEFT_ALT, KC_LEFT_GUI,
        LSFT(KC_MINUS), LSFT(KC_EQUAL), LSFT(KC_SEMICOLON), LSFT(KC_LEFT_BRACKET), LSFT(KC_RIGHT_BRACKET),
        _______, _______, _______, KC_RIGHT_ALT, _______,
        LSFT(KC_GRAVE), KC_SPACE, LSFT(KC_BACKSLASH),
        _______, _______, _______
    ),

    /*
     * FUN LAYER
     * ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
     * │  F1   │  F2   │  F3   │  F4   │  F5   │       │       │       │       │       │       │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │  F6   │  F7   │  F8   │  F9   │  F10  │       │       │ SHIFT │ CTRL  │  ALT  │ SUPER │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │  F11  │  F12  │PRINTSC|SCRLOCK│ PAUSE │       │       │       │       │ ALTGR │       │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
     *
     *                 ┌───────┐                                       ┌───────┐
     *                 │  ESC  │                                       │///////│
     *                 │       ├───────┐                       ┌───────┤///////│
     *                 └───────┤  SPC  │                       │       ├───────┘
     *                         │       ├───────┐       ┌───────┤       │
     *                         └───────┤  TAB  │       │       ├───────┘
     *                                 │       │       │       │
     *                                 └───────┘       └───────┘
     */
    [_FUN] = LAYOUT(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
        _______, _______, _______, _______, _______,
        KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
        _______, KC_LEFT_SHIFT, KC_LEFT_CTRL, KC_LEFT_ALT, KC_LEFT_GUI,
        KC_F11, KC_F12, KC_PRINT_SCREEN, KC_SCROLL_LOCK, KC_PAUSE,
        _______, _______, _______, KC_RIGHT_ALT, _______,
        KC_ESCAPE, KC_SPACE, KC_TAB,
        _______, _______, _______
    ),

    /*
     * NAV LAYER
     * ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
     * │       │       │       │       │       │       │INSERT │ HOME  │  UP   │  END  │ PG U  │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │ SUPER │  ALT  │ CTRL  │ SHIFT │       │       │CAPS L │ LEFT  │ DOWN  │ RIGHT │ PG D  │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │       │ ALTGR │       │       │       │       │       │ PASTE │ COPY  │  CUT  │       │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
     *
     *                 ┌───────┐                                       ┌───────┐
     *                 │       │                                       │  DEL  │
     *                 │       ├───────┐                       ┌───────┤       │
     *                 └───────┤///////│                       │  BSP  ├───────┘
     *                         │///////|───────┐       ┌───────┤       │
     *                         └───────┤       │       │  ENT  ├───────┘
     *                                 │       │       │       │
     *                                 └───────┘       └───────┘
     */
    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______,
        KC_INSERT, KC_HOME, KC_UP, KC_END, KC_PAGE_UP,
        KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, _______,
        KC_CAPS_LOCK, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PAGE_DOWN,
        _______, KC_RIGHT_ALT, _______, _______, _______,
        _______, KC_PASTE, KC_COPY, KC_CUT, _______,
        _______, _______, _______,
        KC_ENTER, KC_BACKSPACE, KC_DELETE
    ),

    /*
     * MEDIA LAYER
     * ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
     * │       │       │       │       │       │       │       │       │ VOL U │       │BRIG U │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │ SUPER │  ALT  │ CTRL  │ SHIFT │       │       │       │ PREV  │ VOL D │ NEXT  │BRIG D │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │       │ ALTGR │       │       │       │       │       │ PLAY  │ MUTE  │ STOP  │       │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
     *
     *                 ┌───────┐                                       ┌───────┐
     *                 │///////│                                       │  DEL  │
     *                 │///////├───────┐                       ┌───────┤       │
     *                 └───────┤       │                       │  BSP  ├───────┘
     *                         │       ├───────┐       ┌───────┤       │
     *                         └───────┤       │       │  ENT  ├───────┘
     *                                 │       │       │       │
     *                                 └───────┘       └───────┘
     */
    [_MEDIA] = LAYOUT(
        _______, _______, _______, _______, _______,
        _______, _______, KC_AUDIO_VOL_UP, _______, KC_BRIGHTNESS_UP,
        KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, _______,
        _______, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK, KC_BRIGHTNESS_DOWN,
        _______, KC_RIGHT_ALT, _______, _______, _______,
        _______, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_MEDIA_STOP, _______,
        _______, _______, _______,
        KC_ENTER, KC_BACKSPACE, KC_DELETE
    ),

    /*
     * MOUSE LAYER
     * ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
     * │       │       │       │       │       │       │       │W LEFT │ M UP  │W RIGHT│ W UP  │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │ SUPER │  ALT  │ CTRL  │ SHIFT │       │       │       │M LEFT │M  DOWN│M RIGHT│ W DO  │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │       │ ALTGR │       │       │       │       │       │ PASTE │ COPY  │  CUT  │       │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
     *
     *                 ┌───────┐                                       ┌───────┐
     *                 │       │                                       │MIDDLE │
     *                 │       ├───────┐                       ┌───────┤       │
     *                 └───────┤       │                       │ LEFT  ├───────┘
     *                         │       ├───────┐       ┌───────┤       │
     *                         └───────┤///////│       │ RIGHT ├───────┘
     *                                 │///////│       │       │
     *                                 └───────┘       └───────┘
     */
    [_MOUSE] = LAYOUT(
        _______, _______, _______, _______, _______,
        _______, KC_MS_WH_LEFT, KC_MS_UP, KC_MS_WH_RIGHT, KC_MS_WH_UP,
        KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, _______,
        _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN,
        _______, KC_RIGHT_ALT, _______, _______, _______,
        _______, KC_PASTE, KC_COPY, KC_CUT, _______,
        _______, _______, _______,
        KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3
    ),

    /*
     * BUTTON LAYER
     * ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
     * │       │       │       │       │       │       │       │       │       │       │       │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │ SUPER │  ALT  │ CTRL  │ SHIFT │       │       │       │ SHIFT │ CTRL  │  ALT  │ SUPER │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │///////│  CUT  │ COPY  │ PASTE │       │       │       │ PASTE │ COPY  │  CUT  │///////│
     * │///////│       │       │       │       │       │       │       │       │       │///////│
     * └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
     *
     *                 ┌───────┐                                       ┌───────┐
     *                 │       │                                       │       │
     *                 │       ├───────┐                       ┌───────┤       │
     *                 └───────┤       │                       │       ├───────┘
     *                         │       ├───────┐       ┌───────┤       │
     *                         └───────┤       │       │       ├───────┘
     *                                 │       │       │       │
     *                                 └───────┘       └───────┘
     */
    [_BUT] = LAYOUT(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, _______,
        _______, KC_LEFT_SHIFT, KC_LEFT_CTRL, KC_LEFT_ALT, KC_LEFT_GUI,
        _______, KC_CUT, KC_COPY, KC_PASTE, _______,
        _______, KC_PASTE, KC_COPY, KC_CUT, _______,
        _______, _______, _______,
        _______, _______, _______
    ),

    /*
     *  LAYER
     * ┌───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┐
     * │       │       │       │       │       │       │       │       │       │       │       │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┤       ├───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │
     * │       │       │       │       │       │       │       │       │       │       │       │
     * └───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┘
     *
     *                 ┌───────┐                                       ┌───────┐
     *                 │       │                                       │       │
     *                 │       ├───────┐                       ┌───────┤       │
     *                 └───────┤       │                       │       ├───────┘
     *                         │       ├───────┐       ┌───────┤       │
     *                         └───────┤       │       │       ├───────┘
     *                                 │       │       │       │
     *                                 └───────┘       └───────┘
     */
    // [_] = LAYOUT(
    //     _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______,
    //     _______, _______, _______,
    //     _______, _______, _______
    // ),
};
