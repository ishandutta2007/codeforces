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

const int MX = 1.1e5;

bool seen[MX];
int cycle[MX];
VVI cycles;
int p[MX];
int N;
VPI edges;

VI cy;

void dfs(int x, int id)
{
	if (seen[x]) return;
	seen[x] = true;
	cycle[x] = id;
	cy.pb(x);
	dfs(p[x], id);
}

void selfConnect(VI& z)
{
	edges.pb({z[0], z[1]});
}

void connect(VI& a, VI& b)
{
	ji(b.size())
	{
		edges.pb({a[i%2], b[i]});
	}
}

int main()
{
	rint(N);
	ji(N) rint(p[i]);
	ji(N) --p[i];
	ji(N) if (!seen[i])
	{
		cy.clear();
		dfs(i, cycles.size());
		cycles.pb(cy);
	}
	int S = cycles.size();
	int i1 = -1;
	ji(S) if (cycles[i].size() == 1) i1 = i;
	if (i1 != -1)
	{
		printf("YES\n");
		ji(N) if (i != cycles[i1][0]) printf("%d %d\n", i+1, cycles[i1][0]+1);
		return 0;
	}
	int i2 = -1;
	ji(S) if (cycles[i].size() == 2) i2 = i;
	ji(S) if (cycles[i].size() % 2 != 0 || i2 == -1)
	{
		printf("NO\n");
		return 0;
	}
	selfConnect(cycles[i2]);
	ji(S) if (i != i2)
		connect(cycles[i2], cycles[i]);
	printf("YES\n");
	foreach(z, edges) printf("%d %d\n", z.first+1, z.second+1);
}