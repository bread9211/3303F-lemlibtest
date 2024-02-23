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
ASSET(Near_Mid_1_Working_txt);
ASSET(Near_Mid_1_Testing_txt);
ASSET(Near_Mid_2_Testing_txt);

// ASSET(Near_Mid_1_AccelAdjust2_txt);
ASSET(Near_Mid_1_PosAdjust_txt)
ASSET(Near_Mid_3_Curve_txt);
// ASSET(Near_Mid_3_Testing_txt);
// ASSET(Near_Mid_2_Cooking_txt);

// new far autons
ASSET(Far_Rush_1);
ASSET(Far_Rush_2);
ASSET(Far_Rush_3);
ASSET(Far_Rush_4);
ASSET(Far_Rush_5);
ASSET(Far_Rush_6);


// programming skills autons
// ASSET()

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

void far_side_rush() {
    chassis.setPose(35, -57.5, 0);
    intake.intake();
    horiz_wings.open();
    pros::delay(350);
    chassis.follow(Far_Rush_1, 25, 5000);
    pros::delay(100);
    horiz_wings.close();
    chassis.waitUntilDone();

    pros::delay(350); // checkpoint 1

    chassis.turnTo(65, 65, 1000);
    chassis.waitUntilDone();
    horiz_wings.open();
    chassis.follow(Far_Rush_2, 25, 2000);
    pros::delay(100);
    intake.outake();
    chassis.waitUntilDone();

    pros::delay(10); // checkpoint 2

    intake.brake();
    chassis.turnTo(0, -65, 500);    
    chassis.waitUntilDone();
    chassis.follow(Far_Rush_3, 25, 3500);
    pros::delay(500);
    intake.intake();
    chassis.waitUntilDone();

    pros::delay(350); // checkpoint 3

    chassis.follow(Far_Rush_4, 25, 5000, false);
    chassis.waitUntilDone();
    intake.outake();

    pros::delay(750); // checkpoint 4

    chassis.turnTo(0, -60, 1200);
    chassis.waitUntilDone();
    intake.intake();
    chassis.moveToPoint(11.505, -58.975, 5000);
    chassis.waitUntilDone();

    pros::delay(350); // checkpoint 5

    chassis.follow(Far_Rush_5, 30, 5000, false);
    pros::delay(2000);
    vert_wings.open();
    pros::delay(750);
    vert_wings.close();
    chassis.waitUntilDone();

    pros::delay(10); // checkpoint 6

    chassis.follow(Far_Rush_6, 30, 5000);
    chassis.waitUntilDone();

    // checkpoint 7 (final)
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
*/
void near_side_rush() {
    // initially sets position/heading to that at beginning of file!
    // chassis.setPose(
    //     -36 // x
    //     , -60 // y
    //     , 0 // heading (degrees by default)
    // );
    chassis.setPose(
        -36
        , -55
        , 0
    );
    

    /**
     * GOAL: yeets alliance triball
    */
    printf("[near_side_full]: opening wings to yeet triballs\n");
    horiz_wings.open();
    // delay for it to like... fully open
    pros::delay(750);
    
    printf("[near_side_full]: close wings cuz otherwise they're gonna get ripped right off\n");
    horiz_wings.close();
    // delay for it to like... fully close
    pros::delay(750);

    
    /**
     * GOAL: goes forward and intake the center try ball
    */
    // starts intake running
    intake.intake();
    // goes to center triball; this x
    chassis.follow(Near_Mid_1_PosAdjust_txt, 30, 5000, true, false);
    // waits for intake to do its thing
    pros::delay(500);
    // stops intake
    // intake.brake();

    return;


    /**
     * GOAL: returns back to initial position (hopefully facing the same way... HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH)
    */
    printf("[near_side_full]: SUPPOSED to go backwards...\n");
    // follows the path but backwards
    chassis.follow(Near_Mid_2_Testing_txt, 30, 1500, false, false);

    /**
     * GOAL: turn toward triball under elevation bar!
    */
    chassis.turnTo(
        0       // x
        , -60   // y
        , 1000  // how long it can spend turning (1000 ms)
        , true  // turns to face triball w/ FRONT of robor
        , 127.0 // max speed 127
        , false // will NOT run asynchronously (blocking function)
    );

    /**
     * GOAL: outtake intaked triball (from middle of field)
    */
    intake.outake();
    // waits for intake to do its thing
    pros::delay(1000);
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

    // /**
    //  * GOAL: move towards the goal (haha, nice pun!)
    // */
    // // chassis.follow(
    // //     Near_Mid_3_Testing_txt // le file to follow
    // //     , 15                   // le lookahead dist in inches
    // //     , 2000                 // timeout (2000 ms)
    // //     , true                 // forwards
    // //     , false                // NO ASYNC; IS BLOCKING
    // // );
    // chassis.moveToPoint(
    //     -60     // x
    //     , -36   // y
    //     , 1500  // timeout
    //     , true  // forwards
    //     , 127.0 // maxSpeed
    //     , false // async
    // );

    // /**
    //  * GOAL: turn TOWARDS the goal
    // */
    // chassis.turnTo(
    //     -60     // x
    //     , 0     // y
    //     , 1000  // timeout
    //     , true  // forwards
    //     , 127.0 // maxSpeed
    //     , false // blocking
    // );

    // /**
    //  * GOAL: push into le goal
    //  * 
    //  * NOTE: the point is INTENTIONALLY set to be on the opposite side of the goal, EVEN THOUGH
    //  * the bot can't get there, to ensure that the bot is actually PUSHING AGAINST the goal
    //  * and scoring the alliance triball
    // */
    // chassis.moveToPoint(
    //     -60     // x
    //     , 24   // y
    //     , 1000   // timeout
    //     , true  // forwards
    //     , 127.0 // 
    //     , false
    // );

    // rams into goal with BACK of bot
    chassis.follow(Near_Mid_3_Curve_txt, 15, 2000, false, false);

    /**
     * GOAL: return back to previous position, slightly more towards the matchload bar
    */
    chassis.moveToPoint(
        -60     // x
        , -44   // y
        , 1000   // timeout = 500ms
        , true // moving backwards
        , 127.0 // maxSpeed
        , false // blocking
    );


    /**
     * GOAL: rotate towards next intended position
    */
    /**
     * TODO: could we just do "moveToPose" so it would turn and then go towards the point, or would it do the funny and swing turn while driving?
    */
    chassis.turnTo(
        -44
        , -60
        , 1500
        , true
        , 127.0
        , false
    );

    // opens vertical wings so the triball in the matchload bar can be untriballed (i mean unmatchloaded)
    vert_wings.open();
    pros::delay(50);

    /**
     * GOAL: go towards next intended position
    */
    chassis.moveToPoint(
        -44
        , -60
        , 1500
        , true
        , 127.0
        , false
    );

    // closes vertical wings
    vert_wings.close();
    // waits a BIIIT longer for wings to close 
    pros::delay(50);

    /**
     * GOAL: turns robot towards matchload bar, (hopefully) getting triball out of matchload bar
    */
    chassis.turnTo(
        -8.75
        , -60
        , 1000
        , true
        , 127.0
        , false
    );

    // shlams into all le triballs, moving towards elevation bar but NOT crossing it!
    chassis.moveToPoint(
        -14
        , -60
        , 1500
        , true
        , 127.0
        , false
    );

    intake.outake();
    pros::delay(500);
    intake.brake();

    // aaand now it should be touching the matchload bar!
}

void prog_skills_max() {
    chassis.setPose(
        -47.605, 
        -55.916,
        0
    );
}

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