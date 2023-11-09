#include <stdio.h>
#include <stdlib.h>
#include "Library.h"
#include "Book.h"

/**
* Cree 50 Book et les ajoute a la Library passee en parametre
* @params lib
*/
void initialization(Library * lib)
{
    srand(time(NULL));

    char title [100];     // titre du livre (ex : A1)
    char author [100];    // auteur (ex : AA)
    int publishDate;    // date de publication 2000 -> 2020

    //lib->books = (Book *)realloc(lib->nbBooks, lib->nbBooks * sizeof(Book));


    for (int i = 0 ; i < 50 ; i++)
    {
        title[0] = (char)(rand()%26+'A');
        title[1] = (rand()%10 + '0');

        author[0] = (char)(rand()%26+'A');
        author[1] = (char)(rand()%26+'A');

        publishDate = 2000+rand()%21;

        printf("%s\n", title);


        Book b;
        strcpy(b.title, title);
        strcpy(b.title, author);
        b.publishDate = publishDate;
        b.isBorrowed = false;

        Book b1 = {"title", "author", 2020, false};
        printf("%s \n", b.title);
        printf("%s \n", b1.title);
        lib->nbBooks++;
        lib->books = (Book *)realloc(lib->books, lib->nbBooks * sizeof(Book));
        lib->books[lib->nbBooks-1] = b;
        printf("%s \n", lib->books[lib->nbBooks-1].title);

    }
}


int main()
{
    Book *books = (Book*)malloc(0 * sizeof(Book));
    Library lib = {books, 0};

    initialization(&lib);

    printf(" test %s \n", lib.books[5].title);

    if(books == NULL)
    {
        return 1;
    }
    else
    {
        //createBook(&lib);
        //createBook(&lib);

        for(int i = 0; i < lib.nbBooks; i++)
        {
            printf("%i:", i);
            printf("Nom ");
            printf("%s \n", lib.books[i].title);
        }
        deleteBook(&lib);
        /*for(int i = 0; i < lib.nbBooks; i++)
        {
            printf("%i:", i);
            printf("Nom ");
            printf("%s", lib.books[i].title);
        }*/
    }
    return 0;
}
