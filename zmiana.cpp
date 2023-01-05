#include "zmiana.h"
#include <iostream>

Zmiana::Zmiana(int inH,int inM, int outH, int outM, int h){
inHour=inH;
inMin=inM;
outHour=outH;
outMin=outM;
hours=h;
}
int Zmiana::getInHour()const{
return inHour;
}
int Zmiana::getInMin()const{
return inMin;
}
int Zmiana::getOutHour()const{
return outHour;
}
int Zmiana::getOutMin()const{
return outMin;
}
void Zmiana::setInHour(int inH){
this->inHour=inH;
}
void Zmiana::setInMin(int inM){
this->inMin=inM;
}
void Zmiana::setOutHour(int outH){
this->outHour=outH;
}
void Zmiana::setOutMin(int outM){
this->outMin=outM;
}
void Zmiana::read(){
    do{
std::cout<<"Podaj godzine rozpoczecia zmiany (Godzina  Minuta): ";
std::cin>>inHour>>inMin;
    }while(inHour<0||inHour>23||inMin<0||inMin>60);
    do{
std::cout<<"Podaj godzine zakonczenia zmiany (Godzina  Minuta): ";
std::cin>>outHour>>outMin;
    }while(outHour<0||outHour>23||outMin<0||outMin>60);
}
void Zmiana::write(){
    if(inHour==100&&inMin==100&&outHour==100&&outMin==100)std::cout<<"Wolne";
    else{
        if(inHour<10) std::cout<<"0";
        if(inMin>=10) std::cout<<inHour<<".";
        else std::cout<<inHour<<".0";
        std::cout<<inMin<<" - ";
        if(outHour<10)std::cout<<"0";
        if(outMin>=10) std::cout<<outHour<<".";
        else std::cout<<outHour<<".0";
        std::cout<<outMin;
}}
int Zmiana::hoursCounter(){
if(inHour>outHour) return 24-inHour+outHour;
else return outHour-inHour;
}
int Zmiana::minsCounter(){
if(inMin>outMin) return inMin-outMin-60;
else return outMin-inMin;
}
