#pragma once
#include "main.h"
#include "arm/arm.hpp"
#include "drivecode/objects.hpp" // for the controller

// arm motor
pros::Motor arm(8, pros::MotorGearset::red);

// runs once at the start
void setupArm() {
	arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD); // so the arm doesnt fall down
	arm.move(0);
}

// runs over and over in opcontrol
// X = up, B = down
void updateArm() {
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
		arm.move(100); // go up
	}
	else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
		arm.move(-100); // go down
	}
	else {
		arm.brake(); // stop and hold
	}
}


