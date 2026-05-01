#pragma once

#include "quantum.h"

void process_arcane_same_hand(uint16_t keycode, keyrecord_t* record);

void process_arcane_opposite_hand(uint16_t keycode, keyrecord_t* record);

bool remember_last_key_arcane(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods);
