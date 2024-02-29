/**
 * TODO: comment code!!!
*/

#include "main.h"
// #include "selection.h"

/**
 * define Auton
*/
// Auton::Auton(std::string name, std::function<void()> callback) {
//     // name = name;
//     func = callback;
// }

namespace selector {

    int auton;
    int autonCount;
    const char *btnmMap[] = {"","","","","","","","","","",""}; // up to 10 autons

    lv_obj_t *tabview;
    lv_obj_t *redBtnm;
    lv_obj_t *blueBtnm;

    lv_res_t redBtnmAction(lv_obj_t *btnm, const char *txt){
        //printf("red button: %s released\n", txt);

        for(int i = 0; i < autonCount; i++){
            if(strcmp(txt, btnmMap[i]) == 0){
                auton = i+1;
            }
        }

        return LV_RES_OK; // return OK because the button matrix is not deleted
    }

    lv_res_t blueBtnmAction(lv_obj_t *btnm, const char *txt)
    {
        //printf("blue button: %s released\n", txt);

        for(int i = 0; i < autonCount; i++){
            if(strcmp(txt, btnmMap[i]) == 0){
                auton = -(i+1);
            }
        }

        return LV_RES_OK; // return OK because the button matrix is not deleted
    }

    lv_res_t skillsBtnAction(lv_obj_t *btn){
    //printf("skills pressed");
        auton = 0;
        return LV_RES_OK;
    }

    int tabWatcher() {
        int activeTab = lv_tabview_get_tab_act(tabview);
        while(1){
            int currentTab = lv_tabview_get_tab_act(tabview);

            if(currentTab != activeTab){
                activeTab = currentTab;
                if(activeTab == 0){
                    if(auton == 0) auton = 1;
                    auton = abs(auton);
                    lv_btnm_set_toggle(redBtnm, true, abs(auton)-1);
                }else if(activeTab == 1){
                    if(auton == 0) auton = -1;
                    auton = -abs(auton);
                    lv_btnm_set_toggle(blueBtnm, true, abs(auton)-1);
                }else{
                    auton = 0;
                }
            }

            pros::delay(20);
        }
    }

    void init(int hue, int default_auton, const char **autons){

        int i = 0;
        do{
            memcpy(&btnmMap[i], &autons[i], sizeof(&autons));
            i++;
        }while(strcmp(autons[i], "") != 0);

        autonCount = i;
        auton = default_auton;

        // lvgl theme
        lv_theme_t *th = lv_theme_alien_init(hue, NULL); //Set a HUE value and keep font default RED
        lv_theme_set_current(th);

        // create a tab view object
        tabview = lv_tabview_create(lv_scr_act(), NULL);

        // add 3 tabs (the tabs are page (lv_page) and can be scrolled
        lv_obj_t *redTab = lv_tabview_add_tab(tabview, "Red");
        lv_obj_t *blueTab = lv_tabview_add_tab(tabview, "Blue");
        lv_obj_t *skillsTab = lv_tabview_add_tab(tabview, "Skills");

        //set default tab
        if(auton < 0){
            lv_tabview_set_tab_act(tabview, 1, LV_ANIM_NONE);
        }else if(auton == 0){
            lv_tabview_set_tab_act(tabview, 2, LV_ANIM_NONE);
        }

        // add content to the tabs
        // button matrix
        redBtnm = lv_btnm_create(redTab, NULL);
        lv_btnm_set_map(redBtnm, btnmMap);
        lv_btnm_set_action(redBtnm, redBtnmAction);
        lv_btnm_set_toggle(redBtnm, true, abs(auton)-1);//3
        lv_obj_set_size(redBtnm, 450, 50);
        lv_obj_set_pos(redBtnm, 0, 100);
        lv_obj_align(redBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

        // blue tab
        blueBtnm = lv_btnm_create(blueTab, NULL);
        lv_btnm_set_map(blueBtnm, btnmMap);
        lv_btnm_set_action(blueBtnm, *blueBtnmAction);
        lv_btnm_set_toggle(blueBtnm, true, abs(auton)-1);
        lv_obj_set_size(blueBtnm, 450, 50);
        lv_obj_set_pos(blueBtnm, 0, 100);
        lv_obj_align(blueBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

        // skills tab
        lv_obj_t *skillsBtn = lv_btn_create(skillsTab, NULL);
        lv_obj_t *label = lv_label_create(skillsBtn, NULL);
        lv_label_set_text(label, "Skills");
        lv_btn_set_action(skillsBtn, LV_BTN_ACTION_CLICK, *skillsBtnAction);
        // lv_btn_set_state(skillsBtn, LV_BTN_STATE_TGL_REL);
        lv_obj_set_size(skillsBtn, 450, 50);
        lv_obj_set_pos(skillsBtn, 0, 100);
        lv_obj_align(skillsBtn, NULL, LV_ALIGN_CENTER, 0, 0);

        // start tab watcher
        pros::Task tabWatcher_task(tabWatcher);
    }
} // namespace selector
















// first attempt code:

// /**
//  * define AutonSelector NAMESPACE
// */
// namespace as {
//     std::vector<Auton> autons;

//     std::atomic<bool> up_and_running;

//     int curr_page;
//     int curr_auton;

//     std::vector<Auton> far_auton_list;
//     std::vector<Auton> near_auton_list;
//     std::vector<Auton> skills_auton_list;

//     const char *far_btnm_map[10] = {"", "", "", "shut uppp", "", "", "", "", "", ""};
//     const char *near_btnm_map[10] = {"", "", "", "shut upppppp", "", "", "", "", "", ""};
//     const char *skills_btnm_map[10] = {"", "", "", "shut upppppp", "", "", "", "", "", ""};

//     int far_auton_count;
//     int near_auton_count;
//     int skills_auton_count;

//     lv_obj_t *tab_view;
//     lv_obj_t *farBtnm;
//     lv_obj_t *nearBtnm;
//     lv_obj_t *skillsBtnm;


//     lv_res_t far_btnm_action(lv_obj_t *btnm, const char *txt) {
//         for (int i = 0; i < far_auton_count; i++) {
//             if (strcmp(txt, far_btnm_map[i]) == 0) {
//                 curr_auton = i;

//                 break;
//             }
//         }

//         // nothing went kaboom! yay!
//         return LV_RES_OK;
//     }

//     lv_res_t near_btnm_action(lv_obj_t *btnm, const char *txt) {
//         for (int i = 0; i < near_auton_count; i++) {
//             if (strcmp(txt, near_btnm_map[i]) == 0) {
//                 curr_auton = i;

//                 break;
//             }
//         }

//         // nothing went kaboom! yay!
//         return LV_RES_OK;
//     }

//     lv_res_t skills_btnm_action(lv_obj_t *btnm, const char *txt) {
//         for (int i = 0; i < skills_auton_count; i++) {
//             if (strcmp(txt, skills_btnm_map[i]) == 0) {
//                 curr_auton = i;

//                 break;
//             }
//         }

//         // nothing went kaboom! yay!
//         return LV_RES_OK;
//     }


//     void tabWatcher() {
//         /**
//          * waits for auton selector to initialize
//          * 
//          * `AutonSelector::up_and_running.load` checks the value of `AutonSelector::up_and_running`
//          * 
//          * `std::memory_order_acquire` ensures that ALL subsequent reads/writes in this thread occur
//          * only after this initial value of `AutonSelector::up_and_running` has been read 
//         */
//         while(!up_and_running.load(std::memory_order_acquire)) {
//             // keeps checking if up_and_running is true yet, about every one millisecond
//             pros::Task::delay(1);
//         }

//         int activeTab = lv_tabview_get_tab_act(tab_view);

//         // this task SHOULD persist for the rest of the duration of the program's runtime
//         /**
//          * TODO: kill auton selector after autonomous period-? or will it be garbage collected automatically
//         */
//         while (true) {
//             int currentTab = lv_tabview_get_tab_act(tab_view);

//             // there was a change!
//             if (currentTab != activeTab) {
//                 switch (activeTab) {
//                     // switch to far side
//                     case 0: 
//                         // sets auton to first default far side auton
//                         curr_page = 0;
//                         curr_auton = 0;

//                         lv_btnm_set_toggle(farBtnm, true, 0);

//                         break;
//                     // switch to near side
//                     case 1:
//                         // sets auton to first default near side auton
//                         curr_page = 1;
//                         curr_auton = 0;
                        
//                         lv_btnm_set_toggle(nearBtnm, true, 0);

//                         break;
//                     // switch to skills
//                     case 2:
//                         curr_page = 2;
//                         curr_auton = 0;

//                         lv_btnm_set_toggle(skillsBtnm, true, 0);

//                         break;
//                 }
//             }
            
//             pros::delay(20);
//         }
//     }


//     void init_far_side(lv_obj_t *farTab) {
//         farBtnm = lv_btnm_create(farTab, NULL);
//         lv_btnm_set_map(farBtnm, far_btnm_map);
//         lv_btnm_set_action(farBtnm, far_btnm_action);
//         lv_btnm_set_toggle(farBtnm, true, 0);
//         lv_obj_set_size(farBtnm, 450, 50);
//         lv_obj_set_pos(farBtnm, 0, 100);
//         lv_obj_align(farBtnm, NULL, LV_ALIGN_CENTER, 0, 0);
//     }

//     void init_near_side(lv_obj_t *nearTab) {
//         nearBtnm = lv_btnm_create(nearTab, NULL);
//         lv_btnm_set_map(nearBtnm, near_btnm_map);
//         lv_btnm_set_action(nearBtnm, near_btnm_action);
//         lv_btnm_set_toggle(nearBtnm, true, 0);
//         lv_obj_set_size(nearBtnm, 450, 50);
//         lv_obj_set_pos(nearBtnm, 0, 100);
//         lv_obj_align(nearBtnm, NULL, LV_ALIGN_CENTER, 0, 0);
//     }

//     void init_skills(lv_obj_t *skillsTab) {
//         skillsBtnm = lv_btnm_create(skillsTab, NULL);
//         lv_btnm_set_map(skillsBtnm, skills_btnm_map);
//         lv_btnm_set_action(skillsBtnm, skills_btnm_action);
//         lv_btnm_set_toggle(skillsBtnm, true, 0);
//         lv_obj_set_size(skillsBtnm, 450, 50);
//         lv_obj_set_pos(skillsBtnm, 0, 100);
//         lv_obj_align(skillsBtnm, NULL, LV_ALIGN_CENTER, 0, 0);
//     }


//     void init(std::vector<Auton> farAutons, std::vector<Auton> nearAutons, std::vector<Auton> skillsAutons, int hue, int default_page, int default_auton) {
//         printf("[autons.cpp] init(): starting initialization...\n\n");

//         curr_page = default_page;
//         curr_auton = default_auton;

//         /**
//          * stores FAR autons, and creates buttons for them
//         */
//         printf("[autons.cpp] init(): iterating through FAR autons...\n");
//         far_auton_count = 0;
//         for (Auton auton : farAutons) {
//             memcpy(&far_btnm_map[far_auton_count], auton.Name.c_str(), sizeof(&farAutons));

//             // printf("[autons.cpp] init(): adding auton %s to FAR autons...\n", &auton.Name);

//             far_auton_count += 1;
//         }

//         printf("[autons.cpp] init(): in total... %d FAR autons!\n\n", far_auton_count);

//         far_auton_list.assign(farAutons.begin(), farAutons.end());


//         /**
//          * stores NEAR autons, and creates buttons for them
//         */
//         printf("[autons.cpp] init(): iterating through NEAR autons...\n");
//         int near_auton_count = 0;
//         for (Auton auton : nearAutons) {
//             memcpy(&near_btnm_map[near_auton_count], auton.Name.c_str(), sizeof(&nearAutons));

//             // printf("[autons.cpp] init(): adding auton %s to NEAR autons...\n", &auton.Name);

//             near_auton_count += 1;
//         }

//         printf("[autons.cpp] init(): in total... %d NEAR autons!\n\n", near_auton_count);

//         near_auton_list.assign(nearAutons.begin(), nearAutons.end());


//         /**
//          * stores SKILLS autons, and creates buttons for them
//         */
//         printf("[autons.cpp] init(): iterating through SKILLS autons...\n");
//         int skills_auton_count = 0;
//         for (Auton auton : skillsAutons) {
//             memcpy(&skills_btnm_map[skills_auton_count], auton.Name.c_str(), sizeof(&skillsAutons));

//             // printf("[autons.cpp] init(): adding auton %s to SKILLS autons...\n", &auton.Name);

//             skills_auton_count += 1;
//         }

//         printf("[autons.cpp] init(): in total... %d SKILLS autons!\n\n", skills_auton_count);

//         skills_auton_list.assign(skillsAutons.begin(), skillsAutons.end());

//         /**
//          * LVGL goofery
//         */
//         // sets theme
//         lv_theme_t *th = lv_theme_alien_init(hue, NULL); 
//         lv_theme_set_current(th);

//         /**
//          * LVGL: tab - create tab view
//         */
//         // creates tab view object (to manage tabs for scrolling through auton groups)
//         tab_view = lv_tabview_create(lv_scr_act(), NULL);

//         // creates three tabs to be present in the tab view (each tab is a page, and can be scrolled through!)
//         lv_obj_t *farTab = lv_tabview_add_tab(tab_view, "Far");
//         lv_obj_t *nearTab = lv_tabview_add_tab(tab_view, "Near");
//         lv_obj_t *skillsTab = lv_tabview_add_tab(tab_view, "Skills");

//         // sets active tab to 1 ("Far" tab)
//         lv_tabview_set_tab_act(tab_view, 1, true);

//         /**
//          * LVGL: tab - button matrix creation
//         */

//         // creates button matrix for far side autons
//         init_far_side(farTab);
//         init_near_side(nearTab);
//         init_skills(skillsTab);

//         // starts tab watcher task
//         pros::Task tabWatcher_task(tabWatcher);

//         /**
//          * lets AutonSelector::tabWatcher() know that AutonSelector has finished initializing
//          * 
//          * `std::memory_order_release` ensures that all write functions to `AutonSelector::up_and_running` finish
//          * before the change is visible to other threads
//         */
//         up_and_running.store(true, std::memory_order_release);
//     }

//     void call_selected_auton() {
//         switch (curr_page) {
//             // far autons
//             case 0:
//                 far_auton_list[curr_auton].func();
//                 break;
//             // near autons
//             case 1:
//                 near_auton_list[curr_auton].func();
//                 break;
//             // skills autons
//             case 2:
//                 skills_auton_list[curr_auton].func();
//                 break;
//         }
//     }
// }