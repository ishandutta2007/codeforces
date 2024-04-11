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
int s[1024000];
//int ms[1024000];
int mal[1024000];
//int mar[1024000];
int d[1024000][2];
int up[1024000];
int dn[1024000];
bool eu[1024000];
bool ed[1024000];

int do_solve()
{
	int mj = 0;
	int ma = -1;
//	int mjl = -1;
//	int mjr = n;
	forn(i, n)
	{
		if (uax(ma, a[i])) mj = i;
	}
	int fr = n;
//	int fl = -1;
	int ss = 0;
	For(i, mj + 1, n - 1)
	{
		if (a[i] > a[i - 1])
		{
//			mjr = i;
			fr = i - 1;
			while (fr > mj && a[fr - 1] < a[i]) --fr;
			break;
		}
	}
/*	Ford(i, mj - 1, 0)
	{
		if (a[i] > a[i + 1])
		{
			mjl = i;
			fl = i + 1;
			while (fl < mj && a[fl + 1] < a[i]) ++fl;
			break;
		}
	}*/
	Ford(i, n - 1, mj)
	{
		int t = lower_bound(s, s + ss, a[i], greater<int>()) - s;
		if (t < ss) s[t] = a[i];
		else s[ss++] = a[i];
//		ms[i] = ss;
//		mar[i] = i;
//		if (i < n - 1 && a[mar[i + 1]] > a[i]) mar[i] = i;
	}
	if (ss > 2) return 0;
//	ss = 0;
	For(i, 0, mj)
	{
//		int t = lower_bound(s, s + ss, a[i], greater<int>()) - s;
//		if (t < ss) s[t] = a[i];
//		else s[ss++] = a[i];
//		ms[i] = ss;
		mal[i] = i;
		if (i > 0 && a[mal[i - 1]] > a[i]) mal[i] = mal[i - 1];
	}
	For(i, 0, mj)
	{
		if (i == 0)
		{
			d[i][0] = a[i];
			d[i][1] = -1;
		}
		else
		{
			d[i][0] = d[i - 1][0];
			d[i][1] = d[i - 1][1];
			if (a[i] > d[i][0])
			{
				d[i][0] = a[i];
			}
			else
			{
				if (a[i] > d[i][1])
				{
					d[i][1] = a[i];
				}
				else
				{
					d[i][1] = 0x7f7f7f7f;
				}
			}
		}
	}
//	For(i, 0, mj - 1)
//	{
//		cerr << d[i][0] << " " << d[i][1] << "\n";
//	}
	int uu = 0;
	int dd = 0;
	int ans = 0;
	bool ff = true;
	int mi = -1;
	a[n] = -1;
	if (fr < n)
	{
		dn[dd++] = fr;
		mi = a[fr];
	}
	else
	{
		dn[dd++] = n;
	}
	up[uu++] = mj;
	int mode = 0;
	Ford(i, mj - 1, 0)
	{
//		cerr << "i=" << i << " mode=" << mode << "\n";
		eu[i] = false;
		ed[i] = false;
		if (mode == 0)
		{
			while (uu > 1 && a[up[uu - 1]] < a[i])
			{
				int x = up[uu - 1];
				if (ed[x])
				{
					mode = 1;
					break;
				}
				else
				{
					eu[x] = true;
					--uu;
				}
			}
		}
		if (mode == 0)
		{
			while (dd > 1 && a[dn[dd - 1]] > a[i])
			{
				int x = dn[dd - 1];
				if (eu[x])
				{
					mode = 1;
					break;
				}
				else
				{
					ed[x] = true;
					--dd;
				}
			}
		}
		if (mode == 0 && a[i] < a[dn[dd - 1]])
		{
			mode = 1;
		}
//		cerr << "! mode=" << mode << " ff=" << ff << "\n";
		if (mode == 0)
		{
			up[uu++] = i;
			dn[dd++] = i;
		}
		else
		{
			assert(dd > 0);
			assert(uu > 0);
			if (a[i] > a[dn[dd - 1]]) dn[dd++] = i;
			else if (a[i] < a[up[uu - 1]]) up[uu++] = i;
			else break;
		}
//		cerr << "? mode=" << mode << " ff=" << ff << "\n";
		if (a[i] > a[i + 1]) ff = false;
		if (d[i][1] >= 0x7f7f7f7f) continue;
		if (a[i] < mi) continue;
//		if (ms[i] > 2) continue;
//		cerr << "mode=" << mode << " ff=" << ff << "\n";
		if (ff)
		{
			if (d[i][0] > a[i])
			{
				if (d[i][0] > a[i + 1]) continue;
				assert(d[i][1] == a[i]);
			}
			else
			{
				// ok
			}
		}
		else
		{
			if (a[mal[i]] > a[i])
			{
				assert(a[mal[i]] == d[i][0]);
				if (mode == 0)
				{
//					cerr << "uu=" << uu << " up[uu - 1]=" << up[uu - 1] << " " << a[up[uu - 1]] << "\n";
//					cerr << "uu=" << uu << " up[uu - 2]=" << up[uu - 2] << " " << a[up[uu - 2]] << "\n";
					if (uu > 1 && a[up[uu - 2]] < d[i][0]) continue;
				}
				else
				{
					continue;
				}
//				if (uu + dd - 2 != (mj - i - 1)) continue;
//				if (uu > 1 && a[up[uu - 2]] < d[i][0]) continue;
//				if (a[dn[0]] < mi) continue;
			}
			else
			{
				assert(a[mal[i]] == a[i]);
				int lim = d[i][1];
//				cerr << "lim=" << lim << " uu=" << uu << " dd=" << dd << "\n";
				if (mode == 0)
				{
					if (uu > 1)
					{
						assert(dd > 0);
						if (a[up[uu - 1]] < a[i])
						{
							if (uu > 1 && a[up[uu - 2]] < lim) continue;
							if (a[dn[0]] < mi) continue;
						}
						else
						{
							if (dd > 1 && a[dn[dd - 2]] > a[i]) continue;
							if (dd > 0 && a[dn[0]] < mi) continue;
						}
					}
					else
					{
						if (dd > 1 && a[dn[0]] < mi) continue;
						// ok
					}
				}
				else
				{
					if (a[dn[dd - 1]] > a[i]) continue;
					if (a[dn[0]] < mi) continue;
					if (a[up[uu - 1]] < lim) continue;
				}
			}
		}
//		cerr << "ok: " << a[i] << "\n";
		++ans;
	}
	return ans;
}

int solve_dull()
{
	int ans = 0;
	int ma = -1;
	int mj = 0;
	forn(i, n)
	{
		if (uax(ma, a[i]))
		{
			mj = i;
		}
	}
	forn(i, n)
	{
		if (mj == i) continue;
		bool ok = false;
		forn(mask, 1 << n)
		{
			if (!((mask >> mj) & 1)) continue;
			if ((mask >> i) & 1) continue;
			auto check = [&](int top_idx, int bit) {
				int prev = a[top_idx];
				ford(j, top_idx)
				{
					if (((mask >> j) & 1) != bit) continue;
					if (a[j] > prev) return false;
					prev = a[j];
				}
				prev = a[top_idx];
				For(j, top_idx + 1, n - 1)
				{
					if (((mask >> j) & 1) != bit) continue;
					if (a[j] > prev) return false;
					prev = a[j];
				}
				return true;
			};
			
			if (!check(mj, 1)) continue;
			if (!check(i, 0)) continue;
			ok = true;
			break;
		}
		if (ok) ++ans;
	}
	return ans;
}

int solve()
{
	int ans = do_solve();
//	cerr << "ans1=" << ans << "\n";
	reverse(a, a + n);
	ans += do_solve();
	reverse(a, a + n);
	return ans;
}

void stress(int nn)
{
	n = nn;
	forn(i, n)
	{
		a[i] = i + 1;
	}
	int cnt = 0;
	do
	{
		int dull = solve_dull();
		int ans = solve();
		if (ans != dull)
		{
			cout << "Botwa!!!\n";
			cout << n << "\n";
			forn(i, n)
			{
				cout << a[i] << " \n"[i == n - 1];
			}
			return;
		}
		++cnt;
	}
	while (next_permutation(a, a + n));
	cout << cnt << " OK\n";
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
//	stress(9);
	
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d", &a[i]);
	}
	
//	int dull = solve_dull();
	int ans = solve();
//	printf("dull=%d\nans=", dull);
	printf("%d\n", ans);
	
	return 0;
}