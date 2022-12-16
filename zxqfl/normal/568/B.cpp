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
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> VPI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;

ll pw(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return ans;
}

const int MX = 4010;

ll pasc[MX][MX];

int main()
{
	jij(MX, MX)
		if (j == 0) pasc[i][j] = 1;
		else if (j > i) pasc[i][j] = 0;
		else pasc[i][j] = (pasc[i-1][j-1] + pasc[i-1][j]) %  MOD;
	ll N;
	rint(N);
	ll dp[N+1];
	dp[0] = 1;
	jjs(i, 1, N+1)
	{
		dp[i] = 0;
		jjl(oth, i)
		{
			dp[i] += pasc[i-1][oth] * dp[i-oth-1] % MOD;
		}
		dp[i] %= MOD;
	}
	ll base = 0;
	jjs(i, 1, N+1)
	{
		base += pasc[N][i] * dp[N-i] % MOD;
		base %= MOD;
	}
	printf("%lld\n", base);
}