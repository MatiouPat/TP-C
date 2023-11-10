
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
