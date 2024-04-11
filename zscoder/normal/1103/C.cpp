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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vi adj[501111];
vi T[501111];
bool vis[501111];
int par[501111];
int h[501111];
vi back[501111];

void build_tree(int u)
{
	vis[u]=1;
	for(int v:adj[u])
	{
		if(par[u]==v) continue;
		if(vis[v])
		{
			back[u].pb(v); continue;
		}
		T[u].pb(v); par[v]=u; h[v]=h[u]+1;
		build_tree(v);
	}
}


int main()
{
	int n,m,k; scanf("%d %d %d",&n,&m,&k); par[0]=-1;
	for(int i=0;i<m;i++)
	{
		int u,v; scanf("%d %d",&u,&v); u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	build_tree(0);
	
	int minpath = (n+k-1)/k;
	for(int i=0;i<n;i++)
	{
		if(h[i]+1>=minpath)
		{
			vi res;
			int cur=i;
			while(cur!=-1)
			{
				res.pb(cur); cur=par[cur];
			}
			printf("PATH\n");
			assert(int(res.size())>=minpath);
			printf("%d\n",int(res.size()));
			for(int i=int(res.size())-1;i>=0;i--)
			{
				printf("%d",res[i]+1);
				if(i>0) printf(" ");
			}
			printf("\n");
			return 0;
		}
	}
	printf("CYCLES\n");
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(T[i].empty())
		{
			c++;
			int u = back[i][0]; int v = back[i][1];
			int hh = h[i];
			int hu = h[u];
			int hv = h[v];
			if(hu>hv) 
			{
				swap(u,v);swap(hu,hv);
			}
			if((hh-hu)%3!=2)
			{
				vi res;
				int cur=i;
				while(cur!=-1)
				{
					res.pb(cur); 
					if(cur==u) break;
					cur=par[cur];
				}
				assert(int(res.size())%3!=0);
				printf("%d\n",int(res.size()));
				for(int i=0;i<res.size();i++)
				{
					printf("%d", res[i]+1);
					if(i+1<res.size()) printf(" ");
				}
				printf("\n");
			}
			else if((hh-hv)%3!=2)
			{
				vi res;
				int cur=i;
				while(cur!=-1)
				{
					res.pb(cur); 
					if(cur==v) break;
					cur=par[cur];
				}
				assert(int(res.size())%3!=0);
				printf("%d\n",int(res.size()));
				for(int i=0;i<res.size();i++)
				{
					printf("%d", res[i]+1);
					if(i+1<res.size()) printf(" ");
				}
				printf("\n");
			}
			else
			{
				vi res;
				res.pb(i);
				int cur=v;
				while(cur!=-1)
				{
					res.pb(cur); 
					if(cur==u) break;
					cur=par[cur];
				}
				assert(int(res.size())%3!=0);
				printf("%d\n",int(res.size()));
				for(int i=0;i<res.size();i++)
				{
					printf("%d", res[i]+1);
					if(i+1<res.size()) printf(" ");
				}
				printf("\n");
			}
			if(c==k) return 0;
		}
	}
}