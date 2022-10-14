#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

#ifdef ROOM_311
__attribute__((destructor)) void fini_main()
{
	fprintf(stderr, "Execution time = %0.0lf ms\n", clock() * 1000.0 / CLOCKS_PER_SEC);
}
#endif

#define MY_RAND 1
#if MY_RAND
uint64_t rnd_data = 0xDEADBEEFDULL;
inline void my_srand(int seed) { rnd_data = ((uint64_t)seed << 16) | 0x330E; }
inline int my_rand() { rnd_data = rnd_data * 0x5DEECE66DULL + 0xB; return (rnd_data >> 17) & 0x7FFFFFFF; }
#define rand my_rand
#define srand my_srand
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }

// Types
typedef long double ld;
typedef long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-11;

const int MAXN = 10240;

#define x first
#define y second

struct ts
{
	int l, r, m, cnt;
};

int n, ss, z;
int a[MAXN];
int b[MAXN];
ts s[MAXN];
PII t[1 << 15];

void tadd(int x, int k)
{
	x += z;
	t[x] = mp(k, x - z);
	x >>= 1;
	while (x)
	{
		t[x] = max(t[x * 2], t[x * 2 + 1]);
		x >>= 1;
	}
}

PII tmin(int l, int r)
{
	PII ans = mp(0, 0);
	l += z;
	r += z;
	while (l <= r)
	{
		if (l & 1) ans = max(ans, t[l]);
		if (!(r & 1)) ans = max(ans, t[r]);
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	return ans;
}

int med(VI const &z)
{
	return z[z.sz / 2];
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d", &n);
	z = 1;
	while (z < n) z <<= 1;
	clr(t);
	forn(i, n)
	{
		scanf("%d", &a[i]);
		a[i] += n - i;
		t[z + i] = mp(a[i], i);
	}
	Ford(i, z - 1, 1)
	{
		t[i] = max(t[i * 2], t[i * 2 + 1]);
	}
	ss = 0;
	forn(i, n)
	{
		ts cur = { .l = i, .r = i, .m = a[i], .cnt = 1 };
		while (ss > 0 && s[ss - 1].m > cur.m)
		{
			ss--;
			cur.l = s[ss].l;
			cur.cnt += s[ss].cnt;
			while (cur.cnt > (cur.r - cur.l + 1) / 2 + 1)
			{
				PII tmp = tmin(cur.l, cur.r);
				tadd(tmp.second, 0);
				cur.cnt--;
			}
			cur.m = tmin(cur.l, cur.r).first;
		}
		s[ss++] = cur;
	}
	i64 ans = 0;
	forn(i, ss)
	{
		int m = s[i].m;
		For(k, s[i].l, s[i].r)
		{
			ans += abs(m - a[k]);
		}
	}
	printf("%lld\n", ans);
	
	return 0;
}