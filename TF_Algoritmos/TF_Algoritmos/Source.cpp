#include <iostream>
using namespace std;


void menu() 
{
	cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << " *                                                     *" << endl;
	cout << " *                       MENU                          *" << endl;
	cout << " *                                                     *" << endl;
	cout << " *        1. Agregar datos a las tablas                *" << endl;
	cout << " *        2. Indexar datos                             *" << endl;
	cout << " *        3. Seleccionar datos                         *" << endl;
	cout << " *        4. Filtrar datos                             *" << endl;
	cout << " *        5. Ordenar datos                             *" << endl;
	cout << " *        6. Exportar datos a un archivo plano         *" << endl;
	cout << " *        7. SALIR                                     *" << endl;
	cout << " *                                                     *" << endl;
	cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
}



int main() 
{
	char opcion;

	do
	{
		menu();
		cin >> opcion;

		switch (switch_on)
		{
		case '1':
			break;

		case '2':
			break;

		case '3':
			break;

		case '4':
			break;

		case '5':
			break;

		case '6':
			break;


		default:
			break;
		}




	} while (opcion != '0');





	system("pause>0");
	return 0;
}