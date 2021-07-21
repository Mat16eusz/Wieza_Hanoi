/**
 * @author    Mateusz Jasiak
 * @author    mateusz.jasiak.dev@gmail.com
 */

#include "Ustawienia_konsoli.h"
#include <windows.h>

/**
 * @brief Ustawianie rozmiaru okna konsoli.
 */
void rozmiar_konsoli(void)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT wielkosc_okna = { 0, 0, 128, 31 };
    COORD wielkosc_bufora = { 120, 30 };
    HWND uchwyt_konsoli = GetConsoleWindow();

    MoveWindow(uchwyt_konsoli, 0, 0, 5000, 5000, TRUE);
    SetConsoleWindowInfo(h, 1, &wielkosc_okna);
    SetConsoleScreenBufferSize(h, wielkosc_bufora);
}

/**
 * @brief Funkcja odpowiadaj�ca za pokazywanie i ukrywanie kursora w konsoli.
 * @param bool jest_kursor: parametr przekazuj�cy warto�� czy kursor ma by� widoczny w konsoli.
 */
void pokaz_kursor_na_ekranie(bool jest_kursor)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO wlasciwosci_kursora;

    GetConsoleCursorInfo(h, &wlasciwosci_kursora);
    wlasciwosci_kursora.bVisible = jest_kursor;
    SetConsoleCursorInfo(h, &wlasciwosci_kursora);
}
