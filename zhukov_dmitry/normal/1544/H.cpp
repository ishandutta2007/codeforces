#include <stdio.h>
#include <bits/stdc++.h>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <string_view>
#include <type_traits>
#include <utility>

#ifdef ROOM_311
#define OLYMP_DEBUG
#else
#define OLYMP_NDEBUG
#endif

//#include <olymp/numeric/epsilonized.h>
//#include <olymp/numeric/modular.h>

namespace olymp::utils {

using std::swap;

uint64_t rnd_data = 0xDEADBEEFDULL;
inline void srand(int seed) { rnd_data = ((uint64_t)seed << 16) | 0x330E; }
inline int rand(uint32_t n) { rnd_data = rnd_data * 0x5DEECE66DULL + 0xB; return ((rnd_data >> 17) & 0x7FFFFFFF) % n; }
template <typename T> void random_shuffle(T b, T e) { for (decltype(e - b) i = 1; i < (e - b); ++i) { swap(b[i], b[rand(i + 1)]); } }

}  // namespace olymp::utils

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(std::make_signed_t<std::decay_t<decltype(en)>> i=(st); i<=static_cast<std::make_signed_t<std::decay_t<decltype(en)>>>(en); ++i)
#define Ford(i, st, en) for(std::make_signed_t<std::decay_t<decltype(st)>> i=(st); i>=static_cast<std::make_signed_t<std::decay_t<decltype(st)>>>(en); --i)
#define forn(i, n) for(std::make_signed_t<std::decay_t<decltype(n)>> i=0; i<static_cast<std::make_signed_t<std::decay_t<decltype(n)>>>(n); ++i)
#define ford(i, n) for(auto i=static_cast<std::make_signed_t<std::decay_t<decltype(n)>>>(n)-1; i>=0; --i)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)

#ifdef OLYMP_DEBUG
#ifndef OLYMP_PRINT_EXEC_TIME
#define OLYMP_PRINT_EXEC_TIME 1
#endif
#endif

namespace olymp {

inline clock_t &get_exec_clock_storage()
{
	static clock_t exec_clock_storage;
	return exec_clock_storage;
}

inline clock_t &get_step_clock_storage()
{
	static clock_t step_clock_storage;
	return step_clock_storage;
}

inline void init_exec_time()
{
	auto &t0e = get_exec_clock_storage();
	auto &t0s = get_step_clock_storage();
	t0e = t0s = clock();
}

inline double get_exec_time_ms()
{
	const auto &t0 = get_exec_clock_storage();
	auto t1 = clock();
	return (t1 - t0) * 1000.0 / CLOCKS_PER_SEC;
}

inline double get_step_time_ms()
{
	auto &t0 = get_step_clock_storage();
	auto t1 = clock();
	double result = (t1 - t0) * 1000.0 / CLOCKS_PER_SEC;
	t0 = t1;
	return result;
}

inline void print_step_time([[maybe_unused]] std::string_view step_name = {})
{
#ifdef OLYMP_PRINT_EXEC_TIME
#if OLYMP_PRINT_EXEC_TIME
	if (step_name.empty()) {
		fprintf(stderr, "Step time = %0.0lf ms\n", get_step_time_ms());
	}
	else {
		fprintf(stderr, "Step '");
		fwrite(step_name.data(), 1, step_name.size(), stderr);
		fprintf(stderr, "' time = %0.0lf ms\n", get_step_time_ms());
	}
#endif
#endif
}

inline void print_exec_time()
{
#ifdef OLYMP_PRINT_EXEC_TIME
#if OLYMP_PRINT_EXEC_TIME
	fprintf(stderr, "Execution time = %0.0lf ms\n", get_exec_time_ms());
#endif
#endif
}

__attribute__((constructor)) inline void init_main()
{
	init_exec_time();
}

__attribute__((destructor)) inline void fini_main()
{
	print_exec_time();
}

}  // namespace olymp

using olymp::utils::rand;
using olymp::utils::srand;
using olymp::utils::random_shuffle;

namespace olymp::utils {

template<typename a_t, typename b_t, typename less_t = std::less<a_t>>
inline constexpr std::enable_if_t<
	std::is_same_v<std::common_type_t<a_t, std::decay_t<b_t>>, a_t>,
	bool
> uin(a_t &a, b_t &&b, less_t &&less = less_t())
{
	return less(b, a) ? a = std::forward<b_t>(b), true : false;
}

template<typename a_t, typename b_t, typename less_t = std::less<a_t>>
inline constexpr std::enable_if_t<
	std::is_same_v<std::common_type_t<a_t, std::decay_t<b_t>>, a_t>,
	bool
> uax(a_t &a, b_t &&b, less_t &&less = less_t())
{
	return less(a, b) ? a = std::forward<b_t>(b), true : false;
}

}  // namespace olymp::utils

using namespace olymp;
using namespace std;
using utils::uax;
using utils::uin;

template <class _T> inline _T sqr(const _T &x) { return x * x; }

// Types
using ld = long double;
//using ld = numeric::epsilonized<long double, 9>;
using i64 = int64_t;
using u64 = uint64_t;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

//const int MOD = 1000000007;
//using mint = numeric::modular<MOD>;

const int MAXN = 15240;

const int inf = 0x3f3f3f3f;

#define cerr if (0) cerr

struct tnode
{
	int val{-1};
	int l{-1}, r{-1};
};

int n, qq;
int a[MAXN];
int ra[MAXN];
vector<int> d[MAXN][2];
//vector<array<int, 3>> pa[MAXN][2];
//set<int> t[1 << 15];
int z, h;
int nc = 0;
tnode nodes[MAXN * 30];
int roots[MAXN];

int new_node(int val = -1)
{
	int res = nc++;
	nodes[res] = {val};
	return res;
}

int init_tree()
{
	nc = 0;
	int r = new_node();
	forn(i, h - 1)
	{
		int rn = new_node();
		nodes[rn].l = nodes[rn].r = r;
		r = rn;
	}
	return r;
}

int do_insert(int v, int b, int key, int val)
{
	if (b < 0)
	{
		int vn = new_node(val);
		return vn;
	}
	int vn = new_node();
	nodes[vn] = nodes[v];
	if (key & (1 << b))
	{
		nodes[vn].r = do_insert(nodes[v].r, b - 1, key, val);
	}
	else
	{
		nodes[vn].l = do_insert(nodes[v].l, b - 1, key, val);
	}
	nodes[vn].val = max(nodes[nodes[vn].l].val, nodes[nodes[vn].r].val);
	return vn;
}

int tinsert(int v, int key, int val)
{
	return do_insert(v, h - 2, key, val);
}

int do_tmax(int v, int l, int r, int ll, int rr)
{
	if (l > rr || r < ll) return -1;
	if (l <= ll && rr <= r) return nodes[v].val;
	return max(
		do_tmax(nodes[v].l, l, r, ll, (ll + rr) / 2),
		do_tmax(nodes[v].r, l, r, (ll + rr) / 2 + 1, rr)
	);
}

int total = 0;
int total2 = 0;
int total3 = 0;

const int hs = 23000009;
i64 hh[hs];
int gg[hs];
int pp;

void hclear()
{
	memset(hh, 0xff, pp * sizeof(hh[0]));
}

int *hinsert(i64 key)
{
	int j = key % pp;
	while (hh[j] != -1)
	{
		if (hh[j] == key) return gg + j;
		j += 2;
		if (j >= pp) j -= pp;
	}
	++total3;
	hh[j] = key;
	gg[j] = -2;
	return gg + j;
}

//unordered_map<i64, int> w;

int tmax(int v, int l, int r)
{
	return do_tmax(v, l, r, 0, z - 1);
}

/*inline bool check(const set<int> &s, int mi, int ma)
{
	auto it = s.lower_bound(mi);
	return it != s.end() && *it <= ma;
}
*/
int find_left(int pos, int mi, int ma)
{
	pos--;
	if (pos < 0) return -1;
	i64 h = ((i64)pos * MAXN + mi) * MAXN + ma;
	int *ptr = hinsert(h);
	if (*ptr != -2) return *ptr;
//	auto [it, inserted] = w.emplace(h, -1);
//	if (!inserted) return it->second;
//	w.insert(h);
//	if (w.insert(h).second) return -1;
	return *ptr = tmax(roots[pos], mi, ma);
/*	pos += z;
	while (!check(t[pos], mi, ma))
	{
		if (!(pos & (pos - 1))) return -1;
		pos = (pos - 1) / 2;
	}
	while (pos < z)
	{
		if (check(t[pos * 2 + 1], mi, ma)) pos = pos * 2 + 1;
		else pos *= 2;
	}
	return pos - z;*/
}

bool upd(int st, bool rr, int len, int val, int prev_st, bool prev_rr, int prev_len)
{
	++total2;
	if (rr)
	{
		int pos = ra[val];
		int stv = a[st];
		while ((int)d[pos][rr].size() <= len) d[pos][rr].pb(-1);
//		while ((int)pa[pos][rr].size() <= len) pa[pos][rr].emplace_back();
		if (uax(d[pos][rr][len], stv))
		{
			cerr << "!upd: " << pos << " " << rr << " " << len << " " << stv << "\n";
//			pa[pos][rr][len][0] = prev_st;
//			pa[pos][rr][len][1] = prev_rr;
//			pa[pos][rr][len][2] = prev_len;
			return true;
		}
	}
	else
	{
		while ((int)d[st][rr].size() <= len) d[st][rr].pb(MAXN + 10);
//		while ((int)pa[st][rr].size() <= len) pa[st][rr].emplace_back();
		if (uin(d[st][rr][len], val))
		{
			cerr << "!upd: " << st << " " << rr << " " << len << " " << val << "\n";
//			pa[st][rr][len][0] = prev_st;
//			pa[st][rr][len][1] = prev_rr;
//			pa[st][rr][len][2] = prev_len;
			return true;
		}
	}
	return false;
}

int solve(bool skip_last)
{
	int ans = 0;
	forn(i, n)
	{
		forn(j, 2)
		{
			d[i][j].clear();
//			pa[i][j].clear();
		}
	}
	if (skip_last)
	{
		ford(i, n - 1)
		{
			upd(i, 0, 1, a[i], -1, -1, -1);
			upd(i, 1, 1, a[i], -1, -1, -1);
		}
	}
	else
	{
		upd(n - 1, 0, 0, a[n - 1], -1, -1, -1);
		upd(n - 1, 1, 0, a[n - 1], -1, -1, -1);
	}
	ford(i, n)
	{
		forn(rr, 2)
		{
			forn(len, d[i][rr].sz)
			{
				total++;
				int lpos;
//				int rpos;
				int lv, rv;
				if (rr)
				{
					rv = a[i];
					lv = d[i][rr][len];
					lpos = ra[lv];
//					rpos = i;
				}
				else
				{
					lv = a[i];
					rv = d[i][rr][len];
					lpos = i;
//					rpos = ra[rv];
				}
				if (lv < 0 || rv >= MAXN) continue;
//				for (int rv : d[i][rr][len])
				{
					cerr << "?? " << i << " " << rr << " " << len << " " << lv << " " << rv << "\n";
//					assert(rv < MAXN);
					// same rr
					if (rr)
					{
						int mi = rv + 1, ma = n - 1, pos = ra[rv];
						for (;;)
						{
							int np = find_left(pos, mi, ma);
							if (np < 0) break;
							cerr << "!1 " << i << " " << rr << " " << len << " " << rv << " " << pos << "->" << np << "\n";
							pos = np;
							upd(lpos, true, len + 1, a[pos], i, rr, len);
							ma = a[pos] - 1;
						}
					}
					else
					{
						int mi = 0, ma = lv - 1, pos = i;
						for (;;)
						{
							int np = find_left(pos, mi, ma);
							if (np < 0) break;
							cerr << "!2 " << i << " " << rr << " " << len << " " << rv << " " << pos << "->" << np << "\n";
							pos = np;
							upd(pos, false, len + 1, rv, i, rr, len);
							mi = a[pos] + 1;
						}
					}
					
					// change rr
					if (rr)
					{
						int mi = 0, ma = lv - 1, pos = ra[rv] - len;
						for (;;)
						{
							int np = find_left(pos, mi, ma);
							if (np < 0) break;
							cerr << "!3 " << i << " " << rr << " " << len << " " << rv << " " << pos << "->" << np << "\n";
							pos = np;
							upd(pos, false, len + 1, rv, i, rr, len);
							mi = a[pos] + 1;
						}
					}
					else
					{
						int mi = rv + 1, ma = n - 1, pos = i - len;
						for (;;)
						{
							int np = find_left(pos, mi, ma);
							if (np < 0) break;
							cerr << "!4 " << i << " " << rr << " " << len << " " << rv << " " << pos << "->" << np << "\n";
							pos = np;
							upd(lpos, true, len + 1, a[pos], i, rr, len);
							ma = a[pos] - 1;
						}
					}
				}
			}
		}
	}
//	int xi = 0, xrr = 0, xlen = 0;
	forn(i, n)
	{
		forn(j, 2)
		{
			if (uax(ans, (int)d[i][j].size() - skip_last))
			{
//				xi = i;
//				xrr = j;
//				xlen = d[i][j].size() - 1;
			}
		}
	}
	// print path
/*	cerr << "n=" << n << "\n";
	forn(i, n)
	{
		cerr << a[i] << " ";
	}
	cerr << "\n";
	while (xi != -1)
	{
		cerr << xi << "(val=" << a[xi] << ") " << (xrr ? "right" : "left") << " cnt=" << xlen + 1 - skip_last << " " << d[xi][xrr][xlen] << "\n";
		int yi = pa[xi][xrr][xlen][0];
		int yrr = pa[xi][xrr][xlen][1];
		int ylen = pa[xi][xrr][xlen][2];
		xi = yi;
		xrr = yrr;
		xlen = ylen;
	}*/
	return ans;
}

int main(int argc, char **argv)
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#define BIG 1
#endif
	
#ifdef BIG
	int counter = 1;
#endif
	scanf("%d", &qq);
	while (qq--)
	{
#ifdef BIG
		n = 16;
		if (argc > 1) sscanf(argv[1], "%d", &n);
		forn(i, n)
		{
			a[i] = i;
		}
		utils::random_shuffle(a, a + n);
		if (0 && counter == 21)
		{
			fprintf(stderr, "%d\n", n);
			forn(i, n)
			{
				fprintf(stderr, "%d%c", a[i] + 1, " \n"[i == n - 1]);
			}
		}
		counter++;
#else
		scanf("%d", &n);
#endif
		forn(i, n)
		{
#ifndef BIG
			scanf("%d", &a[i]);
			a[i]--;
#endif
			ra[a[i]] = i;
		}
		nc = 0;
		z = 1;
		h = 1;
		while (z < n) z <<= 1, h++;
/*		forn(i, z * 2)
		{
			t[i].clear();
		}
		forn(i, n)
		{
			int x = i + z;
			while (x)
			{
				t[x].insert(a[i]);
				x /= 2;
			}
		}*/
		int r = init_tree();
		forn(i, n)
		{
			r = tinsert(r, a[i], i);
			roots[i] = r;
		}
		total = 0;
		total2 = 0;
		total3 = 0;
//		w.clear();
		pp = hs / 15000 * n;
		pp |= 1;
		hclear();
//		w.reserve(12000000);
		int ans = solve(0);
		uax(ans, solve(1));
#ifdef ROOM_311
		fprintf(stderr, "total=%d\n", total);
		fprintf(stderr, "total2=%d\n", total2);
		fprintf(stderr, "total3=%d\n", total3);
#endif
		printf("%d\n", ans);
	}
	
	return 0;
}