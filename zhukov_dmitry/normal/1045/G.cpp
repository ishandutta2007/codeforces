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

struct tr
{
	int x, r, s;
};

bool operator < (const tr &l, const tr &r)
{
	return l.r > r.r;
}

int n, k;
tr a[102400];
int z;
int xs[102400];
int xx;
map<int, int> t[1 << 18];

void tadd(int x, int s, int val)
{
	x = lower_bound(xs, xs + xx, x) - xs;
	x += z;
	while (x)
	{
		t[x][s] += val;
		x >>= 1;
	}
}

int tsum(int l, int r, int s)
{
	l = lower_bound(xs, xs + xx, l) - xs;
	r = upper_bound(xs, xs + xx, r) - xs - 1;
	int ans = 0;
	l += z;
	r += z;
	while (l <= r)
	{
		if (l & 1)
		{
			for (auto it = t[l].lower_bound(s - k); it != t[l].end() && it->first <= s + k; ++it)
//			For(i, -k, k)
			{
//				auto it = t[l].find(s + i);
//				if (it == t[l].end()) continue;
				ans += it->second;
			}
		}
		if (!(r & 1))
		{
			for (auto it = t[r].lower_bound(s - k); it != t[r].end() && it->first <= s + k; ++it)
//			For(i, -k, k)
			{
//				auto it = t[r].find(s + i);
//				if (it == t[r].end()) continue;
				ans += it->second;
			}
		}
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d%d", &n, &k);
	forn(i, n)
	{
		scanf("%d%d%d", &a[i].x, &a[i].r, &a[i].s);
	}
#ifdef ROOM_311
	n = 100000;
	k = 20;
	forn(i, n)
	{
		a[i].x = rand() % 1000000001;
		a[i].r = 1000000001 - rand() % 10000;
		a[i].s = 1000000000 - rand() % 2100000;
	}
#endif
	forn(i, n)
	{
		xs[i] = a[i].x;
	}
	sort(xs, xs + n);
	xx = unique(xs, xs + n) - xs;
	z = 1;
	while (z < n) z <<= 1;
	sort(a, a + n);
	i64 ans = 0;
	forn(i, n)
	{
		ans += tsum(a[i].x - a[i].r, a[i].x + a[i].r, a[i].s);
		tadd(a[i].x, a[i].s, 1);
	}
	cout << ans << endl;
	
	return 0;
}