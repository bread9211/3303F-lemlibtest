// #include "main.h"

// /**
//  * IN reference auton selector:
//  * todo: implement ability to pass custom autons to function (lines 71 - 75)
//  * todo: set custom theme (lines 81 - 82)
//  * 
//  * EXTRA:
//  * todo: implement ability to dynamically define size of the const char*[] array
//  * todo: implement ability to run "test" autons!
//  * todo: make some members (functions) private, and some public!
// */

// Selector::Selector() {
//     tabview = lv_tabview_create(lv_scr_act(), NULL);

//     lv_obj_t *tab_one = lv_tabview_add_tab(tabview, "Tab One");
//     lv_obj_t *tab_two = lv_tabview_add_tab(tabview, "Tab Two");
//     lv_obj_t *tab_three = lv_tabview_add_tab(tabview, "Tab Three");

//     lv_tabview_set_tab_act(tab_one, 0, LV_ANIM_NONE);

//     btnm_one = lv_btnm_create(tab_one, NULL);
//     lv_btnm_set_map(btnm_one, btnmMap);

// };