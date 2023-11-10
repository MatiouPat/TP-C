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


    for (int i = 0 ; i < lib->nbBooks ; i++)
    {
        if(strcmp(b.title, lib->books[i].title) == 0)
        {

        }
    }
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
void printBooks(Book* books, int size)
{
   for(int i = 0 ; i < size ; i++)
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
        printf("-%d-\n", i+1);
        printf("\t\e[1m Nom : \e[0m %s \n", books[i].title);
        printf("\t\e[1m Auteur : \e[0m %s\n", books[i].author);
        printf("\t\e[1m Date de publication : \e[0m %d\n", books[i].publishDate.year);

        printf("\t\e[1m Disponible : \e[0m %s\n", books[i].isBorrowed?"\e[31m Non \e[0m":"\e[32m Oui \e[0m");

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
* Return a book with a specific return date
*/
void returnBook(Library * lib)
{
    char titleToReturn[100];

    printf("Quel livre voulez-vous rendre ? \n\r");
    scanf(" %[^\n]", &titleToReturn);

    int indexToReturn = searchBookByExactTitle(lib, titleToReturn);
    if(indexToReturn != -1)
    {
        lib->books[indexToReturn].isBorrowed = false;
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
    while((i < (lib->nbBooks)) && (foundBookIndex == -1))
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
        for(int i = 0; i < (lib->nbBooks); i++)
        {
            if(strstr(lib->books[i].title, titleBook) != NULL)
            {
                nbFound++;
                findBooks = (Book*)realloc(findBooks, nbFound * sizeof(Book));
                findBooks[nbFound-1] = lib->books[i];
            }
        }
        printBooks(findBooks, nbFound);
        free(findBooks);
    }
}

/**
* Search for a book, all books with the search sub-chain in the author will appear.
*/
void searchBookByAuthor(Library * lib, char author[100])
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
        for(int i = 0; i < (lib->nbBooks); i++)
        {
            if(strstr(lib->books[i].author, author) != NULL)
            {
                nbFound++;
                findBooks = (Book*)realloc(findBooks, nbFound * sizeof(Book));
                findBooks[nbFound-1] = lib->books[i];
            }
        }
        printBooks(findBooks, nbFound);
        free(findBooks);
    }
}

/**
* Search for a book, only books with year of publication will appear.
*/
void searchBookByPublishYear(Library * lib, int publishYear)
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
            if(lib->books[i].publishDate.year == publishYear)
            {
                nbFound++;
                findBooks = (Book*)realloc(findBooks, nbFound * sizeof(Book));
                findBooks[nbFound-1] = lib->books[i];
            }
        }
        printBooks(findBooks, nbFound);
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
