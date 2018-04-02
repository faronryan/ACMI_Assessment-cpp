/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   acmichallengetest.cpp
 * Author: Faron Ryan
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
        std::cout << "%TEST_FAILED% time=0 testname=testCidrBitsPass (acmichallengetest) message=netmaskt to bits failed!" << std::endl;
    } 
}

void testCidrBitsFailOutofBoundsError(){
    ACMIChallenge acmi;
    char rawinput[15] = "255.1.2.3";
    int result = acmi.network_to_bits(rawinput);
    
    int expected = -1;
    if (result != expected) {
        std::cout << "%TEST_FAILED% time=0 testname=testCidrBitsFailOutofBoundsError (acmichallengetest) message=netmask out of bounds!" << std::endl;
    } 
}

void testFindMacAddresFile1(){
    // since this a C++ challenge I'm sticking to C++
    // However, in a production setting I would call the
    // boost libraries (python) to loop through the directory 
    ACMIChallenge acmi; 
    string file_name = "../inputs/inputs01.txt"; // using 1 file in test case
    
    vector<string> results;
    acmi.find_mac_address(file_name, results);
    std::string expected = "File:inputs/inputs01.txt line[0]  mac_address= AA:BB:CC:DD:EE:FF";
    if(expected.compare(results.at(0)) != 0)
    {
        std::cout << "%TEST_FAILED% time=0 testname=testFindMacAddresFile1 (acmichallengetest)";
        std::cout << "message = expected: " + expected << endl;
    }
    
    expected = "File:inputs/inputs01.txt line[2]  mac_address= BA:BC:CC:DD:EE:FF";
    if(expected.compare(results.at(2)) != 0)
    {
        std::cout << "%TEST_FAILED% time=0 testname=testFindMacAddresFile1 (acmichallengetest)";
        std::cout << "message = expected:" + expected << endl;
    }
} 

void testNestedHashConstructor(){
    ACMIChallenge acmi; 
    
    vector<string> rawinput;
    rawinput.push_back("app1|server1|uptime|5");
    rawinput.push_back("app1|server1|loadavg|0.01 0.02 0.03");
    rawinput.push_back("app1|server1|conn1|state|up");
    rawinput.push_back("app1|server2|uptime|10");
    rawinput.push_back("app1|server2|loadavg|0.11 0.22 0.33");
    rawinput.push_back("app1|server2|conn1|state|down");
    rawinput.push_back("app1|running|true");
    HashMap *results = acmi.explodereport(rawinput); 
    HashMap *expected = any_cast<HashMap*>(results->at("app1"));
    BOOST_FOREACH(HashMap::value_type h, *(expected)){
        if(h.first == "server1" || h.first == "server2" || h.first == "running")
            continue; 
        {
            std::cout << "%TEST_FAILED% time=0 testname=testNestedHashConstructor (acmichallengetest)";
            std::cout << "message = map does not contain" + h.first << endl;
            break;
        }
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

    std::cout << "%TEST_STARTED% testFindMacAddresFile1 (acmichallengetest)" << std::endl;
    //testFindMacAddresFile1();
    std::cout << "%TEST_FINISHED% time=0 testFindMacAddresFile1 (acmichallengetest)" << std::endl;

    std::cout << "%TEST_STARTED% testNestedHashConstructor (acmichallengetest)" << std::endl;
    testNestedHashConstructor();
    std::cout << "%TEST_FINISHED% time=0 testNestedHashConstructor (acmichallengetest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}