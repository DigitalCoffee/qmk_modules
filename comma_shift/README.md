# Comma Shift

Comma-Shift comes from a concept found in this [Reddit comment](https://www.reddit.com/r/ErgoMechKeyboards/comments/1n201er/comment/nb2tg1s/).

Generally, the keys that follow a comma and One Shot Shift are different, allowing these to be condensed into a single key.

The key difference with this implementation is that rather than "trapping" the comma key, this is effectively an alternate Shift key for `KC_SPACE` that sends `, ` only if One Shot Shift is active. This allows the benefits of holding for Shift, One Shot timeout, and double-tap for Caps Word, all for free and does not conflict with Sentence Case.

## Installation

Add the following to your `keymap.json` to use this module:

```json
{
    "modules": ["DigitalCoffee/comma_shift"]
}
```

## Keycodes

This module defines no additional keycodes.

## Configuration

### Required QMK Features

- **One Shot Key** must not be disabled.

### Keymap Implementation

Use either `OS_LSFT` or `OS_RSFT` in your keymap, or call `set_oneshot_mods()` for either Shift modifier. Pressing `KC_SPACE` immediately after will send a comma first, followed by a space.

It's possible to define additional keys that act as `KC_SPACE` for this feature by implementing the callback `is_spacelike_key()` in your keymap. This is useful for example when you have a layer tap defined that sends space when tapped. Implement it in your `keymap.c` as follows in that case:
```c
bool is_spacelike_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_SPACE:
            return record->tap.count;
    }
    return false;
}
```
