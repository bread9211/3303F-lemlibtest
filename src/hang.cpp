/**
 * TODO: should this actually be `#include "hang.hpp"`? idk c++...
 * TODO: make this accept vector of ports as the parameter
*/
#include "main.h"

Hang::Hang(std::int8_t hang_motor_port) : hang_motor(hang_motor_port) {};

void Hang::open_hang() {
    hang_motor.move(127);
};

void Hang::close_hang() {
    hang_motor.move(-127);
}

void Hang::stop_hang() {
    hang_motor.brake();
};