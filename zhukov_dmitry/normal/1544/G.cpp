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
using i64 = int64_t;
using u64 = uint64_t;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

//const int MOD = 1000000007;
//using mint = numeric::modular<MOD>;

int n, k, qq;
char s[2][2024];
char ts[2024];
char d[2][2024];
int c[2];
int m[2];
int pa[2][8024][2];

string to_bin(int x)
{
	string res(n, '0');
	forn(i, n)
	{
		if (x & (1 << i)) res[i] = '1';
	}
	return res;
}

void norm(char const *s, char *a, int pa[][2], int &m)
{
	m = 0;
	strcpy(a, s);
	
	auto go = [&](int l, int r)
	{
		pa[m][0] = l;
		pa[m][1] = r;
		reverse(a + pa[m][0], a + pa[m][1] + 1);
		m++;
	};
	
	if (k == c[0])
	{
		int r = n - 1;
		while (a[r] != '1') r--;
		go(0, r);
		while (a[r] != '1') r--;
		
		strcpy(ts, a);
		reverse(ts, ts + r + 1);
		if (strcmp(ts, a) < 0)
		{
			go(0, r);
		}
		return;
	}
	
	assert(c[0] > k);
	int r = -1;
	int rem = k;
	while (rem > 0) rem -= (a[++r] == '1');
	forn(i, c[0] - k - 1)
	{
		if (a[i] != '1')
		{
			go(i, r);
		}
		++r;
		while (a[r] != '1') ++r;
	}
	int l = c[0] - k - 1;
	while (a[l] != '1') l++;
	r++;
	while (a[r] != '1') r++;
	For(cnt, 2, k)
	{
		bool rr = (cnt ^ k) & 1;
		if (rr)
		{
			go(l, r - 1);
		}
		else
		{
			go(l + 1, r);
		}
		while (a[l] != '1') l++;
		while (a[r] != '1') r--;
	}
	int x = c[0] - k - 1;
	if (a[x] != '1')
	{
		go(x, l + k - 1);
	}
	if (k == 1 && a[c[0] - 1] != '1')
	{
		go(c[0] - 1, r);
	}
	
	if (k > 1 && (k & 1) && c[0] > k && c[0] < n && a[c[0] - 1] != '1')
	{
//		cerr << c[0] << " " << k << " " << r << "\n";
		forn(i, k)
		{
			int add = i & 1;
			go(c[0] - k - add, r - add);
		}
	}
}

bool solve()
{
	forn(i, 2)
	{
		c[i] = 0;
		forn(j, n)
		{
			c[i] += s[i][j] == '1';
		}
	}
	m[0] = m[1] = 0;
	if (!strcmp(s[0], s[1])) return true;
	else if (c[0] != c[1]) return false;
	else if (c[0] < k || !k) return false;
	else
	{
		forn(i, 2)
		{
			norm(s[i], d[i], pa[i], m[i]);
		}
//		puts(d[0]);
//		puts(d[1]);
		if (strcmp(d[0], d[1])) return false;
		else
		{
			ford(i, m[1])
			{
				forn(j, 2)
				{
					pa[0][m[0]][j] = pa[1][i][j];
				}
				m[0]++;
			}
		}
	}
	return true;
}

bool u[1 << 20];
int q[1 << 20];
int pd[1 << 20];

bool dull(bool print_res = false)
{
	int mask[2] = {0, 0};
	forn(i, 2)
	{
		forn(j, n)
		{
			if (s[i][j] == '1')
			{
				mask[i] |= 1 << j;
			}
		}
	}
	if (mask[0] == mask[1]) return true;
	memset(u, 0, (1 << n) * sizeof(u[0]));
	int qb = 0, qe = 0;
	q[qe++] = mask[0];
	u[mask[0]] = true;
	while (qb != qe)
	{
		int v = q[qb++];
		forn(l, n)
		{
			int cnt = 0;
			For(r, l, n - 1)
			{
				if (v & (1 << r))
				{
					cnt++;
					if (cnt > k) break;
				}
				if (cnt == k)
				{
					int vn = v;
					For(t, l, r)
					{
						if (v & (1 << t)) vn |= 1 << (l + (r - t));
						else vn &= ~(1 << (l + (r - t)));
					}
					if (!u[vn])
					{
						q[qe++] = vn;
						pd[vn] = v;
						u[vn] = true;
						if (vn == mask[1])
						{
							if (print_res)
							{
								int x = mask[1];
								while (x != mask[0])
								{
									puts(to_bin(x).c_str());
									x = pd[x];
								}
								puts(to_bin(x).c_str());
							}
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

void stress()
{
	For(len, 1, 18)
	{
		For(kk, 1, len - 1)
		{
			cerr << len << " " << kk << "\n";
			n = len;
			k = kk;
			ford(m0, 1 << len)
			{
				if (__builtin_popcount(m0) < k) continue;
				ford(m1, m0)
				{
					if (__builtin_popcount(m1) != __builtin_popcount(m0)) continue;
					int mm[2] = {m0, m1};
					forn(i, 2)
					{
						forn(j, n)
						{
							s[i][j] = '0' + ((mm[i] >> j) & 1);
						}
						s[i][n] = '\0';
					}
					bool ja = dull();
					bool pa = solve();
					if (ja != pa)
					{
						puts("Botwa !!!");
						printf("%d %d\n", n, k);
						puts(s[0]);
						puts(s[1]);
					}
				}
			}
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
//#define STRESS
#endif

#ifdef STRESS
	stress();
#else
	scanf("%d", &qq);
	while (qq--)
	{
		scanf("%d%d", &n, &k);
		forn(i, 2)
		{
			scanf("%s", s[i]);
		}
		bool res = solve();
#ifdef ROOM_311
//		dull(true);
#endif
		if (res)
		{
			printf("%d\n", m[0]);
			forn(i, m[0])
			{
				printf("%d %d\n", pa[0][i][0] + 1, pa[0][i][1] + 1);
			}
		}
		else
		{
			puts("-1");
		}
	}
#endif

	return 0;
}