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
const int nax=1000*1007;

int n, m;

char wcz[nax];

vi graf[nax];
vi farg[nax];

pii tab[nax];

int osio[nax];

int daj(int v)
{
	int od=0;
	if (v<0)
	{
		v*=-1;
		od=1;
	}
	return 2*v-od;
}

int dru(int v)
{
	if (v&1)
		return v+1;
	return v-1;
}

void kra(int a, int b)
{
	//~ debug() << "kra " << a << " " << b;
	graf[a].push_back(b);
	farg[b].push_back(a);
}

void klau(int a, int b)
{
	a=daj(a);
	b=daj(b);
	debug() << "kla " << a << " " << b;
	kra(dru(a), b);
	kra(dru(b), a);
}

void dfs1(int v, int limit)
{
	if (osio[v]==2)
		return;
	//~ debug() << v << " " << farg[v];
	osio[v]=2;
	//~ if (wcz[(v+1)/2]=='E' && v<=limit)
		//~ kra(v, dru(v));
	for (int i=0; i<(int)farg[v].size(); i++)
	{
		//~ debug() << "z " << v << " do " << i;
		dfs1(farg[v][i], limit);
	}
}

int bylo[nax];
int post[nax];
int spo[nax];
int czas;

void dfs2(int v)
{
	if (bylo[v])
		return;
	bylo[v]=1;
	for (int i : graf[v])
		dfs2(i);
	czas++;
	post[czas]=v;
}

void dfs3(int v)
{
	if (spo[v])
		return;
	spo[v]=czas;
	for (int i : farg[v])
		dfs3(i);
}

vi przez[nax];

int zle;

int czyw(vi &wek, int v)
{
	for (int i : wek)
		if (i==v)
			return 1;
	return 0;
}

void dfs4(int v, int sko)
{
	if ((int)przez[v].size()>=2 || czyw(przez[v], sko))
		return;
	przez[v].push_back(sko);
	if (v!=sko && wcz[(v+1)/2]=='A')
		zle=1;
	for (int i : graf[v])
		dfs4(i, sko);
}

void test()
{
	scanf("%d%d", &n, &m);
	scanf("%s", wcz+1);
	for (int i=1; i<=n*2; i++)
	{
		graf[i].clear();
		farg[i].clear();
		osio[i]=0;
	}
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		tab[i]={a, b};
		klau(a, b);
	}
	debug() << "a";
	for (int i=n; i; i--)
	{
		if (wcz[i]=='A')
		{
			osio[2*i]=osio[2*i-1]=1;
		}
		else
		{
			for (int h=2*i-1; h<=2*i; h++)
				for (int j : graf[h])
					if (osio[j])
						osio[h]=1;
		}
		for (int h=2*i-1; h<=2*i; h++)
		{
			if (osio[h] && wcz[i]=='E')
			{
				kra(h, dru(h));
				//~ kra(dru(h), h);
				debug() << h << " " << dru(h);
			}
		}
		for (int h=2*i-1; h<=2*i; h++)
		{
			if (osio[h])
			{
				dfs1(h, 2*i);
			}
		}
	}
	//~ debug() << "b";
	czas=0;
	for (int i=1; i<=2*n; i++)
		bylo[i]=post[i]=spo[i]=0;
	for (int i=1; i<=2*n; i++)
		dfs2(i);
	//~ debug() << "c";
	czas=0;
	//~ for (int i=1; i<=2*n; i++)
		//~ debug() << i << " " << graf[i];
	for (int i=2*n; i; i--)
	{
		int v=post[i];
		if (spo[v])
			continue;
		czas++;
		dfs3(v);
	}
	for (int i=1; i<=n; i++)
	{
		if (spo[daj(i)]==spo[daj(-i)])
		{
			printf("FALSE\n");
			return;
		}
	}
	zle=0;
	for (int i=1; i<=2*n; i++)
		przez[i].clear();
	for (int i=1; i<=n; i++)
	{
		if (wcz[i]=='A')
		{
			dfs4(2*i-1, 2*i-1);
			dfs4(2*i, 2*i);
		}
	}
	debug() << "nom";
	
	
	if (zle)
		printf("FALSE\n");
	else
		printf("TRUE\n");
	//~ printf("KUPA\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}