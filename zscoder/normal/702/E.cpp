#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int MOD = 1e9 + 7;

const int LG = 35;

int par[LG][100001];
ll sum[LG][100001];
ll mini[LG][100001];

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0); 
	int n; ll k;
	scanf("%d %I64d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &par[0][i]);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%I64d", &sum[0][i]);
		mini[0][i] = sum[0][i];
	}
	for(int i = 1; i < LG; i++)
	{
		for(int j = 0; j < n; j++)
		{
			par[i][j] = par[i - 1][par[i-1][j]];
			sum[i][j] = sum[i - 1][j] + sum[i - 1][par[i-1][j]];
			mini[i][j] = min(mini[i - 1][j], mini[i - 1][par[i-1][j]]);
		}
	}
	for(int i = 0; i < n; i++)
	{
		ll s, m;
		s = 0; m = MOD;
		ll x = k; int cnt = 0;
		int nd = i;
		while(x)
		{
			if(x&1)
			{
				s += sum[cnt][nd];
				m = min(m, mini[cnt][nd]);
				nd = par[cnt][nd];
			}
			cnt++;
			x >>= 1;
		}
		printf("%I64d %I64d\n", s, m);
	}
	return 0;
}