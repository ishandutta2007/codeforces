#include <cstdio>
#include <cstring>

#define clr(x) memset((x), 0, sizeof(x))
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)

int n;
int a[1024][1024];
char d[1024][8];
int l[1024];
char s[4096];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	scanf("%d", &n);

	forn(i, n)
	{
		a[i][i] = 0;
		int t = (i * 2 + 1) % n;
		if (i >= n/2) t++;
		For(j, i+1, n-2)
		{
			a[i][j] = a[j][i] = t++;
			if (t == n) t = 1;
		}
		if (i < n/2)
		{
			a[i][n-1] = a[n-1][i] = i * 2;
		}
		else
		{
			a[i][n-1] = a[n-1][i] = (i - n/2) * 2 + 1;
		}
	}
	a[0][0] = a[n-1][n-1] = 0;
	a[0][n-1] = a[n-1][0] = n-1;

	clr(d);
	forn(i, n)
	{
		l[i] = sprintf(d[i], "%d", i);
	}

	forn(i, n)
	{
		int r = 0;
		forn(j, n)
		{
			if (j) s[r++] = ' ';
			int x = a[i][j];
			forn(t, l[x])
			{
				s[r++] = d[x][t];
			}
		}
		s[r] = '\0';
		puts(s);
	}

	return 0;
}