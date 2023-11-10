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
/*
#include <windows.h>
void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,f*16+t);
}*/

/**
* Print all the books of the library in the console
*/
void printBooks(Library * lib)
{
   for(int i = 0 ; i < lib->nbBooks ; i++)
    {
        //printf("\n");
        /*color(15, 0);
        color(3, 3);
        printf("a");
        color(15, 0);
        printf("-%i-", i+1);
        color(3, 3);
        printf("a");
        color(15, 0);*/

        //printf("- %d - \n", i+1);
        printf("-%d-\n", i);
        printf("\tNom : %s \n", lib->books[i].title);
        printf("\tAuteur : %s\n", lib->books[i].author);
        printf("\tDate de publication : %d\n", lib->books[i].publishDate);

        printf("\tDisponible : %s\n", lib->books[i].isBorrowed?"Non":"Oui");

        printf("\n");

    }
}

/**
* Borrow a book with a specific return date
*/
void borrowBook(Library * lib)
{
    int indexToBorrow = -1;

    printf("Quel livre voulez-vous emprunter ? \n\r");
    scanf("%d", &indexToBorrow);

    lib->books[indexToBorrow].isBorrowed = true;
    lib->books[indexToBorrow].borrowingDate = now();

    int day;
    int month;
    int year;
    printf("Quand rendez-vous le livre ? (ex : 10/11/2023) \n\r");
    scanf("%d/%d/%d", &day, &month, &year);

    Date returnDate = {day, month, year};
    lib->books[indexToBorrow].returnDate = returnDate;
}


