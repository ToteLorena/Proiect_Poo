#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>
#include"Eveniment.h"


using namespace std;


class BiletEveniment
{
private:
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
	BiletEveniment():identificareBilet(0)
	{
		this->tipZona = "Necunoscuta";
		this->pret = 0;
		this->nrRand = 0;
		this->nrLocPeRand = 0;
		Eveniment e1;
		this->evenimentBilet = e1;
		this->esteDecontat = 1;
	}

	BiletEveniment(int identificareBilet, string tipZona, float pret, int nrRand, int nrLocPeRand, Eveniment evenimentBilet, bool esteDecontat) :identificareBilet(identificareBilet)
	{
		this->tipZona = tipZona;
		this->pret = pret;
		this->nrRand = nrRand;
		this->nrLocPeRand = nrLocPeRand;
		this->evenimentBilet = evenimentBilet;
		this->esteDecontat = esteDecontat;
	}

	//DESTRUCTOR
	~BiletEveniment()
	{

	}

	//CONSTRUCTOR DE COPIERE
	BiletEveniment(BiletEveniment& b):identificareBilet(b.identificareBilet)
	{
		this->tipZona = b.tipZona;
		this->pret = b.pret;
		this->nrRand = b.nrRand;
		this->nrLocPeRand = b.nrLocPeRand;
		this->evenimentBilet = b.evenimentBilet;
		this->esteDecontat = b.esteDecontat;
	}

	//OPERATORUL DE ATRIBUIRE
	BiletEveniment& operator=(BiletEveniment& b)
	{
		if (this != &b)
		{
			this->tipZona = b.tipZona;
			this->pret = b.pret;
			this->nrRand = b.nrRand;
			this->nrLocPeRand = b.nrLocPeRand;
			this->evenimentBilet = b.evenimentBilet;
			this->esteDecontat = b.esteDecontat;
		}
		return *this;
	}

	//GETTERI
	int getIdentificare()
	{
		return this->identificareBilet;
	}

	string getTipZona()
	{
		return this->tipZona;
	}

	float getPret()
	{
		return this->pret;
	}

	int getNrRand()
	{
		return this->nrRand;
	}

	int getNrLocPeRand()
	{
		return this->nrLocPeRand;
	}

	Eveniment getEvenimentBilet()
	{
		return this->evenimentBilet;
	}

	bool getEsteDecontat()
	{
		return this->esteDecontat;
	}

	static int getProcentTVA()
	{
		return procentTVA;
	}

	//SETTERI
	void setTipZona(string tipZona)
	{
		this->tipZona = tipZona;
	}

	void setPret(float pret)
	{
		this->pret = pret;
	}

	void setNrRand(int nrRand)
	{
		this->nrRand = nrRand;
	}

	void setNrLocPeRand(int nrLocPeRand)
	{
		this->nrLocPeRand = nrLocPeRand;
	}

	void setEvenimentBilet(Eveniment evenimentBilet)
	{
		this->evenimentBilet = evenimentBilet;
	}

	void setEsteDecontat(bool esteDecontat)
	{
		this->esteDecontat = esteDecontat;
	}

	static void setProcentTVA(int procentTVA)
	{
		BiletEveniment::procentTVA = procentTVA;
	}

	//OPERATOR <<
	friend ostream& operator<<(ostream& out, BiletEveniment& b)
	{
		out << "Codul pentru identificarea biletului este: " << b.identificareBilet << endl;
		out << "Zona biletului este: " << b.tipZona << endl;;
		out << "Pretul biletului este: " << b.pret<<endl;
		out << "Numarul randului este: " << b.nrRand<<endl;
		out << "Numarul locului este: " << b.nrLocPeRand<<endl;
		out << "Detalii despre eveniment: " << b.evenimentBilet<<endl;
		out << "Este biletul decontat? (1-DA, 0-NU): " << b.esteDecontat<<endl;
		out << "TVA: " << b.procentTVA<<"%"<<endl;
		return out;
	}

	//OPERATOR >>
	friend istream& operator>>(istream& in, BiletEveniment& b)
	{
		cout << "Introduceti zona biletului:";
		in >> b.tipZona;
		cout << "Introduceti pretul biletului:";
		in >> b.pret;
		cout << "Introduceti numarul randului:";
		in >> b.nrRand;
		cout << "Introduceti locul:";
		in >> b.nrLocPeRand;
		cout << "Introduceti detaliile despre eveniment:";
		in >> b.evenimentBilet;
		cout << "Este biletul decontat? (1-DA, 0-NU):";
		in >> b.esteDecontat;
		cout << "Procent TVA:";
		in >> b.procentTVA;
		return in;
	}

	//METODA STATICA PENTRU CEL MAI IEFTIN BILET
	static float celMaiIeftinBilet(BiletEveniment* vectorBilete, int nrBilete)
	{
		float celMaiIeftinBilet = vectorBilete[0].pret;
		for (int i = 0; i < nrBilete; i++)
		{
			if (celMaiIeftinBilet > vectorBilete[i].pret)
			{
				celMaiIeftinBilet = vectorBilete[i].pret;
			}
		}
		return celMaiIeftinBilet;
	}


	//OPERATOR CAST LA FLOAT
	//PENTRU A CALCULA PRETUL BILETULUI FARA TVA

	operator float()
	{
		float pretTVA = 0;
		pretTVA = this->pret - this->pret*(this->procentTVA / 100);
		return pretTVA;
	}

	//OPERATOR +
	//PENTRU A CALCULA PRETUL IN CAZUL IN CARE SUNT CUMPARATE MAI MULTE BILETE
	float operator+(BiletEveniment& b)
	{
		float pretTotal = 0;
		pretTotal = pret + b.pret;
		return pret;
	}

	//METODA PRET BILET CU DISCOUNT
	float aplicareDiscount(float procentDiscount)
	{
		float pretDiscount = 0;
		pretDiscount = this->pret - this->pret * (procentDiscount / 100);
		return pretDiscount;
	}
	
	//METODA PRET BILET CU ASIGURARE ( IN CAZUL IN CARE EVENIMENTUL SE ANULEAZA/ CUMPARATORUL NU MAI POATE AJUNGE BANII II SUNT RESTITUITI)
	float pretBiletCuAsigurare(float pretAsigurare)
	{
		float pretCuAsigurare = 0;
		pretCuAsigurare = pret + pretAsigurare;
		return pretCuAsigurare;
	}
	






	

};
int BiletEveniment::procentTVA = 2;
