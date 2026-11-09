   #include "drivecode/intake.hpp"
   #include "drivecode/objects.hpp"

   void setupIntake() {
       intake.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
   }

   void updateIntake() {
       if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
           intake.move(127);
       } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
           intake.move(-127);
       } else {
           intake.brake();
       }
   }