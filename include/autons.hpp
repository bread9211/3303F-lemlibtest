#pragma once

#include "main.h"
#include <string>

// #include <mutex>
// #include <condition_variable>
#include <atomic>
#include <chrono>
#include "pros/apix.h"

// basing design off of: 
// - kunwarsahini vex autonomous selector (frontend)
//   - https://github.com/kunwarsahni01/Vex-Autonomous-Selector/blob/master/selection.cpp
// - EZTemplate (backend)
//   - https://github.com/EZ-Robotics/EZ-Template/blob/v2.2.0/src/EZ-Template/auton.cpp
//   - https://github.com/EZ-Robotics/EZ-Template/blob/v2.2.0/src/EZ-Template/auton_selector.cpp

class Auton {
    public:
        const char *name = "";
        std::function<void()> func = nullptr;

        Auton(char *name, std::function<void()> callback);
};

class AutonSelector {
    private:
        static AutonSelector *instancePtr;
    
    public:
        std::vector<Auton> Autons;
        // int curr_auton_page;
        // bool up_and_running = false;
        std::atomic<bool> up_and_running = false;
        // std::mutex mtx;

        // int auton;
        int page;
        int curr_auton;
        
        std::vector<Auton> far_auton_list;
        std::vector<Auton> near_auton_list;
        std::vector<Auton> skills_auton_list;

        int far_auton_count;
        int near_auton_count;
        int skills_auton_count;

        const char *far_btnm_map[10];
        const char *near_btnm_map[10];
        const char *skills_btnm_map[10];

        lv_obj_t *tab_view;
        lv_obj_t *farBtnm;
        lv_obj_t *nearBtnm;
        lv_obj_t *skillsBtnm;

        pros::Task tabWatcher_task;

        // // constructor if ur lazy and are gonna add autons later
        // AutonSelector(int hue);
        // constructor if u nice and add autons when u initialize!!!
        AutonSelector(int hue, std::vector<Auton> farAutons, std::vector<Auton> nearAutons, std::vector<Auton> skillsAutons);

        // initialization functions!
        void init_far_side(lv_obj_t *farTab, lv_btnm_action_t far_side_btnm_action_func);
        void init_near_side(lv_obj_t *nearTab, lv_btnm_action_t near_side_btnm_action_func);
        void init_skills(lv_obj_t *skillsTab, lv_btnm_action_t skills_side_btnm_action_func);

        // vital auton selector functions
        void call_selected_auton();
        void tabWatcher();

        // functionality functions
        lv_btnm_action_t far_side_btnm_action(lv_obj_t *btnm, const char *txt);
        lv_btnm_action_t near_side_btnm_action(lv_obj_t *btnm, const char *txt);
        lv_btnm_action_t skills_side_btnm_action(lv_obj_t *btnm, const char *txt);

        static lv_btnm_action_t far_side_btnm_action_func(AutonSelector *instancePtr, lv_obj_t *btnm, const char *txt);
        static lv_btnm_action_t near_side_btnm_action_func(AutonSelector *instancePtr, lv_obj_t *btnm, const char *txt);
        static lv_btnm_action_t skills_side_btnm_action_func(AutonSelector *instancePtr, lv_obj_t *btnm, const char *txt);

        void scroll_left();

        void scroll_right();
};

void pidTest();

void far_side();