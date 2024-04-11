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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int cost[2][21][21];
int n; 
int ans;
int a[42][42];
int u[42], v[42], p[42], way[42];
int minv[42];
bool used[42];

void solve(int x, int y)
{
	if(x+y>=n)
	{
		ans = max(ans, v[0]);
		return ;
	}
	int old_u[21], old_v[21], old_p[21], old_way[21];
	int i = x + y + 1;
	for(int rot = 0; rot < 2; rot++) 
	{
		if(!rot&&x==n/2) continue;
		if(rot&&y==n/2) continue;
		for(int j = 0; j < n; j++) 
		{
			a[i][j + 1] = -cost[rot][i-1][j];
		}
		for(int j = 0; j <= n; j++) 
		{
			old_u[j] = u[j];
			old_v[j] = v[j];
			old_p[j] = p[j];
			old_way[j] = way[j];
		}
		p[0] = i;
		int j0 = 0;
		for(int j=0;j<=n;j++)
		{
			minv[j]=int(1e9);
			used[j]=0;
		}
		do
		{
			used[j0]=1;
			int i0=p[j0]; int delta = int(1e9); int j1;
			for(int j=1;j<=n;j++)
			{
				if(!used[j])
				{
					int cur=a[i0][j]-u[i0]-v[j];
					if(cur<minv[j])
					{
						minv[j]=cur; way[j]=j0;
					}
					if(minv[j]<delta)
					{
						delta=minv[j]; j1=j;
					}
				}
			}
			for(int j=0;j<=n;j++)
			{
				if(used[j]) u[p[j]]+=delta,v[j]-=delta;
				else minv[j]-=delta;
			}
			j0=j1;
		}while(p[j0]);
		do
		{
			int j1=way[j0];
			p[j0]=p[j1];
			j0=j1;
		}while(j0);
		solve(x+(rot==0),y+(rot==1));
		for(int j=0;j<=n;j++)
		{
			u[j] = old_u[j];
			v[j] = old_v[j]; 
			p[j] = old_p[j];
			way[j] = old_way[j]; 
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>cost[0][i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>cost[1][i][j];
		}
	}
	solve(0,0);
	cout<<ans<<'\n';
}