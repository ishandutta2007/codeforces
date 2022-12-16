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

const int MX = 510;

int n, m;
bool adj[MX][MX];
int deg[MX];
bool active[MX];
char ans[MX];

VI bin;
void dfs(int x)
{
	if (!active[x])
		return;
	active[x] = false;
	bin.push_back(x);
	ji(n) if (adj[x][i])
		dfs(i);
}

void fail()
{
	printf("No\n");
	exit(0);
}

int main()
{
	rint(n); rint(m);
	jk(m)
	{
		int a, b;
		rint(a); rint(b);
		--a; --b;
		++deg[a]; ++deg[b];
		adj[a][b] = adj[b][a] = true;
	}
	ji(n) active[i] = deg[i] != n-1;
	ji(n) if (deg[i] == n-1) ans[i] = 'b';
	vector<vector<int>> components;
	ji(n) {
		if (active[i]) {
			if (components.size() == 2)
				fail();
			bin.clear();
			dfs(i);
			components.push_back(bin);
		}
	}
	ji(components.size())
	{
		char c = "ac"[i];
		for (int x : components[i])
			for (int y : components[i])
				if (x != y && !adj[x][y])
					fail();
		for (int x : components[i])
			ans[x] = c;
	}
	printf("Yes\n%s\n", ans);
}