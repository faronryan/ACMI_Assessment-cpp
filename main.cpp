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
#include "CustomDict.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Main function is used for debugging via IDE
    string rawinput = "deer => 'park', foo => 'bar', this => 'that'";
    CustomDict cd(rawinput); 
    cout << cd.get("deer") << endl; 
    
    return 0;
}

