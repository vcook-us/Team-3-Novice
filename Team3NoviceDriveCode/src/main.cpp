#include "main.h"
#include "drivecode/objects.hpp"
#include "drivecode/intake.hpp"
#include "drivecode/arm.hpp"
#include "drivecode/screen.hpp"

#include <cstdlib>

const int DEADBAND = 6;          // stick values this small count as 0
const double TURN_SCALE = 0.8;   // turning is touchy at full speed
const double SLOW_SCALE = 0.4;   // slow mode speed
const int MATCH_MS = 105000;     // 1:45, for the rumble warnings

int stick(int value) {
    return std::abs(value) < DEADBAND ? 0 : value;
}

void initialize() {
    pros::lcd::initialize();

    chassis.calibrate();
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    setupIntake();
    setupArm();
    startScreen();

    // The controller screen needs a short pause between commands.
    pros::delay(100);
    int missing = missingMotors();
    controller.clear();
    pros::delay(100);
    if (missing > 0) {
        controller.print(0, 0, "%d MOTOR(S) MISSING", missing);
        pros::delay(100);
        controller.rumble("---");
    } else {
        controller.print(0, 0, "Ready");
    }
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
    const int start = pros::millis();
    bool warned15 = false;
    bool warned5 = false;

    while (true) {
        int throttle = stick(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
        int turn = stick(controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));
        double scale = slowMode ? SLOW_SCALE : 1.0;

        if (throttle == 0 && turn == 0) {
            leftMotors.brake();
            rightMotors.brake();
        } else {
            chassis.arcade(throttle * scale, turn * TURN_SCALE * scale);
        }

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
            slowMode = !slowMode;
            controller.rumble(slowMode ? "." : "..");
        }

        updateIntake();
        updateArm();

        int elapsed = pros::millis() - start;
        if (!warned15 && elapsed > MATCH_MS - 15000) {
            controller.rumble("-");
            warned15 = true;
        }
        if (!warned5 && elapsed > MATCH_MS - 5000) {
            controller.rumble("- - -");
            warned5 = true;
        }

        pros::delay(10);
    }
}

