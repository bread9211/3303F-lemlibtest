#pragma once

#include "main.h"

class Slapper {
    public:
        pros::Rotation rotSensor;
        pros::MotorGroup slapperMotors;

        lemlib::PID pid;

        bool activate;

        /**
         * initializes the slapper subsystem
         * 
         * the rotation sensor(`Slapper::rotSensor`) is RESET
        */
        Slapper(std::uint8_t rotPort, std::vector<pros::Motor> slapperMotorGroup, float K_p, float K_i, float K_d);

        /**
         * updates the state of the slapper based on `Slapper::activate`
         * (see `Slapper::runSlapper` and `Slapper::stopSlapper`)
        */
        void update();

        /**
         * activates the slapper (starts it running; `Slapper::activate` = true)
        */
        void runSlapper();

        /**
         * stops the slapper (returns the motor to "equilibrium" position; `Slapper::activate` = false)
        */
        void stopSlapper();
};