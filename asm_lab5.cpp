#include "pch.h"
#include <stdio.h>
#include <iostream>

using namespace std;

void lab5()
{
	double a, b, c, x, y, x1, x2, t;

	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	cout << "Введите c: ";
	cin >> c;
	cout << "Введите левую границу отрезка: ";
	cin >> x1;
	cout << "Введите правую границу отрезка: ";
	cin >> x2;
	cout << "Введите шаг: ";
	cin >> t;

	int key;
	char m1[] = "-----------------------------\n";
	char m2[] = "|      x      |      y      |\n";
	char m3[] = "-----------------------------\n";
	char s0[] = "| %11.3lf | %11.3lf |\n";
	char s1[] = "| %11.3lf | ----------- |\n";
	_asm {
		_asm {
			lea ebx, m1
			push ebx
			call printf
			add esp, 4
			lea ebx, m2
			push ebx
			call printf
			add esp, 4
			lea ebx, m3
			push ebx
			call printf
			add esp, 4

			finit
			fld x1
			fstp x
			fldz
			_begin :
			fld x2
				fsub x
				fcomip st(0), st(1)
				jb _end

				fld c
				fcomip st(0), st(1)
				jnb l2
				fld a
				fcomip st(0), st(1)
				je l2
				fld a
				fchs
				fmul x
				fmul x
				fstp y
				mov key, 0
				jmp l1

				l2 :
				fld c
				fcomip st(0), st(1)
				jbe l3
				fld a
				fcomip st(0), st(1)
				jne l3
				fld x
				fmul c
				fcomip st(0), st(1)
				je l4
				fld x
				fsub a 
				fld x
				fmul c
				fdivp st(1), st(0)
				fstp y
				mov key, 0
				jmp l1

				l3:
				fld c
				fcomip st(0), st(1)
				je l4
				fld x
				fdiv c
				fstp y
				mov key, 0
				jmp l1
				l4:
				mov key, 1

				l1:
				cmp key, 0
				je l5

				sub esp, 8
				fld x
				fstp qword ptr[esp]

				lea eax, s1
				push eax
				call printf
				add esp, 12
				jmp l6
				l5:
				sub esp, 8
				fld y
				fstp qword ptr[esp]
				sub esp, 8
				fld x
				fstp qword ptr[esp]
				lea eax, s0
				push eax
				call printf
				add esp, 20
				l6:
				fld x
				fadd t
				fstp x
				jmp _begin
				_end :
		}
	}
}
