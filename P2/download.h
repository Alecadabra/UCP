#define ELAPSED_TIME(time, startTime) ((time) - (startTime))

#define PERCENT_COMPLETE(bytes, totalBytes) (((bytes) / (totalBytes)) * 100)

#define DOWNLOAD_SPEED(time, startTime, bytes) \
((bytes) / ELAPSED_TIME(time, startTime))

#define TOTAL_TIME(time, startTime, bytes, totalBytes) \
(DOWNLOAD_SPEED(time, startTime, bytes) * (totalBytes))

#define REMAINING_TIME(time, startTime, bytes, totalBytes) \
(TOTAL_TIME(time, startTime, bytes, totalBytes) - ELAPSED_TIME(time, startTime))
