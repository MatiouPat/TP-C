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


void createBook(Library *);
Book getBook(Library *, char * title);
void deleteBook(Library *);
void printBooks();
Book searchBook();
void borrowBook(Library *);

#endif // LIBRARY_H_INCLUDED
