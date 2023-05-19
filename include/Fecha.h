#ifndef FECHA_H
#define FECHA_H


class Fecha{
    public:
        Fecha();
        void Cargar();
        void Mostrar();
         int getDia(){return dia;}
         int getMes(){return mes;}
         int getAnio(){return anio;}
         void setDia(int d){dia=d;}
         void setMes(int m){mes=m;}
         void setAnio(int a){anio=a;}
    protected:

    private:
        int dia, mes, anio;
};

#endif // FECHA_H
