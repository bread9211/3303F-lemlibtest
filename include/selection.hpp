#pragma once

#include "main.h"

class Selector {
    public:
        const char *btnmMap[11] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", NULL};

        lv_obj_t *tabview;
        lv_obj_t *btnm_one;
        lv_obj_t *btnm_two;
        lv_obj_t *btnm_three;

        
        
        Selector();

        lv_res_t btnm_one_action(lv_obj_t *btnm, const char *txt);
};