#include "drivecode/arm.hpp"
#include "drivecode/objects.hpp"

const double ARM_FOLDED = 0;
const double ARM_HIGH_FLAG = 90;
const double ARM_LOW_FLAG = 175;
const double ARM_MAX = 185;     // never drive the arm past this
const int ARM_MANUAL_RPM = 60;  // L1/L2 speed
const int ARM_PRESET_RPM = 80;  // arrow button speed

// true while L1/L2 is moving the arm
static bool armManual = false;

void setupArm() {
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    arm.tare_position();
}

void updateArm() {
    double angle = arm.get_position();

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) && angle < ARM_MAX) {
        arm.move_velocity(ARM_MANUAL_RPM);
        armManual = true;
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && angle > ARM_FOLDED) {
        arm.move_velocity(-ARM_MANUAL_RPM);
        armManual = true;
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
        arm.move_absolute(ARM_HIGH_FLAG, ARM_PRESET_RPM);
        armManual = false;
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        arm.move_absolute(ARM_LOW_FLAG, ARM_PRESET_RPM);
        armManual = false;
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
        arm.move_absolute(ARM_FOLDED, ARM_PRESET_RPM);
        armManual = false;
    } else if (armManual) {
        arm.brake();
        armManual = false;
    }
}