#include "main.h"

// near auton assets
ASSET(Near_Rush_1_SizeAdjust_txt);
ASSET(Near_Rush_2_SizeAdjust_txt);
ASSET(Near_Rush_3_SizeAdjust_txt);

// new far autons
ASSET(Far_Rush_1_txt);
ASSET(Far_Rush_2_txt);
ASSET(Far_Rush_3_txt);
ASSET(Far_Rush_4_txt);
ASSET(Far_Rush_5_txt);
ASSET(Far_Rush_6_txt);

// test autons
ASSET(Test_txt);

/**
 * For those not in the know, PID stands for proportional, integral, derivative control. I’ll break it down:
 * P: if you’re not where you want to be, get there.
 * I: if you haven’t been where you want to be for a long time, get there faster
 * D: if you’re getting close to where you want to be, slow down.
 *
 * https://www.youtube.com/watch?v=qKy98Cbcltw
*/
void pidLinearTest() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 15, 15000, true, 127.0, false);

    // pros::delay(1000);
    // chassis.moveToPoint(0, 10, 1000, true, 127, false);
    // pros::delay(1000);
    // chassis.turnTo(10, 10, 1000, true, 127, false);
    // pros::delay(1000);
    // chassis.moveToPose(0, 0, 0, 10000);
}

void pidAngularTest() {
    chassis.setPose(0, 0, 0);
    chassis.turnTo(10, 0, 15000, true, 127.0, false);
}

void autonTest() {
    chassis.setPose(-12, -36, 0);
    chassis.follow(Test_txt, 15, 5000, true, false);
    chassis.waitUntilDone();
}

/**
 * TODO: verify lookahead distances!
 * TODO: does "heading" parameter matter for end control points?
 * 
 * START: facing front, middle "legal" tile, AT THE FRONT OF SAID TILE (aligned with back part of "connectors") (-35, 55)
 * 
 * ISSUES:
 * - probably needs to be more right
 * 
 * TIME: "about" 14.2 seconds
 * 
 * TODO: see lowest timeouts we can set for `chassis.follow()` and `chassis.turnTo()` calls
 * TODO: find a good lookahead distance for `chassis.follow()` calls
 * TODO: see least possible buffer delay you can set for intaking triballs / opening and closing wings
*/

// currently path 1 is NOT reaching the triball; missing by a GOOD 30% of a tile
void near_side_rush() {
    // initially sets position/heading to that at the beginning of the first path file!
    chassis.setPose(
        -35
        , -58
        , 0
    );

    printf("[near_side_rush]: starting near side autons...\n");
    printf("----------------------------------------------\n\n");
    


    /**
     * GOAL: yeets alliance triball
    */
    // starts intake running
    printf("[near_side_rush]: starting intake\n");
    intake.intake();

    // opens wings to yeet triball
    printf("[near_side_rush]: opening wings to yeet triballs\n");
    horiz_wings.open();
    // delay for it to like... fully open
    pros::delay(500);
    
    // closes wings
    printf("[near_side_rush]: close wings cuz otherwise they're gonna get ripped right off\n");
    horiz_wings.close();
    // delay for it to like... fully close
    pros::delay(500);

    

    /**
     * GOAL: goes forward and intake the center triball
    */
    

    // goes to center triball
    printf("[near_side_rush]: going to intake center triball...");

    chassis.follow(
        Near_Rush_1_SizeAdjust_txt /* path file to follow */

        , 15                       /* lookahead distance */

        , 1200                     /* timeout */

        , true                     /* we're moving forwards along the path! 
                                      (i.e. the front of the robot is moving towards the finish point) */

        , false                    /* we're NOT running this asynchronously; waits for path to finish before
                                      continuing, unless the path times out*/
    );


    // waits for intake to do its thing
    printf("[near_side_rush]: intaking center triball...");
    pros::delay(500);



    /**
     * GOAL: returns back to initial position, following same path as before!
    */
    printf("[near_side_full]: going back to initial position...\n");
    /**
     * TODO: dunno why this is here...?
    */
    // chassis.turnTo(
    //     -36
    //     , -60
    //     , 500
    //     , false);
    // chassis.waitUntilDone();
    // follows the path but backwards
    chassis.follow(
        Near_Rush_2_SizeAdjust_txt // path
        , 15 // lookahead
        , 1500 // timeout
        , false
        , false
    );



    /**
     * GOAL: turn toward triball under elevation bar!
    */
    chassis.turnTo(
        0       // x
        , -60   // y
        , 1000  // how long it can spend turning (1000 ms)
        , true  // turns to face triball with FRONT of robot
        , 127.0 // max speed 127
        , false // will NOT run asynchronously (blocking function)
    );



    /**
     * GOAL: outtake intaked triball (from middle of field)
    */
    // starts outtaking the triball
    intake.outake();

    // waits for intake to do its thing
    pros::delay(500);
    
    // stops intake!
    intake.brake();



    /**
     * GOAL: turn towards goal
    */
    chassis.turnTo(
        -60     // x
        , -36   // y
        , 1000  // timeout
        , false  // backwards
        , 127.0 // max speed
        , false // NO ASYNC; IS BLOCKING
    );

    // rams into goal with BACK of bot (NOTE: the path file is designed to direct the bot toward a position inside the goal, which
    // it will obviously never reach, but this ensures it will spend time like running motors and getting triball under goal if not already)
    chassis.follow(
        Near_Rush_3_SizeAdjust_txt // file
        , 15 // lookahead
        , 1500 // timeout
        , false // going BACKWARDS
        , false // asynchronous!!
    );


    /**
     * GOAL: return back to previous position, slightly more towards the matchload bar
    */
    chassis.moveToPoint(
        -58      // x
        , -44    // y
        , 1000   // timeout = 500ms
        , true   // moving FORWARDS
        , 127.0  // maxSpeed
        , false  // blocking
    );



    /**
     * GOAL: rotate towards next intended position (with FRONT of robot, since sunny removed one of the vertical wings ;-;)
    */
    /**
     * TODO: could we just do "moveToPose" so it would turn and then go towards the point, or would it do the funny and swing turn while driving?
    */
    chassis.turnTo(
        -44   // x
        , -59 // y
        , 1500 // timeout
        , false // moving FORWARD
        , 127.0 // max speed
        , false // asynchronous
    );


    // opens vertical wings so the triball in the matchload bar can be untriballed (i mean unmatchloaded (i mean removed from the matchload bar))
    // you get what i mean...
    vert_wings.open();


    /**
     * GOAL: go towards next intended position
    */
    chassis.moveToPoint(
        -44     // x
        , -59   // y
        , 1500  // timeout
        , false  // moving forward
        , 127.0 // max speed
        , false // async
    );

    // closes vertical wings
    vert_wings.close();
    // waits a BIIIT longer for wings to close 
    pros::delay(100);



    /**
     * GOAL: turns robot towards elevation bar, (hopefully) getting triball out of matchload bar
    */
    chassis.turnTo(
        0
        , -59
        , 1000
        , false
        , 127.0
        , false
    );

    // makes bot face with like... front of robor?
    chassis.turnTo(
        0
        , -59
        , 1000
        , true
        , 127.0
        , false
    );



    /**
     * GOAL: touches elevation bar and pushes all triballs to other side of the field!
    */
    // makes sure triballs don't get stuck in the intake
    intake.outake();

    // shlams into all le triballs, moving towards elevation bar but NOT crossing it!
    chassis.moveToPoint(
        -10    // x
        , -60  // y
        , 1500 // timeout
        , true // moving FORWARDS!
        , 127.0 // max speed
        , false // NOT Async
    );

    // stops intake cuz like we don't like wasting those precious watts here!!!
    intake.brake();

    // aaand now it should be touching the matchload bar!
    printf("[near_side_rush]: finished near side rush!\n");
    printf("----------------------------------------------\n\n");
}

void far_side_rush() {
    chassis.setPose(35, -57.5, 0);
    intake.intake();
    horiz_wings.open();
    pros::delay(350);
    chassis.follow(Far_Rush_1_txt, 25, 5000);
    pros::delay(100);
    horiz_wings.close();
    chassis.waitUntilDone();

    pros::delay(350); // checkpoint 1

    chassis.turnTo(65, 65, 1000);
    chassis.waitUntilDone();
    horiz_wings.open();
    chassis.follow(Far_Rush_2_txt, 25, 2000);
    pros::delay(100);
    intake.outake();
    chassis.waitUntilDone();

    pros::delay(10); // checkpoint 2

    intake.brake();
    chassis.turnTo(0, -65, 500);    
    chassis.waitUntilDone();
    chassis.follow(Far_Rush_3_txt, 25, 3500);
    pros::delay(500);
    intake.intake();
    chassis.waitUntilDone();

    pros::delay(350); // checkpoint 3

    chassis.follow(Far_Rush_4_txt, 25, 5000, false);
    chassis.waitUntilDone();
    intake.outake();

    pros::delay(750); // checkpoint 4

    chassis.turnTo(0, -60, 1200);
    chassis.waitUntilDone();
    intake.intake();
    chassis.moveToPoint(11.505, -58.975, 5000);
    chassis.waitUntilDone();

    pros::delay(350); // checkpoint 5

    chassis.follow(Far_Rush_5_txt, 30, 5000, false);
    pros::delay(2000);
    vert_wings.open();
    pros::delay(750);
    vert_wings.close();
    chassis.waitUntilDone();

    pros::delay(10); // checkpoint 6

    chassis.follow(Far_Rush_6_txt, 30, 5000);
    chassis.waitUntilDone();

    // checkpoint 7 (final)
}

// void prog_skills_max() {
//     chassis.setPose(
//         -47.605, 
//         -55.916,
//         0
//     );
// }

/**
 * START: "same" setup as with near-side autons, except mirrored so triball is on right side of robor, w/ horizontal wings
*/
// void far_side_full() {
//     // opens wings
//     // horiz_wings.right_wing_piston.set_value(1);
//     pros::delay(50);

//     // closes wings WHILE moving forward


//     horiz_wings.close();
//     pros::delay(50);
// }

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