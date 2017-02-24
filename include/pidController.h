/** 
 * @author    Aldrin I. Racelis
 * @copyright Aldrin Racelis (c)2017
 * @file      pidController.h
 * @brief     Header for the PID Controller Class
 * 
 */

#ifndef pidController_H
#define pidController_H

class pidController { 
	
private:
	
	double kp, kd, ki, dt, lastError, lastIntegral;
	
public: 
	
	pidController(double kp, double kd, double ki, double dt);
	~pidController();
	double compute(double desiredVelocity, double actualVelocity); 
	double getKp();
	double getKd();
	double getKi();
	double getDt();
	double getLastError();
	double getLastIntegral();
};

#endif
