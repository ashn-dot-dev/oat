#include <stdbool.h>
#include <stdlib.h> /* NULL, exit, qsort */

#include <oat.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

enum oat_key_kind {
    OAT_KEY_0,
    OAT_KEY_1,
    OAT_KEY_2,
    OAT_KEY_3,
    OAT_KEY_4,
    OAT_KEY_5,
    OAT_KEY_6,
    OAT_KEY_7,
    OAT_KEY_8,
    OAT_KEY_9,
    OAT_KEY_A,
    OAT_KEY_B,
    OAT_KEY_C,
    OAT_KEY_D,
    OAT_KEY_E,
    OAT_KEY_F,
    OAT_KEY_G,
    OAT_KEY_H,
    OAT_KEY_I,
    OAT_KEY_J,
    OAT_KEY_K,
    OAT_KEY_L,
    OAT_KEY_M,
    OAT_KEY_N,
    OAT_KEY_O,
    OAT_KEY_P,
    OAT_KEY_Q,
    OAT_KEY_R,
    OAT_KEY_S,
    OAT_KEY_T,
    OAT_KEY_U,
    OAT_KEY_V,
    OAT_KEY_W,
    OAT_KEY_X,
    OAT_KEY_Y,
    OAT_KEY_Z,
    OAT_KEY_F1,
    OAT_KEY_F2,
    OAT_KEY_F3,
    OAT_KEY_F4,
    OAT_KEY_F5,
    OAT_KEY_F6,
    OAT_KEY_F7,
    OAT_KEY_F8,
    OAT_KEY_F9,
    OAT_KEY_F10,
    OAT_KEY_F11,
    OAT_KEY_F12,
    OAT_KEY_UARROW,
    OAT_KEY_DARROW,
    OAT_KEY_LARROW,
    OAT_KEY_RARROW,
    OAT_KEY_TAB,
    OAT_KEY_LALT,
    OAT_KEY_RALT,
    OAT_KEY_LCTRL,
    OAT_KEY_RCTRL,
    OAT_KEY_LSHIFT,
    OAT_KEY_RSHIFT,
    OAT_KEY_ENTER,
    OAT_KEY_SPACE,
    OAT_KEY_BACKSPACE,
    OAT_KEY_ESCAPE,
    OAT_KEY_COUNT,
};

static SDL_Scancode oat_scancodes[OAT_KEY_COUNT] = {
    [OAT_KEY_0] = SDL_SCANCODE_0,
    [OAT_KEY_1] = SDL_SCANCODE_1,
    [OAT_KEY_2] = SDL_SCANCODE_2,
    [OAT_KEY_3] = SDL_SCANCODE_3,
    [OAT_KEY_4] = SDL_SCANCODE_4,
    [OAT_KEY_5] = SDL_SCANCODE_5,
    [OAT_KEY_6] = SDL_SCANCODE_6,
    [OAT_KEY_7] = SDL_SCANCODE_7,
    [OAT_KEY_8] = SDL_SCANCODE_8,
    [OAT_KEY_9] = SDL_SCANCODE_9,
    [OAT_KEY_A] = SDL_SCANCODE_A,
    [OAT_KEY_B] = SDL_SCANCODE_B,
    [OAT_KEY_C] = SDL_SCANCODE_C,
    [OAT_KEY_D] = SDL_SCANCODE_D,
    [OAT_KEY_E] = SDL_SCANCODE_E,
    [OAT_KEY_F] = SDL_SCANCODE_F,
    [OAT_KEY_G] = SDL_SCANCODE_G,
    [OAT_KEY_H] = SDL_SCANCODE_H,
    [OAT_KEY_I] = SDL_SCANCODE_I,
    [OAT_KEY_J] = SDL_SCANCODE_J,
    [OAT_KEY_K] = SDL_SCANCODE_K,
    [OAT_KEY_L] = SDL_SCANCODE_L,
    [OAT_KEY_M] = SDL_SCANCODE_M,
    [OAT_KEY_N] = SDL_SCANCODE_N,
    [OAT_KEY_O] = SDL_SCANCODE_O,
    [OAT_KEY_P] = SDL_SCANCODE_P,
    [OAT_KEY_Q] = SDL_SCANCODE_Q,
    [OAT_KEY_R] = SDL_SCANCODE_R,
    [OAT_KEY_S] = SDL_SCANCODE_S,
    [OAT_KEY_T] = SDL_SCANCODE_T,
    [OAT_KEY_U] = SDL_SCANCODE_U,
    [OAT_KEY_V] = SDL_SCANCODE_V,
    [OAT_KEY_W] = SDL_SCANCODE_W,
    [OAT_KEY_X] = SDL_SCANCODE_X,
    [OAT_KEY_Y] = SDL_SCANCODE_Y,
    [OAT_KEY_Z] = SDL_SCANCODE_Z,
    [OAT_KEY_F1] = SDL_SCANCODE_F1,
    [OAT_KEY_F2] = SDL_SCANCODE_F2,
    [OAT_KEY_F3] = SDL_SCANCODE_F3,
    [OAT_KEY_F4] = SDL_SCANCODE_F4,
    [OAT_KEY_F5] = SDL_SCANCODE_F5,
    [OAT_KEY_F6] = SDL_SCANCODE_F6,
    [OAT_KEY_F7] = SDL_SCANCODE_F7,
    [OAT_KEY_F8] = SDL_SCANCODE_F8,
    [OAT_KEY_F9] = SDL_SCANCODE_F9,
    [OAT_KEY_F10] = SDL_SCANCODE_F10,
    [OAT_KEY_F11] = SDL_SCANCODE_F11,
    [OAT_KEY_F12] = SDL_SCANCODE_F12,
    [OAT_KEY_UARROW] = SDL_SCANCODE_UP,
    [OAT_KEY_DARROW] = SDL_SCANCODE_DOWN,
    [OAT_KEY_LARROW] = SDL_SCANCODE_LEFT,
    [OAT_KEY_RARROW] = SDL_SCANCODE_RIGHT,
    [OAT_KEY_TAB] = SDL_SCANCODE_TAB,
    [OAT_KEY_LALT] = SDL_SCANCODE_LALT,
    [OAT_KEY_RALT] = SDL_SCANCODE_RALT,
    [OAT_KEY_LCTRL] = SDL_SCANCODE_LCTRL,
    [OAT_KEY_RCTRL] = SDL_SCANCODE_RCTRL,
    [OAT_KEY_LSHIFT] = SDL_SCANCODE_LSHIFT,
    [OAT_KEY_RSHIFT] = SDL_SCANCODE_RSHIFT,
    [OAT_KEY_ENTER] = SDL_SCANCODE_RETURN,
    [OAT_KEY_BACKSPACE] = SDL_SCANCODE_BACKSPACE,
    [OAT_KEY_SPACE] = SDL_SCANCODE_SPACE,
    [OAT_KEY_ESCAPE] = SDL_SCANCODE_ESCAPE,
};

struct oat_key {
    bool pressed;
    bool down;
    bool released;
};

enum oat_mouse_button_kind {
    OAT_MOUSE_LBUTTON,
    OAT_MOUSE_MBUTTON,
    OAT_MOUSE_RBUTTON,
    OAT_MOUSE_4BUTTON,
    OAT_MOUSE_5BUTTON,
    OAT_MOUSE_BUTTON_COUNT,
};

struct oat_mouse_button {
    bool pressed;
    bool down;
    bool released;
    bool single_click;
    bool double_click;
};

struct oat_sprite {
    int w;
    int h;
    SDL_Surface* surface;
    SDL_Texture* texture;
    bool texture_needs_update;
};

struct oat_sound {
    Mix_Chunk* chunk;
};

struct oat_font_cached {
    int size;
    TTF_Font* font;
};

struct oat_font {
    void* ttf_buf_start;
    size_t ttf_buf_count;

    struct oat_font_cached* cached_start;
    size_t cached_count;
};

static struct oat_context {
    SDL_Window* window; // SDL_CreateWindow
    SDL_Renderer* renderer; // SDL_CreateRenderer
    bool audio_device_open; // Mix_OpenAudio
    Uint64 init_now; // SDL_GetPerformanceCounter
    Uint32 fullscreen; // SDL_SetWindowFullscreen flags
    bool quit_requested;

    size_t frame_count; // Number of frames rendered to the screen.
    double frame_begin; // Start time of the current frame.
#define OAT_FRAME_TIME_CAPTURES_COUNT 30
    double frame_time_captures[OAT_FRAME_TIME_CAPTURES_COUNT];
    int target_fps;

    struct oat_key keys[OAT_KEY_COUNT];
    struct oat_mouse_button mouse_buttons[OAT_MOUSE_BUTTON_COUNT];
} oat_context = {0};

#define OAT_XALLOC_FREE ((size_t)0)

static void*
oat_xalloc(void* ptr, size_t size)
{
    if (size == 0) {
        SDL_free(ptr);
        return NULL;
    }
    if ((ptr = SDL_realloc(ptr, size)) == NULL) {
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "[%s] Out of memory", __func__);
        abort();
    }
    return ptr;
}

static struct oat_key*
oat_scancode_to_key(SDL_Scancode scancode)
{
    for (size_t i = 0; i < (size_t)OAT_KEY_COUNT; ++i) {
        if (scancode == oat_scancodes[i]) {
            return &oat_context.keys[i];
        }
    }
    return NULL;
}

static int
oat_font_cached_cmp(void const* lhs, void const* rhs)
{
    struct oat_font_cached const* lhs_ = lhs;
    struct oat_font_cached const* rhs_ = rhs;

    if (lhs_->size < rhs_->size) {
        return -1;
    }
    if (lhs_->size > rhs_->size) {
        return +1;
    }
    return 0;
}

static TTF_Font*
oat_font_add_or_get_cached(struct oat_font* self, int size)
{
    if (size <= 0) {
        return NULL;
    }

    for (size_t i = 0; i < self->cached_count; ++i) {
        if (self->cached_start[i].size == size) {
            return self->cached_start[i].font;
        }
    }

    SDL_RWops* const rwops =
        SDL_RWFromConstMem(self->ttf_buf_start, (int)self->ttf_buf_count);
    if (rwops == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RWFromConstMem] %s\n",
            __func__,
            SDL_GetError());
        return NULL;
    }

    TTF_Font* const font = TTF_OpenFontRW(rwops, 1, size);
    if (font == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][TTF_OpenFontRW] %s\n",
            __func__,
            TTF_GetError());
        return NULL;
    }

    struct oat_font_cached const cached = {
        .size = size,
        .font = font,
    };
    self->cached_start = oat_xalloc(
        self->cached_start,
        (self->cached_count + 1) * sizeof(*self->cached_start));
    self->cached_start[self->cached_count++] = cached;
    qsort(
        self->cached_start,
        self->cached_count,
        sizeof(*self->cached_start),
        oat_font_cached_cmp);

    return font;
}

void
oat_init(int screen_w, int screen_h, char const* title)
{
    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);
    SDL_LogSetPriority(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_WARN);

    if (screen_w <= 0 || screen_h <= 0) {
        SDL_LogCritical(
            SDL_LOG_CATEGORY_ERROR,
            "[%s] invalid screen size (%d x %d)",
            __func__,
            screen_w,
            screen_h);
        oat_fini();
        exit(EXIT_FAILURE);
    }

    SDL_version sdl_version;
    SDL_GetVersion(&sdl_version);
    SDL_LogInfo(
        SDL_LOG_CATEGORY_APPLICATION,
        "SDL version %d.%d.%d",
        sdl_version.major,
        sdl_version.minor,
        sdl_version.patch);

    Uint32 const sdl_init_flags = SDL_INIT_VIDEO | SDL_INIT_AUDIO;
    if (SDL_Init(sdl_init_flags)) {
        SDL_LogCritical(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_Init] %s",
            __func__,
            SDL_GetError());
        oat_fini();
        exit(EXIT_FAILURE);
    }

    oat_context.window = SDL_CreateWindow(
        title != NULL ? title : "",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        screen_w,
        screen_h,
        0);
    if (oat_context.window == NULL) {
        SDL_LogCritical(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_CreateWindow] %s\n",
            __func__,
            SDL_GetError());
        oat_fini();
        exit(EXIT_FAILURE);
    }

    oat_context.renderer =
        SDL_CreateRenderer(oat_context.window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (oat_context.renderer == NULL) {
        SDL_LogCritical(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_CreateRenderer] %s\n",
            __func__,
            SDL_GetError());
        oat_fini();
        exit(EXIT_FAILURE);
    }
    if (SDL_SetRenderDrawBlendMode(oat_context.renderer, SDL_BLENDMODE_BLEND)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_SetRenderDrawBlendMode] %s",
            __func__,
            SDL_GetError());
    }

    SDL_version const* const img_version = IMG_Linked_Version();
    SDL_LogInfo(
        SDL_LOG_CATEGORY_APPLICATION,
        "SDL_image version %d.%d.%d",
        img_version->major,
        img_version->minor,
        img_version->patch);

    int const img_flags = IMG_INIT_PNG;
    int const img_init = IMG_Init(img_flags);
    if ((img_init & img_flags) != img_flags) {
        SDL_LogCritical(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][IMG_Init] %s\n",
            __func__,
            IMG_GetError());
        oat_fini();
        exit(EXIT_FAILURE);
    }

    SDL_version const* mix_ver = Mix_Linked_Version();
    SDL_LogInfo(
        SDL_LOG_CATEGORY_APPLICATION,
        "SDL_mixer version %d.%d.%d",
        mix_ver->major,
        mix_ver->minor,
        mix_ver->patch);

    int const mix_flags = MIX_INIT_OGG;
    int const mix_init = Mix_Init(mix_flags);
    if ((mix_init & mix_flags) != mix_flags) {
        SDL_LogCritical(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][Mix_Init] %s\n",
            __func__,
            Mix_GetError());
        oat_fini();
        exit(EXIT_FAILURE);
    }

    int const frequency = MIX_DEFAULT_FREQUENCY;
    Uint16 const format = MIX_DEFAULT_FORMAT;
    int const channels = MIX_DEFAULT_CHANNELS;
    int const chunksize = 2048;
    if (Mix_OpenAudio(frequency, format, channels, chunksize)) {
        SDL_LogCritical(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][Mix_OpenAudio] %s",
            __func__,
            Mix_GetError());
        oat_fini();
        exit(EXIT_FAILURE);
    }
    oat_context.audio_device_open = true;
    int const numchans = 32;
    int const reschans = Mix_AllocateChannels(numchans);
    if (reschans != numchans) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][Mix_AllocateChannels] allocated %d channels (requested %d)",
            __func__,
            reschans,
            numchans);
    }
    Mix_Volume(-1, MIX_MAX_VOLUME); // All channels to max volume.

    SDL_version const* const ttf_version = TTF_Linked_Version();
    SDL_LogInfo(
        SDL_LOG_CATEGORY_APPLICATION,
        "SDL_ttf version %d.%d.%d",
        ttf_version->major,
        ttf_version->minor,
        ttf_version->patch);

    if (TTF_Init()) {
        SDL_LogCritical(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][TTF_Init] %s\n",
            __func__,
            TTF_GetError());
        oat_fini();
        exit(EXIT_FAILURE);
    }

    oat_context.init_now = SDL_GetPerformanceCounter();
}

void
oat_fini(void)
{
    if (TTF_WasInit()) {
        TTF_Quit();
    }
    if (oat_context.audio_device_open) {
        Mix_CloseAudio();
    }
    if ((Mix_Init(MIX_INIT_OGG) & MIX_INIT_OGG)) {
        Mix_Quit();
    }
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        IMG_Quit();
    }
    if (oat_context.renderer != NULL) {
        SDL_DestroyRenderer(oat_context.renderer);
    }
    if (oat_context.window != NULL) {
        SDL_DestroyWindow(oat_context.window);
    }
    if (SDL_WasInit(SDL_INIT_EVERYTHING)) {
        SDL_Quit();
    }
}

void
oat_screen_set_w(int w)
{
    if (w <= 0) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s] invalid screen width (%d)",
            __func__,
            w);
        return;
    }
    SDL_SetWindowSize(oat_context.window, w, oat_screen_get_h());
}

void
oat_screen_set_h(int h)
{
    if (h <= 0) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s] invalid screen height (%d)",
            __func__,
            h);
        return;
    }
    SDL_SetWindowSize(oat_context.window, oat_screen_get_w(), h);
}

int
oat_screen_get_w(void)
{
    int w = 0;
    SDL_GetWindowSize(oat_context.window, &w, NULL);
    return w;
}

int
oat_screen_get_h(void)
{
    int h = 0;
    SDL_GetWindowSize(oat_context.window, NULL, &h);
    return h;
}

void
oat_screen_save_png_to_file(char const* file)
{
    static int const DEPTH = 32;
    SDL_Surface* const surface = SDL_CreateRGBSurfaceWithFormat(
        0,
        oat_screen_get_w(),
        oat_screen_get_h(),
        DEPTH,
        SDL_PIXELFORMAT_ARGB8888);
    if (surface == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_CreateRGBSurfaceWithFormat] %s",
            __func__,
            SDL_GetError());
        goto end;
    }

    int const err = SDL_RenderReadPixels(
        oat_context.renderer,
        NULL,
        surface->format->format,
        surface->pixels,
        surface->pitch);
    if (err) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RenderReadPixels] %s",
            __func__,
            SDL_GetError());
        goto end;
    }

    if (IMG_SavePNG(surface, file)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][IMG_SavePNG] %s",
            __func__,
            IMG_GetError());
        goto end;
    }

end:
    if (surface != NULL) {
        SDL_FreeSurface(surface);
    }
}

void
oat_set_fullscreen(bool value)
{
    Uint32 const flags = value ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;
    if (SDL_SetWindowFullscreen(oat_context.window, flags)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_SetWindowFullscreen] %s",
            __func__,
            SDL_GetError());
        return;
    }
    oat_context.fullscreen = flags;
}

bool
oat_get_fullscreen(void)
{
    return oat_context.fullscreen != 0;
}

void
oat_set_quit_requested(bool value)
{
    oat_context.quit_requested = value;
}

bool
oat_get_quit_requested(void)
{
    return oat_context.quit_requested;
}

void
oat_set_target_fps(int value)
{
    oat_context.target_fps = value >= 0 ? value : 0;
}

double
oat_get_fps(void)
{
    if (oat_context.frame_count == 0) {
        return 0.0;
    }

    double time = 0.0;
    size_t const count =
        (oat_context.frame_count < OAT_FRAME_TIME_CAPTURES_COUNT)
        ? oat_context.frame_count
        : OAT_FRAME_TIME_CAPTURES_COUNT;
    for (size_t i = 0; i < count; ++i) {
        time += oat_context.frame_time_captures[i];
    }

    return count / time;
}

double
oat_now(void)
{
    Uint64 const now = SDL_GetPerformanceCounter();
    Uint64 const elapsed = now - oat_context.init_now;
    return (double)elapsed / (double)SDL_GetPerformanceFrequency();
}

// Simplified Permuted Congruential Generator algorithms (32 and 64 bit).
// Originally created by Christopher Wellons[1].
//
// [1]: https://nullprogram.com/blog/2017/09/21/
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
// clang-format off
static uint64_t spcg32_state[] = {0xBADF00D01DC0FFEE};
static uint64_t spcg64_state[] = {0xBADF00D01DC0FFEE, 0xCAFED00DCAFEBABE};

static uint32_t
spcg32(uint64_t s[1])
{
    uint64_t m = 0x9b60933458e17d7d;
    uint64_t a = 0xd737232eeccdf7ed;
    *s = *s * m + a;
    int shift = 29 - (*s >> 61);
    return *s >> shift;
}

static uint64_t
spcg64(uint64_t s[2])
{
    uint64_t m  = 0x9b60933458e17d7d;
    uint64_t a0 = 0xd737232eeccdf7ed;
    uint64_t a1 = 0x8b260b70b8e98891;
    uint64_t p0 = s[0];
    uint64_t p1 = s[1];
    s[0] = p0 * m + a0;
    s[1] = p1 * m + a1;
    int r0 = 29 - (p0 >> 61);
    int r1 = 29 - (p1 >> 61);
    uint64_t high = p0 >> r0;
    uint32_t low  = p1 >> r1;
    return (high << 32) | low;
}
// clang-format on
#pragma GCC diagnostic pop

void
oat_seed_random_u32(uint64_t seed)
{
    spcg32_state[0] = seed;
}

void
oat_seed_random_u64(uint64_t seed_a, uint64_t seed_b)
{
    spcg64_state[0] = seed_a;
    spcg64_state[1] = seed_b;
}

uint32_t
oat_random_u32()
{
    return spcg32(spcg32_state);
}

uint64_t
oat_random_u64()
{
    return spcg64(spcg64_state);
}

void
oat_end_frame(void)
{
    // Render the frame.
    SDL_RenderPresent(oat_context.renderer);
    oat_context.frame_count += 1;

    // Clear input state from the previous frame.
    for (size_t i = 0; i < (size_t)OAT_KEY_COUNT; ++i) {
        oat_context.keys[i].pressed = false;
        oat_context.keys[i].released = false;
    }
    for (size_t i = 0; i < (size_t)OAT_MOUSE_BUTTON_COUNT; ++i) {
        oat_context.mouse_buttons[i].pressed = false;
        oat_context.mouse_buttons[i].released = false;
        oat_context.mouse_buttons[i].single_click = false;
        oat_context.mouse_buttons[i].double_click = false;
    }

    // If a target FPS has been set, wait until (1 / TARGET_FPS) seconds have
    // elapsed before starting the next frame.
    double now = oat_now();
    double elapsed = now - oat_context.frame_begin;
    if (oat_context.target_fps != 0) {
        double const timestep = 1.0 / (double)oat_context.target_fps;
        // SDL_Delay has millisecond granularity, but may take longer due to OS
        // scheduling. This granularity is far too coarse for per-frame timing,
        // so a busy loop is used.
        while (elapsed < timestep) {
            elapsed = (now = oat_now()) - oat_context.frame_begin;
        }
    }

    // Record the elapsed time for the previous frame.
    size_t const idx = oat_context.frame_count % OAT_FRAME_TIME_CAPTURES_COUNT;
    oat_context.frame_time_captures[idx] = elapsed;

    // Begin the next frame.
    oat_context.frame_begin = now;

    // Process input state for the next frame.
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        // SDL_QuitEvent
        if (event.type == SDL_QUIT) {
            oat_context.quit_requested = true;
            continue;
        }

        // SDL_KeyboardEvent
        if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
            struct oat_key* key =
                oat_scancode_to_key(event.key.keysym.scancode);
            if (key == NULL && event.key.keysym.sym == SDLK_ESCAPE) {
                // Allow escape by scancode or keycode.
                key = &oat_context.keys[OAT_KEY_ESCAPE];
            }
            if (key == NULL) {
                continue;
            }
            key->pressed = event.type == SDL_KEYDOWN;
            key->released = event.type == SDL_KEYUP;
            key->down = event.type == SDL_KEYDOWN;
            continue;
        }

        // SDL_MouseButtonEvent
        if (event.type == SDL_MOUSEBUTTONDOWN
            || event.type == SDL_MOUSEBUTTONUP) {
            struct oat_mouse_button* button = NULL;
            switch (event.button.button) {
            case SDL_BUTTON_LEFT: {
                button = &oat_context.mouse_buttons[OAT_MOUSE_LBUTTON];
                break;
            }
            case SDL_BUTTON_MIDDLE: {
                button = &oat_context.mouse_buttons[OAT_MOUSE_MBUTTON];
                break;
            }
            case SDL_BUTTON_RIGHT: {
                button = &oat_context.mouse_buttons[OAT_MOUSE_RBUTTON];
                break;
            }
            case SDL_BUTTON_X1: {
                button = &oat_context.mouse_buttons[OAT_MOUSE_4BUTTON];
                break;
            }
            case SDL_BUTTON_X2: {
                button = &oat_context.mouse_buttons[OAT_MOUSE_5BUTTON];
                break;
            }
            }

            if (button == NULL) {
                continue;
            }

            button->pressed = event.button.state == SDL_PRESSED;
            button->released = event.button.state == SDL_RELEASED;
            button->down = event.button.state == SDL_PRESSED;
            button->single_click = event.button.clicks == 1;
            button->double_click = event.button.clicks == 2;
            continue;
        }
    }
}

struct oat_key const*
oat_key_0(void)
{
    return &oat_context.keys[OAT_KEY_0];
}

struct oat_key const*
oat_key_1(void)
{
    return &oat_context.keys[OAT_KEY_1];
}

struct oat_key const*
oat_key_2(void)
{
    return &oat_context.keys[OAT_KEY_2];
}

struct oat_key const*
oat_key_3(void)
{
    return &oat_context.keys[OAT_KEY_3];
}

struct oat_key const*
oat_key_4(void)
{
    return &oat_context.keys[OAT_KEY_4];
}

struct oat_key const*
oat_key_5(void)
{
    return &oat_context.keys[OAT_KEY_5];
}

struct oat_key const*
oat_key_6(void)
{
    return &oat_context.keys[OAT_KEY_6];
}

struct oat_key const*
oat_key_7(void)
{
    return &oat_context.keys[OAT_KEY_7];
}

struct oat_key const*
oat_key_8(void)
{
    return &oat_context.keys[OAT_KEY_8];
}

struct oat_key const*
oat_key_9(void)
{
    return &oat_context.keys[OAT_KEY_9];
}

struct oat_key const*
oat_key_a(void)
{
    return &oat_context.keys[OAT_KEY_A];
}

struct oat_key const*
oat_key_b(void)
{
    return &oat_context.keys[OAT_KEY_B];
}

struct oat_key const*
oat_key_c(void)
{
    return &oat_context.keys[OAT_KEY_C];
}

struct oat_key const*
oat_key_d(void)
{
    return &oat_context.keys[OAT_KEY_D];
}

struct oat_key const*
oat_key_e(void)
{
    return &oat_context.keys[OAT_KEY_E];
}

struct oat_key const*
oat_key_f(void)
{
    return &oat_context.keys[OAT_KEY_F];
}

struct oat_key const*
oat_key_g(void)
{
    return &oat_context.keys[OAT_KEY_G];
}

struct oat_key const*
oat_key_h(void)
{
    return &oat_context.keys[OAT_KEY_H];
}

struct oat_key const*
oat_key_i(void)
{
    return &oat_context.keys[OAT_KEY_I];
}

struct oat_key const*
oat_key_j(void)
{
    return &oat_context.keys[OAT_KEY_J];
}

struct oat_key const*
oat_key_k(void)
{
    return &oat_context.keys[OAT_KEY_K];
}

struct oat_key const*
oat_key_l(void)
{
    return &oat_context.keys[OAT_KEY_L];
}

struct oat_key const*
oat_key_m(void)
{
    return &oat_context.keys[OAT_KEY_M];
}

struct oat_key const*
oat_key_n(void)
{
    return &oat_context.keys[OAT_KEY_N];
}

struct oat_key const*
oat_key_o(void)
{
    return &oat_context.keys[OAT_KEY_O];
}

struct oat_key const*
oat_key_p(void)
{
    return &oat_context.keys[OAT_KEY_P];
}

struct oat_key const*
oat_key_q(void)
{
    return &oat_context.keys[OAT_KEY_Q];
}

struct oat_key const*
oat_key_r(void)
{
    return &oat_context.keys[OAT_KEY_R];
}

struct oat_key const*
oat_key_s(void)
{
    return &oat_context.keys[OAT_KEY_S];
}

struct oat_key const*
oat_key_t(void)
{
    return &oat_context.keys[OAT_KEY_T];
}

struct oat_key const*
oat_key_u(void)
{
    return &oat_context.keys[OAT_KEY_U];
}

struct oat_key const*
oat_key_v(void)
{
    return &oat_context.keys[OAT_KEY_V];
}

struct oat_key const*
oat_key_w(void)
{
    return &oat_context.keys[OAT_KEY_W];
}

struct oat_key const*
oat_key_x(void)
{
    return &oat_context.keys[OAT_KEY_X];
}

struct oat_key const*
oat_key_y(void)
{
    return &oat_context.keys[OAT_KEY_Y];
}

struct oat_key const*
oat_key_z(void)
{
    return &oat_context.keys[OAT_KEY_Z];
}

struct oat_key const*
oat_key_f1(void)
{
    return &oat_context.keys[OAT_KEY_F1];
}

struct oat_key const*
oat_key_f2(void)
{
    return &oat_context.keys[OAT_KEY_F2];
}

struct oat_key const*
oat_key_f3(void)
{
    return &oat_context.keys[OAT_KEY_F3];
}

struct oat_key const*
oat_key_f4(void)
{
    return &oat_context.keys[OAT_KEY_F4];
}

struct oat_key const*
oat_key_f5(void)
{
    return &oat_context.keys[OAT_KEY_F5];
}

struct oat_key const*
oat_key_f6(void)
{
    return &oat_context.keys[OAT_KEY_F6];
}

struct oat_key const*
oat_key_f7(void)
{
    return &oat_context.keys[OAT_KEY_F7];
}

struct oat_key const*
oat_key_f8(void)
{
    return &oat_context.keys[OAT_KEY_F8];
}

struct oat_key const*
oat_key_f9(void)
{
    return &oat_context.keys[OAT_KEY_F9];
}

struct oat_key const*
oat_key_f10(void)
{
    return &oat_context.keys[OAT_KEY_F10];
}

struct oat_key const*
oat_key_f11(void)
{
    return &oat_context.keys[OAT_KEY_F11];
}

struct oat_key const*
oat_key_f12(void)
{
    return &oat_context.keys[OAT_KEY_F12];
}

struct oat_key const*
oat_key_uarrow(void)
{
    return &oat_context.keys[OAT_KEY_UARROW];
}

struct oat_key const*
oat_key_darrow(void)
{
    return &oat_context.keys[OAT_KEY_DARROW];
}

struct oat_key const*
oat_key_larrow(void)
{
    return &oat_context.keys[OAT_KEY_LARROW];
}

struct oat_key const*
oat_key_rarrow(void)
{
    return &oat_context.keys[OAT_KEY_RARROW];
}

struct oat_key const*
oat_key_tab(void)
{
    return &oat_context.keys[OAT_KEY_TAB];
}

struct oat_key const*
oat_key_lalt(void)
{
    return &oat_context.keys[OAT_KEY_LALT];
}

struct oat_key const*
oat_key_ralt(void)
{
    return &oat_context.keys[OAT_KEY_RALT];
}

struct oat_key const*
oat_key_lctrl(void)
{
    return &oat_context.keys[OAT_KEY_LCTRL];
}

struct oat_key const*
oat_key_rctrl(void)
{
    return &oat_context.keys[OAT_KEY_RCTRL];
}

struct oat_key const*
oat_key_lshift(void)
{
    return &oat_context.keys[OAT_KEY_LSHIFT];
}

struct oat_key const*
oat_key_rshift(void)
{
    return &oat_context.keys[OAT_KEY_RSHIFT];
}

struct oat_key const*
oat_key_enter(void)
{
    return &oat_context.keys[OAT_KEY_ENTER];
}

struct oat_key const*
oat_key_backspace(void)
{
    return &oat_context.keys[OAT_KEY_BACKSPACE];
}

struct oat_key const*
oat_key_space(void)
{
    return &oat_context.keys[OAT_KEY_SPACE];
}

struct oat_key const*
oat_key_escape(void)
{
    return &oat_context.keys[OAT_KEY_ESCAPE];
}

bool
oat_key_is_pressed(struct oat_key const* key)
{
    SDL_assert_release(key != NULL);
    return key->pressed;
}

bool
oat_key_is_down(struct oat_key const* key)
{
    SDL_assert_release(key != NULL);
    return key->down;
}

bool
oat_key_is_released(struct oat_key const* key)
{
    SDL_assert_release(key != NULL);
    return key->released;
}

int
oat_mouse_get_x(void)
{
    int x;
    SDL_GetMouseState(&x, NULL);
    return x;
}

int
oat_mouse_get_y(void)
{
    int y;
    SDL_GetMouseState(NULL, &y);
    return y;
}

struct oat_mouse_button const*
oat_mouse_lbutton(void)
{
    return &oat_context.mouse_buttons[OAT_MOUSE_LBUTTON];
}

struct oat_mouse_button const*
oat_mouse_mbutton(void)
{
    return &oat_context.mouse_buttons[OAT_MOUSE_MBUTTON];
}

struct oat_mouse_button const*
oat_mouse_rbutton(void)
{
    return &oat_context.mouse_buttons[OAT_MOUSE_RBUTTON];
}

struct oat_mouse_button const*
oat_mouse_4button(void)
{
    return &oat_context.mouse_buttons[OAT_MOUSE_4BUTTON];
}

struct oat_mouse_button const*
oat_mouse_5button(void)
{
    return &oat_context.mouse_buttons[OAT_MOUSE_5BUTTON];
}

bool
oat_mouse_button_is_pressed(struct oat_mouse_button const* button)
{
    SDL_assert_release(button != NULL);
    return button->pressed;
}

bool
oat_mouse_button_is_down(struct oat_mouse_button const* button)
{
    SDL_assert_release(button != NULL);
    return button->down;
}

bool
oat_mouse_button_is_released(struct oat_mouse_button const* button)
{
    SDL_assert_release(button != NULL);
    return button->released;
}

bool
oat_mouse_button_is_single_click(struct oat_mouse_button const* button)
{
    SDL_assert_release(button != NULL);
    return button->single_click;
}

bool
oat_mouse_button_is_double_click(struct oat_mouse_button const* button)
{
    SDL_assert_release(button != NULL);
    return button->double_click;
}

static void
oat_sprite_update_texture(struct oat_sprite* self)
{
    if (self == NULL) {
        return;
    }

    int const err = SDL_UpdateTexture(
        self->texture, NULL, self->surface->pixels, self->surface->pitch);
    if (err) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_UpdateTexture] %s",
            __func__,
            SDL_GetError());
        return;
    }

    self->texture_needs_update = false;
}

struct oat_sprite*
oat_sprite_new(int w, int h)
{
    if (w <= 0 || h <= 0) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s] invalid sprite size (%d x %d)",
            __func__,
            w,
            h);
        return NULL;
    }

    struct oat_sprite* const self = oat_xalloc(NULL, sizeof(*self));
    SDL_Surface* surface = NULL;
    SDL_Texture* texture = NULL;
    static int const DEPTH = 32;

    surface = SDL_CreateRGBSurfaceWithFormat(
        0, w, h, DEPTH, SDL_PIXELFORMAT_ARGB8888);
    if (surface == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_CreateRGBSurfaceWithFormat] %s",
            __func__,
            SDL_GetError());
        goto error;
    }

    texture = SDL_CreateTexture(
        oat_context.renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        w,
        h);
    if (texture == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_CreateTexture] %s",
            __func__,
            SDL_GetError());
        goto error;
    }
    if (SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_SetTextureBlendMode] %s",
            __func__,
            SDL_GetError());
        goto error;
    }

    self->w = w;
    self->h = h;
    self->surface = surface;
    self->texture = texture;
    self->texture_needs_update = false;

    return self;

error:
    if (self != NULL) {
        oat_xalloc(self, OAT_XALLOC_FREE);
    }
    if (surface != NULL) {
        SDL_FreeSurface(surface);
    }
    if (texture != NULL) {
        SDL_DestroyTexture(texture);
    }
    return NULL;
}

struct oat_sprite*
oat_sprite_new_png_from_mem(void const* png_buf_start, size_t png_buf_count)
{
    SDL_Surface* surface = NULL;
    struct oat_sprite* self = NULL;

    SDL_RWops* const rwops =
        SDL_RWFromConstMem(png_buf_start, (int)png_buf_count);
    if (rwops == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RWFromConstMem] %s\n",
            __func__,
            SDL_GetError());
        goto error;
    }

    surface = IMG_LoadPNG_RW(rwops);
    if (surface == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][IMG_LoadPNG_RW] %s",
            __func__,
            IMG_GetError());
        goto error;
    }

    self = oat_sprite_new(surface->w, surface->h);
    if (self == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][oat_sprite_new] Failed create sprite",
            __func__);
        goto error;
    }

    if (SDL_BlitSurface(surface, NULL, self->surface, NULL)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_BlitSurface] %s",
            __func__,
            SDL_GetError());
        goto error;
    }
    oat_sprite_update_texture(self);

    SDL_FreeSurface(surface);
    return self;

error:
    if (self != NULL) {
        oat_sprite_del(self);
    }
    if (surface != NULL) {
        SDL_FreeSurface(surface);
    }
    return NULL;
}

struct oat_sprite*
oat_sprite_new_png_from_file(char const* file)
{
    SDL_Surface* surface = NULL;
    struct oat_sprite* self = NULL;

    SDL_RWops* const rwops = SDL_RWFromFile(file, "rb");
    if (rwops == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RWFromFile] %s\n",
            __func__,
            SDL_GetError());
        goto error;
    }

    surface = IMG_LoadPNG_RW(rwops);
    if (surface == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][IMG_LoadPNG_RW] %s",
            __func__,
            IMG_GetError());
        goto error;
    }

    self = oat_sprite_new(surface->w, surface->h);
    if (self == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][oat_sprite_new] Failed create sprite",
            __func__);
        goto error;
    }

    if (SDL_BlitSurface(surface, NULL, self->surface, NULL)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_BlitSurface] %s",
            __func__,
            SDL_GetError());
        goto error;
    }
    oat_sprite_update_texture(self);

    SDL_FreeSurface(surface);
    return self;

error:
    if (self != NULL) {
        oat_sprite_del(self);
    }
    if (surface != NULL) {
        SDL_FreeSurface(surface);
    }
    return NULL;
}

struct oat_sprite*
oat_sprite_new_text(
    char const* text,
    struct oat_font* font,
    int font_size,
    uint8_t r,
    uint8_t g,
    uint8_t b,
    uint8_t a)
{
    if (text == NULL || font == NULL || text[0] == '\0') {
        return NULL;
    }

    SDL_Surface* surface = NULL;
    struct oat_sprite* self = NULL;

    TTF_Font* ttf_font = oat_font_add_or_get_cached(font, font_size);
    SDL_Color const color = {.r = r, .g = g, .b = b, .a = a};
    surface = TTF_RenderUTF8_Blended(ttf_font, text, color);
    if (surface == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][TTF_RenderUTF8_Blended] %s\n",
            __func__,
            TTF_GetError());
        goto error;
    }

    self = oat_sprite_new(surface->w, surface->h);
    if (self == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][oat_sprite_new] Failed create sprite",
            __func__);
        goto error;
    }

    if (SDL_BlitSurface(surface, NULL, self->surface, NULL)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_BlitSurface] %s",
            __func__,
            SDL_GetError());
        goto error;
    }
    oat_sprite_update_texture(self);

    SDL_FreeSurface(surface);
    return self;

error:
    if (self != NULL) {
        oat_sprite_del(self);
    }
    if (surface != NULL) {
        SDL_FreeSurface(surface);
    }
    return NULL;
}

void
oat_sprite_del(struct oat_sprite* self)
{
    if (self == NULL) {
        return;
    }

    SDL_FreeSurface(self->surface);
    SDL_DestroyTexture(self->texture);
    SDL_memset(self, 0x00, sizeof(*self)); // scrub
    oat_xalloc(self, OAT_XALLOC_FREE);
}

int
oat_sprite_get_w(struct oat_sprite* self)
{
    if (self == NULL) {
        return 0;
    }

    return self->w;
}

int
oat_sprite_get_h(struct oat_sprite* self)
{
    if (self == NULL) {
        return 0;
    }

    return self->h;
}

static Uint32*
oat_sprite_pixel(struct oat_sprite const* sprite, int x, int y)
{
    SDL_assert_release(sprite != NULL);

    if (!(0 <= x && x < sprite->w)) {
        return NULL;
    }
    if (!(0 <= y && y < sprite->h)) {
        return NULL;
    }

    Uint32* const pixels = sprite->surface->pixels;
    int const rowlen =
        sprite->surface->pitch / sprite->surface->format->BytesPerPixel;
    return pixels + (y * rowlen) + x;
}

void
oat_sprite_set_pixel(
    struct oat_sprite* self,
    int x,
    int y,
    uint8_t r,
    uint8_t g,
    uint8_t b,
    uint8_t a)
{
    if (self == NULL) {
        return;
    }

    Uint32* const px = oat_sprite_pixel(self, x, y);
    if (px == NULL) {
        return;
    }

    Uint32 const rgba = SDL_MapRGBA(self->surface->format, r, g, b, a);
    *px = rgba;
    self->texture_needs_update = true;
}

void
oat_sprite_get_pixel(
    struct oat_sprite const* self,
    int x,
    int y,
    uint8_t* r,
    uint8_t* g,
    uint8_t* b,
    uint8_t* a)
{
    uint8_t tmp_r = 0;
    uint8_t tmp_g = 0;
    uint8_t tmp_b = 0;
    uint8_t tmp_a = 0;

    if (self == NULL) {
        goto result;
    }

    Uint32* const px = oat_sprite_pixel(self, x, y);
    if (px == NULL) {
        goto result;
    }

    SDL_GetRGBA(*px, self->surface->format, &tmp_r, &tmp_g, &tmp_b, &tmp_a);

result:
    if (r != NULL) {
        *r = tmp_r;
    }
    if (g != NULL) {
        *g = tmp_g;
    }
    if (b != NULL) {
        *b = tmp_b;
    }
    if (a != NULL) {
        *a = tmp_a;
    }
}

void
oat_sprite_draw_clear(struct oat_sprite* self, uint8_t r, uint8_t g, uint8_t b)
{
    if (self == NULL) {
        return;
    }

    Uint32 const rgba = SDL_MapRGBA(self->surface->format, r, g, b, 0xFF);
    if (SDL_FillRect(self->surface, NULL, rgba)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_FillRect] %s",
            __func__,
            SDL_GetError());
        return;
    }
    self->texture_needs_update = true;
}

void
oat_sprite_draw_fill(
    struct oat_sprite* self,
    uint8_t r,
    uint8_t g,
    uint8_t b,
    uint8_t a)
{
    if (self == NULL) {
        return;
    }

    Uint32 const rgba = SDL_MapRGBA(self->surface->format, r, g, b, a);
    if (SDL_FillRect(self->surface, NULL, rgba)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_FillRect] %s",
            __func__,
            SDL_GetError());
        return;
    }
    self->texture_needs_update = true;
}

void
oat_sprite_draw_sprite(
    struct oat_sprite* self,
    struct oat_sprite* sprite,
    int x,
    int y)
{
    if (self == NULL || sprite == NULL) {
        return;
    }

    SDL_Rect dst = {.x = x, .y = y, .w = sprite->w, .h = sprite->h};
    if (SDL_BlitSurface(sprite->surface, NULL, self->surface, &dst)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_BlitSurface] %s",
            __func__,
            SDL_GetError());
        return;
    }
    self->texture_needs_update = true;
}

void
oat_sprite_draw_sprite_partial(
    struct oat_sprite* self,
    struct oat_sprite* sprite,
    int x,
    int y,
    int partial_x,
    int partial_y,
    int partial_w,
    int partial_h)
{
    if (self == NULL || sprite == NULL) {
        return;
    }

    if (partial_w > sprite->w) {
        partial_w = sprite->w;
    }
    if (partial_h > sprite->h) {
        partial_h = sprite->h;
    }
    SDL_Rect src = {
        .x = partial_x,
        .y = partial_y,
        .w = partial_w,
        .h = partial_h,
    };
    SDL_Rect dst = {
        .x = x,
        .y = y,
        .w = partial_w,
        .h = partial_h,
    };
    if (SDL_BlitSurface(sprite->surface, &src, self->surface, &dst)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_BlitSurface] %s",
            __func__,
            SDL_GetError());
        return;
    }
    self->texture_needs_update = true;
}

void
oat_sprite_draw_text(
    struct oat_sprite* self,
    char const* text,
    int x,
    int y,
    struct oat_font* font,
    int font_size,
    uint8_t r,
    uint8_t g,
    uint8_t b,
    uint8_t a)
{
    if (self == NULL || text == NULL || font == NULL || text[0] == '\0') {
        return;
    }

    TTF_Font* ttf_font = oat_font_add_or_get_cached(font, font_size);
    SDL_Color const color = {.r = r, .g = g, .b = b, .a = a};
    SDL_Surface* const surface = TTF_RenderUTF8_Blended(ttf_font, text, color);
    if (surface == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][TTF_RenderUTF8_Blended] %s\n",
            __func__,
            TTF_GetError());
        goto end;
    }

    SDL_Rect dst = {.x = x, .y = y, .w = self->w, .h = self->h};
    if (SDL_BlitSurface(surface, NULL, self->surface, &dst)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_BlitSurface] %s",
            __func__,
            SDL_GetError());
        goto end;
    }
    self->texture_needs_update = true;

end:
    if (surface != NULL) {
        SDL_FreeSurface(surface);
    }
}

void
oat_sprite_save_png_to_file(struct oat_sprite* self, char const* file)
{
    if (self == NULL) {
        return;
    }

    if (IMG_SavePNG(self->surface, file)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][IMG_SavePNG] %s",
            __func__,
            IMG_GetError());
        return;
    }
}

struct oat_sound*
oat_sound_new(void const* buf_start, size_t buf_count)
{
    SDL_RWops* const rwops = SDL_RWFromConstMem(buf_start, (int)buf_count);
    if (rwops == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RWFromConstMem] %s\n",
            __func__,
            SDL_GetError());
        return NULL;
    }

    Mix_Chunk* const chunk = Mix_LoadWAV_RW(rwops, 1);
    if (chunk == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][Mix_LoadWAV_RW] %s",
            __func__,
            Mix_GetError());
        return NULL;
    }

    struct oat_sound* const self = oat_xalloc(NULL, sizeof(*self));
    self->chunk = chunk;
    return self;
}

void
oat_sound_del(struct oat_sound* self)
{
    if (self == NULL) {
        return;
    }

    Mix_FreeChunk(self->chunk);
    SDL_memset(self, 0x00, sizeof(*self)); // scrub
    oat_xalloc(self, OAT_XALLOC_FREE);
}

void
oat_sound_play(struct oat_sound* self)
{
    if (self == NULL) {
        return;
    }

    int const channel = Mix_PlayChannel(-1, self->chunk, 0);
    if (channel == -1) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][Mix_PlayChannel] %s",
            __func__,
            Mix_GetError());
        return;
    }
}

struct oat_font*
oat_font_new_ttf_from_mem(void const* ttf_buf_start, size_t ttf_buf_count)
{
    SDL_assert_release(ttf_buf_start != NULL || ttf_buf_count == 0);

    if (ttf_buf_count == 0) {
        return NULL;
    }

    void* ttf_buf_owned = oat_xalloc(NULL, ttf_buf_count);
    SDL_memcpy(ttf_buf_owned, ttf_buf_start, ttf_buf_count);

    struct oat_font* const self = oat_xalloc(NULL, sizeof(*self));
    self->ttf_buf_start = ttf_buf_owned;
    self->ttf_buf_count = ttf_buf_count;
    self->cached_start = NULL;
    self->cached_count = 0;

    // Load/cache with an arbitrary size of 8 to ensure the TTF data is valid.
    if (oat_font_add_or_get_cached(self, 8) == NULL) {
        oat_font_del(self);
        return NULL;
    }

    return self;
}

struct oat_font*
oat_font_new_ttf_from_file(char const* file)
{
    void* ttf_buf_start = NULL;
    size_t ttf_buf_count = 0;

    SDL_RWops* const rwops = SDL_RWFromFile(file, "rb");
    if (rwops == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RWFromFile] %s\n",
            __func__,
            SDL_GetError());
        return NULL;
    }

    char buf[512] = {0};
    size_t nread = 0;
    while ((nread = SDL_RWread(rwops, buf, 1, sizeof(buf))) != 0) {
        ttf_buf_start = oat_xalloc(ttf_buf_start, ttf_buf_count + nread);
        SDL_memcpy(ttf_buf_start + ttf_buf_count, buf, nread);
        ttf_buf_count += nread;
    }

    SDL_RWclose(rwops);

    if (ttf_buf_count == 0) {
        oat_xalloc(ttf_buf_start, OAT_XALLOC_FREE);
        return NULL;
    }

    struct oat_font* const self = oat_xalloc(NULL, sizeof(*self));
    self->ttf_buf_start = ttf_buf_start;
    self->ttf_buf_count = ttf_buf_count;
    self->cached_start = NULL;
    self->cached_count = 0;

    // Load/cache with an arbitrary size of 8 to ensure the TTF data is valid.
    if (oat_font_add_or_get_cached(self, 8) == NULL) {
        oat_font_del(self);
        return NULL;
    }

    return self;
}

void
oat_font_del(struct oat_font* self)
{
    if (self == NULL) {
        return;
    }

    for (size_t i = 0; i < self->cached_count; ++i) {
        TTF_CloseFont(self->cached_start[i].font);
    }
    oat_xalloc(self->cached_start, OAT_XALLOC_FREE);
    oat_xalloc(self->ttf_buf_start, OAT_XALLOC_FREE);

    SDL_memset(self, 0x00, sizeof(*self)); // scrub
    oat_xalloc(self, OAT_XALLOC_FREE);
}

void
oat_measure_text(
    char const* text,
    struct oat_font* font,
    int font_size,
    int* w,
    int* h)
{
    int tmp_w = 0;
    int tmp_h = 0;
    if (text == NULL || font == NULL || text[0] == '\0') {
        goto end;
    }

    TTF_Font* ttf_font = oat_font_add_or_get_cached(font, font_size);
    if (TTF_SizeUTF8(ttf_font, text, &tmp_w, &tmp_h)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][TTF_SizeUTF8] %s\n",
            __func__,
            TTF_GetError());
        goto end;
    }

end:
    if (w != NULL) {
        *w = tmp_w;
    }
    if (h != NULL) {
        *h = tmp_h;
    }
}

void
oat_draw_clear(uint8_t r, uint8_t g, uint8_t b)
{
    static uint8_t const a = SDL_ALPHA_OPAQUE;
    if (SDL_SetRenderDrawColor(oat_context.renderer, r, g, b, a)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_SetRenderDrawColor] %s",
            __func__,
            SDL_GetError());
        return;
    }
    if (SDL_RenderClear(oat_context.renderer)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RenderClear] %s",
            __func__,
            SDL_GetError());
        return;
    }
}

void
oat_draw_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    if (SDL_SetRenderDrawColor(oat_context.renderer, r, g, b, a)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_SetRenderDrawColor] %s",
            __func__,
            SDL_GetError());
        return;
    }

    if (SDL_RenderDrawPoint(oat_context.renderer, x, y)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RenderDrawPoint] %s",
            __func__,
            SDL_GetError());
        return;
    }
}

void
oat_draw_rectangle(
    int x,
    int y,
    int w,
    int h,
    uint8_t r,
    uint8_t g,
    uint8_t b,
    uint8_t a)
{
    if (w <= 0 || h <= 0) {
        return;
    }

    if (SDL_SetRenderDrawColor(oat_context.renderer, r, g, b, a)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_SetRenderDrawColor] %s",
            __func__,
            SDL_GetError());
        return;
    }

    SDL_Rect const rect = {.x = x, .y = y, .w = w, .h = h};
    if (SDL_RenderFillRect(oat_context.renderer, &rect)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RenderFillRect] %s",
            __func__,
            SDL_GetError());
        return;
    }
}

void
oat_draw_rectangle_outline(
    int x,
    int y,
    int w,
    int h,
    uint8_t r,
    uint8_t g,
    uint8_t b,
    uint8_t a,
    int thickness)
{
    if (w <= 0 || h <= 0 || thickness <= 0) {
        return;
    }
    int const thickness_x = thickness <= w ? thickness : w;
    int const thickness_y = thickness <= h ? thickness : h;

    if (SDL_SetRenderDrawColor(oat_context.renderer, r, g, b, a)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_SetRenderDrawColor] %s",
            __func__,
            SDL_GetError());
        return;
    }

    SDL_Rect const rects[] = {
        // top
        {.x = x, .y = y, .w = w, .h = thickness_y},
        // bottom
        {.x = x, .y = y + h - thickness_y, .w = w, .h = thickness_y},
        // left
        {.x = x, .y = y, .w = thickness_x, .h = h},
        // right
        {.x = x + w - thickness_x, .y = y, .w = thickness_x, .h = h},
    };
    if (SDL_RenderFillRects(oat_context.renderer, rects, 4)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RenderFillRects] %s",
            __func__,
            SDL_GetError());
        return;
    }
}

void
oat_draw_text(
    char const* text,
    int x,
    int y,
    struct oat_font* font,
    int font_size,
    uint8_t r,
    uint8_t g,
    uint8_t b,
    uint8_t a)
{
    if (text == NULL || font == NULL || text[0] == '\0') {
        return;
    }

    SDL_Surface* surface = NULL;
    SDL_Texture* texture = NULL;

    TTF_Font* ttf_font = oat_font_add_or_get_cached(font, font_size);
    SDL_Color const color = {.r = r, .g = g, .b = b, .a = a};
    surface = TTF_RenderUTF8_Blended(ttf_font, text, color);
    if (surface == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][TTF_RenderUTF8_Blended] %s\n",
            __func__,
            TTF_GetError());
        goto end;
    }
    texture = SDL_CreateTextureFromSurface(oat_context.renderer, surface);
    if (texture == NULL) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_CreateTextureFromSurface] %s\n",
            __func__,
            SDL_GetError());
        goto end;
    }

    int w = 0;
    int h = 0;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_Rect dst = {.x = x, .y = y, .w = w, .h = h};
    if (SDL_RenderCopy(oat_context.renderer, texture, NULL, &dst)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RenderCopy] %s",
            __func__,
            SDL_GetError());
        goto end;
    }

end:
    if (surface != NULL) {
        SDL_FreeSurface(surface);
    }
    if (texture != NULL) {
        SDL_DestroyTexture(texture);
    }
}

void
oat_draw_sprite(struct oat_sprite* sprite, int x, int y)
{
    if (sprite == NULL) {
        return;
    }

    if (sprite->texture_needs_update) {
        oat_sprite_update_texture(sprite);
    }

    int w = 0;
    int h = 0;
    SDL_QueryTexture(sprite->texture, NULL, NULL, &w, &h);
    SDL_Rect const dst = {.x = x, .y = y, .w = w, .h = h};
    if (SDL_RenderCopy(oat_context.renderer, sprite->texture, NULL, &dst)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RenderCopy] %s",
            __func__,
            SDL_GetError());
        return;
    }
}

void
oat_draw_sprite_ex(
    struct oat_sprite* sprite,
    int x,
    int y,
    double scale_x,
    double scale_y,
    int rotation_x_offset,
    int rotation_y_offset,
    double rotation_degrees,
    bool flip_horizontal,
    bool flip_vertical)
{
    if (sprite == NULL) {
        return;
    }

    if (sprite->texture_needs_update) {
        oat_sprite_update_texture(sprite);
    }

    int w = 0;
    int h = 0;
    SDL_QueryTexture(sprite->texture, NULL, NULL, &w, &h);
    SDL_Rect const dst = {
        .x = x,
        .y = y,
        .w = (int)(w * scale_x),
        .h = (int)(h * scale_y),
    };

    SDL_Point const center = {.x = rotation_x_offset, .y = rotation_y_offset};

    SDL_RendererFlip flip = 0;
    if (flip_horizontal) {
        flip |= SDL_FLIP_HORIZONTAL;
    }
    if (flip_vertical) {
        flip |= SDL_FLIP_VERTICAL;
    }

    int const err = SDL_RenderCopyEx(
        oat_context.renderer,
        sprite->texture,
        NULL,
        &dst,
        rotation_degrees,
        &center,
        flip);
    if (err) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RenderCopyEX] %s",
            __func__,
            SDL_GetError());
        return;
    }
}

void
oat_draw_sprite_partial(
    struct oat_sprite* sprite,
    int x,
    int y,
    int partial_x,
    int partial_y,
    int partial_w,
    int partial_h)
{
    if (sprite == NULL) {
        return;
    }

    if (sprite->texture_needs_update) {
        oat_sprite_update_texture(sprite);
    }

    int w = 0;
    int h = 0;
    SDL_QueryTexture(sprite->texture, NULL, NULL, &w, &h);
    if (partial_w > w) {
        partial_w = w;
    }
    if (partial_h > h) {
        partial_h = h;
    }
    SDL_Rect const src = {
        .x = partial_x,
        .y = partial_y,
        .w = partial_w,
        .h = partial_h,
    };
    SDL_Rect const dst = {
        .x = x,
        .y = y,
        .w = partial_w,
        .h = partial_h,
    };
    if (SDL_RenderCopy(oat_context.renderer, sprite->texture, &src, &dst)) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RenderCopy] %s",
            __func__,
            SDL_GetError());
        return;
    }
}

void
oat_draw_sprite_partial_ex(
    struct oat_sprite* sprite,
    int x,
    int y,
    int partial_x,
    int partial_y,
    int partial_w,
    int partial_h,
    double scale_x,
    double scale_y,
    int rotation_x_offset,
    int rotation_y_offset,
    double rotation_degrees,
    bool flip_horizontal,
    bool flip_vertical)
{
    if (sprite == NULL) {
        return;
    }

    if (sprite->texture_needs_update) {
        oat_sprite_update_texture(sprite);
    }

    int w = 0;
    int h = 0;
    SDL_QueryTexture(sprite->texture, NULL, NULL, &w, &h);
    if (partial_w > w) {
        partial_w = w;
    }
    if (partial_h > h) {
        partial_h = h;
    }
    SDL_Rect const src = {
        .x = partial_x,
        .y = partial_y,
        .w = partial_w,
        .h = partial_h,
    };
    SDL_Rect const dst = {
        .x = x,
        .y = y,
        .w = (int)(partial_w * scale_x),
        .h = (int)(partial_h * scale_y),
    };

    SDL_Point const center = {.x = rotation_x_offset, .y = rotation_y_offset};

    SDL_RendererFlip flip = 0;
    if (flip_horizontal) {
        flip |= SDL_FLIP_HORIZONTAL;
    }
    if (flip_vertical) {
        flip |= SDL_FLIP_VERTICAL;
    }

    int const err = SDL_RenderCopyEx(
        oat_context.renderer,
        sprite->texture,
        &src,
        &dst,
        rotation_degrees,
        &center,
        flip);
    if (err) {
        SDL_LogError(
            SDL_LOG_CATEGORY_ERROR,
            "[%s][SDL_RenderCopyEX] %s",
            __func__,
            SDL_GetError());
        return;
    }
}
