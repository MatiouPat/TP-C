#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include "Book.h"

typedef struct Library
{
    Book * books = NULL;
    Book (*searchBook)()

} Library;


Book addBook(Book book);
Book getBook(char * title);
Book removeBook(char * title);
void printBooks();
Book searchBook();

#endif // LIBRARY_H_INCLUDED
