/*
* LICENSE
*/

#include <mod_reset_domain.h>
#include <fwk_module.h>
#include <mod_rcar4_reset.h>

#include <mmio.h>

#include <fwk_assert.h>
#include <fwk_element.h>
#include <fwk_status.h>
#include <fwk_mm.h>
#include <fwk_module.h>
#include <fwk_module_idx.h>

#include <stdint.h>
#include <stdlib.h>
//#include <lib/utils_def.h>

static struct rcar4_reset_ctx module_ctx;


static void udelay(uint32_t cycles) 
{
  volatile uint32_t i;

    for (i = 0UL; i < cycles ; ++i)
        __asm__ volatile ("nop"); /* FATIH assembler quick help*/
}

static const struct mod_reset_domain_drv_api api_reset = {
    .set_reset_state = rcar4_set_reset_state,
};

static int rcar4_auto_domain(fwk_id_t dev_id, uint32_t state)
{
    struct rcar4_reset_dev_ctx *ctx;

    ctx = module_ctx.dev_ctx_table + fwk_id_get_element_idx(dev_id);

    mmio_write_32(SOFTWARE_RESET_BASE + SRCR(ctx->config->control_reg) , BIT(ctx->config->bit) ); // set reset

    // RLCK @ 32,8kHz  ~= 30,49us
    udelay(SCSR_DELAY_US); // wait for RLCK as per user manual

    mmio_write_32(SOFTWARE_RESET_BASE + SRSTCLR(ctx->config->control_reg) , BIT(ctx->config->bit) ); // release reset

    return FWK_SUCCESS;

}

static int rcar4_assert_domain(fwk_id_t dev_id)
{
    struct rcar4_reset_dev_ctx *ctx;

    ctx = module_ctx.dev_ctx_table + fwk_id_get_element_idx(dev_id);

   mmio_write_32(SOFTWARE_RESET_BASE + SRCR(ctx->config->control_reg) , BIT(ctx->config->bit) ); // set reset

    return FWK_SUCCESS;
}


static int rcar4_deassert_domain(fwk_id_t dev_id)
{
    struct rcar4_reset_dev_ctx *ctx;

    ctx = module_ctx.dev_ctx_table + fwk_id_get_element_idx(dev_id);

     mmio_write_32(SOFTWARE_RESET_BASE + SRSTCLR(ctx->config->control_reg) , BIT(ctx->config->bit) ); // release reset

    return FWK_SUCCESS;
}

static int rcar4_set_reset_state(fwk_id_t dev_id, enum mod_reset_domain_mode mode, uint32_t reset_state, uintptr_t cookie)
{
    switch (mode) {
        case MOD_RESET_DOMAIN_AUTO_RESET:
            rcar4_auto_domain(dev_id, reset_state); 
            break;

        case MOD_RESET_DOMAIN_MODE_EXPLICIT_ASSERT:
            rcar4_assert_domain(dev_id);  
            break;

        case MOD_RESET_DOMAIN_MODE_EXPLICIT_DEASSERT:
            rcar4_deassert_domain(dev_id);
            break;

        default:
            return FWK_E_ACCESS;
    }

    return FWK_SUCCESS;
}

static int rcar4_reset_init(fwk_id_t module_id, unsigned int element_count, const void* data)
{
    module_ctx.dev_count = element_count;
    
    if (element_count == 0)
        return FWK_SUCCESS;

    module_ctx.dev_ctx_table = fwk_mm_calloc(element_count, sizeof(struct rcar4_reset_dev_ctx));
    if (module_ctx.dev_ctx_table == NULL)
        return FWK_E_NOMEM;

    return FWK_SUCCESS;
}

static int rcar4_reset_element_init(fwk_id_t element_id, unsigned int sub_element_count, const void* data)
{
    struct rcar4_reset_dev_ctx *ctx;
    const struct mod_rcar4_reset_dev_config *dev_config = data;

    if(!fwk_module_is_valid_element_id(element_id))
        return FWK_E_PARAM;

    ctx = module_ctx.dev_ctx_table + fwk_id_get_element_idx(element_id);
    ctx->config = dev_config;
}

static int rcar4_reset_process_bind_request(fwk_id_t source_id, fwk_id_t target_id, fwk_id_t api_id, const void **api)
{
    *api = &api_reset;
    return FWK_SUCCESS;
}

const struct fwk_module mod_rcar4_reset = {
    .type = FWK_MODULE_TYPE_DRIVER,
    .api_count = MOD_RCAR4_RESET_API_COUNT,     // passt das?, kann ich einfach .* = 1 schreiben?
    .event_count = 0,
    .init = rcar4_reset_init,
    .element_init = rcar4_reset_element_init,
    .process_bind_request = rcar4_reset_process_bind_request,
}; 
