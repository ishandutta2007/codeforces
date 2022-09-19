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
const int nax = 101;
int a[nax][nax];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = nax;
	vector <int> which;
	for (int i = 0; i < m; ++i) 
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n - 1; ++i) {
		vector <pii> diffs;
		for (int j = 0; j < m; ++j) {
			diffs.emplace_back(a[j][i] - a[j][n - 1], j);
		}
		sort(diffs.begin(), diffs.end());
		debug << imie(diffs);
		int sum = 0;
		for (pii x : diffs) sum += x.first;
		int curr = 0;
		int p = 0;
		vector <int> now;
		while (sum < 0) {
			curr++;
			sum -= diffs[p].first;
			now.push_back(diffs[p].second);
			p++;
		}
		if (curr < ans) {
			ans = curr;
			which = now;
		}
		//~ ans = min(ans, curr);
		debug << imie(curr);
	}
	printf("%d\n", ans);
	for (int x : which) printf("%d ", x + 1);
	printf("\n");
}