#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

double a, d, x, y, dir = 1;
int n, i;

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%lf %lf", &a, &d);
	while (d > 4.0 * a)
		d -= 4.0 * a;
	scanf("%d", &n);
	x = y = 0.0;
	for (i = 1; i <= n; i++)
	{
		if (dir == 1)
			x += d;
		else if (dir == 2)
			y += d;
		else if (dir == 3)
			x -= d;
		else if (dir == 4)
			y -= d;
		while (1)
		{
			if (dir == 1)
			{
				if (x > a)
					y = x - a, x = a, dir = 2;
				else
					break;
			}
			
			else if (dir == 2)
			{
				if (y > a)
					x = a - (y - a), y = a, dir = 3;
				else
					break;
			}
			
			else if (dir == 3)
			{
				if (x < 0)
					y = a + x, x = 0, dir = 4;
				else
					break;
			}
			
			else
			{
				if (y < 0)
					x = -y, y = 0, dir = 1;
				else
					break;
			}
		}
		
		printf("%.10f %.10f\n", x, y);
	}
	
	return 0;
}