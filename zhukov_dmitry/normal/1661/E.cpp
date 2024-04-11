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

const int z = 1 << 19;

struct tnode
{
	array<int, 3> l;
	array<int, 3> r;
	int cc{0};
};

int n, m;
bool a[3][1024000];
char ss[1024000];
tnode t[z * 2];

int num[12];
int pa[12];

int find(int x)
{
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}

void unite(int x, int y)
{
	pa[x] = y;
}

tnode mrg(tnode l, tnode r)
{
	int kl = 0, kr = 0;
	forn(i, 3)
	{
		if (l.l[i] >= 0) ++kl;
		if (l.r[i] >= 0) ++kl;
		if (r.l[i] >= 0) ++kr;
		if (r.r[i] >= 0) ++kr;
	}
	int k = kl + kr;
	forn(i, k)
	{
		pa[i] = i;
	}
	forn(i, 3)
	{
		if (r.l[i] >= 0) r.l[i] += kl;
		if (r.r[i] >= 0) r.r[i] += kl;
	}
	tnode res;
	res.cc = l.cc + r.cc;
	forn(i, 3)
	{
		int x = l.r[i];
		int y = r.l[i];
		if (x >= 0 && y >= 0)
		{
			if (find(x) != find(y))
			{
				unite(pa[x], pa[y]);
				res.cc--;
			}
		}
	}
	forn(i, k)
	{
		num[i] = -1;
	}
	int kk = 0;
	forn(i, 3)
	{
		res.l[i] = l.l[i] >= 0 ? find(l.l[i]) : -1;
		if (res.l[i] >= 0 && num[res.l[i]] < 0)
		{
			num[res.l[i]] = kk++;
		}
	}
	forn(i, 3)
	{
		res.r[i] = r.r[i] >= 0 ? find(r.r[i]) : -1;
		if (res.r[i] >= 0 && num[res.r[i]] < 0)
		{
			num[res.r[i]] = kk++;
		}
	}
	forn(i, 3)
	{
		if (res.l[i] >= 0) res.l[i] = num[res.l[i]];
		if (res.r[i] >= 0) res.r[i] = num[res.r[i]];
	}
	return res;
}

tnode tget(int l, int r)
{
	l += z;
	r += z;
	bool fl = true;
	tnode ansl;
	int l0 = l, r0 = r;
	while (l <= r)
	{
		if (l & 1)
		{
			if (fl)
			{
				ansl = t[l];
				fl = false;
			}
			else
			{
				ansl = mrg(ansl, t[l]);
			}
		}
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	l = l0;
	r = r0;
	bool fr = true;
	tnode ansr;
	while (l <= r)
	{
		if (!(r & 1))
		{
			if (fr)
			{
				ansr = t[r];
				fr = false;
			}
			else
			{
				ansr = mrg(t[r], ansr);
			}
		}
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}
	if (fl)
	{
//		f = fr;
		ansl = ansr;
	}
	else if (!fr)
	{
		ansl = mrg(ansl, ansr);
	}
	return ansl;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d", &n);
	forn(i, 3)
	{
		scanf("%s", ss);
		forn(j, n)
		{
			a[i][j] = ss[j] == '0';
		}
	}
	
	forn(i, z * 2)
	{
		forn(j, 3)
		{
			t[i].l[j] = -1;
			t[i].r[j] = -1;
		}
		t[i].cc = 0;
	}
	forn(i, n)
	{
		forn(i, 3)
		{
			pa[i] = i;
			num[i] = -1;
		}
		auto &cur = t[z + i];
		cur.cc = 0;
		forn(j, 3)
		{
			cur.l[j] = a[j][i] == 0 ? j : -1;
			if (a[j][i] == 0) cur.cc++;
		}
		forn(j, 2)
		{
			int x = cur.l[j];
			int y = cur.l[j + 1];
			if (x >= 0 && y >= 0)
			{
				if (find(x) != find(y))
				{
					unite(pa[x], pa[y]);
					cur.cc--;
				}
			}
		}
		int kk = 0;
		forn(j, 3)
		{
			cur.l[j] = cur.l[j] >= 0 ? find(cur.l[j]) : -1;
			if (cur.l[j] >= 0)
			{
				if (num[cur.l[j]] < 0) num[cur.l[j]] = kk++;
				cur.l[j] = num[cur.l[j]];
			}
		}
		cur.r = cur.l;
/*		cerr << i << " " << cur.cc << "\n";
		forn(j, 3)
		{
			cerr << cur.l[j] << " ";
		}
		cerr << "\n";
		forn(j, 3)
		{
			cerr << cur.r[j] << " ";
		}
		cerr << "\n";*/
	}
	
	Ford(i, z - 1, 1)
	{
		t[i] = mrg(t[i * 2], t[i * 2 + 1]);
/*		int l = i;
		int r = i;
		while (l < z)
		{
			l = l * 2;
			r = r * 2 + 1;
		}
		l -= z;
		r -= z;
		if (r < n)
		{
			const auto &cur = t[i];
			cerr << "i: " << i << " " << l << " " << r << " " << cur.cc << "\n";
			forn(j, 3)
			{
				cerr << cur.l[j] << " ";
			}
			cerr << "\n";
			forn(j, 3)
			{
				cerr << cur.r[j] << " ";
			}
			cerr << "\n";
		}*/
	}
	
	scanf("%d", &m);
	forn(i, m)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r--;
		auto res = tget(l, r);
		
/*		const auto &cur = res;
		cerr << "res: " << i << " " << l << " " << r << " " << cur.cc << "\n";
		forn(j, 3)
		{
			cerr << cur.l[j] << " ";
		}
		cerr << "\n";
		forn(j, 3)
		{
			cerr << cur.r[j] << " ";
		}
		cerr << "\n";*/
		printf("%d\n", res.cc);
	}
	
	return 0;
}