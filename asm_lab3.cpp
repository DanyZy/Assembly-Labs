#include "pch.h"
#include <iostream>

using namespace std;

void lab3()
{
	unsigned char A, C, res=0;
	int B;
	cout << "Реализуйте с помощью логических операций вставку заданного значения (0 или 1)\nв любой бит байта со сдвигом влево и потерей крайнего бита." << endl;

	cout << "Введите символ: ";
	cin >> A;
	cout << "Введите смещение: ";
	cin >> B;
	cout << "Введите бит-вставку (0 или 1): ";
	cin >> C;

	_asm {
		mov al, A
		mov ah, al
		mov ecx, B
		xor edx, edx
		bts edx, ecx
		dec edx
		and al, dl
		not dl
		and ah, dl
		shl ah, 1
		or al, ah
		mov ah, C
		shl ah, cl
		or al, ah
		mov res, al
	}

	cout << "Результат: " << res << endl;
}