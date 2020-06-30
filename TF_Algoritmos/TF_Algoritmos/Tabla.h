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

	void seleccionar(vector<string> coln)
	{
		map<string, CColumna*> colmaptemp;
		for (auto col : colmap) 
		{
			for (auto colname : coln) 
			{
				if (col.first == colname) 
				{
					colmaptemp.insert(pair<string, CColumna*>(col.first, col.second));
				}
			}
		}
		colmap = colmaptemp;
	}
	
	void mostrarTodo() 
	{
		for (auto col : colmap) 
		{
			cout << " " << col.first << "\t\t  ";
		}
		cout << endl;
		for (auto fil : filas) 
		{
			for (auto col : colmap) 
			{
				cout << " " << col.second->getData(fil->getIdx()) << "\t\t      ";
			}
			cout << endl;
		}
	}

	void copy(map<string, CColumna*> col, vector<CFila*> fil) 
	{
		colmap = col;
		filas = fil;
	}

	void InOrder(string colname)
	{
		vector<CFila*> filastemp;
		auto prt = [&](CFila* a) {filastemp.push_back(new CFila(a->getIdx())); };

		tree[colname]->InOrder(prt);
		filas = filastemp;
	}
	void index(string colname) 
	{
		AVLTree <CFila*, string >* t = new AVLTree<CFila*, string>([=](CFila* r) {return colmap[colname]->getData(r->getIdx());});
		for (auto row : this->filas)
		{
			t->Add(row);
		}
		tree[colname] = t;
	}
};
#endif