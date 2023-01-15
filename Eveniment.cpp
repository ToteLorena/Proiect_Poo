#define _CRT_SECURE_NO_WARNINGS
#include"Eveniment.h"
#include"Locatie.h"
#include <fstream>
#include<iostream>
#include<string>
using namespace std;

//CONSTRUCTORI
Eveniment::Eveniment()
{
	this->nume = "Necunoscut";
	for (int i = 0; i < 3; i++)
	{
		this->dataEven[i] = 0;
	}
	for (int j = 0; j < 2; j++)
	{
		this->ora[j] = 0;
	}
	Locatie l1;
	this->locatie = l1;
	this->pentruMajori = 1;
}

Eveniment::Eveniment(const string nume, int data[3], int ora[2], Locatie locatie, bool pentruMajori)
{
	this->nume = nume;
	if (data[0] > 0 && data[0] <= 31 && data[1] > 0 && data[1] <= 12)
	{
		for (int i = 0; i < 3; i++)
		{
			this->dataEven[i] = data[i];
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			this->dataEven[i] = 0;
		}
		cout << "Eroare! Data introdusa nu este corecta.";
	}
	if (ora[0] <= 24 && ora[1] <= 59)
	{
		for (int j = 0; j < 2; j++)
		{
			this->ora[j] = ora[j];
		}
	}
	else
	{
		for (int j = 0; j < 2; j++)
		{
			this->ora[j] = 0;
		}
		cout << "Eroare! Ora introdusa este gresita";

	}
	this->locatie = locatie;
	this->pentruMajori = pentruMajori;
}

//DESTRUCTOR
Eveniment::~Eveniment()
{

}

//CONSTRUCTOR DE COPIERE
Eveniment::Eveniment(const Eveniment& e)
{
	this->nume = e.nume;
	if (e.dataEven[0] > 0 && e.dataEven[0] <= 31 && e.dataEven[1] > 0 && e.dataEven[1] <= 12)
	{
		for (int i = 0; i < 3; i++)
		{
			this->dataEven[i] = e.dataEven[i];
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			this->dataEven[i] = 0;
		}
	}

	if (ora[0] <= 24 && ora[1] <= 59)
	{
		for (int j = 0; j < 2; j++)
		{
			this->ora[j] = ora[j];
		}
	}
	else
	{
		for (int j = 0; j < 2; j++)
		{
			this->ora[j] = 0;
		}
	}
	this->locatie = e.locatie;
	this->pentruMajori = e.pentruMajori;
}

//OPERATOR DE ATRIBUIRE
Eveniment& Eveniment::operator=(const Eveniment& e)
{
	if (this != &e)
	{

		this->nume = e.nume;

		if (e.dataEven[0] > 0 && e.dataEven[0] <= 31 && e.dataEven[1] > 0 && e.dataEven[1] <= 12)
		{
			for (int i = 0; i < 3; i++)
			{
				this->dataEven[i] = e.dataEven[i];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				this->dataEven[i] = 0;
			}
		}

		if (ora[0] <= 24 && ora[1] <= 59)
		{
			for (int j = 0; j < 2; j++)
			{
				this->ora[j] = ora[j];
			}
		}
		else
		{
			for (int j = 0; j < 2; j++)
			{
				this->ora[j] = 0;
			}
		}
		this->locatie = e.locatie;
		this->pentruMajori = e.pentruMajori;
	}
	return *this;
}

//GETTERI
string Eveniment::getNume()
{
	return nume;
}

int Eveniment::getDataZi()
{

	return dataEven[0];
}
int Eveniment::getDataLuna()
{

	return dataEven[1];
}
int Eveniment::getDataAn()
{

	return dataEven[2];
}

int Eveniment::getOra()
{
	return this->ora[0];
}
int Eveniment::getMinute()
{
	return this->ora[1];
}

Locatie Eveniment::getLocatie()
{
	return this->locatie;
}

bool Eveniment::getPentruMajori()
{
	return pentruMajori;
}

//SETTERI
void Eveniment::setNume(string nume)
{

	this->nume = nume;
}

void Eveniment::setData(int dataEven[3])
{
	if (dataEven[0] > 0 && dataEven[0] <= 31 && dataEven[1] > 0 && dataEven[1] <= 12)
	{
		for (int i = 0; i < 3; i++)
		{
			this->dataEven[i] = dataEven[i];
		}
	}
	else
	{

		for (int i = 0; i < 3; i++)
		{
			this->dataEven[i] = 0;
		}
		cout << "Eroare! Data introdusa nu este corecta.";
	}
}

void Eveniment::setOra(int ora[2])
{
	if (ora[0] <= 24 && ora[1] <= 59)
	{
		for (int j = 0; j < 2; j++)
		{
			this->ora[j] = ora[j];
		}
	}
	else
	{
		for (int j = 0; j < 2; j++)
		{
			this->ora[j] = 0;
		}
		cout << "Eroare! Ora introdusa este gresita";
	}
}

void Eveniment::setLocatie(Locatie locatie)
{
	this->locatie = locatie;

}

void Eveniment::setPentruMajori(bool pentruMajori)
{
	this->pentruMajori = pentruMajori;
}

//OPERATOR<<
ostream& operator<<(ostream& out, const Eveniment& e)
{
	out << "Denumirea evenimentului: " << e.nume << endl;
	out << "Eveniment pentru persoane peste 18 ani (1-DA; 0-NU): " << e.pentruMajori << endl;
	out << "Data evenimentului in format zz-ll-aaaa: ";
	out << e.dataEven[0] << "-" << e.dataEven[1] << "-" << e.dataEven[2];
	cout << endl;
	out << "Ora evenimentului in format oo:mm: ";
	out << e.ora[0] << ":" << e.ora[1] << endl;
	out << "Locatia evenimentului: " << endl;
	out << e.locatie << endl;

	return out;
}

//OPERATOR>>
istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Introduceti denumirea evenimentului:";
	in >> e.nume;
	cout << "Iroduceti data evenimentului in format zz-ll-aaaa:";
	in >> e.dataEven[0];
	in >> e.dataEven[1];
	in >> e.dataEven[2];
	cout << "Introduceti ora evenimentului in format oo:mm:";
	if (e.ora[0] <= 24 && e.ora[1] <= 59)
	{

		in >> e.ora[0];
		cout << ":";
		in >> e.ora[1];


	}
	else
	{
		cout << "Eroare! Ora introdusa este gresita.";
	}
	cout << "Introduceti locatia evenimentului:";
	in >> e.locatie;
	cout << "Este evenimentul pentru persoane peste 18 ani?(1-DA, 0-NU)";
	in >> e.pentruMajori;
	return in;
}

//OPERATOR !
//Pentru a schimba daca evenimentul este pentru persoane peste 18 ani.
void operator!(Eveniment& e)
{
	if (e.pentruMajori == 0)
	{
		e.pentruMajori = 1;
	}
	else
	{
		e.pentruMajori = 0;
	}
}

//OPERATOR >=
//Pentru a verifica daca un eveniment este in aceiasi data sau mai tarziu decat altul
bool Eveniment::operator>=(const Eveniment& e)
{
	if (this->dataEven[0] >= e.dataEven[0] && this->dataEven[1] >= dataEven[1] && this->dataEven[2] >= dataEven[2])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//METODA SCHIMBA ZIUA DIN CADRUL EVENIMENTULUI
void Eveniment::schimbareZi(int ziNoua)
{
	if (ziNoua > 0 && ziNoua <= 31)
	{
		this->dataEven[0] = ziNoua;
	}
	else
	{
		cout << "Eroare! Ziua introdusa este gresita!";
	}
}

//METODA SCHIMBA ORA DIN CADRUL EVENIMENTULUI
void Eveniment::schimbareOra(int oraNoua)
{
	if (oraNoua >= 1 && oraNoua <= 24)
	{
		this->ora[0] = oraNoua;
	}
	else
	{
		cout << "Eroare! Ora introdusa este gresita!";
	}
}

//SCRIEREA IN FISIERE TEXT
ofstream& operator<<(ofstream& file, const Eveniment& e)
{
	file << e.nume << endl;
	file << e.dataEven << endl;
	file << e.ora << endl;
	file << e.locatie << endl;
	file << e.pentruMajori << endl;
	return file;
}

//CITIREA DIN FISIERE TEXT 
ifstream& operator>> (ifstream& file, Eveniment& e)
{
	file >> e.nume;
	file >> e.dataEven[0];
	file >> e.dataEven[1];
	file >> e.dataEven[2];
	file >> e.ora[0];
	file >> e.ora[1];
	file >> e.locatie;
	file >> e.pentruMajori;
	return file;
}

// METODA DE SCRIERE IN FISIERE BINARE
void Eveniment::scriereBinar(fstream& file)
{
	int nrLitereNume =nume.size();
	file.write((char*)&nrLitereNume, sizeof(int));
	file.write(nume.c_str(), nrLitereNume);

	file.write((char*)&dataEven[0], sizeof(int));
	file.write((char*)&dataEven[1], sizeof(int));
	file.write((char*)&dataEven[2], sizeof(int));

	file.write((char*)&ora[0], sizeof(int));
	file.write((char*)&ora[1], sizeof(int));

	this->locatie.scriereBinar(file);

	file.write((char*)&pentruMajori, sizeof(bool));

}

//METODA DE CITIRE DIN FISIERE BINARE
void Eveniment::citireBinar(fstream& file)
{
	int nrLitereNume=0;
	file.read((char*)&nrLitereNume, sizeof(int));
	string aux;
	aux.resize(nrLitereNume);
	file.read((char*)aux.c_str(), nrLitereNume);
	nume = aux;

	file.read((char*)&dataEven[0], sizeof(int));
	file.read((char*)&dataEven[1], sizeof(int));
	file.read((char*)&dataEven[2], sizeof(int));

	file.read((char*)&ora[0], sizeof(int));
	file.read((char*)&ora[1], sizeof(int));

	this->locatie.citireBinar(file);

	file.read((char*)&pentruMajori, sizeof(bool));
}



