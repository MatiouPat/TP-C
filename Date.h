#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <time.h>

typedef struct Date
{
    int day;
    int month;
    int year;
}Date;

Date now();
Date calculateDateFromDuration(Date, int);

#endif // DATE_H_INCLUDED
