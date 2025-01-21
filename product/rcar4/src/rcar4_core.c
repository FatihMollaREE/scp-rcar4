/*
*
* License
*
*/

#include <rcar4_core.h>

#include <fwk_mmio.h>

#define RCAR4_CLUSTER_COUNT 1

unsigned int rcar4_core_get_count(void)
{
    /* hardcoded */
    return 3;
}

unsigned int rcar4_cluster_get_count(void)
{
    return RCAR4_CLUSTER_COUNT;
}
