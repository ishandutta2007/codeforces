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
i64 a[512];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif

	const int MOD = 998244353;
	
	cin >> n;
	map<i64, int> w;
	forn(i, n)
	{
		i64 x;
		cin >> x;
		a[i] = x;
	}
	set<i64> divs;
	forn(i, n)
	{
		i64 x = a[i];
		if (x == 1) continue;
		Ford(j, 4, 2)
		{
			i64 y = (i64)(pow(x, 1.0 / j) + 0.5);
			i64 z = 1;
			forn(t, j)
			{
				z *= y;
			}
			if (z == x)
			{
				w[y] += j;
				divs.insert(y);
				x = 1;
				break;
			}
		}
		a[i] = x;
	}
	forn(i, n)
	{
		i64 x = a[i];
		if (x == 1) continue;
		For(j, i + 1, n)
		{
			i64 g = __gcd(x, a[j]);
			if (g > 1 && g != x)
			{
				divs.insert(g);
			}
		}
	}
	for (i64 d : divs)
	{
		forn(j, n)
		{
			if (a[j] > 1 && a[j] % d == 0)
			{
				w[d]++;
				w[a[j] / d]++;
				a[j] = 1;
			}
		}
	}
/*	forn(i, n)
	{
		i64 x = a[i];
		if (x == 1) continue;
		i64 d = 1;
		For(j, i + 1, n)
		{
			i64 g = __gcd(x, a[j]);
			if (g > 1 && g != x)
			{
				d = g;
				break;
			}
		}
		if (d > 1)
		{
			forn(j, n)
			{
				if (a[j] > 1 && a[j] % d == 0)
				{
					w[d]++;
					w[a[j] / d]++;
					a[j] = 1;
				}
			}
		}
	}
*/
	i64 ans = 1;
	for(auto p : w)
	{
//		cerr << p.first << " " << p.second << endl;
		ans = ans * (i64)(p.second + 1) % MOD;
	}
	forn(i, n)
	{
		if (a[i] > 1)
		{
			int cnt = 1;
			For(j, i + 1, n - 1)
			{
				if (a[i] == a[j])
				{
					a[j] = 1;
					cnt++;
				}
			}
			ans = ans * (i64)(cnt + 1) * (cnt + 1) % MOD;
		}
	}
	cout << ans << endl;
	
	return 0;
}