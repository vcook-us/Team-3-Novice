#pragma once

void setupArm();
pros::Motor arm(7);

void armMotor(){
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
		arm.move(127);
	}
	else{
		arm.move(0);
	}
}
