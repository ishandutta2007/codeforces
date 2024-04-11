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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const ld PI = 3.14159265358979323;

ld area(ld r)
{
	return (PI*r*r);
}

ii center[1001];
ll radius[1001];
bool mat[1001][1001];
bool rmat[1001][1001];
vi adj[1001];

ll dist(ii a, ii b)
{
	return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
}

bool inside(ii c1, ll r1, ii c2, ll r2) //is circle 1 in circle 2
{
	ll sqrdist = dist(c1,c2);
	if(sqrdist>=(r1+r2)*(r1+r2)) return 0;
	else if(r1<=r2)
	{
		return 1;
	}
	return 0;
}

ld siz[1001];
ld dp[1001][2][2];
ld ans=0;
int deg[1001];
int ideg[1001];
bool visited[1001];

void dfs2(int u, int p, int h=0)
{
	visited[u]=1;
	//cerr<<u<<' '<<siz[u]<<'\n';
	ld res[2][2][2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				res[i][j][k]=0;
			}
		}
	}
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		dfs2(v,u,h+1);
	}
	for(int l=0;l<2;l++)
	{
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i];
			for(int j = 0; j < 2; j++)
			{
				for(int k = 0; k < 2; k++)
				{
					if(l==0)
					{
						res[l][j][k] += dp[v][j^1][k];
					}
					else
					{
						res[l][j][k] += dp[v][j][k^1];
					}
				}
			}
			//dp[u][1]+=max(dp[v][0],dp[v][1]);
			//dp[u][0]+=max(dp[v][0],dp[v][1]);
		}
		for(int j = 0; j < 2; j++)
		{
			for(int k = 0; k < 2; k++)
			{
				if(l==0)
				{
					if(j==1) res[l][j][k]+=siz[u];
				}
				else
				{
					if(k==1) res[l][j][k]+=siz[u];
				}
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			dp[u][i][j]=max(res[0][i][j],res[1][i][j]);
		}
	}
	//dp[u][1]+=siz[u];
}

bool used[1001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>center[i].fi>>center[i].se>>radius[i];
	}
	for(int i=0;i<n;i++)
	{
		siz[i] = area(radius[i])*2;
		for(int j=0;j<n;j++)
		{
			if(i==j) mat[i][j]=0;
			else
			{
				if(inside(center[i],radius[i],center[j],radius[j]))
				{
					mat[j][i]=1;
					rmat[i][j]=1;
					deg[j]++;
					ideg[i]++;
				}
			}
		}
	}
	vector<ii> v;
	for(int i=0;i<n;i++) v.pb(mp(deg[i],i));
	sort(v.rbegin(),v.rend());
	vi V;
	for(int z=0;z<n;z++)
	{
		int i=v[z].se;
		if(!used[i]) V.pb(i);
		for(int j=0;j<n;j++)
		{
			if(mat[i][j])
			{
				if(ideg[j]==1)
				{
					adj[i].pb(j);
					used[j]=1;
					//cerr<<i<<' '<<j<<'\n';
				}
				ideg[j]--;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		ans-=area(radius[i]);
	}
	for(auto it = V.begin(); it != V.end(); it++)
	{
		int i=(*it);
		if(!visited[i])
		{
			dfs2(i,-1);
			ans+=dp[i][1][1];
		}
	}
	cout<<fixed<<setprecision(15)<<ans<<'\n';
}