#include "main.h"

class Slapper {
    public:
        pros::Rotation rotSensor;
        pros::MotorGroup slapperMotors;

        lemlib::PID pid;

        bool activate;

        Slapper(std::uint8_t rotPort, std::vector<pros::Motor> slapperMotorGroup, float K_p, float K_i, float K_d);

        void update();

        void runSlapper();

        void stopSlapper();
};