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

int n;
int a[1024000];
i64 m;

i64 g(int l, int k)
{
	int ln = l / (k + 1);
	int c1 = l % (k + 1);
	int c0 = k + 1 - c1;
	int ln1 = ln + 1;
	return c0 * sqr<i64>(ln) + c1 * sqr<i64>(ln1);
}

i64 f(int l, int k)
{
	assert(k < l);
	if (k == l - 1) return 0;
	return g(l, k) - g(l, k + 1);
}

pair<i64, int> calc(i64 q)
{
	i64 res = 0;
	int cnt = 0;
	forn(i, n - 1)
	{
		int l = a[i + 1] - a[i];
		if (l == 1)
		{
			res += sqr<i64>(l);
			continue;
		}
		
		int mi = 0;
		int ma = l - 1;
		while (mi < ma)
		{
			int t = (mi + ma) / 2;
			i64 cur = f(l, t);
			if (cur > q) mi = t + 1;
			else ma = t;
		}
//		cerr << "q=" << q << " " << l << " " << mi << " " << f(l, mi) << "\n";
		res += g(l, mi);
		cnt += mi;
	}
	return {res, cnt};
}

int solve(i64 q)
{
	auto [cur, cnt] = calc(q);
	int ans = cnt;
	
	i64 need = cur - m;
//	cerr << "q=" << q << ", ans0=" << ans << ", need=" << need << "\n";
	if (!need) return ans;
	
	ans += (need + q - 1) / q;
	
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d", &n);
	a[0] = 0;
	forn(i, n)
	{
		scanf("%d", &a[i + 1]);
	}
	n++;
	int64_t x;
	scanf("%" PRId64, &x);
	m = x;
	i64 s0 = 0;
	forn(i, n - 1)
	{
		s0 += sqr<i64>(a[i + 1] - a[i]);
	}
//	cerr << "s0=" << s0 << "\n";
	if (s0 <= m)
	{
		puts("0");
		return 0;
	}
	
/*	cerr << f(4, 0) << "\n";
	cerr << f(4, 1) << "\n";
	cerr << f(4, 2) << "\n";
	cerr << f(4, 3) << "\n";
	*/
//	{
//		auto [cur, cnt] = calc(1);
//		cerr << cur << " " << cnt << "\n";
//	}
	
	i64 mi = 0;
	i64 ma = 1000000000000000000;
	while (mi < ma)
	{
		i64 q = midpoint(mi, ma);
		i64 cur = calc(q).first;
		if (cur <= m) mi = q + 1;
		else ma = q;
	}
//	cerr << "mi=" << mi << "\n";
	int ans = solve(mi);
	printf("%d\n", ans);
	
	return 0;
}