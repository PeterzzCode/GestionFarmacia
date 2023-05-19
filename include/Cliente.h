#ifndef CLIENTE_H
#define CLIENTE_H
#include "Fecha.h"


class Cliente
{
    public:
        Cliente();
        ~Cliente();
        bool grabar();
        bool leer(int);



void setnombre(char *c){strcpy(nombre,c);}
void setapellido (char *a){strcpy(apellido,a);}
void setdni(int dni){DNI=dni;}
void setdireccion (int num){direccion=num;}
void setcalle(char *c){strcpy(calle,c);}
void setlocalidad (char *l){strcpy(localidad,l);}
void setestado(bool e){estado=e;}
void setNacimiento (Fecha f){nacimiento=f;}


char *getnombre(){return nombre;}
char *getapellido (){return apellido;}
int getdni(){return DNI;}
int getdireccion (){return direccion;}
char *getcalle(){return calle;}
char *getlocalidad (char *l){return localidad;}
bool getestado(){return estado;}
Fecha getNacimiento(){return nacimiento;}
void cargar();
void mostrar();



    protected:

    private:
       char nombre[30];
       char apellido[30];
       int DNI;
       int direccion;
       char calle[40];
       char localidad[40];
       bool estado;
       Fecha nacimiento;
};

#endif // CLIENTE_H
