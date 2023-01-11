#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<string>
#include"Locatie.h"

using namespace std;





class Eveniment {
private:
	string nume;
	int data[3];
	int ora[2];
	Locatie locatie;
	bool pentruMajori;

public:
	//CONSTRUCTORI
	Eveniment()
	{
		this->nume = "Necunoscut";
		for (int i = 0; i < 3; i++)
		{
			this->data[i] = 0;
		}
		for (int j = 0; j < 2; j++)
		{
			this->ora[j] = 0;
		}
		Locatie l1;
		this->locatie = l1;
		this->pentruMajori = 1;
	}

	Eveniment(const string nume, int data[3], int ora[2], Locatie locatie, bool pentruMajori)
	{
		this->nume = nume;
		if (data[0] > 0 && data[0] <= 31 && data[1] > 0 && data[1] <= 12)
		{
			for (int i = 0; i < 3; i++)
			{
				this->data[i] = data[i];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				this->data[i] = 0;
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
	~Eveniment()
	{

	}

	//CONSTRUCTOR DE COPIERE
	Eveniment(const Eveniment& e)
	{
		this->nume = e.nume;
		if (e.data[0] > 0 && e.data[0] <= 31 && e.data[1] > 0 && e.data[1] <= 12)
		{
			for (int i = 0; i < 3; i++)
			{
				this->data[i] = e.data[i];
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				this->data[i] =0;
			}
		}

		if(ora[0] <= 24 && ora[1] <= 59)
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
	Eveniment& operator=(const Eveniment& e)
	{
		if (this != &e)
		{

			this->nume = e.nume;
			if (e.data[0] > 0 && e.data[0] <= 31 && e.data[1] > 0 && e.data[1] <= 12)
			{
				for (int i = 0; i < 3; i++)
				{
					this->data[i] = e.data[i];
				}
			}
			else
			{
				for (int i = 0; i < 3; i++)
				{
					this->data[i] = 0;
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
	string getNume()
	{
		return nume;
	}

	int getData()
	{
		for (int i = 0; i < 3; i++)
		{
			return data[i];
		}
	}

	int getOra()
	{
		for (int j = 0; j < 2; j++)
		{
			return ora[j];
		}
	}

	Locatie getLocatie()
	{
		return locatie;
	}

	bool getPentruMajori()
	{
		return pentruMajori;
	}

	//SETTERI
	void setNume(string nume)
	{

		this->nume = nume;
	}

	void setData(int data[3])
	{
		if (data[0] > 0 && data[0] <= 31 && data[1] > 0 && data[1] <= 12)
		{
			for (int i = 0; i < 3; i++)
			{
				this->data[i] = data[i];
			}
		}
		else
		{

			for (int i = 0; i < 3; i++)
			{
				this->data[i] = 0;
			}
			cout << "Eroare! Data introdusa nu este corecta.";
		}
	}

	void setOra(int ora[2])
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

	void setLocatie(Locatie locatie)
	{
		this->locatie = locatie;

	}

	void setPentruMajori(bool pentruMajori)
	{
		this->pentruMajori = pentruMajori;
	}

	//OPERATOR <<
	friend ostream& operator<<(ostream& out, Eveniment& e)
	{
		out << "Denumirea evenimentului: "<<e.nume<<endl;
		out << "Data evenimentului in format zz-ll-aaaa: ";
		 out<< e.data[0]<<"-"<<e.data[1]<<"-"<<e.data[2];
		cout<<endl;
		out << "Ora evenimentului in format oo:mm: ";
			out << e.ora[0] << ":" << e.ora[1]<<endl;
		out << "Locatia evenimentului: " << e.locatie<< endl;
		out << "Eveniment pentru persoane peste 18 ani (1-DA; 0-NU): " << e.pentruMajori << endl;
		return out;
     }

	//OPERATOR >>
	friend istream& operator>>(istream& in, Eveniment& e)
	{
		cout << "Introduceti denumirea evenimentului:";
		in >> e.nume;
		cout << "Iroduceti data evenimentului in format zz-ll-aaaa:";
				in>>e.data[0];
				cout << "-";
				in >> e.data[1];
				cout << "-";
				in >> e.data[2];
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
	friend void operator!(Eveniment& e)
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
	bool operator>=(const Eveniment& e)
	{
		if (this->data[1] >= e.data[0] && this->data[1] >= data[1] && this->data[2] >= data[2])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	//METODA SCHIMBA ZIUA DIN CADRUL EVENIMENTULUI
	void schimbareZi(int ziNoua)
	{
		if (ziNoua > 0 && ziNoua <= 31)
		{
			this->data[0] = ziNoua;
		}
		else
		{
			cout << "Eroare! Ziua introdusa este gresita!";
		}
	}

	//METODA SCHIMBA ORA DIN CADRUL EVENIMENTULUI
	void schimbareOra(int oraNoua)
	{
		if (oraNoua >=1 && oraNoua <= 24)
		{
			this->ora[0] = oraNoua;
		}
		else
		{
			cout << "Eroare! Ora introdusa este gresita!";
		}
	}


};
