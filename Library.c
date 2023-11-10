#include "Library.h"
#include "Book.h"

/**
* Create a book in the library by querying
*/
void addBook(Library * lib, Book * b)
{
    //Memory allocation
    lib->nbBooks++;
    if (lib->nbBooks == 1)
    {
        lib->books = (Book*)malloc(1 * sizeof(Book));
        lib->books[0] = (Book)*b;
        return;
    }
    else
    {
        lib->books = (Book*)realloc(lib->books, lib->nbBooks * sizeof(Book));
    }

    for (int i = 0 ; i < (lib->nbBooks - 1) ; i++)
    {
            printf("livre 1 %s", b->title);
            printf(" livre 2 %s\n", lib->books[i].title);
            int isSorted = isAlphabeticallySorted(b->title, lib->books[i].title);
        if (isSorted == 1)
        {
            printf("On ajoute le livre %s position %d", b->title, i);
            printf(" a la place de %s\n", lib->books[i].title);

            for (int j = (lib->nbBooks - 1) ; j > i; j--)
            {
                lib->books[j] = lib->books[j-1];
            }
            lib->books[i] = (Book)*b;

            break;
        }
        else if (isSorted == 0)
        {
            printf("\nImpossible d'ajouter plusieurs livre avec le meme nom !\n");
            lib->nbBooks--;
            lib->books = (Book*)realloc(lib->books, lib->nbBooks * sizeof(Book));

            return;
        }
    }
    lib->books[lib->nbBooks-1] = (Book)*b;
    //printf("\n Livre %s ajoute !\n", lib);
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
        if (lib->nbBooks == 0)
        {
            freeLib(&lib);
        }
        else
        {
            lib->books = (Book*)realloc(lib->books, lib->nbBooks * sizeof(Book));
        }
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
        printf("\t\e[1m Date de publication : \e[0m %d\n", books[i].publishYear);

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
    int returnChoice;

    printf("Quel livre voulez-vous emprunter ? \n\r");
    scanf(" %[^\n]", &titleToBorrow);

    int indexToBorrow = searchBookByExactTitle(lib, titleToBorrow);

    if(indexToBorrow != -1)
    {
        Date initalDate = now();
        int day;
        int month;
        int year;
        int duration;

        lib->books[indexToBorrow].isBorrowed = true;
        lib->books[indexToBorrow].borrowingDate = initalDate;

        printf("Quand rendez-vous le livre ? \n 1) Sur une date precise \n 2) Sur une duree \n ");
        scanf("%i", &returnChoice);

        if(returnChoice == 1)
        {
            printf("A quelle date rendez-vous le livre ? (ex : 10/11/2023) \n\r");
            scanf("%d/%d/%d", &day, &month, &year);

            Date returnDate = {day, month, year};
            lib->books[indexToBorrow].returnDate = returnDate;
        }
        else
        {
            printf("Dans combien de temps rendez-vous le livre ? (en jour) \n\r");
            scanf("%d", &duration);

            Date returnDate = calculateDateFromDuration(initalDate, duration);
            lib->books[indexToBorrow].returnDate = returnDate;
        }
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


void editBookFromLibrary(Library * lib)
{
    // verifier que le livre existe dans la lib
    printf("Entrer le titre du livre a modifier : ");
    char title [100];
    scanf("%s", title);
    getchar();

    int indexes [lib->nbBooks];
    int nbIndexes = 0; // nb of found books

    for (int i = 0 ; i < lib->nbBooks ; i++)
    {
        if(strcmp(title, lib->books[i].title) == 0)
        {
            indexes[nbIndexes] = i;
            nbIndexes++;
            // On peut s'arreter ici si on est sur qu'il n'y a qu'un livre avec ce nom
        }

    }

    int indexBookToEdit;

    if (nbIndexes == 0)
    {
        printf("\nLe livre n'a pas ete trouve :(\n");
        printf("\nAppuyer sur n'importe quel touche pour continuer\n");
        getch();
        return;
    }
    else if (nbIndexes > 1)
    {
        printf("\nPlusieurs livres avec le meme nom ont ete trouves, lequel voulez vous modifier ?\n");
        for (int i = 0 ; i < nbIndexes ; i++)
        {
            printf("%d)\n", indexes[i]+1);
            printBook(lib->books[indexes[i]]);
        }

        scanf("%d", &indexBookToEdit);
        indexBookToEdit--;
    }
    else
    {
        indexBookToEdit = indexes[0];
    }

    Book * ptrBookToEdit;
    ptrBookToEdit = &(lib->books[indexBookToEdit]);
    editBook(ptrBookToEdit);

}

/**
    for (int i = 0 ; i < (lib->nbBooks - 1) ; i++)
    {
        for (int j = 1 ; j < lib->nbBooks ; j++)
        {

            if (isAlphabeticallySorted(lib->books[i]) == 1)
        }

        if (isAlphabeticallySorted)
    }
*/

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
            if(lib->books[i].publishYear == publishYear)
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

int getNumberOfLateReturns(Library * lib)
{
    int numberOfLateReturns = 0;
    for(int i = 0; i < lib->nbBooks; i++)
    {
        if(lib->books[i].isBorrowed && hasExpiredReturnDate(lib->books[i].returnDate))
        {
            numberOfLateReturns++;
        }
    }
    return numberOfLateReturns;
}

void searchBookInLateReturn(Library * lib)
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
        for(int i = 0; i < lib->nbBooks; i++)
        {
            if(lib->books[i].isBorrowed && hasExpiredReturnDate(lib->books[i].returnDate))
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
