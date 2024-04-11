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
typedef double ld;
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
int a[102];
int p[102];
int idx[102];
ld c, t;
ld d[102][1024];
ld p9[102];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	int qq;
	scanf("%d", &qq);
	while (qq--)
	{
		scanf("%d", &n);
		scanf("%lf%lf", &c, &t);
		forn(i, n)
		{
			scanf("%d%d", &a[i], &p[i]);
			idx[i] = i;
		}
		p9[0] = 1.0;
		forn(i, 100)
		{
			p9[i + 1] = p9[i] * 0.9;
		}
		sort(idx, idx + n, [](int l, int r) { return a[l] > a[r]; });
		forn(i, n + 1)
		{
			forn(j, 1001)
			{
				d[i][j] = 1e20;
			}
		}
		d[0][0] = 0;
		int ans = 0;
		forn(t1, n)
		{
			int t = idx[t1];
			ford(i, n)
			{
				forn(j, 1001)
				{
					if (d[i][j] > 1e19) continue;
//					uax(d[i + 1][j], d[i][j]);
					uin(d[i + 1][j + p[t]], d[i][j] + a[t] / p9[i + 1]);
				}
			}
		}
		For(i, 1, n)
		{
			forn(j, 1001)
			{
				if (d[i][j] > 1e19) continue;
				ld rem = t - 10.0 * i;
				if (rem < 0) continue;
				ld x = (sqrt(d[i][j] * c) - 1) / c;
				if (x < 0) x = 0;
				ld total = x + d[i][j] / (1.0 + c * x);
//				cerr << i << " " << j << " " << total << " " << rem << " " << x << " " << d[i][j] << endl;
				if (total <= rem)
				{
					uax(ans, j);
				}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}