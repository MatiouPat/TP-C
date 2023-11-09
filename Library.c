#include "Library.h"
#include "Book.h"

/**
* Create a book in the library by querying
*/
//void createBook(Book *books, int *size)
void createBook(Library * lib)
{
    //Memory allocation
    lib->nbBooks++;
    lib->books = (Book*)realloc(lib->books, lib->nbBooks * sizeof(Book));

    //Book creation
    printf("Quel est le titre du livre ? \n");
    scanf(" %[^\n]", lib->books[lib->nbBooks-1].title);
    printf("Quel est l'auteur du livre ? \n");
    scanf(" %[^\n]", lib->books[lib->nbBooks-1].author);
}

/**
* Remove a book by its title
*/
void deleteBook(Library * lib)
{
    char titleToDelete[100];
    int indexToDelete = -1;

    printf("Quel titre voulez-vous supprimer ? \n\r");
    scanf(" %[^\n]", &titleToDelete);

    //Search by title
    int i = 0;

    printf("test\n");

    while((i < (lib->nbBooks - 1)) && (indexToDelete == -1))
    {
        if(strcmp(titleToDelete, lib->books[i].title) == 0)
        {
            indexToDelete = i;
        }
        i++;
    }


    //Delete book if title is found
    if(indexToDelete != -1)
    {
        for(int i = indexToDelete ; i < (lib->nbBooks - 1) ; i++)
        {
            lib->books[i] = lib->books[i+1];
        }
        lib->nbBooks--;
        lib->books = (Book*)realloc(lib->books, lib->nbBooks * sizeof(Book));
    }
}

