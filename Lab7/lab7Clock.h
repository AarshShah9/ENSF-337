//  ENSF 337, Exercise C
//  lab7Clock.h
//  By: Aarsh Shah

#ifndef lab7clock_h

#define lab7clock_h

class Clock
{

public:
    Clock();
    Clock(int sec);
    Clock(int hr, int mins, int sec);

    int get_hour() const;
    void set_hour(int hr);
    int get_minute() const;
    void set_minute(int min);
    int get_second() const;
    void set_second(int sec);

    void increment();
    void decrement();

    void add_seconds(int sec);

private:
    int hour, minute, second;

    int hms_to_sec();
    void sec_to_hms(int n);
};

#endif