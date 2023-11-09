#include "Book.h"

/**
* Create a book in the library by querying
*/
void createBook(Book *books, int *size)
{
    //Memory allocation
    *size = *size+1;
    printf("%d", *size);
    books = (Book*)realloc(books, (*size) * sizeof(Book));

    //Book creation
    printf("Quel est le titre du livre ? \n");
    scanf(" %[^\n]", books[*size-1].title);
    printf("Quel est l'auteur du livre ? \n");
    scanf(" %[^\n]", books[*size-1].author);
}

/**
* Remove a book by its title
*/
void deleteBook(Book *books, int *size)
{
    char titleToDelete[100];
    int indexToDelete = -1;

    printf("Quel titre voulez-vous supprimer ? \n\r");
    scanf(" %[^\n]", &titleToDelete);

    //Search by title
    int i = 0;
    while(i < *size-1 && indexToDelete == -1)
    {
        if(strcmp(titleToDelete, books[i].title) == 0)
        {
            indexToDelete = i;
        }
        i++;
    }

    //Delete book if title is found
    if(indexToDelete != 1)
    {
        for(int i = indexToDelete; i < *size-1; i++)
        {
            books[i] = books[i+1];
        }
        *size = *size-1;
        books = (Book*)realloc(books, (*size) * sizeof(Book));
    }
}

