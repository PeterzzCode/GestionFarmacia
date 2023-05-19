#ifndef VENTA_H
#define VENTA_H
#include "Fecha.h"


class Venta
{
    public:
        Venta();
        ~Venta();
        void setid(int c){if(c>=0)id=c;}
        void setid_art(int c){if(c>=0)id_art=c;}
        void setcantVent(int cv){if(cv>0)cant_vent=cv;}
        void setTipoPago(char tp){tipo_pago=tp;}
        void setdni(int dni){if(dni>=0)DNI=dni;}
        void setestado(bool e){estado=e;}
        void setimporte(float i){if(i>=0)importe=i;}
        void setVenti(Fecha v){venti=v;}

    int getid(){return id;}
    int getid_art(){return id_art;}
    float getimporte(){return importe;}
    int getdni(){return DNI;}
    bool getestado(){return estado;}
    int getcantVent(){return cant_vent;}
    Fecha getVenti(){return venti;}
    char getTipoPago(){return tipo_pago;}
    bool cargar();
    void mostrar();
    bool grabar();
    bool leer(int);


    private:
        int id;
        int id_art;
        float importe;
        int DNI;
        char tipo_pago;
        int cant_vent;
        bool estado;
        Fecha venti;
};

#endif // VENTA_H
