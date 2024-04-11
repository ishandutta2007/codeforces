#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define INF ((int) 1e9)
#define rint(x) scanf("%d", &(x))

#define MAXN 1010
#define OFFS (MAXN/2)
#define EMP 0
#define UP 1
#define DOWN 2

using namespace std;
typedef long long ll;

int field[MAXN][MAXN*2];
int arr[MAXN];
int N;

char chr(int x)
{
	if (x == EMP)
		return ' ';
	if (x == UP)
		return '/';
	if (x == DOWN)
		return '\\';
	assert(false);
}

int main()
{
	loop(i, MAXN)
		loop(j, MAXN*2)
			field[i][j] = EMP;

	rint(N);

	int px = 0, py = MAXN/2;
	int minY = 0, maxY = 0;
	loop(i, N)
	{
		rint(arr[i]);
		int x = px + arr[i];
		int y = py + ((i % 2 == 0) ? arr[i] : -arr[i]);
		//printf("%d %d (%d) %d %d\n", x, y, arr[i], px, py);
		minY = min(minY, y+1);
		maxY = max(maxY, y-1);

		if (py < y)
		{
			loop(j, arr[i])
				field[px+j][py+j] = UP;
			y--;
		}
		else
		{
			loop(j, arr[i])
				field[px+j][py-j] = DOWN;
			y++;
		}
		px = x;
		py = y;
	}

	for (int y = maxY; y >= minY; y--)
	{
		for (int x = 0; x < px; x++)
			printf("%c", chr(field[x][y]));
		printf("\n");
	}
}