/*
 * ACMIChallenge.cpp
 *
 *  Created on: Mar 29, 2018
 *      Author: Faron Ryan
 */

#include "ACMIChallenge.h"

using namespace std;

int ACMIChallenge::network_to_bits(char *netmask) {
	try {
		int result = check_bounds(netmask);
		return result;
	} catch (OutofBoundsError &e) {
		cout << "Error::" << e.what() << '\n';
	} catch(...){
		return -1;
	}
	return -1;
}

int ACMIChallenge::check_bounds(char *netmask){
	for(int i=0; i < 32 ; i++){
		if(strcmp(netmask,NETMASK_LOOKUP_TABLE[i]) == 0)
			return i+1; // base-1 index
	}

	throw OutofBoundsError("INVALID Netmask!");
}


