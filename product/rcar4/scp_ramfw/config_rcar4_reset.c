/*
*
* LICENSE
*
*/

#include <fwk_element.h>
#include <fwk_module.h>
#include <mod_rcar4_reset.h>

/*
struct fwk_module_elements {
    enum fwk_module_elements_type type;

    union {
        const struct fwk_element *(*generator)(fwk_id_t module_id);
        const struct fwk_element *table;
    };
}; 


struct fwk_module_config {
    const void *data;
    struct fwk_module_elements elements;
};

struct fwk_element {
    const char *name;
    size_t sub_element_count;
    const void *data;
}
*/

#if 1 
const struct fwk_element rcar4_reset_element_table[] = {
    {
        .name = "srt28", /* PWM */
        .data = &( (struct mod_rcar4_reset_dev_config) {
            .control_reg = CPG_SMSTPCR6,
            .bit = 28,
        }),
    },
    {0}, // Terminate description 
};

/*
static const struct mod_reset_domain_config rcar4_reset_config = {

};
*/

static const struct fwk_element *rcar4_reset_get_element_table(fwk_id_t module_id)
{
    return rcar4_reset_element_table;
}
#endif

struct fwk_module_config config_rcar4_reset = {
    .data =  NULL, //&rcar4_reset_config, 
    .elements = FWK_MODULE_DYNAMIC_ELEMENTS(rcar4_reset_get_element_table),
};