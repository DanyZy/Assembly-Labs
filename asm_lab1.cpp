#include "pch.h"
#include <iostream>

using namespace std;

void lab1()
{
	setlocale(0, "Russian");

	int A, B, C, D, X, res;
	cout << "A * X^3 + B * X^2 + C div X + (D div X) div X" << endl;
	cout << "Введите число A: ";
	cin >> A;
	cout << "Введите число B: ";
	cin >> B;
	cout << "Введите число C: ";
	cin >> C;
	cout << "Введите число D: ";
	cin >> D;
	cout << "Введите число X: ";
	cin >> X;
	
	res = A * (int)pow(X, 3) + B * (int)pow(X, 2) + C / X + (D / X) / X;

	_asm
	{
		mov eax, A
		imul X
		imul X
		imul X
		mov A, eax
		mov eax, B
		imul X
		imul X
		add A, eax
		mov eax, C
		cdq
		idiv X
		add A, eax
		mov eax, D
		cdq
		idiv X
		cdq
		idiv X
		add A, eax
	}

	cout << "Результат вычислений на языке ассемблера: " << A << endl;
	cout << "Результат вычислений на языке С++: " << res << endl;
}