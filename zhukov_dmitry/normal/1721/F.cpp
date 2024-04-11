#include <stdio.h>
#include <bits/stdc++.h>
#include <cstdint>
#include <ctime>
#include <functional>
#include <limits>
#include <random>
#include <string_view>
#include <type_traits>
#include <utility>

#ifdef ROOM_311
#	ifndef OLYMP_DEBUG
#		define OLYMP_DEBUG
#	endif
#else
#	define OLYMP_NDEBUG
#endif

//#include <olymp/geometry/point.h>
//#include <olymp/numeric/epsilonized.h>
//#include <olymp/numeric/modular.h>

#ifdef OLYMP_DEBUG
#ifndef OLYMP_PRINT_EXEC_TIME
#define OLYMP_PRINT_EXEC_TIME 1
#endif
#endif

namespace olymp::utils {

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

}  // namespace olymp::utils

namespace olymp::utils {

class rnd_t {
public:
	template<typename int_t = int>
	int_t get()
	{
		if constexpr (gen_.max() >= std::numeric_limits<int_t>::max()) {
			return gen_() & std::numeric_limits<int_t>::max();
		}
		else {
			std::uniform_int_distribution<int_t> d(0, std::numeric_limits<int_t>::max());
			return d(gen_);
		}
	}
	
	template<typename int_t = int>
	int_t operator () ()
	{
		return get<int_t>();
	}
	
	template<typename int_t>
	int_t operator () (int_t n)
	{
		std::uniform_int_distribution<int_t> d(0, n - 1);
		return d(gen_);
	}
	
	template<typename int_l_t, typename int_r_t>
	std::common_type_t<int_l_t, int_r_t> operator () (int_l_t l, int_r_t r)
	{
		std::uniform_int_distribution<std::common_type_t<int_l_t, int_r_t>> d(l, r);
		return d(gen_);
	}
	
	template<typename int_t>
	void seed(int_t &&value)
	{
		gen_.seed(std::forward<int_t>(value));
	}
	
	std::mt19937 &gen() { return gen_; }
	
	template<typename it_t>
	void shuffle(it_t b, it_t e)
	{
		std::shuffle(b, e, gen());
	}
	
	template<typename int_t>
	void discard(int_t n)
	{
		gen_.discard(n);
	}

private:
	std::mt19937 gen_{311311311};
};

#ifdef OLYMP_USE_MT
thread_local
#endif
static inline rnd_t rnd;

}  // namespace olymp::utils

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

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) std::begin(x), std::end(x)
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(std::make_signed_t<std::decay_t<decltype(en)>> i=(st); i<=static_cast<std::make_signed_t<std::decay_t<decltype(en)>>>(en); ++i)
#define Ford(i, st, en) for(std::make_signed_t<std::decay_t<decltype(st)>> i=(st); i>=static_cast<std::make_signed_t<std::decay_t<decltype(st)>>>(en); --i)
#define forn(i, n) for(std::make_signed_t<std::decay_t<decltype(n)>> i=0; i<static_cast<std::make_signed_t<std::decay_t<decltype(n)>>>(n); ++i)
#define ford(i, n) for(auto i=static_cast<std::make_signed_t<std::decay_t<decltype(n)>>>(n)-1; i>=0; --i)

using olymp::utils::print_step_time;
using olymp::utils::print_exec_time;
using olymp::utils::rnd;

template <class _T> inline _T sqr(const _T &x) { return x * x; }

namespace olymp {

__attribute__((constructor)) inline void init_main()
{
	utils::init_exec_time();
}

__attribute__((destructor)) inline void fini_main()
{
	utils::print_exec_time();
}

}  // namespace olymp

using namespace olymp;
using namespace std;
using utils::uax;
using utils::uin;

// Types
using ld = long double;
//using ed = numeric::epsilonized<ld, 9>;
using i64 = long long;
using u64 = unsigned long long;
//using tp = geometry::point<int>;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

//const int MOD = 1000000007;
//const int MOD = 998244353;
//using mint = numeric::modular<MOD>;

#define MAXN 200020
#define MAXE 200020

int n, m, k;
int a[MAXE];
int as[MAXN];
int b[MAXE];
int bs[MAXN];
int e[MAXE][2];
int pa[MAXN];
int p1[MAXN];
bool ul[MAXN];
bool u[MAXN];
int cl[MAXN];
int cr[MAXN];
bool u2[2][MAXN];

int hs;
int h[MAXN];
int pos[MAXN];

set<int> gl;
set<int> gr;

void heapify(int k)
{
	int l = k * 2 + 1;
	int r = k * 2 + 2;
	int m = k;
	if (l < hs && cl[h[l]] < cl[h[m]]) m = l;
	if (r < hs && cl[h[r]] < cl[h[m]]) m = r;
	if (m != k)
	{
		swap(h[m], h[k]);
		pos[h[m]] = m;
		pos[h[k]] = k;
		heapify(m);
	}
}

void lift(int k)
{
	int tmp = h[k];
	int j = k;
	while (j && cl[tmp] < cl[h[(j-1)/2]])
	{
		h[j] = h[(j-1)/2];
		pos[h[j]] = j;
		j = (j-1)/2;
	}
	if (j != k)
	{
		h[j] = tmp;
		pos[h[j]] = j;
	}
}

void precalc(int &ans)
{
	clr(cl);
	clr(cr);
	forn(i, k)
	{
		cl[e[i][0]]++;
		cr[e[i][1]]++;
	}
	hs = 0;

	forn(i, n)
	{
		pos[i] = hs;
		h[hs++] = i;
	}
	ford(i, (hs+1) / 2)
	{
		heapify(i);
	}

	while (hs)
	{
		int v = h[0];
		h[0] = h[--hs];
		pos[h[0]] = 0;
		heapify(0);
		int mi = 1000000000;
		int mj = -1;
		For(j1, as[v], as[v+1]-1)
		{
			int j = a[j1];
			if (pa[j] != -1) continue;
			if (cr[j] < mi)
			{
				mi = cr[j];
				mj = j;
			}
		}
		if (mj != -1)
		{
			pa[mj] = v;
			ul[v] = true;
			ans++;
			For(j1, as[v], as[v+1]-1)
			{
				int j = a[j1];
				cr[j]--;
			}
			For(j1, bs[mj], bs[mj+1]-1)
			{
				int j = b[j1];
				if (ul[j]) continue;
				cl[j]--;
				lift(pos[j]);
			}
		}
	}
}

bool find(int k)
{
	u[k] = true;
	For(i1, as[k], as[k+1]-1)
	{
		int i = a[i1];
		if (pa[i] == -1 || (!u[pa[i]] && find(pa[i])))
		{
			pa[i] = k;
			ul[k] = true;
			return true;
		}
	}
	return false;
}

set<int> sa[MAXN];
set<int> sb[MAXN];

void dfs(int v)
{
	if (u2[0][v]) return;
	u2[0][v] = true;
	for (int i : sa[v])
	{
		u2[1][i] = true;
		//if (pa[i] < 0) for(;;);
		assert(pa[i] >= 0);
		dfs(pa[i]);
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	map<pair<int, int>, int> em;
	int q;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	clr(as);
	clr(bs);
	forn(i, k)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		e[i][0] = x;
		e[i][1] = y;
		em[mp(x, y)] = i;
		as[x]++;
		bs[y]++;
	}
	for(int sum = 0, i = 0; i < n; i++)
	{
		int tmp = as[i];
		as[i] = sum;
		sum += tmp;
	}
	for(int sum = 0, i = 0; i < m; i++)
	{
		int tmp = bs[i];
		bs[i] = sum;
		sum += tmp;
	}
	forn(i, k)
	{
		int x = e[i][0];
		int y = e[i][1];
		a[as[x]++] = y;
		b[bs[y]++] = x;
	}
	ford(i, n)
	{
		as[i+1] = as[i];
	}
	as[0] = 0;
	ford(i, m)
	{
		bs[i+1] = bs[i];
	}
	bs[0] = 0;

	memset(pa, 0xff, sizeof(pa));
	clr(ul);
	int ans = 0;
	precalc(ans);
	clr(u);
	forn(i, n)
	{
		if (ul[i]) continue;
		if (find(i))
		{
			ans++;
			clr(u);
		}
	}
	i64 sum = 0;
	forn(i, m)
	{
		if (pa[i] >= 0)
		{
			int l = pa[i];
			int r = i;
			int z = em.at(mp(l, r));
			sum += z + 1;
			//cerr << "+: " << z + 1 << "\n";
		}
	}
	
	memset(p1, 0xff, sizeof(p1));
	forn(i, m)
	{
		if (pa[i] >= 0) p1[pa[i]] = i;
	}
	
//	printf("%d\n", ans);
	forn(i, n)
	{
		if (!ul[i]) gl.insert(i);
	}
	forn(i, m)
	{
		if (pa[i] < 0) gr.insert(i);
	}
	forn(i, n)
	{
		For(j1, as[i], as[i + 1] - 1)
		{
			int j = a[j1];
			sa[i].insert(j);
		}
	}
	forn(i, m)
	{
		For(j1, bs[i], bs[i + 1] - 1)
		{
			int j = b[j1];
			sb[i].insert(j);
		}
	}
	
	clr(u2);
	forn(i, n)
	{
		if (!ul[i] && !u2[0][i])
		{
			dfs(i);
		}
	}
	
	vector<int> ansv;
	forn(i, n)
	{
		if (!u2[0][i])
		{
			ansv.pb(i + 1);
		}
	}
	forn(i, m)
	{
		if (u2[1][i])
		{
			ansv.pb(-(i + 1));
		}
	}
	assert(int(ansv.size()) == ans);
	
	int pos = 0;
	forn(i, q)
	{
		int tt;
		scanf("%d", &tt);
		if (tt == 1)
		{
			--ans;
			puts("1");
			
			assert(pos < (int)(ansv.size()));
			int cur = ansv[pos++];
			printf("%d\n", cur);
			if (cur > 0)
			{
				int v = cur - 1;
				int l = v;
				int r = p1[v];
				int z = em.at(mp(l, r));
				pa[r] = -1;
				p1[l] = -1;
				ul[l] = false;
				//cerr << "-: " << z + 1 << "\n";
				sum -= z + 1;
			}
			else
			{
				int v = -cur - 1;
				int l = pa[v];
				int r = v;
				int z = em.at(mp(l, r));
				pa[r] = -1;
				p1[l] = -1;
				ul[l] = false;
				//cerr << "-: " << z + 1 << "\n";
				sum -= z + 1;
			}
			
			printf("%" PRId64 "\n", int64_t(sum));
		}
		else
		{
			printf("%d\n", ans);
			bool f = true;
			forn(i, m)
			{
				if (pa[i] >= 0)
				{
					int l = pa[i];
					int r = i;
					int z = em.at(mp(l, r));
					if (f) f = false;
					else putchar(' ');
					printf("%d", z + 1);
				}
			}
			puts("");
		}
		fflush(stdout);
	}

	return 0;
}