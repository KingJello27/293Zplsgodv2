#include "main.h" // IWYU pragma: keep
#include "EZ-Template/drive/drive.hpp"

// Chassis constructor
    ez::Drive chassis(
    // These are your drive motors, the first motor is used for sensing!
    {-7, -14, -18},     // Left Chassis Ports (negative port will reverse it!)
    {12, 15, 9},  // Right Chassis Ports (negative port will reverse it!)

    17,      // IMU Port
    3.25,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
    600,    // Cartridge RPM

    // External Gear Ratio (MUST BE DECIMAL) This is WHEEL GEAR / MOTOR GEAR
    // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 84/36 which is 2.333
    // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 36/60 which is 0.6
    1.33);

//controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// left motor group
pros::MotorGroup leftMotors({-2, -14, -18}, pros::MotorGears::blue);
// right motor group
pros::MotorGroup rightMotors({12, 15, 9}, pros::MotorGears::blue);

// vertical tracking wheel encoder
pros::Rotation vertical_encoder(16);
// horizontal tracking wheel encoder
pros::Rotation horizontal_encoder(19);

//Motors
pros::Motor hookIntake(-13, pros::MotorGearset::blue);
pros::Motor rollerIntake(-10, pros::MotorGearset::blue);

pros::MotorGroup intake({-13,-10}, pros::MotorGears::blue);

//pneumatics
pros::adi::DigitalOut tilter('A');
pros::adi::DigitalOut doinker('B');
// pros::adi::DigitalOut colorPicker('D');

//IMU
pros::Imu imu(17);

// PID Constants
void default_constants() {
  chassis.pid_heading_constants_set(11, 0, 20);
  chassis.pid_drive_constants_set(20, 0, 100);
  chassis.pid_turn_constants_set(3, 0.05, 20, 15);
  chassis.pid_swing_constants_set(6, 0, 65);

  chassis.pid_turn_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_swing_exit_condition_set(80_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
  chassis.pid_drive_exit_condition_set(80_ms, 1_in, 250_ms, 3_in, 500_ms, 500_ms);

  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  chassis.slew_drive_constants_set(7_in, 80);
}