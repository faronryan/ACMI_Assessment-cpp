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

void ACMIChallenge::find_mac_address(string filename,  
                                     vector<string> &results) {
    try {
        std::ifstream infile( filename );
        string line;
        string regex_str = "[\\s]+[abcdef0123456789]{2}:[abcdef0123456789]{2}:[abcdef0123456789]{2}:[abcdef0123456789]{2}:[abcdef0123456789]{2}:[abcdef0123456789]{2}"; 
        static regex address(regex_str,regex_constants::icase); 
        int i=0;
        while (std::getline(infile, line))
        {
            sregex_iterator it(line.begin(), line.end(), address); 
            sregex_iterator it_end; 
            while(it != it_end) { 
                string found = "File:"+filename+" line["+std::to_string(i)+"] "+ 
                        " mac_address="+it->str();
                results.push_back(found);
                ++it;  
            }
            i++;
        }
        
    }catch(const ifstream::failure& e){
        cout << e.what();
    }catch(std::exception e) {
        cout << e.what();
    } catch(...){
       cout << "Something bad happened, alert Sys Admin!" << endl;
    }    
}
