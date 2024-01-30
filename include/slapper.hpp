#include "main.h"

class Slapper {
    public:
        pros::Rotation rotSensor;
        pros::MotorGroup slapperMotors;

        bool activate;

        lemlib::PID* pid;

        Slapper(std::uint8_t rotPort, std::vector<pros::Motor> slapperMotorGroup);

        void update();

        void runSlapper();

        void stopSlapper();
};