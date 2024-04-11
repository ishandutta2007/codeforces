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

int N, L, S;
ll a[100000];

int main()
{
	rint(N); rint(S); rint(L); 
	ji(N) rlong(a[i]);

	int dp[N+1];
	dp[N] = 0;

	multiset<ll> cstrip;
	priority_queue<pi, vector<pi>, greater<pi> > Q;
	int r = N;
	for (int i = N-1; i >= 0; i--)
	{
		cstrip.insert(a[i]);
		while (*cstrip.rbegin() - *cstrip.begin() > S)
		{
			if (r < N)
				cstrip.erase(cstrip.find(a[r]));
			r--;
		}
		if (i + L <= N)
			Q.push(mp(dp[i+L], i+L-1));
		dp[i] = INF;
		while (!Q.empty())
		{
			if (Q.top().second > r)
			{
				Q.pop();
			}
			else
			{
				dp[i] = 1 + Q.top().first;
				break;
			}
		}
	}
	printf("%d\n", dp[0] >= INF ? -1 : dp[0]);
}