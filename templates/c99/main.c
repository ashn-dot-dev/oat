#include <stdlib.h>
#include <oat.h>

static int const SCREEN_W = 640;
static int const SCREEN_H = 480;
static double const TIMESTEP = 1.0 / 60.0;

int
main(void)
{
    oat_init(SCREEN_W, SCREEN_H, "game");
    atexit(oat_fini);

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

        oat_draw_clear(0xFF, 0xFF, 0xFF);

        /* PER-FRAME CODE GOES HERE */

        oat_end_frame();
    }
}
