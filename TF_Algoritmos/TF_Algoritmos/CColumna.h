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
	vector<int> vfila;

public:
	CColumna(bool numero = false, int filas = 0): numero(numero), filas(filas) {}
	~CColumna(){}

	bool getNumero(string str) {
		for (int i = 0; i < str.length(); i++) 
		{
			if (isdigit(str[i]) == false) // isdigit se usa para verificar si el primer carácter en str es un dígito y, por lo tanto, un candidato válido para ser convertido por atoi en un valor entero.
				return false;
			return true;
		}
	}
	string getData(int idx) {
		return data[idx];
	}

	vector<int> Ordenar()
	{
		vector<string> datatmp = data;
		quicksort(datatmp, datatmp[0], datatmp[datatmp.size() - 1]);
		for (int i = 0; i < datatmp.size(); i++) {
			for (int j = 0; j < data.size(); j++) {
				if (datatmp[i] == data[j]) {
					vfila.push_back(j);
				}
			}
		}
		return vfila;
	}
	void quicksort(vector<string>& names, string min, string max) {
		vector<string> tempData;
		int temp = 0, i = 0;
		string lowMin = max,
			lowMax = min,
			highMin = max,
			highMax = min,
			pivot;
		vector<string>  below, above;
		if (min != max) {
			pivot = (max[i] + min[i]) / 2;
			while (temp < names.size()) {
				if (names[temp] <= pivot) {
					if (lowMax.compare(names[temp]) < 0) {
						lowMax = names[temp];
					}
					if (lowMin.compare(names[temp]) > 0) {
						lowMin = names[temp];
					}
					below.push_back(names[temp]);
				}
				else {
					if (highMax.compare(names[temp]) < 0) {
						highMax = names[temp];
					}
					if (highMin.compare(names[temp]) > 0) {
						highMin = names[temp];
					}
					above.push_back(names[temp]);
				}
				temp++;
			}
			if ((below.size() > 1) && (names.size() != below.size())) {
				quicksort(below, lowMin, lowMax);
			}
			if ((above.size() > 1) && (names.size() != above.size())) {
				quicksort(above, highMin, highMax);
			}
			for (size_t i = 0; i < below.size(); i++) {
				names[i] = below[i];
			}
			for (size_t i = below.size(); i < names.size(); i++) {
				names[i] = above[i - below.size()];
			}

		}

	}


	bool sameString(string var, int ind) {
		if (data[ind] == var)
			return true;
		else
			return false;
	}
	bool getMayor(string var, int ind) {
		if (data[ind].compare(var) > 0)
			return true;
		else
			return false;
	}
	bool getMenor(string var, int ind) {
		if (data[ind].compare(var) < 0)
			return true;
		else
			return false;
	}
	bool front(int ind, char c) {
		if (data[ind].front() == c)
			return true;
		else
			return false;
	}
	bool back(int ind, char c) {
		if (data[ind].back() == c)
			return true;
		else
			return false;
	}


	bool getnoIn();//pendiente

};
	









#endif // !__CCOLUMNA_H__