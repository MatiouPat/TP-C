#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include "Book.h"
#include "Date.h"

typedef struct Library
{
    Book *books;
    int nbBooks;
    int nbBookAdded;
    Book (*searchBook)()

} Library;


void addBook(Library *, Book *);
void deleteBook(Library *);
void printBooks(Book*, int);
void borrowBook(Library *);
void returnBook(Library *);
int searchBookByExactTitle(Library *, char[]);
void searchBookByApproximateTitle(Library *, char[]);
void editBookFromLibrary(Library *);
void searchBookByAuthor(Library *, char[]);
void searchBookByPublishYear(Library *, int);
void printStats(Library *);
void freeLib(Library *);
int getNumberOfLateReturns(Library *);
void searchBookInLateReturn(Library *);

#endif // LIBRARY_H_INCLUDED
