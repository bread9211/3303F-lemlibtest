#include "main.h"

ASSET(Far_1_txt);
ASSET(Far_2_txt);
ASSET(Far_3_txt);
ASSET(Far_4_txt);

void pidTest() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 10, 1000, true, 127, false);
    pros::delay(1000);
    chassis.turnTo(10, 10, 1000, true, 127, false);
    pros::delay(1000);
    chassis.moveToPose(0, 0, 0, 10000);
}

void far_side() {
    chassis.setPose(35, -60, 93.548);
    intake.intake();
    chassis.follow(Far_1_txt, 15, 5000, true, false);
    pros::delay(50);
    intake.brake();
    chassis.moveToPoint(60, 0, 1500);
    pros::delay(250);
    intake.outake();
    chassis.waitUntilDone();
    intake.intake();
    chassis.follow(Far_2_txt, 15, 5000);
    pros::delay(50);
    intake.brake();
    chassis.moveToPose(-35, -35, 90, 2500);
    intake.outake();
    pros::delay(100);
    chassis.follow(Far_3_txt, 15, 5000);
    intake.intake();
    chassis.waitUntilDone();
    pros::delay(50);
    intake.brake();
    chassis.follow(Far_4_txt, 15, 5000, false, false);
    wings.open();
    pros::delay(50);
    chassis.turnTo(25, 0, 1000, false, 127, false);
    wings.close();
    pros::delay(50);
    chassis.turnTo(60, 0, 5000);
    chassis.moveToPoint(60, 0, 5000);
}