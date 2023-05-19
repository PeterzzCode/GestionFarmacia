#include<iostream>
#include <cstring>
using namespace std;
#include "Perfumeria.h"
#include "Fecha.h"
int BuscarID(int);
int BuscarID_perf(int);
Perfumeria::Perfumeria()
{
    strcpy(marca,"vacio");
    tipoProd=3;
    Genero=4;
    litros=0;
    stock=0;
}

Perfumeria::~Perfumeria()
{

}
void Perfumeria::Cargar(){
    Articulo::cargar();
    cout << "MARCA: ";
    cin >>marca;
    cout << "TIPO DE PRODUCTO: ";
    cin >>tipoProd;
    cout << "GENERO: ";
    cin >>Genero;
    cout << "CONTENIDO: ";
    cin >>litros;
    cout << "STOCK: ";
    cin >>stock;

}
void Perfumeria::Mostrar(){
      Articulo::mostrar();

    cout << "MARCA: "<<marca<<endl;



switch(tipoProd){
    case 1:
        cout << "TIPO DE PRODUCTO: SHAMPOO"<<endl;
        break;
    case 2:
        cout << "TIPO DE PRODUCTO: ACONDICIONADOR"<< endl;
        break;
    case 3:
        cout << "TIPO DE PRODUCTO: PERFUME"<<endl;
        break;
    case 4:
        cout << "TIPO DE PRODUCTO: OTRO PRODUCTO"<<endl;
        break;
    }
switch(Genero){
    case 1:
        cout << "Genero: HOMBRE"<<endl;
        break;
    case 2:
        cout << "Genero: MUJER"<< endl;
        break;
    case 3:
        cout << "Genero: NINIO"<<endl;
        break;
    case 4:
        cout << "Genero: UNISEX"<<endl;
        break;
    }
    cout << "CONTENIDO: "<<litros<<endl;
    cout << "STOCK: "<<stock<<endl;

}
bool Perfumeria::Grabar(){
FILE *p;
p=fopen("perfumes.dat","ab");
if(p==NULL){return false;}

bool escribio;
escribio=fwrite(this,sizeof (Perfumeria),1,p);
fclose(p);
return escribio;
}
bool Perfumeria::Leer(int pos){
FILE *p;
p=fopen("perfumes.dat","rb");
if(p==NULL){return false;}
fseek(p,pos*sizeof (Perfumeria),0);
bool leyo=fread(this, sizeof (Perfumeria),1,p);
fclose(p);
return leyo;


}
bool ModificarPerf(int pos_perf, int suma){
if(pos_perf>=0){
        Perfumeria obj;

     FILE *p;
     p=fopen("perfumes.dat", "rb+");
     if(p==NULL){return false;}
    int pos=0;
     while(obj.Leer(pos)){
            if(pos==pos_perf){
     obj.setstock(obj.getstock()+suma);
     fseek(p, pos_perf*sizeof obj, 0);
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
void suma_stock(){
int id;
int pos;
int ing;
do{
cout << "INGRESE ID A MODIFICAR: ";
cin >> id;
pos=BuscarID_perf(id);
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
if(ModificarPerf(pos,ing)){cout << "se modifico el stock"<<endl;}

}

