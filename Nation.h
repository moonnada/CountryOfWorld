
#include <iostream>
#include <string>
using namespace std;

class Nation{
    private :
    string countryname;
    string capital;
    string languages;
    string currency;
    
    public :
    string getCountryname();
    string getCapital();
    string getLanguage();
    string getCurrency();
    void setCountryname(string);
    void setCapital(string);
    void setLanguage(string);
    void setCurrency(string);
    Nation();
    Nation(string, string, string, string);
    string toString();
};
