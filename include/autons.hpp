/**
 * things to keep in mind:
 * - length of bot ("height"): 21 inches (including intake--17 inches without)
 *   - NOTE: currently, the autons use 21 inches as length!
 * - width of bot: 15.5 inches
 * 
 * previous auton widths (before states rebuild):
 * WIDTH: 14
 * HEIGHT: 17.5
*/

/**
 * TODO: will width and height values need to encompass WHOLE BOT? (height value seemingly not including intake a little...)
 * TODO: implement autons for both far side and near side!
 * TODO: implement separate autons for far and near side depending on whether you're red or blue team (does this really matter? probs not...)
 * TODO: rewrite auton selector!
 * TODO: condense three init funcs into one bc same templating
 * TODO: colorized terminal output! (see if vex brain's terminal supports it)
 * TODO: partially opening / closing wings might be troublesome; if it's just for autons then it SHOULD be fine bc we close anyways
*/

/**
 * path generator: https://path.jerryio.com/
 * 
 * WIDTH: 14
 * HEIGHT: 17.5
*/

#pragma once

#include "main.h"

// #include <mutex>
// #include <condition_variable>
// #include <atomic>
// #include <chrono>

// #define DEFAULT_AS_HUE 360;
// #define DEFAULT_AS_PAGE 0;
// #define DEFAULT_AS_AUTON 0;

// drives forward / turns, allowing us to test PID
void pidLinearTest();
void pidAngularTest();

// (drives straight along entire length of central (long) barrier)
void autonTest();

// void far_side();

/**
 * TODO: see lowest timeouts we can set for `chassis.follow()` and `chassis.turnTo()` calls
 * TODO: find a good lookahead distance for `chassis.follow()` calls
 * TODO: see least possible buffer delay you can set for intaking triballs / opening and closing wings
*/
void near_side_rush();

void far_side_rush();

/**
 * GOAL: RAHHH. AS MANY TRIBALLS AS POSSIBLE. SCORE!!!
 * 
 * REFERENCE: https://www.youtube.com/watch?v=c86VTALprxo
*/
void prog_skills_max();

/**
 * AIM:
 * - open wings to 
*/
// void near_side();