#pragma once
#include "main.h"
#include "intake/intake.hpp"
#include "drivecode/objects.hpp" // for controller
 
// intake motor
pros::Motor intake(7, pros::MotorGearset::blue);
 
// runs once at the start
void setupIntake() {
	intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST); // let it spin down when we stop
	intake.move(0); // make sure its not moving
}
 
// runs over and over in opcontrol
// R1 = in, R2 = out
void updateIntake() {
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
		intake.move(127);
	}
	else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
		intake.move(-127);
	}
	else {
		intake.move(0);
	}
}
