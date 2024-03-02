/**
 * TODO: add back giant "info" comment (put it in main.h) abt all details for bot (controls, ports, etc!)
 * 
 * TODO: should i be using #pragma once everywhere?
 * 
 * TODO: set up README.md for this "repo"!
*/
#include "main.h"

// extern int currTab;
// extern int currAuton;

const int DRIVE_SPEED = 127;

// port definitions

pros::Controller controller(pros::E_CONTROLLER_MASTER);

/**
 * TODO: see if this nomenclature is correct
*/
// // pros::Motor left_top_front_motor(-18);
// pros::Motor left_top_back_motor(-18);
// // pros::Motor left_top_back_motor(-10);
// pros::Motor left_top_front_motor(-10);
// pros::Motor left_bottom_front_motor(-9);
// pros::Motor left_bottom_back_motor(-19);

pros::Motor left_front(-19);
pros::Motor left_middle(-18);
pros::Motor left_back(-20);

// // pros::Motor right_top_front_motor(14);
// pros::Motor right_top_back_motor(14);
// // pros::Motor right_top_back_motor(12);
// pros::Motor right_top_front_motor(12);
// pros::Motor right_bottom_front_motor(13);
// pros::Motor right_bottom_back_motor(11);

pros::Motor right_front(11);
pros::Motor right_middle(12);
pros::Motor right_back(13);

pros::Motor_Group left_drive({
	left_front, left_middle, left_back
});

pros::Motor_Group right_drive({
	right_front, right_middle, right_back
});

pros::Imu inertial_sensor(1);

lemlib::Drivetrain drivetrain {
    &left_drive, // left drivetrain motors
    &right_drive, // right drivetrain motors
    13.5, // track width
    3.25, // wheel diameter
    450, // wheel rpm
	lemlib::Omniwheel::NEW_325_HALF // chase power
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

// 20 kP, 5 kD -> NOT FULLY TUNED YET (i.e. gotten to step 5 where oscillation can no longer be stopped) 

// 10, <5 -> NOT overshooting but oscillating
// 9, no D -> undershooting

// 10, 5 -> still overshooting

lemlib::ControllerSettings linearController(
	9 // kP
	, 0 // kI
	, 7 // kD
	, 0 // antiWindup
	, 1
	, 100
	, 3
	, 500
	, 0
);

// 2, 8
// 3, 16 -> NOT FULLY TUNED YET (i.e. gotten to step 5 where oscillation can no longer be stopped)

lemlib::ControllerSettings angularController(
	3 // kP
	, 0 // kI
	, 16 // kD
	, 0 // antiWindup
	, 1
	, 100
	, 3
	, 500
	, 0
);

lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);

// Hang hang = Hang('H');
Hang hang = Hang(10);

/**
 * TODO: set intake ports
 * INTAKE: uses motors
*/
Intake intake = Intake(
	-17, pros::E_MOTOR_BRAKE_HOLD
);

// Wings vert_wings = Wings(
// 	'A', 'B'
// );
Wings vert_wings = Wings({
	'B'
});

/**
 * TODO: set ports!
*/
Wings horiz_wings = Wings({
	'F'
});

// Selector s = Selector();

// Selector selector = Selector();

// Slapper slapper = Slapper(
// 	0, 
// 	{pros::Motor(0)}, 
// 	10, 
// 	0, 
// 	2
// );

// AutonSelector as = AutonSelector(360, 
// 	// far autons
// 	{
// 		Auton("far 1", []() { printf("far 1"); }),
// 		Auton("far 2", []() { printf("far 2"); }),
// 		Auton("far 3", []() { printf("far 3"); })
// 	},
// 	// near autons
// 	{
// 		Auton("near 1", []() { printf("near 1"); }),
// 		Auton("near 2", []() { printf("near 2"); }),
// 		Auton("near 3", []() { printf("near 3"); })
// 	},
// 	// skills autons
// 	{
// 		Auton("skills 1", []() { printf("skills 1"); }),
// 		Auton("skills 2", []() { printf("skills 2"); }),
// 		Auton("skills 3", []() { printf("skills 3"); })
// 	}
// );

/**
 * TESTING: (1)
*/
void screenTaskFunc(void* chassis) {
	lemlib::Chassis *myChassis = (lemlib::Chassis *)chassis;

	while (true) {
		// print robot location to the brain screen

		pros::lcd::print(0, "X: %f", myChassis->getPose().x); // x
		pros::lcd::print(1, "Y: %f", myChassis->getPose().y); // y
		pros::lcd::print(2, "Theta: %f", myChassis->getPose().theta); // heading
		// log position telemetry
		lemlib::telemetrySink()->info("Chassis pose: {}", myChassis->getPose());
		
		// delay to save resources
		pros::delay(50);
	}
}

// Test test = Test();

/**
 * TESTING: (1)
*/
// pros::Task screenTask(screenTaskFunc, &chassis);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	printf("[main.py] initialize(): initializing robot...\n");

	// pros::lcd::initialize();

	// controller.set_text(0, 0, "HELP");

	chassis.calibrate();
	// chassis.setPose(0, 0, 0);

	// pros::Task screenTask(screenTaskFunc, &chassis);

	/**
	 * TESTING: (1)
	*/
	// pros::Task screenTask([&]() {
    //     while (true) {
    //         // print robot location to the brain screen

    //         pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
    //         pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
    //         pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
    //         // log position telemetry
    //         lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
    //         // delay to save resources
    //         pros::delay(50);
    //     }
    // });

	// Auton far_auton_1("far 1", []() { printf("far 1"); });
	// Auton far_auton_2("far 1", []() { printf("far 2"); });
	// Auton far_auton_3("far 1", []() { printf("far 3"); });

	// Auton near_auton_1("far 1", []() { printf("near 1"); });
	// Auton near_auton_2("far 1", []() { printf("near 2"); });
	// Auton near_auton_3("far 1", []() { printf("near 3"); });

	// Auton skills_auton_1("far 1", []() { printf("skills 1"); });
	// Auton skills_auton_2("far 1", []() { printf("skills 2"); });
	// Auton skills_auton_3("far 1", []() { printf("skills 3"); });

	// printf("[main.py] initialize(): calling as::init()\n\n");
	// // initializes auton selector
	// as::init(
	// 	// far autons
	// 	{
	// 		far_auton_1,
	// 		far_auton_2,
	// 		far_auton_3
	// 	},
	// 	// near autons
	// 	{
	// 		near_auton_1,
	// 		near_auton_2,
	// 		near_auton_3
	// 	},
	// 	// skills autons
	// 	{
	// 		skills_auton_1,
	// 		skills_auton_2,
	// 		skills_auton_3
	// 	},
	// 	360,
	// 	0,
	// 	0
	// );

	printf("[main.py] initialize(): finished initializing!\n\n");
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
	left_drive.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
	right_drive.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);

	// screenTask.suspend();

	// selector::init();
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
	/**
	 * TESTING: (1)
	 * 
	 * NOTE: make sure this doesn't break anything!
	*/

	printf("[main.py] autonomous(): starting autons!\n");

	near_side_rush();

	// pros::delay(5000);

	// switch (selector::auton) {
	// 	// far side
	// 	case RED_AUTON_RUSH:
	// 		printf("running far side rush...");
	// 		// far_side_rush();
	// 		break;
	// 	case BLUE_AUTON_RUSH:
	// 		printf("running near side rush...");
	// 		// near_side_rush();
	// 		break;
	// 	case SKILLS:
	// 		printf("running skills...");
	// 		// prog_skills_max();
	// 		break;

	printf("[main.py] autonomous(): auton fully finished! (unless auton period ended bfore then ;-;)\n\n");
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
	/**
	 * TESTING: (1)
	 * 
	 * NOTE: make sure this doesn't break anything!
	*/
	// screenTask.resume();

	left_drive.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
	right_drive.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);

	while (true) {
		left_drive.move((controller.get_analog(ANALOG_LEFT_Y) / 127.0) * DRIVE_SPEED);
		right_drive.move((controller.get_analog(ANALOG_RIGHT_Y) / 127.0) * DRIVE_SPEED);
		// chassis.tank((controller.get_analog(ANALOG_LEFT_Y)/127)*DRIVE_SPEED, (controller.get_analog(ANALOG_RIGHT_Y)/127)*DRIVE_SPEED, 1);

		/**
		 * using motors:
		*/
		bool L1_new_press = controller.get_digital_new_press(DIGITAL_L1);
		bool L2_new_press = controller.get_digital_new_press(DIGITAL_L2);
		bool R1_pressed = controller.get_digital(DIGITAL_R1);
		bool R2_pressed = controller.get_digital(DIGITAL_R2);

		bool X_pressed = controller.get_digital(DIGITAL_X);
		bool B_pressed = controller.get_digital(DIGITAL_B);
		
		/**
		 * HANG:
		*/
		if (X_pressed) {
			// toggles hang (if hang open, it will close. if hang close, it will open)
			hang.open_hang();
		} else if (B_pressed) {
			hang.close_hang();
		} else {
			hang.stop_hang();
		} 

		/**
		 * INTAKE: using motors
		*/
		// if the intake and outtake buttons are either BOTH pressed or BOTH depressed...
		if (R1_pressed == R2_pressed) {
			// don't do anything!
			intake.brake();
		}
		// intake
		else if (R1_pressed) {
			intake.intake();
		}
		// outtake 
		else if (R2_pressed) {
			intake.outake();
		}

		/**
		 * WINGS: VERTICAL
		*/
		// if (L1_pressed) {
		// 	// is it bad to repeatedly .set_value() to 1 with .open() commands like this?
		// 	vert_wings.open();
		// } else {
		// 	vert_wings.close();
		// }
		if (L2_new_press) {
			vert_wings.toggle();
		}

		/**
		 * WINGS: HORIZONTAL
		*/
		// if (L2_pressed) {
		// 	horiz_wings.open();
		// } else {
		// 	horiz_wings.close();
		// }
		if (L1_new_press) {
			horiz_wings.toggle();
		}

		pros::delay(10);
	}
}
