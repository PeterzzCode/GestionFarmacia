#include <iostream>
#include <cstring>
using namespace std;
#include "Cliente.h"
#include "Fecha.h"
int BuscarDNI(int);
Cliente::Cliente()
{
    //ctor
}

Cliente::~Cliente()
{
    //dtor
}
bool ModificarNombre(int pos2, char *n){
if(pos2>=0){
        Cliente obj;

     FILE *p;
     p=fopen("clientes.dat", "rb+");
     if(p==NULL){return false;}
    int pos=0;
     while(obj.leer(pos)){
            if(pos==pos2){
     obj.setnombre(n);
     fseek(p, pos2*sizeof obj, 0);
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
void cambioNombre(){
int dni;
int pos;
char nombre[30];
do{
cout << "INGRESE DNI DEL CLIENTE A MODIFICAR: ";
cin >> dni;
pos=BuscarDNI(dni);
if (pos==-1){
    cout << "no existe el dni"<<endl;
}
}while(pos==-1);

cout << "INGRESE UN NOMBRE: ";
cin >> nombre;


if(ModificarNombre(pos,nombre)){cout << "se modifico el nombre"<<endl;}

}
bool Cliente::grabar(){
FILE *p;
p=fopen("clientes.dat","ab");
if(p==NULL){return false;}
bool escribio;
escribio=fwrite(this,sizeof (Cliente),1,p);
fclose(p);
return escribio;
}
bool Cliente::leer(int pos){
FILE *p;
p=fopen("clientes.dat","rb");
if(p==NULL){return false;}
fseek(p,pos*sizeof (Cliente),0);
bool leyo=fread(this, sizeof (Cliente),1,p);
fclose(p);
return leyo;


}
bool restriccionDNI(int dni){
Cliente obj;
int pos=0;
while(obj.leer(pos)){
        if(dni==obj.getdni()){
                cout << "EL DNI SE ENCUENTRA REPETIDO: "<<endl;
            return true;
        }
    pos++;
}

return false;
}

void Cliente::cargar(){
     char rec;
    cout << "NOMBRE: ";
    cin >> nombre;
    cout << "APELLIDO: ";
    cin >> apellido;
    do{
    cout << "DNI: ";
    cin >> DNI;
    }while(restriccionDNI(DNI));
    cout << "DIRECCION: ";
    cin >> direccion;
    cout << "CALLE: ";
    cin >> calle;
    cout << "LOCALIDAD: ";
    cin >> localidad;
    cout << "FECHA NACIMIENTO: "<<endl;
    nacimiento.Cargar();
    cout << "TIENE RECETA (s/n): ";
    cin >> rec;
    if(rec=='s'){
    estado=true;
    }
    else{
        estado=false;
    }
}
void Cliente::mostrar(){

    cout << "NOMBRE: " << nombre<<endl;
    cout << "APELLIDO: " << apellido<<endl;
    cout << "DNI: " << DNI<<endl;
    cout << "DIRECCION: " << direccion<<endl;
    cout << "CALLE: " << calle<<endl;
    cout << "LOCALIDAD: "<< localidad<<endl;
    cout << "FECHA NACIMIENTO: ";
    nacimiento.Mostrar();
    if(estado){
        cout << "TIENE RECETA."<<endl;
    }
    else{
        cout << "NO TIENE RECETA."<<endl;
    }
    cout<<endl;

}
