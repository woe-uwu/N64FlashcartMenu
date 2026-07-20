#include <libdragon.h>

#include "utils/fs.h"
#include "../png_decoder.h"
#include "views.h"

#define MENU_SPLASH_FILE "splash.png"
#define MENU_SPLASH_DURATION_MS 10000

static bool splash_image_loading;
static bool splash_image_loaded;
static bool splash_image_failed;
static surface_t *splash_image;
static uint64_t splash_start_ticks;

static void splash_callback (png_err_t err, surface_t *decoded_image, void *callback_data) {
    (void) callback_data;

    splash_image_loading = false;
    if (err == PNG_OK && decoded_image != NULL) {
        splash_image = decoded_image;
        splash_image_loaded = true;
    } else {
        splash_image_failed = true;
    }
}

static void splash_deinit (void) {
    if (splash_image_loading) {
        png_decoder_abort();
        splash_image_loading = false;
    }

    if (splash_image) {
        surface_free(splash_image);
        free(splash_image);
        splash_image = NULL;
    }
}

static void draw (menu_t *menu, surface_t *d) {
    rdpq_attach_clear(d, NULL);

    if (splash_image_loaded) {
        uint16_t x = (d->width > splash_image->width) ? ((d->width - splash_image->width) / 2) : 0;
        uint16_t y = (d->height > splash_image->height) ? ((d->height - splash_image->height) / 2) : 0;

        rdpq_mode_push();
            rdpq_set_mode_copy(false);
            rdpq_tex_blit(splash_image, x, y, NULL);
        rdpq_mode_pop();
    } else {
        ui_components_background_draw();

        rdpq_textparms_t title_textparms = {
            .width = d->width,
            .height = 24,
            .align = ALIGN_CENTER,
            .wrap = WRAP_NONE
        };

        rdpq_text_print(&title_textparms, FNT_DEFAULT, 0, d->height / 2 - 18, "N64FlashcartMenu");
        rdpq_text_print(&title_textparms, FNT_DEFAULT, 0, d->height / 2 + 8, "Loading...");
    }

    rdpq_detach_show();
}

static void splash_load (menu_t *menu) {
    splash_image_loading = false;
    splash_image_loaded = false;
    splash_image_failed = false;
    splash_image = NULL;
    splash_start_ticks = get_ticks_ms();

    path_t *path = path_init(menu->storage_prefix, "menu");
    path_push(path, MENU_SPLASH_FILE);

    if (file_exists(path_get(path))) {
        png_err_t err = png_decoder_start(path_get(path), 640, 480, splash_callback, menu);
        if (err == PNG_OK) {
            splash_image_loading = true;
        } else {
            splash_image_failed = true;
        }
    } else {
        splash_image_failed = true;
    }

    path_free(path);
}

static void finish_startup (menu_t *menu) {
#ifdef FEATURE_AUTOLOAD_ROM_ENABLED
    // FIXME: rather than use a controller button, would it be better to use the cart button?
    JOYPAD_PORT_FOREACH (port) {
        joypad_poll();
        joypad_buttons_t b_held = joypad_get_buttons_held(port);

        if (menu->settings.rom_autoload_enabled && b_held.start) {
            menu->settings.rom_autoload_enabled = false;
            menu->settings.rom_autoload_path = "";
            menu->settings.rom_autoload_filename = "";
            settings_save(&menu->settings);
        }
    }
    if (menu->settings.rom_autoload_enabled) {
        menu->browser.directory = path_init(menu->storage_prefix, menu->settings.rom_autoload_path);
        menu->load.rom_path = path_clone_push(menu->browser.directory, menu->settings.rom_autoload_filename);
        menu->load_pending.rom_file = true;
        menu->next_mode = MENU_MODE_LOAD_ROM;

        return;
    }
#endif
    
    if (menu->settings.first_run) {
        menu->settings.first_run = false;
        settings_save(&menu->settings);
        menu->next_mode = MENU_MODE_CREDITS;
    }
    else {
        menu->next_mode = MENU_MODE_BROWSER;
    }
}

void view_startup_init (menu_t *menu) {
    if (menu->settings.splash_screen_enabled) {
        splash_load(menu);
    }
}

void view_startup_display (menu_t *menu, surface_t *display) {
    if (!menu->settings.splash_screen_enabled) {
        rdpq_attach_clear(display, NULL);
        rdpq_detach_show();
        finish_startup(menu);
        return;
    }

    if (!splash_start_ticks) {
        splash_load(menu);
    }

    bool skip_splash = false;

    JOYPAD_PORT_FOREACH (port) {
        joypad_buttons_t pressed = joypad_get_buttons_pressed(port);
        if (pressed.raw != 0) {
            skip_splash = true;
        }
    }

    draw(menu, display);

    if (skip_splash) {
        splash_deinit();
        finish_startup(menu);
        return;
    }

    if (splash_image_loaded || splash_image_failed) {
        uint64_t elapsed = get_ticks_ms() - splash_start_ticks;
        if (elapsed >= MENU_SPLASH_DURATION_MS) {
            splash_deinit();
            finish_startup(menu);
        }
    }
}
