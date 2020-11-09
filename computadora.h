#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

class Computadora{
    private:
        string nombre;
        string SO;        
        string procesador;
        int RAM;
    public:
        Computadora();
        Computadora(const string &nombre, const string &SO, const string &procesador, float RAM);

        ///Setters
        void setNombre(const string &n);
        void setSO(const string &s);
        void setProcesador(const string &p);
        void setRAM(int r);

        //Getters
        string getNombre();
        string getSO();
        string getProcesador();
        float getRAM();

        friend ostream& operator<<(ostream &out, const Computadora &p){
            out << left;
            out << setw(15) << p.nombre;
            out << setw(20) <<  p.SO;
            out << setw(15) <<  p.procesador;
            out << setw(5) <<  p.RAM;
            out << endl;
            return out;
        }

        friend istream& operator>>(istream &in, Computadora &c){
            cout << "Nombre: ";
            getline(cin, c.nombre);
            //cin.ignore();

            cout << "Sistema Operativo: ";
            getline(cin, c.SO);
            //cin.ignore();
            cout << "Procesador: ";
            getline(cin, c.procesador);
            //cin.ignore();
            cout << "RAM: ";
            cin >> c.RAM;

            return in;
        }

        bool operator==(const Computadora& c){
            return nombre == c.nombre;
        }
        bool operator==(const Computadora& c) const{
            return nombre == c.nombre;
        }

        bool operator>(const Computadora& c){
            return 2;
        }
        bool operator<(const Computadora& c) const{
            return nombre < c.nombre;
        }
};

#endif