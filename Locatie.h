#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>


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
	Locatie()
	{
		this->denumireaLocatiei = new char[strlen("Anonima") + 1];
		strcpy_s(this->denumireaLocatiei, strlen("Anonima") + 1, "Anonima");
		this->adresa = new char[strlen("Necunoscuta") + 1];
		strcpy_s(this->adresa, strlen("Necunoscuta") + 1, "Necunoscuta");
		this->nrLocuri = 0;
		this->nrRanduri = 0;
		this->locuriLocatie = nullptr;
	}

	Locatie(const char* denumireaLocatiei, const char* adresa, int nrLocuri, int nrRanduri, int** locuriLocatie)
	{
		this->denumireaLocatiei = new char[strlen(denumireaLocatiei) + 1];
		strcpy_s(this->denumireaLocatiei, strlen(denumireaLocatiei) + 1, denumireaLocatiei);

		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);

		if (nrLocuri > 0 && nrRanduri > 0 && locuriLocatie != nullptr)
		{
			this->nrRanduri = nrRanduri;
			this->nrLocuri = nrLocuri;
			this->locuriLocatie = new int* [nrRanduri];

			for (int i = 0; i < this->nrRanduri; i++)
			{
				this->locuriLocatie[i] = new int[this->nrLocuri];
			}
			for (int i = 0; i < this->nrRanduri; i++)
			{
				for (int j = 0; j < this->nrLocuri; j++)
				{
					if (locuriLocatie[i][j] == 1 || locuriLocatie[i][j] == 0 || locuriLocatie[i][j] == 2)
					{
						this->locuriLocatie[i][j] = locuriLocatie[i][j];
					}
					else
					{
						this->locuriLocatie[i][j] = 0;
					}
				}
			}
		}
		else
		{
			this->nrLocuri = 0;
			this->nrRanduri = 0;
			this->locuriLocatie = nullptr;
		}
	}
	//DESTRUCTOR
	~Locatie()
	{
		if (this->adresa != nullptr)
		{
			delete[]this->adresa;
		}

		if (this->locuriLocatie != nullptr)
		{
			delete[]this->locuriLocatie;
		}
	}

	//CONSTRUCTOR DE COPIERE
	Locatie(const Locatie& l)
	{
		this->adresa = new char[strlen(l.adresa) + 1];
		strcpy_s(this->adresa, strlen(l.adresa) + 1, l.adresa);
		this->denumireaLocatiei = l.denumireaLocatiei;
		if (nrLocuri > 0 && nrRanduri > 0 && locuriLocatie != nullptr)
		{
			this->nrRanduri = l.nrRanduri;
			this->nrLocuri = l.nrLocuri;
			this->locuriLocatie = new int* [l.nrRanduri];

			for (int i = 0; i < l.nrRanduri; i++)
			{
				locuriLocatie[i] = new int[l.nrLocuri];

				for (int j = 0; j < l.nrLocuri; j++)
				{
					if (l.locuriLocatie[i][j] == 1 || l.locuriLocatie[i][j] == 0 || l.locuriLocatie[i][j] == 2)
					{
						this->locuriLocatie[i][j] = l.locuriLocatie[i][j];
					}
					else
					{
						this->locuriLocatie[i][j] = 0;
					}
				}
			}
		}

	}

	//OPERATOR DE ATRIBUIRE
	Locatie& operator=(const Locatie& l)
	{
		if (this != &l)
		{
			this->adresa = new char[strlen(l.adresa) + 1];
			strcpy_s(this->adresa, strlen(l.adresa) + 1, l.adresa);
			this->denumireaLocatiei = l.denumireaLocatiei;
			for (int i = 0; i < l.nrRanduri; i++)
			{
				locuriLocatie[i] = new int[l.nrLocuri];

				for (int j = 0; j < l.nrLocuri; j++)
				{
					if (l.locuriLocatie[i][j] == 1 || l.locuriLocatie[i][j] == 0 || l.locuriLocatie[i][j] == 2)
					{
						this->locuriLocatie[i][j] = l.locuriLocatie[i][j];
					}
					else
					{
						this->locuriLocatie[i][j] = 0;
					}
				}
			}
		}
		return *this;
	}

	//GETTERI
	char* getDenumireaLocatiei()
	{
		return denumireaLocatiei;
	}

	char* getAdresa()
	{
		return this->adresa;
	}

	int getLocuri()
	{
		return this->nrLocuri;
	}

	int getRanduri()
	{
		return this->nrRanduri;
	}

	int** getMatriceLocuriLocatie()
	{
		if (locuriLocatie != nullptr)
		{
			int** copy = new int* [nrRanduri];
			for (int i = 0; i < nrRanduri; i++)
			{
				copy[i] = new int[nrLocuri];
				for (int j = 0; j < nrLocuri; j++)
				{
					copy[i][j] = locuriLocatie[i][j];
				}
			}
			return copy;
		}
		else return nullptr;
	}


	//SETTERI
	void setDenumireaLocatiei(char* denumireaLocatiei)
	{
		if (denumireaLocatiei != nullptr)
		{
			this->denumireaLocatiei = denumireaLocatiei;
		}
	}

	void setAdresa(char* adresa)
	{
		if (adresa != nullptr)
		{
			this->adresa = adresa;
		}
		else
		{
			this->adresa = nullptr;
		}
	}

	void setLocuri(int nrRanduri, int nrLocuri, int** locuriLocatie)
	{
		if (nrLocuri > 0 && nrRanduri > 0 && locuriLocatie != nullptr)
		{
			this->nrRanduri = nrRanduri;
			this->nrLocuri = nrLocuri;
			this->locuriLocatie = new int* [nrRanduri];

			for (int i = 0; i < nrRanduri; i++)
			{
				locuriLocatie[i] = new int[nrLocuri];

				for (int j = 0; j < nrLocuri; j++)
				{
					if (locuriLocatie[i][j] == 0 || locuriLocatie[i][j] == 1 || locuriLocatie[i][j] == 2)
					{
						this->locuriLocatie[i][j] = locuriLocatie[i][j];
					}
					else
					{
						locuriLocatie[i][j] = 0;
					}
				}
			}
		}
	}

	//OPERATOR <<
	friend ostream& operator<<(ostream& out, Locatie& l)
	{
		out << "Denumirea locatiei este: " << l.denumireaLocatiei << endl;
		out << "Adresa este: " << l.adresa << endl;
		out << "Numarul de randuri: " << l.nrRanduri << endl;
		out << "Numarul de locuri rand:" << l.nrLocuri << endl;
		out << "1-Loc ocupat, 0-Loc Liber, 2-Loc Rezervat:" << l.locuriLocatie << endl;
		return out;
	}

	//OPERATOR>> 
	friend istream& operator>>(istream& in, Locatie& l)
	{
		if (l.adresa != nullptr)
		{
			delete[]l.adresa;
		}

		if (l.locuriLocatie != nullptr)
		{
			delete[]l.locuriLocatie;
		}

		cout << "Introduceti denumirea locatiei:";
		in >> l.denumireaLocatiei;
		cout << "Introduceti adresa: ";
		char aux[150];
		in >> aux;
		l.adresa = new char[strlen(aux) + 1];
		strcpy_s(l.adresa, strlen(aux) + 1, aux);;
		cout << "Introduceti numarul de randuri:";
		in >> l.nrRanduri;
		cout << "Introduceti numarul de locuri:";
		in >> l.nrLocuri;

		l.locuriLocatie = new int* [l.nrRanduri];

		for (int i = 0; i < l.nrRanduri; i++)
		{
			l.locuriLocatie[i] = new int[l.nrLocuri];

			for (int j = 0; j < l.nrLocuri; j++)
			{
				cout << "Introduceti 1,0 sau 2; 1-Loc ocupat, 0-Loc Liber, 2-Loc Rezervat:";
				in >> l.locuriLocatie[i][j];
			}
		}
		return in;
	}

	//OPERATOR --
	//Pentru a merge cu un rand mai in spate
	Locatie& operator--()
	{
		nrRanduri--;
		if (nrRanduri >= 0)
		{
			return *this;
		}
		else
		{
			cout << "Eroare!";
		}
	}

	//OPERATOR ==
	//Pentru a vedea daca evenimentele sunt in aceiasi locatie
	bool operator==(const Locatie& l)
	{
		if (this->denumireaLocatiei == l.denumireaLocatiei)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	//METODA ADAUGA LOC OCUPAT
	void adaugaLocOcupat(int nrRandOcupat, int nrLocpeRandOcupat)
	{
		if (nrRandOcupat <= nrRanduri && nrLocpeRandOcupat <= nrLocuri)
		{
					locuriLocatie[nrRandOcupat][nrLocpeRandOcupat] = 1;	
			
		}
	}

	//METODA ADAUGA LOC REZERVAT
	void adaugaLocOcupat(int nrRandRez, int nrLocpeRandRez)
	{
		if (nrRandRez <= nrRanduri && nrLocpeRandRez <= nrLocuri)
		{
			locuriLocatie[nrRandRez][nrLocpeRandRez] = 2;

		}
	}
	
	//METODA SCHIMBA LOCUL IN LIBER
	void locLiber(int nrRandLiber, int nrLocpeRandLiber)
	{
		if (nrRandLiber <= nrRanduri && nrLocpeRandLiber <= nrLocuri)
		{
			locuriLocatie[nrRandLiber][nrLocpeRandLiber] = 0;

		}
	}

};
