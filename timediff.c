#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/* days in each month */
const int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* check if time values are valid and return error message if not */
int validate_time(time t, char *error_msg)
{
    if (t.year == 0)
    {
        sprintf(error_msg, "Year 0 is invalid, use negative values for BC years");
        return 0;
    }
    if (t.month < 1 || t.month > 12)
    {
        sprintf(error_msg, "Month must be between 1 and 12, got %d", t.month);
        return 0;
    }
    if (t.day < 1 || t.day > days_in_month[t.month])
    {
        sprintf(error_msg, "Day must be between 1 and %d for month %d, got %d",
                days_in_month[t.month], t.month, t.day);
        return 0;
    }
    if (t.hour < 0 || t.hour > 23)
    {
        sprintf(error_msg, "Hour must be between 0 and 23, got %d", t.hour);
        return 0;
    }
    if (t.minute < 0 || t.minute > 59)
    {
        sprintf(error_msg, "Minute must be between 0 and 59, got %d", t.minute);
        return 0;
    }
    if (t.second < 0 || t.second > 59)
    {
        sprintf(error_msg, "Second must be between 0 and 59, got %d", t.second);
        return 0;
    }
    return 1;
}

/* convert time object to total seconds */
long calculate_seconds(time t)
{
    long total_seconds = 0;
    int i;

    /* convert years to seconds. we subtract 1 from positive years to maintain continuity
       between BCE and CE years (since there's no year 0, it jumps from -1 to 1).
       this helps avoid calculation errors when computing time differences across the eras */
    if (t.year < 0)
    {
        total_seconds = (long)t.year * SECONDS_IN_YEAR;
    }
    else
    {
        total_seconds = ((long)t.year - 1) * SECONDS_IN_YEAR;
    }

    /* convert months to seconds */
    for (i = 1; i < t.month; i++)
    {
        total_seconds += (long)days_in_month[i] * SECONDS_IN_DAY;
    }

    /* convert days, hours, minutes, and seconds to seconds */
    /* subtract 1 from days since if we're on day 1 we have 0 complete days
     (e.g., on January 1st at 5:00, we've completed 0 full days of January) */
    total_seconds += (long)(t.day - 1) * SECONDS_IN_DAY;
    total_seconds += (long)t.hour * SECONDS_IN_HOUR;
    total_seconds += (long)t.minute * SECONDS_IN_MINUTE;
    total_seconds += t.second;

    return total_seconds;
}

/* print seconds as formated (years, days, hours, minutes, and seconds) */
void print_formatted_diff_time(long seconds)
{
    long temp_seconds;
    int years, days, hours, minutes;
    int remaining_seconds;

    temp_seconds = seconds;
    years = temp_seconds / SECONDS_IN_YEAR;
    temp_seconds %= SECONDS_IN_YEAR;
    days = temp_seconds / SECONDS_IN_DAY;
    temp_seconds %= SECONDS_IN_DAY;
    hours = temp_seconds / SECONDS_IN_HOUR;
    temp_seconds %= SECONDS_IN_HOUR;
    minutes = temp_seconds / SECONDS_IN_MINUTE;
    remaining_seconds = temp_seconds % SECONDS_IN_MINUTE;

    printf("Time difference: %ld seconds\n", seconds);
    printf("In readable format: %d years, %d days, %d hours, %d minutes, %d seconds\n\n",
           years, days, hours, minutes, remaining_seconds);
}

/* calculate the difference between two times */
long time_diff(time t1, time t2)
{
    long seconds1 = calculate_seconds(t1);
    long seconds2 = calculate_seconds(t2);

    /* handle the case where both times are from BC (negative seconds) */
    if (seconds1 < 0 && seconds2 < 0)
    {
        return abs(seconds1 - seconds2);
    }

    /* handle the case where the one time is BC and the other one isn't */
    else if (seconds1 < 0)
    {
        return seconds2 - seconds1;
    }
    else if (seconds2 < 0)
    {
        return seconds1 - seconds2;
    }

    /* both times are after BC (positive) */
    return abs(seconds1 - seconds2);
}

void print_welcome_message()
{
    printf("Welcome to the Time Difference Calculator!\n");
    printf("Enter two timestamps as:\n");
    printf("  Year Month Day Hour Minute Second Year Month Day Hour Minute Second\n");
    printf("Example:\n");
    printf("  2023 12 31 23 59 59 2024 1 1 0 0 0\n");
    printf("Press Ctrl+D to exit.\n\n");
}

/* print single time value in readable format */
void print_time(time t)
{
    /* print year with BC/AD */
    if (t.year < 0)
    {
        printf("%d BC", abs(t.year));
    }
    else
    {
        printf("%d AD", t.year);
    }

    /* print remaining date and time components */
    printf(", %02d/%02d %02d:%02d:%02d",
           t.month, t.day, t.hour, t.minute, t.second);
}

int main()
{
    time t1, t2;
    int read_count;
    int pair_number = 0;
    long time_difference;
    char error_msg[100];
    int success_count = 0;

    print_welcome_message();

    /* process input until EOF */
    while (1)
    {
        /* try to read first time */
        printf(">> Enter first time (Year Month Day Hour Minute Second): ");
        read_count = scanf("%d %d %d %d %d %d",
                           &t1.year, &t1.month, &t1.day,
                           &t1.hour, &t1.minute, &t1.second);

        /* check if we reached EOF before any numbers were read */
        if (read_count == EOF)
        {
            break;
        }

        /* check if we got all 6 numbers for first time */
        if (read_count != 6)
        {
            printf("\nPair %d: Error - Invalid input format for first time (expected 6 numbers)\n",
                   pair_number);
            /* try to read until next line */
            while (getchar() != '\n' && getchar() != EOF)
                ;
            pair_number++;
            continue;
        }

        /* validate first time */
        if (!validate_time(t1, error_msg))
        {
            printf("Error in first time: %s\n", error_msg);
            pair_number++;
            continue;
        }

        /* read second time */
        printf(">> Enter second time (Year Month Day Hour Minute Second): ");
        read_count = scanf("%d %d %d %d %d %d",
                           &t2.year, &t2.month, &t2.day,
                           &t2.hour, &t2.minute, &t2.second);

        /* check if we got all 6 numbers for second time */
        if (read_count != 6)
        {
            printf("\nPair %d: Error - Invalid input format for second time (expected 6 numbers)\n",
                   pair_number);
            /* try to read until next line */
            while (getchar() != '\n' && getchar() != EOF)
                ;
            pair_number++;
            continue;
        }

        /* validate second time */
        if (!validate_time(t2, error_msg))
        {
            printf("Error in second time: %s\n", error_msg);
            pair_number++;
            continue;
        }

        printf("\nFirst time:  ");
        print_time(t1);
        printf("\nSecond time: ");
        print_time(t2);
        printf("\n");

        /* calculate and print time difference */
        time_difference = time_diff(t1, t2);
        print_formatted_diff_time(time_difference);

        success_count++;
        pair_number++;
    }

    /* print summary */
    printf("\nProcessed %d pairs of times, %d were valid.\n",
           pair_number, success_count);

    return 0;
}