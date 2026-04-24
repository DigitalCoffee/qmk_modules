#include <quantum.h>

bool open_bracket = false;
bool open_curly_brace = false;
bool open_parentheses = false;

bool was_shift_active = false;

bool process_record_quick_brackets(uint16_t keycode, keyrecord_t *record) {
  const uint8_t mods = get_mods();
  const uint8_t all_mods = (mods | get_weak_mods()
#ifndef NO_ACTION_ONESHOT
                          | get_oneshot_mods()
#endif  // NO_ACTION_ONESHOT
  );
  const uint8_t shift_mods = all_mods & MOD_MASK_SHIFT;

  if (record->event.pressed) {
    switch (keycode) {
      case QUICK_BRACKET:
        if (open_bracket) {
          tap_code16(was_shift_active ? KC_RIGHT_CURLY_BRACE : KC_RIGHT_BRACKET);
          open_bracket = false;
          was_shift_active = false;
        } else {
          tap_code16(KC_LEFT_BRACKET);
          open_bracket = true;
          was_shift_active = shift_mods ? true : false;
        }
        return false;

      case QUICK_CURLY_BRACES:
        if (open_curly_brace) {
          tap_code16(KC_RIGHT_CURLY_BRACE);
          open_curly_brace = false;
        } else {
          tap_code16(KC_LEFT_CURLY_BRACE);
          open_curly_brace = true;
        }
        return false;

      case QUICK_PARENTHESES:
        if (open_parentheses) {
          tap_code16(KC_RIGHT_PAREN);
          open_parentheses = false;
        } else {
          tap_code16(KC_LEFT_PAREN);
          open_parentheses = true;
        }
        return false;
    }
  }
  return true;
}
