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

int n, k;
int a[88][88];
int c[88][88];
PII d[88][88][88];
int p[20];

void rec(int s, int m, int *bad, int &ans)
{
	if (s == m)
	{
		int cur = 0;
//		cerr << endl;
		forn(i, m)
		{
			int x = p[i];
			int y = p[i + 1];
			bool ok = false;
//			cerr << "*** " << x << " " << y << " " << c[x][y] << endl;
			forn(j, c[x][y])
			{
				if (!bad[d[x][y][j].second])
				{
					cur += d[x][y][j].first;
//					cerr << d[x][y][j].first << " " << x << " " << d[x][y][j].second << " " << y /*<< " " << bad[d[x][y][j].second]*/ << endl;
					ok = true;
					break;
				}
			}
			if (!ok) return;
			if (cur >= ans) break;
		}
		uin(ans, cur);
/*		if (uin(ans, cur))
		{
			cerr << "!   ";
			forn(i, m + 1)
			{
				cerr << p[i] << " ";
			}
			cerr << endl;
		}*/
		return;
	}
	forn(i, n)
	{
		++bad[i];
		p[s] = i;
		rec(s + 1, m, bad, ans);
		--bad[i];
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d%d", &n, &k);
	int ans = 2e9;
	forn(i, n)
	{
		forn(j, n)
		{
			scanf("%d", &a[i][j]);
		}
	}
/*	n = 80;
	k = 10;
	forn(i, n)
	{
		forn(j, n)
		{
			a[i][j] = 100000000;//rand() % 100000001;
		}
	}*/
	forn(i, n)
	{
		forn(j, n)
		{
			int m = 0;
			forn(l, n)
			{
				if (l == i || l == j) continue;
				d[i][j][m++] = mp(a[i][l] + a[l][j], l);
			}
			c[i][j] = m;
			sort(d[i][j], d[i][j] + m);
		}
	}
	int bad[88] = {};
	p[0] = 0;
	p[k / 2] = 0;
	bad[0]++;
	rec(1, k / 2, bad, ans);

	printf("%d\n", ans);
	
	return 0;
}