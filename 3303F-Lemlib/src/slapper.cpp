#include "main.h"

Slapper::Slapper(std::uint8_t rotPort, std::vector<pros::Motor> slapperMotorGroup) : rotSensor(rotPort), slapperMotors(slapperMotorGroup) {
    this->pid = new lemlib::PID(10, 0, 2);
    this->rotSensor.reset();
}

void Slapper::update() {
    if (activate) {
        this->slapperMotors.move(127);
    } else {
        this->slapperMotors.move(this->pid->update(abs(this->rotSensor.get_angle()/100.)));
    }
}

void Slapper::runSlapper() {
    activate = true;
}

void Slapper::stopSlapper() {
    activate = false;
}