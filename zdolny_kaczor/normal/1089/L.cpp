#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
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
	sim, class m mor pair<m,c> r) {ris << "(" << r.first << ", " << r.second << ")";}
	#else
	sim mor const c &){ris;}
	#endif
	muu & operator()(){ris;}
};
#define imie(r) "[" #r ": " << (r) << "] "
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": " )

const int N = 1e5 + 7;
int n, k;
vector<int> kto[N];
int koszt[N];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		kto[x].push_back(i);
	}
	
	for (int i = 1; i <= n; ++i) scanf("%d", &koszt[i]);

	int ile = 0;
	for (int i = 1; i <= k; ++i) {
		if (kto[i].empty()) ile++;
	}
	
	vector<int> tab;
	for (int i = 1; i <= k; ++i) {
		if (!kto[i].empty()) {
			sort (kto[i].begin(), kto[i].end(), [](int a, int b) -> bool {
				return koszt[a] > koszt[b];
			});
			for (int j = 1; j < (int) kto[i].size(); ++j) tab.push_back(koszt[kto[i][j]]);
		}
	}
	
	long long res = 0;
	sort (tab.begin(), tab.end());
	for (int i = 0; i < ile; ++i) res += tab[i];
	printf("%lld\n", res);
}