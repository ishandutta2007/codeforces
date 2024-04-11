#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ii par[3][1111][1111];
int dist[3][1111][1111];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int n = 1011;
bool isvalid(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<n);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ii a[3];
	for(int i=0;i<3;i++)
	{
		cin>>a[i].fi>>a[i].se;
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				dist[i][j][k]=int(1e9);
				par[i][j][k]=mp(-1,-1);
			}
		}
		queue<ii> q;
		q.push(mp(a[i].fi,a[i].se)); dist[i][a[i].fi][a[i].se]=0;
		while(!q.empty())
		{
			int x=q.front().fi; int y=q.front().se; q.pop();
			for(int z=0;z<4;z++)
			{
				int x2=x+dx[z]; int y2=y+dy[z];
				if(isvalid(x2,y2)&&dist[i][x2][y2]>dist[i][x][y]+1)
				{
					dist[i][x2][y2]=dist[i][x][y]+1;
					par[i][x2][y2]=mp(x,y); q.push(mp(x2,y2));
				}
			}
		}
	}
	ll best=ll(5e9); ii mn=mp(-1,-1);
	for(int j=0;j<n;j++)
	{
		for(int k=0;k<n;k++)
		{
			ll sum=0;
			for(int i=0;i<3;i++)
			{
				sum+=dist[i][j][k];
			}
			if(sum<best)
			{
				best=sum; mn=mp(j,k);
			}
		}
	}
	set<ii> S;
	for(int i=0;i<3;i++)
	{
		ii cur = mn;
		while(cur!=a[i])
		{
			S.insert(cur);
			cur=par[i][cur.fi][cur.se];
		}
		S.insert(cur);
	}
	cout<<S.size()<<'\n';
	for(ii x:S)
	{
		cout<<x.fi<<' '<<x.se<<'\n';
	}
}