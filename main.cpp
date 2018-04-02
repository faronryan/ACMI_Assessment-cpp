/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: faronr
 *
 * Created on March 29, 2018, 11:11 AM
 */

#include "ACMIChallenge.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Main function is used for debugging via IDE
    ACMIChallenge acmi; 
    string file_name = "inputs/inputs01.txt"; // using 1 file in test case
    
    vector<string> rawinput;
    rawinput.push_back("app1|server1|uptime|5");
    rawinput.push_back("app1|server1|loadavg|0.01 0.02 0.03");
    rawinput.push_back("app1|server1|conn1|state|up");
    rawinput.push_back("app1|server2|uptime|10");
    rawinput.push_back("app1|server2|loadavg|0.11 0.22 0.33");
    rawinput.push_back("app1|server2|conn1|state|down");
    rawinput.push_back("app1|running|true");
    acmi.explodereport(rawinput); 
    return 0;
}

