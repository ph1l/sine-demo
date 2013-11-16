#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <poll.h>

int main(int argc, char *argv[])
{
	int	ah;
	double  f = 1.0;
	double	r = 0.01;
	int     s = 1000;
	int	i;

	if(argc != 2) {
		printf("usage: %s width\n", argv[0]);
		return 1;
	}


	ah = atoi(argv[1]) / 2;

	#ifdef DEBUG
	printf( "ARGS: %s %s\n", argv[1], argv[2]);
	printf( ": %i %f\n", ah, f);
	#endif

	//open stdin

	setvbuf(stdin, NULL, _IONBF, 0);

	struct pollfd p;
	p.fd = STDIN_FILENO;
	p.events = POLLIN;
	
	for(;;) {

		int j;
		char c;

		#ifdef DEBUG
		printf("%g %g ",r, f);
		#endif

		i = ah * cos(r) + ah;
		int pad = ((ah * 2) - i)/2;

		for( j=0; j < pad; j++){
			putchar(' ');
		}
		for( j=0; j <= i; j++){
			putchar('#');
		}

		puts("");

		usleep(s);

		r = r+(0.01*f);

		p.revents=0;

		poll( &p, 1, 10 );

		if ( p.revents && POLLIN){
			read( STDIN_FILENO, &c, 1);
			switch ( c )
			{
				case 'f':
					f = f * 1.1;
					break;
				case 'r':
					f = f * .9;
					break;
				case 'd':
					s = s / 2;
					break;
				case 'e':
					s = s * 2;
					break;
				case 'q':
					return 0;
			}
		}
	}
}
