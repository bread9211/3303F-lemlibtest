#include "main.h"

ASSET(Far_1_txt);
ASSET(Far_2_txt);
ASSET(Far_3_txt);
ASSET(Far_4_txt);

ASSET(Near_1_txt);
ASSET(Near_2_txt);
ASSET(Near_3_txt);
ASSET(Near_4_txt);

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
    chassis.waitUntilDone();
    pros::delay(50);
    intake.brake();
    chassis.moveToPoint(60, 0, 1500);
    pros::delay(250);
    intake.outake();
    chassis.waitUntilDone();
    intake.intake();
    chassis.follow(Far_2_txt, 15, 5000);
    chassis.waitUntilDone();
    pros::delay(50);
    intake.brake();
    chassis.moveToPose(-35, -35, 90, 2500);
    intake.outake();
    pros::delay(100);
    chassis.waitUntilDone();
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
    chassis.waitUntilDone();
    chassis.moveToPoint(60, 0, 5000);
    chassis.waitUntilDone();
}

void near_side() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPose(0, 0, -45, 1000);
    chassis.waitUntilDone();
    intake.outake();
    pros::delay(50);
    intake.brake();
    chassis.moveToPose(0, 0, 0, 1000);
    chassis.waitUntilDone();

    chassis.setPose(-35, -58.75, 99.305);
    chassis.follow(Near_1_txt, 15, 5000);
    pros::delay(50);
    intake.intake();
    chassis.waitUntilDone();
    pros::delay(50);
    intake.brake();
    chassis.follow(Near_1_txt, 15, 5000, false);
    chassis.waitUntilDone();
    chassis.setPose(0, 0, 0);
    chassis.turnTo(0, -58, 1000);
    chassis.waitUntilDone();
    intake.outake();
    pros::delay(50);
    intake.brake();
    chassis.moveToPose(0, 0, 0, 1000);
    chassis.waitUntilDone();
    chassis.setPose(-35, -58.75, 99.286);
    chassis.follow(Near_2_txt, 15, 5000, false);
    chassis.waitUntilDone();
    chassis.follow(Near_3_txt, 15, 1500);
    pros::delay(150);
    wings.open();
    chassis.waitUntilDone();
    wings.close();
    chassis.follow(Near_3_txt, 15, 1500, false);
    chassis.waitUntilDone();
    chassis.follow(Near_4_txt, 15, 5000);
    chassis.waitUntilDone();
}