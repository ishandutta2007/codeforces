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

const int MOD = 1000000007;

int n, k;
int a[1024000];
const int z = 1 << 20;
PII t[z * 2];
int pref[1024000];

inline void add(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

inline void sub(int &a, int b)
{
	a -= b;
	if (a < 0) a += MOD;
}

PII tmax(int l, int r)
{
	PII ans = mp(0, 0);
	l += z;
	r += z;
	while (l <= r)
	{
		uax(ans, t[l]);
		uax(ans, t[r]);
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	return ans;
}

int calc_sum(int l, int r)
{
	int ans = pref[r + 1];
	sub(ans, pref[l]);
	return ans;
}

int solve(int l, int r)
{
	if (l > r) return 0;
	PII tmp = tmax(l, r);
	int val = tmp.first;
	int m = tmp.second;

	int ans = 0;
	int pos = m - l;

	add(ans, calc_sum(r - l - pos, r - l));
	sub(ans, calc_sum(0, pos - 1));
//	cerr << m << " " << val << " " << ans << endl;
	ans = ans * (i64)val % MOD;

	add(ans, solve(l, m - 1));
	add(ans, solve(m + 1, r));
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d%d", &n, &k);
	memset(t, 0x80, sizeof(t));
	forn(i, n)
	{
		scanf("%d", &a[i]);
	}
	forn(i, n)
	{
		t[z + i] = mp(a[i], i);
	}
	Ford(i, z - 1, 1)
	{
		t[i] = max(t[i * 2], t[i * 2 + 1]);
	}
	pref[0] = 0;
	forn(i, n + 1)
	{
		pref[i + 1] = pref[i];
		add(pref[i + 1], i / (k - 1));
	}
	int ans = solve(0, n - 1);
	printf("%d\n", ans);
	
	return 0;
}