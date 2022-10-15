#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)

typedef long long i64;

const int MOD = 51123987;

#define MAXN 2000002
const int SHAMANIC = 11;
#define hx 73
const int LOG = 5;

char s1[MAXN];
char s2[MAXN];
int n;
int h1[LOG][MAXN];
int h2[LOG][MAXN];
int st[MAXN];
int fn[MAXN];
int bs[MAXN];
int bf[MAXN];

void calc_h(char *s, int n, int h[][MAXN])
{
	int z = 1;
	forn(j, SHAMANIC)
	{
		z = z * hx;
	}
	
	h[0][0] = 0;
	forn(j, SHAMANIC)
	{
		h[0][0] = h[0][0] * hx + s[j] - '`';
	}
	For(j, SHAMANIC, n-1)
	{
		h[0][j+1-SHAMANIC] = h[0][j-SHAMANIC] * hx + (s[j] - '`') - (s[j - SHAMANIC] - '`') * z;
	}
	int r = 1;
	For(i, 1, LOG-1)
	{
		r *= SHAMANIC;
		int t = z;
		z = 1;

		forn(j, SHAMANIC)
		{
			z = z * t;
		}
	
		forn(l, r)
		{
			h[i][l] = 0;
			forn(j, SHAMANIC)
			{
				h[i][l] = h[i][l] * t + h[i-1][j * r + l];
			}
			int j0 = SHAMANIC * r;
			for(int j = j0; j < n; j += r)
			{
				h[i][l + j - j0 + r] = h[i][l + j - j0] * t + h[i-1][j + l] - h[i-1][j + l - j0] * z;
			}
		}
	}
}

inline void add(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

inline void add2(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

inline void sub(int &a, int b)
{
	a -= b;
	if (a < 0) a += MOD;
}

int go(int i, int j, int t)
{
	int r = 1;
	forn(l, LOG)
	{
		r *= SHAMANIC;
	}
	ford(l, LOG)
	{
		while (i + r <= n && j + r <= n && h1[l][i] == h2[l][j])
		{
			i += r;
			j += r;
		}
		r /= SHAMANIC;
	}
	while (i + r <= n && j + r <= n && s1[i] == s2[j])
	{
		i += r;
		j += r;
	}
	return i - t;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	gets(s1);
	sscanf(s1, "%d", &n);
	gets(s1);
	forn(i, n)
	{
		s2[i] = s1[n-i-1];
	}
	calc_h(s1, n, h1);
	calc_h(s2, n, h2);
	clr(bs);
	clr(bf);

	int cnt = 0;
	forn(t, n)
	{
		int i = t;
		int j = n - t - 1;
		int l1 = go(i, j, t);
		add(cnt, l1);
		bs[t - l1 + 1]++;
		bs[t + 1]--;
		bf[t]++;
		bf[t + l1]--;
		if (t)
		{
			i = t;
			j = n - t;
			int l2 = go(i, j, t);
			add(cnt, l2);
			bs[t - l2]++;
			bs[t]--;
			bf[t]++;
			bf[t + l2]--;
		}
	}

	clr(st);
	fn[0] = 0;

	int ans = (i64)cnt * (cnt-1) / 2 % MOD;

	int x = 0;
	int y = 0;
	forn(i, n)
	{
		add2(x, bs[i]);
		st[i] = x;
		add2(y, bf[i]);
		add(fn[i], y);
		fn[i+1] = fn[i];
	}

	For(i, 1, n-1)
	{
		sub(ans, (i64)st[i] * fn[i-1] % MOD);
	}
	printf("%d\n", ans);

	return 0;
}