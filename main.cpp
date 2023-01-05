#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include "pracownik.h"
#include <fstream>
using namespace std;
vector <Pracownik*> p;
int id=1;
fstream lista;

void returnMain();
void addPerson(); //dodawanie pracownika
void showShift(); //wyswietlanie zmian
void listPerson(); //wyswietlanie listy pracownikow
void deleteShift();
void modifyPerson(Pracownik* temp){                 //modyfikowanie danych pracownika
    temp->read();
    system("cls");
    cout<<"Pomyslnie zmodyfikowano pracownika.\n\n"<<endl<<endl;
    listPerson();
}
void addShift(Pracownik* temp){                 //dodawanie zmiany pracownika
int d; //dzien do wyboru
do{
cout<<"\n\nPodaj dzien do zmiany: ";
cin>>d;
}while(d>31||d<1);
temp->day[d-1].read();
system("cls");
}
void deleteShift(Pracownik* temp){
int d; //dzien do wyboru
cout<<"\n\nPodaj dzien do usuniecia zmiany: ";
cin>>d;
temp->day[d-1].setInHour(100);
temp->day[d-1].setInMin(100);
temp->day[d-1].setOutHour(100);
temp->day[d-1].setOutMin(100);
system("cls");
}
void showShift(Pracownik* temp){
    cout<<endl;
    temp->write();
    cout<<endl;
temp->showShifts();
cout<<"\nSuma godzin: ";
temp->countHours();
cout<<"\nDni pracy: ";
temp->daysInWork();
temp->saveShiftsToFile();
}
void listPerson(){
    int id;
    int sizeOfObject=0;
    Pracownik* temp;
    int inc=1;
    unsigned char menu;
    cout<<endl;
    for(vector<Pracownik*>::iterator i=p.begin();i!=p.end();i++){
    temp=*i;
    cout<<inc<<". ";
    temp->write();
    inc++;
    sizeOfObject++;
    }
    cout<<"\n\n\n1. Modyfikuj dane pracownika\n2. Pokaz zmiany pracownika\n3. Dodaj pracownikowi zmiane\n4. Usun pracownikowi zmiane\n5. Wroc do menu\n";
    menu= _getch();
    if(menu=='1'){
        cout<<"\n--------------------\nPodaj id modyfikowanego pracownika: ";
        do{
        cin>>id;
        }while(id>sizeOfObject);
    modifyPerson(p[id-1]);
    }
    else if(menu=='5'){system("cls");returnMain();}

    else if(menu=='4'){
        cout<<"\n--------------------\nPodaj id pracownika: ";
        do{
        cin>>id;
        }while(id>sizeOfObject);
        system("cls");
        showShift(p[id-1]);
        deleteShift(p[id-1]);
        listPerson();
        }

    else if(menu=='3'){
        cout<<"\n--------------------\nPodaj id pracownika: ";
        do{
        cin>>id;
        }while(id>sizeOfObject);
        system("cls");
        showShift(p[id-1]);
        addShift(p[id-1]);
        listPerson();
        }
    else if(menu=='2'){
        cout<<"\n--------------------\nPodaj id pracownika: ";
        do{
        cin>>id;
        }while(id>sizeOfObject);
        system("cls");
            do{
    showShift(p[id-1]);
    cout<<"\n\n1. Wroc";
    menu= _getch();
    if(menu=='1'){
        system("cls");
        listPerson();
    }
    else{
        system("cls");
    }}while(menu!='1');
    }
    else listPerson();

}
void addPerson(){
    unsigned char menu;
    do{
    Pracownik  *temp=new Pracownik;
    p.push_back(temp);
    temp->read();
    temp->setNr(id);
    id++;
    lista<<temp->getName()<<"\t"<<temp->getSurname()<<"\t"<<temp->getNr()<<endl;
    system("cls");
    cout<<"Pomyslnie dodano  nowego pracownika.\n\n1. Dodaj kolejnego pracownika\n2. Wroc do menu"<<endl<<endl;


        menu= _getch();
        if(menu=='1') {system("cls");}
        else if(menu=='2'){system("cls");lista.close();returnMain();break;}
    }while(menu=='1');
}

int main(){
    unsigned char menu='0';
    do{
    returnMain();
    menu= _getch();
    if(menu=='1') {system("cls");lista.open("lista.txt",ios::out);addPerson();system("cls");}
    else if (menu=='2'){system("cls");listPerson();system("cls");}
    else if(menu=='3'){return 0;}
    else system("cls");
    }while(menu!='3');
    return 0;
}
void returnMain(){
cout<<"--- MENU ---"<<endl;
cout<<"1. Dodaj pracownika\n2. Lista pracownikow\n3. Wyjscie\n";
}
