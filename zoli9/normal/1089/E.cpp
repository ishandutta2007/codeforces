#include <stdio.h>
#include <stdlib.h>
#define TESTING

#ifdef TESTING
#define TO
#else
#define TO if(0)
#endif

int mleft;

void pm(int x, int y) {printf("%c%i ", 'a' + x, y + 1);}

void move(int x, int y)
{
	pm(x, y);
	if (--mleft <= 2 - (y == 7))
	{
		if (x != 7)
		{
			if (y != 7) pm(x, 7);
			pm(7, 7);
		}
		else
		{
			if (y != 6) pm(7, 6);
			pm(7, 7);
		}
		exit(0);
	}
}

int main(){
	scanf("%i", &mleft);
	++mleft;
	
	for (int y = 0; y != 6; y++)
		for (int x = 0; x != 8; x++)
			move(x ^ ((y & 1) * 7), y);
	move(0, 6);
	if (mleft == 3) move(1, 6);
	for (int x = 7; x; x--) move(x, 6);
	move(1, 7); move(0, 7);
	for (int x = 2; x != 8; x++) move(x, 7);
	return 1;
}