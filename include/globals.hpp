#pragma once
#include "main.h" // IWYU pragma: keep
#include "EZ-Template/drive/drive.hpp"

//Chassis constructor
extern Drive chassis;

//Controller
extern pros::Controller controller;

//Motors
extern pros::Motor hookIntake,rollerIntake;
extern pros::Motor motors[8];
extern pros::MotorGroup leftMotors, rightMotors;

//IMU
extern pros::IMU imu;

//Pneumatics
extern pros::adi::DigitalOut doinker, tilter;

//PID Constants
extern void default_constants();