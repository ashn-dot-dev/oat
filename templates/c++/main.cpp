#include <cstdlib>
#include <oat.hpp>

static int const SCREEN_W = 640;
static int const SCREEN_H = 480;

int
main(void)
{
    oat_init(SCREEN_W, SCREEN_H, "game");
    std::atexit(oat_fini);

    oat_set_target_fps(60);
    while (!oat_get_quit_requested()) {
        oat_draw_clear(0xFF, 0xFF, 0xFF);

        /* PER-FRAME CODE GOES HERE */

        oat_end_frame();
    }
}
