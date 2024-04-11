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

int n, qq, m;
//vector<int> a[202400];
vector<int> b[202400];
int c[202400];
int ans[202400];
bool u[202400];
int col[202400];
vector<int> comp[202400];
int cs;
pair<int, int> e[202400];

void dfs(int k)
{
	u[k] = true;
	col[k] = cs;
	comp[cs].pb(k);
	for (int v : b[k])
	{
		if (!u[v]) dfs(v);
	}
	int v = c[k];
	if (!u[v]) dfs(v);
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d", &qq);
	while (qq--)
	{
		scanf("%d", &n);
		forn(i, n)
		{
//			a[i].clear();
			b[i].clear();
			comp[i].clear();
			u[i] = false;
		}
		forn(i, n)
		{
			scanf("%d", &c[i]);
			c[i]--;
			b[c[i]].pb(i);
		}
		cs = 0;
		forn(i, n)
		{
			if (!u[i])
			{
				dfs(i);
				cs++;
			}
		}
		
		forn(i, n)
		{
			u[i] = false;
		}
		
		forn(i, cs)
		{
			int z = comp[i].sz;
			int x = comp[i].front();
			forn(tmp, z)
			{
				x = c[x];
			}
			while (!u[x])
			{
				u[x] = true;
				ans[x] = c[x];
				x = c[x];
			}
		}
		m = 0;
		forn(i, cs)
		{
			for (int v : comp[i])
			{
				if (!u[v] && b[v].empty())
				{
					int x = v;
//					while (!u[x])
					for(;;)
					{
						u[x] = true;
						int xn = c[x];
						if (u[xn]) break;
						ans[x] = c[x];
						x = xn;
					}
					e[m++] = mp(v, x);
				}
			}
		}
		
		if (m == 1 && e[0].first == e[0].second)
		{
			int v = e[0].first;
			int st = c[v];
			int x = st;
			while (c[x] != st) x = c[x];
			ans[v] = st;
			ans[x] = v;
		}
		else
		{
			forn(i, m)
			{
				ans[e[i].second] = e[(i + 1) % m].first;
			}
		}
		
		int ac = 0;
		forn(i, n)
		{
			ac += c[i] == ans[i];
		}
		printf("%d\n", ac);
		forn(i, n)
		{
			printf("%d%c", ans[i] + 1, " \n"[i == n - 1]);
		}
	}
	
	return 0;
}