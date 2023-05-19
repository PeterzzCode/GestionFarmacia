#include <iostream>
#include <cstring>
using namespace std;
#include "Venta.h"
#include "Remedio.h"
#include "Perfumeria.h"
#include "Fecha.h"
#include "Cliente.h"
Venta::Venta()
{
id=0;
 DNI=0;

}

Venta::~Venta()
{

}
float BuscarPUxID(int);
int BuscarID(int id){
Remedio obj;
int pos=0;
while(obj.Leer(pos)){
        if(id==obj.getid()){

            return pos;
        }
    pos++;
}
return -1;
}
int BuscarID_perf(int id){
Perfumeria obj;
int pos=0;
while(obj.Leer(pos)){
        if(id==obj.getid()){

            return pos;
        }
    pos++;
}

return -1;
}


bool cambioStock(int pos_med, int ventas){
if(pos_med>=0){
        Remedio obj;

     FILE *p;
     p=fopen("remedios.dat", "rb+");
     if(p==NULL){return false;}
      int pos=0;
     while(obj.Leer(pos)){
            if(pos==pos_med){
     obj.setstock(obj.getstock()-ventas);
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
bool cambioStockPerf(int pos_perf, int ventas){
if(pos_perf>=0){
        Perfumeria obj;

     FILE *p;
     p=fopen("perfumes.dat", "rb+");
     if(p==NULL){return false;}
    int pos=0;
     while(obj.Leer(pos)){
            if(pos==pos_perf){
     obj.setstock(obj.getstock()-ventas);
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

int BuscarDNI(int dni){
Cliente obj;
int pos=0;
while(obj.leer(pos)){
        if(dni==obj.getdni()){

            return pos;
        }
    pos++;
}
cout << "EL DNI NO COINCIDE CON NINGUN CLIENTE: "<<endl;
return -1;
}
bool restriccionIDventa(int id){
Venta obj;
int pos=0;
if(id<=0){return true;}
while(obj.leer(pos)){
        if(id==obj.getid()){
                cout << "EL ID SE ENCUENTRA REPETIDO: "<<endl;
            return true;
        }
    pos++;
}

return false;
}
int restriccionStockMed(int id, int ventas){
    int pos=0;
    Remedio obj;
while(obj.Leer(pos)){
        if(id==obj.getid()){
                if(obj.getstock()==0){
                    return -1;
                }
            if(obj.getstock()>=ventas){
                return 1;
            }

        }
    pos++;
}
return 0;
}
bool restriccionReceta(int id, int dni){
Remedio obj;
Cliente reg;
bool e=false;
int pos=0;
int p;
while(obj.Leer(pos)){
        p=0;
        if(obj.getid()==id){
       if(obj.getlibre()==false){
        e=true;
       }
        }
        pos++;
}
 while(reg.leer(p)){
                if(reg.getdni()==dni){
                        if(e==true&&reg.getestado()==false){
                            return false;
                }

        }
        p++;
 }
return true;

}
int restriccionStockPerf(int id, int ventas){
    int pos=0;
    Perfumeria obj;
while(obj.Leer(pos)){
        if(id==obj.getid()){
                if(obj.getstock()==0){
                    return -1;
                }
            if(obj.getstock()>=ventas){
                return 1;
            }

        }
    pos++;
}
return 0;
}
bool Venta::cargar(){
    float pu;
    bool receta;
    int pos;
    int pos2;
    int p;
    int e;
    do{
cout << "ID DE VENTA: ";
cin >>id;
if(id<=0){
    cout << "el ID tiene q ser mayor a 0"<<endl;
}
    }while(restriccionIDventa(id));
do{
cout << "ID DE ARTICULO: ";
cin >>id_art;
pos=BuscarID(id_art);
p=BuscarID_perf(id_art);
if(pos==-1&&p==-1){
    cout << "EL ID NO EXISTE"<<endl;
}

}while((pos==-1&&p==-1));
do{
cout << "DNI: ";
cin >> DNI;
pos2=BuscarDNI(DNI);
}while(pos2==-1);
do{
cout << "CANTIDAD DE VENTAS: ";
cin >> cant_vent;
if(pos>=0){
        e=restriccionStockMed(id_art,cant_vent);
       receta=restriccionReceta(id_art,DNI);
        if(receta==false){
                cout << "el medicamento necesita receta"<<endl;
        system("pause");
                return false;}
}

if(p>=0){e=restriccionStockPerf(id_art,cant_vent);}
if(e<=0){
    cout << "el articulo no cuenta con el stock necesario"<<endl;
    if(e==-1){return false;}

}
}while(e==0||cant_vent<=0);
cout << "MEDIO DE PAGO (e/t): ";
cin >> tipo_pago;
cout << "FECHA VENTA: "<<endl;
venti.Cargar();
estado=true;
cambioStock(pos,cant_vent);
cambioStockPerf(p,cant_vent);
pu=BuscarPUxID(id_art);
importe=pu*cant_vent;
return true;
}
void Venta::mostrar(){
cout << "ID DE VENTA: "<<id<<endl;
cout << "ID DE ARTICULO: " << id_art<<endl;
cout << "CANTIDAD DE VENTAS: "<< cant_vent<<endl;
cout << "DNI: "<<DNI<<endl;
cout << "IMPORTE: "<<importe<<endl;
switch(tipo_pago){
case 'e':
    cout << "MEDIO DE PAGO: EFECTIVO"<<endl;
    break;
case 't':
    cout << "MEDIO DE PAGO: TARJETA"<<endl;

}
cout << "FECHA VENTA: ";
venti.Mostrar();
cout <<endl;

}
bool Venta::grabar(){
FILE *p;
p=fopen("ventas.dat","ab");
if(p==NULL){return false;}
bool escribio;
escribio=fwrite(this,sizeof (Venta),1,p);
fclose(p);
return escribio;
}
bool Venta::leer(int pos){
FILE *p;
p=fopen("ventas.dat","rb");
if(p==NULL){return false;}
fseek(p,pos*sizeof (Venta),0);
bool leyo=fread(this, sizeof (Venta),1,p);
fclose(p);
return leyo;

}
