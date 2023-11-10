#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <stdbool.h>
#include "Date.h"

typedef struct Book
{
    char title[100];
    char author[100];
    Date publishDate;
    bool isBorrowed;
    Date borrowingDate;
    Date returnDate;
}Book;


Book createBook();
int isAlphabeticalSorted(Book*, Book*);

#endif // BOOK_H_INCLUDED
