#include <bits/stdc++.h>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define pb push_back
#define INF ((ll) 1e9)
#define rint(x) scanf("%d", &(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, M;

int main()
{
	rint(N), rint(M);

	double dp[N+1];
	loop(i, N+1)
		dp[i] = 0;
	dp[0] = 1;
	double ndp[N+1];

	rep(N)
	{
		loop(i, N+1)
			ndp[i] = 0;

		loop(i, N)
		{
			double c = (double) (M - i) / (N * M - COUNTER);
			ndp[i+1] += dp[i] * c;
			ndp[i] += dp[i] * (1 - c);
		}

		loop(i, N+1)
			dp[i] = ndp[i];
	}

	double sum = 0;
	loop(i, N+1)
	{
		dp[i] *= i;
		sum += dp[i];
	}
	loop(i, N+2)
		dp[i] /= sum;

	double ans = 0;

	loop(i, N+1)
	{
		//printf("dp[%d] = %lf\n", i, dp[i]);
		ans += dp[i] * ((double) i / N);
	}

	printf("%.12lf\n", ans);
}