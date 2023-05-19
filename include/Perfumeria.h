#ifndef PERFUMERIA_H
#define PERFUMERIA_H
#include "Articulo.h"

class Perfumeria: public Articulo
{
    public:
        Perfumeria();
        ~Perfumeria();
    void setmarca  (char *c){strcpy(marca,c);}
void settipoProd   (int e){tipoProd=e;}
    void setGenero (int e){Genero=e;}
    void setlitros (float l){litros=l;}
    char *getmarca  (){return marca;}
    int gettipoProd(){return tipoProd;}
    int  getGenero (){return Genero;}
    float getlitros(){return litros;}
    void Cargar();
    void Mostrar();
    bool Grabar();
    bool Leer(int);
    protected:
    char marca[30];
    int tipoProd;
    int Genero;
    float litros;

    private:
};

#endif // PERFUMERIA_H
