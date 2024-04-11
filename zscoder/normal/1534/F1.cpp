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

struct SCC
{
	const int INF = int(1e9);
	vector<vector<int> > vec;
	int index;
	vector<int> idx;
	vector<int> lowlink;
	vector<bool> onstack;
	stack<int> s;
	vector<int> sccidx;
	int scccnt;
	vi topo;
	
	//lower sccidx means appear later
	void init(int n)
	{
		idx.assign(n,-1);
		index = 0;
		onstack.assign(n,0);
		lowlink.assign(n,INF);
		while(!s.empty()) s.pop();
		sccidx.assign(n,-1);
		scccnt = 0;
		vec.clear();
		topo.clear();
		vec.resize(n);
	}
	
	void addedge(int u, int v) //u -> v
	{
		vec[u].pb(v);
	}
	
	void connect(int u)
	{
		idx[u] = index;
		lowlink[u] = index;
		index++;
		s.push(u);
		onstack[u] = true;
		for(int i = 0; i < vec[u].size(); i++)
		{
			int v = vec[u][i];
			if(idx[v] == -1)
			{
				connect(v);
				lowlink[u] = min(lowlink[u], lowlink[v]);
			}
			else if(onstack[v])
			{
				lowlink[u] = min(lowlink[u], idx[v]);
			}
		}
		if(lowlink[u] == idx[u])
		{
			while(1)
			{
				int v = s.top();
				s.pop();
				onstack[v] = false;
				sccidx[v] = scccnt;
				if(v == u) break;
			}
			scccnt++;
		}
	}
	
	void tarjan()
	{
		for(int i = 0; i < vec.size(); i++)
		{
			if(idx[i] == -1)
			{
				connect(i);
			}
		}
	}
	
	void toposort() //if graph is a DAG and i just want to toposort
	{
		tarjan();
		int n = vec.size();
		topo.resize(n);
		vector<ii> tmp;
		for(int i = 0; i < n; i++)
		{
			tmp.pb(mp(sccidx[i],i));
		}
		sort(tmp.begin(),tmp.end());
		reverse(tmp.begin(),tmp.end());
		for(int i = 0; i < n; i++)
		{
			topo[i]=tmp[i].se;
			if(i>0) assert(tmp[i].fi!=tmp[i-1].fi);
		}
	}
};

int n,m;
vector<vector<int> > a;
vector<vector<int> > id;
int target[555555];

int getid(int x, int y)
{
	return (x*m+y);
}

int vis[555555];
vi adj[555555];
vector<ii> pos[555555];

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

bool isvalid(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<m);
}
SCC scc; 

void addedge(int u, int v)
{
	//cerr<<"ADD EDGE "<<u<<" -> "<<v<<'\n';
	scc.addedge(u,v); adj[u].pb(v);
}

void dfs(int u)
{
	//cerr<<"VISIT "<<u<<'\n';
	vis[u]=1;
	for(int v:adj[u])
	{
		if(!vis[v]) dfs(v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	a.resize(n); id.resize(n);
	int curid=0;
	for(int i=0;i<n;i++)
	{
		a[i].resize(m);
		id[i].assign(m,-1);
		string s; cin>>s;
		for(int j=0;j<m;j++)
		{
			if(s[j]=='#') 
			{
				a[i][j]=1; id[i][j]=curid++;
				pos[j].pb({i,id[i][j]});
			}
			else a[i][j]=0;
		}
	}
	for(int i=0;i<m;i++)
	{
		cin>>target[i];
		sort(pos[i].begin(),pos[i].end());
	}
	scc.init(n*m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==0) continue;
			//cerr<<"ID: "<<i<<' '<<j<<' '<<id[i][j]<<'\n';
			for(int dir=0;dir<4;dir++)
			{
				int i2=i+dx[dir]; int j2=j+dy[dir];
				if(isvalid(i2,j2))
				{
					if(a[i2][j2]==1)
					{
						addedge(id[i][j],id[i2][j2]);
					}
				}
			}
		}
	}
	//also add downward and l,r edges
	//downward
	for(int i=0;i<m;i++)
	{
		for(int j=0;j+1<pos[i].size();j++)
		{
			addedge(pos[i][j].se,pos[i][j+1].se);
		}
	}
	//rightward and leftward
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<pos[i].size();j++)
		{
			int id=pos[i][j].se;
			int v=pos[i][j].fi;
			if(i-1>=0)
			{
				int lb = lower_bound(pos[i-1].begin(),pos[i-1].end(),mp(v,-1))-pos[i-1].begin();
				if(lb>=0&&lb<pos[i-1].size())
				{
					addedge(id,pos[i-1][lb].se);
				}	
			}
			if(i+1<m)
			{
				int lb = lower_bound(pos[i+1].begin(),pos[i+1].end(),mp(v,-1))-pos[i+1].begin();
				if(lb>=0&&lb<pos[i+1].size())
				{
					addedge(id,pos[i+1][lb].se);
				}
			}
		}
	}
	//cerr<<"HERE"<<endl;
	scc.tarjan();
	//cerr<<"CURID = "<<curid<<endl;
	vector<ii> vertices;
	//[0,curid-1] are our vertices
	for(int i=0;i<curid;i++)
	{
		vertices.pb({scc.sccidx[i],i});
	}
	sort(vertices.rbegin(),vertices.rend()); //so higher index, means appear front, so like a toposort
	//dfs from the front
	int cc=0;
	for(auto x:vertices)
	{
		//cerr<<"X: "<<x.fi<<' '<<x.se<<'\n';
		int v=x.se;
		if(vis[v]) continue;
		dfs(v); cc++;
	}
	cout<<cc<<'\n';
}