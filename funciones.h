#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "rlutil.h"
using namespace rlutil;

void DrawBox(){

    //esquina superior izquierda
	rlutil::locate(40, 8);
	cout << (char)201;

	//linea superior
	for (int i = 0; i < 31; i++)
	{
		cout << (char)205;
	}

	//esquina inferior izquierda
	rlutil::locate(40, 20);
	cout << (char)200;

	//linea inferior
	for (int i = 0; i < 31; i++)
	{
		cout << (char)205;
	}

	//linea izquierda
	for (int i = 0; i < 11; i++)
	{
		rlutil::locate(40, 9 + i);
		cout << (char)186;
	}
	//linea derecha
	for (int i = 0; i < 11; i++)
	{
		rlutil::locate(72, 9 + i);
		cout << (char)186;
	}
	//esquina superior derecha
	rlutil::locate(72, 8);
	cout << (char)187;

	//esquina inferior derecha
	rlutil::locate(72, 20);
	cout << (char)188;



	rlutil::locate(41, 17);
	for (int i = 0; i < 31; i++)
	{
		cout << (char)205;
	}

	rlutil::locate(40, 17);
	cout << (char)204;

	rlutil::locate(72, 17);
	cout << (char)185;


}


void DrawBoxInformes(){
  //esquina superior izquierda
	rlutil::locate(40, 8);
	cout << (char)201;

	//linea superior
	for (int i = 0; i < 50; i++)
	{
		cout << (char)205;
	}

	//esquina inferior izquierda
	rlutil::locate(40, 20);
	cout << (char)200;

	//linea inferior
	for (int i = 0; i < 50; i++)
	{
		cout << (char)205;
	}

	//linea izquierda
	for (int i = 0; i < 11; i++)
	{
		rlutil::locate(40, 9 + i);
		cout << (char)186;
	}
	//linea derecha
	for (int i = 0; i < 12; i++)
	{
		rlutil::locate(91, 9 + i);
		cout << (char)186;
	}
	//esquina superior derecha
	rlutil::locate(91, 8);
	cout << (char)187;

	//esquina inferior derecha
	rlutil::locate(91, 20);
	cout << (char)188;



	rlutil::locate(41, 17);
	for (int i = 0; i < 50; i++)
	{
		cout << (char)205;
	}

	rlutil::locate(40, 17);
	cout << (char)204;

	rlutil::locate(91, 17);
	cout << (char)185;

}


void cambioNombre();
void CargaReg(Remedio obj){
    obj.Cargar();
    obj.Grabar();

}
void CargaReg(Perfumeria obj){
    obj.Cargar();
    obj.Grabar();

}
void CargaReg(Cliente obj){
    obj.cargar();
    obj.grabar();

}
void CargaReg(Venta obj){
    char c;
    do{
if(obj.cargar()){
    obj.grabar();
    }
    cout << "desea registrar otra venta? (s/n)"<<endl;
    cin >> c;
    }while(c=='s');

}
void MostraReg(Cliente obj){
    int pos=0;
 while(obj.leer(pos)){
            obj.mostrar();
        pos++;
    }
}
void MostraReg(Remedio obj){
    int pos=0;
 while(obj.Leer(pos)){
            obj.Mostrar();
        pos++;
    }
}
void MostraReg(Venta obj){
    int pos=0;
 while(obj.leer(pos)){
            obj.mostrar();
        pos++;
    }
}
void MostraReg(Perfumeria obj){
    int pos=0;
 while(obj.Leer(pos)){
            obj.Mostrar();
            cout<<endl;
        pos++;
    }
}
void menu();
float BuscarPUxID(int);
void submenu_informes();
int BuscarID(int);
void suma_stockmed();
void suma_stock();
void por_med(){
Remedio obj;
Venta reg;
int v[5]={0};
int Ac=0;
int pos=0;
int p;
float porcent;
while(reg.leer(pos)){
    p=0;
        while (obj.Leer(p)){
       if(reg.getid_art()==obj.getid()){
        v[obj.gettipo()-1]=reg.getcantVent();
        Ac+=reg.getcantVent();
        }
        p++;
        }
    pos++;
}
for(int i=0;i<5;i++){
        switch(i){
    case 0:
        cout << "ANALGESICO: ";
        break;
        case 1:
            cout << "ANTIFEBRIL: ";
        break;
        case 2:
            cout << "ANTIINFLAMATORIO: ";
        break;
        case 3:
            cout << "ANTIDEPRESIVO: ";
        break;
        case 4:
            cout << "OTROS MEDICAMENTOS: ";
        break;

        }
    porcent= v[i]*100/(float) Ac;
    cout << porcent<<endl;
}

}
bool modificarStock_med(int pos){
FILE *p;
Remedio obj;
p=fopen("remedios.dat","ab");
if(p==NULL){return false;};

bool escribio=fwrite(&obj,pos*sizeof obj,1,p);
fclose(p);
return escribio;
}
bool modificarStock_perf(int pos){
FILE *p;
Perfumeria obj;
p=fopen("perfumes.dat","ab");
if(p==NULL){return false;};
bool escribio=fwrite(&obj,pos*sizeof obj,1,p);
fclose(p);
return escribio;
}
void mostrarxDNI(){
int dni;
    Cliente obj;
    cout << "INGRESE DNI DEL CLIENTE A MOSTRAR: ";
    cin >> dni;

int pos=0;
while(obj.leer(pos)){
        if(dni==obj.getdni()){
        obj.mostrar();
        return;
        }
    pos++;
}
cout<<"NO HAY UN DNI: "<<dni<<endl;

}
void mostrarxID(){
    int id;
    Remedio obj;
    cout << "INGRESE ID DEL ARTICULO A MOSTRAR: "<<endl;
    cin >> id;

int pos=0;
while(obj.Leer(pos)){
        if(id==obj.getid()){
        obj.Mostrar();
        }
    pos++;
}
}
void mostrarxIDPer(){
    int id;
    Perfumeria obj;
    cout << "INGRESE ID DEL ARTICULO A MOSTRAR: "<<endl;
    cin >> id;

int pos=0;
while(obj.Leer(pos)){
        if(id==obj.getid()){
        obj.Mostrar();
        }
    pos++;
}
}
void mostrarxIDvent(){
    int id;
    Venta obj;
    cout << "INGRESE ID DE LA VENTA A MOSTRAR: "<<endl;
    cin >> id;

int pos=0;
while(obj.leer(pos)){
        if(id==obj.getid()){
        obj.mostrar();
        }
    pos++;
}
}
float BuscarPUxID(int id){
int pos=0;
Articulo obj;
while(obj.leerArticulo(pos)){
    if(id==obj.getid()){
        return obj.getpu();
    }
    pos++;
}

return -1;
}
void submenu_med(){
Remedio obj;
int opc;

do{
system("cls");
DrawBox();
rlutil::locate(41, 10);
cout << "    -- MENU MEDICAMENTO -- "<<endl;
rlutil::locate(41, 11);
cout << " 1. CARGAR         "<<endl;
rlutil::locate(41, 12);
cout << " 2. MOSTRAR MEDICAMENTOS  "<<endl;
rlutil::locate(41, 13);
cout << " 3. BUSCAR POR ID "<<endl;
rlutil::locate(41, 14);
cout << " 4. MODIFICAR STOCK "<<endl;
rlutil::locate(41, 15);
cout << " 0. SALIR "<<endl;
rlutil::locate(42, 18);
cout << "Ingrese una Opcion: ";
cin >> opc;
system("cls");

switch(opc){
case 1:
    CargaReg(obj);
    system("pause");
    break;
case 2:
    MostraReg(obj);
    system("pause");
    break;
case 3:
    mostrarxID();
    system("pause");
    break;
case 4:suma_stockmed();
system("pause");
    break;


}
}while(opc!=0);
}
void submenu_vent(){
Venta obj;
int opc;

do{
system("cls");
DrawBox();
rlutil::locate(44, 10);
cout << "    -- MENU VENTA -- "<<endl;
rlutil::locate(41, 11);
cout << " 1. CARGAR         "<<endl;
rlutil::locate(41, 12);
cout << " 2. MOSTRAR VENTAS  "<<endl;
rlutil::locate(41, 13);
cout << " 3. BUSCAR POR ID "<<endl;
rlutil::locate(41, 14);
cout << " 0. SALIR "<<endl;
rlutil::locate(42, 18);
cout << "Ingrese una Opcion: ";
cin >> opc;
system("cls");
switch(opc){
case 1:
    CargaReg(obj);
    system("pause");
    break;
case 2:
    MostraReg(obj);
system("pause");
    break;
case 3:mostrarxIDvent();
system("pause");
    break;


}
}while(opc!=0);
}
void submenu_perf(){
Perfumeria obj;
int opc;

do{
system("cls");
DrawBox();
rlutil::locate(41, 10);
cout << "    -- MENU PERFUMERIA -- "<<endl;
rlutil::locate(41, 11);
cout << " 1. CARGAR         "<<endl;
rlutil::locate(41, 12);
cout << " 2. MOSTRAR PRODUCTOS  "<<endl;
rlutil::locate(41, 13);
cout << " 3. BUSCAR POR ID "<<endl;
rlutil::locate(41, 14);
cout << " 4. MODIFICAR STOCK "<<endl;
rlutil::locate(41, 15);
cout << " 0. SALIR "<<endl;
rlutil::locate(42, 18);
cout << "Ingrese una Opcion: ";
cin >> opc;
system("cls");
switch(opc){
case 1:
   CargaReg(obj);
   system("pause");
    break;
case 2:
    MostraReg(obj);
    system("pause");
    break;
case 3:mostrarxIDPer();
system("pause");
    break;
case 4:suma_stock();
system("pause");
    break;


}
}while(opc!=0);
}
void submenu_cli(){
Cliente obj;
int opc;

do{
        system("cls");
DrawBox();
rlutil::locate(43, 10);
cout << "    -- MENU CLIENTE -- "<<endl;
rlutil::locate(43, 11);
cout << " 1. CARGAR         "<<endl;
rlutil::locate(43, 12);
cout << " 2. MOSTRAR CLIENTES  "<<endl;
rlutil::locate(43, 13);
cout << " 3. BUSCAR POR DNI "<<endl;
rlutil::locate(43, 14);
cout << " 4. MODIFICAR NOMBRE "<<endl;
rlutil::locate(43, 15);
cout << " 0. SALIR "<<endl;
rlutil::locate(44, 18);
cout << "Ingrese una Opcion: ";
cin >> opc;
system("cls");
switch(opc){
case 1:
    CargaReg(obj);
system("pause");
    break;
case 2:
   MostraReg(obj);
system("pause");
    break;
case 3:mostrarxDNI();
system("pause");
    break;
case 4:cambioNombre();
system("pause");
    break;


}
}while(opc!=0);
}
void menu(){
int opc;

do{
        system("cls");
        rlutil::setColor(rlutil::BLACK);
        DrawBox();
        rlutil::setColor(rlutil::BLACK);
rlutil::locate(43, 10);
cout << "    -- MENU PRINCIPAL -- "<<endl;
rlutil::locate(43, 11);
cout << " 1. MENU REMEDIO          "<<endl;
rlutil::locate(43, 12);
cout << " 2. MENU PERFUMERIA   "<<endl;
rlutil::locate(43, 13);
cout << " 3. MENU CLIENTE "<<endl;
rlutil::locate(43, 14);
cout << " 4. MENU VENTA "<<endl;
rlutil::locate(43, 15);
cout << " 5. MENU DE INFORMES "<<endl;
rlutil::locate(43, 16);
cout << " 0. SALIR "<<endl;
rlutil::locate(44, 18);
cout << "Ingrese una Opcion: ";
cin >> opc;
system("cls");
switch(opc){
case 1:submenu_med();
    break;
case 2:submenu_perf();
    break;
case 3:submenu_cli();
    break;
case 4:submenu_vent();
    break;
case 5:submenu_informes();
    break;



}
}while(opc!=0);
}
int cant_venta_pan(){
Venta obj;
Remedio reg;
int pos=0;
int p;
int Ac=0;
while(obj.leer(pos)){
        p=0;
    while(reg.Leer(p)){
     if(obj.getid_art()==reg.getid()){
        if(obj.getVenti().getAnio()==2020||obj.getVenti().getAnio()==2021){
            if(reg.gettipo()==4){
               Ac+=obj.getcantVent();
            }
        }
     }
     p++;
    }
    pos++;
}
return Ac;
}
void por_perf(){
Perfumeria obj;
Venta reg;
int v[4]={0};
int Ac=0;
int pos=0;
int p;
int anio;
float porcent;
cout << "INGRESE UN ANIO: ";
cin >> anio;
while(reg.leer(pos)){
    p=0;
        while (obj.Leer(p)){
       if(reg.getid_art()==obj.getid()){
            if(reg.getVenti().getAnio()==anio){
        v[obj.gettipoProd()-1]=reg.getcantVent();
        Ac+=reg.getcantVent();
        }
        }
        p++;
        }
    pos++;
}
for(int i=0;i<4;i++){
        switch(i){
    case 0:
        cout << "SHAMPOO: ";
        break;
        case 1:
            cout << "ACONDICIONADOR: ";
        break;
        case 2:
            cout << "PERFUME: ";
        break;
        case 3:
            cout << "OTRO PRODUCTO: ";
        break;

        }
    porcent= v[i]*100/(float) Ac;
    cout << porcent<<endl;
}

}
void MostrarVec(int vec[], int tam){
    for(int i=0;i<tam;i++){
        switch(i){
    case 0:
        cout << "ENERO: ";
        break;
        case 1:
            cout << "FEBRERO: ";
        break;
        case 2:
            cout << "MARZO: ";
        break;
        case 3:
            cout << "ABRIL: ";
        break;
        case 4:
            cout << "MAYO: ";
        break;
        case 5:
            cout << "JUNIO: ";
        break;
        case 6:
            cout << "JULIO: ";
        break;
        case 7:
            cout << "AGOSTO: ";
        break;
        case 8:
            cout << "SEPTIEMBRE: ";
        break;
        case 9:
            cout << "OCTUBRE: ";
        break;
        case 10:
            cout << "NOVIEMBRE: ";
        break;
        case 11:
            cout << "DICIEMBRE: ";
        break;


        }

    cout << vec[i]<<endl;
    }
}
void recxMes(){
    int anio;
    int v[12]={0};
    Venta obj;
    int pos=0;
cout <<"INGRESE UN ANIO: ";
cin >>anio;
while(obj.leer(pos)){
        if(obj.getVenti().getAnio()==anio){
    v[obj.getVenti().getMes()-1]+=obj.getimporte();
        }
    pos++;
}
MostrarVec(v,12);
}
void submenu_informes(){

int opc;
do{
int cant;
system("cls");
DrawBoxInformes();
rlutil::locate(41, 9);
cout << "    -- MENU INFORMES -- "<<endl;
rlutil::locate(41, 10);
cout << " 1. PORCENTAJE EN TIPOS DE MEDICAMENTOS   "<<endl;
rlutil::locate(41, 11);
cout << " 2. ANTIDEPRESIVOS VENDIDOS DURANTE"<<endl;
rlutil::locate(41, 12);
cout << "    LA PANDEMIA (2020-2021). "<<endl;
rlutil::locate(41, 13);
cout << " 3. RECAUDACION MENSUAL. "<<endl;
rlutil::locate(41, 14);
cout << " 4. PORCENTAJE DE VENTAS DISCRIMINADO"<<endl;
rlutil::locate(41, 15);
cout << "    EN TIPOS DE PERFUMERIA EN UN ANIO DETERMINADO." <<endl;
rlutil::locate(41, 16);
cout << " 0. SALIR"<<endl;
rlutil::locate(42, 18);
cout << "Ingrese una Opcion: ";
cin >> opc;
system("cls");
switch(opc){
case 1:
  por_med();
  system("pause");
    break;
case 2:
    cant=cant_venta_pan();
    cout << "VENTAS DE ANTIDEPRESIVOS EN PANDEMIA: "<<cant<<endl;
    system("pause");
    break;
case 3:recxMes();
    system("pause");
    break;
case 4:por_perf();
system("pause");
    break;


}
}while(opc!=0);


}


#endif // FUNCIONES_H_INCLUDED
