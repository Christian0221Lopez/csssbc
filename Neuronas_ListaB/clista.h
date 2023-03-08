#ifndef CLISTA_H
#define CLISTA_H
#include "neurona.h"


class Clista
{
private:
    /*Neurona* Inicio;
    Neurona* Final;*/;
    Neurona* Inicio = nullptr;
    Neurona* Final = nullptr;
    int cont;
    friend class Neurona;
public:
    Clista();
        ~Clista() {
            // Liberar la memoria asignada a las neuronas
            delete Inicio;
            delete Final;
        }
    void InsertarInicio(int,float,int,int,int,int,int);
    void InsertarFinal(int,float,int,int,int,int,int);
    float EliminarInicio();
    float EliminarFinal();
    int Tamanio();
    void Vaciar();
    QString Set();
    Neurona* getInicio();
    void BusquedaL(QString,int&,float&,int&,int&,int&,int&,int&);
    void Save(QString);
    void Recover(QString);
    void setX(int&);
};

#endif // CLISTA_H
