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
using u128 = __uint128_t;
//using tp = geometry::point<int>;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

//const int MOD = 1000000007;
//const int MOD = 998244353;
//using mint = numeric::modular<MOD>;

int n[2], qq, k;
u128 a[2][1020];
char buf[10240];
u128 b[102400];
vector<pair<int, int>> e[2][1020];
int q[1024000];
int ma[2][102400];
bool u[102400];
bool ans[2][1020];
vector<pair<int, int>> c[2][102400];

inline bool even(u128 x)
{
	return !(((uint32_t)x) & 1);
}

u128 gcd(u128 a, u128 b)
{
	if (!a) return b;
	if (!b) return a;
	int p2 = 0;
	while (even(a) && even(b))
	{
		++p2;
		a >>= 1;
		b >>= 1;
	}
	while (a && b)
	{
		while (even(a)) a >>= 1;
		while (even(b)) b >>= 1;
		if (a > b) a -= b;
		else b -= a;
	}
	return (a + b) << p2;
}

void add(u128 x, int st = 0)
{
	int kk = k;
	For(i, st, kk - 1)
	{
		auto g = gcd(b[i], x);
		if (g == 1) continue;
		
		if (b[i] != g)
		{
			u128 tmp = b[i] / g;
			b[i] = g;
			add(tmp, i);
			return add(x, i);
		}
		x /= g;
		while (x % g == 0) x /= g;
		return add(x, i);
	}
	if (x > 1) b[k++] = x;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#else
#define cerr if (0) cerr
#endif
	
	scanf("%d", &qq);
	while (qq--)
	{
		forn(t, 2)
		{
			scanf("%d", &n[t]);
		}
		k = 0;
		forn(t, 2)
		{
			forn(i, n[t])
			{
				scanf("%s", buf);
				int l = strlen(buf);
				a[t][i] = 0;
				forn(j, l)
				{
					a[t][i] = a[t][i] * 10 + buf[j] - '0';
				}
				add(a[t][i]);
				ans[t][i] = true;
			}
		}
		sort(b, b + k);
		cerr << "k=" << k << "\nb: ";
		forn(i, k)
		{
			cerr << u64(b[i]) << " ";
		}
		cerr << "\n";
//		forn(i, k)
//		{
//			forn(j, i)
//			{
//				assert(gcd(b[i], b[j]) == 1);
//			}
//		}
		forn(t, 2)
		{
			forn(i, k)
			{
				ma[t][i] = 0;
			}
		}
		forn(t, 2)
		{
			forn(i, n[t])
			{
				u128 x = a[t][i];
				forn(j, k)
				{
					if (x % b[j] == 0)
					{
						e[t][i].emplace_back(j, 1);
						x /= b[j];
						while (x % b[j] == 0)
						{
							x /= b[j];
							++e[t][i].back().second;
						}
						c[t][j].emplace_back(i, e[t][i].back().second);
					}
				}
				for (auto [p, m] : e[t][i])
				{
					uax(ma[t][p], m);
				}
			}
		}
		forn(i, k)
		{
			u[i] = false;
			uin(ma[0][i], ma[1][i]);
		}
		int qb = 0, qe = 0;
		forn(i, k)
		{
			q[qe++] = i;
			u[i] = true;
		}
		forn(t, 2)
		{
			cerr << "t=" << t << "\n";
			forn(i, n[t])
			{
				cerr << "i=" << i << ": ";
				for (auto [pp, ee] : e[t][i])
				{
					cerr << pp << " " << ee << ", ";
				}
				cerr << "\n";
			}
			cerr << "\n";
		}
		
		forn(t, 2)
		{
			forn(i, k)
			{
				cerr << "t=" << t << ", i=" << i << ", c: ";
				for (auto [v, cnt] : c[t][i])
				{
					cerr << v << " " << cnt << ", ";
				}
				cerr << "\n";
			}
		}
		cerr << "ma: ";
		forn(i, k)
		{
			cerr << ma[0][i] << " ";
		}
		cerr << "\n";
		
		while (qb != qe)
		{
			auto v = q[qb++];
			cerr << "v=" << v << ", ma=" << ma[0][v] << "\n";
			u[v] = false;
			forn(t, 2)
			{
				for (auto [i, cnt] : c[t][v])
				{
					if (!ans[t][i]) continue;
					if (cnt > ma[0][v])
					{
						cerr << "remove " << t << " " << i << "\n";
						ans[t][i] = false;
						for (auto [pp, ee] : e[t][i])
						{
							ma[0][pp] = 0;
							ma[1][pp] = 0;
							forn(t2, 2)
							{
								for (auto [i2, cnt2] : c[t2][pp])
								{
									if (!ans[t2][i2]) continue;
									uax(ma[t2][pp], cnt2);
								}
							}
							uin(ma[0][pp], ma[1][pp]);
							forn(t2, 2)
							{
								for (auto [i2, cnt2] : c[t2][pp])
								{
									if (!ans[t2][i2]) continue;
									if (u[pp]) continue;
									if (cnt2 > ma[0][pp])
									{
										cerr << "add " << t2 << " " << i2 << " " << pp << "\n";
										q[qe++] = pp;
										u[pp] = true;
									}
								}
							}
						}
					}
				}
			}
		}
		
		cerr << "ma2: ";
		forn(i, k)
		{
			cerr << ma[0][i] << " ";
		}
		cerr << "\n";
		int cc[2] = {0, 0};
		forn(t, 2)
		{
			forn(i, n[t])
			{
				cc[t] += ans[t][i];
			}
		}
		
		if (!cc[0] || !cc[1]) puts("NO");
		else
		{
			puts("YES");
			printf("%d %d\n", cc[0], cc[1]);
			forn(t, 2)
			{
				bool f = true;
				forn(i, n[t])
				{
					if (ans[t][i])
					{
						if (f) f = false;
						else putchar(' ');
						int l = 0;
						u128 x = a[t][i];
						do
						{
							buf[l++] = '0' + x % 10;
							x /= 10;
						}
						while (x);
						buf[l] = '\0';
						reverse(buf, buf + l);
						printf("%s", buf);
					}
				}
				puts("");
			}
		}
		
		forn(t, 2)
		{
			forn(i, k)
			{
				c[t][i].clear();
			}
			forn(i, n[t])
			{
				e[t][i].clear();
			}
		}
	}
	
	return 0;
}