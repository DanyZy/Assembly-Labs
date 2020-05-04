#include "pch.h"
#include <iostream>

using namespace std;

void lab2()
{
	setlocale(0, "Russian");

	cout << "Задание: Summ(Ai * Bi) * X + Summ(Ci) * Y" << endl;

	int A[3];
	int B[3];
	int C[3];
	int X, Y;
	int res = 0;
	int res2 = 0;

	for (int i = 0; i < 3; i++)
	{
		cout << "Введите " << i + 1 << " элемент массива A: ";
		cin >> A[i];
	}
	cout << "\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "Введите " << i + 1 << " элемент массива B: ";
		cin >> B[i];
	}
	cout << "\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "Введите " << i + 1 << " элемент массива C: ";
		cin >> C[i];
	}

	cout << "\nВведите переменную X: ";
	cin >> X;
	cout << "Введите переменную Y: ";
	cin >> Y;

	res2 = (A[0] * B[0] + A[1] * B[1] + A[2] * B[2])
		* X + (C[0] + C[1] + C[2]) * Y;

	_asm {
		mov dword ptr res, 0
		mov esi, 0
		mov edi, 0
		mov ecx, 3
		lea ebx, A
		lea edx, B
		cycle1:
			mov esi, [ebx]
			mov edi, [edx]
			imul esi, edi
			push esi
			add ebx, 4
			add edx, 4
			loop cycle1
		mov eax, 0
		mov ecx, 3
		cycle2:
			pop esi
			add eax, esi
			loop cycle2
		imul X
		mov esi, 0
		mov edi, 0
		mov ecx, 3
		lea ebx, C
		cycle3:
			mov esi, [ebx]
			add edi, esi
			add ebx, 4
			loop cycle3
		imul edi, Y
		add eax, edi
		mov res, eax
	}

	cout << "Результат вычислений на языке ассемблера: " << res << endl;
	cout << "Результат вычислений на языке С++: " << res2 << endl;
}
