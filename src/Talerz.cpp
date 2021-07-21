/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include "Talerz.h"

#include <iostream>
#include <windows.h>

using namespace std;

/**
 * @brief Konstruktor domyœlny ustawiaj¹cy iloœæ talerzy na 0 a wska¿nik tablicy na NULL.
 */
Talerz::Talerz()
{
	this->szerokosc_talerzy = NULL;
	this->ilosc_talerzy = 0;
}

/**
 * Ustawiamy szerokoœci talerzy od najwiêkszego do najmniejszego zmiejszaj¹c ka¿dy talerz o dwa. Najwiêkszy talerz ma wielkoœæ (iloœæ kr¹¿ków * 2) + 1
 * 
 * @brief Konstruktor jednoargumentowy tworz¹cy tablicê szerokoœci talerzy.
 * @param short ilosc_talerzy: iloœæ talerzy do gry wie¿a Hanoi.
 */
Talerz::Talerz(short ilosc_talerzy)
{
	this->ilosc_talerzy = ilosc_talerzy;

	this->szerokosc_najwiekszego_talerza = (ilosc_talerzy * 2) + 1;

	this->szerokosc_talerzy = new unsigned[this->ilosc_talerzy];

	this->szerokosc_talerzy[0] = szerokosc_najwiekszego_talerza;
	for (unsigned i = 1; i < this->ilosc_talerzy; i++)
	{
		this->szerokosc_talerzy[i] = this->szerokosc_talerzy[i - 1] - 2;
	}
}

/**
 * @brief Destruktor zwalniaj¹cy pamiêæ obiektu klasy.
 */
Talerz::~Talerz()
{
	delete[] this->szerokosc_talerzy;
	this->szerokosc_talerzy = NULL;
}

/**
 * @brief Kursor jest ustawiany na podane koordynaty w konsoli.
 * @param int x: koordynat X na planszy.
 * @param int y: koordynat Y na planszy.
 */
void Talerz::idz_do_x_y(int x, int y)
{
	HANDLE hCon;
	COORD dwPos;

	dwPos.X = x;
	dwPos.Y = y;

	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon, dwPos);
}

/**
 * Funkcja rysuje 3 pionowe paliki, podstawê oraz talerze.
 *
 * @brief Funkcja rysuje pocz¹tkow¹ planszê do gry.
 * @param short ilosc_talerzy: iloœæ talerzy do gry wie¿a Hanoi.
 * @param Talerz& Obiekt: obiekt klasy talerz.
 */
void Talerz::rysuj_start(short ilosc_talerzy, Talerz& Obiekt)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	
	for (short i = 0; i < ilosc_talerzy + 3; i++)
	{
		Obiekt.idz_do_x_y(ilosc_talerzy * 7, i + 1);
		cout << this->linia_pionowa;
		Obiekt.idz_do_x_y(ilosc_talerzy * 4, i + 1);
		cout << this->linia_pionowa;
		Obiekt.idz_do_x_y(ilosc_talerzy, i + 1);
		cout << this->linia_pionowa;
	}
	SetConsoleTextAttribute(h, 0x88);
	for (short i = 0; i < (ilosc_talerzy * 8) + 1; i++)
	{
		Obiekt.idz_do_x_y(i, ilosc_talerzy + 4);
		cout << " ";
	}

	SetConsoleTextAttribute(h, 0x77);
	for (short i = 0; i < ilosc_talerzy; i++)
	{
		Obiekt.idz_do_x_y((ilosc_talerzy - i - 1), i + 4);
		for (short j = 0; j < Obiekt.szerokosc_talerzy[ilosc_talerzy - i - 1]; j++)
		{
			cout << " ";
		}
		cout << endl << endl;
	}
	SetConsoleTextAttribute(h, 0x07);
}

/**
 * Funkcja rysuje puste pole na szczycie stosu a nastêpnie rysuje pionowy palik w miejscu usuniêcia talerza.
 *
 * @brief Funkcja rysuje puste pole na szczycie stosu.
 * @param short ilosc_talerzy: iloœæ talerzy do gry wie¿a Hanoi.
 * @param Stos& Obiekt_stos: obiekt klasy stos.
 * @param Talerz& Obiekt_talerz: obiekt klasy talerz.
 * @param short palik_z: s³upek z którego chcemy przenieœæ talerz.
 */
void Talerz::rysuj_usun(short ilosc_talerzy, Stos& Obiekt_stos, Talerz& Obiekt_talerz, short palik_z)
{
	unsigned aktualny_talerz = Obiekt_stos.tablica[Obiekt_stos.rozmiar - 1];
	const short podstawa = ilosc_talerzy + 4;

	if (palik_z == 1)
	{
		Obiekt_talerz.idz_do_x_y(0, podstawa - Obiekt_stos.rozmiar - 1);
		for (short i = 0; i < Obiekt_talerz.szerokosc_talerzy[0]; i++)
		{
			cout << " ";
		}
		Obiekt_talerz.idz_do_x_y(ilosc_talerzy, podstawa - Obiekt_stos.rozmiar - 1);
		cout << this->linia_pionowa;
	}
	else if (palik_z == 2)
	{
		Obiekt_talerz.idz_do_x_y(this->szerokosc_talerzy[ilosc_talerzy - 1] * ilosc_talerzy, podstawa - Obiekt_stos.rozmiar - 1);
		for (short i = 0; i < Obiekt_talerz.szerokosc_talerzy[0]; i++)
		{
			cout << " ";
		}
		Obiekt_talerz.idz_do_x_y(ilosc_talerzy * 4, podstawa - Obiekt_stos.rozmiar - 1);
		cout << this->linia_pionowa;
	}
	else
	{
		Obiekt_talerz.idz_do_x_y((this->szerokosc_talerzy[ilosc_talerzy - 1] * ilosc_talerzy) * 2, podstawa - Obiekt_stos.rozmiar - 1);
		for (short i = 0; i < Obiekt_talerz.szerokosc_talerzy[0]; i++)
		{
			cout << " ";
		}
		Obiekt_talerz.idz_do_x_y(ilosc_talerzy * 7, podstawa - Obiekt_stos.rozmiar - 1);
		cout << this->linia_pionowa;
	}
}

/**
 * @brief Funkcja rysuje talerz na szczycie podanego palika.
 * @param short ilosc_talerzy: iloœæ talerzy do gry wie¿a Hanoi.
 * @param Stos& Obiekt_stos: obiekt klasy stos.
 * @param Talerz& Obiekt_talerz: obiekt klasy talerz.
 * @param short palik_na: s³upek na którego chcemy przenieœæ talerz.
 */
void Talerz::rysuj_dodaj(short ilosc_talerzy, Stos& Obiekt_stos, Talerz& Obiekt_talerz, short palik_na)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned aktualny_talerz = Obiekt_stos.tablica[Obiekt_stos.rozmiar - 1];
	const short podstawa = ilosc_talerzy + 4;
	short pomocnicza_1 = ilosc_talerzy - 3;
	short pomocnicza_2 = 0;

	if (ilosc_talerzy != 3)
	{
		pomocnicza_2 = ilosc_talerzy - 3;
	}

	SetConsoleTextAttribute(h, 0x77);
	if (palik_na == 1)
	{
		Obiekt_talerz.idz_do_x_y(aktualny_talerz + pomocnicza_1 - pomocnicza_2, podstawa - Obiekt_stos.rozmiar);
		for (short i = 0; i < Obiekt_talerz.szerokosc_talerzy[aktualny_talerz]; i++)
		{
			cout << " ";
		}
	}
	else if (palik_na == 2)
	{
		Obiekt_talerz.idz_do_x_y(this->szerokosc_najwiekszego_talerza + aktualny_talerz + pomocnicza_1 + 2, podstawa - Obiekt_stos.rozmiar);
		for (short i = 0; i < Obiekt_talerz.szerokosc_talerzy[aktualny_talerz]; i++)
		{
			cout << " ";
		}
	}
	else
	{
		Obiekt_talerz.idz_do_x_y((this->szerokosc_najwiekszego_talerza * 2) + aktualny_talerz + (pomocnicza_1 * 2) + 4, podstawa - Obiekt_stos.rozmiar);
		for (short i = 0; i < Obiekt_talerz.szerokosc_talerzy[aktualny_talerz]; i++)
		{
			cout << " ";
		}
	}
	Obiekt_talerz.idz_do_x_y(0, podstawa + 1);
	SetConsoleTextAttribute(h, 0x07);
}

/**
 * Funkcja sprawdza czy wie¿a zosta³a w ca³oœci przeniesiona na 3 stos.
 * 
 * @brief Funkcja sprawdza czy wie¿a Hanoi zosta³a u³o¿ona.
 * @param Talerz& Obiekt: obiekt klasy talerz.
 * @param short ilosc_talerzy: iloœæ talerzy do gry wie¿a Hanoi.
 * @return bool: prawda jeœli zosta³a u³o¿ona, fa³sz jeœli nie zosta³a u³o¿ona.
 */
bool Talerz::koniec_gry(Talerz& Obiekt, short ilosc_talerzy)
{
	Talerz Pomocniczy;
	for (short i = 0; i < ilosc_talerzy; i++)
	{
		Pomocniczy.poloz_na_stos(i);
	}

	for (short i = 0; i < ilosc_talerzy; i++)
	{
		if (Obiekt.tablica[i] != Pomocniczy.tablica[i])
		{
			return false;
		}
	}
	
	return true;
}
