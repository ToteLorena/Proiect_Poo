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
		if(this->denumireaLocatiei != nullptr)
		{
			delete[]this->denumireaLocatiei;
		}
		
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
		this->denumireaLocatiei = new char[strlen(l.denumireaLocatiei) + 1];
		strcpy_s(this->denumireaLocatiei, strlen(l.denumireaLocatiei) + 1, l.denumireaLocatiei);

		this->adresa = new char[strlen(l.adresa) + 1];
		strcpy_s(this->adresa, strlen(l.adresa) + 1, l.adresa);

			this->nrRanduri = l.nrRanduri;
			this->nrLocuri = l.nrLocuri;
			this->locuriLocatie = new int* [this->nrRanduri];

			for (int i = 0; i < this->nrRanduri; i++)
			{
				this->locuriLocatie[i] = new int[l.nrLocuri];
			}

			for (int i = 0; i < this->nrRanduri; i++)
			{
				for (int j = 0; j < this->nrLocuri; j++)
				{
						this->locuriLocatie[i][j] = l.locuriLocatie[i][j];
					
				}
			}
	}


	//OPERATOR DE ATRIBUIRE
	Locatie& operator=(const Locatie& l)
	{
		if (this->adresa != nullptr)
		{
			delete[]this->adresa;
		}
		if (this->denumireaLocatiei != nullptr)
		{
			delete[]this->denumireaLocatiei;
		}
		if (this->locuriLocatie != nullptr)
		{
			delete[]this->locuriLocatie;
		}

		if (this != &l)
		{

			this->denumireaLocatiei = new char[strlen(l.denumireaLocatiei) + 1];
			strcpy_s(this->denumireaLocatiei, strlen(l.denumireaLocatiei) + 1, l.denumireaLocatiei);

			this->adresa = new char[strlen(l.adresa) + 1];
			strcpy_s(this->adresa, strlen(l.adresa) + 1, l.adresa);

			this->nrRanduri = l.nrRanduri;
			this->nrLocuri = l.nrLocuri;
			this->locuriLocatie = new int* [this->nrRanduri];

			for (int i = 0; i < this->nrRanduri; i++)
			{
				this->locuriLocatie[i] = new int[l.nrLocuri];
			}

			for (int i = 0; i < this->nrRanduri; i++)
			{
				for (int j = 0; j < this->nrLocuri; j++)
				{
					this->locuriLocatie[i][j] = l.locuriLocatie[i][j];

				}
			}
		}
		return *this;
	}

	//GETTERI
	char* getDenumireaLocatiei()
	{
		if (denumireaLocatiei != nullptr)
		{
			char*copy=new char[strlen(denumireaLocatiei) + 1];
			strcpy_s(copy, strlen(denumireaLocatiei) + 1, denumireaLocatiei);
			return copy;
		}
		else
		{
			return nullptr;
		}
	}

	char* getAdresa()
	{
		if (adresa != nullptr)
		{
			char* copy = new char[strlen(adresa) + 1];
			strcpy_s(copy, strlen(adresa) + 1, adresa);
			return copy;
		}
		else
		{
			return nullptr;
		}
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
			}
				for (int i = 0; i < nrRanduri; i++)
				{
					for (int j = 0; j < nrLocuri; j++)
					{
						copy[i][j]=locuriLocatie[i][j];
					}
				}
			return copy;
		}
		else return nullptr;
	}


	//SETTERI
	void setDenumireaLocatiei(char* denumireaLocatiei)
	{
		if (this->denumireaLocatiei != nullptr)
		{
			delete[]this->denumireaLocatiei;
		}
		
		if(denumireaLocatiei!=nullptr)
		{
	        this->denumireaLocatiei = new char[strlen(denumireaLocatiei) + 1];
		strcpy_s(this->denumireaLocatiei, strlen(denumireaLocatiei) + 1, denumireaLocatiei);
		}
		else
		{
denumireaLocatiei = nullptr;
		}
		
	}

	void setAdresa(char* adresa)
	{
		if (this->adresa != nullptr)
		{
			delete[]this->adresa;
		}
		
		if(adresa!=nullptr)
		{
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
		}
		else
		{
			adresa=nullptr;
		}
		
	}

	void setLocuri(int nrRanduri, int nrLocuri, int** locuriLocatie)
	{
		if(this->locuriLocatie != nullptr)
		{
			delete[]this->locuriLocatie;
		}

		if (nrLocuri > 0 && nrRanduri > 0 && locuriLocatie != nullptr)
		{
			this->nrRanduri = nrRanduri;
			this->nrLocuri = nrLocuri;
			this->locuriLocatie = new int* [this->nrRanduri];

			for (int i = 0; i < this->nrRanduri; i++)
			{
				this->locuriLocatie[i] = new int[nrLocuri];
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
		out << "1-Loc ocupat, 0-Loc Liber, 2-Loc Rezervat:"<<endl;
		for (int i = 0; i < l.nrRanduri; i++)
		{
			for (int j = 0; j < l.nrLocuri; j++)
			{
				out << l.locuriLocatie[i][j]<<" ";
			}
			cout << endl;
			
		}
		cout << endl;
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
		
		if(l.denumireaLocatiei != nullptr)
		{
			delete[]l.denumireaLocatiei;
		}
		
	
		cout << "Introduceti denumirea locatiei:";
		char aux1[160];
		in >> aux1;
		l.denumireaLocatiei = new char[strlen(aux1) + 1];
		strcpy_s(l.denumireaLocatiei, strlen(aux1) + 1, aux1);
		cout << "Introduceti adresa: ";
		char aux2[150];
		in >> aux2;
		l.adresa = new char[strlen(aux2) + 1];
		strcpy_s(l.adresa, strlen(aux2) + 1, aux2);
		cout << "Introduceti numarul de randuri:";
		in >> l.nrRanduri;
		cout << "Introduceti numarul de locuri:";
		in >> l.nrLocuri;

		l.locuriLocatie = new int* [l.nrRanduri];

		
		for (int i = 0; i < l.nrRanduri; i++)
		{
			l.locuriLocatie[i] = new int[l.nrLocuri];
		}

		for (int i = 0; i < l.nrRanduri; i++)
		{
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
	void adaugaLocRezervat(int nrRandRez, int nrLocpeRandRez)
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
