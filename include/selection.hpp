/**
 * TODO: should i be using `#pragma once` everywhere?
*/
#pragma once

#include "main.h"

/**
 * iteration 1
*/
// /**
//  * TODO: shld this be included manually, or is it okay to omit? might as well just move 
// */
// #include <map>
// #include <string>
// #include <stdexcept>

// using FunctionType = std::function<void()>;

// /**
//  * TODO: consider passing in a vector of `Auton` classes, INSTEAD of using a map of str -> func?
// */
// class Selector {
//     public:
//         int auton;

//         /**
//          * TODO: make ID system
//         */
//         std::map<std::string, FunctionType> far_autons;
//         std::map<std::string, FunctionType> near_autons;
//         std::map<std::string, FunctionType> skills_autons;

//         Selector(
//             std::map<std::string, FunctionType> far_auton_funcs,
//             std::map<std::string, FunctionType> near_auton_funcs,
//             std::map<std::string, FunctionType> skills_auton_funcs
//         );

//         void display();

//     private:
//         int autonCount;
 
//         // can hold up to 10 autons!
//         const char *farBtnmMap[11] = {"", "", "", "", "", "", "", "", "", "", NULL};
//         const char *nearBtnmMap[11] = {"", "", "", "", "", "", "", "", "", "", NULL};
//         const char *skillsBtnmMap[11] = {"", "", "", "", "", "", "", "", "", "", NULL};
// };

/**
 * iteration 2
*/
// class Test {
//     public:
//         // // last element ALWAYS has to be null!
//         const char *farBtnmMap[10] = {"one", "two", "three", "", "", "", "", "", "", NULL};
//         const char *nearBtnmMap[10] = {"das", "crazy", "bro", "", "", "", "", "", "", NULL};
//         const char *skillsBtnmMap[10] = {"wut", "the", "???", "", "", "", "", "", "", NULL};

//         int currTab;
//         int currAuton;

//         // lv_obj_t *tabview;

//         // lv_obj_t *farBtnm;
//         // lv_obj_t *nearBtnm;
//         // lv_obj_t *skillsBtnm;

//         Test();

//         // lv_res_t farBtnmAction(const char *txt);
//         // lv_res_t nearBtnmAction(const char *txt);
//         // lv_res_t skillsBtnmAction(const char *txt);
//     private:
//         // lv_res_t tabAction(lv_obj_t *tabview, uint16_t tab_id);

//         // lv_res_t btnAction(lv_obj_t *btnm, const char *txt);

//         void createButtonMatrix(lv_obj_t* parent, const char* btnm_map[]);
// };

// iteration 5
// namespace as {
//     extern int currTab;
//     extern int currAuton;

//     void createButtonMatrix(lv_obj_t* parent, const char* btnm_map[]);

//     void init();
// };

// iteration 6

// class Selector {
//     public:
//         int currTab = 0;
//         int currAuton = 0;

//         lv_res_t tabAction(lv_obj_t *tabview, uint16_t tab_id);

//         lv_res_t btnAction(lv_obj_t *btnm, const char *txt);

//         const char *farBtnmMap[11] = {"rush", "not rush", "", "", "", "", "", "", "", NULL};
//         const char *nearBtnmMap[11] = {"rush", "not rush", "", "", "", "", "", "", "", NULL};
//         const char *skillsBtnmMap[11] = {"max", "normal", "", "", "", "", "", "", "", NULL};

//         Selector();

//         void createButtonMatrix(lv_obj_t* parent, const char* btnm_map[]);
// };