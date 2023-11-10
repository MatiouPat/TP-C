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

Date calculateDateFromDuration(Date initialDate, int duration)
{
    Date finalDate;
    struct tm *local = {0};

    local->tm_year = initialDate.year -1900;
    local->tm_mon = initialDate.month - 1;
    local->tm_mday = initialDate.day;

    local->tm_mday += duration;

    mktime(&local);
    asctime(&local);
    localtime(&local);

    finalDate.day = local->tm_mday;
    finalDate.month = local->tm_mon + 1;
    finalDate.year = local->tm_year + 1900;

    return finalDate;
}

bool hasExpiredReturnDate(Date returnDate)
{
    Date currentDate = now();
    if(returnDate.year <= currentDate.year && returnDate.month <= currentDate.month && returnDate.day <= currentDate.day)
    {
        return true;
    }
    else
    {
        return false;
    }
}


