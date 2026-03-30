# Tienda Virtual - Sistema de Gestión de Productos

Sistema de consola desarrollado en C++ para organizar y consultar productos de una tienda virtual. Proyecto académico para la materia de **Estructuras de Datos y Algoritmos**.

## Descripción

El programa carga una base de datos de 120 productos desde un archivo de texto y permite al usuario realizar búsquedas, ordenamientos y filtrados a través de un menú interactivo.

## Funcionalidades

- **Buscar producto por nombre:** ordena el catálogo alfabéticamente con QuickSort y localiza el producto mediante búsqueda binaria. La búsqueda es case-insensitive.
- **Ordenar productos por nombre o precio:** utiliza QuickSort para ordenar el catálogo completo alfabéticamente (A→Z) o por precio (menor a mayor).
- **Filtrar por categoría:** recorre el catálogo y muestra únicamente los productos de la categoría seleccionada (Electrónica, Alimentos, Ropa, Hogar, Deportes, Papelería).
- **Mostrar los N más económicos o costosos:** ordena por precio con QuickSort y muestra los primeros o últimos N productos según la elección del usuario.

## Algoritmos implementados

| Algoritmo | Uso | Complejidad promedio |
|---|---|---|
| QuickSort (pivote central) | Ordenamiento por nombre y precio | O(n log n) |
| Búsqueda binaria | Búsqueda por nombre | O(log n) |
| Recorrido lineal | Filtrado por categoría | O(n) |

## Estructura de datos

```cpp
struct Producto {
    string nombre;
    double precio;
    string categoria;
};
```

Los productos se almacenan en un `vector<Producto>` por su acceso directo en O(1), compatibilidad con QuickSort y tamaño dinámico.

## Formato del archivo de datos

El archivo `productos.txt` contiene 120 productos con el formato:

```
Nombre|Precio|Categoria
```

Distribuidos equitativamente en 6 categorías: Electrónica, Alimentos, Ropa, Hogar, Deportes y Papelería.

## Cómo ejecutar

1. Clonar el repositorio
2. Asegurarse de que `productos.txt` esté en la misma carpeta que el ejecutable
3. Compilar y ejecutar:

```bash
g++ -o tienda main.cpp
./tienda
```

## Tecnologías

- C++
- STL (vector, string, fstream, sstream)
