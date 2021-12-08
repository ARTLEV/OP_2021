#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "AllAlg.h"
#include "Sorts.h"

int menu(char** Name_punct, int Number) {
	int result = 0, kod, i = 0;
	system("cls");
	//system("color 3F");
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
	do {
		system("cls");
		for (i = 0; i < Number; i++) {
			if (i == result) {
				//system("color FF");
				// изменить цвет на инверсный
				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED);

				printf("%s\n", Name_punct[i]);
				//system("color 3F");

				//вернуть цвет

				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);

			}
			else {
				printf("%s\n", Name_punct[i]);
			}
		}
		kod = _getch();
		if (kod == 0) {
			kod = _getch();
		}
		else if (kod == 72) // нажата стрелка вверх
		{
			result--;
			if (result < 0) { result = Number - 1; }
		}
		else if (kod == 80) // нажата стрелка вниз
		{
			result++;
			if (result == Number) { result = 0; }
		}
	} while (kod != 13);

	return result;
}

void alrogitms() {
	setlocale(LC_ALL, "rus");

	char** Np;
	int n = 11, m;

	Np = (char**)calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++) {
		Np[i] = (char*)calloc(10 * n, sizeof(char));
	}
	strcpy(Np[0], "Выход");
	strcpy(Np[1], "Сумма n-чисел");
	strcpy(Np[2], "Поиск минимального элемента массива с определением его места в массиве");
	strcpy(Np[3], "Отбор элемента массива по заданному признаку с формированием нового массива");
	strcpy(Np[4], "Линейный поиск");
	strcpy(Np[5], "Бинарный поиск");
	strcpy(Np[6], "Список без повторений");
	strcpy(Np[7], "Список без повторений + рейтинг");
	strcpy(Np[8], "Список без повторений + характеристика");
	strcpy(Np[9], "Деление строки на слова при помощи одного разделителя");
	strcpy(Np[10], "Деление строки на слова в случае разных разделителей");
	do {
		m = menu(Np, n);

		switch (m) {
		case 0:
			system("exit");
			break;
		case 1:
			system("cls");
			alg1();
			break;
		case 2:
			system("cls");
			alg2();
			break;
		case 3:
			system("cls");
			alg3();
			break;
		case 4:
			system("cls");
			alg4();
			break;
		case 5:
			system("cls");
			alg5();
			break;
		case 6:
			system("cls");
			alg6();
			break;
		case 7:
			system("cls");
			alg7();
			break;
		case 8:
			system("cls");
			alg8();
			break;
		case 9:
			system("cls");
			alg9();
			break;
		case 10:
			system("cls");
			alg10();
			break;
		}
	} while (m != 0);
}

void sorts() {
	setlocale(LC_ALL, "rus");

	char** Sp;
	int n = 7, m;

	Sp = (char**)calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++) {
		Sp[i] = (char*)calloc(7 * n, sizeof(char));
	}
	strcpy(Sp[0], "Выход");
	strcpy(Sp[1], "Пузырёк");
	strcpy(Sp[2], "Улучшенный пузырёк");
	strcpy(Sp[3], "Сортировка Шелла");
	strcpy(Sp[4], "Минимальное значение");
	strcpy(Sp[5], "Вставками");
	strcpy(Sp[6], "Слияние");
	do {
		m = menu(Sp, n);

		switch (m) {
		case 0:
			system("exit");
			break;
		case 1:
			system("cls");
			bubble();
			break;
		case 2:
			system("cls");
			SuperBubble();
			break;
		case 3:
			system("cls");
			Shell();
			break;
		case 4:
			system("cls");
			sortirovka_min();
			break;
		case 5:
			system("cls");
			Вставками();
			break;
		case 6:
			system("cls");
			Слияние();
			break;
		}
	} while (m != 0);
}

int main()
{
	setlocale(LC_ALL, "rus");

	char** Np;
	int n = 3, m;

	Np = (char**)calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++) {
		Np[i] = (char*)calloc(3 * n, sizeof(char));
	}
	strcpy(Np[0], "Выход");
	strcpy(Np[1], "Алгоритмы");
	strcpy(Np[2], "Сортировки");
	do {
		m = menu(Np, n);

		switch (m) {
		case 0:
			system("exit");
			break;
		case 1:
			system("cls");
			alrogitms();
			break;
		case 2:
			system("cls");
			sorts();
			break;
		}
	} while (m != 0);
}