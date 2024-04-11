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

const i64 INF = 1e18 + 1e16;

int n, m;
i64 k;
string s;
int b[1024][1024];
PII a[1024 * 1024];
i64 d[1024][1024];
i64 sd[1024];

bool cmp(PII x, PII y)
{
	int l = b[x.first][y.first];
	uin(l, x.second);
	uin(l, y.second);
//	cerr << "l = " << l << endl;
	int cx = l < x.second ? s[x.first + l] : 0;
	int cy = l < y.second ? s[y.first + l] : 0;
	return cx < cy;
}

inline void add(i64 &a, i64 b)
{
	a += b;
	uin(a, INF);
}

i64 calc(int q)
{
	clr(d);
	d[0][n] = 1;

	PII x = a[q];
	forn(p, m)
	{
		sd[n] = d[p][n];
		ford(i, n)
		{
			sd[i] = d[p][i];
			add(sd[i], sd[i + 1]);
		}
		ford(i, n)
		{
			PII y = mp(i, n - i);
			int l = b[x.first][i];
			uin(l, x.second);
			int st;
			if (l == x.second)
			{
				st = i + l;
			}
			else
			{
				int cx = l < x.second ? s[x.first + l] : 0;
				int cy = l < y.second ? s[y.first + l] : 0;
				if (cx > cy) continue;
				st = i + l + 1;
			}
/*			if (p == 0)
			{
				cerr << i << " " << st << endl;
			}*/
//			For(j, st, n)
//			{
//				add(d[p + 1][i], d[p][j]);
//			}
//			cerr << "st=" << st << endl;
			add(d[p + 1][i], sd[st]);
		}
	}

//	cerr << s.substr(x.first, x.second) << " " << d[m][0] << endl;
	return d[m][0];
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	cin >> n >> m >> k;
	cin >> s;
	clr(b);
	int t = 0;
	ford(i, n)
	{
		b[i][i] = n - i;
		Ford(j, n - 1, i + 1)
		{
			b[i][j] = b[j][i] = s[i] == s[j] ? b[i + 1][j + 1] + 1 : 0;
		}
	}
/*	forn(i, n)
	{
		forn(j, n)
		{
			cerr << b[i][j] << " ";
		}
		cerr << endl;
	}*/
	forn(i, n)
	{
		For(j, i, n - 1)
		{
			a[t++] = mp(i, j - i + 1);
		}
	}
/*	forn(i, t - 1)
	{
		cerr << s.substr(a[i].first, a[i].second) << " ";
		cerr << (cmp(a[i], a[i + 1]) ? "<" : ">=") << " ";
		cerr << s.substr(a[i + 1].first, a[i + 1].second) << endl;
	}*/
	sort(a, a + t, cmp);
	int tt = 1;
	For(i, 1, t - 1)
	{
		if (cmp(a[tt - 1], a[i])) a[tt++] = a[i];
	}
	t = tt;
	int mi = 0;
	int ma = t - 1;

/*	forn(i, t)
	{
		cerr << s.substr(a[i].first, a[i].second) << endl;
	}
	cerr << endl;
*/
	while (mi < ma)
	{
		int q = (mi + ma + 1) / 2;
		if (calc(q) < k) ma = q - 1;
		else mi = q;
	}

	cout << s.substr(a[mi].first, a[mi].second) << endl;
	
	return 0;
}