using namespace std;
#include "Menu.h"
#include <iostream>

void Menu::menu()
{
    cout << "Menu: "<<endl<<"------------------------\n";
    cout << " 1. Wypisz listę książek\n";
    cout << " 2. Dodaj książkę\n";
    cout << " 3. Usuń książkę\n";
    cout << " 4. Zapisz bibliotekę do pliku\n";
    cout << " 5. Wczytaj z pliku\n";
    cout << " 6. EXIT\n";
    cout << "------------------------\n";
    cout << "Wybierz z menu: ";

    int chose;
    cin >> chose;

        switch(chose)
        {
            case 1:
            {
                cout<<"Funkcjonalność w produkcji";
                break;
            }
            case 2:
            {
                cout<<"Funkcjonalność w produkcji";
                break;
            }

            case 3:
            {
                cout<<"Funkcjonalność w produkcji";
                break;
            }

            case 4:
            {
                cout<<"Funkcjonalność w produkcji";
                break;
            }

            case 5:
            {
                cout<<"Funkcjonalność w produkcji";
                break;
            }

            case 6:
            {
                break;
            }

        }



}