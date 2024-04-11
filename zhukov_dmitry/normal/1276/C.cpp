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

int n;
int a[1024000];
PII e[1024000];
int c[1024000];
int xx[1024000];
int nums[1024000];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	clr(c);
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d", &a[i]);
		xx[i] = a[i];
	}
	sort(xx, xx + n);
	int xs = unique(xx, xx + n) - xx;
	forn(i, n)
	{
		a[i] = lower_bound(xx, xx + xs, a[i]) - xx;
	}
	forn(i, n)
	{
		++c[a[i]];
	}
	forn(i, xs)
	{
		e[i] = mp(c[i], i);
	}
	sort(e, e + xs, greater<PII>());
	int ans = 0;
	int ansh = 0;
	for (int h = 1; h * h <= n; h++)
	{
		int all = n;
		forn(i, xs)
		{
			if (e[i].first > h) all -= e[i].first - h;
			else break;
		}
		int w = all / h;
		if (w < h) continue;
		all = w * h;
		if (all > ans)
		{
//			cerr << all << " " << h << endl;
			ans = all;
			ansh = h;
		}
	}
	printf("%d\n", ans);
//	cerr << "ansh=" << ansh << "\n";
	{
		int h = ansh;
		int all = n;
		forn(i, xs)
		{
			if (e[i].first > h)
			{
				all -= e[i].first - h;
				e[i].first = h;
			}
			else break;
		}
		int w = all / h;
//		cerr << "w=" << w << endl;
		all = w * h;
		vector<vector<int>> u;
		u.resize(h, vector<int>(w, -1));
		assert(all == ans);
		printf("%d %d\n", h, w);
		int x = -1, y = -1;
		auto next = [&] {
			++x;
			if (x == h) x = 0;
			++y;
			if (y == w) y = 0;
			if (u[x][y] != -1)
			{
				++y;
				if (y == w) y = 0;
			}
//			cerr << x << " " << y << endl;
			assert(u[x][y] == -1);
		};

		int z = 0;
		while (all > 0)
		{
			next();
			while (e[z].first == 0) z++;
			e[z].first--;
			int t = xx[e[z].second];
			u[x][y] = t;
			--all;
		}
		forn(i, h)
		{
			forn(j, w)
			{
				printf("%d%c", u[i][j], " \n"[j == w - 1]);
			}
		}
	}
	
	return 0;
}