#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <time.h>
#include <stdbool.h>

typedef struct Book
{
    char title[100];
    char author[100];
    int publishDate;
    bool isBorrowed;
    time_t borrowingDate;
    time_t returnDate;
}Book;


Book createBook();

#endif // BOOK_H_INCLUDED
