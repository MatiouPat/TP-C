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
    struct tm initiaDateTm = {0};
    time_t initialTimestamp;
    struct tm durationTm = {0};
    time_t durationTimestamp;
    time_t finalTimestamp;
    struct tm *finalDateTm;

    initiaDateTm.tm_year = initialDate.year -1900;
    initiaDateTm.tm_mon = initialDate.month - 1;
    initiaDateTm.tm_mday = initialDate.day;

    initiaDateTm.tm_mday += duration;

    mktime(&initiaDateTm);
    asctime(&initiaDateTm);
    localtime(&initiaDateTm);

    finalDate.day = initiaDateTm.tm_mday;
    finalDate.month = initiaDateTm.tm_mon + 1;
    finalDate.year = initiaDateTm.tm_year + 1900;

    return finalDate;
}
