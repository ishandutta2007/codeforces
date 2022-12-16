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

const int MX = 5010;

int n;
int digits[MX];
char str[MX];
int pre[MX][MX];
int match[MX][MX];
ll dp[MX];

int z[MX];

template <typename T>
void Z(const vector<T>& inp)
{
	int L = 0, R = 0;
	for (int i = 1; i < inp.size(); i++) {
	  if (i > R) {
	    L = R = i;
	    while (R < n && inp[R-L] == inp[R]) R++;
	    z[i] = R-L; R--;
	  } else {
	    int k = i-L;
	    if (z[k] < R-i+1) z[i] = z[k];
	    else {
	      L = i;
	      while (R < n && inp[R-L] == inp[R]) R++;
	      z[i] = R-L; R--;
	    }
	  }
	}
}

int main()
{
	rint(n);
	scanf("%s", str);
	ji(n)
	{
		digits[i] = str[i] - '0';
	}
	jjl(start, n)
	{
		VI v;
		jjs(i, start, n)
			v.pb(digits[i]);
		Z(v);
		match[start][start] = n - start;
		jjs(i, start + 1, n)
		{
			match[start][i] = z[i-start];
		}
	}
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = i; j < n; j++)
		{
			if (j == n-1)
				dp[j] = 1;
			else
			{
				int k = j+1;
				int len = j - i + 1;
				if (k + len - 1 >= n || digits[k] == 0)
					dp[j] = 0;
				else
				{
					int mat = match[i][k];
					if (mat >= len || digits[i+mat] > digits[k+mat])
						dp[j] = pre[k][k+len];
					else
						dp[j] = pre[k][k+len-1];
				}
			}
		}
		for (int j = n-1; j >= 0; j--)
		{
			pre[i][j] = (dp[j] + pre[i][j+1]) % MOD;
		}
	}
	printf("%d\n", pre[0][0]);
}