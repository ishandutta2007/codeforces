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
const int nax=507;
const int inf=1e9;

int n, m;

vi graf[nax];

int odl[nax][nax];

void ff()
{
	fflush(stdout);
}

char wcz[17];

int pyt(int v)
{
	printf("%d\n", v);
	ff();
	scanf("%s", wcz);
	if (wcz[0]=='F')
		return 0;
	scanf("%d", &v);
	return v;
}

void dawaj()
{
	vi wek(n);
	iota(wek.begin(), wek.end(), 1);
	while(1)
	{
		pii mog={inf, -1};
		for (int i : wek)
		{
			int naj=0;
			for (int j : graf[i])
			{
				int ile=0;
				for (int l : wek)
					if (odl[j][l]<odl[i][l])
						ile++;
				naj=max(naj, ile);
			}
			mog=min(mog, {naj, i});
		}
		int x=mog.second;
		int w=pyt(x);
		if (!w)
			break;
		vi pom=wek;
		wek.clear();
		for (int i : pom)
			if (odl[w][i]<odl[x][i])
				wek.push_back(i);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		while(a--)
		{
			int c;
			scanf("%d", &c);
			graf[b].push_back(c);
			graf[c].push_back(b);
			b=c;
		}
	}
	for (int i=1; i<=n; i++)
	{
		queue <int> kol;
		for (int j=1; j<=n; j++)
			odl[i][j]=-1;
		kol.push(i);
		odl[i][i]=0;
		while(!kol.empty())
		{
			int v=kol.front();
			kol.pop();
			for (int j : graf[v])
			{
				if (odl[i][j]==-1)
				{
					odl[i][j]=odl[i][v]+1;
					kol.push(j);
				}
			}
		}
		//~ debug() << range(odl[i]+1, odl[i]+1+n);
	}
	for (int h=1; h<=n; h++)
		dawaj();
	return 0;
}