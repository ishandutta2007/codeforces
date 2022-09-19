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

using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;
using pll=pair<ll,ll>;
using vll=vector<ll>;
const int nax=2100*1007;
const int n1=(1<<20);
const ll inf=1e18;

int q;
ll dod[nax];
ll spod[nax];

ll ile[nax];
ll gdz[nax];

ll daj(int v)
{
	return dod[v]+spod[v];
}

void upd(int v)
{
	spod[v]=max(daj(v*2), daj(v*2+1));
}

void dodaj(int v, int a, int b, int graa, int grab, ll w)
{
	if (a>=graa && b<=grab)
	{
		dod[v]+=w;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	dodaj((v<<1), a, (a+b)>>1, graa, grab, w);
	dodaj((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	upd(v);
}

ll czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return daj(v);
	}
	if (a>grab || b<graa)
	{
		return -inf;
	}
	ll r1=czyt((v<<1), a, (a+b)>>1, graa, grab);
	ll r2=czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab);
	return max(r1, r2)+dod[v];
}

int main()
{
	for (int i=1; i<=n1; i++)
		dodaj(1, 1, n1, i, i, i);
	scanf("%d", &q);
	for (int h=1; h<=q; h++)
	{
		char c;
		scanf(" %c", &c);
		if (c=='?')
		{
			int x;
			scanf("%d", &x);
			ll wyn=czyt(1, 1, n1, 1, x)-(czyt(1, 1, n1, x+1, x+1)-(x+1));
			printf("%lld\n", wyn-x);
		}
		if (c=='+')
		{
			scanf("%lld%lld", &gdz[h], &ile[h]);
			dodaj(1, 1, n1, 1, gdz[h], ile[h]);
			//~ assert(0);
		}
		if (c=='-')
		{
			int x;
			scanf("%d", &x);
			dodaj(1, 1, n1, 1, gdz[x], -ile[x]);
			//~ assert(0);
		}
	}
	return 0;
}