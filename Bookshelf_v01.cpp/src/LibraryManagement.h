#ifndef BOOKSHELF_V01_CPP_LIBRARYMANAGEMENT_H
#define BOOKSHELF_V01_CPP_LIBRARYMANAGEMENT_H

#include <iostream>
#include "LibraryManagement.h"
#include <unordered_map>
#include <utility>

using namespace std;
/**
 * @brief Klasa obsługująca bibliotekę.
 *
 * Dodawanie, wczytywanie, zapisywyanie i wyświetlanie biblioteki.
 *
 */


class LibraryManagement
{
public:

    static void printBook();
    /**
     * @brief printBook()-  wyświetla bibliotekę na ekranie
     *
     */
    void addBook();
    /**
     * @brief addBook()- przyjmuje dane od użytkownika i dodaje książkę do pamięci.
     *
     */
    static void saveBook();
    /**
     * @brief saveBook()- zapisuje książki z pamięci (przechowywane w unordered map) do pliku txt.
     *
     */
    void loadBook();
    /**
     * @brief loadBook()- wczytuje książki z pliku txt do pamięci (unoredered map).
     *
     */
};


#endif //BOOKSHELF_V01_CPP_LIBRARYMANAGEMENT_H
