#include "Tabla.h"


void crearTabla(vector<CTabla*>& tbl)
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
		cout << endl;
		--i;
	} while (i < 0 || i >= tbl.size());
	tbl[i]->mostrarTodo();
	cout << endl << " Nombre de columna a indexar: ";
	cin >> name;
	tbl[i]->index(name);
	tbl[i]->InOrder(name);
	cout << endl << "LA COLUMNA HA SIDO INDEXADA CORRECTAMENTE !!!" << endl;
	cout << " ";
	system("pause");
}

void seleccionar(vector<CTabla*>& tbl)
{
	int i;
	char op;

	do 
	{
		cout << " Seleccionar una TABLA [del 1 al " << tbl.size() << "]: ";
		cin >> i;
		cout << endl;
		--i;
	} while (i < 0 || i >= tbl.size());
	tbl[i]->mostrarTodo();
	string col;
	vector<string>cols;
	CTabla* nuevo = new CTabla();
	nuevo->copy(tbl[i]->getColmap(), tbl[i]->getFilas());
	int n;

	cout << endl << " Desea seleccionar columnas?" << endl << " S para SI // N para NO: ";
	cin >> op;
	op = toupper(op);
	if (op == 'S')
	{
		cout << endl << " Cuantas columnas desea seleccionar: ";
		cin >> n;
		for (int j = 0; j < n; j++) {
			cout << " Ingrese el nombre de la columna "<< j + 1 <<": ";
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

void filtrar(vector<CTabla*>& tbl)
{
	system("cls");
	int i, n;
	char op, opConsulta, c;
	string nombre, palabra;

	do
	{
		do
		{
			cout << " Seleccionar una TABLA [del 1 al " << tbl.size() << "]: ";
			cin >> i;
			cout << endl;
			--i;
		} while (i < 0 || i >= tbl.size());
		tbl[i]->mostrarTodo();

		cout << endl << " 1. Mayor:" << endl
			<< " 2. Menor: " << endl
			<< " 3. Igual a: " << endl
			<< " 4. Inicia con: " << endl
			<< " 5. Finaliza con: " << endl
			<< " 6. Contenido en: " << endl
			<< " 7. No contenido en: " << endl
			<< endl << " Elige una opcion: ";

		cin >> op;
		cout << " Elige una columna: ";
		cin.get();
		getline(cin, nombre);

		CTabla* nuevo = new CTabla();
		nuevo->copy(tbl[i]->getColmap(), tbl[i]->getFilas());
		if (nuevo->colesnum(nombre))
		{
			switch (op)
			{
			case '1':
				cout << " Ingrese un numero: ";
				cin >> n;
				nuevo->Filtra_Mayor_Num(nombre, n);
				system("cls");
				nuevo->mostrarTodo();
				break;
			case '2':
				cout << " Ingrese un numero: ";
				cin >> n;
				nuevo->Filtra_Menor_Num(nombre, n);
				system("cls");
				nuevo->mostrarTodo();
				break;
			case '3':
				cout << " Ingrese un numero: ";
				cin >> n;
				nuevo->Filtra_Igual_Num(nombre, n);
				system("cls");
				nuevo->mostrarTodo();
				break;
			case '4':
				cout << " Ingrese un numero: ";
				cin >> c;
				nuevo->Filtra_Empieza(nombre, c);
				system("cls");
				nuevo->mostrarTodo();
				break;
			case '5':
				cout << " Ingrese un numero: ";
				cin >> c;
				nuevo->Filtra_Termina(nombre, c);
				system("cls");
				nuevo->mostrarTodo();
				break;
			case '6':
				cout << " Ingrese un numero: ";
				cin >> palabra;
				nuevo->Filtra_Contiene(nombre, palabra);
				system("cls");
				nuevo->mostrarTodo();
				break;
			case '7':
				cout << " Ingrese un numero: ";
				cin >> palabra;
				nuevo->Filtra_No_Contiene(nombre, palabra);
				system("cls");
				nuevo->mostrarTodo();
				break;
			}
		}

		else
		{
			switch (op)
			{
			case '1':
				cout << " Ingrese una palabra o letra: ";
				cin >> palabra;
				nuevo->Filtra_Mayor_letras(nombre, palabra);
				system("cls");
				nuevo->mostrarTodo();
				break;
			case '2':
				cout << " Ingrese una palabra o letra: ";
				cin >> palabra;
				nuevo->Filtra_Menor_letras(nombre, palabra);
				system("cls");
				nuevo->mostrarTodo();
				break;
			case '3':
				cout << " Ingrese una palabra o letra: ";
				cin >> palabra;
				nuevo->Filtra_Igual_letras(nombre, palabra);
				system("cls");
				nuevo->mostrarTodo();
				break;
			case '4':
				cout << " Ingrese una palabra o letra: ";
				cin >> c;
				nuevo->Filtra_Empieza(nombre, c);
				system("cls");
				nuevo->mostrarTodo();
				break;
			case '5':
				cout << " Ingrese una palabra o letra: ";
				cin >> c;
				nuevo->Filtra_Termina(nombre, c);
				system("cls");
				nuevo->mostrarTodo();
				break;
			case '6':
				cout << " Ingrese una palabra o letra: ";
				cin >> palabra;
				nuevo->Filtra_Contiene(nombre, palabra);
				system("cls");
				nuevo->mostrarTodo();
				break;
			case '7':
				cout << " Ingrese una palabra o letra: ";
				cin >> palabra;
				nuevo->Filtra_No_Contiene(nombre, palabra);
				system("cls");
				nuevo->mostrarTodo();
				break;
			}
		}
		cout << endl << endl << " Desea realizar otra consulta ?";
		cout << " S para SI // N para NO: ";
		cin >> opConsulta;
		opConsulta = toupper(opConsulta);
		system("cls");
	} while (opConsulta != 'N');
	
	cout << " ";
	system("pause");
}

void ordenar(vector<CTabla*>& tbl)
{
	system("cls");
	int i;
	string name;
	do
	{
		cout << " Seleccionar una TABLA [del 1 al " << tbl.size() << "]: ";
		cin >> i;
		cout << endl;
		--i;

	} while (i < 0 || i >= tbl.size());
	cout << endl << " Ingrese el nombre de columna a ordenar:";
	cin >> name;
	tbl[i]->Ordenar(name);
	tbl[i]->mostrarTodo();
	cout << " ";
	system("pause");
}

void exportar(vector<CTabla*>& tbl)
{
	int i;
	string name;
	do
	{
		cout << " Seleccionar una TABLA [del 1 al " << tbl.size() << "]: ";
		cin >> i;
		cout << endl;
		--i;
	} while(i < 0  || i >= tbl.size());
	tbl[i]->mostrarTodo();
	cout << endl << " Nombre de la Nueva tabla: "; 
	cin >> name;
	tbl[i]->GuardaTabla(name);
	cout << endl << endl <<  "ARCHIVO CREADO CORRECTAMENTE !!";
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
			crearTabla(tbl);
			break;

		case '2':
			indexar(tbl);
			break;

		case '3':
			seleccionar(tbl);
			break;

		case '4':
			filtrar(tbl);
			break;

		case '5':
			ordenar(tbl);
			break;

		case '6':
			exportar(tbl);
			break;
		}
	} while (opcion != '7');
	system("pause");
	return 0;
}