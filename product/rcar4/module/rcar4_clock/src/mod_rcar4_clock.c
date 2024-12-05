/*
* LICENSE
*/

#include <fwk_module.h>
#include <mod_rcar4_clock.h>


static int rcar4_clock_init(fwk_id_t module_id, unsigned int element_count, const void* data)
{
    //  code um clock zu initialiesieren ?
}

const struct fwk_module mod_rcar4_clock = {
    .type = FWK_MODULE_TYPE_DRIVER,
    .api_count = MOD_RCAR4_CLOCK_API_COUNT,     // tbu
    .event_count = 0,                           // tbu?
    .init = rcar4_clock_init,
    .element_init = rcar_clock_element_init,
    .process_bind_request = rcar_clock_process_bind_request,
    .start = rcar_clock_start,
}; 

// copied from rcar

// ganze datei, um obige funktionen zu implementieren