#ifndef REMEDIO_H
#define REMEDIO_H
#include "Articulo.h"

class Remedio:public Articulo
{
    public:
        Remedio();
        ~Remedio();
        void settipo(int t){if(t>0&&t<=5)tipo=t;}
        void settipoConsumo(int tc){if(tc>0&&tc<=5)tipo_consumo=tc;}

        void setlibre(bool l){vent_libre=l;}

        int gettipo(){return tipo;}
        int gettipoConsumo(){return tipo_consumo;}
        bool getlibre(){return vent_libre;}

        void Cargar();
        void Mostrar();
        bool Grabar();
        bool Leer(int);

    protected:
    int tipo;
    int tipo_consumo;
    bool vent_libre;

    private:
};

#endif // REMEDIO_H
