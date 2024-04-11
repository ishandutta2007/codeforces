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

int n, m, k;
SI a[1024000];
int c[1024000];
int b[1024000][2];
int ans[1024000];
int q[1024000];
bool u[1024000];

int solve0()
{
	int qb = 0, qe = 0;
	forn(i, n)
	{
		c[i] = a[i].sz;
		if (c[i] < k)
		{
			u[i] = true;
			q[qe++] = i;
		}
	}
	while (qb != qe)
	{
		int v = q[qb++];
		for (int i : a[v])
		{
			c[i]--;
			if (c[i] < k && !u[i])
			{
				u[i] = true;
				q[qe++] = i;
			}
		}
	}
	return qe;
}

int bfs(int x, int y)
{
	if (u[x] || u[y]) return 0;
	int qb = 0, qe = 0;
	for (int i : {x, y})
	{
		if (c[i] - 1 < k)
		{
//			cerr << "! " << i << " " << c[i] << endl;
			u[i] = true;
			q[qe++] = i;
		}
	}
	if (qe == 0)
	{
		a[x].erase(y);
		a[y].erase(x);
		c[x]--;
		c[y]--;
		return 0;
	}
//	cerr << x << " " << y << " " << qe << " " << q[qe - 1] << " " << c[0] << " " << c[1] << " " << c[4] << endl;
	while (qb != qe)
	{
		int v = q[qb++];
		for (int i : a[v])
		{
			c[i]--;
			if (c[i] < k && !u[i])
			{
				u[i] = true;
				q[qe++] = i;
			}
		}
	}
/*	cerr << "qe=" << qe << endl;
	forn(i, qe)
	{
		cerr << q[i] << " ";
	}
	cerr << endl;*/
	return qe;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	clr(u);
	scanf("%d%d%d", &n, &m, &k);
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		b[i][0] = x;
		b[i][1] = y;
		a[x].insert(y);
		a[y].insert(x);
	}

	ans[m - 1] = n - solve0();
	ford(i, m - 1)
	{
		int x = b[i + 1][0];
		int y = b[i + 1][1];
//		cerr << x << " " << y << endl;
		ans[i] = ans[i + 1] - bfs(x, y);
	}

	forn(i, m)
	{
		printf("%d\n", ans[i]);
	}
	
	return 0;
}