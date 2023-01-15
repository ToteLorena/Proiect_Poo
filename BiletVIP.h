#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include"BiletEveniment.h"
#include"Locatie.h"
#include"Eveniment.h"
#include"ClasaAbstracta.h"
#include<iostream>
#include<string>
#include <fstream>
#include<cstdlib>

using namespace std;

class BiletVIP : public BiletEveniment, public MetodaPretVIP
{
	string beneficiiVIP;
	float taxaVIP;

public:
	//CONSTRUCTORI
	BiletVIP();
	BiletVIP(string beneficiiVIP, float taxaVIP, const string tipZona, float pret, int nrRand, int nrLocPeRand, Eveniment evenimentBilet, bool esteDecontat, int identificareBilet);

	//DESTRUCTOR
	~BiletVIP();

	//GETTERI
	string getBeneficiiVIP();
	float getTaxaVIP();

	//SETTERI
	void setBeneficiiVip(string beneficiiVIP);
	void setTaxaVIP(float TaxaVIP);

	//CONSTRUCTORUL DE COPIERE
	BiletVIP(const BiletVIP& bv);

	//OPERATOR<<
	friend ostream& operator<<(ostream& out, const BiletVIP& bv);

	//OPERATOR>>
	friend istream& operator>>(istream& in, BiletVIP& bv);

	//OPERATOR EGAL
	BiletVIP& operator=(const BiletVIP& bv);

	//UPCASTING: SE REALIZEAZA IMPLICIT

	//DOWNCASTING
	BiletVIP(const BiletEveniment& bv);

	//METODA: CALCUL PRET PRODUS VIP
	float pretBiletVIP();

	//SCRIEREA IN FISIERE TEXT A OBIECTELOR
	friend ofstream& operator<<(ofstream& file, const BiletVIP& bv);

	//CITIREA IN FISIERE TEXT
	friend ifstream& operator>>(ifstream& file, BiletVIP& bv);

	//METODA DE SCRIERE IN FISIERE BINARE
	void scriereBinar(fstream& file);

	//METODA DE CITIRE IN FISIERE BINARE
	void citireBinar(fstream& file);

	//METODA PRET BILET CU DISCOUNT
	float aplicareDiscount(float procentDiscount);


	//METODA PRET BILET CU ASIGURARE ( IN CAZUL IN CARE EVENIMENTUL SE ANULEAZA/ CUMPARATORUL NU MAI POATE AJUNGE BANII II SUNT RESTITUITI)
	float pretBiletCuAsigurare(float pretAsigurare);
};

