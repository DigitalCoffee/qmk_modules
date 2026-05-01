# Arcane

Arcane keys come from a concept by @empressabyss, who popularized it in their [Nordrassil](https://github.com/empressabyss/nordrassil) layout:

> If the preceding key is on the same hand as the arcane key, it acts as a repeat key. This creates an inward roll for any letter that must repeat: finger->thumb. Double letters make up ~2.5% of all bigrams, which is a significant increase to inward rolling for any layout.
>
> If the preceding key is on the opposite hand to the arcane key, it acts as magic, which, as mentioned in above, will provide varied benefits completely decided by the individual.

This is an implementation of Arcane keys using [Chordal Hold](https://docs.qmk.fm/tap_hold#chordal-hold) to determine which hand pressed the previous key. Sends Alternate Repeat if the hand of the previous key is not the same as the pressed Arcane key, otherwise sends the Repeat Key. Any key assigned `'*'` in `chordal_hold_layout` sends the Repeat Key, following how Chordal Hold does not apply the "opposite hands rule" to them.

## Installation

Add the following to your `keymap.json` to use this module:

```json
{
    "modules": ["DigitalCoffee/arcane"]
}
```

## Keycodes

This module defines the following keycodes:

| Keycode   | Alias  | Description |
|-----------|--------|-------------|
| `ARCANEL` | `ARC_L`| Arcane key for the left hand |
| `ARCANER` | `ARC_R`| Arcane key for the right hand |

## Configuration

### Required QMK Features

- **Chordal Hold** must be enabled and `chordal_hold_layout` must be defined.
- **Alternate Repeat Key** must not be disabled.

### Keymap Implementation

`ARCANEL` must be on the left hand in your keymap and `ARCANER` must be on the right hand. Preferably these should be assigned to opposite thumb keys.

> [!IMPORTANT]
> You must implement `remember_last_key_user()` in your keymap and it must use the return value of `remember_last_key_arcane()` in order to not remember Arcane keys and to properly set the last hand position. The Arcane keys will only work if this is setup properly.
>
> Example implementation in your `keymap.c`:
>
> ```c
> bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
>     return remember_last_key_arcane(keycode, record, remembered_mods);
> }
> ```

It's also possible to customize the functionality of the same and opposite hand Arcane invocations by defining the callbacks `process_arcane_same_hand()` and `process_arcane_opposite_hand()`. You can use `get_last_keycode()` to get the keycode for the previous key.