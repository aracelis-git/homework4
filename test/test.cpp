/** 
 * @author    Aldrin I. Racelis
 * @copyright Aldrin Racelis (c)2017
 * @file      test.cpp
 * @brief     Tests the PID Controller Class and compute function
 * 
 */

#include <gtest/gtest.h>
#include "../include/pidController.h"

TEST(controllerGains, nonNegative) {
    pidController controller(-10,-24,0,0.5);
    ASSERT_GE(controller.getKi(),0);
    ASSERT_GE(controller.getKp(),0);
    ASSERT_GE(controller.getKd(),0);
}

TEST(computeFunction, calculatesCorrectly) {
    pidController controller(1,1,0,0.5);
    EXPECT_EQ(3, controller.compute(2,1));
}