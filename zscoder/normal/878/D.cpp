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
typedef bitset<4096> b100;

b100 dp[100111];
int a[13][100101];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,q; cin>>n>>k>>q;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<(1<<k);j++)
		{
			if(j&(1<<i)) dp[i].set(j,1);
			else dp[i].set(j,0);
		}
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	int cur=k;
	for(int i=0;i<q;i++)
	{
		int t; cin>>t;
		int x,y; cin>>x>>y;
		x--; y--;
		if(t==1)
		{
			dp[cur] = (dp[x]|dp[y]);
			cur++;
		}
		else if(t==2)
		{
			dp[cur] = (dp[x]&dp[y]);
			cur++;
		}
		else
		{
			int res=0;
			for(int j=0;j<k;j++)
			{
				int ans=a[j][y];
				int bit=0;
				for(int z=0;z<k;z++)
				{
					if(a[z][y]>=ans)
					{
						bit|=(1<<z);
					}
				}
				if(dp[x][bit])
				{
					res=max(res,ans);
				}
			}
			cout<<res<<'\n';
		}
	}
}