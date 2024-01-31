#include "main.h"
#include <string>

/**
 * uses pistons:
*/
// Intake::Intake(std::uint8_t intake_piston_port1, std::uint8_t intake_piston_port2) : intake_piston_in(intake_piston_port1), intake_piston_out(intake_piston_port2) {
//     intake_enabled = false;

//     intake_piston_in.set_value(intake_enabled);
//     intake_piston_out.set_value(!intake_enabled);
// }

// void Intake::update() {
//     intake_piston_in.set_value(intake_enabled);
//     intake_piston_out.set_value(!intake_enabled);
// }

// void Intake::extend_intake() {
//     intake_enabled = true;

//     this->update();
// }

// void Intake::retract_intake() {
//     intake_enabled = false;

//     this->update();
// }

/**
 * uses motors:
*/
Intake::Intake(std::int8_t intake_motor_port, pros::motor_brake_mode_e brake_mode) : intake_motor(intake_motor_port) {
    brake_mode = brake_mode;
}

void Intake::intake() {
    intake_motor.move(-127);
}

void Intake::outake() {
    intake_motor.move(127);
}

void Intake::brake() {
    intake_motor.brake();
}