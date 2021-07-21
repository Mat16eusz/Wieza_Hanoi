#ifndef STOS_H
#define STOS_H

#include <iostream>
#include <cstring>

using namespace std;

/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 * 
 * Klasa szablonowa reprezentuj�ca stos LIFO.
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
 * @brief Konstruktor domy�lny ustawiaj�cy rozmiar na 0 a wska�nik tablicy na NULL.
 */
template <typename Typ> Stos<Typ>::Stos()
{
	this->tablica = NULL;
	this->rozmiar = 0;
}

/**
 * @brief Konstruktor kopiuj�cy obiekt klasy szablonowej Stos.
 * @param const Stos& Obiekt: obiekt klasy, kt�ry chcemy skopiowa�.
 */
template <typename Typ> Stos<Typ>::Stos(const Stos& Obiekt)
{
	this->rozmiar = Obiekt.rozmiar;

	this->tablica = new Typ[rozmiar];

	memcpy(&this->tablica[0], &Obiekt.tablica[0], Obiekt.rozmiar * sizeof(Typ));
}

/**
 * @brief Destruktor zwalniaj�cy pami�� obiektu klasy szablonowej.
 */
template <typename Typ> Stos<Typ>::~Stos()
{
	delete[] this->tablica;
	this->tablica = NULL;
}

/**
 * Funkcja tworzy tablic� tymczasow�, kopiuje jej zawarto�� do tablicy tymczasowej, zwalnia pami�� tablicy obiektu, tworzymy tablic� obiektu rozmiarze
 * o jeden wi�kszym, kopiujemy tablic� tymczasow� do tablicy obiektu, na ostatni element tablicy obiektu wpisujemy warto�� podan� z argumentu funkcji,
 * zwalniamy pami�� tablicy tymczasowej.
 * 
 * @brief Funkcja k�adzie element na szczyt stosu.
 * @param Typ na_stos: warto�� jak� k�adziemy na szczyt stosu.
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
 * Funkcja sprawdza czy stos jest pusty, je�li tak rzuca wyj�tek. Zmiejszamy rozmiar o jeden, ostatni� warto�� elementu tablicy zapisujemy do zmiennej,
 * tworzymy tablic� tymaczosow�, kopiujemy tablic� obiektu do tablicy tymczasowej, zwalniamy pami�� tablicy obiektu, tworzymy tablic� obiektu o rozmiarze
 * o jeden mniejszym ni� bazowa warto��, kopiujemy elementy tablicy tymczasowej do tablicy obiektu, zwalniamy pami�� tablicy tymczasowej.
 *
 * @brief Funkcja zdejmuje ze szczytu warto�� element.
 * @return Typ ostatni: funkcja zwraca usuni�t� warto�� elementu tablicy obiektu.
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
 * @brief Funkcja opr�niaj�ca ca�y stos.
 */
template <typename Typ> void Stos<Typ>::oproznij()
{
	while (this->rozmiar != 0)
	{
		zdejmij_z_wierzchu();
	}
}

/**
 * @brief Funkcja sprawdzaj�ca czy stos jest pusty.
 * @return bool: prawda je�li pusty, fa�sz je�li nie jest pusty.
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
 * @brief Funkcja zwracaj�ca rozmiar tablicy obiektu.
 * @return unsigned rozmiar: warto�� rozmiaru tablicy.
 */
template <typename Typ> unsigned Stos<Typ>::pobierz_rozmiar()
{
	return this->rozmiar;
}

/**
 * @brief Funkcja wy�wietlaj�ca warto�ci z ca�ego stosu.
 */
template <typename Typ> void Stos<Typ>::wyswietl_stos()
{
	for (int i = 0; i < this->rozmiar; i++)
	{
		cout << this->tablica[i] << endl;
	}
}

/**
 * @brief Funkcja sprwdzaj�ca kolejno�� po�o�enia na stosie.
 * @param Stos& Obiekt_1: obiekt pierwszy.
 * @param Stos& Obiekt_1: obiekt drugi.
 * @return bool: prawda lub fa�sz.
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
 * @brief Funkcja zamieniaj�ca element ze szczytu obiektu na szczyt drugiego obiektu.
 * @param Stos& Obiekt_1: obiekt pierwszy.
 * @param Stos& Obiekt_2: obiekt drugi.
 */
template <typename Typ> void Stos<Typ>::zamien(Stos& Obiekt_1, Stos& Obiekt_2)
{
	Obiekt_2.poloz_na_stos(Obiekt_1.zdejmij_z_wierzchu());
}

#endif
