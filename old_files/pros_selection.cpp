// tab order: far side autons, near side autons, skills autons
// LLEMUSelector::LLEMUSelector(
//     std::map<std::string, void(*)()>& far_side_auton_map
//     , std::map<std::string, void(*)()>& near_side_auton_map
//     , std::map<std::string, void(*)()>& skills_auton_map
// ) : far_side_autons(far_side_auton_map)
//     , near_side_autons(near_side_auton_map)
//     , skills_autons(skills_auton_map) 
// {
//     currTab = 0;
//     currAuton = 0;

//     auto american = std::bind(&LLEMUSelector::left_tab, this);

//     pros::lcd::register_btn0_cb(american);
// };

// std::map<std::string, void(*)()>::iterator LLEMUSelector::fetch_curr_auton() {
//     std::string currAutonText = "";
//     std::map<std::string, void(*)()>::iterator it;

//     switch (currTab) {
//         // far side
//         case 0:
//             it = far_side_autons.begin();

//             break;
//         // near side
//         case 1:
//             it = near_side_autons.begin();

//             break;
//         // skills
//         case 2:
//             it = skills_autons.begin();

//             break;
//     };

//     // fetches the current auton in the relevant auton map
//     std::advance(it, currAuton);

//     return it;
// }

// void LLEMUSelector::display_auton() {
//     std::string tabName = "";

//     switch (currTab) {
//         case 0:
//             tabName = "Far Side Autons";
//             break;
//         case 1:
//             tabName = "Near Side Autons";
//             break;
//         case 2:
//             tabName = "Skills Autons";
//             break;
//     }

//     // tab heading
//     pros::lcd::set_text(0, tabName);

//     // demarcator
//     pros::lcd::set_text(1, "-----------------");

//     std::string currAutonText = "";
//     std::map<std::string, void(*)()>::iterator curr_auton = this->fetch_curr_auton();

//     currAutonText = curr_auton->first;

//     // auton marker
//     pros::lcd::set_text(3, currAutonText);
// };

// void LLEMUSelector::left_tab() {
//     if (currTab > 0) {
//         currTab -= 1;
//     }
// };

// void LLEMUSelector::right_tab() {
//     if (currTab < 2) {
//         currTab += 1;
//     }
// };

// void LLEMUSelector::call() {
//     std::map<std::string, void(*)()>::iterator curr_auton = this->fetch_curr_auton();

//     curr_auton->second()();
// }