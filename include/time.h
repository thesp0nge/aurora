#ifndef _TIME_H
#define _TIME_H

#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1);
#endif
