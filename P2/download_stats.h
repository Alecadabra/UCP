/**********************************
*AUTHOR: Hugh Flanigan
*DATE: 07/08/2019
*LAST EDITED: 07/08/2019
*PURPOSE: Stubbed funcitonality for UCP Practical 2 for students to work with
**********************************/
#ifndef DOWNLOAD_STATS_H
#define DOWNLOAD_STATS_H

int elapsedTime(int currentTime, int startTime);

double percentComplete(double bytes, double totalBytes);

double downloadSpeed(int currentTime, int startTime, double bytes);

double totalTime(int currentTime, int startTime, double bytes, double totalBytes);

double remainingTime(int currentTime, int startTime, double bytes, double totalBytes);

#endif