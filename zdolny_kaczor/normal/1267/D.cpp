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
const int maxn = 300;
using Pii = pii;
int n;
int potrzebuje[maxn];
int testuje[maxn];
int propaguje[maxn];
bool zaspokojony[maxn];
int maski[8];
vector<Pii> res;
bool bez_testow[maxn];
void uzupelnij(int ind)
{
	int zapotrz = potrzebuje[ind];
	if(zapotrz == 0)
	{
		zaspokojony[ind] = true;
		return;
	}
	if(maski[zapotrz] != -1)
	{
		res.push_back({maski[zapotrz], ind});
		maski[propaguje[ind]] = ind;
	}
	else
	{
		if(__builtin_popcount(zapotrz) != 2)
		{
			puts("Impossible");
			exit(0);
		}
		int a = zapotrz & (zapotrz - 1);
		int b = zapotrz - a;
		if(maski[a] == -1 || maski[b] == -1)
		{
			puts("Impossible");
			exit(0);
		}
		res.push_back({maski[a], ind});
		res.push_back({maski[b], ind});
		maski[zapotrz] = ind;
		bez_testow[ind] = true;
	}
	zaspokojony[ind] = true;
}
void zachlan()
{
	for(int tt = 0; tt < 20; ++tt)
		for(int i = 0; i < n; ++i)
			if(!zaspokojony[i])
			{
				if(maski[potrzebuje[i]] != -1)
				{
					uzupelnij(i);
					
				}
			}
}
bool da_sie(int v)
{
	int zap = potrzebuje[v];
	if(__builtin_popcount(zap) != 2)
		return false;
	int a = zap & (zap - 1);
	int b = zap - a;
	if(maski[a] == -1 || maski[b] == -1)
		return false;
	return true;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			int v;
			scanf("%d", &v);
			potrzebuje[i] += v << j;
		}
	}
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			int v;
			scanf("%d", &v);
			testuje[i] += v << j;
		}
		propaguje[i] = testuje[i] & potrzebuje[i];
	}
	zaspokojony[0] = true;
	for(int i = 0; i < 7; ++i)
		maski[i] = -1;
	maski[7] = 0;
	zachlan();
	for(int i = 0; i < n; ++i)
		if(!zaspokojony[i])
			uzupelnij(i);
	if(res.size() <= 264)
	{
		puts("Possible");
		for(int i = 0; i < n; ++i)
		{
			int v = 1;
			if(bez_testow[i])
				v = 0;
			printf("%d ", v);
		}
		puts("");
		printf("%d\n", (int)res.size());
		for(Pii p : res)
			printf("%d %d\n", p.first + 1, p.second + 1);
	}
	else
		puts("Impossible");
		
		
		
		
		
}