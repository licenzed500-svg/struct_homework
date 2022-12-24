//Задача 6

#include <iostream>
#include <time.h>


struct Most_accurate
{
    short most_by_infelicity;
    short index;
};

struct Sensor_accuracy
{
    const short diapason_min = 10;
    const short diapason_max = 50;
    const short max_speed = 20;
    const short min_speed = 5;
    const short min_infelicity = 2;
    const short max_infelicity = 7;
};

struct Sensor
{
    Sensor_accuracy accuracy;
    short self_diapason;
    short max_speed;
    short infelicity;
};

void data_out(Most_accurate *most_accurate)
{
    std::cout << "\nmost accurate sensor is:" << most_accurate->index << "\n";
}

Most_accurate most_accuracy_sensor(Sensor *sensors, short count)
{
    Most_accurate most_accurate_sensor;
    most_accurate_sensor.most_by_infelicity = sensors[0].infelicity;
    for(short i = 0; i<count; i++)
    {
        if(sensors[i].infelicity>most_accurate_sensor.most_by_infelicity)
        {
            most_accurate_sensor.most_by_infelicity = sensors[i].infelicity;
            most_accurate_sensor.index = i;
        }
    }
    return most_accurate_sensor;
}

void fill_random(Sensor *sensors, short count)
{
    for(short i = 0; i<count; i++)
    {
        sensors[i].self_diapason = sensors[i].accuracy.diapason_min + rand() % (sensors[i].accuracy.diapason_max - sensors[i].accuracy.diapason_min);
        sensors[i].max_speed = sensors[i].accuracy.min_speed + rand() % (sensors[i].accuracy.max_speed - sensors[i].accuracy.min_speed);
        sensors[i].infelicity = sensors[i].accuracy.min_infelicity + rand() % (sensors[i].accuracy.max_infelicity - sensors[i].accuracy.min_infelicity);
    }
}

int main()
{
    srand(time(NULL));
    const short count_sensors = 10;
    Sensor *sensors = new Sensor[count_sensors];
    fill_random(sensors, count_sensors);
    Most_accurate some_sensor = most_accuracy_sensor(sensors, count_sensors);
    data_out(&some_sensor);
    
}
