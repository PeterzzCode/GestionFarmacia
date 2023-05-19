#ifndef ARTICULO_H
#define ARTICULO_H
#include <cstring>

class Articulo
{
    public:
        Articulo();
        ~Articulo();
    void setid (int id){ID=id;}
void setnombre(char *c){strcpy(nombre,c);}
void setstock(int s){stock=s;}
void setpu(float precio_unitario){pu=precio_unitario;}
void setestado(bool e){estado=e;}


int getid (){return ID;}
char *getnombre(){return nombre;}

float getpu(){return pu;}
bool getestado(){return estado;}
int getstock(){return stock;}
void cargar();
void mostrar();
bool grabar();
bool leerArticulo(int);


    protected:
        int ID;
        char nombre[30];
        float pu;
        bool estado;
        int stock;

    private:
};

#endif // ARTICULO_H
