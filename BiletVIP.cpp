#define _CRT_SECURE_NO_WARNINGS
#include"BiletVIP.h"
#include"BiletEveniment.h"
#include"Locatie.h"
#include"Eveniment.h"
#include<iostream>
#include<string>
#include <fstream>
#include<cstdlib>

using namespace std;

//CONSTRUCTORI
BiletVIP::BiletVIP() :BiletEveniment()
{
	this->beneficiiVIP="Necunoscute";
	this->taxaVIP = 0;
}

BiletVIP::BiletVIP(string beneficiiVIP, float taxaVIP, const string tipZona, float pret, int nrRand, int nrLocPeRand, Eveniment evenimentBilet, bool esteDecontat, int identificareBilet) : BiletEveniment(tipZona,pret,nrRand,nrLocPeRand,evenimentBilet,esteDecontat,identificareBilet)
{
	this->beneficiiVIP = beneficiiVIP;
	this->taxaVIP = taxaVIP;
}

//DESTRUCTOR
BiletVIP::~BiletVIP()
{

}

//GETTERI
string BiletVIP::getBeneficiiVIP()
{
	return this->beneficiiVIP;
}

float BiletVIP::getTaxaVIP()
{
	return this->taxaVIP;
}

//SETTERI
void BiletVIP::setBeneficiiVip(string beneficiiVIP)
{
	this->beneficiiVIP = beneficiiVIP;
}

void BiletVIP::setTaxaVIP(float taxaVip)
{
	this->taxaVIP = taxaVip;
}

//CONSTRUCTOR DE COPIERE
BiletVIP::BiletVIP(const BiletVIP& bv) :BiletEveniment(bv)
{
	this->beneficiiVIP = bv.beneficiiVIP;
	this->taxaVIP = bv.taxaVIP;
}

//OPERATOR EGAL
BiletVIP& BiletVIP::operator=(const BiletVIP& bv)
{
	if (this != &bv)
	{
		BiletEveniment::operator=(bv);
		this->beneficiiVIP = bv.beneficiiVIP;
		this->taxaVIP = bv.taxaVIP;
}
	return *this;

}

//OPERATOR<<
ostream& operator<<(ostream& out, const BiletVIP& bv)
{
	out << "Beneficiile biletului VIP sunt: " << bv.beneficiiVIP << endl;
	out << "Taxa aditionala pentru biletul VIP este:" << bv.taxaVIP << endl;
	out << (BiletEveniment&)bv;
	return out;
}

//OPERATOR>>
istream& operator>>(istream& in, BiletVIP& bv)
{
	cout<<"Introduceti beneficiile biletului VIP:";
	in >> bv.beneficiiVIP;
	cout << "Introduceti taxa aditionala penttu biletul VIP:";
	in >> bv.taxaVIP;
	in >> (BiletVIP&)bv;
	return in;
}

//UPCASTING: SE REALIZEAZA IMPLICIT

//DOWNCASTING
BiletVIP::BiletVIP(const BiletEveniment& bv) :BiletEveniment(bv)
{
	this->beneficiiVIP = "VIP";
	this->taxaVIP = 50;
}

//METODA: CALCUL PRET PRODUS VIP
float BiletVIP::pretBiletVIP()
{
	float pretBiletVIP = 0;
	pretBiletVIP = pret + taxaVIP;
	return pretBiletVIP;
}

//SCRIEREA IN FISIERE TEXT A OBIECTELOR
ofstream& operator<<(ofstream& file, const BiletVIP& bv)
{
	file << bv.beneficiiVIP << endl;
	file << bv.taxaVIP << endl;
	file << (BiletEveniment&)bv;
	return file;
}

//CITIREA IN FISIERE TEXT
 ifstream& operator>>(ifstream& file, BiletVIP& bv)
{
	 file >> bv.beneficiiVIP;
	 file >> bv.taxaVIP;
	 file >> (BiletVIP&)bv;
	 return file;
}

//METODA DE SCRIERE IN FISIERE BINARE
 void BiletVIP::scriereBinar(fstream& file)
 {
	 int dimensiuneBeneficii = beneficiiVIP.size();
	 file.write((char*)&dimensiuneBeneficii, sizeof(int));
	 file.write(beneficiiVIP.c_str(), dimensiuneBeneficii);

	 file.write((char*)&taxaVIP, sizeof(float));

	 BiletEveniment::scriereBinar(file);
}

//METODA DE CITIRE IN FISIERE BINARE
 void BiletVIP::citireBinar(fstream& file)
 {
	 int dimensiuneBeneficii = 0;
	 file.read((char*)&dimensiuneBeneficii, sizeof(int));
	 string aux;
	 aux.resize(dimensiuneBeneficii);
	 file.read((char*)aux.c_str(), dimensiuneBeneficii);
	 beneficiiVIP = aux;

	 file.read((char*)&taxaVIP, sizeof(float));

	 BiletEveniment::citireBinar(file);

	 
}

 //METODA PRET BILET CU DISCOUNT
 float BiletVIP::aplicareDiscount(float procentDiscount)
 {
	 float pretDiscount = 0;
	 pretDiscount = pretBiletVIP() - pretBiletVIP() * (procentDiscount / 100);
	 return pretDiscount;
 }


 //METODA PRET BILET CU ASIGURARE ( IN CAZUL IN CARE EVENIMENTUL SE ANULEAZA/ CUMPARATORUL NU MAI POATE AJUNGE BANII II SUNT RESTITUITI)
 float BiletVIP::pretBiletCuAsigurare(float pretAsigurare)
 {
	 float pretCuAsigurare = 0;
	 pretCuAsigurare = pretBiletVIP() + pretAsigurare;
	 return pretCuAsigurare;
 }


