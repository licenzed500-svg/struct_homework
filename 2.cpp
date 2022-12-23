//Задача 3

#include <iostream>
#include <time.h>

struct Gabarits
{
    short x = 0;
    short y = 0;
};

struct Min_index
{
    short min_robot_weight_index;
    short min_robot_speed_index;
    short min_robot_gabarits_index_x;
    short min_robot_gabarist_index_y;
};

struct Robot
{
    Gabarits gabarits;
    short weight = 0;
    short speed = 0;
    const short max_weight = 40;
    const short min_weight = 10;
    const short max_speed = 40;
    const short min_speed = 5;
    const short max_x = 5;
    const short min_x = 2;
    const short max_y = 5;
    const short min_y = 2;
};

void data_out(Min_index min_index)
{
    std::cout << "minimal speed is robot:" << min_index.min_robot_speed_index << "\n";
    std::cout << "minimal weight is robot:" << min_index.min_robot_weight_index << "\n";
    std::cout << "minimal gabarits is robot:" << min_index.min_robot_gabarist_index_y << "\n";
}

void smallest_robot(Robot* robot, const short count)
{
    Min_index min_index;
    short min_robot_weight = robot[0].weight;
    Gabarits min_robot_gabarites = robot[0].gabarits;
    short min_robot_speed = robot[0].speed;
    for(short i = 0; i<count; i++)
    {
        if(robot[i].weight<min_robot_weight)
        {
            min_robot_weight = robot[i].weight;
            min_index.min_robot_weight_index = i;
        }
        if(robot[i].speed<min_robot_speed)
        {
            min_robot_speed = robot[i].speed;
            min_index.min_robot_speed_index = i;
        }
        if( (robot[i].gabarits.x<min_robot_gabarites.x) && (robot[i].gabarits.y<min_robot_gabarites.y) )
        {
            min_robot_gabarites.x = robot[i].gabarits.x;
            min_robot_gabarites.y = robot[i].gabarits.y;
            min_index.min_robot_gabarits_index_x = i;
            min_index.min_robot_gabarist_index_y = i;
        }
    }
    data_out(min_index);
}

void set_random(Robot* robot, const short count)
{
    for(short i = 0; i<count; i++)
    {
        robot[i].weight = robot->min_weight - rand() % (robot->max_weight- robot->min_weight);
        robot[i].speed = robot->min_speed - rand() % (robot->max_speed - robot->min_speed);
        robot[i].gabarits.x = robot->min_x - rand() % (robot->max_x-robot->min_x);
        robot[i].gabarits.y = robot->min_y - rand() % (robot->max_y-robot->min_y);
    }
}

int main()
{
    srand(time(NULL));
    const short robots_count = 10;
    Robot *robot = new Robot[robots_count];
    set_random(robot, robots_count);
    smallest_robot(robot, robots_count);
    
}
