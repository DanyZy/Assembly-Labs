#include "pch.h"
#include <iostream>
#include "labs.h"
#include <string>

using namespace std;

void print_menu() {
	system("cls");
	cout << "Выберите номер лабораторной работы\nили введите 6 для выхода:" << endl;
	cout << ">";
}

int get_variant(int count) {
	int variant;
	string s;
	getline(cin, s);

	while (sscanf_s(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
		cout << "Неправильный номер, попробуйте еще раз: ";
		getline(cin, s);
	}

	return variant;
}

int main()
{
	setlocale(0, "Russian");
	int variant;

	do {
		print_menu();

		variant = get_variant(6);

		switch (variant) {
		case 1:
			lab1();
			break;

		case 2:
			lab2();
			break;

		case 3:
			lab3();
			break;

		case 4:
			lab4();
			break;

		case 5:
			lab5();
			break;
		}

		if (variant != 6)
			system("pause");

	} while (variant != 6);
	return 0;
}
