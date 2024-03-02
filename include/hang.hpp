#pragma once

#include "main.h"

class Hang {
    public:
        pros::Motor hang_motor;

        Hang(std::int8_t hang_motor_port);

        void open_hang();

        void close_hang();

        void stop_hang();
};