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
typedef unordered_map<int, int> MLI;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

const int MAXN = 102400;
const int MAXL = 7;

typedef u64 hash_t;

int n, m, k;
char s0[MAXN];
char s[MAXN];
char s2[MAXN];
int p[MAXN];
unordered_map<hash_t, int> hids;
//pair<hash_t, int> vhids[MAXN * (MAXL + 1)];
VI hpos[MAXN * (MAXL + 1)];
VI t[MAXN * (MAXL + 1)];
int tz[MAXN * (MAXL + 1)];
hash_t ph[MAXL + 1];
int ans[102400];
int b[102400][3];
string c[102400];

int get_hid(hash_t h, bool add)
{
	auto it = hids.find(h);
	if (it == hids.end())
		return add ? (hids[h] = k++) : k;
	return it->second;
}

/*int get_hid2(hash_t h)
{
	int idx = lower_bound(vhids, vhids + k, h, [](const pair<hash_t, int> &l, hash_t r) { return l.first < r; }) - vhids;
	if (idx == k || vhids[idx].first != h)
		return k;
	return vhids[idx].second;
}
*/
int get_pos(int tt, int pos)
{
	return lower_bound(all(hpos[tt]), pos) - hpos[tt].begin();
}

void calc_pref(char const *s, int n, int *p)
{
	int q = -1;
	p[0] = -1;
	For(i, 1, n - 1)
	{
		while (q != -1 && s[i] != s[q + 1]) q = p[q];
		if (s[i] == s[q + 1]) q++;
		p[i] = q;
	}
}

int total = 0;

void tadd(int tt, int x, int k)
{
	total++;
	int *ts = t[tt].data();
	int z = tz[tt];
	x += z;
	while (x)
	{
		ts[x] += k;
		x >>= 1;
	}
}

int tsum(int tt, int l, int r)
{
	int *ts = t[tt].data();
	int z = tz[tt];
	int ans = 0;
	l += z;
	r += z;
	while (l <= r)
	{
		if (l & 1) ans += ts[l];
		if (!(r & 1)) ans += ts[r];
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
	return ans;
}

int solve_long(int l, int r, char const *s2, int len)
{
	calc_pref(s2, len, p);
	int q = -1;
	int ans = 0;
	int ma = min(n, r + 1);
	forn(i, ma)
	{
		while (q != -1 && s2[q + 1] != s[i]) q = p[q];
		if (s2[q + 1] == s[i]) q++;
		if (q == len - 1)
		{
			int st = i - len + 1;
			int en = i;
			if (st >= l && en <= r) ans++;
			q = p[q];
		}
	}
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	k = 0;
	ph[0] = 1;
	For(i, 1, MAXL)
	{
		ph[i] = ph[i - 1] * 26;
	}
	scanf("%s", s);
#ifdef ROOM_311
	int nn = 100000;
	forn(i, nn)
	{
		s[i] = 'a' + rand() % 26;
	}
	s[nn] = '\0';
#endif
	n = strlen(s);
	scanf("%d", &m);
#ifdef ROOM_311
	m = 100000;
#endif
	forn(i, m)
	{
		int qt;
#ifdef ROOM_311
		qt = i < 100000 / MAXL ? 2 : 1;
#else
		scanf("%d", &qt);
#endif
		b[i][0] = qt;
		if (qt == 1)
		{
			int pos;
			char cc;
#ifdef ROOM_311
			pos = rand() % n;
			cc = 'a' + rand() % 26;
#else
			scanf("%d %c", &pos, &cc);
			pos--;
#endif
			b[i][1] = pos;
			b[i][2] = cc;
		}
		else
		{
			int l, r;
#ifdef ROOM_311
			l = 0;//rand() % n;
			r = n - 1;
			strncpy(s2, s, MAXL + 1);
#else
			scanf("%d%d%s", &l, &r, s2);
			l--;
			r--;
#endif
			b[i][1] = l;
			b[i][2] = r;
			c[i] = s2;
		}
	}
	strcpy(s0, s);
	For(cur, 1, min(MAXL, n))
	{
		k = 0;
		hids.clear();
//		cerr << "!" << endl;
		strcpy(s, s0);
//		forn(i, z * 2)
//		{
//			t[i].clear();
//		}
		For(j, cur, cur)
		{
			hash_t h = 0;
			forn(i, j)
			{
				h = h * 26 + s[i] - 'a';
			}
			int hi = get_hid(h, true);
			hpos[hi].pb(0);
			For(i, j, n - 1)
			{
				h = h * 26 + s[i] - 'a' - (s[i - j] - 'a')* ph[j];
				hi = get_hid(h, true);
				hpos[hi].pb(i - j + 1);
			}
		}
		forn(i, m)
		{
			int qt = b[i][0];
			if (qt == 1)
			{
				int pos = b[i][1];
				char cc = b[i][2];
				s[pos] = cc;
				For(j, cur, cur)
				{
					int st = max(pos - j + 1, 0);
					if (st + j > n) continue;
					hash_t h = 0;
					forn(q, j)
					{
						h = h * 26 + s[st + q] - 'a';
					}
					int hi = get_hid(h, true);
					hpos[hi].pb(st);
					forn(q, j - 1)
					{
						if (st + j + q >= n) break;
						h = h * 26 + s[st + j + q] - 'a' - (s[st + q] - 'a') * ph[j];
						int hi = get_hid(h, true);
						hpos[hi].pb(st + q + 1);
					}
				}
			}
		}
		forn(i, k)
		{
			sort(all(hpos[i]));
			hpos[i].erase(unique(all(hpos[i])), hpos[i].end());
			tz[i] = 1;
			while (tz[i] < (int)hpos[i].sz) tz[i] <<= 1;
			t[i].resize(tz[i] * 2);
			forn(j, tz[i] * 2)
			{
				t[i][j] = 0;
			}
		}
/*		int kt = 0;
		fori(it, hids)
		{
			vhids[kt++] = *it;
		}
		sort(vhids, vhids + kt);
		assert(kt == k);*/
		
		strcpy(s, s0);
		For(j, cur, cur)
		{
			hash_t h = 0;
			forn(i, j)
			{
				h = h * 26 + s[i] - 'a';
			}
			int hi = get_hid(h, false);
			tadd(hi, get_pos(hi, 0), 1);
			For(i, j, n - 1)
			{
				h = h * 26 + s[i] - 'a' - (s[i - j] - 'a')* ph[j];
				hi = get_hid(h, false);
				tadd(hi, get_pos(hi, i - j + 1), 1);
			}
		}
		forn(i, m)
		{
			int qt = b[i][0];
			if (qt == 1)
			{
				int pos = b[i][1];
				char cc = b[i][2];
				For(j, cur, cur)
				{
					int st = max(pos - j + 1, 0);
					if (st + j > n) continue;
					hash_t h = 0;
					forn(q, j)
					{
						h = h * 26 + s[st + q] - 'a';
					}
					int hi = get_hid(h, false);
					tadd(hi, get_pos(hi, st), -1);
					forn(q, j - 1)
					{
						if (st + j + q >= n) break;
						h = h * 26 + s[st + j + q] - 'a' - (s[st + q] - 'a') * ph[j];
						hi = get_hid(h, false);
						tadd(hi, get_pos(hi, st + q + 1), -1);
					}
				}
				s[pos] = cc;
				For(j, cur, cur)
				{
					int st = max(pos - j + 1, 0);
					if (st + j > n) continue;
					hash_t h = 0;
					forn(q, j)
					{
						h = h * 26 + s[st + q] - 'a';
					}
					int hi = get_hid(h, false);
					tadd(hi, get_pos(hi, st), 1);
					forn(q, j - 1)
					{
						if (st + j + q >= n) break;
						h = h * 26 + s[st + j + q] - 'a' - (s[st + q] - 'a') * ph[j];
						hi = get_hid(h, false);
						tadd(hi, get_pos(hi, st + q + 1), 1);
					}
				}
			}
			else // qt == 2
			{
				int l = b[i][1], r = b[i][2];
				char const *s2 = c[i].c_str();
				int len = c[i].sz;
				if (len > MAXL)
				{
					if (cur == 1) ans[i] = solve_long(l, r, s2, len);
				}
				else if (len == cur)
				{
					hash_t h = 0;
					forn(j, len)
					{
						h = h * 26 + s2[j] - 'a';
					}
					int hi = get_hid(h, false);
					if (hi != k)
					{
						int ll = get_pos(hi, l);
						int rr = upper_bound(all(hpos[hi]), r - len + 1) - hpos[hi].begin() - 1;
						ans[i] = tsum(hi, ll, rr);
					}
				}
			}
		}
		forn(i, k)
		{
			hpos[i].clear();
		}
//		cerr << total << endl;
	}

	forn(i, m)
	{
		int qt = b[i][0];
		if (qt == 2)
			printf("%d\n", ans[i]);
	}
	
	return 0;
}