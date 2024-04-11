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
const size_t LIM = 300;

int n;
ld p[MAXN];
VI a[MAXN];
VI al[MAXN];
VI ah[MAXN];
ld s[MAXN];
ld sh[MAXN];
bool hv[MAXN];

void precalc()
{
	forn(i, n)
	{
		s[i] = 0.0;
		for(int vn : al[i])
		{
			s[i] += p[vn];
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d", &n);
	forn(i, n)
	{
		double x;
		scanf("%lf", &x);
		p[i] = x;
	}
	forn(i, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].pb(y);
		a[y].pb(x);
	}
	forn(i, n)
	{
		hv[i] = a[i].sz > LIM;
		sh[i] = 0.0;
	}
	forn(i, n)
	{
		for(int vn : a[i])
		{
			if (hv[vn])
			{
				ah[i].pb(vn);
			}
			else
			{
				al[i].pb(vn);
			}
		}
	}
	precalc();
	forn(i, n)
	{
		if (hv[i])
		{
			for (auto vn : a[i])
			{
				sh[i] += 1.0 - p[vn];
			}
		}
	}
	int m;
	scanf("%d", &m);
	ld spall = 0.0;
	forn(i, n)
	{
		spall += p[i];
	}
	ld sumprev = 0.0;
	forn(j, n)
	{
//		for (int vn : a[j])
//		{
//			sumprev += p[j] + p[vn] - p[j] * p[vn];
//		}
		sumprev += a[j].sz * p[j];
		sumprev += (1.0 - p[j]) * s[j];
		sumprev += p[j] * sh[j];
	}
//	cerr << sumprev << endl;
	forn(i, m)
	{
		int x;
		double y;
		scanf("%d%lf", &x, &y);
		spall -= p[x];
		sumprev -= a[x].sz * p[x] + (1.0 - p[x]) * s[x] + p[x] * sh[x];

		if (!hv[x])
		{
			for (int vn : a[x])
			{
				sumprev -= (1.0 - p[vn]) * s[vn];
				s[vn] -= p[x];
			}
		}
		for (auto vn : ah[x])
		{
			sumprev -= p[vn] * sh[vn];
			sh[vn] -= 1.0 - p[x];
		}
		p[x] = y;
		for (auto vn : ah[x])
		{
			sh[vn] += 1.0 - p[x];
			sumprev += p[vn] * sh[vn];
		}
		if (!hv[x])
		{
			for (int vn : a[x])
			{
				s[vn] += p[x];
				sumprev += (1.0 - p[vn]) * s[vn];
			}
		}
		spall += p[x];
//		precalc();
		sumprev += a[x].sz * p[x] + (1.0 - p[x]) * s[x] + p[x] * sh[x];
		ld ans = 2.0 + sumprev;
/*		forn(j, n)
		{
//			for (int vn : a[j])
//			{
//				ans += p[j] + p[vn] - p[j] * p[vn];
//			}
			ans += a[j].sz * p[j] + (1.0 - p[j]) * s[j];
		}*/
		ans -= spall * 2.0;
		ans /= 2.0;
		printf("%0.9f\n", (double)ans);
	}
	
	return 0;
}