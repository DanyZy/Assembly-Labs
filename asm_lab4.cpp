#include "pch.h"
#include <iostream>
#include <windows.h>

DWORD len(char* s)
{
	DWORD l = 0;
	__asm
	{
		cld
		mov edi, s
		mov esi, edi
		mov ecx, 0ffffffffh
		xor al, al
		repne scasb
		sub edi, esi
		dec edi
		mov l, edi
	}
	return l;
}

void lab4()
{
	char task[] = "Создать строку, полученную копированием исходной строки заданное число раз.\nВведите строку и число ее повторений: ";

	char s[256];
	char f1[] = "%s%i";
	char f2[] = "\n";
	int i = 5;
	char res[256] = "";

	_asm {
		cld
		lea eax, task
		push eax
		call printf
		pop eax
		xor eax, eax

		lea edx, i
		push edx
		lea ebx, s
		push ebx
		lea ecx, f1
		push ecx
		call scanf
		pop eax
		xor eax, eax
		call len
		pop esi
		pop edx
		xor edx, edx

		lea edi, res
		mov ecx, i
		cyc:
			push ecx
			lea esi, s
			mov ecx, eax
		    rep movsb 
			pop ecx
			loop cyc

		lea esi, f2
		mov ecx, 2
		rep movsb
		lea eax, res
		push eax
		call printf
		pop eax
		xor eax, eax
	}
}