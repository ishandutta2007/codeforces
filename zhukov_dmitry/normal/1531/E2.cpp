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
using i64 = long long;
using u64 = unsigned long long;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

//const int MOD = 1000000007;
//using mint = numeric::modular<MOD>;

const int MAXL = 1568929 + 1;
const int MAXH = 64;

char a[MAXL + 1];
int dmi[MAXL];
int dma[MAXL];
int d[MAXL][MAXH];
int n;

int calc_mi(int n)
{
	int &ans = dmi[n];
	if (ans != -1) return ans;
	if (n <= 1) return ans = 0;
	int l = n / 2;
	int r = n - l;
	return ans = calc_mi(l) + calc_mi(r) + l;
}

int calc_ma(int n)
{
	int &ans = dma[n];
	if (ans != -1) return ans;
	if (n <= 1) return ans = 0;
	int l = n / 2;
	int r = n - l;
	return ans = calc_ma(l) + calc_ma(r) + l + r - 1;
}

int check(int pos, int k)
{
	if (k <= 1) return 0;
	int ans_cur = -1;
	int &ans = (k - 2 < MAXH ? d[pos][k - 2] : ans_cur);
	if (ans != -1) return ans;
	ans = 0;
	int l = k / 2;
	int r = k - l;
	int k1 = check(pos, l);
	if (k1 == -2) return ans = -2;
	pos += k1;
	int k2 = check(pos, r);
	if (k2 == -2) return ans = -2;
	pos += k2;
	int i = 0;
	int j = 0;
	while (pos + ans < n && i < l && j < r)
	{
		if (a[pos + ans++] == '0') i++;
		else j++;
	}
	if (i < l && j < r) return ans = -2;
	ans += k1 + k2;
	return ans;
}

bool check(int k)
{
//	return k == 16;
	int res = check(0, k);
//	cerr << k << " " << res << "\n";
//	if (res == -2) return false;
	return res == n;
}

int p[MAXL];
int q[MAXL];

void solve(int l, int r, int &pos, int *p)
{
	if (r - l <= 1) return;
	int m = (l + r) >> 1;
	solve(l, m, pos, p);
	solve(m, r, pos, p);
	int i = l;
	int j = m;
	int t = l;
	while (i < m && j < r)
	{
		if (a[pos++] == '0') q[t++] = p[i++];
		else q[t++] = p[j++];
	}
	while (i < m) q[t++] = p[i++];
	while (j < r) q[t++] = p[j++];
	For(z, l, r - 1)
	{
		p[z] = q[z];
	}
}

void solve(int k)
{
	forn(i, k)
	{
		p[i] = i;
	}
	int pos = 0;
	solve(0, k, pos, p);
	assert(pos == n);
	forn(i, k)
	{
		q[p[i]] = i;
	}
	printf("%d\n", k);
	forn(i, k)
	{
		printf("%d%c", q[i] + 1, " \n"[i == k - 1]);
	}
}

void gen(int l, int r, int *p, string &ans)
{
	if (r - l <= 1) return;
	int m = (l + r) >> 1;
	gen(l, m, p, ans);
	gen(m, r, p, ans);
	int i = l;
	int j = m;
	int t = l;
	while (i < m && j < r)
	{
		if (p[i] < p[j])
		{
			ans += '0';
			q[t++] = p[i++];
		}
		else
		{
			ans += '1';
			q[t++] = p[j++];
		}
	}
	while (i < m) q[t++] = p[i++];
	while (j < r) q[t++] = p[j++];
	For(z, l, r - 1)
	{
		p[z] = q[z];
	}
}

string gen(int len)
{
	forn(i, len)
	{
		p[i] = i;
	}
	utils::random_shuffle(p, p + len);
	string ans;
	gen(0, len, p, ans);
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input1.txt", "rt", stdin);
#endif

//	cerr << sizeof(d) << "\n";
//	cerr << gen(100) << "\n";
//	return 0;
	
	scanf("%s", a);
	n = strlen(a);

	memset(dmi, 0xff, sizeof(dmi));
	memset(dma, 0xff, sizeof(dma));
/*	For(i, 1, 16)
	{
		cerr << i << " " << calc_mi(i) << " " << calc_ma(i) << "\n";
	}
	For(j, 1, 16)
	{
		int i = 1 << j;
		cerr << i << " " << calc_mi(i) << " " << calc_ma(i) << "\n";
	}
	For(i, 100000 - 20, 100000)
	{
		cerr << i << " " << calc_mi(i) << " " << calc_ma(i) << "\n";
	}*/
	int st = 0;
	int en = MAXL - 1;
	while (calc_ma(st) < n && st <= en) ++st;
	while (calc_mi(en) > n && en >= st) --en;
	memset(d, 0xff, sizeof(d));
	int mi = st;
	int ma = en;
	while (mi < ma)
	{
		int q = (mi + ma + 1) / 2;
		int tmp = check(0, q);
		if (tmp == -2) ma = q - 1;
		else mi = q;
	}
//	assert(check(mi));
	solve(mi);
//	cerr << st << " " << en << "\n";
/*	For(i, st, en)
	{
		if (check(i))
		{
			solve(i);
			return 0;
		}
	}
	assert(false);*/
	
	return 0;
}