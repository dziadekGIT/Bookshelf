#include <iostream>
#include <unordered_map>
#include <utility>
#include "LibraryManagement.h"
#include <fstream>
#include <sstream>


using namespace std;

struct Book
{
    std::string bookTitle;
    std::string bookAuthor;
    std::string bookYear;
    Book(string T, string A, string Y) : bookTitle(std::move(T)),
                                         bookAuthor(std::move(A)),
                                         bookYear(std::move(Y)){}
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

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Podaj tytul ksiazki: " << endl;
        getline(cin, title);


        cout << "Podaj autora ksiazki: "  << endl;
        getline(cin, author);


        cout << "Podaj rok wydania: " << endl;
        getline(cin, year);

        cout << " Dodano ksiazkie";

        Book kniga(title,author, year);
        bookShelf.insert({bookID,kniga});

    }
    else
    {
        string title;
        string author;
        string year;
        int bookID = bookShelf.size()+1;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Podaj tytul ksiazki: " << endl;
        getline(cin, title);


        cout << "Podaj autora ksiazki: "  << endl;
        getline(cin, author);


        cout << "Podaj rok wydania: " << endl;
        getline(cin, year);

        cout << " Dodano ksiazkie";

        Book kniga(title,author, year);
        bookShelf.insert({bookID,kniga});


    }
}

void LibraryManagement::printBook()
{

    cout << "Ilość książek w bibliotece: " << bookShelf.size() << endl;

/* Funkcja iteruje bibliotekę i wypisuje wszystkie książki.
 *
 *  @param:
 *          for () -  range-based for loop, która pozwala na iterację
 *                    przez elementy unordered map
 *
 *          auto - deklaracja zmiennej o automatycznym typie
 *          const - tylko do odczytu
 *          & - skorzysta z istniejącej referencji zamiast tworzyc kopię (operator może też
 *          odwoływać się do adresu zmiennej)
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

        cout << "Przyciśnij dowolny klawisz by kontynuować...\n\n";

        system("read");
}

void LibraryManagement::saveBook()
{
    ofstream save;
    save.open("/Users/espastudio/Desktop/BOOKSHELF_00/Bookshelf_v01.cpp/data/BookShelf.txt");

    for (const auto& pair:bookShelf)
    {
    save  << "-------------\n"
          << pair.second.bookTitle << "\n"
          << pair.second.bookAuthor << "\n"
          << pair.second.bookYear <<"\n"
          << "-------------\n";
    }
    cout << "Pomyślnie zapisano bilbiotekę do pliku BookShelf.txt\n";
    system("read");
    save.close();
}

void LibraryManagement::loadBook()
{
    ifstream load("/Users/espastudio/Desktop/BOOKSHELF_00/Bookshelf_v01.cpp/data/BookShelf.txt");
    string txtLine;


    while (getline(load,txtLine))
    {
       if (txtLine.empty() || txtLine.find("-------------") != string::npos)
           // string::npos - stała statyczna, której wartość reprezentuje brak
           // wystąpienia określonego podciągu w ciągu znaków. W kontekście find
           // oznacza że ozdobnik nie został znaleziony.
           //  ten if pomija "--------"
       {
           continue;
       }

        string title;
        string author;
        string year;

        istringstream iss(txtLine);
        getline(iss, title);
        getline(load, author);
        getline(load, year);
        Book kniga(title,author,year);

        int bookID = 1;
        if (bookShelf.empty())
        {

            bookShelf.insert({bookID,kniga});
        }
        else
        {
            bookID = bookShelf.size()+1;
            bookShelf.insert({bookID,kniga});
        }

    }
    load.close();
}


