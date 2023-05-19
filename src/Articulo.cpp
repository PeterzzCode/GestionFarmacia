#include <iostream>
#include <cstring>
using namespace std;
#include "Articulo.h"
#include "Remedio.h"
#include "Fecha.h"
Articulo::Articulo()
{
    strcpy(nombre,"vacio");

    pu=0;

}

Articulo::~Articulo()
{

}
bool restriccionID(int id){
Remedio obj;
int pos=0;
while(obj.leerArticulo(pos)){
        if(id==obj.getid()){
                cout << "EL ID SE ENCUENTRA REPETIDO: "<<endl;
            return true;
        }
    pos++;
}

return false;
}
void Articulo::cargar(){

do{
cout << "ID: #";
cin >>ID;
if(ID<=0){
    cout << "el ID tiene q ser mayor a 0"<<endl;
}
    }while(restriccionID(ID)||ID<=0);

cout << "NOMBRE: ";
cin >>nombre;
do{
cout << "PRECIO UNITARIO: ";
cin >> pu;
if(pu<=0){
    cout << "el precio unitario debe contener un numero mayor a 0"<<endl;
}
}while(pu<=0);
estado=true;
grabar();

}
void Articulo::mostrar(){


cout << "ID: #"<<ID<<endl;
cout << "NOMBRE: "<<nombre<<endl;


cout << "PRECIO UNITARIO: "<< pu<<endl;
estado=true;

}
bool Articulo::grabar(){
FILE *p;
p=fopen("articulos.dat","ab");
if(p==NULL){return false;}
bool escribio;
escribio=fwrite(this,sizeof (Articulo),1,p);
fclose(p);
return escribio;
}
bool Articulo::leerArticulo(int pos){
FILE *p;
p=fopen("articulos.dat","rb");
if(p==NULL){return false;}
fseek(p,pos*sizeof (Articulo),0);
bool leyo=fread(this, sizeof (Articulo),1,p);
fclose(p);
return leyo;

}

