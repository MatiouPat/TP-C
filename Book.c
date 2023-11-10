
#include "Book.h"

/**
* Print a book in the console
*/
void printBook(Book * book)
{
        printf("\tNom : %s \n", book->title);
        printf("\tAuteur : %s\n", book->author);
        printf("\tDate de publication : %d\n", book->publishYear);
        printf("\tDisponible : %s\n", book->isBorrowed?"Non":"Oui");
        if (book->isBorrowed)
        {
            printf("\tDate d'emprunt : %d/%d/%d", book->borrowingDate.day, book->borrowingDate.month, book->borrowingDate.year);
            printf("\tDate de retour : %d/%d/%d", book->returnDate.day, book->returnDate.month, book->returnDate.year);

        }
}

/**
* Create a new book by querying the user
*/
Book createBook()
{
    //Book creation
    printf("\nCreation d'un nouveau livre\n");
    Book b;

    printf("\tQuel est le titre du livre ? ");
    scanf(" %[^\n]", b.title);

    printf("\tQuel est l'auteur du livre ? ");
    scanf(" %[^\n]", b.author);

    int date = 0;

    while ( (date < 2000) || (date > 2020))
    {
        printf("\tA quelle date a-t-il ete publie ? (entre 2000 et 2020) ");
        scanf("%d", &date);
    }

    b.publishYear = date;

    b.isBorrowed = false;

    return b;
}


/**
* Edit an existing book by querying the user
*/
Book * editBook(Book * book)
{

    printf("\nVous avez choisi de modifier le livre suivant,\n");
    printf("\tTitre : %s \n", book->title);
    printf("\tAuteur : %s\n", book->author);
    printf("\tDate de publication : %d\n", book->publishYear);

    printf("\nQuel information voulez vous modifier ?\n");
    int actionChoice;
    printf("\t1) Le titre du livre \n \t2) L'auteur \n \t3) La date de publication \n \t0) Annuler \n");
    scanf("%d", &actionChoice);

    switch(actionChoice)
    {
        case 0:
            return &book;
        case 1:;
            char newTitle [100];
            printf("Nouveau titre  : ");
            scanf(" %[^\n]", newTitle);
            strcpy(book->title, newTitle);
            break;
        case 2:;
            char newAuthor[100];
            printf("Nouvel auteur  : ");
            scanf(" %[^\n]", newAuthor);
            strcpy(book->author, newAuthor);
            break;
        case 3:;
            char newPublishDate[20];
            printf("Nouvelle date de publication  : ");
            scanf(" %[^\n]", newPublishDate);
            book->publishYear = atoi(newPublishDate);
            break;
    }

    printf("\nLivre modifie avec succes !\n");
    printf("\nVoici les nouvelles informations du livre,\n");
    printf("\tTitre : %s \n", book->title);
    printf("\tAuteur : %s\n", book->author);
    printf("\tDate de publication : %d\n", book->publishYear);

    printf("\nAppuyer sur n'importe quelle touche pour continuer\n");
    getch();

    return &book;
}


