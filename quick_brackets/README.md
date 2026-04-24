# Quick Brackets

Press a key to get an open bracket `[`. Press the same key to get a closing bracket `]`. This is repeated the next time the key is pressed.

This enables using the same key to send left and right brackets/curly braces/parentheses.

Add the following to your `keymap.json` to use this module:

```json
{
    "modules": ["DigitalCoffee/quick_brackets"]
}
```

This module defines the following keycodes:

| Keycode              |  Alias      | Description         |
|----------------------|-------------|---------------------|
| `QUICK_BRACKET`      | `QK_BRKT`   | Sends `[`, then `]` |
| `QUICK_CURLY_BRACES` | `QK_CBKT`   | Sends `{`, then `}` |
| `QUICK_PARENTHESES`  | `QK_PREN`   | Sends `(`, then `)` |

Pressing `QUICK_BRACKET` while Shift is active will send a curly brace instead. This modifier is remembered for the next time `QUICK_BRACKET` is pressed.
