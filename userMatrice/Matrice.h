#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
template <class T>
class Matrice
{
private:
	int colone; int ligne;
	T** TMatrice;
public:
	Matrice(int col, int lig)
	{
		assert(col > 0 and lig > 0);
		this->colone = col;
		this->ligne = lig;
		this->TMatrice = new T * [lig];
		for (int i = 0; i < col; i++)
		{
			this->TMatrice[i] = new T[col];
		}
		//initialisation de tous les cases par 0
		for (int i = 0; i < lig; i++)
			for (int j = 0; j < col; j++)
				this->TMatrice[i][j] = 0;
		
	}
	Matrice(const Matrice&) = delete;
	void remplissage();
	void affichage()const;
	Matrice& operator=(const Matrice&) = delete;
	Matrice* operator+(const Matrice&)const;
	Matrice* operator-(const Matrice&)const;
	Matrice* operator*(const Matrice&)const;
	void produitparSca(const T&);
	~Matrice();
	
};

template<class T>
void Matrice<T>::remplissage()
{
	for (int i = 0; i < this->ligne; i++)
	{
		for (int j = 0; j < this->colone; j++)
		{
			cout << "donner une valeur pour Tab[" << i <<"][" << j << "] = ";
			cin >> this->TMatrice[i][j];
			cout << endl;
		}

	}
}

template<class T>
void Matrice<T>::affichage() const
{
	for (int i = 0; i < this->ligne; i++)
	{
		for (int j = 0; j < this->colone; j++)
		{
			cout << "Tab[" << i << "][" << j << "] = " << this->TMatrice[i][j] << endl;
		}

	}
}

template<class T>
Matrice<T>* Matrice<T>::operator+(const Matrice<T>& M) const
{
	//errer si la matrice n'est pas carrée
	assert((this->colone == M.colone) && (this->ligne == M.ligne));
	Matrice* res = new Matrice(this->ligne, this->colone);
	for (int i = 0; i < this->ligne; i++)
	{
		for (int j = 0; j < this->colone; j++)
		{
			res->TMatrice[i][j] = this->TMatrice[i][j] + M.TMatrice[i][j];
		}
	}
	return res;
}

template<class T>
Matrice<T>* Matrice<T>::operator-(const Matrice<T>& M) const
{
	assert((this->colone == M.colone) && (this->ligne == M.ligne));
	Matrice* res = new Matrice(this->ligne, this->colone);
	for (int i = 0; i < this->ligne; i++)
	{
		for (int j = 0; j < this->colone; j++)
		{
			res->TMatrice[i][j] = this->TMatrice[i][j] - M.TMatrice[i][j];
		}
	}
	return res;
}

template<class T>
Matrice<T>* Matrice<T>::operator*(const Matrice<T>& M) const
{
	assert((this->colone == M.colone) && (this->ligne == M.ligne));
	Matrice* P = new Matrice(this->ligne, this->colone);
	for (int i = 0; i < this->ligne; i++) {
		for (int j = 0; j < M.colone; j++) {
			for (int k = 0; k < M.ligne; k++) {
				P->TMatrice[i][j] += this->TMatrice[i][k] * M.TMatrice[k][j];
			}
		}
	}
	return P;
}

template<class T>
void Matrice<T>::produitparSca(const T& val)
{
	for (int i = 0; i < this->ligne; i++)
	{
		for (int j = 0; j < this->colone; j++)
		{
			this->TMatrice[i][j] = this->TMatrice[i][j] * val;
		}
	}
}

template<class T>
Matrice<T>::~Matrice()
{
	if (this->TMatrice)
	{
		for (int i = 0; i < this->ligne; i++)
		{
			delete[] this->TMatrice[i];
			this->TMatrice[i] = NULL;
		}
		delete[] this->TMatrice;
		this->TMatrice = NULL;
	}
}
