#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "System.h"
using namespace std;

int main () {
    System system;
    system.cargarProductos();
    int option = 0;
        while (option != 5) {
            cout << "========================================" << endl;
            cout << "       TIENDA VIRTUAL - MENU" << endl;
            cout << "========================================" << endl;
            cout << "1. Buscar producto por nombre" << endl;
            cout << "2. Mostrar productos ordenados por precio o nombre" << endl;
            cout << "3. Filtrar productos por categoria" << endl;
            cout << "4. Mostrar los N productos mas economicos o mas costosos" << endl;
            cout << "5. Salir" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Ingrese una opcion: ";
            cin >> option;
            switch (option) {
            case 1: {
                string nombre;
                cout << "Introduzca el nombre del producto a buscar: ";
                cin.ignore();
                getline(cin, nombre);
                system.quickSort(system.productos,0,system.productos.size()-1);
                int resultado = system.binarySearch(system.productos,0,system.productos.size()-1,nombre);
                if (resultado != -1) {
                    cout << "Nombre: " << system.productos[resultado].nombre << endl;
                    cout << "Precio: " << system.productos[resultado].precio << endl;
                    cout << "Categoria: " << system.productos[resultado].categoria << endl;
                } else {
                    cout << "Producto no encontrado." << endl;
                }
                cout << endl << "Presione Enter para volver al menu..." << endl;
                cin.get();
                break;
            }
            case 2: {
                string opcion;
                cout << "Como desea ordenador los productos?" <<endl;
                cout << "a. Por nombre" << endl;
                cout << "b. Por precio(economicos a costosos)" << endl;
                cin >> opcion;
                if (opcion == "a") {
                    system.quickSort(system.productos,0,system.productos.size()-1);
                    for (int i = 0; i < system.productos.size(); i++) {
                        cout << system.productos[i].nombre << " | " << system.productos[i].precio << " | " << system.productos[i].categoria << endl;
                    }
                }
                if (opcion == "b") {
                    system.quickSort2(system.productos,0,system.productos.size()-1);
                    for (int i = 0; i < system.productos.size(); i++) {
                        cout << system.productos[i].nombre << " | " << system.productos[i].precio << " | " << system.productos[i].categoria << endl;
                    }

                }
                cout << endl << "Presione Enter para volver al menu..." << endl;
                cin.ignore();
                cin.get();
                break;
            }
            case 3: {
                string o;
                cout << "Categorias disponibles: " << endl;
                cout << "1. Electronica" << endl;
                cout << "2. Alimentos" << endl;
                cout << "3. Ropa" << endl;
                cout << "4. Hogar" << endl;
                cout << "5. Deportes" << endl;
                cout << "6. Papeleria" << endl;
                cout << "Ingrese el nombre de la categoria del producto que busca: " << endl;
                cin >> o;
                system.buscarPorCategoria(o);
                cout << endl << "Presione Enter para volver al menu..." << endl;
                cin.ignore();
                cin.get();
                break;
            }
            case 4: {
                int n;
                cout << "Ingrese la cantidad de productos que desea buscar: " << endl;
                cin >> n;
                system.nProductos(n);
                cout << endl << "Presione Enter para volver al menu..." << endl;
                cin.ignore();
                cin.get();
                break;
            }
                case 5: {
                cout << "Gracias por usar la Tienda Virtual. Hasta pronto!" << endl;
                break;
            }
        }
    }
return 0;

}