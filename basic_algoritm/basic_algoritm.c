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

void alg1() {
	int N;
	int sum;
	int i;
	int* a;
	setlocale(LC_ALL, "rus");
	printf("Введите кол-во чисел: ");
	scanf_s("%d", &N);
	a = (int*)calloc(N, sizeof(int));
	printf("Введите числа: ");
	for (i = 0; i < N; i++) {
		scanf_s("%d", &a[i]);
	}
	sum = summing(a, N);
	printf("Сумма чисел равна %d", sum);
	_getch();
	return 0;
}

void alg2() {
	int* a;
	int n;
	int min, l;

	setlocale(LC_ALL, "rus");

	printf("Введите кол-во чисел: ");
	scanf_s("%d", &n);

	a = (int*)calloc(n, sizeof(int));

	printf("Введите список:\n");

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}

	min = a[0];
	l = 0;

	min_number(a, n, &min, &l);

	printf("Минимальное число: %d Его индекс %d", min, l);
	_getch();
	return 0;
}

void alg3() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int N;
	char tmp[255];
	char** Names;
	char** NewNames;
	char param[2];

	printf("Введите количество элементов: \n");
	scanf_s("%d", &N);

	Names = (char**)calloc(N, sizeof(char*));

	printf("Введите элементы:\n");
	for (int i = 0; i < N; i++) {
		scanf_s("%s", &tmp);
		int len = strlen(tmp) + 2;
		Names[i] = (char*)calloc(len, sizeof(char));
		strcpy(Names[i], tmp);
	}

	printf("Введите букву: \n");

	scanf_s("%s", &param);

	int k = otbor_elem(Names, N, param[0], &NewNames);

	printf("Новый список:\n");

	for (int i = 0; i < k; i++) {
		printf("[%d] = %s\n", i, NewNames[i]);
	}
	_getch();
	return 0;
}

void alg4() {
	int N, i, len;
	char** name;
	char* ctrl;
	char tmp[255];

	rsize_t l;

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf_s("Введите кол-во N: ");
	scanf_s("%d", &N);

	name = (char**)calloc(N, sizeof(char*));

	printf("Введи список:\n");

	for (i = 0; i < N; i++) {

		scanf_s("\n");
		fgets(tmp, 255, stdin);
		len = strlen(tmp) + 2;
		l = sizeof(rsize_t);
		name[i] = (char*)calloc(len, sizeof(char));

		strcpy_s(name[i], l * len, tmp);
	}

	printf("Введите искомое слово: ");
	scanf_s("\n");
	fgets(tmp, 255, stdin);

	len = strlen(tmp) + 2;
	l = sizeof(rsize_t);
	ctrl = (char*)calloc(len, sizeof(char));

	strcpy_s(ctrl, len, tmp);

	printf("Линейный поиск %d\n", linear_search(name, ctrl, N));
	_getch();
	return 0;
}

void alg5() {
	int N, i, len;
	char** name;
	char* ctrl;
	char tmp[255];

	rsize_t l;

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf_s("Введите кол-во N: ");
	scanf_s("%d", &N);

	name = (char**)calloc(N, sizeof(char*));

	printf("Введи список: \n");

	for (i = 0; i < N; i++) {

		scanf_s("\n");
		fgets(tmp, 255, stdin);
		len = strlen(tmp) + 2;
		l = sizeof(rsize_t);
		name[i] = (char*)calloc(len, sizeof(char));

		strcpy_s(name[i], l * len, tmp);
	}

	printf("Введите искомое слово: ");
	scanf_s("\n");
	fgets(tmp, 255, stdin);

	len = strlen(tmp) + 2;
	l = sizeof(rsize_t);
	ctrl = (char*)calloc(len, sizeof(char));

	strcpy_s(ctrl, len, tmp);

	printf("Бинарный поиск %d\n", binary_search(name, ctrl, N));
	_getch();
	return 0;
}

void alg6() {
	char tmp[255];
	char** name;
	char** list;
	int N;

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	printf("Введите количество элементов: \n");
	scanf_s("%d", &N);

	name = (char**)calloc(N, sizeof(char*));
	list = (char**)calloc(N, sizeof(char*));

	for (int i = 0; i < N; i++) {
		scanf_s("%s", &tmp);
		int len = strlen(tmp);
		name[i] = (char*)calloc(len + 2, sizeof(char));
		strcpy(name[i], tmp);
	}

	int k = spisok_bez_povtoreniy(name, N, &list);

	printf("Список без повторений\n");
	for (int i = 0; i < k; i++) {
		printf("[%d] = %s\n", i, list[i]);
	}
	_getch();
	return 0;
}

void alg7() {
	char tmp[255];
	char** name;
	char** list;
	int* Rate;
	int N;

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	printf("Введите количество элементов: ");
	scanf_s("%d", &N);

	name = (char**)calloc(N, sizeof(char*));
	list = (char**)calloc(N, sizeof(char*));
	Rate = (int*)calloc(N, sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf_s("%s", &tmp);
		int len = strlen(tmp);
		name[i] = (char*)calloc(len + 2, sizeof(char));
		strcpy(name[i], tmp);
	}

	int k = spisok_bez_povtoreniy_rate(name, N, &list, &Rate);

	printf("Список без повторений и подсчет рейтинга\n");
	for (int i = 0; i < k; i++) {
		printf("[%d] = %s Его рейтинг %d\n", i, list[i], Rate[i]);
	}
	_getch();
	return 0;
}

void alg8() {
	char tmp[255];
	char** name;
	char** list;
	int* Sum;
	int* CH;
	int N;

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Введите количество элементов: ");
	scanf_s("%d", &N);

	name = (char**)calloc(N, sizeof(char*));
	list = (char**)calloc(N, sizeof(char*));
	CH = (int*)calloc(N, sizeof(int));
	Sum = (int*)calloc(N, sizeof(int));

	printf("Введите название элемента и его характеристику\n");
	for (int i = 0; i < N; i++) {
		scanf_s("%s %d", &tmp, &CH[i]);
		int len = strlen(tmp);
		name[i] = (char*)calloc(len + 2, sizeof(char));
		strcpy(name[i], tmp);
	}

	int k = spisok_bez_povtoreniy_sum(name, N, CH, &list, &Sum);

	printf("Список без повторений и подсчет рейтинга\n");
	for (int i = 0; i < k; i++) {
		printf("[%d] = %s\n Характеристика %d\n", i, list[i], Sum[i]);
	}
	_getch();
	return 0;
}

void alg9() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char data[100];
	char** result;

	printf("Введите строку: ");
	fgets(data, 100, stdin);

	int len = strlen(data) + 2;

	result = (char**)calloc(len, sizeof(char*));

	int k = string_split(data, " ", &result);

	for (int i = 0; i < k; i++) {
		printf("[%d] %s\n", i, result[i]);
	}
	_getch();
	return 0;
}

void alg10() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char data[100];
	char** result;
	char razd[] = ",/.'[]*-+ ";

	printf("Введите строку: ");
	fgets(data, 100, stdin);

	int len = strlen(data) + 2;

	result = (char**)calloc(len, sizeof(char*));

	int k = string_split_smart(data, razd, &result);

	for (int i = 0; i < k; i++) {
		printf("[%d] %s\n", i, result[i]);
	}
	_getch();
	return 0;
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