#include "Nation.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;


//Search a country by sequencial method
void findbySequencial (string searchcounrySeq, vector<Nation>& Country){
    bool found = false;
    for(int i=0; i<Country.size(); i++){
        if(searchcounrySeq == Country[i].getCountryname()){
            cout<<"Use "<<i+1<<" comparisons to find this country by sequencial method:"<<endl;
            cout<<left<<setw(20)<<"Country" <<left<<setw(20)<<"Capital"<<left<<setw(30)<<"Language"<<"Currency"<<endl;
            cout<<Country[i].toString()<<endl;
            found = true;
        }
    }
    if(found == false)
        cout<<"We can't find this country"<<endl;
}

//Search a country by binary method
void findbyBinary(string searchcountryBi, vector<Nation> Country){
    int first = 0;
    int last = Country.size();
    int middle;
    int comparison = 0;
    bool found = false;
    while(first<=last){
        middle = (first + last) / 2;
        comparison++;
        if(searchcountryBi == Country[middle].getCountryname()){
            cout<<"Use "<<comparison<<" comparisons to find this country by sequencial method:"<<endl;
                       cout<<left<<setw(20)<<"Country" <<left<<setw(20)<<"Capital"<<left<<setw(30)<<"Language"<<"Currency"<<endl;
                       cout<<Country[middle].toString()<<endl;
                       found = true;
            break;
        }
        else if(searchcountryBi < Country[middle].getCountryname()){
            last = ((first + last) / 2) - 1;
        }
        else
            first = ((first + last) / 2) +1;
    }
}

//Find a country by a capital
void findbyCap(string searchbyCap, vector<Nation> Country   ){
    bool found = false;
    for(int i=0; i<196; i++){
        if(searchbyCap == Country[i].getCapital()){
            cout<<"Use "<<i+1<<" comparisons to find this country by sequencial method:";
                    cout<<left<<setw(20)<<"Country" <<left<<setw(20)<<"Capital"<<left<<setw(30)<<"Language"<<"Currency"<<endl;
                    cout<<Country[i].toString()<<endl;
                    found = true;
                }
            }
            if(found == false)
                cout<<"We can't find this country"<<endl;
}

void addCountry(string countryValue, vector<Nation> &Country){
    string newCapital;
    string newLanguage;
    string newCurrency;
    cout<<"Enter the capital";
    getline(cin, newCapital);
    cout<<"Enter the language";
    getline(cin, newLanguage);
    cout<<"Enter the currency";
    getline(cin, newCurrency);
    
    Nation newCountry(countryValue, newCapital, newLanguage, newCurrency);
    for(int i=0; i<Country.size(); i++){
        if(Country[0].getCountryname() > countryValue){
            Country.insert(Country.begin(), newCountry);
            break;
        }
        if(Country[i].getCountryname() < countryValue && Country[i+1].getCountryname() > countryValue){
            Country.insert(Country.begin()+i, newCountry);
            break;
        }
    }
}
     

int main(){
    vector <Nation> Country;
    string country;
    string capital;
    string language;
    string currency;
    string choice;
    string searchCountry;
    string searchbyc;
    string newCountry;
    //read a file
    ifstream rcountryFile;
    ifstream rcapitalFile;
    ifstream rlanguageFile;
    ifstream rcurrencyFile;
    //write a file
    ofstream wcountryFile;
    ofstream wcapitalFile;
    ofstream wlanguageFile;
    ofstream wcurrencyFile;
    
    //open files
    rcountryFile.open("xcountry.txt");
    if(!rcountryFile){
        cout << "Unable to open file" << endl;
               exit(1);
    }
    rcapitalFile.open("xcapital.txt");
    if(!rcapitalFile){
        cout << "Unable to open file" << endl;
               exit(1);
    }
    rlanguageFile.open("xlanguage.txt");
    if(!rlanguageFile){
        cout << "Unable to open file" << endl;
               exit(1);
    }
    rcurrencyFile.open("xcurrency.txt");
    if(!rcurrencyFile){
        cout << "Unable to open file" << endl;
               exit(1);
    }
    
    //read files
    while(getline(rcountryFile, country)){
        getline(rlanguageFile, language);
        getline(rcapitalFile, capital);
        getline(rcurrencyFile, currency);
        Nation newNation(country, capital, language, currency);
        Country.push_back(newNation);
    }
    
    //print the first 20 countries
    cout<<"     " <<left<<setw(20)<<"Country"<<left<<setw(20)<<"Capital"<<left<<setw(30)<<"Language"<<"Currency"<<endl<<endl;

    for(int i=0; i<20; i++){
        cout<<left <<setw(5)<<i+1<<Country[i].toString()
        ;
    }
   
    do{
        cout<<"How can I find a country? by name press 'N', by capital press 'C', or just exit by 'E'"<<endl;
        cin>>choice;
        if(choice == "N"){
            cout<<"Please enter the name of country"<<endl;
            cin>>searchCountry;
            findbyBinary(searchCountry, Country);
            findbySequencial(searchCountry, Country);
        }
       else if(choice == "C"){
            cout<<"Please enter the capital of country"<<endl;
            cin>>searchbyc;
            findbyCap(searchbyc, Country);
        }
           else if (choice == "E")
               break;
            
    }while(choice == "N" || choice == "C" || choice == "E");
   
    //add a new country
    cout<<"Type a new country that you want to add"<<endl;
    cin.ignore();
    getline(cin, newCountry);
    addCountry(newCountry, Country);
    cout<<"    "<<left<<setw(20)<<"Country"<<left<<setw(20)<<"Capital"<<left<<setw(30)<<"Language"<<"Currency"<<endl<<endl;

    for(int i=0; i<20; i++){
        cout<<left <<setw(5)<<i+1<<Country[i].toString()<<endl;
    }
    
    //open files for writing
   wcountryFile.open("xcountry.txt");
    if(!wcountryFile){
        cout << "Unable to open file"<<endl;
              exit(1);
    }
    wcapitalFile.open("xcapital.txt");
    if(!wcapitalFile){
        cout << "Unable to open file" << endl;
               exit(1);
    }
    wlanguageFile.open("xlanguage.txt");
    if(!wlanguageFile){
        cout << "Unable to open file" << endl;
               exit(1);
    }
    wcurrencyFile.open("xcurrency.txt");
    if(!wcurrencyFile){
        cout << "Unable to open file" << endl;
               exit(1);
    }
    
        for(int i=0; i<Country.size(); i++){
            wcountryFile<<Country[i].getCountryname();
            wcapitalFile<<Country[i].getCapital();
            wlanguageFile<<Country[i].getLanguage();
            wcurrencyFile<<Country[i].getCurrency();
        }
    rcountryFile.close();
    rcapitalFile.close();
    rlanguageFile.close();
    rcurrencyFile.close();
    wcountryFile.close();
    wcapitalFile.close();
    wlanguageFile.close();
    wcurrencyFile.close();
    
}
