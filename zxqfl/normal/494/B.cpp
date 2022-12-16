#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define INF ((int) 1e9+10)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

char s[100001], t[100001];
int sL, tL;
int f[100010];
bool isMatch[100001];

int main()
{
	scanf("%s%s", s, t);
	sL = strlen(s);
	tL = strlen(t);

	f[0] = f[1] = 0;
	for (int i = 2; i <= tL; i++)
	{
		int crnt = f[i-1];
		while (crnt > 0 && t[i-1] != t[crnt])
			crnt = f[crnt];
		if (t[i-1] == t[crnt])
			f[i] = crnt + 1;
		else
			f[i] = 0;
	}
	int clen = 0;
	vector<int> matches;
	ji(sL)
	{
		while (s[i] != t[clen] && clen > 0)
			clen = f[clen];
		if (s[i] == t[clen])
			clen++;
		else
			clen = 0;
		if (clen == tL)
		{
			matches.pb(i - clen + 1);
			isMatch[i-clen+1] = true;
			clen = f[clen];
		}
	}

	ll dp[sL+1];
	dp[sL] = 1;
	int rend = sL;
	ll tsum = 0;
	for (int i = sL-1; i >= 0; i--)
	{
		dp[i] = dp[i+1];
		if (isMatch[i])
		{
			while (rend >= i+tL)
			{
				tsum += dp[rend];
				tsum %= MOD;
				rend--;
			}
		}
		dp[i] += tsum;
		dp[i] %= MOD;
	}
	printf("%lld\n", (dp[0]-1+MOD)%MOD);
}