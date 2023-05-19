#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include "Fecha.h"

Fecha::Fecha()
{
    dia=0;
    mes=0;
    anio=0;
}

void Fecha::Cargar()
{
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
}

void Fecha::Mostrar()
{
    if(dia<10){
        cout << "0";
    }
    cout<<dia<<"/";
    if(mes<10){
        cout << "0";
    }
    cout <<mes<<"/";
    if(anio<10){
        cout << "000";
    }
    else{
        if(anio<100){
            cout <<"00";
        }
        else{
            if(anio<1000){
                cout << "0";
            }
        }
    }
    cout<<anio<<endl;
}
