#include <stdio.h>
#include <stdlib.h>
#include "Library.h"
#include "Book.h"
#include "Date.h"

/**
* Create 50 Book and add them to the Library in parameters
* @params lib : the Library where to add the books
*/
int initialization(Library * lib)
{
    printf("Creation de donnees factices...");

    srand(time(NULL));

    char title [100];           // book title (ex: A1)
    char author [100];          // author (ex: AA)
    int publishDate;            // publish date 2000 -> 2020

    lib->books = (Book*)malloc(50 * sizeof(Book));
    printf("nb book %d\n", lib->nbBooks);

    if(lib->books == NULL)
    {
        // desallouer les variables
        // quitter le programme
        return 1;
    }

    for (int i = 0 ; i < 50 ; i++)
    {
        // Random book title
        title[0] = (char)(rand()%26+'A');
        title[1] = (rand()%10 + '0');
        title[2] = '\0';

        // Random author name
        author[0] = (char)(rand()%26+'A');
        author[1] = (char)(rand()%26+'A');
        author[2] = '\0';

        // Random publish date between 2000 and 2020
        publishDate = 2000+rand()%21;

        // We create the book
        Book b;
        strcpy(b.title, title);
        strcpy(b.author, author);
        //b.publishDate = publishDate;
        b.isBorrowed = false;

        printf("%s ", b.title);
        printf("%s, ", b.author);

        // We add the book to the library
        lib->nbBooks++;

        lib->books[i] = b;
        printf("%s ajoutez index %d.\n", lib->books[i].title, i);
        printf("nb book boucle %d\n", lib->nbBooks);

    }
    return 0;
}


int main()
{
    Book *books;
    Library lib = {books, 0};
    printf("%d", lib.nbBooks);

    if (initialization(&lib)) {
        return 1;
    }


    //createBook(&lib);
    //createBook(&lib);
    printBooks(&lib);
    borrowBook(&lib);

    //deleteBook(&lib);
    /*for(int i = 0; i < lib.nbBooks; i++)
    {
        printf("%i:", i);
        printf("Nom ");
        printf("%s", lib.books[i].title);
    }*/

    //deleteBook(&lib);
    addBook(&lib);

    printBooks(&lib);

    printf("free");
    freeLib(&lib);

    return 0;
}
