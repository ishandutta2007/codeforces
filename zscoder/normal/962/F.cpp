#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int n,m; 
const int N = 100111;

vi adj[N];
map<ii,int> label;
int timer;
int low[N];
int disc[N];
vector<vector<ii> > comps;
stack<ii> st;

void dfs(int u, int p)
{
	//cerr<<"DFS "<<u<<' '<<p<<'\n';
	int child = 0; disc[u]=++timer; low[u] = timer;
	for(int v:adj[u])
	{
		if(v==p) continue;
		if(!disc[v])
		{
			child++;
			st.push({u,v});
			dfs(v,u);
			low[u] = min(low[u], low[v]);
			if((p==-1&&child>1)||(p!=-1&&low[v]>=disc[u]))
			{
				//articulation point
				comps.pb(vector<ii>()); pair<int,int> a1={u,v};
				while(!st.empty()&&(st.top()!=a1))
				{
					comps.back().pb(st.top()); st.pop();
				}
				comps.back().pb(st.top()); st.pop();
			}
		}
		else if(disc[v]<disc[u])
		{
			low[u] = min(low[u], disc[v]);
			st.push({u,v});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
		label[{u,v}] = label[{v,u}] = i+1;
	}
	for(int i=0;i<n;i++)
	{
		if(!disc[i])
		{
			dfs(i,-1);
			if(!st.empty())
			{
				comps.pb(vector<ii>());
				while(!st.empty())
				{
					comps.back().pb(st.top()); st.pop();
				}
			}
		}
	}
	set<int> ans;
	for(auto x:comps)
	{
		set<int> S;
		for(auto y:x)
		{
			S.insert(y.fi); S.insert(y.se);
		}
		if(S.size()==x.size()) 
		{
			for(auto y:x)
			{
				ans.insert(label[y]);
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(int x:ans)
	{
		cout<<x<<' ';
	}
	cout<<'\n';
}