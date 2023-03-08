#include "neurona.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<iostream>
#include<stdio.h>
#include<fstream>
#include <string>
#include <sstream>
#include <QApplication>

using namespace std;



void Neurona::InsertarAdelantefloat(int id,float voltaje,int pos_x,int pos_y,int red,int green,int blue)
{
    Neurona* Pnn = new Neurona;

      Pnn->Id = id;
      Pnn->Voltaje = voltaje;
      Pnn->Pos_x = pos_x;
      Pnn->Pos_y = pos_y;
      Pnn->Red = red;
      Pnn->Green = green;
      Pnn->Blue = blue;

      Pnn->pAnt = this;
      if (this->pSig == NULL) {
          // La lista está vacía, añadir el nuevo nodo al final
          Pnn->pSig = NULL;
          this->pSig = Pnn;
      } else {
          // La lista tiene al menos un nodo
          this->pSig->pAnt = Pnn;
          Pnn->pSig = this->pSig;
          this->pSig = Pnn;
      }

      cont++;
      cout <<cont<<"agregar "<<endl;
}

float Neurona::EliminarSiguiente()
{
    Neurona* Pnn = this->pAnt->pAnt;

    delete this->pAnt;

    this->pAnt = Pnn;
    Pnn->pSig = this;

    return 0;

}

void Neurona::BusquedaL(QString label, int& ID, float& Volt, int& x, int& y, int& r, int& g, int& b)
{
    Neurona* Pnn = this->pSig;

    int bandera = 0;
    bool ok = 0;

    int num = label.toInt(&ok);
    if (!ok) {
      cout << "Conversion failed. Repeat conversion" <<endl;
    }
        if(cont > 0)
        {
            while(Pnn != nullptr)
            {
                 cout<<num<<"Primero "<<endl;
                if(Pnn->Id == num)
                {
                    ID = Pnn->Id;
                    Volt = Pnn->Voltaje;
                    x = Pnn->Pos_x;
                    y = Pnn->Pos_y;
                    r = Pnn->Red;
                    g = Pnn->Green;
                    b = Pnn->Blue;
                    return;
                }

                Pnn = Pnn->pSig;
            }
        }

        else
        {
            cout<<"\n\tRegistro vacio..!";
        }

        if(bandera==0)
        {
            cout<<"\n\n\tEl Disco no fue encontrado..! :S"<<endl;

        }
}

void Neurona::setX(int &x)
{
    Neurona *pActual = this;
    x = pActual->Pos_x;
     pActual = pActual->pSig;
}

void Neurona::setID(int &id)
{
    Neurona *pActual = this;
    id = pActual->Id;
     pActual = pActual->pSig;
}


void Neurona::setV(float& v)
{
    if (pSig != nullptr) {
        // Si hay un siguiente nodo en la lista
        v = pSig->Voltaje; // Asignamos el valor del siguiente nodo a v
    }
}

/*void Neurona::setV(float &v)
{
    Neurona *pActual = this;
    v = pActual->Voltaje;
     pActual = pActual->pSig;
}*/;

void Neurona::setY(int &y)
{
    Neurona *pActual = this;
    y = pActual->Pos_y;
     pActual = pActual->pSig;
}

void Neurona::setR(int &r)
{
    Neurona *pActual = this;
    r = pActual->Red;
     pActual = pActual->pSig;
}

void Neurona::setG(int &g)
{
    Neurona *pActual = this;
    g = pActual->Green;
     pActual = pActual->pSig;
}

void Neurona::setB(int &b)
{
    Neurona *pActual = this;
    b = pActual->Blue;
     pActual = pActual->pSig;
}

/*void Neurona::setX(int &x)
{
    Neurona *pActual = this; // Empezamos en el primer nodo
    while (pActual != NULL) { // Mientras no lleguemos al final de la lista
        x =pActual->Pos_x; // Actualizamos el valor de Pos_x en el nodo actual
        pActual = pActual->pSig; // Avanzamos al siguiente nodo
    }
}*/;
