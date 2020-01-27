/**********************************
*AUTHOR: Hugh Flanigan
*DATE: 07/08/2019
*LAST EDITED: 07/08/2019
*PURPOSE: Stubbed funcitonality for UCP Practical 2 for students to work with
**********************************/
#include "download_stats.h"
#include "download.h"

int elapsedTime(int currentTime, int startTime)
{
    return ELAPSED_TIME(currentTime, startTime);
}

double percentComplete(double bytes, double totalBytes)
{
    return PERCENT_COMPLETE(bytes, totalBytes);
}

double downloadSpeed(int currentTime, int startTime, double bytes)
{
    return DOWNLOAD_SPEED(currentTime, startTime, bytes);
}

double totalTime(int currentTime, int startTime, double bytes, double totalBytes)
{
    return TOTAL_TIME(currentTime, startTime, bytes, totalBytes);
}

double remainingTime(int currentTime, int startTime, double bytes, double totalBytes)
{
    return REMAINING_TIME(currentTime, startTime, bytes, totalBytes);
}