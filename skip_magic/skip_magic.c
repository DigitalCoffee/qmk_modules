#include "skip_magic.h"

ASSERT_COMMUNITY_MODULES_MIN_API_VERSION(1, 0, 0);

static uint16_t preprevious_keycode = 0;
static uint8_t  preprevious_mods    = 0;

static uint16_t previous_keycode = 0;
static uint8_t  previous_mods    = 0;

uint16_t get_preprevious_keycode(void) {
  return preprevious_keycode;
}

uint8_t get_preprevious_mods(void) {
  return preprevious_mods;
}

void set_preprevious_keycode(uint16_t keycode) {
  preprevious_keycode = keycode;
}

void set_preprevious_mods(uint8_t mods) {
  preprevious_mods = mods;
}

uint16_t get_skip_magic_keycode(void) {
  uint16_t user_keycode = get_skip_magic_keycode_user(preprevious_keycode, preprevious_mods);

  if (user_keycode != KC_TRANSPARENT) {
    return user_keycode;
  }

  return preprevious_keycode;
}

__attribute__((weak)) uint16_t get_skip_magic_keycode_user(uint16_t keycode, uint8_t mods) {
    return KC_TRANSPARENT;
}

void skip_magic_invoke(const keyevent_t* event) {
  if (get_repeat_key_count() || !preprevious_keycode) {
    return;
  }

  uint16_t registered_keycode = get_last_keycode();
  uint8_t  registered_mods = get_last_mods();

  set_last_keycode(get_skip_magic_keycode());
  set_last_mods(preprevious_mods);

  repeat_key_invoke(event);

  set_last_keycode(registered_keycode);
  set_last_mods(registered_mods);
}

bool process_record_skip_magic(uint16_t keycode, keyrecord_t* record) {
  if (keycode == SKIP_MAGIC) {
    skip_magic_invoke(&record->event);
    return false;
  }

  return true;
}

void post_process_record_skip_magic(uint16_t keycode, keyrecord_t* record) {
  if (get_repeat_key_count()) {
    return;
  }

  if (record->event.pressed && process_last_key(keycode, record) && keycode == get_last_keycode()) {
    preprevious_keycode = previous_keycode;
    preprevious_mods = previous_mods;

    previous_keycode = get_last_keycode();
    previous_mods = get_last_mods();
  }
}
