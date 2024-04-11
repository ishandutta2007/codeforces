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

char s1[202400];
char s2[202400];
int k[2][2];
int sk;
int f[202400];
int rf[202400];

inline int calc_c(int n, int k)
{
	if (!k) return 1 % MOD;
	if (n < k) return 0;
	return f[n] * (i64)rf[k] % MOD * (i64)rf[n - k] % MOD;
}

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

int modpow(int a, int k)
{
	if (!k) return 1 % MOD;
	int ans = modpow(a, k / 2);
	ans = ans * (i64)ans % MOD;
	if (k & 1) ans = ans * (i64)a % MOD;
	return ans;
}

int solve(char *s)
{
	int len = strlen(s);
//	cerr << len << " " << sk+1 << endl;
	if (sk + 1 > len) return 0;
	if (k[1][0] < k[0][1] || k[1][0] > k[0][1] + 1) return 0;
	if (sk + 1 < len)
	{
//		cerr << "k10 = " << k[1][0] << endl;
//		cerr << "k00 = " << k[0][0] << endl;
//		cerr << calc_c(k[1][0] + k[0][0] - 1, k[0][0]) << " " << calc_c(k[0][1] + k[1][1], k[1][1]) << endl;
		return calc_c(k[1][0] + k[0][0] - 1, k[0][0]) * (i64)calc_c(k[0][1] + k[1][1], k[1][1]) % MOD;
	}
//	cerr << "!" << endl;
	int curk[2][2] = {};
//	clr(curk);
	int ans = 0;
	For(i, 1, len - 1)
	{
		int prev = s[i - 1] - '0';
		if (s[i] == '1')
		{
			++curk[prev][0];
			bool ok = true;
			forn(l, 2)
			{
				forn(r, 2)
				{
					ok = ok && curk[l][r] <= k[l][r];
				}
			}
			if (ok)
			{
				add(ans, calc_c(k[0][1] - curk[0][1] + k[1][1] - curk[1][1] - 1, k[1][1] - curk[1][1]) *
					(i64)calc_c(k[1][0] - curk[1][0] + k[0][0] - curk[0][0], k[0][0] - curk[0][0]) % MOD);
			}
			--curk[prev][0];
		}
		int cur = s[i] - '0';
		++curk[prev][cur];
	}
	bool ok = true;
	forn(l, 2)
	{
		forn(r, 2)
		{
			ok = ok && curk[l][r] == k[l][r];
		}
	}
	if (ok) add(ans, 1);
	return ans;
}

int solve(char *s1, char *s2)
{
	int ans = 0;
	int l = strlen(s1) - 1;
	while (l >= 0 && s1[l] == '0') s1[l--] = '1';
	s1[l] = '0';
	int st = 0;
	if (l == 0) st = 1;
	sub(ans, solve(s1 + st));
	add(ans, solve(s2));
	return ans;
}

int dull(const char *s1, const char *s2)
{
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int mi = 0, ma = 0;
	forn(i, l1)
	{
		mi = mi * 2 + s1[i] - '0';
	}
	forn(i, l2)
	{
		ma = ma * 2 + s2[i] - '0';
	}
	int ans = 0;
	For(m, mi, ma)
	{
		int t[2][2] = {};
		int x = m;
		int prev = x & 1;
		x >>= 1;
		while (x)
		{
			int cur = x & 1;
			++t[cur][prev];
			prev = cur;
			x >>= 1;
		}
		bool ok = true;
		forn(l, 2)
		{
			forn(r, 2)
			{
				ok = ok && t[l][r] == k[l][r];
			}
		}
		if (ok) ans++;
	}
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	f[0] = 1;
	rf[0] = 1;
	forn(i, 200001)
	{
		f[i + 1] = f[i] * (i64)(i + 1) % MOD;
		rf[i + 1] = modpow(f[i + 1], MOD - 2);
	}

	scanf("%s", s1);
	scanf("%s", s2);
	sk = 0;
	forn(i, 2)
	{
		forn(j, 2)
		{
			scanf("%d", &k[i][j]);
			sk += k[i][j];
		}
	}
//	int d = dull(s1, s2);
//	cerr << d << endl;
	int ans = solve(s1, s2);
//	assert(d == ans);
	printf("%d\n", ans);
	
	return 0;
}