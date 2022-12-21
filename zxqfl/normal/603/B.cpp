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

long long modPow(long long a, long long b, int mod)
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

const int MX = 1.1e6;

int p, k;
VI e[MX];
VI e2[MX];
bool s[MX];
int dep[MX];
bool onstack[MX];
int allowedCycleLength;

bool BAAAAAAD;

void fail()
{
	BAAAAAAD = true;
}

void dfs1(int x, int mydep)
{
	if (dep[x] != -1)
	{
		if (onstack[x] && (mydep - dep[x]) % allowedCycleLength)
			fail();
		return;
	}
	onstack[x] = true;
	dep[x] = mydep;
	foreach(o, e[x])
	{
		dfs1(o, mydep + 1);
	}
	onstack[x] = false;
}

void dfs2(int x)
{
	if (s[x]) return;
	s[x] = true;
	foreach(o, e[x]) dfs2(o);
}

int invert(int x)
{
	return modPow(x, p-2, p);
}

int mul(int a, int b)
{
	return (ll) a * b % p;
}

void add_edge(int a, int b)
{
	// printf("%d -> %d\n", a, b);
	e[a].pb(b);
	e2[a].pb(b);
	e2[b].pb(a);
}

int main()
{
	rint(p); rint(k);
	if (k == 0)
	{
		printf("%d\n", modPow(p, p-1, MOD));
		return 0;
	}
	else if (k == 1)
	{
		printf("%d\n", modPow(p, p, MOD));
		return 0;
	}
	int kinv = invert(k);
	int z = kinv;
	allowedCycleLength = 1;
	while (z != 1)
	{
		++allowedCycleLength;
		z = mul(kinv, z);
	}
	ji(p)
	{
		add_edge(mul(k, i), i);
	}
	ji(MX) dep[i] = -1;
	int ans = 1;
	ji(p)
	{
		BAAAAAAD = false;
		dfs1(i, 0);
		if (BAAAAAAD) dfs2(i);
	}
	ji(p)
	{
		if (!s[i])
		{
			ans = (ll) ans * p % MOD;
			dfs2(i);
		}
	}
	printf("%d\n", ans);
}