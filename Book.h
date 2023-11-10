#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <stdbool.h>
#include "Date.h"

typedef struct Book
{
    char title[100];
    char author[100];
    int publishYear;
    bool isBorrowed;
    Date borrowingDate;
    Date returnDate;
}Book;


Book createBook();
Book * editBook(Book *);
void printBook();

#endif // BOOK_H_INCLUDED
