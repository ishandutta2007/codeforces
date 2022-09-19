#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim>typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c*r)->decltype(cerr << *r);
sim> char dud(...);
struct muu {
	#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << "[";
		for (c i = u.b; i != u.e; ++i)
			*this << ", " + 2 * (i == u.b) << *i;
		ris << "]";
	}
	sim, class m mor pair <m,c>r){ris << "(" << r.first << ", " << r.second << ")";}
	#else
	sim mor const c&){ris;}
	#endif
};
#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r...) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair <int, int>;
using ll = long long;
using ull = unsigned long long;
ull mix(ull a) {
	a += 42042011342033ull;
	a = (a ^ (a >> 30)) * 41203420577ull;
	a = (a ^ (a >> 31)) * 998244353333ull;
	return (a ^ (a >> 27));
}
ull H(const vector <int> &v) {
	ull ans = 0;
	for (int x : v) ans = mix(ans ^ x);
	return ans;
}
unordered_map<ull, ll> cache;
const int nax = 30;
ll cho[nax][nax];
ll go(vector <int> v) {
	if (v.empty()) return 1;
	int n = v.size();
	for (int i = 0; i < n - 1; ++i) {
		if (v[i] > i + 1) return 0;
	}
	ull h = H(v);
	auto it = cache.find(h);
	if (it != cache.end()) return it->second;
	ll ans = 0;
	for (int c = 0; c < 2; ++c) {
		bool has = false;
		for (int x : v) if (x == c) has = true;
		if (!has) continue;
		vector <int> sub;
		bool did = false;
		int ze = 0, ne = 0;
		for (int x : v) {
			if (x == c && !did) did = true;
			else {
				if (x == 1) ze++;
				else if (x == 0) ne++;
				sub.push_back(max(0, x - 1));
			}
		}
		debug << imie(ze) imie(ne) imie(cho[ze + ne][ne]);
		debug << imie(v) imie(c) imie(sub);
		ans += go(sub) * cho[ze + ne][ne];
	}
	return cache[h] = ans;
}
int main() {
	int t;
	scanf("%d", &t);
	cho[0][0] = 1;
	for (int i = 1; i < nax; ++i) {
		cho[i][0] = cho[i][i] = 1;
		for (int j = 1; j < i; ++j) cho[i][j] = cho[i - 1][j] + cho[i - 1][j - 1];
	}
	while (t--) {
		ll k;
		scanf("%lld", &k);
		vector <int> code;
		int m = 2;
		while (k) {
			code.push_back(k % m);
			k /= m;
			m++;
		}
		debug << imie(code);
		sort(code.begin(), code.end());
		ll ans = go(code);
		if (code[0] == 0) {
			code.erase(code.begin());
			ans -= go(code);
		}
		printf("%lld\n", ans - 1);
	}
}
//~ kp371301@white15:~/kontest$ ./k < kin1 
//~ main#101: [code: [1]] 
//~ go#77: [ze: 0] [ne: 0] [cho[ze + ne][ne]: 1] 
//~ go#78: [v: [1]] [c: 1] [sub: []] 
//~ 0
//~ main#101: [code: [1, 2, 1]] 
//~ go#77: [ze: 1] [ne: 0] [cho[ze + ne][ne]: 1] 
//~ go#78: [v: [1, 1, 2]] [c: 1] [sub: [0, 1]] 
//~ go#77: [ze: 1] [ne: 0] [cho[ze + ne][ne]: 1] 
//~ go#78: [v: [0, 1]] [c: 0] [sub: [0]] 
//~ go#77: [ze: 0] [ne: 0] [cho[ze + ne][ne]: 1] 
//~ go#78: [v: [0]] [c: 0] [sub: []] 
//~ go#77: [ze: 0] [ne: 1] [cho[ze + ne][ne]: 1] 
//~ go#78: [v: [0, 1]] [c: 1] [sub: [0]] 
//~ 1
//~ main#101: [code: [0, 0, 0, 4, 2, 3, 0, 3]] 
//~ go#77: [ze: 0] [ne: 3] [cho[ze + ne][ne]: 1] 
//~ go#78: [v: [0, 0, 0, 0, 2, 3, 3, 4]] [c: 0] [sub: [0, 0, 0, 1, 2, 2, 3]] 
//~ go#77: [ze: 1] [ne: 2] [cho[ze + ne][ne]: 3] 
//~ go#78: [v: [0, 0, 0, 1, 2, 2, 3]] [c: 0] [sub: [0, 0, 0, 1, 1, 2]] 
//~ go#77: [ze: 2] [ne: 2] [cho[ze + ne][ne]: 6] 
//~ go#78: [v: [0, 0, 0, 1, 1, 2]] [c: 0] [sub: [0, 0, 0, 0, 1]] 
//~ go#77: [ze: 1] [ne: 3] [cho[ze + ne][ne]: 4] 
//~ go#78: [v: [0, 0, 0, 0, 1]] [c: 0] [sub: [0, 0, 0, 0]] 
//~ go#77: [ze: 0] [ne: 3] [cho[ze + ne][ne]: 1] 
//~ go#78: [v: [0, 0, 0, 0]] [c: 0] [sub: [0, 0, 0]] 
//~ go#77: [ze: 0] [ne: 2] [cho[ze + ne][ne]: 1] 
//~ go#78: [v: [0, 0, 0]] [c: 0] [sub: [0, 0]] 
//~ go#77: [ze: 0] [ne: 1] [cho[ze + ne][ne]: 1] 
//~ go#78: [v: [0, 0]] [c: 0] [sub: [0]] 
//~ go#77: [ze: 0] [ne: 4] [cho[ze + ne][ne]: 1] 
//~ go#78: [v: [0, 0, 0, 0, 1]] [c: 1] [sub: [0, 0, 0, 0]] 
//~ go#77: [ze: 1] [ne: 3] [cho[ze + ne][ne]: 4] 
//~ go#78: [v: [0, 0, 0, 1, 1, 2]] [c: 1] [sub: [0, 0, 0, 0, 1]] 
//~ go#77: [ze: 0] [ne: 3] [cho[ze + ne][ne]: 1] 
//~ go#78: [v: [0, 0, 0, 1, 2, 2, 3]] [c: 1] [sub: [0, 0, 0, 1, 1, 2]] 
//~ 199
//~ kp371301@white15:~/kontest$ ./k < kin1