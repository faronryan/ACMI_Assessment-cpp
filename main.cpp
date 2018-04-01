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
    
    vector<string> results;
    acmi.find_mac_address(file_name, results);
    for(std::vector<string>::iterator it = results.begin(); it != results.end(); ++it) {
        cout << (*it) << endl;
    } 
    return 0;
}

