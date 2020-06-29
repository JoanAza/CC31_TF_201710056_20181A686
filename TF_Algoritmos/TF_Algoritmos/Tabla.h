#ifndef __TABLA_H__
#define __TABLA_H__
#include "AVL.h"
#include "CFila.h"
#include "CColumna.h"
#include <vector>

class CTabla 
{
private:
	map<string, AVLTree<CFila*, string>*> tree;
	map<string, CColumna*> colmap;
	vector<CFila*> filas;
	vector<string> colnames;
	int nCol;

public:
	CTabla() {};
	~CTabla() {};

	bool colesnum(string colname)
	{
		colmap[colname]->isNum();
		return colmap[colname]->getNum();
	}

	vector<CFila*> getFilas()
	{
		return filas;
	};

	map<string, CColumna*> getColmap() 
	{
		return colmap;
	};

	void crearColumna(string nombre, int nCol)
	{
		colmap.insert(pair<string, CColumna*>(nombre, new CColumna()));
		colnames.push_back(nombre);
		this->nCol = nCol;
	}

	void crearFila(string dato, int nFilas)
	{
		int i = --nFilas;
			filas.push_back(new CFila(i));
			stringstream ss(dato);
			for (int j = 0; j < nCol; ++j)
			{
				getline(ss, dato, ',');
				colmap[colnames[j]]->inputData(dato);
			}
	}
	





};
#endif