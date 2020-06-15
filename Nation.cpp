
#include "Nation.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream> 
using namespace std;

string Nation::getCountryname(){
    return countryname;
}
string Nation::getCapital(){
    return capital;
}
string Nation::getLanguage(){
    return languages;
}
string Nation::getCurrency(){
    return currency;
}
void Nation::setCountryname(string countryValue){
    countryname = countryValue;
}
void Nation::setCapital(string capitalValue){
    capital = capitalValue;
}
void Nation::setLanguage(string languageValue){
    languages = languageValue;
}
void Nation::setCurrency(string currencyValue){
    currency = currencyValue;
}
Nation::Nation(string n, string c, string l, string u){
    countryname = n;
    capital = c;
    languages = l;
    currency = u;
}

string Nation::toString(){
    ostringstream sout;
    sout<<left<<setw(20)<<getCountryname()<<left<<setw(20)<<getCapital()<<left<<setw(30)<<getLanguage()<<getCurrency();
    return sout.str();
}

