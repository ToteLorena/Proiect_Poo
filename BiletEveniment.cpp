#define _CRT_SECURE_NO_WARNINGS
#include"BiletEveniment.h"
#include"Eveniment.h"
#include"Locatie.h"
#include<iostream>
#include<string>
#include <fstream>
#include<cstdlib>.

using namespace std;
int BiletEveniment::procentTVA = 2;

//CONSTRUCTORI
BiletEveniment::BiletEveniment():identificareBilet(0)
{
	this->tipZona = "Necunoscuta";
	this->pret = 0;
	this->nrRand = 0;
	this->nrLocPeRand = 0;
	Eveniment e1;
	this->evenimentBilet = e1;
	this->esteDecontat = 1;
}

BiletEveniment::BiletEveniment(const string tipZona, float pret, int nrRand, int nrLocPeRand, Eveniment evenimentBilet, bool esteDecontat, int identificareBilet) :identificareBilet(identificareBilet)
{
	identificareBilet = 1 + (rand() % 999999);
	identificareBilet++;
	this->tipZona = tipZona;
	this->pret = pret;
	this->nrRand = nrRand;
	this->nrLocPeRand = nrLocPeRand;
	this->evenimentBilet = evenimentBilet;
	this->esteDecontat = esteDecontat;
}

//DESTRUCTOR
BiletEveniment::~BiletEveniment()
{

}

//GETTERI
int BiletEveniment::getIdentificare()
{
	return this->identificareBilet;
}

string  BiletEveniment::getTipZona()
{
	return this->tipZona;
}

float  BiletEveniment::getPret()
{
	return this->pret;
}

int  BiletEveniment::getNrRand()
{
	return this->nrRand;
}

int  BiletEveniment::getNrLocPeRand()
{
	return this->nrLocPeRand;
}

Eveniment  BiletEveniment::getEvenimentBilet()
{
	return this->evenimentBilet;
}

bool  BiletEveniment::getEsteDecontat()
{
	return this->esteDecontat;
}

int BiletEveniment::getProcentTVA()
{
	return procentTVA;
}

//SETTERI
void BiletEveniment::setTipZona(string tipZona)
{
	this->tipZona = tipZona;
}

void BiletEveniment::setPret(float pret)
{
	this->pret = pret;
}

void BiletEveniment::setNrRand(int nrRand)
{
	this->nrRand = nrRand;
}

void BiletEveniment::setNrLocPeRand(int nrLocPeRand)
{
	this->nrLocPeRand = nrLocPeRand;
}

void BiletEveniment::setEvenimentBilet(Eveniment evenimentBilet)
{
	this->evenimentBilet = evenimentBilet;
}

void BiletEveniment::setEsteDecontat(bool esteDecontat)
{
	this->esteDecontat = esteDecontat;
}

void BiletEveniment::setProcentTVA(int procentTVA)
{
	BiletEveniment::procentTVA = procentTVA;
}

//CONSTRUCTOR DE COPIERE
BiletEveniment::BiletEveniment(const BiletEveniment& b):identificareBilet(b.identificareBilet)
	{
		this->tipZona = b.tipZona;
		this->pret = b.pret;
		this->nrRand = b.nrRand;
		this->nrLocPeRand = b.nrLocPeRand;
		this->evenimentBilet = b.evenimentBilet;
		this->esteDecontat = b.esteDecontat;
	}

//OPERATOR =
  BiletEveniment& BiletEveniment::operator=(const BiletEveniment& b)
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

  //OPERATOR <<
  ostream& operator<<(ostream& out,const BiletEveniment& b)
  {
	  out << "Codul pentru identificarea biletului este: " << b.identificareBilet << endl;
	  out << "Zona biletului este: " << b.tipZona << endl;;
	  out << "Pretul biletului este: " << b.pret << endl;
	  out << "Este biletul decontat? (1-DA, 0-NU): " << b.esteDecontat << endl;
	  out << "TVA: " << b.procentTVA << "%" << endl;
	  out << "Numarul randului este: " << b.nrRand << endl;
	  out << "Numarul locului este: " << b.nrLocPeRand << endl;
	  out << "Detalii despre eveniment: " << b.evenimentBilet << endl;
	  return out;
  }

  //OPERATOR>>
  istream&operator>>(istream& in, BiletEveniment& b)
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
 float BiletEveniment::celMaiIeftinBilet(BiletEveniment* vectorBilete, int nrBilete)
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
 BiletEveniment::operator float()
 {
	 float pretTVA = 0;
	 pretTVA = this->pret - this->pret * (this->procentTVA) / 100;
	 return pretTVA;
 }

 //OPERATOR +
//PENTRU A CALCULA PRETUL IN CAZUL IN CARE SUNT CUMPARATE MAI MULTE BILETE
 float BiletEveniment::operator+(BiletEveniment& b)
 {
	 float pretTotal = 0;
	 pretTotal = pret + b.pret;
	 return pretTotal;
 }

 //METODA PRET BILET CU DISCOUNT
 float BiletEveniment::aplicareDiscount(float procentDiscount)
 {
	 float pretDiscount = 0;
	 pretDiscount = this->pret - this->pret * (procentDiscount / 100);
	 return pretDiscount;
 }

 //METODA PRET BILET CU ASIGURARE ( IN CAZUL IN CARE EVENIMENTUL SE ANULEAZA/ CUMPARATORUL NU MAI POATE AJUNGE BANII II SUNT RESTITUITI)
 float BiletEveniment::pretBiletCuAsigurare(float pretAsigurare)
 {
	 float pretCuAsigurare = 0;
	 pretCuAsigurare = pret + pretAsigurare;
	 return pretCuAsigurare;
 }

 //SCRIEREA IN FISIERE TEXT A OBIECTELOR
  ofstream& operator<<(ofstream& file, const BiletEveniment& b)
 {
	 file << b.identificareBilet << endl;
	 file << b.tipZona << endl;
	 file << b.pret << endl;
	 file << b.nrRand << endl;
	 file << b.nrLocPeRand << endl;
	 file << b.evenimentBilet << endl;
	 file <<b.esteDecontat<< endl;
	 return file;
 }

  //CITIREA DIN FISIERE TEXT A OBIECTELOR
  ifstream& operator>> (ifstream& file, BiletEveniment&b)
  {

	  file >> b.tipZona;
	  file >> b.pret;
	  file >> b.nrRand;
	  file >>b.nrLocPeRand;
	  file >> b.evenimentBilet;
	  file >> b.esteDecontat;
	  return file;
  }

  //METODA DE SCRIERE IN FISIERE BINARE
  void BiletEveniment::scriereBinar(fstream& file)
  {
	  int nrLitereTipZona =tipZona.size();
	  file.write((char*)&nrLitereTipZona, sizeof(int));
	  file.write(tipZona.c_str(), nrLitereTipZona);

	  file.write((char*)&pret, sizeof(float));

	  file.write((char*)&nrRand, sizeof(int));

	  file.write((char*)&nrLocPeRand, sizeof(int));

	  this->evenimentBilet.scriereBinar(file);

	  file.write((char*)&esteDecontat, sizeof(bool));
  }

  //METODA DE CITIRE IN FISIERE BINARE
  void BiletEveniment::citireBinar(fstream& file)
  {
	  int nrLitereTipZona=0;
	  file.read((char*)&nrLitereTipZona, sizeof(int));
	  string aux;
	  aux.resize(nrLitereTipZona);
	  file.read((char*)aux.c_str(), nrLitereTipZona);
	  tipZona = aux;

	  file.read((char*)&pret, sizeof(float));

	  file.read((char*)&nrRand, sizeof(int));

	  file.read((char*)&nrLocPeRand, sizeof(int));

	  this->evenimentBilet.citireBinar(file);

	  file.read((char*)&esteDecontat, sizeof(bool));

  }

 


