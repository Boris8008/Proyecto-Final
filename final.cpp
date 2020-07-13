#include "iostream"
#include "string"
#include "string.h"

const int longCad=20;

using namespace std;

struct CostoPorArticulo
{
char NombreArticulo[longCad + 1];
int Cantidad;
float PrecioUnitario;
float CostoTotalPorArticulo;
};

//En esta parte del codigo pedimos al usuario que ingrese los valores o los productos que el desea.
void nota (CostoPorArticulo arreglo[], int a)
{
    string articulo;
    for (int i=0; i<a; i++)
    {
        cout << "Ingrese el nombre del articulo: " << endl;
        getline (cin, articulo, '\n');
        strncpy(arreglo[i].NombreArticulo, articulo.c_str( ), longCad);
        arreglo[i].NombreArticulo[longCad]='\0';
        cout << "Cuantas unidades llevara: ";
        cin >> arreglo[i].Cantidad;
        cout << "Digite el costo unitario: $";
        cin >> arreglo[i].PrecioUnitario;
        cin.ignore(100, '\n'); 
    }
}

//Se lleva a cabo las operaciones para poder sacar el resultado de los costos por articulo
float dinero (CostoPorArticulo arreglo[], int a)
{
    for (int i=0; i<a; i++)
    {
        arreglo[i].CostoTotalPorArticulo = arreglo[i].PrecioUnitario * arreglo[i].Cantidad;
    }
}

//Definimos que "lleva" y el "costo por articulo"
void funcion (CostoPorArticulo arreglo[], int a)
{
    cout << "Lleva la cantidad de " << a << " productos distintos" << endl;
    for (int i=0; i<a; i++)
    {
        cout << "Lleva: " << arreglo[i].Cantidad << arreglo[i].NombreArticulo << endl ;
        cout << "costo por articulo: $" << arreglo[i].CostoTotalPorArticulo<< endl;
    }
    
}

float total(CostoPorArticulo arreglo[], int a)
{
    float total;
    total = 0;
    for (int i=0; i<a; i++)
    {
      total = arreglo[i].CostoTotalPorArticulo + total;
    }
     
    return total;
}
int main()
{
    int a;
    cout << endl;

    cout << "~~PRODUCTOS COMPRADOS~~" << endl << endl;

    cout << "Digite la cantidad de articulos a comprar: " << endl;
    cin >> a;
    cin.ignore(100, '\n');

    CostoPorArticulo arreglo[a];
    nota(arreglo, a);
    dinero(arreglo, a);
    funcion(arreglo, a);

    cout << "Total a pagar: $" << total(arreglo, a) << endl;

    cout << endl;
    return 0;
}