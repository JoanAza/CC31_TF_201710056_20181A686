#include <iostream>
#include "Tabla.h"
using namespace std;

void crearColumnas(vector<CTabla*>& tbl)
{
	string nomCol;
	string datos;
	int cantCol, cantFila;
	int contCol = 1;
	int contFila = 1;
	CTabla* dat = new CTabla();
	system("cls");
	cout << " Cuantas columnas desea agregar: ";
	cin >> cantCol;
	do
	{
		cout << "Ingrese el nombre de la columna " << contCol << ": ";
		cin >> nomCol;
		dat->crearColumna(nomCol, cantCol);
		contCol++;
	} while (contCol <= cantCol);

	cout << endl << "Cuantas filas desea agregar: ";
	cin >> cantFila;

	do
	{
		cout << "Ingrese los datos para la fila " << contFila << ": ";
		cin >> datos;
		dat->crearFila(datos, contFila);
		contFila++;
	} while (contFila <= cantFila);
	tbl.push_back(dat);
}

void insertarDatos()
{

}

void indexar()
{

}

void seleccionar()
{

}

void filtrar()
{

}

void ordenar()
{

}

void exportar()
{

}


void menu() 
{
	cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << " *                                                                     *" << endl;
	cout << " *                                 MENU                                *" << endl;
	cout << " *                                                                     *" << endl;
	cout << " *        1. Crear columnas para la tabla e insertar los datos         *" << endl;
	cout << " *        3. Indexar datos                                             *" << endl;
	cout << " *        4. Seleccionar datos                                         *" << endl;
	cout << " *        5. Filtrar datos                                             *" << endl;
	cout << " *        6. Ordenar datos                                             *" << endl;
	cout << " *        7. Exportar datos a un archivo plano                         *" << endl;
	cout << " *        8. SALIR                                                     *" << endl;
	cout << " *                                                                     *" << endl;
	cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
	cout << " Elige una opcion: ";
}

int main() 
{
	char opcion;
	vector<CTabla*> tbl;
	do
	{
		menu();
		cin >> opcion;

		switch (opcion)
		{
		case '1':
			crearColumnas(tbl);
			break;

		case '2':
			insertarDatos();
			break;

		case '3':
			indexar();
			break;

		case '4':
			seleccionar();
			break;

		case '5':
			filtrar();
			break;

		case '6':
			ordenar();
			break;

		case '7':
			exportar();
			break;
		}
	} while (opcion != '8');

	system("pause");
	return 0;
}