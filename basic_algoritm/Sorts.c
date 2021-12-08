#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include "Sorts.h"

void Sliyanie() {
	
	int NF=0, NS=0;

	printf("������� ���������� ��������� � 1-�� �������: ");
	scanf_s("%d", &NF);

	printf("������� ���������� ��������� �� 2-�� �������: ");
	scanf_s("%d", &NS);

	int NR = NF + NS;

	int* First;
	int* Second;
	int* Result;

	First = (int*)calloc(NF, sizeof(int));
	Second = (int*)calloc(NS, sizeof(int));
	Result = (int*)calloc(NR, sizeof(int));

	printf("������ ������:\n");
	for (int i = 0; i < NF; i++) {
		scanf_s("%d", &First[i] );
		
	}
	printf("������ ������:\n");
	for (int i = 0; i < NS; i++) {
		scanf_s("%d", &Second[i]);
	}

	printf("�������� ������: ");
	for (int i = 0, j = 0, k = 0; i < NF || j < NS; k++)
	{
		if (i < NF && (j == NS || First[i] < Second[j]))
		{
			Result[k] = First[i];
			i++;
		}
		else
		{
			Result[k] = Second[j];
			j++;
		}
	}
	for (int j = 0; j < NR; j++) { printf("%d ", Result[j]); }
	_getch();
}
void Shell() {
	int* A;
	int N;
	setlocale(LC_ALL, "Rus");
	printf("������� ���-�� ���������: ");
	scanf("%d", &N);
	A = (int*)calloc(N, sizeof(int));
	printf("������� �����:\n");
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int d, f, b;
	d = N;
	do {
		d = (d + 1) / 2;
		f = 0;
		for (int i = 0; i + d < N; i++)
			if (A[i] > A[i + d])
			{
				b = A[i];
				A[i] = A[i + d];
				A[i + d] = b;
				f = 1;
			}
	} while ((d > 1) || (f == 1));

	printf("������������� �����: ");
	for (int i = 0; i < N; i++) {
		printf(" %d", A[i]);
	}
	_getch();
}
void bubble() {
	int* A;
	int N;

	setlocale(LC_ALL, "Rus");

	printf("������� ���-�� ���������: ");
	scanf("%d", &N);

	A = (int*)calloc(N, sizeof(int));
	printf("������� �����:\n");
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int L, F, C;
	L = N - 1;
	do {
		F = 0;
		for (int i = 0; i < L; i++) {
			if (A[i] > A[i + 1]) {
				C = A[i];
				A[i] = A[i + 1];
				A[i + 1] = C;
				F = 1;
			}
		}
		L--;
	} while (F == 1);

	printf("������������� �����:");
	for (int i = 0; i < N; i++) {
		printf(" %d", A[i]);
	}
	_getch();
}
void SuperBubble() {
	int* A;
	int N;

	setlocale(LC_ALL, "Rus");

	printf("������� ���-�� ���������: ");
	scanf("%d", &N);

	A = (int*)calloc(N, sizeof(int));
	printf("������� �����:\n");
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int L, F, C, Start;
	L = N - 1;
	Start = 0;
	do {
		F = 0;
		for (int i = Start; i < L; i++) {
			if (A[i] > A[i + 1]) {
				C = A[i];
				A[i] = A[i + 1];
				A[i + 1] = C;
				F = 1;
			}
		}
		L--;
		if (F == 1) {
			F = 0;
			for (int i = L; i > Start; i--) {
				if (A[i] < A[i - 1]) {
					C = A[i];
					A[i] = A[i - 1];
					A[i - 1] = C;
					F = 1;
				}
			}
			Start++;
		}
	} while (F == 1);

	printf("������������� �����:");
	for (int i = 0; i < N; i++) {
		printf(" %d", A[i]);
	}
	_getch();
}
void sortirovka_min() {
	int* a;
	int n;


	setlocale(LC_ALL, "Rus");
	printf("������� ���������� ���������: ");
	scanf("%d", &n);

	a = (int*)calloc(n, sizeof(int));

	printf("������� �����:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	int min, l;
	for (int i = 0; i < n - 1; i++)
	{
		min = a[i];
		l = i;
		for (int j = i + 1; j < n; j++)
		{
			if (min > a[j])
			{
				min = a[j];
				l = j;
			}
		}
		a[l] = a[i];
		a[i] = min;
	}

	printf("����������� �����:");
	for (int i = 0; i < n; i++)
	{
		printf(" %d", a[i]);
	}
	_getch();
}
void ���������() {
	int* a;
	int n;


	setlocale(LC_ALL, "Rus");
	printf("������� ���������� ���������: ");
	scanf("%d", &n);

	a = (int*)calloc(n, sizeof(int));

	printf("������� �����:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	int B, j, m=1;
	for (int i = m; i < n; i++)
	{
		B = a[i]; j = i - 1;
		while (j >= 0 && B < a[j])
		{
			a[j + 1] = a[j]; j--;
		}
		a[j + 1] = B;
	}

	printf("����������� �����:");
	for (int i = 0; i < n; i++)
	{
		printf(" %d", a[i]);
	}
	_getch();
}
void slienie(int* first, int NF, int* second, int NS, int k, int* result, int NR)
{
	int p, q, cout;
	first[NF] = abs(first[NF - 1]);
	if (NS > 0)
	{
		first[NF] += abs(second[NS - 1]);
	}
	second[NS] = first[NF];
	p = 0;
	q = 0;
	cout = 0;
	while (cout < (NF + NS))
	{
		if (first[p] < second[q])
		{
			result[k + cout] = first[p++];
		}
		else
		{
			result[k + cout] = second[q++];
		}
		cout++;
	}
}
void sort_slienie(int* A, int N)
{
	int* first, * second;
	int NF, NS;
	int d, k, i;
	first = (int*)calloc(N, sizeof(int));
	second = (int*)calloc(((N / 2) + 1), sizeof(int));
	d = 1;
	while (d < N)
	{
		k = 0;
		while ((k + d) < N)
		{
			NF = 0;
			for (i = 0; i < d && ((k + i) < N); i++)
			{
				first[NF++] = A[k + i];
			}
			NS = 0;
			for (i = 0; i < d && ((k + d + i) < N); i++)
			{
				second[NS++] = A[k + d + i];
			}
			slienie(first, NF, second, NS, k, A, N);
			k = k + 2 * d;
		}
		d = 2 * d;
	}
}
void �������()
{
	int* a;
	int n;


	setlocale(LC_ALL, "Rus");
	printf("������� ���������� ���������: ");
	scanf("%d", &n);

	a = (int*)calloc(n, sizeof(int));

	printf("������� �����:\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	sort_slienie(a, n);

	printf("����������� �����:");
	for (int i = 0; i < n; i++)
	{
		printf(" %d", a[i]);
	}
	_getch();
}