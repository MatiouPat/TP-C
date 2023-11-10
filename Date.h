#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <stdbool.h>
#include <time.h>

typedef struct Date
{
    int day;
    int month;
    int year;
}Date;

Date now();
Date calculateDateFromDuration(Date, int);
bool hasExpiredReturnDate(Date);

#endif // DATE_H_INCLUDED
