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
    printf("Creation de donnees factices...\n\n");

    srand(time(NULL));

    char title [100];           // book title (ex: A1)
    char author [100];          // author (ex: AA)
    int publishDate;            // publish date 2000 -> 2020

    lib->books = (Book*)malloc(50 * sizeof(Book));
    if(lib->books == NULL)
    {
        // desalloue la library et quitte le programme
        freeLib(&lib);
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
        b.publishDate = (Date){0, 0, publishDate};
        b.isBorrowed = false;

        // We add the book to the library
        lib->nbBooks++;
        lib->books[i] = b;
        printf("Ajout du livre %s.\n", lib->books[i].title);

    }
    return 0;
}


int main()
{
    Book *books;
    Book newBook;
    Library lib = {books, 0};
    int actionChoice = 0;
    bool isExecute = true;

    if (initialization(&lib)) {
        return 1;
    }


    while(isExecute)
    {
        printf("\033c");
        printf("Que voulez-vous faire ? \n 1) Voir tous les livres \n 2) Creer un livre \n 3) Supprimer un livre \n 4) Rechercher par titre \n 5) Emprunter un livre \n 6) Rendre un livre \n 0) Quitter l'application \n");
        scanf("%d", &actionChoice);
        switch(actionChoice)
        {
            case 0:
                isExecute = false;
                break;
            case 1:
                printf("\033c");
                printBooks(&lib);
                printf("Appuyer sur n'importe quel touche pour continuer...\n");
                getch();
                break;
            case 2:
                printf("\033c");
                newBook = createBook();
                addBook(&lib, newBook);
                break;
            case 3:
                printf("\033c");
                deleteBook(&lib);
                break;
            case 4:
                printf("\033c");
                char titleToSearch[100];
                printf("Quel livre recherchez-vous ? \n");
                scanf(" %[^\n]", &titleToSearch);
                searchBookByApproximateTitle(&lib, titleToSearch);
                printf("Appuyer sur n'importe quel touche pour continuer\n");
                getch();
            case 5:
                printf("\033c");
                borrowBook(&lib);
                break;
            case 6:
                printf("\033c");
                returnBook(&lib);
                break;
            default:
                break;
        }
    }

    printf("free");
    freeLib(&lib);

    return 0;
}
