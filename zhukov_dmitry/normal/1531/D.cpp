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

char buf[42];

struct tnode
{
	int val;
	bool has_0;
};

int n;
string a[102400];
set<int> c;
set<int> l;
set<int> u;
const int z = 1 << 17;
tnode t[z * 2];

void tset(int v, int l, int r, int ll, int rr, int x)
{
	if (l > rr || r < ll) return;
	if (l <= ll && rr <= r)
	{
		t[v].val = x;
		t[v].has_0 = (x == 0);
		return;
	}
	if (t[v].val != -1)
	{
		t[v * 2] = t[v * 2 + 1] = t[v];
	}
	tset(v * 2, l, r, ll, (ll + rr) / 2, x);
	tset(v * 2 + 1, l, r, (ll + rr) / 2 + 1, rr, x);
	t[v].has_0 = t[v * 2].has_0 || t[v * 2 + 1].has_0;
	if (t[v * 2].val != t[v * 2 + 1].val) t[v].val = -1;
	else t[v] = t[v * 2];
}

void set_0(int l, int r)
{
	uax(l, 0);
	uin(r, n);
	if (l > r) return;
//	cerr << "set_0 " << l << " " << r << "\n";
	tset(1, l, r, 0, z - 1, 0);
}

void set_1(int l, int r)
{
	uax(l, 0);
	uin(r, n);
	if (l > r) return;
//	cerr << "set_1 " << l << " " << r << "\n";
	tset(1, l, r, 0, z - 1, 1);
}

int get_last_0()
{
	int v = 1;
	assert(t[v].has_0);
	while (v < z)
	{
		if (t[v].val != -1)
		{
			t[v * 2] = t[v * 2 + 1] = t[v];
		}
		assert(t[v].has_0);
		v *= 2;
		if (t[v + 1].has_0) v++;
	}
	assert(t[v].has_0);
	return v - z;
}

bool locked(int x)
{
	int ll = *prev(l.upper_bound(x));
	int uu = *u.upper_bound(ll);
	return uu >= x;
}

void add_l(int x)
{
	bool ll = locked(x);
	l.insert(x);
	if (ll) return;
	int uu = min(*l.upper_bound(x) - 1, *u.upper_bound(x));
	set_1(x, uu);
}

void del_l(int x)
{
	assert(l.count(x));
	l.erase(x);
	bool ll = locked(x);
	if (ll) return;
	int uu = min(*l.upper_bound(x) - 1, *u.upper_bound(x) - 1);
	set_0(x, uu);
}

void add_u(int x)
{
	u.insert(x);
	bool ll = locked(x);
	if (!ll)
	{
		set_1(x, x);
		return;
	}
	int rr = min(*l.upper_bound(x) - 1, *u.upper_bound(x) - 1);
	set_0(x + 1, rr);
}

void del_u(int x)
{
	assert(u.count(x));
	u.erase(x);
	bool ll = locked(x);
	if (!ll)
	{
		set_0(x, x);
		return;
	}
	int rr = min(*l.upper_bound(x) - 1, *u.upper_bound(x));
	set_1(x, rr);
}

void solve()
{
	int pos = get_last_0();
	assert(a[pos] != "lock");
	assert(a[pos] != "unlock");
//	cerr << " pos=" << pos << "\n";
	puts(a[pos].c_str());
}

int main()
{
#ifdef ROOM_311
	freopen("input1.txt", "rt", stdin);
#endif
	
	forn(i, z * 2)
	{
		t[i].val = -1;
		t[i].has_0 = false;
	}
	scanf("%d", &n);
	forn(i, n + 1)
	{
		t[z + i].val = 0;
		t[z + i].has_0 = true;
	}
	Ford(i, z - 1, 1)
	{
		t[i].has_0 = (t[i * 2].has_0 || t[i * 2 + 1].has_0);
		t[i].val = (t[i * 2].val == t[i * 2 + 1].val ? t[i].val : -1);
	}
	a[0] = "blue";
	l.insert(-2);
	u.insert(-1);
	u.insert(n + 1);
	l.insert(n + 2);
	c.insert(0);
	For(i, 1, n)
	{
		scanf("%s", buf);
		a[i] = buf;
		if (a[i] == "lock") add_l(i);
		else if (a[i] == "unlock") add_u(i);
		else c.insert(i);
	}
	solve();
	int m;
	scanf("%d", &m);
	forn(i, m)
	{
		int x;
		scanf("%d%s", &x, buf);
		string y = buf;
		if (y != a[x])
		{
			if (a[x] == "lock") del_l(x);
			else if (a[x] == "unlock") del_u(x);
			else c.erase(x);

			a[x] = move(y);
			if (a[x] == "lock") add_l(x);
			else if (a[x] == "unlock") add_u(x);
			else c.insert(x);
		}
		
		solve();
	}
	
	return 0;
}