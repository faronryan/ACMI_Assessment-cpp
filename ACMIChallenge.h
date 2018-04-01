/*
 * ACMIChallenge.h
 *
 *  Created on: Mar 29, 2018
 *      Author: Faron Ryan
 */

#ifndef ACMICHALLENGE_H_
#define ACMICHALLENGE_H_

#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include <exception>

using namespace std;

class OutofBoundsError{
public:
	OutofBoundsError(string message)
		:message_( message ){}
	const string what() const { return message_; }
private:
	const string message_;
};

class ACMIChallenge {
public:
	int network_to_bits(char *netmask); 
        void find_mac_address(string filename,  
                              vector<string> &results);
        
private:
	int check_bounds(char *netmask);
        const char* NETMASK_LOOKUP_TABLE[32] =
   {"128.0.0.0","192.0.0.0","224.0.0.0","240.0.0.0",
	"248.0.0.0","252.0.0.0","254.0.0.0","255.0.0.0",
	"255.128.0.0","255.192.0.0","255.224.0.0",
	"255.240.0.0","255.248.0.0","255.252.0.0","255.254.0.0",
	"255.255.0.0","255.255.128.0","255.255.192.0",
	"255.255.224.0","255.255.240.0","255.255.248.0",
	"255.255.252.0","255.255.254.0","255.255.255.0",
	"255.255.255.128","255.255.255.192","255.255.255.224",
	"255.255.255.240","255.255.255.248","255.255.255.252",
	"255.255.255.254","255.255.255.255"};
};

#endif /* ACMICHALLENGE_H_ */
