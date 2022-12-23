//Вариант 6 задача f

#include <iostream>



struct Time_
{
    short hours;
    short minutes;
    short seconds;
};

void calculate(Time_* first_moment_time, Time_* second_moment_time)
{
    std::cout << "difference between hours:";
    if(first_moment_time->hours>second_moment_time->hours)
    {
        std::cout << first_moment_time->hours-second_moment_time->hours << "\n";
    }
    else
    {
        std::cout << second_moment_time->hours-second_moment_time->hours << "\n";
    }
    std::cout << "difference between minutes:";
    if(first_moment_time->minutes>second_moment_time->minutes)
    {
        std::cout << first_moment_time->minutes-second_moment_time->minutes << "\n";
    }
    else
    {
        std::cout << second_moment_time->minutes-second_moment_time->minutes << "\n";
    }
    std::cout << "difference between seconds:";
    if(first_moment_time->seconds>second_moment_time->seconds)
    {
        std::cout << first_moment_time->seconds-second_moment_time->seconds << "\n";
    }
    else
    {
        std::cout << second_moment_time->seconds-second_moment_time->seconds << "\n";
    }
}

void fill_time(Time_* first_moment_time, Time_* second_moment_time)
{
    std::cout << "Enter time of the first moment (h/m/s):";
    std::cin >> first_moment_time->hours;
    std::cout << "\n";
    std::cin >> first_moment_time->minutes;
    std::cout << "\n";
    std::cin >> first_moment_time->seconds;
    std::cout << "\n";
    std::cout << "Enter time of the second moment (h/m/s):";
    std::cin >> second_moment_time->hours;
    std::cout << "\n";
    std::cin >> second_moment_time->minutes;
    std::cout << "\n";
    std::cin >> second_moment_time->seconds;
    std::cout << "\n";
}

int main()
{
    Time_ first_time_moment;
    Time_ second_time_moment;
    fill_time(&first_time_moment, &second_time_moment);
    calculate(&first_time_moment, &second_time_moment);
}
