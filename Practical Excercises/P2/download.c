/* This code is part of Worksheet 2 (for UCP 120). */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  /* <-- Actually part of UNIX rather than C; needed for the sleep() function. */

#include "download_stats.h"

#define MIN_DOWNLOAD_SIZE 0
#define MAX_DOWNLOAD_SIZE 1000000
#define MIN_DOWNLOAD_RATE 50000
#define MAX_DOWNLOAD_RATE 100000

int main(void)
{
    int currentTime, startTime;
    double bytes, totalBytes;

    srand(time(NULL));
    startTime = rand();
    totalBytes = (double)(MIN_DOWNLOAD_SIZE + rand() % (MAX_DOWNLOAD_SIZE - MIN_DOWNLOAD_SIZE));

    printf("startTime == %d, totalBytes == %.2f\n(Press Ctrl-C to exit)\n", startTime, totalBytes);

    currentTime = startTime;
    bytes = 0;
    do
    {
        sleep(1);
        bytes += MIN_DOWNLOAD_RATE + rand() % (MAX_DOWNLOAD_RATE - MIN_DOWNLOAD_RATE);
        if(bytes > totalBytes)
        {
            bytes = totalBytes;
        }
        currentTime++;

        printf("\ntime == %d, bytes == %.2f\n-------------------\n", currentTime, bytes);

        #ifdef ALL_STATS
        printf("ELAPSED_TIME: %d seconds\n", elapsedTime(currentTime, startTime));
        printf("PERCENT_COMPLETE: %.2f%%\n", percentComplete(bytes, totalBytes));
        printf("DOWNLOAD_SPEED: %.2f bytes/second\n", downloadSpeed(currentTime, startTime, bytes));
        printf("TOTAL_TIME: %.2f seconds\n", totalTime(currentTime, startTime, bytes, totalBytes));
	    #endif
        printf("REMAINING_TIME: %.2f seconds\n", remainingTime(currentTime, startTime, bytes, totalBytes));
    }
    while(bytes < totalBytes);

    return 0;
}
