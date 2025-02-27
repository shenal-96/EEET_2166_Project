/*
 * TL_I1.h
 *
 *  Created on: 29Sep.,2019
 *      Author: LukeT
 */

#ifndef TL_I1_H_
#define TL_I1_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // Used for sleep()
#include <pthread.h>

enum lightState     {red, yellow, green, off, disabled, flashing};
enum sequenceState  {initial, day1, day2, day3, day4,   day5,   day6, day7, day8, day9, day10,   day11,   day12,
                                                night4, night5, night6,                 night10, night11, night12};
                          // Night sequences 4,5,6 and 10,11,12 are equal with the same day sequences numbers
struct light
{
    enum lightState pedestrian1;
    enum lightState left;
    enum lightState straight;
    enum lightState right;
    enum lightState pedestrian2;
};

struct intersection
{
    struct light north;
    struct light south;
    struct light east;
    struct light west;
    enum sequenceState seqState;
}intersection;


/// For functions
void setState(int northPedestrian1, int northLeft, int northStraight, int northRight, int northPedestrian2,
              int southPedestrian1, int southLeft, int southStraight, int southRight, int southPedestrian2,
              int eastPedestrian1,  int eastLeft,  int eastStraight,  int eastRight,  int eastPedestrian2,
              int westPedestrian1,  int westLeft,  int westStraight,  int westRight,  int westPedestrian2);
unsigned long hash(char *str);


/// For Threads
void extCommunication(void);
void *gpioController(void);
void *daySequence(void);
void *nightSequence(void);
void *commandLineInputThread(void);

#endif /* TL_I1_H_ */
