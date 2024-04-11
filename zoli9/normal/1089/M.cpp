#include <stdio.h>
#define TESTING

#ifdef TESTING
#define TO
#else
#define TO if(0)
#endif

int main(){
	int n;
	scanf("%i", &n);
	
	char p[27][6][37] = {};
	for (int i = 0; i != n; i++)
	{
		int x = i * 3;
		for (int y = 1; y <= 3; y++)
			p[x][y][0] = p[x+1][y][0] = '.';
		p[x][2][0] = '1' + i;
		for (int z = 0; z != 37; z++)
			p[x][0][z] = '.';
		int z, q;
		for (z = 0; z <= 4*(i+1); z++)
		{
			p[x][4][z] = p[x][5][z] = p[x+1][4][z] = p[x+1][5][z] = '.';
			p[x + !(z&2)][4 | (z+1&2)>>1][z] = 0;
		}
		--z;
		p[x][3][z] = '.';
		for (int ox = 0; ox != 27; ox++) p[ox][2][z] = '.';
		for (int j = 0; j != n; j++)
		{
			scanf("%i", &q);
			if (q) p[j*3][1][z] = '.';
		}
	}
	
	printf("%i %i %i\n", n*3, 6, n*4+1);
	for (int z = n*4; z >= 0; z--)
	{
		if (z < n * 4) putchar('\n');
		for (int y = 0; y != 6; y++)
		{
			for (int x = 0; x != n*3; x++)
				putchar(p[x][y][z] ? p[x][y][z] : '#');
			putchar('\n');
		}
	}
	return 0;
}