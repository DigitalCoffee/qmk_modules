#include "comma_shift.h"

#if defined(NO_ACTION_ONESHOT)
// One-Shot Shift is required by this module, so error if it's manually disabled.
#error "comma_shift: Please enable One Shot Keys."
#endif

ASSERT_COMMUNITY_MODULES_MIN_API_VERSION(1, 0, 0);

bool process_record_comma_shift(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    if (keycode == KC_SPACE || is_spacelike_key(keycode, record)) {
      if (get_oneshot_mods() & MOD_MASK_SHIFT) {
        clear_oneshot_mods();
        tap_code(KC_COMMA);
      }
    }
  }
  return true;
}

__attribute__((weak)) bool is_space_key(uint16_t keycode, keyrecord_t *record) {
  return false;
}
