#include "clista.h"
#include "neurona.h"
#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <QApplication>
#include<QFileDialog>
#include<QMessageBox>
#include <QStringList>
#include <QtCore/QString>
#include <QtGlobal>

using namespace std;

Clista::Clista()
{
    Inicio = new Neurona;
    Final = new Neurona;

    Inicio->pSig = Final;
    Final->pAnt = Inicio;

    Final->pSig = NULL;
    Inicio->pAnt = NULL;
}

void Clista::InsertarInicio(int id,float voltaje,int pos_x,int pos_y,int red,int green,int blue)
{

    Inicio->InsertarAdelantefloat(id,voltaje,pos_x,pos_y,red,green,blue);
    cont++;

}

void Clista::InsertarFinal(int id,float voltaje,int pos_x,int pos_y,int red,int green,int blue)
{

    Final->pAnt->InsertarAdelantefloat(id,voltaje,pos_x,pos_y,red,green,blue);
    cont++;
}

float Clista::EliminarInicio()
{

    Inicio->pSig->pSig->EliminarSiguiente();

    return 0;
}

float Clista::EliminarFinal()
{

    Final->EliminarSiguiente();

    return 0;
}

int Clista::Tamanio()
{
    Neurona* Pnn = Inicio->pSig;
    int l = 0;

    while (Pnn != Final)
    {
        l++;
        Pnn = Pnn->pSig;
    }
    return l;
}

void Clista::Vaciar()
{
    Inicio->pSig = Final;
    Final->pAnt = Inicio;
}

QString Clista::Set()
{
    Neurona* Pnn = Inicio->pSig;
    QString Oracion;
    QString oracion;

    while(Pnn!=Final)
    {
        oracion = QString::number(Pnn->Id);
        Oracion.append(oracion);
        oracion = QString::number(Pnn->Voltaje);
        Oracion.append(oracion);
        oracion = QString::number(Pnn->Pos_x);
        Oracion.append(oracion);
        oracion = QString::number(Pnn->Pos_y);
        Oracion.append(oracion);
        oracion = QString::number(Pnn->Red);
        Oracion.append(oracion);
        oracion = QString::number(Pnn->Green);
        Oracion.append(oracion);
        oracion = QString::number(Pnn->Blue);
        Oracion.append(oracion);
        Oracion.append("\n");

        Pnn = Pnn->pSig;
    }

    return Oracion;
}


void Clista::Save(QString filename)
{
    Neurona* Pnn = Inicio->pSig;


    QByteArray ba = filename.toLatin1();
    const char *file = ba.data();

    ofstream File(file);

        if (!File.is_open()) {
                cerr <<"Error de apertura "<<endl;
                return;
            }

        while (Pnn != Final) {
            if (Pnn->Id != -1) {
                File << Pnn->Id << ",";
                File << Pnn->Voltaje << ",";
                File << Pnn->Pos_x << ",";
                File << Pnn->Pos_y << ",";
                File << Pnn->Red << ",";
                File << Pnn->Green << ",";
                File << Pnn->Blue << "|";
                File << "\n";
            }
            Pnn = Pnn->pSig;
        }

        File.close();
}

void Clista::Recover(QString filename)
{
    Neurona* Pnn = Inicio->pSig;
    QByteArray ba = filename.toLatin1();
    const char *file = ba.data();

    ifstream File(file);


        if(File.is_open())
        {

        while(!File.eof())
        {
        int id = 0;
        float V = 0;
        int pX = 0;
        int pY = 0;
        int r = 0;
        int g = 0;
        int b = 0;
        string oracion;
        stringstream ss;
        stringstream ss2;
        stringstream ss3;
        stringstream ss4;
        stringstream ss5;
        stringstream ss6;
        stringstream ss7;

            std::getline(File,oracion,',');
            ss << oracion;
            ss >> id;

            std::getline(File,oracion,',');
            ss2 << oracion;
            ss2 >> V;

            std::getline(File,oracion,',');
            ss3 << oracion;
            ss3 >> pX;

            std::getline(File,oracion,',');
            ss4 << oracion;
            ss4 >> pY;

            std::getline(File,oracion,',');
            ss5 << oracion;
            ss5 >> r;

            std::getline(File,oracion,',');
            ss6 << oracion;
            ss6 >> g;

            std::getline(File,oracion,'|');
            ss7 << oracion;
            ss7 >> b;



        if(Pnn == NULL)
        {
            Pnn = new Neurona;
            Pnn->InsertarAdelantefloat(id,V,pX,pY,r,g,b);
        }
        else
        {
            Pnn->InsertarAdelantefloat(id,V,pX,pY,r,g,b);
        }

        if(File.eof())
            {
                break;
            }


        }
        File.close();
    }
}

void Clista::BusquedaL(QString label, int& ID, float& Volt, int& x, int& y, int& r, int& g, int& b)
{
    Inicio->BusquedaL(label,ID,Volt,x,y,r,g,b);
}

void Clista::setX(int& x)
{
    Inicio->pSig->setX(x);
}
