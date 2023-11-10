
#include "Book.h"

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
* Checks that the first book passed as a parameter is sorted alphabetically compared to the second
* @returns 0: book1.title = book1.title
* @returns 1: book1.title < book2.title (sorted)
* @returns 2: book1.title > book2.title (not sorted)
*/
int isAlphabeticallySorted(Book * b1, Book * b2)
{
    int i = 0;
    char letterB1, letterB2;

    // We compare letter to letter and return in case one is greater than other
    while ((b1->title[i] != '\0') && (b2->title[i] != '\0'))
    {
        letterB1 = tolower(b1->title[i]);
        letterB2 = tolower(b2->title[i]);

        if (letterB1 < letterB2)
        {
            return 1;
        }
        else if (letterB1 > letterB2)
        {
            printf("tic");
            return 2;
        }

        i++;
    }

    // If one or both of the string are finished
    // we check their length
    if ((b1->title[i] == '\0') && (b2->title[i] == '\0'))
    {
        return 0;
    }
    else if (b1->title[i] == '\0')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
