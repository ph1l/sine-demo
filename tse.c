#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <poll.h>

int main(int argc, char *argv[])
{
	int	ah;
	double  f;
	double	r = 0.01;
	int     s = 1000;
	int	i;

	if(argc != 4) {
		printf("usage: %s amplitude factor sleep\n", argv[0]);
		return 1;
	}


	ah = atoi(argv[1]) / 2;
	//f = strtod(argv[2], NULL);
	f = atof(argv[2]);
	s = atoi(argv[3]);

	#ifdef DEBUG
	printf( "ARGS: %s %s\n", argv[1], argv[2]);
	printf( ": %i %f\n", ah, f);
	#endif

	//open stdin

	setvbuf(stdin, NULL, _IONBF, 0);

	struct pollfd p;
	p.fd = 0;
	p.events = POLLIN;
	
	for(;;) {

		int j;

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

		poll( &p, 1, 10 );

		if ( p.revents && POLLIN) return 0;
	}
}
