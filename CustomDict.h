/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CustomDict.h
 * Author: faronr
 *
 * Created on April 2, 2018, 5:31 PM
 */

#ifndef CUSTOMDICT_H
#define CUSTOMDICT_H

#include <string.h>
#include <map>
#include <regex>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/trim.hpp>

using namespace std;

class CustomDict{
public:
    CustomDict(string dict);
    string get(string key);
    void add(string key_value);
    void delete_(string key); // Note: delete is a reserved word in C++
    void modify(string key_value);
    void deltas();
    
private:
    std::map<string, string> internal;
    std::map<string, string> history;
};
    

#endif /* CUSTOMDICT_H */

