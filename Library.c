#include "Library.h"
#include "Book.h"

/**
* Create a book in the library by querying
*/
void addBook(Library * lib, Book b)
{
    //Memory allocation
    lib->nbBooks++;
    lib->books = (Book*)realloc(lib->books, lib->nbBooks * sizeof(Book));

    lib->books[lib->nbBooks-1] = b;

    printf("\n Livre %s ajoute !\n", b.title);
}

/**
* Remove a book by its title
*/
void deleteBook(Library * lib)
{
    char titleToDelete[100];

    printf("Quel titre voulez-vous supprimer ? \n\r");
    scanf(" %[^\n]", &titleToDelete);

    int indexToDelete = searchBookByExactTitle(lib, titleToDelete);

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
        printf("\tDate de publication : %d\n", lib->books[i].publishDate.year);

        printf("\tDisponible : %s\n", lib->books[i].isBorrowed?"Non":"Oui");

        printf("\n");

    }
}

/**
* Borrow a book with a specific return date
*/
void borrowBook(Library * lib)
{
    char titleToBorrow[100];

    printf("Quel livre voulez-vous emprunter ? \n\r");
    scanf(" %[^\n]", &titleToBorrow);

    int indexToBorrow = searchBookByExactTitle(lib, titleToBorrow);

    if(indexToBorrow != -1)
    {
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
}

/**
* Search for a book, only those with exactly the same title will appear
*/
int searchBookByExactTitle(Library * lib, char titleBook[100])
{
    int foundBookIndex = -1;
    //Search by title
    int i = 0;
    while((i < (lib->nbBooks - 1)) && (foundBookIndex == -1))
    {
        if(strcmp(titleBook, lib->books[i].title) == 0)
        {
            foundBookIndex = i;
        }
        i++;
    }
    return foundBookIndex;
}

/**
* Search for a book, all books with the search sub-chain in the title will appear.
*/
void searchBookByApproximateTitle(Library * lib, char titleBook[100])
{
    int nbFound = 0;
    Book *findBooks = (Book*)malloc(nbFound * sizeof(Book));

    if(findBooks == NULL)
    {
        /**/
    }
    else
    {
        //Search by title
        for(int i = 0; i < (lib->nbBooks - 1); i++)
        {
            if(strstr(lib->books[i].title, titleBook) != NULL)
            {
                nbFound++;
                findBooks = (Book*)realloc(findBooks, nbFound * sizeof(Book));
                findBooks[nbFound-1] = lib->books[i];
            }
        }
        for(int i = 0 ; i < nbFound ; i++)
        {
            printf("-%d-\n", i);
            printf("\tNom : %s \n", findBooks[i].title);
            printf("\tAuteur : %s\n", findBooks[i].author);
            printf("\tDate de publication : %d/%d/%d\n", findBooks[i].publishDate.day, findBooks[i].publishDate.month, findBooks[i].publishDate.year);

            printf("\tDisponible : %s\n", findBooks[i].isBorrowed?"Non":"Oui");

            printf("\n");

        }
        free(findBooks);
    }
}

/**
* Free all memory from attributes
*/
void freeLib(Library * lib)
{
    free(lib->books);
}
