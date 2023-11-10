#include "Date.h"

Date now()
{
    Date todayDateFormatted;
    time_t todayDate;

    time(&todayDate);
    ctime(&todayDate);

    struct tm *local = localtime(&todayDate);
    todayDateFormatted.day = local->tm_mday;
    todayDateFormatted.month = local->tm_mon + 1;
    todayDateFormatted.year = local->tm_year + 1900;

    return todayDateFormatted;
}
