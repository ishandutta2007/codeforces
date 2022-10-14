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

const int maxn = 1 << 19;

int n, qq;
int a[maxn];
pair<int, int> t0[maxn * 2];
pair<int, int> ti[maxn * 2];
pair<int, int> ta[maxn * 2];
int b[maxn];
int z;

void tuin(pair<int, int> *t, int x, int k)
{
	int x0 = x;
	x += z;
	while (x)
	{
		if (uin(t[x].first, k)) t[x].second = x0;
		x >>= 1;
	}
}

pair<int, int> tmin(pair<int, int> *t, int l, int r)
{
	pair<int, int> ans(n, n);
	l += z;
	r += z;
	while (l <= r)
	{
		if (l & 1) uin(ans, t[l]);
		if (!(r & 1)) uin(ans, t[r]);
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return ans;
}

void tuax(pair<int, int> *t, int x, int k)
{
	int x0 = x;
	x += z;
	while (x)
	{
		if (uax(t[x].first, k)) t[x].second = x0;
		x >>= 1;
	}
}

pair<int, int> tmax(pair<int, int> *t, int l, int r)
{
	pair<int, int> ans(-1, n);
	l += z;
	r += z;
	while (l <= r)
	{
		if (l & 1) uax(ans, t[l]);
		if (!(r & 1)) uax(ans, t[r]);
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	return ans;
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
			scanf("%d", &a[i]);
			--a[i];
		}
		z = 1;
		while (z < n) z <<= 1;
		memset(t0, 0x3f, z * 2 * sizeof(t0[0]));
		memset(ti, 0x3f, z * 2 * sizeof(ti[0]));
		memset(ta, 0xff, z * 2 * sizeof(ta[0]));
		forn(i, n)
		{
			tuin(ti, i, a[i]);
			tuax(ta, i, a[i]);
		}
		
		tuin(t0, a[n - 1], n - 1);
		ford(i, n - 1)
		{
			if (a[i + 1] > a[i]) b[i] = tmin(t0, 0, a[i] - 1).first;
			else b[i] = tmin(t0, a[i] + 1, n - 1).first;
			tuin(t0, a[i], i);
		}
		int ans = 0;
		int pos = 0;
		while (pos < n - 1)
		{
			if (a[pos + 1] > a[pos]) pos = tmax(ta, pos + 1, b[pos] - 1).second;
			else pos = tmin(ti, pos + 1, b[pos] - 1).second;
			++ans;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}