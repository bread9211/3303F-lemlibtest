/**
 * TODO: should this just include `selection.hpp`, or ALL of the files?
*/
#include "main.h"

#include "selection.hpp"

/**
 * iteration 1
*/

/**
 * just switch/case selector.auton instead of passing function directly ;-;
*/
// Selector::Selector(
//     std::map<std::string, FunctionType> far_auton_funcs,
//     std::map<std::string, FunctionType> near_auton_funcs,
//     std::map<std::string, FunctionType> skills_auton_funcs
// ) {
//     // guard clause to make sure too many autons aren't populated into the code
//     if (far_autons.size() > 10 || near_autons.size() > 10 || skills_autons.size() > 10) throw std::runtime_error("too many autons provided!");

//     /**
//      * TODO: duplicated code in for loops; make one function? (loop through far_auton_funcs... have a list that connects them to far_autons...)
//     */
//     for (const auto &auton : far_auton_funcs) {
//         far_autons.insert(far_autons.end(), std::pair<std::string, FunctionType>(auton.first, auton.second));
//     }

//     for (const auto &auton : near_auton_funcs) {
        
//     }

//     for (const auto &auton : skills_auton_funcs) {
        
//     }
// }

// void Selector::display() {
//     lv_obj_t *label = lv_label_create(lv_scr_act(), NULL);
// 	lv_label_set_text(label, "hii!!!");
// }

// lv_res_t farBtnmAction(lv_obj_t *btnm, const char *txt) {
//     printf("HELP MEEEE");
// }

/**
 * iteration 2
*/

// static void event_handler(lv_event_t * e)
// {
//     lv_event_code_t code = lv_event_get_code(e);
//     lv_obj_t * obj = lv_event_get_target(e);
//     if(code == LV_EVENT_VALUE_CHANGED) {
//         uint32_t id = lv_buttonmatrix_get_selected_button(obj);
//         const char * txt = lv_buttonmatrix_get_button_text(obj, id);
//         LV_UNUSED(txt);
//         LV_LOG_USER("%s was pressed\n", txt);
//     }
// }

// static const char * btnm_map[] = {"1", "2", "3", "4", "5", "\n",
//                                   "6", "7", "8", "9", "0", "\n",
//                                   "Action1", "Action2", ""
//                                  };

// void lv_example_buttonmatrix_1(void)
// {
//     lv_obj_t * btnm1 = lv_btnm_create(lv_screen_active());
//     lv_buttonmatrix_set_map(btnm1, btnm_map);
//     lv_buttonmatrix_set_button_width(btnm1, 10, 2);        /*Make "Action1" twice as wide as "Action2"*/
//     lv_buttonmatrix_set_button_ctrl(btnm1, 10, LV_BUTTONMATRIX_CTRL_CHECKABLE);
//     lv_buttonmatrix_set_button_ctrl(btnm1, 11, LV_BUTTONMATRIX_CTRL_CHECKED);
//     lv_obj_align(btnm1, LV_ALIGN_CENTER, 0, 0);
//     lv_obj_add_event_cb(btnm1, event_handler, LV_EVENT_ALL, NULL);
// }

/**
 * iteration 3
*/

// Test::Test() {
//     /**
//      * TODO: change hue, font!
//     */
//     lv_theme_t *th = lv_theme_alien_init(360, NULL);
//     lv_theme_set_current(th);

//     // tabview = lv_tabview_create(lv_scr_act(), NULL);

//     lv_obj_t *farTab = lv_tabview_add_tab(tabview, "Far"); // 0; default
//     // lv_obj_t *nearTab = lv_tabview_add_tab(tabview, "Near"); // 1
//     // lv_obj_t *skillsTab = lv_tabview_add_tab(tabview, "Skills"); // 2
    
//     lv_tabview_set_tab_act(farTab, 0, true);

//     // far
//     farBtnm = lv_btnm_create(farTab, NULL);
//     lv_btnm_set_map(farBtnm, farBtnmMap);
//     // lv_btnm_set_action(farBtnm, farBtnmAction);
//     lv_obj_set_size(farBtnm, 450, 50);
//     lv_obj_set_pos(farBtnm, 0, 100);
//     lv_obj_align(farBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

//     // // near
//     // nearBtnm = lv_btnm_create(nearTab, NULL);
//     // lv_btnm_set_map(nearBtnm, nearBtnmMap);
//     // lv_obj_set_size(nearBtnm, 450, 50);
//     // lv_obj_set_pos(nearBtnm, 0, 100);
//     // lv_obj_align(nearBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

//     // // skills
//     // skillsBtnm = lv_btnm_create(skillsTab, NULL);
//     // lv_btnm_set_map(skillsBtnm, skillsBtnmMap);
//     // lv_obj_set_size(skillsBtnm, 450, 50);
//     // lv_obj_set_pos(skillsBtnm, 0, 100);
//     // lv_obj_align(skillsBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

//     printf("i did all the cool and crazy stuff!");
// };

/**
 * iteration 4
*/

// namespace as {
//     static lv_res_t tabAction(lv_obj_t *tabview, uint16_t tab_id) {
//         test.currTab = tab_id;

//         printf("changed to tab %d", tab_id);

//         return LV_RES_OK;
//     }

//     static lv_res_t btnAction(lv_obj_t *btnm, const char *txt) {
//         printf("changed to auton %s", txt);
//         // for (int i = 0; i < 10; i++) {
//         //     if strcmp(txt, btnm)
//         // }
//         return LV_RES_OK;
//     }
// }

// Test::Test() { 
//     // Initialize the tabview
//     lv_obj_t* tabview = lv_tabview_create(lv_scr_act(), nullptr);

//     // Add tabs
//     lv_obj_t* tab1 = lv_tabview_add_tab(tabview, "Tab 1");
//     lv_obj_t* tab2 = lv_tabview_add_tab(tabview, "Tab 2");
//     lv_obj_t* tab3 = lv_tabview_add_tab(tabview, "Tab 3");

//     lv_tabview_set_tab_act(tab1, 0, false);
//     lv_tabview_set_tab_load_action(tabview, as::tabAction);

//     // Create button matrices in each tab
//     createButtonMatrix(tab1, farBtnmMap);
//     createButtonMatrix(tab2, nearBtnmMap);
//     createButtonMatrix(tab3, skillsBtnmMap);
// }

// void Test::createButtonMatrix(lv_obj_t* parent, const char* btnm_map[]) {
//     lv_obj_t* btnm = lv_btnm_create(parent, nullptr);
//     lv_btnm_set_map(btnm, btnm_map);
//     lv_btnm_set_toggle(btnm, true, 0);
//     lv_btnm_set_action(btnm, as::btnAction);
//     lv_obj_set_size(btnm, 450, 50);
//     lv_obj_set_pos(btnm, 0, 100);
//     lv_obj_align(btnm, NULL, LV_ALIGN_CENTER, 0, 0);
// }

// iteration 5...?

// namespace as {
//     // last element ALWAYS has to be null!
//     const char *farBtnmMap[11] = {"rush", "not rush", "", "", "", "", "", "", "", NULL};
//     const char *nearBtnmMap[11] = {"rush", "not rush", "", "", "", "", "", "", "", NULL};
//     const char *skillsBtnmMap[11] = {"max", "normal", "", "", "", "", "", "", "", NULL};

//     lv_res_t tabAction(lv_obj_t *tabview, uint16_t tab_id) {
//         // currTab = tab_id;

//         return LV_RES_OK;
//     }

//     lv_res_t btnAction(lv_obj_t *btnm, const char *txt) {
//         printf("changed to auton %s", txt);
//         // for (int i = 0; i < 10; i++) {
//         //     if strcmp(txt, btnm)
//         // }
//         return LV_RES_OK;
//     }

//     void createButtonMatrix(lv_obj_t* parent, const char* btnm_map[]) {
//         lv_obj_t* btnm = lv_btnm_create(parent, nullptr);
//         lv_btnm_set_map(btnm, btnm_map);
//         lv_btnm_set_toggle(btnm, true, 1);
//         lv_btnm_set_action(btnm, btnAction);
//         lv_obj_set_size(btnm, 450, 50);
//         lv_obj_set_pos(btnm, 0, 100);
//         lv_obj_align(btnm, NULL, LV_ALIGN_CENTER, 0, 0);
//     }

//     void init() {
//         /**
//          * TODO: change defaults?
//         */
        
//         // Initialize the tabview
//         lv_obj_t *tabview = lv_tabview_create(lv_scr_act(), nullptr);

//         // Add tabs
//         lv_obj_t *farTab = lv_tabview_add_tab(tabview, "Far Tab");
//         lv_obj_t *nearTab = lv_tabview_add_tab(tabview, "Near Tab");
//         lv_obj_t *skillsTab = lv_tabview_add_tab(tabview, "Skills Tab");

//         /**
//          * TODO: disable sliding animations when switching tabs?!?!
//          * for some reason it's giving a data abort exception
//          * when I uncomment this line
//         */
//         // lv_tabview_set_tab_act(tab1, 1, false);
//         lv_tabview_set_tab_load_action(tabview, tabAction);

//         // Create button matrices in each tab
//         createButtonMatrix(farTab, farBtnmMap);
//         createButtonMatrix(nearTab, nearBtnmMap);
//         createButtonMatrix(skillsTab, skillsBtnmMap);
//     }
// };