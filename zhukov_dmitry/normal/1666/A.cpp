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
#pragma GCC optimize("-Ofast")

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

const int maxn = 20000;

int n;
char s[maxn + 2];
uint32_t u[maxn][(maxn + 64) >> 5];
//bitset<maxn + 1> u[maxn];

int16_t su[maxn + 2];
int16_t sd[maxn + 2];
bool bf[maxn + 2];
bool bl[maxn + 2];
int16_t sbf[maxn + 2];
int16_t sbl[maxn + 2];
bool bin[maxn + 2];
int16_t sbin[maxn + 2];
int kh[maxn];

uint32_t em[(maxn >> 5) + 2];

bool st[maxn + 2];
bool mid[maxn + 2];
bool en[maxn + 2];

inline int calc(int16_t *s, int l, int r)
{
	return s[r + 1] - s[l];
}

void go()
{
	su[0] = 0;
	sd[0] = 0;
	clr(kh);
	forn(i, n)
	{
		su[i + 1] = su[i] + (s[i] == 'U');
		sd[i + 1] = sd[i] + (s[i] == 'D');
	}
	forn(i, n - 1)
	{
		int x = i;
		while (s[x] == 'D' && s[x + 1] == 'U')
		{
			x += 2;
			u[i][x >> 5] |= 1 << x;
//			u[i].set(x);
		}
	}
	clr(em);
	forn(i, n - 1)
	{
		int x = i;
		while (s[x] == 'R' && s[x + 1] == 'L')
		{
			x += 2;
			u[i][x >> 5] |= 1 << x;
//			u[i].set(x);
		}
	}
	For(i, 1, n - 2)
	{
		kh[i] = (s[i - 1] == 'R') + (s[i + 1] == 'L');
	}
	
	For(m, 2, n / 2)
	{
		clr(bf);
		clr(bl);
		clr(bin);
		clr(sbl);
		clr(sbf);
		clr(sbin);
		For(i, 1, n - m - 2)
		{
			bf[i] = (kh[i] + (s[i + m] == 'U') != 1);
			sbf[i + 1] = sbf[i] + bf[i];
		}
		For(i, m + 1, n - 2)
		{
			bl[i] = (kh[i] + (s[i - m] == 'D') != 1);
			sbl[i + 1] = sbl[i] + bl[i];
		}
		For(i, m, n - m - 1)
		{
			bool ok = true;
			ok = ok && (kh[i] + (s[i - m] == 'D') + (s[i + m] == 'U') == 1);
			bin[i] = !ok;
			sbin[i + 1] = sbin[i] + bin[i];
		}
		
		clr(st);
		clr(en);
		clr(mid);
		
		For(i, 0, n - m)
		{
			int l = i;
			int r = i + m - 1;
			if (s[l] == 'L' || s[r] == 'R') continue;
			
			if (r + m < n)
			{
				bool gfst = true;
				gfst = gfst && (calc(su, l, r) == 0);
				gfst = gfst && (calc(sbf, l + 1, r - 1) == 0);
				gfst = gfst && ((s[l + 1] == 'L') + (s[l + m] == 'U') == 1);
				gfst = gfst && ((s[r - 1] == 'R') + (s[r + m] == 'U') == 1);
			
				st[i] = gfst;
			}
			
			if (l - m >= 0)
			{
				bool glast = true;
				glast = glast && (calc(sd, l, r) == 0);
				glast = glast && (calc(sbl, l + 1, r - 1) == 0);
				glast = glast && ((s[l + 1] == 'L') + (s[l - m] == 'D') == 1);
				glast = glast && ((s[r - 1] == 'R') + (s[r - m] == 'D') == 1);
				
				en[i] = glast;
			}
			
			if (r + m < n && l - m >= 0)
			{
				bool gmid = true;
				gmid = gmid && ((s[l - m] == 'D') + (s[l + m] == 'U') + (s[l + 1] == 'L') == 1);
				gmid = gmid && ((s[r - m] == 'D') + (s[r + m] == 'U') + (s[r - 1] == 'R') == 1);
				gmid = gmid && (calc(sbin, l + 1, r - 1) == 0);
				
				mid[i] = gmid;
			}
		}
		
		forn(md, m)
		{
			int prev = -1;
//			for (int i = md; i + m <= n; i += m)
//			{
//				if (en[i]) em[i >> 5] |= 1 << i;
//			}
			for (int i = md; i + m <= n; i += m)
			{
				if (!st[i]) continue;
				
				int last = prev < i + m ? i + m : prev;
//				int last = i + m;
				while (last + m <= n)
				{
					if (!mid[last])
					{
						last += m;
						break;
					}
					last += m;
				}
				
				auto *uu = u[i];

/*				int tt = i + m;
				uint32_t x = tt >> 5;
				uint32_t y = tt & 31;
				int cnt = (last - tt) / m;
				uint32_t dx = m >> 5;
				uint32_t dy = m & 31;
				forn(tmp, cnt)
				{
					if (en[tt]) uu[x] |= 1 << y;
					x += dx;
					y += dy;
					x += (y >> 5);
					y &= 31;
					tt += m;
				}
				*/
					for (int t = i + m; t < last; t += m)
//					for (int t = i + m; t + m <= n; t += m)
					{
//						uu[t >> 5] |= em[t >> 5];
//						if (em[t >> 5] & (1 << t)) uu[t >> 5] |= 1 << t;
						if (en[t]) uu[t >> 5] |= 1 << t;
//						if (!mid[t]) break;
					}
			}
//			for (int i = md; i + m <= n; i += m)
//			{
//				em[i >> 5] = 0;
//			}
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#define BIG 1
#endif
	
#ifdef BIG
	n = 20000;
	forn(i, n)
	{
		s[i] = "RL"[i & 1];
	}
	s[n] = '\0';
#else
	scanf("%s", s);
#endif
	n = strlen(s);
	clr(u);
//	forn(i, n)
//	{
//		u[i].reset();
//	}
	
/*	forn(i, n)
	{
		if (s[i] == 'R') s[i] = 'D';
		else if (s[i] == 'L') s[i] = 'U';
		else if (s[i] == 'D') s[i] = 'R';
		else if (s[i] == 'U') s[i] = 'L';
	}
	puts(s);*/
	go();
	
	int ans = 0;
	forn(i, n - 1)
	{
		For(j, i + 2, n)
		{
			if (u[i][j >> 5] & (1 << j))
			{
//				cerr << i << " " << j - i << "\n";
				++ans;
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}