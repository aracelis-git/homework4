/** 
 * @author    Aldrin I. Racelis
 * @copyright Aldrin Racelis (c)2017
 * @file      pidController.cpp
 * @brief     Class Implementation of the PID Controller Object 
 * 
 */

#include <iostream> 
#include <exception>
#include "../include/pidController.h"



pidController::pidController(double kp, double kd, double ki, double dt)  :
	kp(kp),	kd(kd),	ki(ki),	dt(dt),	lastError(0),	lastIntegral(0) {

	  /**
	   * If values are negative make them positive
	   */
	  (this->kp <0)? this->kp = -1*kp :  kp;

      (this->kd <0)? this->kd = -1*kd  : kd;

      (this->ki <0)? this->ki = -1*ki  : ki;

}
pidController::~pidController() { }

/** 
 * @brief Calculates the input given the desired velocity, actual velocity and PID gains
 * @param the set point
 * @param the magnitude of the velocity at a current time
 */


double pidController::compute(double desiredVelocity, double actualVelocity) {
	
	 double epsilon = 0.001;
	 double error = getLastError();
     double result = 0;

	 // Implement computation for input
	// currentError = desVel - actVel;
	// value = kp * currentError + kd * (currentError - lastError) / dt + ki * currentErrorInt;
	// currentError = desVel - actVel;
	// value = kp * currentError + kd * (currentError - lastError) / dt + ki * currentErrorInt;

    double currentError = desiredVelocity - actualVelocity;

    do {

    	result = currentError * this->getKp() + (currentError-error)/(this->getDt()* this->getKd())
    		+ this->getLastIntegral()* this->getKi();

    	//std::cout<< " values " <<(desiredVelocity-result) << "  " <<epsilon<<std::endl << " result " << result;

    }while( (desiredVelocity - result ) > epsilon );

    return result;

	//return 3;
}

double pidController::getKp() { return kp; }
double pidController::getKd() { return kd; }
double pidController::getKi() { return ki; }
double pidController::getDt() {return dt;}
double pidController::getLastError(){return lastError;}
double pidController::getLastIntegral(){return lastIntegral;}

