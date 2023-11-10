
#include "Book.h"

/**
* Print a book in the console
*/
void printBook(Book * book)
{
        printf("\tNom : %s \n", book->title);
        printf("\tAuteur : %s\n", book->author);
        printf("\tDate de publication : %d\n", book->publishDate.year);
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

    printf("\tA quelle date a-t-il ete publie ? ");
    scanf("%d", &b.publishDate.year);

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
    printf("\tDate de publication : %d\n", book->publishDate.year);

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
            book->publishDate.year = atoi(newPublishDate);
            break;
    }

    printf("\nLivre modifie avec succes !\n");
    printf("\nVoici les nouvelles informations du livre,\n");
    printf("\tTitre : %s \n", book->title);
    printf("\tAuteur : %s\n", book->author);
    printf("\tDate de publication : %d\n", book->publishDate.year);

    printf("\nAppuyer sur n'importe quelle touche pour continuer\n");
    getch();

    return &book;
}


/**
* Checks that the first book passed as a parameter is sorted alphabetically compared to the second
* @returns 0: book1.title = book1.title
* @returns 1: book1.title < book2.title (sorted)
* @returns 2: book1.title > book2.title (not sorted)
*/
int isAlphabeticallySorted(char * title1, char * title2)
{
    int i = 0;
    char letterB1, letterB2;

    // We compare letter to letter and return in case one is greater than other
    //while ((b1->title[i] != '\0') && (b2->title[i] != '\0'))
    while ((title1[i] != '\0') && (title2[i] != '\0'))
    {

        //printf("%c - ", b1->title[i]);
        //printf("%c\n", b2->title[i]);

        letterB1 = tolower(title1[i]);
        //letterB1 = tolower(b1->title[i]);
        letterB2 = tolower(title2[i]);
        //letterB2 = tolower(b2->title[i]);

        printf("%c - ", letterB1);
        printf("%c\n", letterB2);

        if (letterB1 < letterB2)
        {
            printf("%c > %c", letterB1, letterB2);
            return 1;
        }
        else if (letterB1 > letterB2)
        {
            return 2;
        }

        i++;
    }

    // If one or both of the string are finished
    // we check their length
    //if ((b1->title[i] == '\0') && (b2->title[i] == '\0'))
    if ((title1[i] == '\0') && (title2[i] == '\0'))
    {
        return 0;
    }
    //else if (b1->title[i] == '\0')
    else if (title1[i] == '\0')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
