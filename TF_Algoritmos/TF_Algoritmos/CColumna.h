#ifndef __CCOLUMNA_H__
#define __CCOLUMNA_H__
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

class CColumna 
{
private:
	string nombre;
	bool numero;
	int filas;
	vector<string> data;
	map<string, int> mDato;
	vector<int> vfila;

public:
	CColumna(bool numero = false, int filas = 0): numero(numero), filas(filas) {}
	~CColumna(){}

	bool isNumber(string str) 
	{
		for (int i = 0; i < str.length(); i++) 
		{
			if (isdigit(str[i]) == false) // isdigit se usa para verificar si el primer car�cter en str es un d�gito y, por lo tanto, un candidato v�lido para ser convertido por atoi en un valor entero.
				return false;
			return true;
		}
	}
	void isNum()
	{
		if (isNumber(data[0]))
		{
			numero = true;
		}
		else
		{
			numero = false;
		};
	}
	
	void inputData(string dato)
	{
		data.push_back(dato);
	}
	string getData(int idx) 
	{
		return data[idx];
	}
	bool getNum()
	{
		return numero;
	}

	void showData() 
	{
		for (auto dat : data) 
		{
			cout << dat << endl;
		}
	}

	vector<int> sort()
	{
		vector<string> datatmp = data;
		quicksort(datatmp, datatmp[0], datatmp[datatmp.size() - 1]);
		for (int i = 0; i < datatmp.size(); i++) 
		{
			for (int j = 0; j < data.size(); j++) 
			{
				if (datatmp[i] == data[j]) 
				{
					vfila.push_back(j);
				}
			}
		}
		return vfila;
	}
	void quicksort(vector<string>& names, string min, string max) 
	{
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
			while (temp < names.size()) 
			{
				if (names[temp] <= pivot) {
					if (lowMax.compare(names[temp]) < 0) 
					{
						lowMax = names[temp];
					}
					if (lowMin.compare(names[temp]) > 0) 
					{
						lowMin = names[temp];
					}
					below.push_back(names[temp]);
				}
				else 
				{
					if (highMax.compare(names[temp]) < 0) 
					{
						highMax = names[temp];
					}
					if (highMin.compare(names[temp]) > 0) 
					{
						highMin = names[temp];
					}
					above.push_back(names[temp]);
				}
				temp++;
			}
			if ((below.size() > 1) && (names.size() != below.size())) 
			{
				quicksort(below, lowMin, lowMax);
			}
			if ((above.size() > 1) && (names.size() != above.size())) 
			{
				quicksort(above, highMin, highMax);
			}
			for (size_t i = 0; i < below.size(); i++) 
			{
				names[i] = below[i];
			}
			for (size_t i = below.size(); i < names.size(); i++) 
			{
				names[i] = above[i - below.size()];
			}
		}
	}

	// letras
	bool getIgualLetra(string var, int ind)  // para palbras
	{
		if (data[ind] == var)
			return true;
		else
			return false;
	}
	bool getMayorLetra(string var, int ind)  // palabras
	{
		if (data[ind].compare(var) > 0)
			return true;
		else
			return false;
	}
	bool getMenorLetra(string var, int ind)  // palabras
	{
		if (data[ind].compare(var) < 0)
			return true;
		else
			return false;
	}

	bool front(char c, int ind) 
	{
		if (data[ind].front() == c)
			return true;
		else
			return false;
	}
	bool back(char c, int ind)
	{
		if (data[ind].back() == c)
			return true;
		else
			return false;
	}

	bool getContiene(string var, int ind) 
	{
		if (data[ind].find(var) == string::npos) // lee hasta el fin de la cadena y busca la palabra
			return false;
		else
			return true;
	}
	bool getNoContiene(string var, int ind) 
	{
		if (data[ind].find(var) == string::npos)// lee hasta el fin de la cadena y busca la palabra
			return true;
		else
			return false;
	}

	// numeros
	bool getIgualNumero(int var, int ind) 
	{
		if (stoi(data[ind]) == var)
			return true;
		else
			return false;

		/*return (stoi(data[ind]) == var ? return true : false);*/
	}
	bool getMayorNumero(int var, int ind) 
	{
		if (stoi(data[ind]) > var)
			return true;
		else
			return false;
	}
	bool getMenorNumero(int var, int ind) 
	{
		if (stoi(data[ind]) < var)
			return true;
		else
			return false;
	}
};
#endif // !__CCOLUMNA_H__