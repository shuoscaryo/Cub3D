#include "sys/time.h"
#include <stddef.h>

unsigned long	millis(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
#include <stdio.h>
float	fps()
{
	static long  counter = 0;
	static long last_time = 0;
	static int first = 1;
	unsigned long this_time = millis();
	static float fps;
	if (first)
	{
		first  = 0;
		last_time = this_time;
	}
	if (this_time - last_time > 1000)
	{
		fps = (float)counter/(this_time - last_time) * 1000;
		counter = 0;
		last_time = this_time;
	}
	counter ++;
	return (fps);
}