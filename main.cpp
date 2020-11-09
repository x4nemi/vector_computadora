#include "laboratorio.h"

using namespace std;

int main(){
    Laboratorio lab;
    int op;

    while(1){
        cout << "\n\n1. Agregar cpu" << "\t";
        cout << "2. Mostrar" << "\t";
        cout << "3. Respaldad" << endl;
        cout << "4. Recuperar" << "\t";
        cout << "5. Insertar" << "\t";
        cout << "6. Inicializar" << endl;
        cout << "7. Eliminar" << "\t";
        cout << "8. Ordenar" << "\t";
        cout << "9. Buscar" << endl;
        cout << "0. Salir" << endl << "Opcion: ";
        cin >> op; cin.ignore();

        if(!op) break;
        cout << endl;
        
        switch(op){
            case 1:
            {
                Computadora c;
                cin >> c; 
                lab.agregarCPU(c);
                cin.ignore();
            }
                break;
            case 2:
                lab.mostrar();
                break;
            case 3:
                lab.respaldar();
                cout << "Respaldado";
                break;
            case 4:
                lab.recuperar();
                cout << "Recuperado";
                break;
            case 5:
            {
                size_t pos;
                cout << "Posicion: ";
                cin >> pos; cin.ignore();

                if(lab.size() <= pos){
                    cout << "Posicion invalida";
                    break;
                }
                Computadora c;
                cin >> c; 
                lab.insertar(c, pos);
                
            }
                break;
            case 6:
            {
                size_t tam;
                cout << "Tamanio: ";
                cin >> tam; cin.ignore();

                Computadora c;
                cin >> c;
                lab.inicializar(c, tam);
            }
                break;
            case 7:
            {
                size_t pos;
                cout << "Posicion: ";
                cin >> pos; //cin.ignore();

                if(lab.size() <= pos){
                    cout << "Posicion invalida";
                    break;
                }

                lab.eliminar(pos);
            }
                break;
            case 8:
                if(lab.size() == -1){
                    cout << "No hay computadoras registradas";
                    break;
                }
                lab.ordenar();
                cout << "Ordenado";
                break;
            case 9:
            {
                Computadora c;
                cin >> c;

                Computadora* ptr = lab.buscar(c);
                if(ptr == nullptr){
                    cout << "No encontrado" << endl;
                    break;
                }

                else{
                    cout << *ptr;
                }
            }

        }
    }
    return 0;
}