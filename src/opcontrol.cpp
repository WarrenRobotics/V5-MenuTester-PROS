#include "main.h"

#define DRIVE_LEFT_FRONT_PORT 10
#define DRIVE_LEFT_BACK_PORT 2
#define DRIVE_RIGHT_FRONT_PORT 4
#define DRIVE_RIGHT_BACK_PORT 1

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor driveLFMotor (DRIVE_LEFT_FRONT_PORT);
	pros::Motor driveLBMotor (DRIVE_LEFT_BACK_PORT);
	pros::Motor driveRFMotor (DRIVE_RIGHT_FRONT_PORT, true);
	pros::Motor driveRBMotor (DRIVE_RIGHT_BACK_PORT, true);
	while (true) {
		//Confiugre drivetrain
		driveLFMotor.move(master.get_analog(ANALOG_LEFT_Y));
		driveLBMotor.move(master.get_analog(ANALOG_LEFT_Y));
		driveRFMotor.move(master.get_analog(ANALOG_RIGHT_Y));
		driveRBMotor.move(master.get_analog(ANALOG_RIGHT_Y));

		//Dont hog
		pros::delay(2);
	}
}
