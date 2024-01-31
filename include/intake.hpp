#pragma once

#include "main.h"

/**
 * uses pistons:
*/
// class Intake {
//     public:
//         pros::ADIDigitalOut intake_piston_in;
//         pros::ADIDigitalOut intake_piston_out;

//         bool intake_enabled;

//         Intake(std::uint8_t intake_piston_port1, std::uint8_t intake_piston_port2);

//         void update();

//         void extend_intake();

//         void retract_intake();
// };

/**
 * uses motors:
*/
class Intake {
    public:
        pros::Motor intake_motor;

        pros::motor_brake_mode_e brake_mode;

        Intake(std::int8_t intake_motor_port, pros::motor_brake_mode_e brake_mode);

        void intake();

        void outake();

        void brake();
};