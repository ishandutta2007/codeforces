#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#define SIZE 300005
#define BT 20

using namespace std;
typedef pair <int,int> P;

struct Graph
{
	vector <int> vec[SIZE];
	vector <int> tree[SIZE];
	int par[SIZE][BT],dep[SIZE];
	int low[SIZE],ord[SIZE];
	int cmb[SIZE],id[SIZE];
	int tour[SIZE],ch[SIZE];
	bool use[SIZE];
	int n,sz;//treevf
	int now_id;
	
	void init(int m)
	{
		n=m;
		for(int i=0;i<n;i++) vec[i].clear();
	}
	inline void add(int a,int b)
	{
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	void dfs(int v,int p)
	{
		use[v]=true;
		low[v]=ord[v]=now_id++;
		int cnt=0;
		for(int i=0;i<vec[v].size();i++)
		{
			int to=vec[v][i];
			if(to!=p)
			{
				if(!use[to])
				{
					dfs(to,v);
					low[v]=min(low[v],low[to]);
				}
				else low[v]=min(low[v],ord[to]);
			}
			else
			{
				if(cnt>0) low[v]=min(low[v],ord[to]);
				cnt++;
			}
		}
	}
	void build_lowlink()
	{
		for(int i=0;i<n;i++) use[i]=false;
		now_id=0;
		for(int i=0;i<n;i++)
		{
			if(!use[i])
			{
				dfs(i,-1);
			}
		}
	}
	bool bridge(int s,int t)//  true
	{
		if(ord[s]<ord[t]) swap(s,t);//ord[s]>=ord[t]
		return low[s]>ord[t];
	}
	void dfs2(int v,int p,int d)
	{
		tour[v]=now_id++;
		par[v][0]=p;
		dep[v]=d;
		use[v]=true;
		for(int i=0;i<tree[v].size();i++)
		{
			int to=tree[v][i];
			if(to!=p) dfs2(to,v,d+1);
		}
		ch[v]=now_id;
	}
	void build_LCA()
	{
		for(int i=0;i+1<BT;i++)
		{
			for(int j=0;j<sz;j++)
			{
				if(par[j][i]==-1) par[j][i+1]=-1;
				else par[j][i+1]=par[par[j][i]][i];
			}
		}
	}
	inline int LCA(int a,int b)
	{
		if(dep[a]>dep[b]) swap(a,b);//dep[a]<=dep[b]
		for(int i=BT-1;i>=0;i--)
		{
			if(par[b][i]!=-1&&dep[par[b][i]]>=dep[a])
			{
				b=par[b][i];
			}
		}
		if(a==b) return b;
		for(int i=BT-1;i>=0;i--)
		{
			if(par[a][i]!=par[b][i])
			{
				a=par[a][i];
				b=par[b][i];
			}
		}
		return par[a][0];
	}
	void build_component()
	{
		build_lowlink();
		for(int i=0;i<n;i++) id[i]=-1;
		sz=0;
		for(int i=0;i<n;i++)
		{
			if(id[i]==-1)
			{
				id[i]=sz;
				queue <int> que;
				que.push(i);
				while(!que.empty())
				{
					int v=que.front();que.pop();
					for(int j=0;j<vec[v].size();j++)
					{
						int to=vec[v][j];
						if(id[to]==-1&&!bridge(v,to))
						{
							id[to]=sz;
							que.push(to);
						}
					}
				}
				sz++;
			}
		}
	}
	void build_tree()//component !!
	{
		build_component();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<vec[i].size();j++)
			{
				int to=vec[i][j];
				if(bridge(i,to))
				{
					tree[id[i]].push_back(id[to]);
				}
			}
		}
		for(int i=0;i<sz;i++) use[i]=false;
		now_id=0;
		for(int i=0;i<sz;i++) if(!use[i]) dfs2(i,-1,0);
		build_LCA();
	}
	P pos[SIZE],ans[SIZE];
	int MM[SIZE];
	int contract(vector <int> nd)
	{
		int now=0;
		for(int i=0;i<nd.size();i++) pos[now++]=P(tour[nd[i]],nd[i]);
		sort(pos,pos+now);
		int nm=0;
		int S=0;
		for(int i=0;i<now;i++)
		{
			int v=pos[i].second;
			while(S>0&&ch[MM[S-1]]<=tour[v]) S--;
			if(S>0) ans[nm++]=P(MM[S-1],v);
			MM[S++]=v;
		}
		return nm;
	}
	inline bool same(int a,int b)
	{
		return id[a]==id[b];
	}
};
Graph G;
Graph query;
int R;
int n,m,q;
int left[SIZE],right[SIZE];
int memo[SIZE];
P pos[SIZE];
int cl[SIZE];

int get_input()
{
	int v;
	scanf("%d",&v);v=(v+R)%n;
	if(v==0) v=n;
	return v;
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	G.init(n+2);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		G.add(a,b);
	}
	G.build_tree();
	//for(int i=0;i<n;i++) printf("%d ",G.id[i]);puts("");
	for(int i=0;i<q;i++)
	{
		int N,M;
		scanf("%d %d",&N,&M);
		vector <int> nd;
		for(int j=0;j<N;j++)
		{
			int v=get_input();v--;
			nd.push_back(G.id[v]);
			memo[j]=G.id[v];
		}
		for(int j=0;j<M;j++)
		{
			int a=get_input(),b=get_input();
			a--,b--;
			left[j]=G.id[a],right[j]=G.id[b];
			if(left[j]!=right[j])
			{
				nd.push_back(left[j]);
				nd.push_back(right[j]);
			}
		}
		int sz=0;
		for(int j=0;j<nd.size();j++) pos[sz++]=P(G.tour[nd[j]],nd[j]);
		sort(pos,pos+sz);
		for(int j=0;j+1<sz;j++)
		{
			if(pos[j]!=pos[j+1])
			{
				int v=G.LCA(pos[j].second,pos[j+1].second);
				if(v!=-1) nd.push_back(v);
			}
		}
		sort(nd.begin(),nd.end());
		nd.erase(unique(nd.begin(),nd.end()),nd.end());
		for(int j=0;j<nd.size();j++) cl[nd[j]]=j;
		query.init(nd.size());
		for(int j=0;j<M;j++)
		{
			left[j]=cl[left[j]];
			right[j]=cl[right[j]];
			if(left[j]!=right[j]) query.add(left[j],right[j]);
		}
		//nd
		int nm=G.contract(nd);
		for(int j=0;j<nm;j++)
		{
			int a=G.ans[j].first,b=G.ans[j].second;
			query.add(cl[a],cl[b]);
		}
		query.build_component();
		bool up=true;
		for(int j=0;j<N;j++)
		{
			memo[j]=cl[memo[j]];
			if(!query.same(memo[0],memo[j]))
			{
				up=false;
				break;
			}
		}
		if(up)
		{
			puts("YES");
			R+=i+1;
			R%=n;
		}
		else puts("NO");
	}
	return 0;
}