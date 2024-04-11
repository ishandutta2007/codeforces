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

bool a[100010];

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

ii tmp[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; 
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<100001;i++) tmp[i]=mp(-1,-1);
	for(int i = 0; i < m; i++)
	{
		int k; cin>>k;
		for(int j =0;j<k;j++)
		{
			int z; cin>>z;
			z--;
			if(tmp[z].fi==-1) tmp[z].fi=i;
			else tmp[z].se=i;
		}
	}
	SCC scc;
	scc.init(2*m);
	for(int i=0;i<n;i++)
	{
		int l = tmp[i].fi; int r = tmp[i].se;
		if(a[i])
		{
			scc.addedge(2*l,2*r);
			scc.addedge(2*r,2*l);
			scc.addedge(2*l+1,2*r+1);
			scc.addedge(2*r+1,2*l+1);
		}
		else
		{
			scc.addedge(2*l,2*r+1);
			scc.addedge(2*r+1,2*l);
			scc.addedge(2*l+1,2*r);
			scc.addedge(2*r,2*l+1);
		}
	}
	scc.tarjan();
	for(int i = 0; i < m; i++)
	{
		if(scc.sccidx[2*i]==scc.sccidx[2*i+1])
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
}