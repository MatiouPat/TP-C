#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include "Book.h"
#include "Date.h"

typedef struct Library
{
    Book *books;
    int nbBooks;
    Book (*searchBook)()

} Library;


void addBook(Library *, Book);
Book getBook(Library *, char * title);
void deleteBook(Library *);
void printBooks();
Book searchBook();
int searchBookByExactTitle(Library *, char[]);
void borrowBook(Library *);
void freeLib(Library *);
void editBookFromLibrary(Library *);
#endif // LIBRARY_H_INCLUDED
