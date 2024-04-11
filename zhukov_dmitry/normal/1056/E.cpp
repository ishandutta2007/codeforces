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

const int HS = 2;
int p[HS];
int b[HS];
int pb[1024000][HS];

struct th
{
	int h[HS];

	bool operator == (const th &r) const
	{
		forn(i, HS)
		{
			if (h[i] != r.h[i]) return false;
		}
		return true;
	}
	bool operator != (const th &r) const
	{
		return !(operator == (r));
	}
};

th operator - (const th &l, const th &r)
{
	th res;
	forn(i, HS)
	{
		res.h[i] = l.h[i] - r.h[i];
		if (res.h[i] < 0) res.h[i] += p[i];
//		if (res.h[i] < 0) cerr << l.h[i] << " " << r.h[i] << " " << p[i] << endl;
		assert(res.h[i] >= 0);
	}
	return res;
}

th operator * (const th &l, int k)
{
	th res = l;
	forn(i, HS)
	{
		assert(res.h[i] >= 0);
		res.h[i] = res.h[i] * (i64)pb[k][i] % p[i];
	}
	return res;
}

int n;
char s[102400];
char t[1024000];
th h[1024000];
int sl, tl;

th calc_h(int l, int len)
{
	return (h[l + len] - h[l]) * (tl - l);
}

int pr[] = {100020191, 100020149, 100020121, 100020131, 100020133, 100020103, 100020023, 100120183, 100120159, 100120091, 100120067, 100120037, 100120003};
int ps = sizeof(pr) / sizeof(pr[0]);

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	i64 z = chrono::system_clock::now().time_since_epoch().count();
	srand(z);
	p[0] = pr[rand() % ps];
	do
	{
		p[1] = pr[rand() % ps];
	}
	while (p[0] == p[1]);
//	cerr << p[0] << " " << p[1] << endl;
	b[0] = 239;
	b[1] = 311;
	int c[2] = {};
	scanf("%s", s);
	scanf("%s", t);
	sl = strlen(s);
	tl = strlen(t);
	forn(i, HS)
	{
		pb[0][i] = 1;
	}
	forn(i, tl + 2)
	{
		forn(j, HS)
		{
			pb[i + 1][j] = pb[i][j] * (i64)b[j] % p[j];
		}
	}
	clr(h);
	forn(i, tl)
	{
		h[i + 1] = h[i];
		forn(j, HS)
		{
			h[i + 1].h[j] = (h[i + 1].h[j] + pb[i][j] * (i64)t[i]) % p[j];
		}
	}
/*	{
		th h1 = calc_h(0, 4);
		th h2 = calc_h(4, 4);
		forn(i, HS)
		{
			cerr << h1.h[i] << " " << h2.h[i] << endl;
		}
	}*/
	int f[2] = {-1, -1};
	forn(i, sl)
	{
		int z = s[i] - '0';
		++c[z];
		if (f[z] < 0) f[z] = i;
	}
	char c0 = s[0];
	int ans = 0;
	For(l, 1, tl)
	{
		i64 ll = l * (i64)c[c0 - '0'];
		int z = (c0 - '0') ^ 1;
		if (ll >= tl) continue;
		int rem = tl - ll;
		if (rem % c[z]) continue;
		int l0 = l;
		int l1 = rem / c[z];
		if (c0 == '1') swap(l0, l1);
		int st0 = 0, st1 = 0;
		if (f[0]) st0 = l1 * f[0];
		else st1 = l0 * f[1];
		th h0 = calc_h(st0, l0);
		th h1 = calc_h(st1, l1);
		if (h0 == h1) continue;
		int pos = 0;
		bool ok = true;
		forn(i, sl)
		{
			if (s[i] == '0')
			{
				th curh = calc_h(pos, l0);
				if (curh != h0)
				{
					ok = false;
					break;
				}
				pos += l0;
			}
			else
			{
				th curh = calc_h(pos, l1);
				if (curh != h1)
				{
					ok = false;
					break;
				}
				pos += l1;
			}
			if (!ok) break;
		}
//		cerr << "pos=" << pos << endl;
//		assert(pos == tl);
//		cerr << ok << " " << l0 << " " << l1 << " " << string(t + st0, t + st0 + l0) << " " << string(t + st1, t + st1 + l1) << endl;
		if (ok)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	
	return 0;
}