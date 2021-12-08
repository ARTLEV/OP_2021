#define _CRT_SECURE_NO_WARNINGS
#include "AllAlg.h"

//???????? 1
int summing(int* b, int k) 
{
	int sum;
	int i;
	sum = 0;
	for (i = 0; i < k; i++) {
		sum += b[i];
	}
	return sum;
}

//???????? 2
void min_number(int* a, int n, int* min, int* l) { 
	(*min) = a[0];
	(*l) = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < (*min)) {
			(*min) = a[i];
			(*l) = i;
		}
	}
}

//???????? 3
int otbor_elem(char** a, int n, char param, char*** best) { 
	(*best) = (char**)calloc(n, sizeof(char*));
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i][0] == param) {
			int len = strlen(a[i]) + 2;
			(*best)[k] = (char*)calloc(len, sizeof(char));
			strcpy((*best)[k], a[i]);
			k++;
		}
	}
	return k;
}

//???????? 4
int linear_search(char** dst, char* source, int size) { 
	int index = -1;
	int i = 0;

	while (index == -1 && i < size) {

		if (strcmp(dst[i], source) == 0) {
			index = i;
		}

		i++;
	}

	return index;
}

//???????? 5
int binary_search(char** dst, char* source, int size) { 
	int start = 0;
	int finish = size - 1;
	int index = -1;
	int i = 0;

	while (start <= finish)
	{
		int middle = (start + finish) / 2;

		int str_cmp_data = strcmp(source, dst[middle]);

		if (str_cmp_data == 0) {
			index = middle;
			break;
		}
		if (str_cmp_data < 0)
			finish = middle - 1;
		else
			start = middle + 1;
	}

	return index;
}

//???????? 6
int spisok_bez_povtoreniy(char** name, int n, char*** list) { 
	int k = 0;

	for (int i = 0; i < n; i++) {

		int l = -1;
		int j = 0;
		while (l == -1 && j < k)
		{
			if (strcmp(name[i], (*list)[j]) == 0)
			{
				l = j;
			}
			j++;
		}
		if (l == -1)
		{
			(*list)[k] = (char*)calloc(strlen(name[i]) + 2, sizeof(char));
			strcpy((*list)[k], name[i]);
			k++;
		}
	}
	return k;
}

//???????? 7
int spisok_bez_povtoreniy_rate(char** name, int n, char*** list, int** rate) { 
	int k = 0;

	for (int i = 0; i < n; i++) {

		int l = -1;
		int j = 0;
		while (l == -1 && j < k)
		{
			if (strcmp(name[i], (*list)[j]) == 0)
			{
				l = j;
			}
			j++;
		}
		if (l == -1)
		{
			(*list)[k] = (char*)calloc(strlen(name[i]) + 2, sizeof(char));
			strcpy((*list)[k], name[i]);
			(*rate)[k] = 1;
			k++;
		}
		else {
			(*rate)[l] += 1;
		}
	}
	return k;
}

//???????? 8
int spisok_bez_povtoreniy_sum(char** name, int n, int* ch, char*** list, int** sum) { 
	int k = 0;

	for (int i = 0; i < n; i++) {

		int l = -1;
		int j = 0;
		while (l == -1 && j < k)
		{
			if (strcmp(name[i], (*list)[j]) == 0)
			{
				l = j;
			}
			j++;
		}
		if (l == -1)
		{
			(*list)[k] = (char*)calloc(strlen(name[i]) + 2, sizeof(char));
			strcpy((*list)[k], name[i]);
			(*sum)[k] = ch[i];
			k++;
		}
		else {
			(*sum)[l] += ch[i];
		}
	}
	return k;
}

//???????? 9
int string_split(char* str, char* razd, char*** res) {

	strcat(str, " ");
	int k = 0;
	while (strlen(str) > 0) {
		int l = strcspn(str, razd);
		if (l > 0) {
			(*res)[k] = (char*)calloc(l + 2, sizeof(char));
			strncpy((*res)[k], str, l);
			k++;
		}
		int len = strlen(str);
		for (int i = 0; i < len - l + 1; i++) {
			str[i] = str[l + i + 1];
		}
	}
	return k;
}

//???????? 10
int string_split_smart(char* str, char* razd, char*** res) {
	char* tmp;
	int len = strlen(str);

	str[len - 1] = ' ';
	str[len] = '\0';

	tmp = (char*)calloc(len + 2, sizeof(char));

	int k = 0;

	strcpy(tmp, "");

	for (int i = 0; i < len; i++) {
		char symb[2] = { str[i], '\0' };
		int l = strcspn(symb, razd);

		if (l > 0) {
			strcat(tmp, symb);
		}
		else {
			if (symb[0] == ' ')
			{
				int tmp_len = strlen(tmp);
				if (tmp_len != 0)
				{
					(*res)[k] = (char*)calloc(tmp_len + 2, sizeof(char));
					strcpy((*res)[k], tmp);
					strcpy(tmp, "");
					k++;
				}
			}
			else {
				int tmp_len = strlen(tmp);
				if (tmp_len != 0) {
					(*res)[k] = (char*)calloc(tmp_len + 2, sizeof(char));
					strcpy((*res)[k], tmp);
					strcpy(tmp, "");
					k++;
				}
				(*res)[k] = (char*)calloc(2, sizeof(char));
				strcpy((*res)[k], symb);
				k++;
			}
		}
	}
	return k;
}


//????? ??????? ?????????
void alg1() {
	int N;
	int sum;
	int i;
	int* a;
	setlocale(LC_ALL, "rus");
	printf("??????? ???-?? ?????: ");
	scanf_s("%d", &N);
	a = (int*)calloc(N, sizeof(int));
	printf("??????? ?????: ");
	for (i = 0; i < N; i++) {
		scanf_s("%d", &a[i]);
	}
	sum = summing(a, N);
	printf("????? ????? ????? %d", sum);
	_getch();
	return 0;
}

void alg2() {
	int* a;
	int n;
	int min, l;

	setlocale(LC_ALL, "rus");

	printf("??????? ???-?? ?????: ");
	scanf_s("%d", &n);

	a = (int*)calloc(n, sizeof(int));

	printf("??????? ??????:\n");

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}

	min = a[0];
	l = 0;

	min_number(a, n, &min, &l);

	printf("??????????? ?????: %d ??? ?????? %d", min, l);
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

	printf("??????? ?????????? ?????????: \n");
	scanf_s("%d", &N);

	Names = (char**)calloc(N, sizeof(char*));

	printf("??????? ????????:\n");
	for (int i = 0; i < N; i++) {
		scanf_s("%s", &tmp);
		int len = strlen(tmp) + 2;
		Names[i] = (char*)calloc(len, sizeof(char));
		strcpy(Names[i], tmp);
	}

	printf("??????? ?????: \n");

	scanf_s("%s", &param);

	int k = otbor_elem(Names, N, param[0], &NewNames);

	printf("????? ??????:\n");

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

	printf_s("??????? ???-?? N: ");
	scanf_s("%d", &N);

	name = (char**)calloc(N, sizeof(char*));

	printf("????? ??????:\n");

	for (i = 0; i < N; i++) {

		scanf_s("\n");
		fgets(tmp, 255, stdin);
		len = strlen(tmp) + 2;
		l = sizeof(rsize_t);
		name[i] = (char*)calloc(len, sizeof(char));

		strcpy_s(name[i], l * len, tmp);
	}

	printf("??????? ??????? ?????: ");
	scanf_s("\n");
	fgets(tmp, 255, stdin);

	len = strlen(tmp) + 2;
	l = sizeof(rsize_t);
	ctrl = (char*)calloc(len, sizeof(char));

	strcpy_s(ctrl, len, tmp);

	printf("???????? ????? %d\n", linear_search(name, ctrl, N));
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

	printf_s("??????? ???-?? N: ");
	scanf_s("%d", &N);

	name = (char**)calloc(N, sizeof(char*));

	printf("????? ??????: \n");

	for (i = 0; i < N; i++) {

		scanf_s("\n");
		fgets(tmp, 255, stdin);
		len = strlen(tmp) + 2;
		l = sizeof(rsize_t);
		name[i] = (char*)calloc(len, sizeof(char));

		strcpy_s(name[i], l * len, tmp);
	}

	printf("??????? ??????? ?????: ");
	scanf_s("\n");
	fgets(tmp, 255, stdin);

	len = strlen(tmp) + 2;
	l = sizeof(rsize_t);
	ctrl = (char*)calloc(len, sizeof(char));

	strcpy_s(ctrl, len, tmp);

	printf("???????? ????? %d\n", binary_search(name, ctrl, N));
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


	printf("??????? ?????????? ?????????: \n");
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

	printf("?????? ??? ??????????\n");
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


	printf("??????? ?????????? ?????????: ");
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

	printf("?????? ??? ?????????? ? ??????? ????????\n");
	for (int i = 0; i < k; i++) {
		printf("[%d] = %s ??? ??????? %d\n", i, list[i], Rate[i]);
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

	printf("??????? ?????????? ?????????: ");
	scanf_s("%d", &N);

	name = (char**)calloc(N, sizeof(char*));
	list = (char**)calloc(N, sizeof(char*));
	CH = (int*)calloc(N, sizeof(int));
	Sum = (int*)calloc(N, sizeof(int));

	printf("??????? ???????? ???????? ? ??? ??????????????\n");
	for (int i = 0; i < N; i++) {
		scanf_s("%s %d", &tmp, &CH[i]);
		int len = strlen(tmp);
		name[i] = (char*)calloc(len + 2, sizeof(char));
		strcpy(name[i], tmp);
	}

	int k = spisok_bez_povtoreniy_sum(name, N, CH, &list, &Sum);

	printf("?????? ??? ?????????? ? ??????? ????????\n");
	for (int i = 0; i < k; i++) {
		printf("[%d] = %s\n ?????????????? %d\n", i, list[i], Sum[i]);
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

	printf("??????? ??????: ");
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

	printf("??????? ??????: ");
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