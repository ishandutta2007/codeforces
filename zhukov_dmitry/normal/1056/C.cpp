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

int n, m;
int a[10240];
int pa[10240];
bool u[10240];
int rem;

int read_move()
{
	int x;
	scanf("%d", &x);
	x--;
	u[x] = true;
	rem--;
	return x;
}

void go(int x)
{
	u[x] = true;
	rem--;
	printf("%d\n", x + 1);
	fflush(stdout);
}

int main()
{
#ifdef ROOM_311
//	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d%d", &n, &m);
	forn(i, 2 * n)
	{
		scanf("%d", &a[i]);
	}
	clr(u);
	memset(pa, 0xff, sizeof(pa));
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		pa[x] = y;
		pa[y] = x;
	}
	int t;
	scanf("%d", &t);
	rem = 2 * n;
	if (t == 2)
	{
		while (rem)
		{
			int x = read_move();
			if (pa[x] >= 0)
			{
				go(pa[x]);
			}
			else break;
		}
	}
	forn(i, n * 2)
	{
		if (u[i]) continue;
		if (pa[i] >= 0)
		{
			int x = pa[i];
			int y = i;
			if (a[x] < a[y]) swap(x, y);
			go(x);
			/*int yy = */read_move();
//			assert(y == yy);
		}
	}


	while (rem)
	{
		int ma = -1, mj = -1;
		forn(i, n * 2)
		{
			if (!u[i])
			{
				if (uax(ma, a[i])) mj = i;
			}
		}
		if (mj < 0) break;
		go(mj);
		if (rem) read_move();
	}

	return 0;
}