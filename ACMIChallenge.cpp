/*
 * ACMIChallenge.cpp
 *
 *  Created on: Mar 29, 2018
 *      Author: Faron Ryan
 */

#include "ACMIChallenge.h"

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

HashMap* ACMIChallenge::explodereport(vector<string> rawinput) {
    
    HashMap *dumper = new HashMap();
    // Usually I would mix in python code here from the 
    // boost library however to stay true to C++ code assessment 
    // I didn't. Instead I'm using some of the boost helper functions.
    // Much longer piece of code! 
    for(std::vector<string>::iterator it = rawinput.begin(); 
            it != rawinput.end(); ++it) {
        string line = (*it);
        vector<string> lst; 
        typedef split_iterator<string::iterator> string_split_iterator;
        for(string_split_iterator It=
            make_split_iterator(line, first_finder("|", is_iequal()));
            It!=string_split_iterator(); 
            ++It)
        {
            lst.push_back(copy_range<std::string>(*It));
        }
        
        exploder_helper(lst,0,dumper);
    }
    
    return 0;
} 

void* ACMIChallenge::exploder_helper(vector<string> lst, int index, HashMap *hsh){
    
    if( index < lst.size() -1)
    {
        if(hsh->at(lst[index])){ 
            hsh->at(lst[index]) = exploder_helper(lst, index+1,
                    (HashMap*)hsh->at(lst[index]));
            return hsh;
        }
        else{
            hsh->at(lst[index]) = exploder_helper(lst, index+1,
                    new HashMap);
            return hsh;
        }
    }
    else{
        return &lst[index];
    }
    
    /*if index < (len(lst) -1):
        if hsh.has_key(str(lst[index])):
            hsh[str(lst[index])] = exploder_helper(lst, index+1, 
                                                   hsh[str(lst[index])])
            return hsh
        else:
            hsh[str(lst[index])] = exploder_helper(lst, index+1, {})
            return hsh        
    else:
        return lst[index]
     */ 
}