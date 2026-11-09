#include "drivecode/objects.hpp"

pros::MotorGroup leftMotors({1, 2, 3},pros::MotorGears::blue);
pros::MotorGroup rightMotors({-4, -5, -6},pros::MotorGears::blue);
pros::Motor intake(7, pros::MotorGears::blue);


lemlib::Drivetrain drivetrain(
    &leftMotors,
    &rightMotors,
    14.0,                       // track width in inches: measure yours
    lemlib::Omniwheel::NEW_275, // 2.75" wheels
    360,                        // wheel rpm
    8                           // horizontal drift
);

lemlib::OdomSensors odomSensors(nullptr, nullptr, nullptr, nullptr, nullptr);


lemlib::ControllerSettings lateralController(0, 0, 0, 0, 0, 0, 0, 0, 0);
lemlib::ControllerSettings angularController(0, 0, 0, 0, 0, 0, 0, 0, 0);

lemlib::Chassis chassis(drivetrain, lateralController, angularController, odomSensors);

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor arm(8, pros::MotorGears::red, pros::MotorUnits::degrees);