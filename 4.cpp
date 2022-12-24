//Задача 11

#include <iostream>
#include <time.h>

struct Diapasons
{
    const int seconds_in_hour = 3600;
    const short max_speed = 255;
    const short min_speed = 100;
    const int min_duration = 1000l;
    const int max_duration = 35000;
};

struct Robot_car
{
    
    Diapasons diapasons;
    float distance = 0;
    short speed;
    int duration; //time(seconds)
    short numer;
};

void data_out(Robot_car *cars, short count)
{
    for(short i = 0; i<count; i++)
    {
        std::cout << "\ncar:" << cars[i].numer << " distance:" << cars[i].distance << "\n";
    }
}

void calculate(Robot_car *cars, short count)
{
    for(int i = 0; i<count; i++)
    {
        float *duration_in_hours = new float;
        *duration_in_hours = cars[i].duration / cars[i].diapasons.seconds_in_hour;
        cars[i].distance = cars[i].speed * (*duration_in_hours);
        delete duration_in_hours;
    }
}

void fill_data(Robot_car *cars, short count)
{
    for(short i = 0; i<count; i++)
    {
        cars[i].duration = cars[i].diapasons.min_duration + rand () % (cars[i].diapasons.max_duration - cars[i].diapasons.min_duration);
        cars[i].speed = cars[i].diapasons.min_speed + rand() % (cars[i].diapasons.max_speed - cars[i].diapasons.min_speed);
        cars[i].numer = i+1;
    }
}

int main()
{
    srand(time(NULL));
    const short count = 10;
    Robot_car *cars = new Robot_car[count];
    fill_data(cars, count);
    calculate(cars, count);
    data_out(cars, count);
    delete[] cars;
}
