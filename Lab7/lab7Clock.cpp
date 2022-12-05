//  ENSF 337, Exercise C
//  lab7Clock.cpp
//  By: Aarsh Shah

#include "lab7Clock.h"

Clock::Clock()
{
    hour = 0;
    minute = 0;
    second = 0;
}

Clock::Clock(int sec)
{
    if (sec >= 0)
    {
        sec_to_hms(sec);
    }
    else
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
}
Clock::Clock(int hr, int min, int sec)
{
    if ((sec >= 0) && (sec < 60) && (min >= 0) && (min < 60) && (hr >= 0) && (hr < 24))
    {
        hour = hr;
        minute = min;
        second = sec;
    }
    else
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
}

int Clock::get_hour() const { return hour; }
int Clock::get_minute() const { return minute; }
int Clock::get_second() const { return second; }

void Clock::set_hour(int hr)
{
    if (hr < 24 && hr >= 0)
    {
        hour = hr;
    }
}
void Clock::set_minute(int min)
{
    if (min < 60 && min >= 0)
    {
        minute = min;
    }
}
void Clock::set_second(int sec)
{
    if (sec < 60 && sec >= 0)
    {
        second = sec;
    }
}

void Clock::increment() { sec_to_hms(1 + hms_to_sec()); }

void Clock::decrement() { sec_to_hms(hms_to_sec() - 1); }

void Clock::add_seconds(int sec) { sec_to_hms(sec + hms_to_sec()); }

int Clock::hms_to_sec()
{
    return (hour * 3600) + (minute * 60) + second;
}
void Clock::sec_to_hms(int n)
{
    if (n < 0)
    {
        n = 86400 + n;
    }

    minute = n / 60;
    second = n % 60;
    hour = minute / 60;
    minute = minute % 60;

    minute %= 60;
    hour %= 24;
    second %= 60;
}
