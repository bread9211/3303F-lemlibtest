/**
 * TODO: convert this to namespace... all because of some annoying issue
 * - CONVERT BACK TO CLASS, ALL BECAUSE OF UGHGHGHGHAOWEJFOIWEJFIOWFJ
 * TODO: implement default autons for both far side and near side!
 * TODO: condense three init funcs into one bc same templating
 * TODO: colorized terminal output!!!
 * TODO: make auton selector a separate file
*/

#include "main.h"

// old far autons
ASSET(Far_1_txt);
ASSET(Far_2_txt);
ASSET(Far_3_txt);
ASSET(Far_4_txt);

// old near autons
ASSET(Near_1_txt);
ASSET(Near_2_txt);
ASSET(Near_3_txt);
ASSET(Near_4_txt);

// new near autons
/**
 * NOTE: this file is configured so the robot starts the path at the CENTER of the tile. in practice,
 * the robot should ACTUALLY start at the FRONT of the tile
*/
ASSET(Near_Mid_1_Verified_txt);
ASSET(Near_Mid_2_Cooking_txt);

// test autons
ASSET(Test_1_txt);

void pidTest() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 10, 1000, true, 127, false);
    pros::delay(1000);
    chassis.turnTo(10, 10, 1000, true, 127, false);
    pros::delay(1000);
    chassis.moveToPose(0, 0, 0, 10000);
}

void autonTest() {
    chassis.setPose(-12, -36, 0);
    chassis.follow(Test_1_txt, 15, 5000, true, false);
    chassis.waitUntilDone();
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
    vert_wings.open();
    pros::delay(50);
    chassis.turnTo(25, 0, 1000, false, 127, false);
    vert_wings.close();
    pros::delay(50);
    chassis.turnTo(60, 0, 5000);
    chassis.waitUntilDone();
    chassis.moveToPoint(60, 0, 5000);
    chassis.waitUntilDone();
}

void near_side_full() {
    chassis.setPose(
        -36 // x
        , -60 // y
        , 0 // heading (degrees by default)
    );
    
    printf("[near_side_full]: pretend wings open...\n");
    horiz_wings.open();
    // delay for it to like... fully open
    pros::delay(50);
    printf("[near_side_full]: pretend wings close...\n");
    horiz_wings.close();
    // delay for it to like... fully close
    pros::delay(50);

    // starts intake running
    intake.intake();
    // goes to center triball; this x
    chassis.follow(Near_Mid_1_Verified_txt, 15, 5000, true, false);
    // waits for intake to do its thing
    pros::delay(500);
    // keeps intake running bc otherwise when u drive back triball does the funny
    // intake.brake();

    printf("[near_side_full]: SUPPOSED to go backward...\n");
    // follows the same path but backwards
    chassis.follow(Near_Mid_2_Cooking_txt, 15, 5000, false, false);
}

// void near_side() {
//     // chassis.setPose(0, 0, 0);
//     // chassis.moveToPose(0, 0, -60, 1000);
//     // chassis.waitUntilDone();
//     // intake.outake();
//     // pros::delay(1000);
//     // intake.brake();
//     // chassis.moveToPose(0, 0, 0, 1000);
//     // chassis.waitUntilDone();

//     chassis.setPose(-35, -60, 0);

//     vert_wings.open();
//     pros::delay(750);
//     vert_wings.close();

//     chassis.moveToPoint(-35, -43, 1000);
//     pros::delay(100);
//     intake.intake();
//     chassis.moveToPoint(-27, -15, 1000);
//     chassis.waitUntilDone();
//     pros::delay(500);
//     intake.brake();
//     chassis.moveToPoint(-35, -35, 1000);
//     chassis.moveToPose(-42, -58, 90, 1000);
//     pros::delay(250);
//     vert_wings.open();
//     chassis.waitUntilDone();
    
//     intake.outake();
//     pros::delay(750);

//     chassis.turnTo(0, -60, 1000);
//     chassis.moveToPoint(-12, -60, 1000);
//     pros::delay(250);
//     vert_wings.close();
// }

// 
void near_side_awp() {
    
}