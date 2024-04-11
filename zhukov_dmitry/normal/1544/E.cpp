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
#define cerr if (0) cerr
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

int n, qq;
char s[102400];
int c0[26];
int c[26];
int cd;
int p[102400];
char a[102400];
char ans[102400];
int total;

bool rec(int pos, int n, int lim, int q, bool eq, bool b2, int le)
{
	if (pos >= n) return true;
	++total;
	if (lim == 0 && pos > 0)
	{
		int z = a[0] - 'a';
		if (c[z] > 0) return false;
	}
	if (eq && pos == lim + 1)
	{
		int co = 0;
		int cc = 0;
		int z = a[0] - 'a';
		forn(i, 26)
		{
			if (i == z) cc += c[i];
			else co += c[i];
		}
		if (co * lim < cc) return false;
	}
	if (lim > 0 && b2 && pos > lim && cd == 2 && le == lim && a[pos - 1] == a[0])
	{
		int z0 = a[0] - 'a';
		int z1 = a[lim] - 'a';
		bool ok = false;
		bool ff = true;
		forn(i, 26)
		{
			if (c[i] > 0)
			{
				if (i != z0 && i != z1) ok = true;
				else if (i == z1) ff = false;
			}
		}
//		cerr << "! " << ok << " " << ff << "\n";
		if (!ok && !ff) return false;
	}
	forn(i, 26)
	{
		if (!c[i]) continue;
		a[pos] = 'a' + i;
		cd -= !--c[i];
		int qq = q;
		while (qq != -1 && a[pos] != a[qq + 1]) qq = p[qq];
		if (pos != 0 && a[pos] == a[qq + 1]) qq++;
		p[pos] = qq;
		if (p[pos] + 1 > lim)
		{
			
		}
//		if (p[pos] + 1 <= lim && lim == 3)
//		{
//			a[pos + 1] = '\0';
//			puts(a);
//			cerr << pos << " " << p[pos] << " " << lim << "\n";
//		}
		bool neq = eq && (!pos || a[pos - 1] == a[pos]);
		bool nb2 = b2 && (pos > lim || (pos < lim && neq) || (pos == lim && !neq));
		if (p[pos] + 1 <= lim && rec(pos + 1, n, lim, qq, neq, nb2, (pos ? (a[pos - 1] == a[pos] ? le + 1 : 1) : 1))) return true;
		cd += !(c[i]++);
	}
	return false;
}

bool check(int lim)
{
	total = 0;
	if (lim == 0)
	{
		bool ok = false;
		forn(i, 26)
		{
			if (c[i] == 1) ok = true;
		}
		if (!ok) return false;
	}
	return rec(0, n, lim, -1, true, true, 0);
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
//#define BIG 1
#endif
	
	scanf("%d", &qq);
	while (qq--)
	{
		scanf("%s", s);
#ifdef BIG
		n = 100000;
		forn(i, n)
		{
			s[i] = 'a' + rand() % 2;
		}
		forn(i, n / 2)
		{
			s[i] = 'a';
		}
//		s[10] = 'z';
		s[n] = '\0';
#endif
		n = strlen(s);
		clr(c);
		forn(i, n)
		{
			++c[s[i] - 'a'];
		}
		int mi = 0;
		int ma = n;
		a[n] = '\0';
		memcpy(c0, c, sizeof(c));
		int cd0 = 0;
		forn(i, 26)
		{
			cd0 += c[i] > 0;
		}
		while (mi < ma)
		{
			int q = (mi + ma) / 2;
			cerr << "q=" << q << "\n";
			memcpy(c, c0, sizeof(c));
			cd = cd0;
			if (check(q))
			{
				strcpy(ans, a);
				ma = q;
			}
			else
			{
				mi = q + 1;
			}
			cerr << "total=" << total << "\n";
		}
//		cerr << "mi=" << mi << "\n";
		puts(ans);
	}
	
	return 0;
}