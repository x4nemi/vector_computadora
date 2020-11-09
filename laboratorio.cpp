#include "laboratorio.h"

using namespace std;

Laboratorio::Laboratorio(){ }

void Laboratorio::agregarCPU(const Computadora &c){
    CPU.push_back(c);
}

void Laboratorio::mostrar(){
    if(CPU.empty()){
        cout << "No hay computadoras registradas";
        return;
    }

    Computadora c;

    cout << left;
    cout << setw(15) << "Nombre ";
    cout << setw(20) << "Sistema Operativo ";
    cout << setw(15) << "Procesador ";
    cout << setw(5) << "RAM ";
    cout << endl;
    for(size_t i = 0; i < CPU.size(); i++){
        c = CPU[i];
        cout << c;
        /*cout << "Computadora " << i + 1 << endl;
        cout << "Nombre del equipo: " << c.getNombre() << endl;
        cout << "Sistema Operativo: " << c.getSO() << endl;
        cout << "Procesador: " << c.getProcesador() << endl;
        cout << "Memoria RAM: " << c.getRAM() << endl << endl;*/
    }
}

void Laboratorio::respaldar_tabla(){
    Computadora c;
    ofstream archivo("computadoras_tabla.txt");

    if(archivo.is_open()){
        archivo << left;
        archivo << setw(15) << "Nombre ";
        archivo << setw(20) << "Sistema Operativo ";
        archivo << setw(15) << "Procesador ";
        archivo << setw(5) << "RAM ";
        archivo << endl;
        for(size_t i = 0; i < CPU.size(); i++){
            c = CPU[i];
            archivo << c;
        }
    }

    archivo.close();
}

void Laboratorio::respaldar(){
    Computadora c;
    ofstream archivo("computadoras.txt");

    if(archivo.is_open()){
        for(size_t i = 0; i < CPU.size(); i++){
            c = CPU[i];
            archivo << c.getNombre() << endl;
            archivo << c.getSO() << endl;
            archivo << c.getProcesador() << endl;
            archivo << c.getRAM() << endl;
        }
    }

    archivo.close();
}

void Laboratorio::recuperar(){
    ifstream archivo("computadoras.txt");

    if(archivo.is_open()){
        string temp;
        int ram;
        Computadora c;

        while(true){
            getline(archivo, temp);
            if(archivo.eof()){
                break;
            }
            c.setNombre(temp);

            getline(archivo, temp);
            c.setSO(temp);

            getline(archivo, temp);
            c.setProcesador(temp);

            getline(archivo, temp);
            ram = stof(temp);
            c.setRAM(ram);

            agregarCPU(c);
        }
    }

    archivo.close();
}

void Laboratorio::insertar(const Computadora& c, size_t pos){
        CPU.insert(CPU.begin() + pos, c);
}

size_t Laboratorio::size(){
    return CPU.size();
}

void Laboratorio::inicializar(const Computadora& c, const int& tam){
    CPU = vector<Computadora>(tam, c);
}

void Laboratorio::eliminar(size_t p){
    CPU.erase(CPU.begin() + p);
}

void Laboratorio::ordenar(){
    sort(CPU.begin(), CPU.end());
}

Computadora* Laboratorio::buscar(const Computadora& c){
    auto it = find(CPU.begin(), CPU.end(), c); //vector<Computadora>::iterador it

    if(it == CPU.end()){
        return nullptr;
    }

    return &(*it);
}