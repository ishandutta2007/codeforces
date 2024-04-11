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

const int NN = int(500000);
map<int,int> PP[5111];
map<int,ii> T[NN]; //later check data
int vertex=1;
vector<ii> adj[NN];
int sub[NN];

int add(int u, int p, int c)
{
	if(T[u].find(p)==T[u].end())
	{
		//if(max(u,vertex)<=4) cerr<<u<<' '<<vertex<<' '<<c<<'\n';
		adj[u].pb({vertex,c}); adj[vertex].pb({u,c});
		T[u][p]={vertex++,c};
		return vertex-1;
	}
	else
	{
		int newc = c-T[u][p].se;
		if(newc>0)
		{
			return add(T[u][p].fi,p,newc);
		}
		else return T[u][p].fi;
	}
}
	
int cnt[5555];
ll h[NN];

void dfs(int u, int p=-1)
{
	for(ii e:adj[u])
	{
		int v=e.fi; int c=e.se;
		if(v==p) continue;
		dfs(v,u);
		sub[u]+=sub[v];
	}
}


int centroid(int u, int r, int p)
{
	for(ii e:adj[u])
	{
		int v=e.fi; int c=e.se;
		if(v==p) continue;
		if(sub[v]*2>sub[r]) return centroid(v,r,u);
	}
	return u;
}

void dfs2(int u, int p)
{
	for(ii e:adj[u])
	{
		int v=e.fi; int c=e.se;
		if(v==p) continue;
		h[v]=h[u]+c;
		dfs2(v,u);
	}
}

int s[NN];

int main()
{
	for(int i=2;i<=5001;i++)
	{
		PP[i]=PP[i-1];
		int cur=i;
		for(int j=2;j<=i;j++)
		{
			int cnt=0;
			if(cur%j==0)
			{
				while(cur%j==0)
				{
					cnt++;
					cur/=j;
				}
				PP[i][-j]+=cnt;
			}
		}
	}
	//node 0 = number 1
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		cnt[x]++;
		if(x<2) 
		{
			sub[0]++; s[0]++;
		}
	}
	for(int i=2;i<=5000;i++)
	{
		int curv = 0;
		for(ii x:PP[i])
		{
			int p = -x.fi;
			int cnt = x.se;
			curv = add(curv,p,cnt);
		}
		sub[curv]+=cnt[i]; s[curv]+=cnt[i];
	}
	dfs(0,-1);
	int c = centroid(0,0,-1);
	dfs2(c,-1);
	ll ans = 0;
	for(int i=0;i<NN;i++)
	{
		ans+=ll(h[i])*ll(s[i]);
	}
	cout<<ans<<'\n';
}