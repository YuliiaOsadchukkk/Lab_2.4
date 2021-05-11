//Matrix.cpp
#include "Matrix.h"
#include <iomanip>

using namespace std;

Matr::Row::Row()
{
	v = new int[1];
	v[0] = 0;
}

Matr::Row::Row(int Col)
{
	v = new int[Col];
	for (int j = 0; j < Col; j++)
		v[j] = 0;
}

Matr::Matr()
{
	Col = 1;
	r = new Row(Col);
	r[0] = Row(Col);
}

Matr::Matr(int Rowa, int Col)
{
	if (Rowa < 1)
		this->Rowa = 1;
	else
		this->Rowa = Rowa;
	if (Col < 1)
		this->Col = 1;
	else
		this->Col = Col;

	r = new Row[this->Rowa];

	for (int i = 0; i < this->Rowa; i++)
	{
		r[i] = Row(this->Col);
	}
}

Matr::Matr(const Matr& a)
{
	Rowa = a.Rowa;
	Col = a.Col;

	r = new Row[this->Rowa];
	for (int i = 0; i < this->Rowa; i++)
	{
		r[i] = Row(this->Col);
	}
	for (int i = 0; i < Rowa; i++)
		for (int j = 0; j < Col; j++)
			r[i][j] = a.r[i][j];
}

Matr:: ~Matr()
{
	for (int i = 0; i < Rowa; i++)
	{
		if (r[i].v != nullptr)
			delete[] r[i].v;
	}

	if (r != nullptr)
		delete[] r;
}

Matr& Matr::operator = (const Matr& a)
{
	for (int i = 0; i < Rowa; i++)
		if (r[i].v != nullptr)
		{

			delete[] r[i].v;
		}
	if (r != nullptr)
	{
		delete[] r;
	}

	Rowa = a.Rowa;
	Col = a.Col;

	r = new Row[this->Rowa];
	for (int i = 0; i < this->Rowa; i++)
	{
		r[i] = Row(this->Col);
	}
	for (int i = 0; i < Rowa; i++)
		for (int j = 0; j < Col; j++)
			r[i][j] = a.r[i][j];

	return *this;
}

Matr::operator string() const
{
	stringstream sout;

		for (int i = 0; i < GetR(); i++)
		{
			for (int k = 0; k < GetC(); k++)
			{
				sout << setw(4) << r[i][k];
			}
			sout << endl;
		}
		return sout.str();
}

Matr operator + (Matr& a, Matr& b)
{
	Matr tmp(a);

	for (int i = 0; i < a.GetR(); i++)
	{
		for (int k = 0; k < a.GetC(); k++)
		{
			tmp[i][k] = a[i][k] + b[i][k];
		}
	}
	return tmp;
}

bool operator == (Matr& a, Matr& b)
{
	if (a.Col != b.Col || a.Rowa != b.Rowa)
		return false;

	for (int i = 0; i < a.GetR(); i++)
	{
		for (int k = 0; k < a.GetC(); k++)
		{
			if (a[i][k] != b[i][k])
				return false;
		}
		cout << endl;
	}
	return true;
}

bool operator != (Matr& a, Matr& b)
{
	if (a.Col != b.Col || a.Rowa != b.Rowa)
		return true;
	else
		return false;

}

bool operator > (Matr& a, Matr& b)
{
	if (a.Col < b.Col || a.Rowa < b.Rowa)
		return false;


	for (int i = 0; i < a.GetR(); i++)
	{
		for (int k = 0; k < a.GetC(); k++)
		{
			if (a[i][k] < b[i][k])
				return false;
		}
	}
	return true;
}

ostream& operator << (ostream& out, const Matr& a)
{
	out << string(a);
	return out;
}

istream& operator >> (istream& in, Matr& a)
{
	for (int i = 0; i < a.GetR(); i++)
	{
		for (int j = 0; j < a.GetC(); j++)
		{
			cout << "Mas[" << i << "][" << j << "] = "; in >> a[i][j];
		}
		cout << endl;
	}
	return in;
}

double Matr::Norm()
{
	int b = 0;

	for (int i = 0; i < this->GetR(); i++)
	{
		for (int k = 0; k < this->GetC(); k++)
		{
			int f = 0;
			int e = 0;
			if (f > r[i][k])//max
				f = r[i][k];
			if (e < r[i][k])//min
				e = r[i][k];

			b = (f - e);
		}
		cout << endl;
	}
	return abs(b);
}   


