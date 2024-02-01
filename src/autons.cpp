/**
 * TODO: convert this to namespace... all because of some annoying issue
 * TODO: implement default autons for both far side and near side!
 * TODO: condense three init funcs into one bc same templating
*/

#include "main.h"

ASSET(Far_1_txt);
ASSET(Far_2_txt);
ASSET(Far_3_txt);
ASSET(Far_4_txt);



/**
 * define Auton
*/
Auton::Auton(char *name, std::function<void()> callback) {
    name = name;
    func = callback;
}

/**
 * define AutonSelector
*/
// AutonSelector::AutonSelector(int hue) : tabWatch{
//     // curr_auton_page = 0;
//     int auton = 0;

//     Autons = {};
// }

AutonSelector::AutonSelector(int hue, std::vector<Auton> farAutons, std::vector<Auton> nearAutons, std::vector<Auton> skillsAutons) : tabWatcher_task(tabWatcher) {
    // curr_auton_page = 0;

    // int auton = 1;
    int page = 0;
    int curr_auton = 0;
    
    /**
     * stores FAR autons, and creates buttons for them
    */
    int far_auton_count = 0;
    for (Auton auton : farAutons) {
        memcpy(&far_btnm_map[far_auton_count], &auton.name, sizeof(&farAutons));

        far_auton_count += 1;
    }

    far_auton_list.assign(farAutons.begin(), farAutons.end());


    /**
     * stores NEAR autons, and creates buttons for them
    */
    int near_auton_count = 0;
    for (Auton auton : nearAutons) {
        memcpy(&near_btnm_map[near_auton_count], &auton.name, sizeof(&nearAutons));

        near_auton_count += 1;
    }

    near_auton_list.assign(nearAutons.begin(), nearAutons.end());


    /**
     * stores SKILLS autons, and creates buttons for them
    */
    int skills_auton_count = 0;
    for (Auton auton : skillsAutons) {
        memcpy(&skills_btnm_map[skills_auton_count], &auton.name, sizeof(&skillsAutons));

        skills_auton_count += 1;
    }

    skills_auton_list.assign(skillsAutons.begin(), skillsAutons.end());


    /**
     * LVGL goofery
    */
    // sets theme
    lv_theme_t *th = lv_theme_alien_init(hue, NULL); 
    lv_theme_set_current(th);

    /**
     * LVGL: tab - create tab view
    */
    // creates tab view object (to manage tabs for scrolling through auton groups)
    tab_view = lv_tabview_create(lv_scr_act(), NULL);

    // creates three tabs to be present in the tab view (each tab is a page, and can be scrolled through!)
    lv_obj_t *farTab = lv_tabview_add_tab(tab_view, "Far");
    lv_obj_t *nearTab = lv_tabview_add_tab(tab_view, "Near");
    lv_obj_t *skillsTab = lv_tabview_add_tab(tab_view, "Skills");

    // sets active tab to 1 ("Far" tab)
    lv_tabview_set_tab_act(tab_view, 1, true);

    /**
     * LVGL: tab - button matrix creation
    */
    // // binds class member functions to "regular" functions for use by the stupid, stupid lv_btn_set_action() function
    // std::function<lv_btnm_action_t()> farSideBtnmActionFunc = std::bind(&AutonSelector::farSideBtnmAction, this);
    
    // stores a callback to class member functions within a "regular" variable of that function's type, because the stuipd, stupid lv_btn_set_action()
    // function does not accept class member functions
    // lv_btnm_action_t far_side_btnm_action_func = [this](lv_obj_t *btnm, const char *txt) { return this->far_side_btnm_action(btnm, txt); };
    // lv_btnm_action_t near_side_btnm_action_func = [this](lv_obj_t *btnm, const char *txt) { return this->near_side_btnm_action(btnm, txt); };
    // lv_btnm_action_t skills_side_btnm_action_func = [this](lv_obj_t *btnm, const char *txt) { return this->skills_side_btnm_action(btnm, txt); };

    // creates button matrix for far side autons
	this->init_far_side(farTab, far_side_btnm_action_func);
    this->init_near_side(nearTab, near_side_btnm_action_func);
    this->init_skills(skillsTab, skills_side_btnm_action_func);

    instancePtr = this;

    /**
     * lets AutonSelector::tabWatcher() know that AutonSelector has finished initializing
     * 
     * `std::memory_order_release` ensures that all write functions to `AutonSelector::up_and_running` finish
     * before the change is visible to other threads
    */
    up_and_running.store(true, std::memory_order_release);
}

void AutonSelector::init_far_side(lv_obj_t *farTab, lv_btnm_action_t far_side_btnm_action_func) {
    farBtnm = lv_btnm_create(farTab, NULL);
	lv_btnm_set_map(farBtnm, far_btnm_map);
	lv_btnm_set_action(farBtnm, far_side_btnm_action_func);
	lv_btnm_set_toggle(farBtnm, true, 0);
	lv_obj_set_size(farBtnm, 450, 50);
	lv_obj_set_pos(farBtnm, 0, 100);
	lv_obj_align(farBtnm, NULL, LV_ALIGN_CENTER, 0, 0);
}

void AutonSelector::init_near_side(lv_obj_t *nearTab, lv_btnm_action_t near_side_btnm_action_func) {
	nearBtnm = lv_btnm_create(nearTab, NULL);
	lv_btnm_set_map(nearBtnm, near_btnm_map);
	lv_btnm_set_action(nearBtnm, near_side_btnm_action_func);
	lv_btnm_set_toggle(nearBtnm, true, 0);
	lv_obj_set_size(nearBtnm, 450, 50);
	lv_obj_set_pos(nearBtnm, 0, 100);
	lv_obj_align(nearBtnm, NULL, LV_ALIGN_CENTER, 0, 0);
}

void AutonSelector::init_skills(lv_obj_t *skillsTab, lv_btnm_action_t skills_side_btnm_action_func) {
    skillsBtnm = lv_btnm_create(skillsTab, NULL);
	lv_btnm_set_map(skillsBtnm, skills_btnm_map);
	lv_btnm_set_action(skillsBtnm, skills_side_btnm_action_func);
	lv_btnm_set_toggle(skillsBtnm, true, 0);
	lv_obj_set_size(skillsBtnm, 450, 50);
	lv_obj_set_pos(skillsBtnm, 0, 100);
	lv_obj_align(skillsBtnm, NULL, LV_ALIGN_CENTER, 0, 0);
    
    // // skills tab
	// lv_obj_t *skillsBtn = lv_btn_create(skillsTab, NULL);
	// lv_obj_t *label = lv_label_create(skillsBtn, NULL);
	// lv_label_set_text(label, "Skills");
	// lv_btn_set_action(skillsBtn, LV_BTN_ACTION_CLICK, *skillsBtnAction);
	// // lv_btn_set_state(skillsBtn, LV_BTN_STATE_TGL_REL);
	// lv_obj_set_size(skillsBtn, 450, 50);
	// lv_obj_set_pos(skillsBtn, 0, 100);
	// lv_obj_align(skillsBtn, NULL, LV_ALIGN_CENTER, 0, 0);
}

void AutonSelector::call_selected_auton() {
    switch (page) {
        // far autons
        case 0:
            far_auton_list[curr_auton].func();
        // near autons
        case 1:
            near_auton_list[curr_auton].func();
        // skills autons
        case 2:
            skills_auton_list[curr_auton].func();
    }

    // Autons[auton].func();
}

void AutonSelector::tabWatcher() {
    /**
     * waits for auton selector to initialize
     * 
     * `AutonSelector::up_and_running.load` checks the value of `AutonSelector::up_and_running`
     * 
     * `std::memory_order_acquire` ensures that ALL subsequent reads/writes in this thread occur
     * only after this initial value of `AutonSelector::up_and_running` has been read 
    */
    while(!up_and_running.load(std::memory_order_acquire)) {
        // keeps checking if up_and_running is true yet, about every one millisecond
        pros::Task::delay(1);
    }

    int activeTab = lv_tabview_get_tab_act(tab_view);

    // this task SHOULD persist for the rest of the duration of the program's runtime
    /**
     * TODO: kill auton selector after autonomous period-? or will it be garbage collected automatically
    */
    while (true) {
        int currentTab = lv_tabview_get_tab_act(tab_view);

        // there was a change!
        if (currentTab != activeTab) {
            switch (activeTab) {
                // switch to far side
                case 0: 
                    // sets auton to first default far side auton
                    page = 0;
                    curr_auton = 0;

                    lv_btnm_set_toggle(farBtnm, true, 0);

                    break;
                // switch to near side
                case 1:
                    // sets auton to first default near side auton
                    page = 1;
                    curr_auton = 0;
                    
                    lv_btnm_set_toggle(nearBtnm, true, 0);

                    break;
                // switch to skills
                case 2:
                    page = 2;
                    curr_auton = 0;

                    lv_btnm_set_toggle(skillsBtnm, true, 0);

                    break;
            }
        }
        
        pros::delay(20);
    }
}

lv_btnm_action_t AutonSelector::far_side_btnm_action(lv_obj_t *btnm, const char *txt) {
    for (int i = 0; i < far_auton_count; i++) {
        if (strcmp(txt, far_btnm_map[i]) == 0) {
            curr_auton = i;
        }
    }

    // return LV_RES_OK;
}

lv_btnm_action_t AutonSelector::far_side_btnm_action_func(AutonSelector *instancePtr, lv_obj_t *btnm, const char *txt) {
    if (instancePtr != nullptr) {
        return instancePtr->far_side_btnm_action(btnm, txt);
    }
}

lv_btnm_action_t AutonSelector::near_side_btnm_action(lv_obj_t *btnm, const char *txt) {
    for (int i = 0; i < near_auton_count; i++) {
        if (strcmp(txt, near_btnm_map[i]) == 0) {
            curr_auton = i;
        }
    }

    // return LV_RES_OK;
}

lv_btnm_action_t AutonSelector::near_side_btnm_action_func(AutonSelector *instancePtr, lv_obj_t *btnm, const char *txt) {
    if (instancePtr != nullptr) {
        return instancePtr->near_side_btnm_action(btnm, txt);
    }
}

lv_btnm_action_t AutonSelector::skills_side_btnm_action(lv_obj_t *btnm, const char *txt) {
    for (int i = 0; i < skills_auton_count; i++) {
        if (strcmp(txt, skills_btnm_map[i]) == 0) {
            curr_auton = i;
        }
    }

    // return LV_RES_OK;
}

lv_btnm_action_t AutonSelector::skills_side_btnm_action_func(AutonSelector *instancePtr, lv_obj_t *btnm, const char *txt) {
    if (instancePtr != nullptr) {
        return instancePtr->skills_side_btnm_action(btnm, txt);
    }
}

// ...
ASSET(Near_1_txt);
ASSET(Near_2_txt);
ASSET(Near_3_txt);
ASSET(Near_4_txt);

void pidTest() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 10, 1000, true, 127, false);
    pros::delay(1000);
    chassis.turnTo(10, 10, 1000, true, 127, false);
    pros::delay(1000);
    chassis.moveToPose(0, 0, 0, 10000);
}

void far_side() {
    chassis.setPose(35, -60, 93.548);
    intake.intake();
    chassis.follow(Far_1_txt, 15, 5000, true, false);
    chassis.waitUntilDone();
    pros::delay(50);
    intake.brake();
    chassis.moveToPoint(60, 0, 1500);
    pros::delay(250);
    intake.outake();
    chassis.waitUntilDone();
    intake.intake();
    chassis.follow(Far_2_txt, 15, 5000);
    chassis.waitUntilDone();
    pros::delay(50);
    intake.brake();
    chassis.moveToPose(-35, -35, 90, 2500);
    intake.outake();
    pros::delay(100);
    chassis.waitUntilDone();
    chassis.follow(Far_3_txt, 15, 5000);
    intake.intake();
    chassis.waitUntilDone();
    pros::delay(50);
    intake.brake();
    chassis.follow(Far_4_txt, 15, 5000, false, false);
    wings.open();
    pros::delay(50);
    chassis.turnTo(25, 0, 1000, false, 127, false);
    wings.close();
    pros::delay(50);
    chassis.turnTo(60, 0, 5000);
    chassis.waitUntilDone();
    chassis.moveToPoint(60, 0, 5000);
    chassis.waitUntilDone();
}

void near_side() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPose(0, 0, -45, 1000);
    chassis.waitUntilDone();
    intake.outake();
    pros::delay(50);
    intake.brake();
    chassis.moveToPose(0, 0, 0, 1000);
    chassis.waitUntilDone();

    chassis.setPose(-35, -58.75, 99.305);
    chassis.follow(Near_1_txt, 15, 5000);
    pros::delay(50);
    intake.intake();
    chassis.waitUntilDone();
    pros::delay(50);
    intake.brake();
    chassis.follow(Near_1_txt, 15, 5000, false);
    chassis.waitUntilDone();
    chassis.setPose(0, 0, 0);
    chassis.turnTo(0, -58, 1000);
    chassis.waitUntilDone();
    intake.outake();
    pros::delay(50);
    intake.brake();
    chassis.moveToPose(0, 0, 0, 1000);
    chassis.waitUntilDone();
    chassis.setPose(-35, -58.75, 99.286);
    chassis.follow(Near_2_txt, 15, 5000, false);
    chassis.waitUntilDone();
    chassis.follow(Near_3_txt, 15, 1500);
    pros::delay(150);
    wings.open();
    chassis.waitUntilDone();
    wings.close();
    chassis.follow(Near_3_txt, 15, 1500, false);
    chassis.waitUntilDone();
    chassis.follow(Near_4_txt, 15, 5000);
    chassis.waitUntilDone();
}