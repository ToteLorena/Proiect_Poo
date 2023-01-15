#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>


using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include<list>


using namespace std;

class Locatie
{

private:
	char* denumireaLocatiei;
	char* adresa;
	int nrLocuri;
	int nrRanduri;
	int** locuriLocatie;//valoarea 1 daca este ocupat locul, 0 daca este liber, 2 daca este rezervat

public:
	//CONSTRUCTORI
	Locatie();

	Locatie(const char* denumireaLocatiei, const char* adresa, int nrLocuri, int nrRanduri, int** locuriLocatie);
	
	//DESTRUCTOR
	~Locatie();
	
	//CONSTRUCTOR COPIERE
	Locatie(const Locatie& l);

	//OPERATOR DE ATRIBUIRE
	Locatie& operator=(const Locatie& l);

	//GETTERI
	char* getDenumireaLocatiei();
	char* getAdresa();
	int getLocuri();
	int getRanduri();
	int** getMatriceLocuriLocatie();

	//SETTERI
	void setDenumireaLocatiei(const char* denumireaLocatiei);
	void setAdresa(const char* adresa);
	void setLocuri(int nrRanduri, int nrLocuri, int** locuriLocatie);

	//OPERATOR <<
	friend ostream& operator<<(ostream& out, const Locatie& l);

	//OPERATOR>> 
	friend istream& operator>>(istream& in, Locatie& l);

	//OPERATOR --
	//Pentru a elimina un rand
	Locatie& operator--();

	//OPERATOR ==
	//Pentru a vedea daca evenimentele sunt in aceiasi locatie
	bool operator==(const Locatie& l);
	
	//METODA ADAUGA LOC OCUPAT
	void adaugaLocOcupat(int nrRandOcupat, int nrLocpeRandOcupat);

	//METODA ADAUGA LOC REZERVAT
	void adaugaLocRezervat(int nrRandRez, int nrLocpeRandRez);
	
	//METODA SCHIMBA LOCUL IN LIBER
	void locLiber(int nrRandLiber, int nrLocpeRandLiber);

	//SCRIEREA IN FISIERE TEXT 
	friend ofstream& operator<<(ofstream& file, const Locatie& l);

	//CITIREA DIN FISIERE TEXT 
	friend ifstream& operator>> (ifstream& file, Locatie& l);

	//METODA DE SCRIERE IN FISIERE BINARE
	void scriereBinar(fstream& file);
	
	//METODA DE CITIRE IN FISIERE BINARE
	void citireBinar(fstream& file);

};

class Locatie
{

private:
	char* denumireaLocatiei;
	char* adresa;
	int nrLocuri;
	int nrRanduri;
	int** locuriLocatie;//valoarea 1 daca este ocupat locul, 0 daca este liber, 2 daca este rezervat

public:
	//CONSTRUCTORI
	Locatie();

	Locatie(const char* denumireaLocatiei, const char* adresa, int nrLocuri, int nrRanduri, int** locuriLocatie);
	
	//DESTRUCTOR
	~Locatie();
	
	//CONSTRUCTOR COPIERE
	Locatie(const Locatie& l);

	//OPERATOR DE ATRIBUIRE
	Locatie& operator=(const Locatie& l);

	//GETTERI
	char* getDenumireaLocatiei();
	char* getAdresa();
	int getLocuri();
	int getRanduri();
	int** getMatriceLocuriLocatie();

	//SETTERI
	void setDenumireaLocatiei(const char* denumireaLocatiei);
	void setAdresa(const char* adresa);
	void setLocuri(int nrRanduri, int nrLocuri, int** locuriLocatie);

	//OPERATOR <<
	friend ostream& operator<<(ostream& out, const Locatie& l);

	//OPERATOR>> 
	friend istream& operator>>(istream& in, Locatie& l);

	//OPERATOR --
	//Pentru a elimina un rand
	Locatie& operator--();

	//OPERATOR ==
	//Pentru a vedea daca evenimentele sunt in aceiasi locatie
	bool operator==(const Locatie& l);
	
	//METODA ADAUGA LOC OCUPAT
	void adaugaLocOcupat(int nrRandOcupat, int nrLocpeRandOcupat);

	//METODA ADAUGA LOC REZERVAT
	void adaugaLocRezervat(int nrRandRez, int nrLocpeRandRez);
	
	//METODA SCHIMBA LOCUL IN LIBER
	void locLiber(int nrRandLiber, int nrLocpeRandLiber);
};
