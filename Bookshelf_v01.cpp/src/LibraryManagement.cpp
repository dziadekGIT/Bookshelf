#include <iostream>
#include <unordered_map>
#include <utility>
#include "LibraryManagement.h"
using namespace std;

struct Book
{

    std::string bookTitle;
    std::string bookAuthor;
    std::string bookYear;
    Book(string T, string A, string Y) : bookTitle(std::move(T)),
                                         bookAuthor(std::move(A)),
                                         bookYear(std::move(Y))  {}
};


std::unordered_map<int, Book> bookShelf;

void LibraryManagement::addBook()
{
    if(bookShelf.empty())
    {
        string title;
        string author;
        string year;
        int bookID = 1;

        cout << "Podaj tytul ksiazki: " << endl;
        cin >> title;
        cout << "Tytul: " << title << endl;

        cout << "Podaj autora ksiazki: "  << endl;
        cin >> author;
        cout << "Autor: " << author << endl;

        cout << "Podaj rok wydania: " << year << endl;
        cin >> year;
        cout << " Dodano ksiazkie";

        Book kniga(title,author, year);
        bookShelf.insert({bookID,kniga});

    }
}

void LibraryManagement::printBook()
{

    cout << "Number of books in the library: " << bookShelf.size() << endl;

/* Funkcja iteruje bibliotekę i wypisuje wszystkie książki.
 *
 *  Parametry:
 *          for () -  range-based for loop, która pozwala na iterację
 *                    przez elementy unordered map
 *
 *          auto - deklaracja zmiennej o automatycznym typie
 *          const - tylko do odczytu
 *          & - skorzysta z istniejącej referencji zamiast tworzyc kopię
 *  Return :
 *  void
 */
        for (const auto& pair : bookShelf)
        {
            cout << "Book ID: " << pair.first << endl;
            cout << "Title: " << pair.second.bookTitle << endl;
            cout << "Author: " << pair.second.bookAuthor << endl;
            cout << "Year: " << pair.second.bookYear << endl;
            cout << "------------------------" << endl;
        }
}


