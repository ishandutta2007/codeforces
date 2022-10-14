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
template <class _T> inline string tostr(const _T &a) { ostringstream os(""); os << a; return os.str(); }

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
const int INF = 0x3f3f3f3f;

struct te
{
	int v1, v2;
	int a, f;
	int c;
};

int n, m, k;
char s[1024];
char a[1024][1024];
int b[1024];
int c[1024];
int d[1024];
int pa[1024];
te e[202400];

void add_edge(int v1, int v2, int w, int c)
{
	e[k++] = {v1, v2, w, 0, c};
	e[k++] = {v2, v1, 0, 0, -c};
}

int find(int st, int en)
{
	memset(d, 0x3f, sizeof(d));
	d[st] = 0;
	forn(tt, n + 1)
	{
		bool bb = true;
		forn(i, k)
		{
			int v1 = e[i].v1;
			int v2 = e[i].v2;
			if (d[v1] >= INF || e[i].f >= e[i].a) continue;
			if (d[v2] > d[v1] + e[i].c)
			{
				d[v2] = d[v1] + e[i].c;
				pa[v2] = i;
				bb = false;
			}
		}
		if (bb) break;
	}
	return d[en];
}

i64 flow(int st, int en, int x)
{
	i64 ans = 0;
	forn(tt, x)
	{
		int j = find(st, en);
		if (j >= 0) break;
		int k = en;
		while (k != st)
		{
			int ee = pa[k];
			ans += e[ee].c;
			e[ee].f++;
			e[ee ^ 1].f--;
			k = e[ee].v1;
		}
	}
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	k = 0;
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%d", &m);
	forn(i, m)
	{
		scanf("%s%d", a[i], &c[i]);
		b[i] = strlen(a[i]);
		forn(j, n - b[i] + 1)
		{
			if (!strncmp(s + j, a[i], b[i]))
				add_edge(j, j + b[i], 1, -c[i]);
		}
	}
	int x;
	scanf("%d", &x);
	forn(i, n)
	{
		add_edge(i, i + 1, x, 0);
	}
	i64 ans = -flow(0, n, x);
	printf("%lld\n", ans);
	
	return 0;
}