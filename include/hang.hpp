#pragma once

#include "main.h"

class Hang {
    public:
        pros::ADIDigitalOut hang_pistons;

        bool hang_enabled = false;

        Hang(std::uint8_t hang_pistons_port);

        void update();

        void open_hang();

        void close_hang();

        void toggle();
};