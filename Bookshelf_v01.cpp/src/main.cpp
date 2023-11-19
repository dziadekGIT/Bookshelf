#include <iostream>
#include "Menu.h"
#include <unordered_map>
#include <utility>

using namespace std;

class Book
{
public:

    string bookTitle;
    string bookAuthor;
    int bookYear;

    Book(string T, string A, int Y) : bookTitle(std::move(T)),
                                      bookAuthor(std::move(A)),
                                      bookYear(Y) {}

};

class LibraryManagement
{
private:
    unordered_map<int, Book> bookShelf;

public:
    void addBook(int bookID, Book book)
    {

        bookShelf.insert({bookID,book});
    }



    void printBook()
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
        for (const auto& pair : bookShelf) {
            cout << "Book ID: " << pair.first << endl;
            cout << "Title: " << pair.second.bookTitle << endl;
            cout << "Author: " << pair.second.bookAuthor << endl;
            cout << "Year: " << pair.second.bookYear << endl;
            cout << "------------------------" << endl;
        }
    }
};




int main()
{

    LibraryManagement library;
    Book kniga("Wiedzmin","Andrzej Sapkowski", 1970);
    Book kniga2("Rok 1984", "Orwell", 1950);

    library.addBook(1,kniga);
    library.addBook(5,kniga2);



   library.printBook();
   // Menu::menu();

   return 0;
}
