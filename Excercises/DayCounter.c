#include <stdio.h>

// Determines the first day of current month given the info about last month

int determine_first_day(int month, int leap_year, int start_day){
    int month_category = 0; // 0 means 30 days, 1 means 31 days, 2 means 28 days, 3 means 29 days

    if(month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11){
        month_category = 1;
    }else if(month == 1){
        if(leap_year){
            //printf("Leap Spotted\n");
            month_category = 3;
        }else{
            month_category = 2;
        }
    }

    int raw_day_result = 0;
    switch (month_category){
        case 0:
            raw_day_result = start_day + 2;
            break;
        case 1:
            raw_day_result = start_day + 3;
            break;
        case 2:
            raw_day_result = start_day;
            break;
        case 3:
            raw_day_result = start_day + 1;
            break;
    }

    if(raw_day_result > 6){
        return raw_day_result - (6 + 1);
    }

    return raw_day_result;
}

int is_leap(int year){
    if(year % 100 == 0){
        return year % 400 == 0;
    }
    return year % 4 == 0;
}

// TODO: Fix 1800
int monday_counter(int start_year, int end_year, int december_start_day){
    // Getting info about January of start_year;
    int current_start_day = december_start_day;
    int monday_number = 0;

    for(int year = start_year; year <= end_year; year++){
        //printf("Year: %d\n", year);
        for(int month = 0; month < 12; month++){
            if(month == 0){
                current_start_day = determine_first_day(11, 0, current_start_day);
            }else{
                current_start_day = determine_first_day(month-1, is_leap(year), current_start_day);
            }
            //printf("%d month of year %d starts at %d day\n", month, year, current_start_day);
            if(current_start_day == 1){
                //printf("Month: %d\n", month);
                monday_number++;
            }
        }
    }

    return monday_number;
}

int DayCounter_main(){
    int mondays = monday_counter(1780, 2016, 3);
    printf("%d", mondays);

    return 0;
}




