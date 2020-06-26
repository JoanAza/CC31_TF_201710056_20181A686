#ifndef __CCOLUMNA_H__
#define __CCOLUMNA_H__
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

class CColumna {
private:
	string nombre;
	bool numero;
	int filas;
	vector<string> data;
	map<string, int> dato;
	vector<int> vFila;

public:
	CColumna(bool numero = false, int filas = 0): numero(numero), filas(filas) {}
	~CColumna(){}


	bool getMayor();
	bool getMenor();
	bool first();
	bool last();


};
	









#endif // !__CCOLUMNA_H__