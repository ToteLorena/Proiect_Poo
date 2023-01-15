#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
#include"Eveniment.h"
#include"BiletE#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include"Eveniment.h"
#include"BiletEveniment.h"
#include"Locatie.h"
#include"BiletVIP.h"
#include<cstdlib>
#include<list>


using namespace std;

int main()
{
	int** v1 = new int* [8];
	for (int i = 0; i < 8; i++)
	{
		v1[i] = new int[7];
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7; j++) {
			v1[i][j] = 0;
		}
	}
	Locatie l1("Arena Nationala", "Bulevardul Basarabia 37-39, Bucuresti", 7, 8, v1);
	int** v2 = new int* [9];
	for (int i = 0; i < 9; i++)
	{
		v2[i] = new int[8];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++) {
			v2[i][j] = 0;
		}
	}
	Locatie l2("Arena Nationala", "Bulevardul Basarabia 37-39, Bucuresti", 8, 9, v2);
	int** v3 = new int* [10];
	for (int i = 0; i < 10; i++)
	{
		v3[i] = new int[20];
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++) {
			v3[i][j] = 0;
		}
	}
	Locatie l3("AFI Cinema City", "Bulevardul Doina Cornea 4, Bucuresti", 20, 10, v3);
	int** v4 = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		v4[i] = new int[10];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++) {
			v4[i][j] = 0;
		}
	}
	Locatie l4("AFI Cinema City", "Bulevardul Doina Cornea 4, Bucuresti", 10, 3, v4);
	int** v5 = new int*[8];
	for (int i = 0; i < 8; i++)
	{
		v5[i] = new int[8];
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			v5[i][j] = 0;
		}
	}
	Locatie l5("Teatrul Nottara", "Bulevardul General Gheorghe Magheru 20, Bucuresti", 8, 8, v5);
	int** v6 = new int* [9];
	for (int i = 0; i < 9; i++)
	{
		v6[i] = new int[9];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) {
			v6[i][j] = 0;
		}
	}
	Locatie l6("Teatrul Nottara", "Bulevardul General Gheorghe Magheru 20, Bucuresti", 9, 9, v6);
	int** v7 = new int*[6];
	for (int i = 0; i < 6; i++)
	{
		v7[i] = new int[10];
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 10; j++) {
			v7[i][j] = 0;
		}
	}
	Locatie l7("Teatrul Nottara", "Bulevardul General Gheorghe Magheru 20, Bucuresti", 10, 6, v7);
	list<Locatie> lista;
	lista.push_back(l1);
	lista.push_back(l2);
	lista.push_back(l3);
	lista.push_back(l4);
	lista.push_back(l5);
	lista.push_back(l6);
	lista.push_back(l7);

	int d1[3] = { 7,6,2023 };
	int o1[2] = { 18,30 };
	int d2[3] = { 21,1,2023 };
	int o2[2] = { 20,0 };
	int d3[3] = { 17,2,2023 };
	int o3[2] = { 17,45 };
	Eveniment e1("MECI DE FOTBAL", d1, o1, l1, 0);
	Eveniment e12("MECI DE FOTBAL", d1, o1, l2, 0);

	Eveniment e2("FILM", d2, o2, l3, 1);
	Eveniment e22("FILM", d2, o2, l4, 1);

	Eveniment e3("PIESA DE TEATRU", d3, o3, l5, 0);
	Eveniment e32("PIESA DE TEATRU", d3, o3, l6, 0);
	Eveniment e33("PIESA DE TEATRU", d3, o3, l7, 0);

	BiletEveniment b1("TRIBUNA 1", 60, 0, 0, e1, 0, rand());
	BiletEveniment b12("TRIBUNA 2", 70, 0, 0, e12, 0, rand());

	BiletEveniment b2("STANDARD", 33, 0, 0, e2, 0, rand());
	BiletEveniment b22("VIP", 100, 0, 0, e22, 0, rand());

	BiletEveniment b3("CATEGORIA 1", 40, 0, 0, e3, 0, rand());
	BiletEveniment b32("CATEGORIA 2", 50, 0, 0, e32, 0, rand());
	BiletEveniment b33("LOJA", 70, 0, 0, e33, 0, rand());



	cout << "*********************     THE TICKETING APP     *********************" << endl << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------------" << endl;

	cout << "                        EVENIMENTE DISPONIBILE:                        " << endl;
	cout << "       ";
	cout << "     1.MECI DE FOTBAL";
	cout << "      2.FILM";
	cout << "     3.PIESA DE TEATRU";
	cout << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------------" << endl << endl;
	cout << "SELECTATI EVENIMENTUL (INTRODUCETI 1,2 SAU 3) : ";
	int a;
	cin >> a;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------------------------" << endl;


		


	
};

