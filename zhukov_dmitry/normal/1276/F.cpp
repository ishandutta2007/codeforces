#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)

#ifdef ROOM_311
__attribute__((destructor)) void fini_main()
{
	fprintf(stderr, "Execution time = %0.0lf ms\n", clock() * 1000.0 / CLOCKS_PER_SEC);
}
#endif

#define MY_RAND 1
#if MY_RAND
uint64_t rnd_data = 0xDEADBEEFDULL;
inline void my_srand(int seed) { rnd_data = ((uint64_t)seed << 16) | 0x330E; }
inline int my_rand() { rnd_data = rnd_data * 0x5DEECE66DULL + 0xB; return (rnd_data >> 17) & 0x7FFFFFFF; }
#define rand my_rand
#define srand my_srand
template <typename T> void my_random_shuffle(T b, T e) { For(i, 1, (int)(e - b) - 1) { swap(b[i], b[rand() % (i + 1)]); } }
#define random_shuffle my_random_shuffle
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }
template<typename type_t, typename less_t = std::less<type_t>> inline bool uin(type_t &a, const type_t &b, const less_t &ls = less_t()) { return ls(b, a) ? a = b, true : false; }
template<typename type_t, typename less_t = std::less<type_t>> inline bool uax(type_t &a, const type_t &b, const less_t &ls = less_t()) { return ls(a, b) ? a = b, true : false; }

// Types
typedef long double ld;
typedef long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

template<typename elem_t, elem_t inf = 0x3f3f3f3f>
class seg_tree_min_t
{
public:
	seg_tree_min_t() = default;

	template<typename it_t>
	seg_tree_min_t(it_t begin, it_t end) :
		seg_tree_min_t(begin, std::distance(begin, end))
	{}

	template<typename it_t>
	seg_tree_min_t(it_t begin, int n)
	{
		int z = 1;
		while (z < n) z <<= 1;
		t_.resize(z * 2);
		for (int i = 0; i < n; ++i)
		{
			t_[z + i] = *begin++;
		}
		for (int i = z - 1; i > 0; --i)
		{
			t_[i] = std::min(t_[i * 2], t_[i * 2 + 1]);
		}
	}

	elem_t operator () (int l, int r) const
	{
		int z = t_.size() / 2;
		elem_t ans = inf;
		l += z;
		r += z;
		while (l <= r)
		{
			if (l & 1) uin(ans, t_[l]);
			if (!(r & 1)) uin(ans, t_[r]);
			l = (l + 1) >> 1;
			r = (r - 1) >> 1;
		}
		return ans;
	}

	explicit operator bool () const
	{
		return !t_.empty();
	}

private:
	std::vector<elem_t> t_;
};

class suffix_array_t
{
public:
	suffix_array_t() = default;

	template<typename data_t>
	suffix_array_t(const data_t &s) :
		suffix_array_t(s.begin(), s.end())
	{}

	template <typename it_t>
	suffix_array_t(it_t begin, it_t end) :
		suffix_array_t(begin, std::distance(begin, end))
	{}

	template <typename it_t>
	suffix_array_t(it_t begin, int n) :
		sa_(n),
		pos_(n),
		lcp_(n)
	{
		build_array(begin, n);
		for (int i = 0; i < n; ++i)
		{
			pos_[sa_[i]] = i;
		}
		calc_lcp(begin, n);
		lcp_seg_tree_ = seg_tree_min_t<int>(lcp_.begin(), sa_.size() - 1);
	}

	int operator [] (int x) const { return (x >= int(sa_.size()) ? int(sa_.size()) : sa_[x]); }

	int pos(int x) const { return (x >= int(sa_.size()) ? int(sa_.size()) : pos_[x]); }

	int lcp(int x) const
	{
		return lcp_[x];
	}

	int lcp(int l, int r) const
	{
		if (l < 0 || l >= int(sa_.size()) || r < 0 || r >= int(sa_.size())) return 0;
		if (l == r) return sa_.size() - sa_[l];
		if (l > r) swap(l, r);
		return lcp_seg_tree_(l, r - 1);
	}

	int size() const { return sa_.size(); }

private:
	class buf_t
	{
	public:
		explicit buf_t(int len) :
			p_(buf().data() + bs()),
			len_(len)
		{
			bs() += len_;
		}

		~buf_t()
		{
			bs() -= len_;
		}

		buf_t(const buf_t &) = delete;
		buf_t(buf_t &&r) :
			p_(r.p_),
			len_(r.len_)
		{
			r.len_ = 0;
		}

		buf_t &operator = (const buf_t &) = delete;
		buf_t &operator = (buf_t &&r)
		{
			p_ = r.p_;
			len_ = r.len_;
			r.len_ = 0;
			return *this;
		}

		const int &operator [] (int x) const { return p_[x]; }
		int &operator [] (int x) { return p_[x]; }

		const int *operator * () const { return p_; }
		int *operator * () { return p_; }

		static void resize(int n)
		{
			buf().resize(n);
		}

		const int *data() const { return p_; }
		int *data() { return p_; }

	private:
		static std::vector<int> &buf()
		{
			static std::vector<int> static_buf{};
			return static_buf;
		}

		static int &bs()
		{
			static int static_bs{0};
			return static_bs;
		}

		int *p_;
		int len_{0};
	};

	template <typename it_t>
	void build_array(it_t it, int n)
	{
		buf_t::resize(8 * n + 2390);

		auto a = alloc_buf(n + 3);
		a[n] = a[n + 1] = a[n + 2] = 0;
		int max_c = 127;
		for (int i = 0; i < n; ++i)
		{
			a[i] = *it++;
			uax(max_c, a[i]);
		}

		suffix_array(a.data(), sa_.data(), n, max_c + 1);
	}

	buf_t alloc_buf(int size)
	{
		return buf_t(size);
	}

	inline bool leq(int a1, int a2, int b1, int b2)
	{
		return a1 < b1 || (a1 == b1 && a2 <= b2);
	}

	inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3)
	{
		return a1 < b1 || (a1 == b1 && leq(a2, a3, b2, b3));
	}

	void cnt_sort(int *a, int *b, int *r, int n, int k)
	{
		auto cnt = alloc_buf(k + 1);
		memset(cnt.data(), 0, (k + 1) * sizeof(*cnt));

		for (int i = 0; i < n; ++i)
		{
			++cnt[r[a[i]]];
		}

		for (int i = 0, sum = 0; i <= k; ++i)
		{
			int tmp = cnt[i];
			cnt[i] = sum;
			sum += tmp;
		}

		for (int i = 0; i < n; ++i)
		{
			b[cnt[r[a[i]]]++] = a[i];
		}
	}

	void suffix_array(int *s, int *sa, int n, int k)
	{
		int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
		auto s0 = alloc_buf(n0);
		auto sa0 = alloc_buf(n0);
		auto s12 = alloc_buf(n02 + 3);
		s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;
		auto sa12 = alloc_buf(n02 + 3);
		sa12[n02] = sa12[n02 + 1] = sa12[n02 + 2] = 0;

		int m = 0;
		for (int i = 0; i < n + n0 - n1; ++i)
		{
			if (i % 3)
			{
				s12[m++] = i;
			}
		}

		cnt_sort(s12.data(), sa12.data(), s + 2, n02, k);
		cnt_sort(sa12.data(), s12.data(), s + 1, n02, k);
		cnt_sort(s12.data(), sa12.data(), s, n02, k);

		m = 0;
		int c0 = int(-1), c1 = int(-1), c2 = int(-1);
		for (int i = 0; i < n02; ++i)
		{
			if (s[sa12[i]] != c0 || s[sa12[i] + 1] != c1 || s[sa12[i] + 2] != c2)
			{
				m++;
				c0 = s[sa12[i]];
				c1 = s[sa12[i] + 1];
				c2 = s[sa12[i] + 2];
			}
			if (sa12[i] % 3 == 1)
			{
				s12[sa12[i] / 3] = m;
			}
			else
			{
				s12[sa12[i] / 3 + n0] = m;
			}
		}

		if (m != n02)
		{
			suffix_array(s12.data(), sa12.data(), n02, m);
			for (int i = 0; i < n02; ++i)
			{
				s12[sa12[i]] = i + 1;
			}
		}
		else
		{
			for (int i = 0; i < n02; ++i)
			{
				sa12[s12[i] - 1] = i;
			}
		}

		m = 0;
		for (int i = 0; i < n02; ++i)
		{
			if (sa12[i] < n0)
			{
				s0[m++] = sa12[i] * 3;
			}
		}

		cnt_sort(s0.data(), sa0.data(), s, n0, k);

		int p = 0;
		int t = n0 - n1;
		for (int z = 0; z < n; ++z)
		{
			int i = (sa12[t] < n0 ? sa12[t] * 3 + 1 : (sa12[t] - n0) * 3 + 2);
			int j = sa0[p];
			if (sa12[t] < n0 ? leq(s[i], s12[sa12[t]+n0], s[j], s12[j / 3]) : leq(s[i], s[i + 1], s12[sa12[t] - n0 + 1], s[j], s[j + 1], s12[j / 3 + n0]))
			{
				sa[z] = i;
				t++;
				if (t == n02)
				{
					for (z++; p < n0; ++p, ++z)
					{
						sa[z] = sa0[p];
					}
				}
			}
			else
			{
				sa[z] = j;
				p++;
				if (p == n0)
				{
					for (z++; t < n02; ++t, ++z)
					{
						sa[z] = (sa12[t] < n0 ? sa12[t] * 3 + 1 : (sa12[t] - n0) * 3 + 2);
					}
				}
			}
		}
	}

	template <typename it_t>
	void calc_lcp(it_t begin, int n)
	{	
		for (int i = 0; i < n; ++i)
		{
			int j = pos_[i];
			if (j == n - 1) lcp_[pos_[i]] = 0;
			else
			{
				int x = (i ? std::max(lcp_[pos_[i - 1]] - 1, 0) : 0);
				j = sa_[j + 1];
				while (i + x < n && j + x < n && *(begin + i + x) == *(begin + j + x)) x++;
				lcp_[pos_[i]] = x;
			}
		}
	}

	std::vector<int> sa_;
	std::vector<int> pos_;
	std::vector<int> lcp_;
	seg_tree_min_t<int> lcp_seg_tree_;
};

const int MAXN = 102000;

int n;
char s[MAXN];
char rs[MAXN];

int pa[MAXN];
i64 sum = 0;

struct suf_set_t
{
	SI poss;
	i64 sum = 0;

	i64 add(const suffix_array_t &sa, int suf)
	{
//		cerr << "add " << s + suf << endl;
		i64 old = sum;
		int pos = sa.pos(suf);
		sum += sa.size() - suf + 1;
		auto it = poss.emplace(pos).first;
		auto itr = next(it);
		if (it != poss.begin())
		{
			auto itl = prev(it);
			if (itr != poss.end())
			{
				sum += sa.lcp(*itl, *itr) + 1;
			}
			sum -= sa.lcp(*itl, *it) + 1;
		}
		if (itr != poss.end())
		{
			sum -= sa.lcp(*it, *itr) + 1;
		}
		return sum - old;
	}

	i64 merge(const suffix_array_t &sa, suf_set_t &&r)
	{
		i64 old = sum + r.sum;
		if (poss.size() < r.poss.size())
		{
			swap(poss, r.poss);
			swap(sum, r.sum);
		}
/*		cerr << "merge:\n";
		for (auto x : poss)
		{
			cerr << s + sa[x] << " ";
		}
		cerr << endl;
		for (auto x : r.poss)
		{
			cerr << s + sa[x] << " ";
		}
		cerr << endl;*/
		for (int suf : r.poss)
		{
			add(sa, sa[suf]);
		}
		r.poss.clear();
		r.sum = 0;
		return sum - old;
	}
};

int find(int x)
{
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}

i64 dull(char const *s, int n)
{
	set<string> w;
	w.insert(string{});
	forn(l, n)
	{
		For(r, l, n - 1)
		{
			string t(s + l, s + r + 1);
			w.insert(t);
			forn(j, t.sz)
			{
				string z = t;
				z[j] = '*';
				w.insert(z);
			}
		}
	}
//	cerr << "w:\n";
//	for (const auto &s : w)
//	{
//		if (s.find('*') == string::npos) continue;
//		if (s.back() != '*') continue;
//		cerr << s << endl;
//	}
//	cerr << "\n";
	return w.sz;
}

void solve()
{
	scanf("%s", s);
	n = strlen(s);
	if (0)
	{
		n = 100000;
		forn(i, n)
		{
			s[i] = 'a' + rand() % 2;
		}
		s[n] = '\0';
	}
//	cerr << "dull=" << dull(s, n) << "\n";
	forn(i, n)
	{
		rs[n - i - 1] = s[i];
	}
	rs[n] = '\0';

	suffix_array_t sa(s, n);
	suffix_array_t rsa(rs, n);

	i64 ans = n * i64(n + 1) / 2 + 1;
	forn(i, n - 1)
	{
		ans -= sa.lcp(i);
	}
//	cerr << ans << endl;

	vector<suf_set_t> f(n + 1);
	SI g;

	sum = 0;
	forn(i, n + 1)
	{
		pa[i] = i;
	}
	vector<VI> q(n);
	ford(llen, n)
	{
		int suf = llen + 1;

		int lsuf = n - llen;
		int lpos = rsa.pos(lsuf);
		sum += f[lpos].add(sa, suf);
		auto it = g.emplace(lpos).first;
		if (it != g.begin())
		{
			auto itl = prev(it);
			int lcp = rsa.lcp(*itl, *it);
			q[lcp].push_back(lpos);
		}
		{
			auto itr = next(it);
			if (itr != g.end())
			{
				int lcp = rsa.lcp(*it, *itr);
				q[lcp].push_back(lpos);
			}
		}

		auto merge = [&](int xx, int yy) {
			int x = find(xx);
			int y = find(yy);
			if (x != y)
			{
				if (rand() & 1) swap(x, y);
				pa[x] = y;
//				cerr << "pref: " << string(s, s + n - rsa[xx]) << " " << string(s, s + n - rsa[yy]) << endl;
				sum += f[y].merge(sa, move(f[x]));
			}
		};

		for (auto x : q[llen])
		{
			auto it = g.find(x);
			if (it != g.end())
			{
				if (it != g.begin())
				{
					auto itl = prev(it);
					int lcp = rsa.lcp(*itl, *it);
					if (lcp == llen)
					{
						merge(*itl, *it);
					}
				}
				auto itr = next(it);
				if (itr != g.end())
				{
					int lcp = rsa.lcp(*it, *itr);
					if (lcp == llen)
					{
						merge(*it, *itr);
					}
				}
			}
		}

//		cerr << "sum=" << sum << "\n\n";
		ans += sum;
	}

/*	forn(i, n)
	{
		printf("%s %d\n", s + sa[i], sa.lcp(i));
//		printf("%s %d\n", rs + rsa[i], rsa.lcp(i));
	}
	printf("---\n");
*/
	cout << ans << endl;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	solve();
	
	return 0;
}