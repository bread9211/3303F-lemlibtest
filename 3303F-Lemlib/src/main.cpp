#include "main.h"

#define f (float)

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

// port definitions

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor left_top_front_motor(18);
pros::Motor left_top_back_motor(20);
pros::Motor left_bottom_front_motor(-19);
pros::Motor left_bottom_back_motor(-17);

pros::Motor right_top_front_motor(-11);
pros::Motor right_top_back_motor(-13);
pros::Motor right_bottom_front_motor(10);
pros::Motor right_bottom_back_motor(12);

pros::Motor_Group left_drive({
	left_top_front_motor, left_top_back_motor, left_bottom_front_motor, left_bottom_back_motor
});

pros::Motor_Group right_drive({
	right_top_front_motor, right_top_back_motor, right_bottom_front_motor, right_bottom_back_motor
});

pros::Imu inertial_sensor(16);

lemlib::Drivetrain drivetrain {
    &left_drive, // left drivetrain motors
    &right_drive, // right drivetrain motors
    13, // track width
	lemlib::Omniwheel::NEW_325_HALF,
    3.25, // wheel diameter
    450 // wheel rpm
};

// odometry struct
lemlib::OdomSensors sensors {
    nullptr, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2
    nullptr, // horizontal tracking wheel 1
    nullptr, // we don't have a second tracking wheel, so we set it to nullptr
    &inertial_sensor // inertial sensor
};

// kp, ki, kd, windup, smallerror, smallerrortimeout, largeerror, largeerrortimeout, slew

lemlib::ControllerSettings linearController(10, 0, 30, 0, 1, 100, 3, 500, 20);

lemlib::ControllerSettings angularController(2, 0, 10, 0, 1, 100, 3, 500, 20);

lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "hi bozo!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mtr(1);
	pros::Motor right_mtr(2);

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);

		left_mtr = left;
		right_mtr = right;

		pros::delay(20);
	}
}
