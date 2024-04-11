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

struct tp{int x, y;};

tp a[3];
int xs[3];
int ys[3];
int xx, yy;
bool bh[3][2];
bool bv[2][3];
vector<pair<tp, tp>> pans;
bool d[9][9];

i64 dist(tp p1, tp p2)
{
	return abs(p1.x - p2.x) + i64(abs(p1.y - p2.y));
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	xx = 0;
	yy = 0;
	forn(i, 3)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		xs[xx++] = a[i].x;
		ys[yy++] = a[i].y;
	}
	sort(xs, xs + xx);
	xx = unique(xs, xs + xx) - xs;
	sort(ys, ys + yy);
	yy = unique(ys, ys + yy) - ys;
	forn(i, 3)
	{
		a[i].x = lower_bound(xs, xs + xx, a[i].x) - xs;
		a[i].y = lower_bound(ys, ys + yy, a[i].y) - ys;
	}
	i64 ans = 1e18;
	forn(mask, 1 << 12)
	{
		i64 cur = 0;
		vector<pair<tp, tp>> ca;
		int t = 0;
		
		auto fp = [](int x, int y) {
			return tp{xs[x], ys[y]};
		};
		
		clr(d);
		forn(i, 3)
		{
			d[a[i].x * 3 + a[i].y][a[i].x * 3 + a[i].y] = true;
		}
		forn(j, 2)
		{
			forn(l, 3)
			{
				bv[j][l] = (mask >> t) & 1;
				if (bv[j][l])
				{
					ca.pb(mp(fp(j, l), fp(j + 1, l)));
					cur += dist(ca.back().first, ca.back().second);
					d[j * 3 + l][(j + 1) * 3 + l] = true;
					d[(j + 1) * 3 + l][j * 3 + l] = true;
				}
				t++;
			}
		}
		forn(j, 3)
		{
			forn(l, 2)
			{
				bh[j][l] = (mask >> t) & 1;
				if (bh[j][l])
				{
					ca.pb(mp(fp(j, l), fp(j, l + 1)));
					d[j * 3 + l][j * 3 + l + 1] = true;
					d[j * 3 + l + 1][j * 3 + l] = true;
					cur += dist(ca.back().first, ca.back().second);
				}
				t++;
			}
		}
		forn(k, 9)
		{
			forn(i, 9)
			{
				forn(j, 9)
				{
					d[i][j] = d[i][j] || (d[i][k] && d[k][j]);
				}
			}
		}
		
		bool ok = true;
		forn(i, 3)
		{
			forn(j, i)
			{
				ok = ok && d[a[i].x * 3 + a[i].y][a[j].x * 3 + a[j].y];
			}
		}
		if (ok)
		{
			if (uin(ans, cur)) pans = ca;
		}
	}
	
//	cerr << ans << "\n";
	printf("%d\n", int(pans.size()));
	for (auto &s : pans)
	{
//		cerr << s.first.x << " " << s.first.y << "  ";
//		cerr << s.second.x << " " << s.second.y << "\n";
		printf("%d %d %d %d\n", s.first.x, s.first.y, s.second.x, s.second.y);
	}
	
	return 0;
}