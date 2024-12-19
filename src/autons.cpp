#include "ladybrown.hpp"
#include "main.h"
#include "globals.hpp"
#include "colorSort.hpp"


void autonomous() {
  chassis.pid_targets_reset();                // Resets PID targets to 0
  chassis.drive_imu_reset();                  // Reset gyro position to 0
  chassis.drive_sensor_reset();               // Reset drive sensors to 0
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency

  ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
}


void redLeftAWP(){

  colorIndex = 1;
  
  //score on alliance goal
  chassis.pid_drive_set(1,90);
  chassis.pid_wait();
  chassis.pid_turn_set(41,90);
  chassis.pid_wait();
  setPosition(17000);
  pros::delay(750);

  //grab mobile goal
  chassis.pid_drive_set(-4,90);
  chassis.pid_wait();
  setPosition(-1950);
  pros::delay(250);
  chassis.pid_turn_set(70,90);
  chassis.pid_wait();
  tilter.set_value(false);
  chassis.pid_drive_set(-36,90);
  chassis.pid_wait();
  pros::delay(100);
  tilter.set_value(true);
  pros::delay(500);

  //score first ring
  intake.move_voltage(12000);
  chassis.pid_turn_set(180,90);
  chassis.pid_wait();
  chassis.pid_drive_set(26,90);
  chassis.pid_wait();
  pros::delay(500);

  //score other two rings
  chassis.pid_turn_set(-95,90);
  chassis.pid_wait();
  chassis.pid_drive_set(14,90);
  chassis.pid_wait();
  chassis.pid_turn_set(-40,90);
  chassis.pid_wait();
  chassis.pid_drive_set(15,90);
  chassis.pid_wait();
 
  //touch the pole
  chassis.pid_turn_set(13,90);
  chassis.pid_wait();
  chassis.pid_drive_set(10,90);
  chassis.pid_wait();
  intake.move_voltage(0);


}  


void redRightAWP(){

  colorIndex = 1;
  
}


void blueLeftAWP(){

  colorIndex = 0;
  
}


void blueRightAWP(){

  colorIndex = 0;
  
  //score on alliance goal
  chassis.pid_drive_set(1,90);
  chassis.pid_wait();
  chassis.pid_turn_set(-41,90);
  chassis.pid_wait();
  setPosition(17000);
  pros::delay(750);

  //grab mobile goal
  chassis.pid_drive_set(-4,90);
  chassis.pid_wait();
  setPosition(-1950);
  pros::delay(250);
  chassis.pid_turn_set(-70,90);
  chassis.pid_wait();
  tilter.set_value(false);
  chassis.pid_drive_set(-36,90);
  chassis.pid_wait();
  pros::delay(100);
  tilter.set_value(true);
  pros::delay(500);

  //score first ring
  intake.move_voltage(12000);
  chassis.pid_turn_set(-180,90);
  chassis.pid_wait();
  chassis.pid_drive_set(26,90);
  chassis.pid_wait();
  pros::delay(750);

  //score other two rings
  chassis.pid_turn_set(95,90);
  chassis.pid_wait();
  chassis.pid_drive_set(7,90);
  chassis.pid_wait();
  chassis.pid_turn_set(40,90);
  chassis.pid_wait();
  chassis.pid_drive_set(8,90);
  chassis.pid_wait();

  //touch the pole
  chassis.pid_turn_set(-13,90);
  chassis.pid_wait();
  chassis.pid_drive_set(10,90);
  chassis.pid_wait();
  intake.move_voltage(0);

}


void redLeftElim(){

  colorIndex = 1;
  
}


void redRightElim(){

  colorIndex = 1;
  
}


void blueLeftElim(){

  colorIndex = 0;
  
}


void blueRightElim(){

  colorIndex = 0;
  
}


void skills(){

  colorIndex = 1;
  
}


//REFERENCE DOWN BELOW

// /////
// // For installation, upgrading, documentations, and tutorials, check out our website!
// // https://ez-robotics.github.io/EZ-Template/
// /////

// // These are out of 127
// const int DRIVE_SPEED = 110;
// const int TURN_SPEED = 90;
// const int SWING_SPEED = 90;

// ///
// // Constants
// ///


// ///
// // Drive Example
// ///
// void drive_example() {
//   // The first parameter is target inches
//   // The second parameter is max speed the robot will drive at
//   // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
//   // for slew, only enable it when the drive distance is greater than the slew distance + a few inches

//   chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
//   chassis.pid_wait();

//   chassis.pid_drive_set(-12_in, DRIVE_SPEED);
//   chassis.pid_wait();

//   chassis.pid_drive_set(-12_in, DRIVE_SPEED);
//   chassis.pid_wait();
// }

// ///
// // Turn Example
// ///
// void turn_example() {
//   // The first parameter is the target in degrees
//   // The second parameter is max speed the robot will drive at

//   chassis.pid_turn_set(90_deg, TURN_SPEED);
//   chassis.pid_wait();

//   chassis.pid_turn_set(45_deg, TURN_SPEED);
//   chassis.pid_wait();

//   chassis.pid_turn_set(0_deg, TURN_SPEED);
//   chassis.pid_wait();
// }

// ///
// // Combining Turn + Drive
// ///
// void drive_and_turn() {
//   chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
//   chassis.pid_wait();

//   chassis.pid_turn_set(45_deg, TURN_SPEED);
//   chassis.pid_wait();

//   chassis.pid_turn_set(-45_deg, TURN_SPEED);
//   chassis.pid_wait();

//   chassis.pid_turn_set(0_deg, TURN_SPEED);
//   chassis.pid_wait();

//   chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
//   chassis.pid_wait();
// }

// ///
// // Wait Until and Changing Max Speed
// ///
// void wait_until_change_speed() {
//   // pid_wait_until will wait until the robot gets to a desired position

//   // When the robot gets to 6 inches slowly, the robot will travel the remaining distance at full speed
//   chassis.pid_drive_set(24_in, 30, true);
//   chassis.pid_wait_until(6_in);
//   chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
//   chassis.pid_wait();

//   chassis.pid_turn_set(45_deg, TURN_SPEED);
//   chassis.pid_wait();

//   chassis.pid_turn_set(-45_deg, TURN_SPEED);
//   chassis.pid_wait();

//   chassis.pid_turn_set(0_deg, TURN_SPEED);
//   chassis.pid_wait();

//   // When the robot gets to -6 inches slowly, the robot will travel the remaining distance at full speed
//   chassis.pid_drive_set(-24_in, 30, true);
//   chassis.pid_wait_until(-6_in);
//   chassis.pid_speed_max_set(DRIVE_SPEED);  // After driving 6 inches at 30 speed, the robot will go the remaining distance at DRIVE_SPEED
//   chassis.pid_wait();
// }

// ///
// // Swing Example
// ///
// void swing_example() {
//   // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
//   // The second parameter is the target in degrees
//   // The third parameter is the speed of the moving side of the drive
//   // The fourth parameter is the speed of the still side of the drive, this allows for wider arcs

//   chassis.pid_swing_set(ez::LEFT_SWING, 45_deg, SWING_SPEED, 45);
//   chassis.pid_wait();

//   chassis.pid_swing_set(ez::RIGHT_SWING, 0_deg, SWING_SPEED, 45);
//   chassis.pid_wait();

//   chassis.pid_swing_set(ez::RIGHT_SWING, 45_deg, SWING_SPEED, 45);
//   chassis.pid_wait();

//   chassis.pid_swing_set(ez::LEFT_SWING, 0_deg, SWING_SPEED, 45);
//   chassis.pid_wait();
// }

// ///
// // Motion Chaining
// ///
// void motion_chaining() {
//   // Motion chaining is where motions all try to blend together instead of individual movements.
//   // This works by exiting while the robot is still moving a little bit.
//   // To use this, replace pid_wait with pid_wait_quick_chain.
//   chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
//   chassis.pid_wait();

//   chassis.pid_turn_set(45_deg, TURN_SPEED);
//   chassis.pid_wait_quick_chain();

//   chassis.pid_turn_set(-45_deg, TURN_SPEED);
//   chassis.pid_wait_quick_chain();

//   chassis.pid_turn_set(0_deg, TURN_SPEED);
//   chassis.pid_wait();

//   // Your final motion should still be a normal pid_wait
//   chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
//   chassis.pid_wait();
// }

// ///
// // Auto that tests everything
// ///
// void combining_movements() {
//   chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
//   chassis.pid_wait();

//   chassis.pid_turn_set(45_deg, TURN_SPEED);
//   chassis.pid_wait();

//   chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
//   chassis.pid_wait();

//   chassis.pid_turn_set(0_deg, TURN_SPEED);
//   chassis.pid_wait();

//   chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
//   chassis.pid_wait();
// }

// ///
// // Interference example
// ///
// void tug(int attempts) {
//   for (int i = 0; i < attempts - 1; i++) {
//     // Attempt to drive backward
//     printf("i - %i", i);
//     chassis.pid_drive_set(-12_in, 127);
//     chassis.pid_wait();

//     // If failsafed...
//     if (chassis.interfered) {
//       chassis.drive_sensor_reset();
//       chassis.pid_drive_set(-2_in, 20);
//       pros::delay(1000);
//     }
//     // If the robot successfully drove back, return
//     else {
//       return;
//     }
//   }
// }

// // If there is no interference, the robot will drive forward and turn 90 degrees.
// // If interfered, the robot will drive forward and then attempt to drive backward.
// void interfered_example() {
//   chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
//   chassis.pid_wait();

//   if (chassis.interfered) {
//     tug(3);
//     return;
//   }

//   chassis.pid_turn_set(90_deg, TURN_SPEED);
//   chassis.pid_wait();
// }

// // . . .
// // Make your own autonomous functions here!
// // . . .