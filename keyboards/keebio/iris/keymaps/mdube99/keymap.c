#include QMK_KEYBOARD_H
#include "features/select_word.h"


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAME 3

#define HOME_Z  LGUI_T(KC_T)
#define HOME_SL RGUI_T(KC_SLSH)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  GAME,

  // Custom keycodes
  SELWORD,
  CMD_TAB,
  TMUX_LEADER,
  VOICE_MUTE,
};

// Tap dancing
enum {
    TD_SFT_QUES,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_SFT_QUES] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_QUES),
};

// combos
const uint16_t PROGMEM lctl_spc[] = { MT(MOD_LCTL, KC_ESC), KC_SPC, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
  COMBO(lctl_spc, KC_ENTER),
};

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
MT(MOD_LCTL, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_PSCR,      TMUX_LEADER,  KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(TD_SFT_QUES),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI,  LOWER,   KC_SPC,                    KC_ENTER, LT(RAISE, KC_BSPC),  MT(MOD_LALT, MOD_RCTL)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_PSCR, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_END, KC_AMPR, KC_ASTR, KC_LBRC,  KC_RBRC, KC_EQL, 
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     CMD_TAB,   KC_1,    KC_2,    KC_3,    KC_4,    KC_Y,                              KC_HOME, U_CPY,   U_PST,   KC_END,  KC_MINUS,   KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     TMUX_LEADER,  _______, KC_LEFT, KC_DEL, KC_UP,   KC_LBRC,                            KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT, KC_RIGHT, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, _______, VOICE_MUTE, _______, KC_DOWN, KC_LCBR, KC_LPRN,          KC_RPRN,   KC_N,  KC_PGDN, KC_PGUP,  KC_P3,   KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_LGUI, _______, KC_DEL,                    KC_COPY, SELWORD, KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV,  KC_S,   KC_VOLU, KC_PGUP, KC_UNDS,                            KC_MS_L,  KC_MS_D, KC_MS_U, KC_MS_R, RGB_VAI, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN,  KC_B,    KC_LPRN,          CG_TOGG, KC_BTN1, KC_BTN3, KC_BTN2, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_UNDS, TG(GAME), KC_PMNS,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_GAME] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_PSCR,      TMUX_LEADER,  KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(TD_SFT_QUES),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI,  LOWER,   KC_SPC,                    KC_ENTER, LT(RAISE, KC_BSPC),  KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_select_word(keycode, record, SELWORD)) { return false; }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case CMD_TAB:
      if (record->event.pressed) {
        // when keycode CMD_TAB is pressed
        SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_TAB));
      } else {
        // when keycode CMD_TAB is released
      }
      break;
    case TMUX_LEADER:
      if (record->event.pressed) {
        // when keycode TMUX_LEADER is pressed
        // SEND_STRING(SS_TAP(X_LCTL)SS_TAP(X_A));
        SEND_STRING(SS_LCTL("a"));
      } else {
        // when keycode TMUX_LEADER is released
      }
      break;
    case VOICE_MUTE:
      if (record->event.pressed) {
        // when keycode VOICE_MUTE is pressed
        SEND_STRING(SS_LCTL("M"));
      } else {
        // when keycode VOICE_MUTE is released
      }
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _GAME);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _GAME);

        // when the layer toggler key for LOWER is released,
        // also release the LGUI key
        SEND_STRING(SS_UP(X_LGUI));
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _GAME);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _GAME);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        layer_on(_GAME);
      } else {
        layer_off(_GAME);
      }
      return false;
      break;
  }
  return true;
}
