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
const int maxn = 4e5;
char buff[maxn];
int main() {
	scanf("%s", buff);
	vector<pair<char, int>> repr;
	char curr = buff[0];
	int ile = 1;
	for(int i = 1; buff[i]; ++i)
	{
		if(curr != buff[i])
		{
			repr.push_back({curr, ile});
			curr = buff[i];
			ile = 0;
		}
		++ile;
	}
	repr.push_back({curr, ile});
	if(repr.size() % 2 == 0)
	{
		puts("0");
		return 0;
	}
	int sz = repr.size();
	if(repr[sz/2].second < 2)
	{
		puts("0");
		return 0;
	}
	for(int i = 0; i < sz / 2; ++i)
	{
		if(repr[i].first != repr[sz - 1 - i].first)
		{
			puts("0");
			return 0;
		}
		if(repr[i].second +  repr[sz - 1 - i].second < 3)
		{
			puts("0");
			return 0;
		}
	}
	printf("%d\n", repr[sz / 2].second + 1);
}