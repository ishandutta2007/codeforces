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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int a[1001];
int dp[1001][8][150];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		a[i]--;
	}
	memset(dp,-1,sizeof(dp));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			dp[i][j][0] = i;
		}
	}
	for(int i = 0; i < n; i++)
	{
		dp[i][a[i]][1] = i;
	}
	for(int i = n - 2; i >= 0; i--)
	{
		for(int j = 0; j < 8; j++)
		{
			if(a[i]==j) dp[i][j][1] = i;
			else dp[i][j][1] = dp[i+1][j][1];
			for(int k = 2; k <= (n+7)/8; k++)
			{
				if(a[i]!=j) dp[i][j][k] = dp[i+1][j][k];
				else dp[i][j][k] = dp[i+1][j][k-1];
				//cerr<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<'\n';
			}
		}
	}
	int lo = 0; int hi = (n+7)/8;
	vi perm;
	for(int i = 0; i < 8; i++) perm.pb(i);
	int ans = 0;
	while(lo<=hi)
	{
		int mid = (lo+hi)>>1;
		bool ex = 0;
		for(int i = 0; i < (1<<8); i++)
		{
			vi vec;
			vec=perm;
			vi cnt(8);
			for(int j = 0; j < 8; j++)
			{
				if(i&(1<<j))
				{
					cnt[j] = mid+1;
				}
				else
				{
					cnt[j] = mid;
				}
			}
			bool pos = false;
			do
			{
				int cur = 0;
				for(int j = 0; j < 8; j++)
				{
					if(cur>=n)
					{
						cur=-1;
						break;
					}
					int u = vec[j];
					//if(	(u==7-j)) cerr<<j<<' '<<u<<' '<<cur<<'\n';
					cur=dp[cur][u][cnt[u]];
					if(cur==-1) break;
					if(cnt[u]>0) cur++;
				}
				if(cur==-1) continue;
				else 
				{
					pos=true;
					break;
				}
			}while(next_permutation(vec.begin(),vec.end()));
			if(pos)
			{
				ex = 1;
				//cerr<<"ANSWER : "<<ans<<' '<<i<<' '<<mid<<'\n';
				ans = max(ans,8*mid + __builtin_popcount(i));
			}
		}
		if(ex)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}
	cout<<ans;
}