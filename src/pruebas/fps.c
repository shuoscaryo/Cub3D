#include "sys/time.h"
#include <stddef.h>

unsigned long	millis(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
#include <stdio.h>
void fps()
{
	static long  counter = 0;
	static long last_time = 0;
	static int first = 1;
	unsigned long this_time = millis();
	if (first)
	{
		first  = 0;
		last_time = this_time;
	}
	if (this_time - last_time > 1000)
	{
		printf("fps: %4f\n", (float)counter/(this_time - last_time) * 1000);
		counter = 0;
		last_time = this_time;
	}
	counter ++;
}