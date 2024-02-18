/**
 * TODO: should this actually be `#include "hang.hpp"`? idk c++...
 * TODO: make this accept vector of ports as the parameter
*/
#include "main.h"

Hang::Hang(std::uint8_t hang_pistons_port) : hang_pistons(hang_pistons_port) {
    hang_enabled = false;

    this->update();
}

void Hang::update() {
    hang_pistons.set_value(hang_enabled);
}

void Hang::open_hang() {
    hang_enabled = true;

    this->update();
}

void Hang::close_hang() {
    hang_enabled = false;

    this->update();
}

void Hang::toggle() {
    switch (hang_enabled) {
        case true:
            this->close_hang();
        case false:
            this->open_hang();
    }
}