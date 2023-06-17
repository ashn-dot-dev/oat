#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <oat.h>

// Public Pixel Font, version 1.1.
// Licensed as Creative Commons Zero v1.0 Universal.
// https://ggbot.itch.io/public-pixel-font
//
// $ xxd -i assets/PublicPixel.ttf > assets/PublicPixel.c
#include "assets/PublicPixel.c"
// $ xxd -i assets/DVDLogo.png > assets/DVDLogo.c
#include "assets/DVDLogo.c"
// $ xxd -i assets/FaceSpriteSheet.png > assets/FaceSpriteSheet.c
#include "assets/FaceSpriteSheet.c"
// $ xxd -i assets/Bump.ogg > assets/Bump.c
#include "assets/Bump.c"

#define SCREEN_W 640
#define SCREEN_H 480
#define SQUARE_SIDE_LENGTH 8

#define OFFSET 2
#define MARGIN 4

static double const PI = 3.14159265358979323846;
static double const TIMESTEP = 1.0 / 60.0;

static void
randomize_pixel_colors(struct oat_sprite* dvd)
{
    uint8_t r = (uint8_t)oat_random_u32();
    uint8_t g = (uint8_t)oat_random_u32();
    uint8_t b = (uint8_t)oat_random_u32();

    for (int y = 0; y < oat_sprite_get_h(dvd); ++y) {
        for (int x = 0; x < oat_sprite_get_w(dvd); ++x) {
            uint8_t a;
            oat_sprite_get_pixel(dvd, x, y, NULL, NULL, NULL, &a);
            if (a != 0) {
                oat_sprite_set_pixel(dvd, x, y, r, g, b, 0xFF);
            }
        }
    }
}

int
main(void)
{
    oat_init(SCREEN_W, SCREEN_H, "demo");
    atexit(oat_fini);

    struct oat_font* const font = oat_font_new_ttf_from_mem(
        assets_PublicPixel_ttf, (size_t)assets_PublicPixel_ttf_len);

    struct oat_sprite* const square =
        oat_sprite_new(SQUARE_SIDE_LENGTH, SQUARE_SIDE_LENGTH);
    int square_x = oat_screen_get_w() / 2 - oat_sprite_get_w(square) / 2;
    int square_y = oat_screen_get_h() / 2 - oat_sprite_get_h(square) / 2;
    oat_sprite_draw_clear(square, 0xFF, 0x00, 0x00);

    struct oat_sprite* const dvd = oat_sprite_new_png_from_mem(
        assets_DVDLogo_png, (size_t)assets_DVDLogo_png_len);
    randomize_pixel_colors(dvd);
    double const dvd_scale = 2.0;
    int dvd_x = 0;
    int dvd_y = oat_screen_get_h() / 2 - oat_sprite_get_h(dvd) / 2;
    int dvd_vx = +1;
    int dvd_vy = +1;

    struct oat_sprite* const face_spritesheet = oat_sprite_new_png_from_mem(
        assets_FaceSpriteSheet_png, (size_t)assets_FaceSpriteSheet_png_len);
    int const face_frame_w = oat_sprite_get_w(face_spritesheet) / 2;
    int const face_frame_h = oat_sprite_get_h(face_spritesheet);
    oat_sprite_draw_text(
        face_spritesheet, "1", 0, 0, font, 8, 0x00, 0x80, 0x80, 0xEE);
    oat_sprite_draw_text(
        face_spritesheet,
        "2",
        face_frame_w,
        0,
        font,
        8,
        0x00,
        0x80,
        0x80,
        0xEE);

    struct oat_sprite* const spinning =
        oat_sprite_new_text("SPINNING TEXT", font, 16, 0x00, 0x00, 0x00, 0xFF);

    char const* const hello_text = "HELLO";
    int hello_x = 0;
    int hello_y = 48;
    int hello_vy = +2;
    int hello_w = 0;
    int hello_h = 0;
    oat_measure_text(hello_text, font, 32, &hello_w, &hello_h);

    struct oat_sound* const bump =
        oat_sound_new(assets_Bump_ogg, (size_t)assets_Bump_ogg_len);

    double time = 0.0;
    double prev = 0.0;
    while (!oat_get_quit_requested()) {
        double const now = oat_now();
        time += now - prev;
        prev = now;
        if (time <= TIMESTEP) {
            continue;
        }
        time -= TIMESTEP;

        if (oat_key_is_pressed(oat_key_escape())) {
            oat_set_quit_requested(true);
        }
        if (oat_key_is_pressed(oat_key_f11())) {
            oat_set_fullscreen(!oat_get_fullscreen());
        }
        if (oat_key_is_down(oat_key_larrow()) || oat_key_is_down(oat_key_h())) {
            square_x -= 4;
        }
        if (oat_key_is_down(oat_key_rarrow()) || oat_key_is_down(oat_key_l())) {
            square_x += 4;
        }
        if (oat_key_is_down(oat_key_uarrow()) || oat_key_is_down(oat_key_k())) {
            square_y -= 4;
        }
        if (oat_key_is_down(oat_key_darrow()) || oat_key_is_down(oat_key_j())) {
            square_y += 4;
        }
        if (oat_mouse_button_is_down(oat_mouse_lbutton())) {
            square_x = oat_mouse_get_x() - oat_sprite_get_w(square) / 2;
            square_y = oat_mouse_get_y() - oat_sprite_get_h(square) / 2;
        }

        if (dvd_x < 0) {
            dvd_vx *= -1;
            randomize_pixel_colors(dvd);
            oat_sound_play(bump);
        }
        if (dvd_x + oat_sprite_get_w(dvd) * dvd_scale > oat_screen_get_w()) {
            dvd_vx *= -1;
            randomize_pixel_colors(dvd);
            oat_sound_play(bump);
        }
        if (dvd_y < 0) {
            dvd_vy *= -1;
            randomize_pixel_colors(dvd);
            oat_sound_play(bump);
        }
        if (dvd_y + oat_sprite_get_h(dvd) * dvd_scale > oat_screen_get_h()) {
            dvd_vy *= -1;
            randomize_pixel_colors(dvd);
            oat_sound_play(bump);
        }
        dvd_x += dvd_vx;
        dvd_y += dvd_vy;

        if (hello_y < 0) {
            hello_vy *= -1;
        }
        if (hello_y + hello_h > oat_screen_get_h()) {
            hello_vy *= -1;
        }
        hello_x = (int)(fabs(sin(now)) * (oat_screen_get_w() - hello_w));
        hello_y += hello_vy;

        oat_draw_clear(0xFF, 0xFF, 0xFF);

        oat_draw_sprite_partial_ex(
            face_spritesheet,
            500,
            50,
            ((int)now % 2) * face_frame_w,
            0,
            face_frame_w,
            face_frame_h,
            4.0,
            4.0,
            0,
            0,
            0.0,
            false,
            false);

        oat_draw_sprite_ex(
            dvd, dvd_x, dvd_y, dvd_scale, dvd_scale, 0, 0, 0.0, false, false);

        int spinning_side_max =
            oat_sprite_get_w(spinning) > oat_sprite_get_h(spinning)
            ? oat_sprite_get_w(spinning)
            : oat_sprite_get_h(spinning);
        int const spinning_x =
            oat_screen_get_w() - spinning_side_max / 2 - OFFSET;
        int const spinning_y =
            oat_screen_get_h() - spinning_side_max / 2 - OFFSET;
        oat_draw_sprite_ex(
            spinning,
            spinning_x - oat_sprite_get_w(spinning) / 2,
            spinning_y - oat_sprite_get_h(spinning) / 2,
            1.0,
            1.0,
            oat_sprite_get_w(spinning) / 2,
            oat_sprite_get_h(spinning) / 2,
            now * (180.0 / PI) / 2,
            false,
            false);
        oat_draw_rectangle(
            spinning_x - OFFSET,
            spinning_y - OFFSET,
            4,
            4,
            0xFF,
            0x00,
            0x00,
            0xFF);

        char textbox_str[] = "the quick brown fox jumps over the lazy dog";
        size_t const textbox_end =
            (size_t)fmin(now * 4, (double)(sizeof(textbox_str) - 1));
        textbox_str[textbox_end] = '\0';
        int textbox_w = 0;
        int textbox_h = 0;
        oat_measure_text(textbox_str, font, 8, &textbox_w, &textbox_h);
        oat_draw_rectangle_outline(
            2,
            oat_screen_get_h() - 2 * MARGIN - textbox_h - OFFSET,
            textbox_w + 2 * MARGIN,
            textbox_h + 2 * MARGIN,
            0x00,
            0x00,
            0x00,
            0xFF,
            MARGIN / 2);
        oat_draw_text(
            textbox_str,
            2 + MARGIN,
            oat_screen_get_h() - 1 * MARGIN - textbox_h - OFFSET,
            font,
            8,
            0x00,
            0x00,
            0x00,
            0xFF);

        char buf[256] = {0};
        char const* const demo_text_1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char const* const demo_text_2 = "abcdefghijklmnopqrstuvwxyz";
        char const* const demo_text_3 = "!\"#$%&\'()*+,-./:;<=>?@[\\]^_`~";
        oat_draw_text(
            demo_text_1, OFFSET, 16 * 0, font, 16, 0x00, 0x00, 0x00, 0xFF);
        oat_draw_text(
            demo_text_2, OFFSET, 16 * 1, font, 16, 0x00, 0x00, 0x00, 0xFF);
        oat_draw_text(
            demo_text_3, OFFSET, 16 * 2, font, 16, 0x00, 0x00, 0x00, 0xFF);
        snprintf(buf, sizeof(buf), "ELAPSED TIME: %0.3f", now);
        oat_draw_text(buf, OFFSET, 16 * 4, font, 16, 0x00, 0x00, 0x00, 0xFF);
        oat_draw_text(
            "KEY STATE", OFFSET, 16 * 6, font, 16, 0x00, 0x00, 0x00, 0xFF);
        snprintf(
            buf,
            sizeof(buf),
            "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
            oat_key_is_down(oat_key_a()) ? '-' : 'A',
            oat_key_is_down(oat_key_b()) ? '-' : 'B',
            oat_key_is_down(oat_key_c()) ? '-' : 'C',
            oat_key_is_down(oat_key_d()) ? '-' : 'D',
            oat_key_is_down(oat_key_e()) ? '-' : 'E',
            oat_key_is_down(oat_key_f()) ? '-' : 'F',
            oat_key_is_down(oat_key_g()) ? '-' : 'G',
            oat_key_is_down(oat_key_h()) ? '-' : 'H',
            oat_key_is_down(oat_key_i()) ? '-' : 'I',
            oat_key_is_down(oat_key_j()) ? '-' : 'J',
            oat_key_is_down(oat_key_k()) ? '-' : 'K',
            oat_key_is_down(oat_key_l()) ? '-' : 'L',
            oat_key_is_down(oat_key_m()) ? '-' : 'M',
            oat_key_is_down(oat_key_n()) ? '-' : 'N',
            oat_key_is_down(oat_key_o()) ? '-' : 'O',
            oat_key_is_down(oat_key_p()) ? '-' : 'P',
            oat_key_is_down(oat_key_q()) ? '-' : 'Q',
            oat_key_is_down(oat_key_r()) ? '-' : 'R',
            oat_key_is_down(oat_key_s()) ? '-' : 'S',
            oat_key_is_down(oat_key_t()) ? '-' : 'T',
            oat_key_is_down(oat_key_u()) ? '-' : 'U',
            oat_key_is_down(oat_key_v()) ? '-' : 'V',
            oat_key_is_down(oat_key_w()) ? '-' : 'W',
            oat_key_is_down(oat_key_x()) ? '-' : 'X',
            oat_key_is_down(oat_key_y()) ? '-' : 'Y',
            oat_key_is_down(oat_key_z()) ? '-' : 'Z');
        oat_draw_text(buf, OFFSET, 16 * 7, font, 16, 0x00, 0x00, 0x00, 0xFF);
        oat_draw_text(
            "MOUSE STATE", OFFSET, 16 * 9, font, 16, 0x00, 0x00, 0x00, 0xFF);
        snprintf(
            buf,
            sizeof(buf),
            "%c%c%c%c%c",
            oat_mouse_button_is_down(oat_mouse_lbutton()) ? '-' : 'L',
            oat_mouse_button_is_down(oat_mouse_mbutton()) ? '-' : 'M',
            oat_mouse_button_is_down(oat_mouse_rbutton()) ? '-' : 'R',
            oat_mouse_button_is_down(oat_mouse_4button()) ? '-' : '4',
            oat_mouse_button_is_down(oat_mouse_5button()) ? '-' : '5');
        oat_draw_text(buf, OFFSET, 16 * 10, font, 16, 0x00, 0x00, 0x00, 0xFF);
        oat_draw_text(
            "MOUSE POSITION",
            OFFSET,
            16 * 12,
            font,
            16,
            0x00,
            0x00,
            0x00,
            0xFF);
        snprintf(
            buf,
            sizeof(buf),
            "(x, y) = (%d, %d)",
            oat_mouse_get_x(),
            oat_mouse_get_y());
        oat_draw_text(buf, OFFSET, 16 * 13, font, 16, 0x00, 0x00, 0x00, 0xFF);

        oat_draw_text(
            hello_text, hello_x, hello_y, font, 32, 0x00, 0x00, 0x00, 0xFF);

        oat_draw_rectangle(
            square_x,
            square_y,
            SQUARE_SIDE_LENGTH,
            SQUARE_SIDE_LENGTH,
            0xAA,
            0x00,
            0xAA,
            0x77);
        oat_draw_rectangle_outline(
            square_x,
            square_y,
            SQUARE_SIDE_LENGTH,
            SQUARE_SIDE_LENGTH,
            0x00,
            0x00,
            0x00,
            0xFF,
            2);
        oat_draw_sprite_ex(
            square,
            square_x + (int)(sin(now) * oat_sprite_get_w(square) * 2),
            square_y + (int)(cos(now) * oat_sprite_get_h(square) * 2),
            1.0,
            1.0,
            oat_sprite_get_w(square) / 2,
            oat_sprite_get_h(square) / 2,
            -now * (180.0 / PI),
            false,
            false);
        oat_draw_sprite_ex(
            square,
            square_x - (int)(sin(now) * oat_sprite_get_w(square) * 2),
            square_y - (int)(cos(now) * oat_sprite_get_h(square) * 2),
            1.0,
            1.0,
            oat_sprite_get_w(square) / 2,
            oat_sprite_get_h(square) / 2,
            -now * (180.0 / PI),
            false,
            false);

        oat_end_frame();
    }

    oat_font_del(font);
    oat_sprite_del(square);
    oat_sprite_del(dvd);
    oat_sprite_del(face_spritesheet);
    oat_sprite_del(spinning);
    oat_sound_del(bump);
}
