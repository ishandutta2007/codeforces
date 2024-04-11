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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<ii> vec;
int a[11111];
int par[11111];
vector<ii> pairs;
int visited[11111];

void choose(int x)
{
	visited[x]=1;
	cout<<x+1<<'\n';
	fflush(stdout);
}

int read()
{
	int x; cin>>x; x--; visited[x]=1; return x;
}

int n;

int main()
{
	cin>>n; int m; cin>>m;
	vector<ii> sorted;
	for(int i=0;i<2*n;i++) 
	{
		cin>>a[i]; sorted.pb(mp(a[i],i));
	}
	sort(sorted.rbegin(),sorted.rend());
	memset(par,-1,sizeof(par));
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--; par[u]=v; par[v]=u; 
		if(a[u]<a[v]) swap(u,v);
		pairs.pb(mp(u,v)); //u is the better version
	}
	int player; cin>>player; player--; int las=-1;
	for(int i=0;i<2*n;i++)
	{
		if(i%2==player%2) //your turn
		{
			if(las!=-1&&par[las]!=-1&&!visited[par[las]])
			{
				choose(par[las]); continue;
			}
			bool pos=0;
			for(int j=0;j<pairs.size();j++)
			{
				if(!visited[pairs[j].fi])
				{
					choose(pairs[j].fi);
					pos=1; break;
				}
			}
			if(pos) continue;
			for(int j=0;j<sorted.size();j++)
			{
				if(!visited[sorted[j].se])
				{
					choose(sorted[j].se);
					pos=1; break;
				}
			}
		}
		else
		{
			las = read();
		}
	}
}