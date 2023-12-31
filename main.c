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

    if(lib->books == NULL)
    {
        // free the memory and exit the program
        freeLib(&lib);
        return 1;
    }

    int i = -1;
    while (lib->nbBooks < 50)
    {
        i++;
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
        b.publishYear = publishDate;
        b.isBorrowed = false;

        Book * ptrBook = &b;

        // We add the book to the library
        addBook(lib, ptrBook);


    }
    return 0;
}



int main()
{
    Book *books;
    Library lib = {books, 0, 0};
    Library * ptrLib = &lib;

    int actionChoice = 0;
    bool isExecute = true;

    if (initialization(ptrLib)) {
        return 1;
    }

    printf("\nAppuyer sur n'importe quelle touche pour continuer\n");
    getch();

    while(isExecute)
    {
        printf("\033c");
        int numberOfLateReturn = getNumberOfLateReturns(&lib);
        if(numberOfLateReturn > 0)
        {
            printf("\e[5m\e[31m/!\\ Attention ! %d livre(s) pas encore rendu !\e[0m \n\n", numberOfLateReturn);
        }

        /*


        */
        printf("\e[1m Que voulez-vous faire ? \e[0m \n 1) Voir tous les livres \n 2) Creer un livre \n 3) Supprimer un livre \n 4) Rechercher un livre... \n 5) Emprunter un livre \n 6) Rendre un livre \n 7) Modifier un livre \n 8) Voir les livres en retard de rendu \n 9) Afficher statistiques \n 0) Quitter l'application \n");
        scanf("%d", &actionChoice);
        switch(actionChoice)
        {
            case 0:
                isExecute = false;
                break;
            case 1:
                printf("\033c");
                printBooks(lib.books, lib.nbBooks);
                printf("Appuyer sur n'importe quelle touche pour continuer...\n");
                getch();
                break;
            case 2:
                printf("\033c");
                Book bookToAdd;
                Book * ptrBookToAdd = &bookToAdd;
                bookToAdd = createBook();
                addBook(&lib, ptrBookToAdd);
                break;
            case 3:
                printf("\033c");
                deleteBook(&lib);
                break;
            case 4:
                printf("\033c");
                int searchChoice = 0;
                char titleToSearch[100];
                char authorToSearch[100];
                int yearToSearch;
                printf("\e[1m Rechercher un livre... \e[0m \n 1) par titre \n 2) par auteur \n 3) par annee \n");
                scanf("%d", &searchChoice);
                switch(searchChoice)
                {
                    case 1:
                        printf("\033c");
                        printf("Quel titre de livre recherchez-vous ? \n");
                        scanf(" %[^\n]", &titleToSearch);
                        searchBookByApproximateTitle(&lib, titleToSearch);
                        printf("Appuyer sur n'importe quelle touche pour continuer\n");
                        getch();
                        break;
                    case 2:
                        printf("\033c");
                        printf("Quel auteur recherchez-vous ? \n");
                        scanf(" %[^\n]", &authorToSearch);
                        searchBookByAuthor(&lib, authorToSearch);
                        printf("Appuyer sur n'importe quelle touche pour continuer\n");
                        getch();
                        break;
                    case 3:
                        printf("\033c");
                        printf("Quel annee de publication recherchez-vous ? \n");
                        scanf("%d", &yearToSearch);
                        searchBookByPublishYear(&lib, yearToSearch);
                        printf("Appuyer sur n'importe quelle touche pour continuer\n");
                        getch();
                        break;
                    default:
                        break;
                }
                break;
            case 5:
                printf("\033c");
                borrowBook(&lib);
                break;
            case 6:
                printf("\033c");
                returnBook(&lib);
                break;
            case 7:
                printf("\033c");
                editBookFromLibrary(&lib);
                break;
            case 8:
                printf("\033c");
                searchBookInLateReturn(&lib);
                printf("Appuyer sur n'importe quelle touche pour continuer\n");
                getch();
            case 9:
                printf("\033c");
                printStats(&lib);
                break;
            default:
                break;
        }
    }

    printf("free");
    freeLib(&lib);

    return 0;
}
