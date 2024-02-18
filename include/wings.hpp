#pragma once

#include "main.h"

class Wings {
    public:
        // pros::ADIDigitalOut left_wing_piston;
        // pros::ADIDigitalOut right_wing_piston;
        
        std::vector<pros::ADIDigitalOut> wing_pistons;

        bool wings_enabled = false;

        // Wings(std::uint8_t left_wing_piston_port, std::uint8_t right_wing_piston_port);

        Wings(std::vector<std::uint8_t> wing_pistons_ports);

        /**
         * Updates wing state based on `wings_enabled` class variable! 
        */
        void update();

        /**
         * Sets `wings_enabled` to "false"; closes wings
        */
        void close();

        /**
         * Sets `wings_enabled` to "false"; opens wings
        */
        void open();

        /**
         * Toggles wing state (`wings_enabled = !wings_enabled`)
        */
        void toggle();
};