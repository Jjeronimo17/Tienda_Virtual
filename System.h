//
// Created by USUARIO on 29/03/2026.
//

#ifndef PARCIAL2_SYSTEM_H
#define PARCIAL2_SYSTEM_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


struct Producto {
    string nombre;
    double precio;
    string categoria;
};



class System {
public:

    vector<Producto> productos;

    //Cargar productos al vector

    void cargarProductos() {
        ifstream file("productos.txt");

        if (!file.is_open()) {
            cout << "No se pudieron cargar los productos al inventario" << endl;
        }
        string linea;
        while (getline(file, linea)) {
            stringstream ss(linea);
            string nombre, precioStr, categoria;

            getline(ss, nombre, '|');
            getline(ss, precioStr, '|');
            getline(ss, categoria, '|');

            Producto temp;
            temp.nombre = nombre;
            temp.precio = stod(precioStr);
            temp.categoria = categoria;

            productos.push_back(temp);
        }

        file.close();
        cout << productos.size() << " productos cargados exitosamente." << endl;
    }

    string toLower(string texto) {
        for (int i = 0; i < texto.size(); i++) {
            texto[i] = tolower(texto[i]);
        }
        return texto;
    }

    // Funcion QuickSort para ordenar los productos

    int partition1 (vector<Producto>& productos, int low, int high) {   // Este partition es para ordenar por nombre
        int mid = (low + high) / 2;
        swap(productos[mid], productos[high]);
        string pivot = toLower(productos[high].nombre);
        int j = low - 1;
        for (int i = low; i < high; i++) {
            if (toLower(productos[i].nombre) < toLower(pivot)) {
                j++;
                swap(productos[j], productos[i]);
            }
        }
        swap(productos[j + 1], productos[high]);
        return j + 1;
    }

    void quickSort(vector<Producto>&productos, int low, int high) {
        if (low < high) {
            int pivotIndex = partition1(productos, low, high);
            quickSort(productos, low, pivotIndex - 1);
            quickSort(productos, pivotIndex + 1, high);
        }
    }

    // Busqueda binaria para encontrar productos por nombre
    int binarySearch(vector<Producto>&productos, int low, int high, string nombre) {
        if (low > high) {
            return -1;
        }
        int mid = (low + high) / 2;
        if (toLower(productos[mid].nombre) == toLower(nombre)) {
            return mid;
        } else if (toLower(productos[mid].nombre) < toLower(nombre)) {
            low = mid + 1;
            return binarySearch(productos, low, high, nombre);

        } else if (toLower(productos[mid].nombre) > toLower(nombre)) {
            high = mid - 1;
            return binarySearch(productos, low, high, nombre);

        }
    }

    int partition2 (vector<Producto>& productos, int low, int high) {   // Este partition es para ordenar por precio
        int mid = (low + high) / 2;
        swap(productos[mid], productos[high]);
        double pivot = productos[high].precio;
        int j = low - 1;
        for (int i = low; i < high; i++) {
            if (productos[i].precio < pivot) {
                j++;
                swap(productos[j], productos[i]);
            }
        }
        swap(productos[j + 1], productos[high]);
        return j + 1;
    }

    void quickSort2(vector<Producto>&productos, int low, int high) {
        if (low < high) {
            int pivotIndex = partition2(productos, low, high);
            quickSort2(productos, low, pivotIndex - 1);
            quickSort2(productos, pivotIndex + 1, high);
        }
    }



    void buscarPorCategoria(string nombre) {
        cout << "Productos disponibles en la categoria: " << endl;
        for (int i = 0; i < productos.size(); i++) {
            if (toLower(productos[i].categoria) == toLower(nombre)) {
                cout << productos[i].nombre << " | Precio: " << productos[i].precio << endl;
            }
        }
    }

    void nProductos(int n) {
        if (n < 1 || n > productos.size()) {
            cout << "Error: el numero debe estar entre 1 y " << productos.size() << endl;
            return;
        }
        string answer;
        cout << "De que manera desea ordenar?" << endl;
        cout << "a. Mas costosos" << endl;
        cout << "b. Mas baratos" << endl;
        cin >> answer;
        if (answer == "a") {
            quickSort2(productos, 0, productos.size() - 1);
            for (int i = productos.size()-1; i >= productos.size() - n; i--) {
                cout << productos[i].nombre << " | " << productos[i].precio << endl;
            }
        }
        if (answer == "b") {
            quickSort2(productos, 0, productos.size() - 1);
            for (int i = 0; i < n;i++) {
                cout << productos[i].nombre << " | " << productos[i].precio << endl;
            }
        }
    }
};


#endif //PARCIAL2_SYSTEM_H