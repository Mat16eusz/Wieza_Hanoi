#ifndef TALERZ_H
#define TALERZ_H

#include "Stos.h"

/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 * 
 * Klasa reprezentuj¹ca talerze wie¿y Hanoi dziedzicz¹ca z klasy Stos.
 *
 * @class Talerz Talerz.h
 * @brief Klasa talerzy gry wie¿a Hanoi.
 */
class Talerz : public Stos<short>
{
private:
	short szerokosc_najwiekszego_talerza;
	unsigned* szerokosc_talerzy;
	short ilosc_talerzy;
	const char linia_pionowa = 186;

public:
	Talerz();
	Talerz(short ilosc_talerzy);
	~Talerz();

	void idz_do_x_y(int x, int y);
	void rysuj_start(short ilosc_talerzy, Talerz& Obiekt);
	void rysuj_usun(short ilosc_talerzy, Stos& Obiekt_stos, Talerz& Obiekt_talerz, short palik_na);
	void rysuj_dodaj(short ilosc_talerzy, Stos& Obiekt_stos, Talerz& Obiekt_talerz, short palik_na);
	bool koniec_gry(Talerz& Obiekt, short ilosc_talerzy);
};

#endif
