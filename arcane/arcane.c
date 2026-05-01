#include "arcane.h"

#if defined(NO_ALT_REPEAT_KEY)
#error "Arcane: Please enable Alternate Repeat Key."
#endif

#if !defined(CHORDAL_HOLD)
#error "Arcane: Please enable Chordal Hold."
#endif

ASSERT_COMMUNITY_MODULES_MIN_API_VERSION(1, 0, 0);

// L, R, or * based on chordal_hold_layout
static char last_hand;

bool process_record_arcane(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case ARCANEL:
    case ARCANER:
      if (get_repeat_key_count()) {
          return true;
      }
      if (!last_hand) {
        // Do nothing if there's no key to repeat
      } else if ((keycode == ARCANEL && last_hand == 'R') || (keycode == ARCANER && last_hand == 'L')) {
        process_arcane_opposite_hand(keycode, record);
      } else {
        process_arcane_same_hand(keycode, record);
      }
      return false;
  }
  return true;
}

__attribute__((weak)) void process_arcane_same_hand(uint16_t keycode, keyrecord_t* record) {
  repeat_key_invoke(&record->event);
}

__attribute__((weak)) void process_arcane_opposite_hand(uint16_t keycode, keyrecord_t* record) {
  alt_repeat_key_invoke(&record->event);
}

bool remember_last_key_arcane(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
  switch (keycode) {
      case ARCANEL:
      case ARCANER:
          return false; // Ignore Arcane keys
  }
  // Save hand position of the key
  last_hand = chordal_hold_layout[record->event.key.row][record->event.key.col];
  // There may not be a position for the key if it's not defined, a combo, etc.
  if (!last_hand) {
      last_hand = '*';
  }
  return true;
}
