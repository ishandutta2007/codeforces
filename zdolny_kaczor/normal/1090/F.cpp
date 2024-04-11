//Konrad Paluszek, University of Warsaw (former XIV LO Warsaw)
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<< (
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)), muu&>::type operator<<(c g) {
sim> struct rge {c h, n;};
sim> rge<c> range(c h, c n) {return rge<c>{h, n};}
sim, class F> struct rgm {c h, n; F f;};
sim, class F> rgm<c, F> map_range(c b, c e, F f) {return rgm<c, F>{b, e, f};}
sim, class F> rgm<typename c::const_iterator, F> map_range(const c &x, F f) {return map_range(x.begin(), x.end(), f);}
sim> auto dud(c *r) -> decltype(cerr << *r);
sim> char dud(...);
struct muu {
#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << '{';
		for (c s = u.h; s != u.n; ++s)
			*this << ", " + 2 * (s == u.h) << *s;
		ris << '}';
	}
	sim, class n mor pair <c,n> r) {ris << "(" << r.first << ", " << r.second << ")";}
	sim, class F mor rgm<c, F> u) {
		for (c s = u.h; s != u.n; ++s)
			u.f(*this << ", " + 2 * (s == u.h), *s);
		ris;
	}
	#else
	sim mor const c&) {ris;}
	#endif
	muu & operator()() {ris;}
};
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": ")
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
const int nax = 1e3 + 44;
int n;
long long ans[nax];
#ifdef LOCAL
long long c[nax];
#endif
map <array <int, 3>, long long> cache;
long long query(int i, int j, int k) {
	long long a;
	auto it = cache.find(array<int, 3>{i, j, k});
	if (it != cache.end())
		return it->second;
	assert(i != j && i != k && j != k);
#ifdef LOCAL
	a = max(max(c[i], c[j]), c[k]) + 1ll * min(min(c[i], c[j]), c[k]);
#else
	printf("\? %d %d %d\n", i, j, k);
	fflush(stdout);
	scanf("%lld", &a);
#endif
	cache[array<int, 3>{i, j, k}] = a;
	return a;
}
void answer() {
#ifdef LOCAL
	bool OK = true;
	for (int i = 1; i <= n; ++i)
		if (ans[i] != c[i]) {
			debug << "WA " arr(ans, i) arr(c, i);
			OK = false;
		}
	assert(OK);
#else
	printf("!");
	for (int i = 1; i <= n; ++i)
		printf(" %lld", ans[i]);
	printf("\n");
	fflush(stdout);
	exit(0);
#endif
}
using equ = pair <array<int, 5>, long long>;
void solve(int lowest) {
	int highest = lowest + 4;
	vector <pair <array <int, 5>, long long> > inputs;
	for (int i = lowest; i <= highest; ++i)
		for (int j = i + 1; j <= highest; ++j)
			for (int k = j + 1; k <= highest; ++k) {
				array <int, 5> which = {};
				which[i - lowest] = which[j - lowest] = which[k - lowest] = 1;
				inputs.emplace_back(which, query(i, j, k));
			}
	vector <int> order = {0, 1, 2, 3, 4};
	vector <long long> val(5);
	do {
		array <int, 5> lm = {};
		array <int, 5> lh = {};
		array <int, 5> mh = {};
		array <int, 5> v134 = {}, v013 = {};
		lm[order[0]] = lm[order[1]] = lm[order[2]] = lh[order[0]] = lh[order[2]] = lh[order[4]] = mh[order[2]] = mh[order[3]] = mh[order[4]] = 1;
		v134[order[1]] = v134[order[3]] = v134[order[4]] = 1;
		v013[order[0]] = v013[order[1]] = v013[order[3]] = 1;
		long long lm_val = -1, lh_val = -1, mh_val = -1, v134_val = -1, v013_val = -1;
		for (auto &x : inputs) {
			if (x.first == lm)
				lm_val = x.second;
			else if (x.first == lh)
				lh_val = x.second;
			else if (x.first == mh)
				mh_val = x.second;
			else if (x.first == v013)
				v013_val = x.second;
			else if (x.first == v134)
				v134_val = x.second;
		}
		assert(lm_val >= 0 && lh_val >= 0 && mh_val >= 0 && v134_val >= 0 && v013_val >= 0);
		long long sum = (lm_val + lh_val + mh_val);
		if (sum % 2)
			continue;
		sum /= 2;
		val[order[0]] = sum - mh_val;
		val[order[2]] = sum - lh_val;
		val[order[4]] = sum - lm_val;
		val[order[1]] = v134_val - val[order[4]];
		val[order[3]] = v013_val - val[order[0]];
		bool good = true;
		for (long long x : val)
			if (x < 0) {
				good = false;
				break;
			}
		if (!good) continue;
		for (equ &u : inputs) {
			vector <long long> pos;
			for (int i = 0; i < 5; ++i)
				if (u.first[i])
					pos.push_back(val[i]);
			sort(pos.begin(), pos.end());
			long long v = pos[0] + pos[2];
			if (v != u.second) {
				debug << "err on " imie(u) imie(v);
				good = false;
				break;
			}
		}
		if (good) {
			for (int i = 0; i < 5; ++i)
				ans[lowest + i] = val[i];
			return;
		}
	} while (next_permutation(order.begin(), order.end()));
	assert(false);
}
int main() {
	scanf("%d", &n);
#ifdef LOCAL
	for (int i = 1; i <= n; ++i)
		scanf("%lld", c + i);
#endif
	for (int i = 1; i + 4 <= n; i += 5)
		solve(i);
	if (n % 5)
		solve(n - 4);
	answer();
}