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
    void BusquedaL(QString,int&,float&,int&,int&,int&,int&,int&);
    void Save(QString);
    void Recover(QString);
    void setID(int&);
    void setV(float&);
    void setX(int&);
    void setY(int&);
    void setR(int&);
    void setG(int&);
    void setB(int&);
    Neurona* getInicio() {
           return Inicio;
       }

       Neurona* getFinal() {
           return Final;
       }
};

#endif // CLISTA_H
