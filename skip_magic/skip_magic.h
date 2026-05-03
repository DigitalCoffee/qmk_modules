#pragma once

#include "quantum.h"

uint16_t get_preprevious_keycode(void);
uint8_t  get_preprevious_mods(void);

void     set_preprevious_keycode(uint16_t keycode);
void     set_preprevious_mods(uint8_t mods);

uint16_t get_skip_magic_keycode(void);

uint16_t get_skip_magic_keycode_user(uint16_t keycode, uint8_t mods);

void     skip_magic_invoke(const keyevent_t* event);
