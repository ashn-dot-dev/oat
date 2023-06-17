#ifndef OAT_H_INCLUDED
#define OAT_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct oat_key;
struct oat_mouse_button;
struct oat_sprite;
struct oat_sound;
struct oat_font;

void oat_init(int screen_w, int screen_h, char const* title);
void oat_fini(void);

void oat_screen_set_w(int w);
void oat_screen_set_h(int h);
int oat_screen_get_w(void);
int oat_screen_get_h(void);
void oat_screen_save_png_to_file(char const* file);

void oat_set_fullscreen(bool value);
bool oat_get_fullscreen(void);

void oat_set_quit_requested(bool value);
bool oat_get_quit_requested(void);

double oat_now(void);
void oat_seed_random_u32(uint64_t seed);
void oat_seed_random_u64(uint64_t seed_a, uint64_t seed_b);
uint32_t oat_random_u32();
uint64_t oat_random_u64();

void oat_end_frame(void);

struct oat_key const* oat_key_0(void);
struct oat_key const* oat_key_1(void);
struct oat_key const* oat_key_2(void);
struct oat_key const* oat_key_3(void);
struct oat_key const* oat_key_4(void);
struct oat_key const* oat_key_5(void);
struct oat_key const* oat_key_6(void);
struct oat_key const* oat_key_7(void);
struct oat_key const* oat_key_8(void);
struct oat_key const* oat_key_9(void);
struct oat_key const* oat_key_a(void);
struct oat_key const* oat_key_b(void);
struct oat_key const* oat_key_c(void);
struct oat_key const* oat_key_d(void);
struct oat_key const* oat_key_e(void);
struct oat_key const* oat_key_f(void);
struct oat_key const* oat_key_g(void);
struct oat_key const* oat_key_h(void);
struct oat_key const* oat_key_i(void);
struct oat_key const* oat_key_j(void);
struct oat_key const* oat_key_k(void);
struct oat_key const* oat_key_l(void);
struct oat_key const* oat_key_m(void);
struct oat_key const* oat_key_n(void);
struct oat_key const* oat_key_o(void);
struct oat_key const* oat_key_p(void);
struct oat_key const* oat_key_q(void);
struct oat_key const* oat_key_r(void);
struct oat_key const* oat_key_s(void);
struct oat_key const* oat_key_t(void);
struct oat_key const* oat_key_u(void);
struct oat_key const* oat_key_v(void);
struct oat_key const* oat_key_w(void);
struct oat_key const* oat_key_x(void);
struct oat_key const* oat_key_y(void);
struct oat_key const* oat_key_z(void);
struct oat_key const* oat_key_f1(void);
struct oat_key const* oat_key_f2(void);
struct oat_key const* oat_key_f3(void);
struct oat_key const* oat_key_f4(void);
struct oat_key const* oat_key_f5(void);
struct oat_key const* oat_key_f6(void);
struct oat_key const* oat_key_f7(void);
struct oat_key const* oat_key_f8(void);
struct oat_key const* oat_key_f9(void);
struct oat_key const* oat_key_f10(void);
struct oat_key const* oat_key_f11(void);
struct oat_key const* oat_key_f12(void);
struct oat_key const* oat_key_uarrow(void);
struct oat_key const* oat_key_darrow(void);
struct oat_key const* oat_key_larrow(void);
struct oat_key const* oat_key_rarrow(void);
struct oat_key const* oat_key_tab(void);
struct oat_key const* oat_key_lalt(void);
struct oat_key const* oat_key_ralt(void);
struct oat_key const* oat_key_lctrl(void);
struct oat_key const* oat_key_rctrl(void);
struct oat_key const* oat_key_lshift(void);
struct oat_key const* oat_key_rshift(void);
struct oat_key const* oat_key_enter(void);
struct oat_key const* oat_key_space(void);
struct oat_key const* oat_key_backspace(void);
struct oat_key const* oat_key_escape(void);

bool oat_key_is_pressed(struct oat_key const* key);
bool oat_key_is_down(struct oat_key const* key);
bool oat_key_is_released(struct oat_key const* key);

int oat_mouse_get_x(void);
int oat_mouse_get_y(void);

struct oat_mouse_button const* oat_mouse_lbutton(void);
struct oat_mouse_button const* oat_mouse_mbutton(void);
struct oat_mouse_button const* oat_mouse_rbutton(void);
struct oat_mouse_button const* oat_mouse_4button(void);
struct oat_mouse_button const* oat_mouse_5button(void);

bool oat_mouse_button_is_pressed(struct oat_mouse_button const* button);
bool oat_mouse_button_is_down(struct oat_mouse_button const* button);
bool oat_mouse_button_is_released(struct oat_mouse_button const* button);
bool oat_mouse_button_is_single_click(struct oat_mouse_button const* button);
bool oat_mouse_button_is_double_click(struct oat_mouse_button const* button);

struct oat_sprite* oat_sprite_new(int w, int h);
struct oat_sprite* oat_sprite_new_png_from_mem(void const* png_buf_start, size_t png_buf_count);
struct oat_sprite* oat_sprite_new_png_from_file(char const* file);
struct oat_sprite* oat_sprite_new_text(char const* text, struct oat_font* font, int font_size, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void oat_sprite_del(struct oat_sprite* self);
int oat_sprite_get_w(struct oat_sprite* self);
int oat_sprite_get_h(struct oat_sprite* self);
void oat_sprite_set_pixel(struct oat_sprite* self, int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void oat_sprite_get_pixel(struct oat_sprite const* self, int x, int y, uint8_t* r, uint8_t* g, uint8_t* b, uint8_t* a);
void oat_sprite_draw_clear(struct oat_sprite* self, uint8_t r, uint8_t g, uint8_t b);
void oat_sprite_draw_fill(struct oat_sprite* self, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void oat_sprite_draw_sprite(struct oat_sprite* self, struct oat_sprite* sprite, int x, int y);
void oat_sprite_draw_sprite_partial(struct oat_sprite* self, struct oat_sprite* sprite, int x, int y, int partial_x, int partial_y, int partial_w, int partial_h);
void oat_sprite_draw_text(struct oat_sprite* self, char const* text, int x, int y, struct oat_font* font, int font_size, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void oat_sprite_save_png_to_file(struct oat_sprite* self, char const* file);

struct oat_sound* oat_sound_new(void const* buf_start, size_t buf_count);
void oat_sound_del(struct oat_sound* self);
void oat_sound_play(struct oat_sound* self);

struct oat_font* oat_font_new_ttf_from_mem(void const* ttf_buf_start, size_t ttf_buf_count);
struct oat_font* oat_font_new_ttf_from_file(char const* file);
void oat_font_del(struct oat_font* self);

void oat_measure_text(char const* text, struct oat_font* font, int font_size, int* w, int* h);

void oat_draw_clear(uint8_t r, uint8_t g, uint8_t b);
void oat_draw_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void oat_draw_rectangle(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void oat_draw_rectangle_outline(int x, int y, int w, int h, uint8_t r, uint8_t g, uint8_t b, uint8_t a, int thickness);
void oat_draw_sprite(struct oat_sprite* sprite, int x, int y);
void oat_draw_sprite_ex(struct oat_sprite* sprite, int x, int y, double scale_x, double scale_y, int rotation_x_offset, int rotation_y_offset, double rotation_degrees, bool flip_horizontal, bool flip_vertical);
void oat_draw_sprite_partial(struct oat_sprite* sprite, int x, int y, int partial_x, int partial_y, int partial_w, int partial_h);
void oat_draw_sprite_partial_ex(struct oat_sprite* sprite, int x, int y, int partial_x, int partial_y, int partial_w, int partial_h, double scale_x, double scale_y, int rotation_x_offset, int rotation_y_offset, double rotation_degrees, bool flip_horizontal, bool flip_vertical);
void oat_draw_text(char const* text, int x, int y, struct oat_font* font, int font_size, uint8_t r, uint8_t g, uint8_t b, uint8_t a);

#endif // OAT_H_INCLUDED
