#include "pracownik.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Pracownik::Pracownik(string fn,string sn,int n,float h){
name=fn;
surname=sn;
nr=n;
hours=h;
}
string Pracownik::getName(){
return name;
}
string Pracownik::getSurname(){
return surname;
}
int Pracownik::getNr(){
return nr;
}
void Pracownik::setName(string fn){
this->name=fn;
}
void Pracownik::setSurname(string sn){
this->surname=sn;
}
void Pracownik::setNr(int n){
this->nr=n;
}
void Pracownik::write(){
cout<<name<<" "<<surname<<" ("<<nr<<") "<<endl;
}
void Pracownik::read(){
cout<<"Podaj imie i nazwisko pracownika: ";
cin>>name>>surname;
}
void Pracownik::showShifts(){//pokazuje zmiany
for(int i=0;i<31;i++){
        cout<<i+1<<".\t";
    day[i].write();
    cout<<endl;
}
}
void Pracownik::daysInWork(){//liczy dni pracy
int days=0;
for(int i=0;i<31;i++){
    if(day[i].getInHour()!=100&&day[i].getInMin()!=100&&day[i].getOutHour()!=100&&day[i].getOutMin()!=100) days++;
}
cout<<days;
}
void Pracownik::countHours(){//liczenie godzin pracy
float minutes=0;
hours=0;
for(int i=0;i<31;i++){
    hours+=day[i].hoursCounter();
    minutes=day[i].minsCounter();
    minutes/=60;
    hours+=minutes;
}
cout<<hours;
}
void Pracownik::saveShiftsToFile(){//zapis zmian do plikow
    fstream personalFile;
    ostringstream nrid;
    nrid<<this->nr;
    string nridString=nrid.str();
    string fileName=this->name+"_"+this->surname+"_"+nridString+".txt";
    personalFile.open(fileName.c_str(),ios::out);
    personalFile<<this->name<<" "<<this->surname<<" "<<this->nr<<endl;
for(int i=0;i<31;i++){
        personalFile<<i+1<<".\t";
        if(day[i].getInHour()==100&&day[i].getInMin()==100&&day[i].getOutHour()==100&&day[i].getOutMin()==100)personalFile<<"Wolne\n";
        else{
        if(day[i].getInHour()<10) personalFile<<"0";
        if(day[i].getInMin()>=10) personalFile<<day[i].getInHour()<<".";
        else personalFile<<day[i].getInHour()<<".0";
        personalFile<<day[i].getInMin()<<" - ";
        if(day[i].getOutHour()<10)personalFile<<"0";
        if(day[i].getOutMin()>=10) personalFile<<day[i].getOutHour()<<".";
        else personalFile<<day[i].getOutHour()<<".0";
        personalFile<<day[i].getOutMin();
        personalFile<<endl;
}}
personalFile.close();
}
