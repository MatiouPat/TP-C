
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
    scanf("%d/%d/%d", &b.publishDate.day, &b.publishDate.month, &b.publishDate.year);

    return b;
}


/**
* Checks that the first book passed as a parameter is sorted alphabetically compared to the second
*/
bool isAlphabeticallySorted(Book * b1, Book * b2)
{
    int i = 0;
    int lenBook1 = 0;
    printf("%c\n", b1->title[0]);

    while (b1->title[i] != '\0')
    {
        printf("%s\n", (b1->title[i] == '\0')?"true":"false");
        printf("%c\n",b1->title[i]);
        lenBook1;
    }

    printf("%d\n", lenBook1);

}
