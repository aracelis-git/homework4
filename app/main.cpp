/**
 * @author    Aldrin I. Racelis
 * @copyright Aldrin Racelis (c)2017
 * @brief			Creates a controller object based on the PID Controller class
 * 
 */

#include <iostream>
#include <pidController.h>

using std::cout; 
using std::endl;

int main() {
	pidController controller(1,1,1,.01);
	cout << controller.compute(10,15) << endl; 
	cout << controller.getKi() << controller.getKd() << controller.getKp() << endl; 
  return 0;
}
