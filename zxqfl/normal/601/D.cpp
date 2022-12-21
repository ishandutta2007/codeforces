#include <bits/stdc++.h>
using namespace std;

#define jjs(i, s, x) for (int i = (s); i < int(x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rint(x);
#define rfloat(x) scanf("%lf", &(x))

#define rint readInteger
template<typename T>
bool readInteger(T& x)
{
	char c,r=0,n=0;
	x=0;
	for (ever)
	{
		c=getchar();
		if ((c<0) && (!r))
			return(0);
		else if ((c=='-') && (!r))
			n=1;
		else if ((c>='0') && (c<='9'))
			x=x*10+c-'0',r=1;
		else if (r)
			break;
	}
	if (n)
		x=-x;
	return(1);
}

const int MOD = 1000000007;

long long modPow(long long a, long long b, int mod = MOD)
{
	assert(b >= 0);
	long long ret = 1 % mod;
	while (b)
	{
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> VPI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;

const int MX = 3.1e5;
int ci[MX];
char letstr[MX];
int let[MX];
VI E[MX];
VI child[MX];
int par[MX];
int f[MX];
struct trie;
trie* myTrie[MX];
int n;

struct trie
{
	int dif;
	trie* edg[26];

	trie()
	{
		ji(26) edg[i] = NULL;
	}
};

int get_dif(trie* t)
{
	if (!t) return 0;
	return t->dif;
}

void recalc(trie* t)
{
	t->dif = 1;
	ji(26) t->dif += get_dif(t->edg[i]);
}

trie* merge(trie* a, trie* b)
{
	if (!a) return b;
	if (!b) return a;
	trie* ret = new trie();
	ji(26) ret->edg[i] = merge(a->edg[i], b->edg[i]);
	recalc(ret);
	return ret;
}

void init(int x)
{
	foreach(o, E[x])
	{
		if (o != par[x])
		{
			par[o] = x;
			child[x].pb(o);
			init(o);
		}
	}
}

void solve(int x)
{
	trie*& t = myTrie[x];
	t = new trie();
	foreach(o, child[x])
	{
		solve(o);
		t->edg[let[o]] = merge(t->edg[let[o]], myTrie[o]);
	}
	recalc(t);
}

int main()
{
	rint(n);
	ji(n) rint(ci[i]);
	scanf("%s", letstr);
	ji(n) let[i] = letstr[i] - 'a';
	jk(n-1)
	{
		int a, b;
		rint(a); rint(b);
		--a; --b;
		E[a].pb(b);
		E[b].pb(a);
	}
	par[0] = -1;
	init(0);
	solve(0);
	int mx = -1;
	int cnt = 0;
	ji(n)
	{
		int q = ci[i] + myTrie[i]->dif;
		if (q > mx)
			mx = q, cnt = 1;
		else if (q == mx)
			++cnt;
	}
	printf("%d\n%d\n", mx, cnt);
}