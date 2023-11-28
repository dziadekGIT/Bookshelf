using namespace std;
#include "Menu.h"
#include <iostream>
#include "LibraryManagement.h"

void Menu::menu()
{
    LibraryManagement library;
    int chose;
    do
    {
        cout << "Menu: \n"<<"------------------------\n";
        cout << " 1. Wypisz listę książek\n";
        cout << " 2. Dodaj książkę\n";
        cout << " 3. Usuń książkę\n";
        cout << " 4. Zapisz bibliotekę do pliku\n";
        cout << " 5. Wczytaj z pliku\n";
        cout << " 6. EXIT\n";
        cout << "------------------------\n";
        cout << "Wybierz z menu: ";

        cin >> chose;

        switch (chose)
        {
            case 1:
            {
                library.printBook();
                continue;
            }
            case 2:
            {
                library.addBook();

                continue;
            }
            case 3:
            {
                cout << "Funkcjonalność w produkcji";
                continue;
            }
            case 4:
            {
                library.saveBook();
                continue;
            }
            case 5:
            {
                library.loadBook();
                continue;
            }
            case 6:
            {

                continue;
            }

        }
    }
    while (chose !=6);
}