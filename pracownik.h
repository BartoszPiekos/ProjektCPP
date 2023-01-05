#include <iostream>
#include "zmiana.h"
class Pracownik{
    private:
std::string name, surname;
int nr;
public:
Zmiana day[31];
float hours;
    Pracownik(std::string="N",std::string="N",int=0,float=0);
    void write();
    void read();
    std::string getName();
    std::string getSurname();
    int getNr();
    void setName(std::string fn);
    void setSurname(std::string sn);
    void setNr(int n);
    void showShifts();
    void saveShiftsToFile();
    void countHours();
    void daysInWork();
};
