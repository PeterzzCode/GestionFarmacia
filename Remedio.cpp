#include <iostream>
#include <cstring>
using namespace std;
#include "Remedio.h"
#include "Fecha.h"
int BuscarID(int);
Remedio::Remedio()
{
    tipo=1;
    strcpy(nombre,"vacio");
    stock=0;

}

Remedio::~Remedio()
{
    //dtor
}


void Remedio::Cargar(){
    char c;
    Articulo::cargar();
    cout << "TIPO DE MEDICAMENTO: ";
    cin >> tipo;
    cout << "TIPO DE CONSUMO: ";
    cin >> tipo_consumo;
    cout << "STOCK: ";
    cin >>stock;
cout << "¿ES DE VENTA LIBRE?(s/n)";
cin>> c;
switch(c){
case 's':
    vent_libre=true;
    break;
case 'n':
    vent_libre=false;
    break;
default:
    vent_libre=false;
    break;
}




}

void Remedio::Mostrar(){
    cout <<endl;
      Articulo::mostrar();
      cout << "TIPO DE MEDICAMENTO: "<<tipo<<endl;
    cout << "TIPO DE CONSUMO: "<<tipo_consumo<<endl;
      cout << "STOCK: "<<stock<<endl;
if(vent_libre==false){
        cout << "DISPONIBLE BAJO RECETA"<<endl;
    }
    else{
        cout << "VENTA LIBRE" <<endl;
    }

}


bool Remedio::Grabar(){
FILE *p;
p=fopen("remedios.dat","ab");
if(p==NULL){return false;}

bool escribio;
escribio=fwrite(this,sizeof (Remedio),1,p);
fclose(p);
return escribio;
}
bool Remedio::Leer(int pos){
FILE *p;
p=fopen("remedios.dat","rb");
if(p==NULL){return false;}
fseek(p,pos*sizeof (Remedio),0);
bool leyo=fread(this, sizeof (Remedio),1,p);
fclose(p);
return leyo;


}

bool ModificarMed(int pos_med, int suma){
if(pos_med>=0){
        Remedio obj;

     FILE *p;
     p=fopen("remedios.dat", "rb+");
     if(p==NULL){return false;}
    int pos=0;
     while(obj.Leer(pos)){
            if(pos==pos_med){
     obj.setstock(obj.getstock()+suma);
     fseek(p, pos_med*sizeof obj, 0);
     fwrite(&obj, sizeof obj, 1, p);
     fseek(p,0,2);
            }
            pos++;
     }
     fclose(p);
     return true;

}
return false;
}
void suma_stockmed(){
int id;
int pos;
int ing;
do{
cout << "INGRESE ID A MODIFICAR: ";
cin >> id;
pos=BuscarID(id);
if (pos==-1){
    cout << "no existe el id"<<endl;
}
}while(pos==-1);
do{
cout << "INGRESOS DE ARTICULO: ";
cin >> ing;
if(ing<=0){
    cout << "cantidad erronea, los ingresos tienen que ser mayores a 0"<<endl;
}
}while(ing<0);
if(ModificarMed(pos,ing)){cout << "se modifico el stock"<<endl;}

}
