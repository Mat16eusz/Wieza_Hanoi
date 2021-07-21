/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include <iostream>
#include <windows.h>

#include "Stos.h"
#include "Talerz.h"
#include "Ustawienia_konsoli.h"

using namespace std;

int main()
{
    short ilosc_talerzy = 0;
    short palik_z, palik_na;

    rozmiar_konsoli();
    
    while (ilosc_talerzy < 3 || ilosc_talerzy > 16)
    {
        cout << "Podaj ilosc talerzy(3-16): ";
        cin  >> ilosc_talerzy;

        if (ilosc_talerzy < 3 || ilosc_talerzy > 16)
        {
            cout << "Podales za malo lub za duzo talerzy!" << endl;
        }
    }
    system("cls");

    Talerz A(ilosc_talerzy);
    Talerz B(ilosc_talerzy);
    Talerz C(ilosc_talerzy);
    for (short i = 0; i < ilosc_talerzy; i++)
    {
        A.poloz_na_stos(i);
    }

    A.rysuj_start(ilosc_talerzy, A);

    while (true)
    {
        pokaz_kursor_na_ekranie(true);
        cout << "Podaj z ktorego stosu chcesz przeniesc talerz: ";
        cin  >> palik_z;
        pokaz_kursor_na_ekranie(false);
        
        for (short i = 0; i < 2; i++)
        {
            A.idz_do_x_y(0, ilosc_talerzy + 5 + i);
            for (short j = 0; j < 200; j++)
            {
                cout << " ";
            }
        }
        A.idz_do_x_y(0, ilosc_talerzy + 5);

        if (palik_z == 1)
        {
            pokaz_kursor_na_ekranie(true);
            cout << "Podaj palik na ktorych chcesz przeniesc talerz: ";
            cin  >> palik_na;
            pokaz_kursor_na_ekranie(false);
            for (short i = 0; i < 2; i++)
            {
                A.idz_do_x_y(0, ilosc_talerzy + 5 + i);
                for (short j = 0; j < 200; j++)
                {
                    cout << " ";
                }
            }
            A.idz_do_x_y(0, ilosc_talerzy + 5);

            if (palik_na == 2)
            {
                if (A.sprawdz_wielkosc_ostatniego_elementu(A, B))
                {
                    A.zamien(A, B);
                    A.rysuj_usun(ilosc_talerzy, A, A, palik_z);
                    B.rysuj_dodaj(ilosc_talerzy, B, B, palik_na);
                }
            }
            else if (palik_na == 3)
            {
                if (A.sprawdz_wielkosc_ostatniego_elementu(A, C))
                {
                    A.zamien(A, C);
                    A.rysuj_usun(ilosc_talerzy, A, A, palik_z);
                    C.rysuj_dodaj(ilosc_talerzy, C, C, palik_na);

                    if (C.koniec_gry(C, ilosc_talerzy))
                    {
                        cout << "Gratulacje!" << endl << "Ulozyles wieze Hanoi!" << endl;
                        system("pause > nul");

                        exit(0);
                    }
                }
            }
            else
            {
                cout << "Nie ma takiego palika lub nie mozna przeniesc na ten sam palik!" << endl;
                Sleep(1000);
                for (short i = 0; i < 2; i++)
                {
                    A.idz_do_x_y(0, ilosc_talerzy + 5 + i);
                    for (short j = 0; j < 200; j++)
                    {
                        cout << " ";
                    }
                }
                A.idz_do_x_y(0, ilosc_talerzy + 5);
            }

        }
        else if (palik_z == 2)
        {
            pokaz_kursor_na_ekranie(true);
            cout << "Podaj palik na ktorych chcesz przeniesc talerz: ";
            cin  >> palik_na;
            pokaz_kursor_na_ekranie(false);
            for (short i = 0; i < 2; i++)
            {
                A.idz_do_x_y(0, ilosc_talerzy + 5 + i);
                for (short j = 0; j < 200; j++)
                {
                    cout << " ";
                }
            }
            A.idz_do_x_y(0, ilosc_talerzy + 5);

            if (palik_na == 1)
            {
                if (B.sprawdz_wielkosc_ostatniego_elementu(B, A))
                {
                    B.zamien(B, A);
                    B.rysuj_usun(ilosc_talerzy, B, B, palik_z);
                    A.rysuj_dodaj(ilosc_talerzy, A, A, palik_na);
                }
            }
            else if (palik_na == 3)
            {
                if (B.sprawdz_wielkosc_ostatniego_elementu(B, C))
                {
                    B.zamien(B, C);
                    B.rysuj_usun(ilosc_talerzy, B, B, palik_z);
                    C.rysuj_dodaj(ilosc_talerzy, C, C, palik_na);

                    if (C.koniec_gry(C, ilosc_talerzy))
                    {
                        cout << "Gratulacje!" << endl << "Ulozyles wieze Hanoi!" << endl;
                        system("pause > nul");

                        exit(0);
                    }
                }
            }
            else
            {
                cout << "Nie ma takiego palika lub nie mozna przeniesc na ten sam palik!" << endl;
                Sleep(1000);
                for (short i = 0; i < 2; i++)
                {
                    A.idz_do_x_y(0, ilosc_talerzy + 5 + i);
                    for (short j = 0; j < 200; j++)
                    {
                        cout << " ";
                    }
                }
                A.idz_do_x_y(0, ilosc_talerzy + 5);
            }
        }
        else if (palik_z == 3)
        {
            pokaz_kursor_na_ekranie(true);
            cout << "Podaj palik na ktorych chcesz przeniesc talerz: ";
            cin  >> palik_na;
            pokaz_kursor_na_ekranie(false);
            for (short i = 0; i < 2; i++)
            {
                A.idz_do_x_y(0, ilosc_talerzy + 5 + i);
                for (short j = 0; j < 200; j++)
                {
                    cout << " ";
                }
            }
            A.idz_do_x_y(0, ilosc_talerzy + 5);

            if (palik_na == 1)
            {
                if (C.sprawdz_wielkosc_ostatniego_elementu(C, A))
                {
                    C.zamien(C, A);
                    C.rysuj_usun(ilosc_talerzy, C, C, palik_z);
                    A.rysuj_dodaj(ilosc_talerzy, A, A, palik_na);
                }
            }
            else if (palik_na == 2)
            {
                if (C.sprawdz_wielkosc_ostatniego_elementu(C, B))
                {
                    C.zamien(C, B);
                    C.rysuj_usun(ilosc_talerzy, C, C, palik_z);
                    B.rysuj_dodaj(ilosc_talerzy, B, B, palik_na);
                }
            }
            else
            {
                cout << "Nie ma takiego palika lub nie mozna przeniesc na ten sam palik!" << endl;
                Sleep(1000);
                for (short i = 0; i < 2; i++)
                {
                    A.idz_do_x_y(0, ilosc_talerzy + 5 + i);
                    for (short j = 0; j < 200; j++)
                    {
                        cout << " ";
                    }
                }
                A.idz_do_x_y(0, ilosc_talerzy + 5);
            }
        }
        else
        {
            cout << "Nie ma takiego palika!" << endl;
            Sleep(1000);
            for (short i = 0; i < 2; i++)
            {
                A.idz_do_x_y(0, ilosc_talerzy + 5 + i);
                for (short j = 0; j < 200; j++)
                {
                    cout << " ";
                }
            }
            A.idz_do_x_y(0, ilosc_talerzy + 5);
        }
    }

    return 0;
}
