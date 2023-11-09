#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include "Book.h"

typedef struct Library
{
    Book *books;
    Book (*searchBook)()

} Library;


void createBook(Book*, int*);
Book getBook(char * title);
void deleteBook(Book*, int*);
void printBooks();
Book searchBook();

#endif // LIBRARY_H_INCLUDED
