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

#define x first
#define y second

int n, m;
char s[102400];
int b[102400][2];
int dl[102400][26];
int dr[102400][26];
VI pos[26];
VI tx[26];
VI stx[26];
int zx[26];
vector<PII> sq;
int nextc[102400][26];
int prevc[102400][26];
int idx[102400];

inline void tadd(int j, int x, int k)
{
	x += zx[j];
	while (x)
	{
		tx[j][x] ^= k;
		x >>= 1;
	}
}

inline int txor(int j, int l, int r)
{
	int ans = 0;
	l += zx[j];
	r += zx[j];
	while (l <= r)
	{
		if (l & 1) ans ^= tx[j][l];
		if (!(r & 1)) ans ^= tx[j][r];
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	return ans;
}

inline int txorf(int j, int l, int r)
{
	return stx[j][r + 1] ^ stx[j][l];
}

int solvel(int l, int j, bool calc_tadd = false);
int solver(int r, int j, bool calc_tadd = false);

int solve0(int l, int r, bool calc_tadd = false, bool fastx = false)
{
	if (r < l) return 0;
	int u = 0;
	forn(i, 26)
	{
		int xpos = nextc[l][i];
		if (xpos >= n) continue;
		int x = idx[xpos];
		if (pos[i][x] > r) continue;
		int ypos = prevc[r][i];
		int y = idx[ypos];

		int cur = fastx ? txorf(i, x, y - 1) : txor(i, x, y - 1);
		cur ^= solvel(l, i, calc_tadd);
		cur ^= solver(r, i, calc_tadd);

		u |= 1 << cur;
	}

	forn(i, 30)
	{
		if (!(u & (1 << i)))
		{
			if (l > 0 && r < n - 1 && s[l - 1] == s[r + 1] && calc_tadd)
			{
				int ch = s[l - 1] - 'a';
				int x = idx[l - 1];
				if (pos[ch][x + 1] == r + 1) tadd(ch, x, i);
			}
			return i;
		}
	}
	assert(false);
	return -1;
}

int solvel(int l, int j, bool calc_tadd/* = false*/)
{
	int &ans = dl[l][j];
	if (ans >= 0) return ans;
	int posj = nextc[l][j];
	int x = posj == n ? pos[j].sz - 1 : idx[posj];
	int r = pos[j][x] - 1;
	if (r < l)
	{
		return ans = 0;
	}

	return ans = solve0(l, r, calc_tadd);
}

int solver(int r, int j, bool calc_tadd/* = false*/)
{
	int &ans = dr[r][j];
	if (ans >= 0) return ans;
	int posj = prevc[r][j];
	int x = posj == -1 ? 0 : idx[posj];
	int l = pos[j][x] + 1;
	if (r < l)
	{
		return ans = 0;
	}

	return ans = solve0(l, r, calc_tadd);
}

void precalc()
{
	ford(i, n)
	{
		forn(j, 26)
		{
			solvel(i, j);
		}
	}
	forn(i, n)
	{
		forn(j, 26)
		{
			solver(i, j);
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	memset(dl, 0xff, sizeof(dl));
	memset(dr, 0xff, sizeof(dr));
	scanf("%s", s);
	n = strlen(s);
#ifdef ROOM_311
	n = 100000;
	forn(i, n)
	{
		s[i] = rand() % 26 + 'a';
	}
#endif
	forn(i, 26)
	{
		pos[i].pb(-1);
	}
	forn(i, n)
	{
		int x = s[i] - 'a';
		pos[x].pb(i);
		idx[i] = pos[x].sz - 1;
	}
	forn(i, 26)
	{
		pos[i].pb(n);
	}
	forn(j, 26)
	{
		nextc[n][j] = n;
		ford(i, n)
		{
			nextc[i][j] = s[i] == 'a' + j ? i : nextc[i + 1][j];
		}
	}
	forn(j, 26)
	{
		prevc[0][j] = s[0] == 'a' + j ? 0 : -1;
		For(i, 1, n)
		{
			prevc[i][j] = s[i] == 'a' + j ? i : prevc[i - 1][j];
		}
	}

	forn(i, 26)
	{
		zx[i] = 1;
		while ((int)pos[i].sz > zx[i]) zx[i] <<= 1;
		tx[i].resize(zx[i] * 2, 0);
	}

	scanf("%d", &m);
	forn(i, m)
	{
		scanf("%d%d", &b[i][0], &b[i][1]);
		b[i][0]--;
		b[i][1]--;
	}
#ifdef ROOM_311
	m = 100000;
	forn(i, m)
	{
		b[i][0] = rand() % n;
		b[i][1] = rand() % n;
		sort(b[i], b[i] + 2);
	}
#endif
	forn(i, 26)
	{
		forn(j, pos[i].sz - 1)
		{
			if (pos[i][j] + 1 <= pos[i][j + 1] - 1) sq.pb(mp(pos[i][j] + 1, pos[i][j + 1] - 1));
		}
	}

	sort(all(sq), [](PII l, PII r) { return l.y - l.x < r.y - r.x; });
	for (auto &qq : sq)
	{
		solve0(qq.x, qq.y, true);
	}
//	precalc();

	forn(i, 26)
	{
		stx[i].resize(pos[i].sz + 1);
		stx[i][0] = 0;
		forn(j, pos[i].sz)
		{
			stx[i][j + 1] = stx[i][j] ^ tx[i][zx[i] + j];
		}
	}

	forn(i, m)
	{
		puts(solve0(b[i][0], b[i][1], false, true) ? "Alice" : "Bob");
	}
	
	return 0;
}