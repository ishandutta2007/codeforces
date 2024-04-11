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
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)

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
template <typename T> void my_random_shuffle(T b, T e) { For(i, 1, (int)(e - b) - 1) { swap(b[i], b[rand() % (i + 1)]); } }
#define random_shuffle my_random_shuffle
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }
template<typename type_t, typename less_t = std::less<type_t>> inline bool uin(type_t &a, const type_t &b, const less_t &ls = less_t()) { return ls(b, a) ? a = b, true : false; }
template<typename type_t, typename less_t = std::less<type_t>> inline bool uax(type_t &a, const type_t &b, const less_t &ls = less_t()) { return ls(a, b) ? a = b, true : false; }

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
const ld EPS = 1e-9;

const int MAXN = 202400;

int n, m;
int a[MAXN];
int b[MAXN * 3];
int p1[MAXN * 3];
int p2[MAXN * 3];

void calc_pal1(int *a, int n, int *p)
{
	int r = 0, m = -1;
	forn(i, n)
	{
		int z = i <= r ? min(p[m - (i - m)], r - i) : 1;
		while (i + z < n && i - z >= 0 && a[i + z] == a[i - z]) z++;
		p[i] = z;
		if (i + z - 1 > r)
		{
			r = i + z - 1;
			m = i;
		}
	}
}

void calc_pal2(int *a, int n, int *p)
{
	int r = 0, m = -1;
	forn(i, n)
	{
		int z = i <= r ? min(p[m - (i - m)], r - i) : 0;
		while (i + z < n && i - 1 - z >= 0 && a[i + z] == a[i - 1 - z]) z++;
		p[i] = z;
		if (i + z - 1 > r)
		{
			r = i + z - 1;
			m = i;
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d%d", &n, &m);
	forn(i, n)
	{
		scanf("%d", &a[i]);
	}
	a[n] = a[0] + m;
	forn(i, n)
	{
		b[i] = a[i + 1] - a[i];
	}
/*	forn(i, n)
	{
		cerr << b[i] << " ";
	}
	cerr << endl;*/
	forn(i, n * 2)
	{
		b[i + n] = b[i];
	}
	calc_pal1(b, 3 * n, p1);
	calc_pal2(b, 3 * n, p2);
	VI ans;
	forn(i, n)
	{
		int x = (a[i] + a[0]) % m;
//		cerr << "? " << x << endl;
		if (x & 1)
		{
			int y = lower_bound(a, a + n, (x + 1) / 2) - a;
			int y1 = y - 1;
			if (y1 < 0) y1 = n - 1;
			int l = a[y1];
			int r = a[y];
			if (l > x / 2) l -= m;
			if (x == l + r && p1[n + y1] >= n) ans.pb(x);
		}
		else
		{
			int y = lower_bound(a, a + n, (x + 1) / 2) - a;
			if (a[y] == x / 2)
			{
				if (p2[n + y] >= n) ans.pb(x);
			}
			else
			{
				int y1 = y - 1;
				if (y1 < 0) y1 = n - 1;
				int l = a[y1];
				int r = a[y];
				if (l > x / 2) l -= m;
				if (x == l + r && p1[n + y1] >= n) ans.pb(x);
			}
		}
/*		if (a[y] == x)
		{
			if (p2[n + y] >= n) ans.pb(x);
		}
		else
		{
			int y1 = y - 1;
			if (y1 < 0) y1 = n - 1;
			int l = a[y1];
			int r = a[y];
			if (l > x) l -= m;
			cerr << x << " " << l << " " << r << endl;
			if (x * 2 == l + r && p1[n + y1] >= n) ans.pb(x);
		}*/
	}
	sort(all(ans));
	printf("%d\n", (int)ans.sz);
	forn(i, ans.sz)
	{
		printf("%d%c", ans[i], " \n"[i == (int)ans.sz - 1]);
	}
	
	return 0;
}