/*
* LICENSE
*/


#ifndef MOD_RCAR4_CLOCK_H
#define MOD_RCAR4_CLOCK_H



struct mod_rcar4_clock_drv_api {

    const char* name;

    int (*set_rate)(uint64_t rate);
    
    int (*get_rate)(uint64_t* rate);
};

enum mod_rcar4_clock_api_type {
    
    MOD_RCAR4_CLOCK_API_COUNT = -99, // tbu  
};

#endif /* MOD_RCAR4_CLOCK_H */