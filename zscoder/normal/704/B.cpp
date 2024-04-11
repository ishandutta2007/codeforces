#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll dp[2][5100][3][3];
ll a[5100], b[5100], c[5100], d[5100], x[5100];
const ll INF = ll(1e18);

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, s, e; cin >> n >> s >> e; s--; e--;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> d[i];
	}
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < 2; k++)
			{
				for(int l = 0; l < 2; l++)
				{
					dp[i][j][k][l] = INF;
				}
			}
		}
	}
	dp[1][0][0][0] = 0; //when 0 vertices exist
	ll ans = INF;
	for(int i = 0; i < n; i++)
	{
		int cur = (i&1); int prev = (cur^1);
		//cerr << cur << ' ' << prev << '\n';
		for(int j = 0; j < n + 1; j++)
		{
			for(int k = 0; k < 2; k++)
			{
				for(int l = 0; l < 2; l++)
				{
					dp[cur][j][k][l] = INF;
				}
			}
		}
		for(int j = 0; j < n + 1; j++)
		{
			for(int k = 0; k < 2; k++)
			{
				for(int l = 0; l < 2; l++)
				{
					if(dp[prev][j][k][l] != INF)
					{
						ll val = dp[prev][j][k][l];
						if(i != s && i != e)
						{
							//cerr << "HE" << endl;
							ll cur2;
							cur2 = x[i]*2+a[i]+c[i];
							if(j+k+l>1&&j>0) dp[cur][j-1][k][l] = min(dp[cur][j-1][k][l], cur2 + val);
							if(i==n-1&&!j&&k&&l) ans = min(ans, cur2+val);
							cur2 = a[i]+d[i];
							if(j||k) dp[cur][j][k][l] = min(dp[cur][j][k][l], cur2 + val);
							cur2 = b[i]+c[i];
							if(j||l) dp[cur][j][k][l] = min(dp[cur][j][k][l], cur2 + val);
							cur2 = x[i]*-2+b[i]+d[i];
							dp[cur][j+1][k][l] = min(dp[cur][j+1][k][l], cur2 + val);
						}
						else if(i == s && !k)
						{
							//cerr << "HERE" << endl;
							ll cur2 = x[i] + c[i];
							if(j) dp[cur][j-1][1][l] = min(dp[cur][j-1][1][l], cur2 + val);
							if(i==n-1&&!j&&l) ans = min(ans, cur2+val);
							cur2 = -x[i] + d[i];
							dp[cur][j][1][l] = min(dp[cur][j][1][l], cur2 + val);
						}
						else if(i == e && !l)
						{
							ll cur2 = x[i] + a[i];
							if(j) dp[cur][j-1][k][1] = min(dp[cur][j-1][k][1], cur2 + val);
							if(i==n-1&&!j&&k) ans = min(ans, cur2+val);
							cur2 = -x[i] + b[i];
							dp[cur][j][k][1] = min(dp[cur][j][k][1], cur2 + val);
						}
					}
				}
			}
		}
	}
	//ans = dp[cur][0][1][1];
	cout << ans << '\n';
}