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

	void mostraColumnas() 
	{
		map<string, CColumna*> ::iterator it;
		for (it = colmap.begin(); it != colmap.end(); it++) 
		{
			cout << it->first << "\t";
		}
	}

	void mostraColumna(string nombreCol) 
	{
		if (colmap[nombreCol] != nullptr)
			colmap[nombreCol]->showData();
	}

	void cargarTabla(string nombre, int ncol)
	{
		this->nCol = ncol;
		ifstream data;
		data.open(nombre);
		string line;
		getline(data, line);
		stringstream ss(line);
		for (int j = 0; j < ncol; j++)
		{
			getline(ss, line, ',');
			colmap.insert(pair<string, CColumna*>(line, new CColumna()));
			colnames.push_back(line);
		}
		int i = 0;
		while (getline(data, line)) 
		{
			filas.push_back(new CFila(i));
			stringstream ss(line);
			for (int j = 0; j < ncol; j++)
			{
				getline(ss, line, ',');
				colmap[colnames[j]]->inputData(line);
			}
		}

	}

  	void GuardaTabla(string nombre) 
	{
		ofstream data;
		int cont1 = 1;
		int cont2 = 1;
		data.open(nombre);
		for (auto col : colmap)	
		{
			data << col.first;
			if (cont1 < nCol)
				data << ",";
			cont1++;
		}
		data << endl;
		
		for (auto fil : filas){
			cont2 = 1;
			for (auto col : colmap){
				data << col.second->getData(fil->getIdx());
				if (cont2 < nCol)
					data << ",";
				cont1++;
			}
			data << endl;
		}
	}

	void mostrarTodo() 
	{
		for (auto col : colmap)
		{
			cout << " " << col.first << "\t\t  ";
		}
		cout << endl << endl;

		for (auto fil : filas) 
		{
			for (auto col : colmap) 
			{
				cout << " " << col.second->getData(fil->getIdx()) << "\t\t      ";
			}
			cout << endl;
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

	void Ordenar(string colname) 
	{
		vector<int> filastpm;
		filastpm = colmap[colname]->sort();
		for (int j = 0; j < filas.size(); j++)
		{
			filas[j]->setIdx(filastpm[j]);
		}
	}

	// funciones Numero

	void Filtra_Mayor_Num(string nCol, int num) 
	{
		vector<string> temp;
		vector <CFila*> filtemp;
		for (auto fil : filas)
		{
			if(colmap[nCol]->getMayorNumero(num, fil->getIdx()) == true)
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}
	void Filtra_Menor_Num(string nCol, int num) 
	{
		vector<string> temp;
		vector <CFila*> filtemp;
		for (auto fil : filas)
		{
			if (colmap[nCol]->getMenorNumero(num, fil->getIdx()) == true) 
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}
	void Filtra_Igual_Num(string nCol, int num) 
	{
		vector<string> temp;
		vector <CFila*> filtemp;
		for (auto fil : filas)
		{
			if (colmap[nCol]->getIgualNumero(num, fil->getIdx()) == true) 
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}

	// funciones Letras
	void Filtra_Mayor_letras(string nCol, string letra) 
	{
		vector<string> temp;
		vector <CFila*> filtemp;
		for (auto fil : filas)
		{
			if (colmap[nCol]->getMayorLetra(letra, fil->getIdx()) == true) 
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}

	void Filtra_Menor_letras(string nCol, string letra) 
	{
		vector<string> temp;
		vector <CFila*> filtemp;
		for (auto fil : filas)
		{
			if (colmap[nCol]->getMenorLetra(letra, fil->getIdx()) == true) 
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}

	void Filtra_Igual_letras(string nCol, string letra) 
	{
		vector<string> temp;
		vector <CFila*> filtemp;
		for (auto fil : filas)
		{
			if (colmap[nCol]->getIgualLetra(letra, fil->getIdx()) == true) 
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}

	// funcion especial

	void Filtra_Empieza(string nCol, char c) 
	{
		vector<string> temp;
		vector <CFila*> filtemp;
		for (auto fil : filas)
		{
			if (colmap[nCol]->front(c, fil->getIdx()) == true) 
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}

	void Filtra_Termina(string nCol, char c) 
	{
		vector<string> temp;
		vector <CFila*> filtemp;
		for (auto fil : filas)
		{
			if (colmap[nCol]->back(c, fil->getIdx()) == true) 
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}

	void Filtra_Contiene(string nCol, string var) 
	{
		vector<string> temp;
		vector <CFila*> filtemp;
		for (auto fil : filas)
		{
			if (colmap[nCol]->getContiene(var, fil->getIdx()) == true) 
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}

	void Filtra_No_Contiene(string nCol, string var) 
	{
		vector<string> temp;
		vector <CFila*> filtemp;
		for (auto fil : filas)
		{
			if (colmap[nCol]->getNoContiene(var, fil->getIdx()) == true) 
			{
				temp.push_back(colmap[nCol]->getData(fil->getIdx()));
				filtemp.push_back(fil);
			}
		}
		this->filas = filtemp;
	}
};
#endif