/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest1.cpp
 * Author: faronr
 *
 * Created on March 29, 2018, 11:14 AM
 */

#include <stdlib.h>
#include <iostream>
#include "ACMIChallenge.h"
/*
 * C++ Test Suite
 */

void testCidrBitsPass(){
    ACMIChallenge acmi;
    char rawinput[15] = "255.255.252.0";
    int result = acmi.network_to_bits(rawinput);
    
    int expected = 22;
    if (result != expected) {
        std::cout << "%TEST_FAILED% time=0 testname=testCidrBitsPass (acmichallengetest) message=error message sample" << std::endl;
    } 
}

void testCidrBitsFailOutofBoundsError(){
    ACMIChallenge acmi;
    char rawinput[15] = "255.1.2.3";
    int result = acmi.network_to_bits(rawinput);
    
    int expected = -1;
    if (result != expected) {
        std::cout << "%TEST_FAILED% time=0 testname=testCidrBitsFailOutofBoundsError (acmichallengetest) message=error message sample" << std::endl;
    } 
}
    
int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% acmichallengetest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testCidrBitsPass (acmichallengetest)" << std::endl;
    testCidrBitsPass();
    std::cout << "%TEST_FINISHED% time=0 testCidrBitsPass (acmichallengetest)" << std::endl;
    
    std::cout << "%TEST_STARTED% testCidrBitsFailOutofBoundsError (acmichallengetest)" << std::endl;
    testCidrBitsFailOutofBoundsError();
    std::cout << "%TEST_FINISHED% time=0 testCidrBitsFailOutofBoundsError (acmichallengetest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}
