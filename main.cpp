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
    ACMIChallenge acmi;
    char rawinput[15] = "255.255.252.0";
    int result = acmi.network_to_bits(rawinput);
    return 0;
}

