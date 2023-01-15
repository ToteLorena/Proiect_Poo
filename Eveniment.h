#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include"Locatie.h"

using namespace std;


class Eveniment {
private:
	string nume;
	int dataEven[3];
	int ora[2];
	Locatie locatie;
	bool pentruMajori;

public:
	//CONSTRUCTORI
	Eveniment();

	Eveniment(const string nume, int dataEven[3], int ora[2], Locatie locatie, bool pentruMajori);

	//DESTRUCTOR
	~Eveniment();

	//CONSTRUCTOR DE COPIERE
	Eveniment(const Eveniment& e);

	//OPERATOR DE ATRIBUIRE
	Eveniment& operator=(const Eveniment& e);

	//GETTERI
	string getNume();
	int getDataZi();
	int getDataLuna();
	int getDataAn();
	int getOra();
	int getMinute();
	Locatie getLocatie();
	bool getPentruMajori();

	//SETTERI
	void setNume(string nume);
	void setData(int dataEven[3]);
	void setOra(int ora[2]);
	void setLocatie(Locatie locatie);
	void setPentruMajori(bool pentruMajori);

	//OPERATOR <<
	friend ostream& operator<<(ostream& out, const Eveniment& e);

	//OPERATOR >>
	friend istream& operator>>(istream& in, Eveniment& e);

	//OPERATOR !
	//Pentru a schimba daca evenimentul este pentru persoane peste 18 ani.
	friend void operator!(Eveniment& e);

	//OPERATOR >=
	//Pentru a verifica daca un eveniment este in aceiasi data sau mai tarziu decat altul
	bool operator>=(const Eveniment& e);

	//METODA SCHIMBA ZIUA DIN CADRUL EVENIMENTULUI
	void schimbareZi(int ziNoua);

	//METODA SCHIMBA ORA DIN CADRUL EVENIMENTULUI
	void schimbareOra(int oraNoua);

	//SCRIEREA IN FISIERE TEXT 
	friend ofstream& operator<<(ofstream& file, const Eveniment& e);

	//CITIREA DIN FISIERE TEXT 
	friend ifstream& operator>> (ifstream& file, Eveniment& e);

	// METODA DE SCRIERE IN FISIERE BINARE
	void scriereBinar(fstream& file);

	//METODA DE CITIRE IN FISIERE BINARE
	void citireBinar(fstream& file);




};
