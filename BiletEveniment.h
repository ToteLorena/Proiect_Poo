#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include <fstream>
#include"Eveniment.h"

using namespace std;


class BiletEveniment
{
protected:
	const int identificareBilet;
	string tipZona;
	float pret;
	int nrRand;
	int nrLocPeRand;
	Eveniment evenimentBilet;
	bool esteDecontat;
	static int procentTVA;

public:
	//CONSTRUCTORI
	BiletEveniment();

	BiletEveniment(const string tipZona, float pret, int nrRand, int nrLocPeRand, Eveniment evenimentBilet, bool esteDecontat, int identificareBilet);

	//DESTRUCTOR
	~BiletEveniment();

	//CONSTRUCTOR DE COPIERE
	BiletEveniment(const BiletEveniment& b);


	//OPERATORUL DE ATRIBUIRE
	BiletEveniment& operator=(const BiletEveniment& b);

	//GETTERI
	int getIdentificare();
	string getTipZona();
	float getPret();
	int getNrRand();;
	int getNrLocPeRand();
	Eveniment getEvenimentBilet();
	bool getEsteDecontat();
	static int getProcentTVA();

	//SETTERI
	void setTipZona(string tipZona);
	void setPret(float pret);
	void setNrRand(int nrRand);
	void setNrLocPeRand(int nrLocPeRand);
	void setEvenimentBilet(Eveniment evenimentBilet);
	void setEsteDecontat(bool esteDecontat);
	static void setProcentTVA(int procentTVA);

	//OPERATOR <<
	friend ostream& operator<<(ostream& out,const BiletEveniment& b);

	//OPERATOR >>
	friend istream& operator>>(istream& in,  BiletEveniment& b);

	//METODA STATICA PENTRU CEL MAI IEFTIN BILET
	static float celMaiIeftinBilet(BiletEveniment* vectorBilete, int nrBilete);

	//OPERATOR CAST LA FLOAT
	//PENTRU A CALCULA PRETUL BILETULUI FARA TVA
	operator float();

	//OPERATOR +
	//PENTRU A CALCULA PRETUL IN CAZUL IN CARE SUNT CUMPARATE MAI MULTE BILETE
	float operator+(BiletEveniment& b);

	//METODA PRET BILET CU DISCOUNT
	virtual float aplicareDiscount(float procentDiscount);
	
	//METODA PRET BILET CU ASIGURARE ( IN CAZUL IN CARE EVENIMENTUL SE ANULEAZA/ CUMPARATORUL NU MAI POATE AJUNGE BANII II SUNT RESTITUITI)
	virtual float pretBiletCuAsigurare(float pretAsigurare);

	//SCRIEREA IN FISIERE TEXT A OBIECTELOR
	friend ofstream& operator<<(ofstream& file,  const BiletEveniment& b);

	//CITIREA IN FISIERE TEXT
	friend ifstream& operator>>(ifstream& file, BiletEveniment& b);

	//METODA DE SCRIERE IN FISIERE BINARE
	void scriereBinar(fstream& file);

	//METODA DE CITIRE IN FISIERE BINARE
	void citireBinar(fstream& file);





};

