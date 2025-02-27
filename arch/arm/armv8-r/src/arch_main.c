/*
*
* License
* 
*/

#include <stdint.h>
#include <fwk_arch.h>
#include <fwk_attributes.h>
#include <fwk_noreturn.h>
#include <fwk_status.h>
#include <arch_gic.h>
#include <stdbool.h>
#include <fwk_assert.h>

unsigned int critical_section_nest_level;

void panic(void)
{
	while(true)
		{
		}
}

static struct fwk_arch_init_driver arch_init_driver = {
    .interrupt = arm_gic_init,
};

void arch_main(void)
{
	int status;

	status = fwk_arch_init(&arch_init_driver);

	if(status != FWK_SUCCESS)
		panic();
}
