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

const int pp = 2062693;

#define x first
#define y second

int n;
i64 k;
i64 a[1024000];
pair<i64, i64> b[1024000];

i64 solve(i64 k)
{
	forn(i, n)
	{
		b[i] = mp(0, a[i]);
	}
	i64 ans = 0;
	i64 total = 0;
	ford(i, 62)
	{
		i64 cnt = 0;
		i64 mask = (-1LL) << (i + 1);
		int p2 = 0;
		forn(p1, n)
		{
			int r = p1;
			i64 cur = a[p1] & mask;
			int cnta[2] = {0, 0};
			int cntb[2] = {0, 0};
			while (r < n && (a[r] & mask) == cur)
			{
				if (a[r] & (1LL << i)) cnta[1]++;
				else cnta[0]++;
				r++;
			}
			r--;
//			int cnt1 = r - p1 + 1;
			while (p2 < n && b[p2].first < cur) p2++;
//			int cnt2 = 0;
			while (p2 < n && b[p2].first == cur)
			{
				if ((b[p2].second ^ cur) & (1LL << i)) cntb[1]++;
				else cntb[0]++;
				p2++;
			}
			p1 = r;
			cnt += cnta[0] * (i64)cntb[0];
			cnt += cnta[1] * (i64)cntb[1];
		}
/*		i64 xx = ans >> i;
		forn(j, pp)
		{
			if (hh[j].x < 0) continue;
			i64 x = hh[j].x ^ xx;
			int tmp = hfind(hh, x);
			cnt += tmp * (i64)hh[j].y;
//			if (total + cnt >= k) break;
		}*/
//		cerr << "cnt=" << cnt << endl;
		if (total + cnt < k)
		{
			total += cnt;
			ans |= 1LL << i;
		}
		forn(l, n)
		{
			int r = l;
			while (r + 1 < n && b[r + 1].first == b[l].first) r++;
			For(m, l, r)
			{
				b[m].first ^= (b[m].second ^ ans) & (1LL << i);
			}
			sort(b + l, b + r + 1, [](const auto &l, const auto &r) { return l.first < r.first; });
			l = r;
		}
	}
//	cerr << "total=" << total << endl;
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#define BIG 1
#endif
	
#ifdef BIG
	scanf("%d%Ld", &n, &k);
	n = 1000000;
	k = n * (i64)n;
#else
	scanf("%d%I64d", &n, &k);
#endif
	a[0] = 0;
	forn(i, n - 1)
	{
		int x;
		i64 y;
#ifdef BIG
		scanf("%d%Ld", &x, &y);
		x = rand() % (i + 1) + 1;
		y = ((i64)rand() << 31) | rand();
#else
		scanf("%d%I64d", &x, &y);
#endif
		x--;
		a[i + 1] = a[x] ^ y;
	}
	sort(a, a + n);

/*	forn(i, n * n)
	{
		cerr << i + 1 << " " << solve(i + 1) << endl;
	}
*/
	i64 ans = solve(k);
	cout << ans << endl;
	
	return 0;
}