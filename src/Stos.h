#ifndef STOS_H
#define STOS_H

#include <iostream>
#include <cstring>

using namespace std;

/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 * 
 * Klasa szablonowa reprezentuj¹ca stos LIFO.
 *
 * @class Stos Stos.h
 * @brief Reprezentacja stosu.
 */
template <typename Typ> class Stos
{
public:
	Typ* tablica;
	unsigned rozmiar;

	Stos();
	Stos(const Stos& Obiekt);
	~Stos();

	void poloz_na_stos(Typ na_stos);
	Typ zdejmij_z_wierzchu();
	void oproznij();
	bool czy_pusty();
	unsigned pobierz_rozmiar();
	void wyswietl_stos();
	bool sprawdz_wielkosc_ostatniego_elementu(Stos& Obiekt_1, Stos& Obiekt_2);
	void zamien(Stos& Obiekt_1, Stos& Obiekt_2);
};

/**
 * @brief Konstruktor domyœlny ustawiaj¹cy rozmiar na 0 a wska¿nik tablicy na NULL.
 */
template <typename Typ> Stos<Typ>::Stos()
{
	this->tablica = NULL;
	this->rozmiar = 0;
}

/**
 * @brief Konstruktor kopiuj¹cy obiekt klasy szablonowej Stos.
 * @param const Stos& Obiekt: obiekt klasy, który chcemy skopiowaæ.
 */
template <typename Typ> Stos<Typ>::Stos(const Stos& Obiekt)
{
	this->rozmiar = Obiekt.rozmiar;

	this->tablica = new Typ[rozmiar];

	memcpy(&this->tablica[0], &Obiekt.tablica[0], Obiekt.rozmiar * sizeof(Typ));
}

/**
 * @brief Destruktor zwalniaj¹cy pamiêæ obiektu klasy szablonowej.
 */
template <typename Typ> Stos<Typ>::~Stos()
{
	delete[] this->tablica;
	this->tablica = NULL;
}

/**
 * Funkcja tworzy tablicê tymczasow¹, kopiuje jej zawartoœæ do tablicy tymczasowej, zwalnia pamiêæ tablicy obiektu, tworzymy tablicê obiektu rozmiarze
 * o jeden wiêkszym, kopiujemy tablicê tymczasow¹ do tablicy obiektu, na ostatni element tablicy obiektu wpisujemy wartoœæ podan¹ z argumentu funkcji,
 * zwalniamy pamiêæ tablicy tymczasowej.
 * 
 * @brief Funkcja k³adzie element na szczyt stosu.
 * @param Typ na_stos: wartoœæ jak¹ k³adziemy na szczyt stosu.
 */
template <typename Typ> void Stos<Typ>::poloz_na_stos(Typ na_stos)
{
	Typ* tablica_tymczasowa = new Typ[this->rozmiar];

	memcpy(&tablica_tymczasowa[0], &this->tablica[0], this->rozmiar * sizeof(Typ));

	delete[] this->tablica;
	this->rozmiar++;
	this->tablica = new Typ[this->rozmiar];

	memcpy(&this->tablica[0], &tablica_tymczasowa[0], this->rozmiar * sizeof(Typ));
	this->tablica[this->rozmiar - 1] = na_stos;

	delete[] tablica_tymczasowa;
	tablica_tymczasowa = NULL;
}

/**
 * Funkcja sprawdza czy stos jest pusty, jeœli tak rzuca wyj¹tek. Zmiejszamy rozmiar o jeden, ostatni¹ wartoœæ elementu tablicy zapisujemy do zmiennej,
 * tworzymy tablicê tymaczosow¹, kopiujemy tablicê obiektu do tablicy tymczasowej, zwalniamy pamiêæ tablicy obiektu, tworzymy tablicê obiektu o rozmiarze
 * o jeden mniejszym ni¿ bazowa wartoœæ, kopiujemy elementy tablicy tymczasowej do tablicy obiektu, zwalniamy pamiêæ tablicy tymczasowej.
 *
 * @brief Funkcja zdejmuje ze szczytu wartoœæ element.
 * @return Typ ostatni: funkcja zwraca usuniêt¹ wartoœæ elementu tablicy obiektu.
 */
template <typename Typ> Typ Stos<Typ>::zdejmij_z_wierzchu()
{
	if (czy_pusty())
	{
		throw this->rozmiar;
	}
	else
	{
		this->rozmiar--;

		Typ ostatni = this->tablica[this->rozmiar];

		Typ* tablica_tymczasowa = new Typ[this->rozmiar];

		memcpy(&tablica_tymczasowa[0], &this->tablica[0], this->rozmiar * sizeof(Typ));

		delete[] this->tablica;
		this->tablica = new Typ[this->rozmiar];

		memcpy(&this->tablica[0], &tablica_tymczasowa[0], this->rozmiar * sizeof(Typ));

		delete[] tablica_tymczasowa;
		tablica_tymczasowa = NULL;

		return ostatni;
	}
}

/**
 * @brief Funkcja opró¿niaj¹ca ca³y stos.
 */
template <typename Typ> void Stos<Typ>::oproznij()
{
	while (this->rozmiar != 0)
	{
		zdejmij_z_wierzchu();
	}
}

/**
 * @brief Funkcja sprawdzaj¹ca czy stos jest pusty.
 * @return bool: prawda jeœli pusty, fa³sz jeœli nie jest pusty.
 */
template <typename Typ> bool Stos<Typ>::czy_pusty()
{
	if (this->rozmiar == 0)
	{
		return true;
	}

	return false;
}

/**
 * @brief Funkcja zwracaj¹ca rozmiar tablicy obiektu.
 * @return unsigned rozmiar: wartoœæ rozmiaru tablicy.
 */
template <typename Typ> unsigned Stos<Typ>::pobierz_rozmiar()
{
	return this->rozmiar;
}

/**
 * @brief Funkcja wyœwietlaj¹ca wartoœci z ca³ego stosu.
 */
template <typename Typ> void Stos<Typ>::wyswietl_stos()
{
	for (int i = 0; i < this->rozmiar; i++)
	{
		cout << this->tablica[i] << endl;
	}
}

/**
 * @brief Funkcja sprwdzaj¹ca kolejnoœæ po³o¿enia na stosie.
 * @param Stos& Obiekt_1: obiekt pierwszy.
 * @param Stos& Obiekt_1: obiekt drugi.
 * @return bool: prawda lub fa³sz.
 */
template <typename Typ> bool Stos<Typ>::sprawdz_wielkosc_ostatniego_elementu(Stos& Obiekt_1, Stos& Obiekt_2)
{
	if (Obiekt_1.rozmiar == 0 && Obiekt_2.rozmiar == 0)
	{
		return false;
	}
	if (Obiekt_2.rozmiar == 0)
	{
		return true;
	}
	if (Obiekt_1.rozmiar == 0)
	{
		return false;
	}
	if (Obiekt_1.tablica[Obiekt_1.rozmiar - 1] < Obiekt_2.tablica[Obiekt_2.rozmiar - 1])
	{
		return false;
	}
	
	return true;
}

/**
 * @brief Funkcja zamieniaj¹ca element ze szczytu obiektu na szczyt drugiego obiektu.
 * @param Stos& Obiekt_1: obiekt pierwszy.
 * @param Stos& Obiekt_2: obiekt drugi.
 */
template <typename Typ> void Stos<Typ>::zamien(Stos& Obiekt_1, Stos& Obiekt_2)
{
	Obiekt_2.poloz_na_stos(Obiekt_1.zdejmij_z_wierzchu());
}

#endif
