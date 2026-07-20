## Background Images

### How to add a background image
First copy an image in `.PNG` format with a size of `640x480` to anywhere on the SD card. Then when the N64FlashcartMenu is loaded on the N64, browse to the image and then press the `A` Button to preview it on the screen. Press the `A` Button again to open up the confirmation message, which will ask if you want to set a new background image.
<!-- Could use a sample screenshot here -->
Press the `A` Button to confirm and set the image as your new background or press the `B` Button to cancel and return to the image display screen.

### Theme-specific background images
You can also add per-theme background images by placing PNG files in the `sd:/menu/` folder with the following names:

- `background-default.png`
- `background-pastel.png`
- `background-dark-neon.png`
- `background-retro.png`
- `background-dark-mode.png`
- `background-forest.png`
- `background-ocean.png`

When the menu starts, it will load the matching theme background if no custom background has already been selected. When you change the theme in Settings, the menu will attempt to load the corresponding theme PNG immediately.

> Note: the files must be valid `.PNG` images at `640x480` resolution and should be placed directly inside `sd:/menu/`.
