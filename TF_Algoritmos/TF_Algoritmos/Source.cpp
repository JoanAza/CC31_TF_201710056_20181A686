#include "Tabla.h"


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
		cout << " Ingrese el nombre de la columna " << contCol << ": ";
		cin >> nomCol;
		dat->crearColumna(nomCol, cantCol);
		contCol++;
	} while (contCol <= cantCol);

	cout << endl << " Cuantas filas desea agregar: ";
	cin >> cantFila;

	do
	{
		cout << " Ingrese los datos para la fila " << contFila << ": ";
		cin >> datos;
		dat->crearFila(datos, contFila);
		contFila++;
	} while (contFila <= cantFila);
	tbl.push_back(dat);
	cout << endl << " TABLA CREADA CORRECTAMENTE !!" << endl;
	cout << " ";
	system("pause");
}

void indexar(vector<CTabla*>& tbl)
{
	int i;
	string name;
	do 
	{
		cout << " Seleccionar una TABLA [del 1 al " << tbl.size() << "]: ";
		cin >> i;
		--i;
	} while (i < 0 || i >= tbl.size());
	cout << " Nombre de columna a indexar: ";
	cin >> name;
	tbl[i]->index(name);
	tbl[i]->InOrder(name);
}

void seleccionar(vector<CTabla*>& tbl)
{
	int i;
	char op;
	string name;
	do {
		cout << " Seleccionar una TABLA [del 1 al " << tbl.size() << "]: ";
		cin >> i;
		cout << endl;
		--i;
	} while (i < 0 || i >= tbl.size());
	tbl[i]->mostrarTodo();
	string col;
	vector<string>cols;
	CTabla* nuevo = new CTabla();
	nuevo->copy(tbl[0]->getColmap(), tbl[0]->getFilas());
	int n;

	cout << endl << " Desea seleccionar columnas?" << endl << " S para SI // N para NO: ";
	cin >> op;
	op = toupper(op);
	if (op == 'S')
	{
		cout << endl << " Cuantas columna desea seleccionar: ";
		cin >> n;
		for (int j = 0; j < n; j++) {
			cout << " Ingrese el nombre de la columna: ";
			cin >> col;
			cols.push_back(col);
		}
		nuevo->seleccionar(cols);
		tbl.push_back(nuevo);
		cout << " Se ha creado correctamente otra tabla con la(s) columna(s) seleccionada(s)" << endl << endl;
	}
	cout << " ";
	system("pause");
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
	system("cls");
	cout << endl << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << " *                                                                     *" << endl;
	cout << " *                                 MENU                                *" << endl;
	cout << " *                                                                     *" << endl;
	cout << " *        1. Crear columnas para la tabla e insertar los datos         *" << endl;
	cout << " *        2. Indexar datos                                             *" << endl;
	cout << " *        3. Seleccionar datos                                         *" << endl;
	cout << " *        4. Filtrar datos                                             *" << endl;
	cout << " *        5. Ordenar datos                                             *" << endl;
	cout << " *        6. Exportar datos a un archivo plano                         *" << endl;
	cout << " *        7. SALIR                                                     *" << endl;
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
			indexar(tbl);
			break;

		case '3':
			seleccionar(tbl);
			break;

		case '4':
			filtrar();
			break;

		case '5':
			ordenar();
			break;

		case '6':
			exportar();
			break;
		}
	} while (opcion != '7');

	system("pause");
	return 0;
}