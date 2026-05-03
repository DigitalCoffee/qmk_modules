# Skip Magic

Skip Magic helps avoid same-finger and/or same-key skipgrams by sending a key based on the key before the last key pressed.

The original concept comes from the [Afterburner keyboard layout](https://blog.simn.me/posts/2025/afterburner/).

## Installation

Add the following to your `keymap.json` to use this module:

```json
{
    "modules": ["DigitalCoffee/skip_magic"]
}
```

## Keycodes

This module defines the following keycodes:

| Keycode      | Alias    | Description |
|--------------|----------|-------------|
| `SKIP_MAGIC` | `SKP_MGC`| Repeat the preprevious key, or send an alternate key based on the preprevious key |


## Configuration

### Keymap Implementation

> [!IMPORTANT]
> You must implement `remember_last_key_user()` in your keymap and it must return `false` for the Skip Magic keycode.
>
> Example implementation in your `keymap.c`:
>
> ```c
> bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
>     if (keycode == SKIP_MAGIC) {
>         return false;
>     }
>     return true;
> }
> ```

### Optional Customization

Skip Magic repeats the preprevious key by default. Implement the `get_skip_magic_keycode_user()` callback if you want to send a different key when Skip Magic is pressed:

```c
uint16_t get_skip_magic_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_A:
            return KC_B;
    }
    return KC_TRNS;
}
```