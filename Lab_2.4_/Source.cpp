//Source.cpp
#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	int Row1, Col1, Row2, Col2;

	cout << "Matrix A:" << endl;
	cout << "Row = "; cin >> Row1;
	cout << "Col = "; cin >> Col1;
	Matr a(Row1, Col1);
	cin >> a;
	
	cout << "Matrix B:" << endl;
	cout << "Row = "; cin >> Row2;
	cout << "Col = "; cin >> Col2;
	Matr b(Row2, Col2);
	cin >> b;

	cout << "Matrix A:" << endl;
	cout << a << endl;
	cout << "Matrix B:" << endl;
	cout << b << endl;

	if (a != b)
	{
		cout << "Matrix C(Sum):" << endl;
		cout << "Matrix sizes are not the same, so we can not search their sum" << endl;
	}
	else
	{
		cout << "Matrix C(Sum):" << endl;
		Matr c = a + b;
		cout << c << endl;
	}

	cout << endl;
	if (a != b)
	{
		cout << "Matrix sizes are not the same" << endl;

		if (a > b)
			cout << "Matrix A is bigger than Matrix B" << endl;
		else
			cout << "Matrix A is smaller than Matrix B" << endl;
	}
	else
	{
		cout << "Matrix sizes are the same" << endl;
	
	     if (a == b)
		    cout << "Matrix are equal" << endl;
		 else
		    cout << "Matrix are not equal" << endl;
	}

	cout << endl;
	cout << "Norm (Matrix A) = " << a.Norm() << endl;//////////////qqq
	cout << "Size of class = " << sizeof(a) << endl;////////////////qqq

	return 0;
}
