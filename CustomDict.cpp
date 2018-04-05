/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "CustomDict.h"
using namespace std;
using namespace boost;

// Note: Just using strings (easy to test with) as 
// the main input. Similar to what I did in the Python prototype.
// Like Python, C++ also suports variable number of params.
CustomDict::CustomDict(string dict){
     
    string regex_str = "[\\s]*[a-z0-9]+[\\s]*=>[\\s]*'[a-z0-9]+'[\\s]*";
    static regex initial_dict(regex_str,regex_constants::icase);
    sregex_iterator it(dict.begin(), dict.end(), initial_dict); 
    sregex_iterator it_end; 
    while(it != it_end) {  
        string entry = it->str();
        string key = entry.substr(0,entry.find("="));
        string value = entry.substr(entry.find(">")+1,entry.size()-1);
        boost::trim(key);
        boost::trim(value);
        boost::replace_all(value,"'", ""); 
        internal[key]=value;
        ++it;  
    }   
}

string CustomDict::get(string key) {
    
    return internal[key];
}

void CustomDict::add(string key_value) {
    string key = key_value.substr(0,key_value.find("="));
    string value = key_value.substr(key_value.find(">")+1,key_value.size()-1);
    // Just using boost for fun!
    boost::trim(key);
    boost::trim(value);
    boost::replace_all(value,"'", ""); 
    internal[key]=value;
    history[key] = "ADD "+key+" = "+value;  
}

void CustomDict::delete_(string key) {
    internal.erase(key);
    history[key] = "DELETE "+key;
}

void CustomDict::modify(string key_value) {
    // Could have packed below 5 lines in another 
    // function since I've used it 3 times in total
    string key = key_value.substr(0,key_value.find("="));
    string value = key_value.substr(key_value.find(">")+1,key_value.size()-1);
    boost::trim(key);
    boost::trim(value);
    boost::replace_all(value,"'", ""); 
    internal[key]=value;
    history[key] = "MODIFY "+key+" = "+value;
}

void CustomDict::deltas() {
    
    std::map<string, string>::iterator it;
    for(it = history.begin(); it != history.end(); it++){
        cout << it->second << endl;
    }
}