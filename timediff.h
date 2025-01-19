#ifndef TIMEDIFF_H
#define TIMEDIFF_H

/* constants */
#define SECONDS_PER_MINUTE 60
#define MINUTES_PER_HOUR 60
#define HOURS_PER_DAY 24
#define DAYS_PER_YEAR 365

#define SECONDS_IN_MINUTE (SECONDS_PER_MINUTE)
#define SECONDS_IN_HOUR (SECONDS_IN_MINUTE * MINUTES_PER_HOUR)
#define SECONDS_IN_DAY (SECONDS_IN_HOUR * HOURS_PER_DAY)
#define SECONDS_IN_YEAR (SECONDS_IN_DAY * DAYS_PER_YEAR)

typedef struct
{
    int year;   /* year (negative for BC) */
    int month;  /* 1-12 */
    int day;    /* 1-31 */
    int hour;   /* 0-23 */
    int minute; /* 0-59 */
    int second; /* 0-59 */
} time;

/* function prototypes */
int validate_time(time t, char *error_msg);
long calculate_seconds(time t);
void print_formatted_diff_time(long seconds);
long time_diff(time t1, time t2);
void print_welcome_message(void);
void print_time(time t);

#endif /* TIMEDIFF_H */