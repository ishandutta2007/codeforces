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

const int MX = 1010;
const int LIM = 100 * MX + 10;

int n, m;
int x[MX];

long double dp[LIM];
long double pre[LIM];

int main()
{
	rint(n); rint(m);
	ji(n) rint(x[i]);
	if (m == 1)
	{
		printf("1\n");
		return 0;
	}
	int myscore = 0;
	ji(n) myscore += x[i];
	ji(LIM) dp[i] = pre[i] = 0;
	dp[0] = 1;
	ji(n)
	{
		int a = i*m+1;
		int b = (i+1)*m+1;
		jj(b) pre[j] = 0;
		jj(a)
		{
			long double z = dp[j] / (m - 1);
			pre[j+1] += z;
			pre[j+x[i]] -= z;
			pre[j+x[i]+1] += z;
			pre[j+m+1] -= z;
		}
		dp[0] = 0;
		jjs(j, 1, b) dp[j] = dp[j-1] + pre[j];
	}
	long double ex = 0;
	ji(myscore) ex += dp[i];
	ex *= (m - 1);
	ex += 1;
	printf("%.15f\n", (double) ex);
}