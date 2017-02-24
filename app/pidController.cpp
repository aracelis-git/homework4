/** 
 * @author    Aldrin I. Racelis
 * @copyright Aldrin Racelis (c)2017
 * @file      pidController.cpp
 * @brief     Class Implementation of the PID Controller Object 
 * 
 */

#include <iostream> 
#include "../include/pidController.h"


pidController::pidController(double kp, double kd, double ki, double dt) :
	kp(kp),	kd(kd),	ki(ki),	dt(dt),	lastError(0),	lastIntegral(0) { }

pidController::~pidController() { }

/** 
 * @brief Calculates the input given the desired velocity, actual velocity and PID gains
 * @param the set point
 * @param the magnitude of the velocity at a current time
 */
double pidController::compute(double desiredVelocity, double actualVelocity) {
	
	// Implement computation for input
	// currentError = desVel - actVel;
	// value = kp * currentError + kd * (currentError - lastError) / dt + ki * currentErrorInt; 
	return 10; 	
}

double pidController::getKp() { return kp; }
double pidController::getKd() { return kd; }
double pidController::getKi() { return ki; }

