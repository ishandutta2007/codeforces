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
int n;
void solve()
{
	scanf("%d", &n);
	vector<int> V(n);
	for(int i = 0; i < n; ++i)
	{
		int c;
		scanf("%d", &c);
		--c;
		++V[c];
	}
	vector<int> legit(n+2);
	int niezero = 0;
	//~ vector<int> rozm(n);
	for(int i = 0; i < n; ++i)
		if(V[i] > 0)
		{
			++niezero;
			int r = V[i];
			vector<bool> ok(r + 2);
			for(int j = 1; j <= r; ++j)
			{
				int ne = (r + j - 1) / j;
				ok[ne] = true;
				if(r / j == ne)
					ok[ne + 1] = true;
			}
			for(int j = 0; j <= r + 1; ++j)
				if(ok[j])
					legit[j]++;
		}
	for(int i = n; i >= 1; --i)
	{
		if(legit[i] == niezero)
		{
			int res = 0;
			for(int j = 0; j < n; ++j)
				if(V[j] > 0)
				{
					debug << imie(V[j]) << imie((V[j] + i - 1) / i);
					res += (V[j] + i - 1) / i;
				}
			printf("%d\n", res);
			return;
		}
	}

	
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}