#include "main.h"
#include "globals.hpp"
#include "ladybrown.hpp"
#include "pros/misc.h"


void opcontrol() {
  // This is preference to what you like to drive on
  pros::motor_brake_mode_e_t driver_preference_brake = MOTOR_BRAKE_COAST;

  chassis.drive_brake_set(driver_preference_brake);

  int counter = 0;
    bool tilterState = false;
    tilter.set_value(tilterState);

    bool doinkerState = false;
    doinker.set_value(doinkerState);

    bool shift = false;

    ladyBrownInit();


  while (true) {
    // PID Tuner
    // After you find values that you're happy with, you'll have to set them in auton.cpp
    if (!pros::competition::is_connected()) {
      // Enable / Disable PID Tuner
      //  When enabled:
      //  * use A and Y to increment / decrement the constants
      //  * use the arrow keys to navigate the constants
      if (master.get_digital_new_press(DIGITAL_X))
        chassis.pid_tuner_toggle();

      // Trigger the selected autonomous routine
      if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
        autonomous();
        chassis.drive_brake_set(driver_preference_brake);
      }

      chassis.pid_tuner_iterate();  // Allow PID Tuner to iterate
    }

    // chassis.opcontrol_tank();  // Tank control
    chassis.opcontrol_arcade_standard(ez::SPLIT);   // Standard split arcade
    // chassis.opcontrol_arcade_standard(ez::SINGLE);  // Standard single arcade
    // chassis.opcontrol_arcade_flipped(ez::SPLIT);    // Flipped split arcade
    // chassis.opcontrol_arcade_flipped(ez::SINGLE);   // Flipped single arcade

    //Tilter Control
        if (controller.get_digital_new_press(DIGITAL_L1)){
        tilterState = !tilterState;
        tilter.set_value(tilterState);
        }

        //Doinker Control
        if (controller.get_digital_new_press(DIGITAL_UP)){
        doinkerState = !doinkerState;
        doinker.set_value(doinkerState);
        }

        //Shift Toggle
        // if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
        //     shift = !shift;
        // }

        //Intake Control
        if (shift == false){
            if (controller.get_digital(DIGITAL_R2)){
                intake.move_voltage(-12000);
            }else if (controller.get_digital(DIGITAL_R1)){
               intake.move_voltage(12000);
            }else{
                intake.move_voltage(0);
            }
        }


        //Lady Brown
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
            manual = false;
        }
        
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
            if (counter == 0) {
                setPosition(1950);
            }
            else if (counter == 1) {
                setPosition(13000);
                waitUntilSettled();
                manual = true;
            }
            else if (counter == 2) {
                setPosition(0);
            }
            counter ++;
            counter = counter % 3;
        }

        if (manual == true){
            if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
                ladyBrown.move_voltage(12000);
                intake.move_voltage(0);
            }
        }

//         //Color Sorter
//         rgb_value = opticalSensor.get_rgb();
//             //Blue
//             if (rgb_value.blue){
//                 colorPicker.set_value(true);
//                 pros::delay(800);
//                 colorPicker.set_value(false);
// ;            }

//             //Red
//             if (rgb_value.red){
//                 colorPicker.set_value(true);
//                 pros::delay(800);
//                 colorPicker.set_value(false);
//             }


    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}