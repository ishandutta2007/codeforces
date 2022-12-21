#include <bits/stdc++.h>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define pb push_back
#define INF ((int) 1e9)
#define rint(x) scanf("%d", &(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, M;

ll freq[100000];

int main()
{
	M = 100000;

	rint(N);
	rep(N)
	{
		int x;
		rint(x);
		freq[x-1]++;
	}

	ll dp[M+2][2];
	dp[M][0] = dp[M+1][0] = 0;
	dp[M][1] = dp[M+1][1] = 0;

	for (int i = M-1; i >= 0; i--)
	{
		dp[i][0] = max(dp[i+1][0], dp[i+1][1] + freq[i] * (i+1));
		dp[i][1] = dp[i+1][0];
	}

	printf("%I64d\n", dp[0][0]);
}