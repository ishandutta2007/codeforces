#include <algorithm>
#include <cstdio>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)

int qq, n;
int a[202400][2];
int ind[202400];

bool cmp(int p1, int p2)
{
	return a[p1][1] < a[p2][1];
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	scanf("%d", &qq);
	while (qq--)
	{
		scanf("%d", &n);
		forn(i, n * 2 - 1)
		{
			scanf("%d%d", &a[i][0], &a[i][1]);
			ind[i] = i;
		}

		sort(ind, ind+n*2-1, cmp);

		printf("YES\n%d", ind[2*n-2] + 1);
		forn(i, n-1)
		{
			int y = ind[2 * i];
			if (a[ind[2 * i + 1]][0] > a[y][0]) y = ind[2 * i + 1];
			printf(" %d", y+1);
		}
		puts("");
	}

	return 0;
}