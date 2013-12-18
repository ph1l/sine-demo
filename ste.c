/*
	main.h
*/
#define WIDTH 80
#define HEIGHT 23
#define FPS 10
#define FULL_CYCLE_TIME 3

void draw_frame( int w, int h, int frame_no, int fps );

int in_ellipse( int x, int y, int a, int b, int r );

/*
	main.c
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
	int f=0;
	//printf( "WIDTH %d HEIGHT %d\n", WIDTH, HEIGHT );
	for (;;)
	{
		f++;
		draw_frame( WIDTH, HEIGHT, f, FPS );
		usleep(1000000/FPS);
	}
	return(0);
}

void draw_frame(w,h,frame_no,fps)
{
	int y=0;
	int x=0;
	int max_y, max_x, r;

	max_y= h / 2;
	max_x= w / 2;

	r = frame_no%(FPS*FULL_CYCLE_TIME);
	r = r-(FPS*FULL_CYCLE_TIME/2);

	for(y=-max_y; y<=max_y; y++)
	{
		for (x=-max_x; x<max_x; x++)
		{
			if ( in_ellipse( x, y, max_x, max_y, abs(r) )==1 )
			{
				int c;
				for (c=0;c < 6; c++)
				{
					if ( in_ellipse( x, y, max_x, max_y, abs(r)/(c+1) )==1 )
					{
						putchar(27);
						printf("[1;%dm",31+(c));
						continue;
					}
				}
				putchar('@');
			} else {
				putchar(' ');
			}
			putchar(27); //escape
			printf("[0m");
		}
		printf("\n");
	}
}

int in_ellipse(x,y,a,b,max)
{
	if (
		(( pow(x,2) / pow(a,2) ) +
		 ( pow(y,2) / pow(b,2) ) ) * (FPS*FULL_CYCLE_TIME/2) <= max )
		return 1;
	else
		return 0;
}
/*

void draw_random_frame(w,h)
{
	int y=0;
	int x=0;
	int i=0;

	for(y=0; y<h; y++)
	{
		for (x=0; x<w; x++)
		{
			i=(random()%94)+33;
			putchar(i);
		}
		printf("\n");
	}
}

*/
