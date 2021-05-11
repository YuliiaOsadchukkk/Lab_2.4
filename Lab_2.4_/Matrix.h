//Matrix.h
#pragma once
#include <iostream>	
#include <string>
#include <sstream>	

using namespace std;

class Matr
{
	class Row;
	int Rowa, Col;
	Row* r;

	class Row
	{
	public:
		int* v;

		Row();
		Row(int Col);
		int& operator [] (int j) { return v[j]; }
		const int& operator [] (const int i) const { return v[i]; }
	};

public:
	int GetC() const { return Col; }
	int GetR() const { return Rowa; }

	Matr();
	Matr(int Rowa, int Col);
	Matr(const Matr& a);
	~Matr();

	Row& operator [] (int i) { return r[i]; }
	const Row& operator [] (const int i) const { return r[i]; }
   
	Matr& operator = (const Matr& a);
	operator string() const;

	friend ostream& operator << (ostream& out, const Matr& a);
	friend istream& operator >> (istream& in, Matr& a);

	friend Matr operator + (Matr& a, Matr& b);//Matrix1 + Matrix2
	friend bool operator ==(Matr& a, Matr& b);//equal
	friend bool operator !=(Matr& a, Matr& b);//size
    friend bool operator >(Matr& a, Matr& b);//bigger/smaller
    double Norm();
};

