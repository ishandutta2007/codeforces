#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef long double ld;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int MOD = 1e9 + 7;

int a[101];
int dp[101][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i]; a[i]++;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			dp[i][j] = 1000000;
		}
	}
	dp[0][0] = 1;
	if(a[0] == 4) {dp[0][1] = 0; dp[0][2] = 0;}
	if(a[0] == 3) dp[0][2] = 0;
	if(a[0] == 2) dp[0][1] = 0;
	for(int i = 1; i < n; i++)
	{
		if(a[i] == 1) 
		{
			dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]))+1;
		}
		else if(a[i] == 2)
		{
			dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]))+1;
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
		}
		else if(a[i] == 3)
		{
			dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]))+1;
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
		}
		else
		{
			dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]))+1;
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
		}
	}
	cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2])) << endl;
}