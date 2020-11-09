#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "computadora.h"
#include <algorithm>

#define TAM 5

class Laboratorio{
    private:
        vector<Computadora> CPU;

    public:
        Laboratorio();

        void agregarCPU(const Computadora&);
        void mostrar();

        void respaldar_tabla();
        void respaldar();

        void recuperar();

        void insertar(const Computadora&, size_t p);
        size_t size();
        void inicializar(const Computadora&, const int&);
        void eliminar(size_t p);
        void ordenar();
        Computadora* buscar(const Computadora& c);

        friend Laboratorio& operator<<(Laboratorio &l, const Computadora &c){
            l.agregarCPU(c);

            return l;
        }
};

#endif 