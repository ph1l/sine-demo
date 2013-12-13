#include <stdio.h>
#include <unistd.h>

int main()
{
	int b=fork();
	if ( b ) sleep(1);
	printf("%i\n",  b);
	return 0;
}
