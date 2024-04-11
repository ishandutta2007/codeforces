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

vi vec[100001];

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

int a[200001];
vi adj[200001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);	
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		vec[i].resize(x);
		for(int j=0;j<x;j++)
		{
			cin>>vec[i][j];
			vec[i][j]--;
		}
	}
	memset(a,-1,sizeof(a));
	for(int i=0;i+1<n;i++)
	{
		int id=-1;
		for(int j=0;j<min(vec[i].size(),vec[i+1].size());j++)
		{
			if(vec[i][j]!=vec[i+1][j])
			{
				id=j;
				break;
			}
		}
		if(id==-1)
		{
			if(vec[i].size()>vec[i+1].size())
			{
				cout<<"No\n";
				return 0;
			}
			continue;
		}
		int x=vec[i][id]; int y=vec[i+1][id];
		if(x<y)
		{
			//scc.addedge(2*y+1,2*x+1);
			adj[y].pb(x);
			//scc.addedge(y,x);
		}
		else
		{
			if(a[x]==0)
			{
				cout<<"No\n";
				return 0;
			}
			a[x]=1;
			if(a[y]==1)
			{
				cout<<"No\n";
				return 0;
			}
			a[y]=0;
			//scc.addedge(2*x,2*x+1);
			//scc.addedge(2*y+1,2*y);
		}
	}
	queue<int> q;
	for(int i=0;i<m;i++)
	{
		if(a[i]==1)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i];
			if(a[v]==0)
			{
				cout<<"No\n";
				return 0;
			}
			if(a[v]==-1)
			{
				a[v]=1;
				q.push(v);
			}
		}
	}
	/*
	scc.tarjan();
	vi vec;
	for(int i=0;i<m;i++)
	{
		int s1 = scc.sccidx[i*2];
		int s2 = scc.sccidx[i*2+1];
		if(s1==s2)
		{
			cout<<"No\n";
			return 0;
		}
		else if(s1<s2)
		{
			
		}
		else
		{
			vec.pb(i+1);
		}
	}
	*/
	
	vi vec;
	for(int i=0;i<m;i++)
	{
		if(a[i]==1) vec.pb(i+1);
	}
	cout<<"Yes\n";
	cout<<vec.size()<<'\n';
	if(!vec.empty())
	{
		for(int i=0;i<vec.size();i++)
		{
			cout<<vec[i];
			if(i+1<vec.size()) cout<<' ';
		}
		cout<<'\n';
	}
}