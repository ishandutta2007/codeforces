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

const int MX = 505;
int dp[MX][MX];

int main()
{
	int n;
	rint(n);
	int c[n];
	ji(n) rint(c[i]);
	jjl(diff, n)
	{
		jjl(a, n)
		{
			int b = a + diff;
			if (b >= n) break;
			if (diff == 0)
				dp[a][b] = 1;
			else if (diff == 1)
				dp[a][b] = (c[a] == c[b] ? 1 : 2);
			else
			{
				dp[a][b] = INF;
				if (c[a] == c[b])
					dp[a][b] = min(dp[a][b], dp[a+1][b-1]);
				for (int split = a; split < b; split++)
					dp[a][b] = min(dp[a][b], dp[a][split] + dp[split+1][b]);
			}
		}
	}
	printf("%d\n", dp[0][n-1]);
}