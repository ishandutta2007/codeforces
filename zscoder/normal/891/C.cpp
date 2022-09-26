#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int dsupar[511111];

int rt(int u)
{
	if(dsupar[u]<0) return u;
	return (dsupar[u]=rt(dsupar[u]));
}

void merge(int u, int v)
{
	u=rt(u); v=rt(v);
	if(u==v) return;
	if(dsupar[u]>dsupar[v]) swap(u,v);
	dsupar[u]+=dsupar[v]; dsupar[v]=u;
}

pair<ll,ii> E[511111];
vector<ii> T[511111];
vector<int> V[511111];
int n,m; 

#define N 501000
#define LN 20

////////////----/////////////
struct node
{
    int to,next,cost;
}edge[2*N];

int cnt,pre[N];


void add_edge(int u,int v,int c)
{
    edge[cnt].to = v;
    edge[cnt].next = pre[u];
    edge[cnt].cost=c;
    pre[u] = cnt++;
}
//////////////////////////////////////

int deep[N];//
int order[N];//
int indx=0;
int par[N];
int parw[N];

/*
void precomp_par(int u, int p)
{
	for(int i=0;i<T[u].size();i++)
	{
		int v=T[u][i].fi;
		if(v==p) continue;
		parw[v] = T[u][i].se;
		precomp_par(v,u);
	}
}
*/
struct Lca_Online
{
    int _n;
    
    int dp[N][LN];
    int dpw[N][LN];
    void _dfs(int s,int fa,int dd)
    {
		//////cerr<<"DFS : "<<s<<' '<<fa<<' '<<dd<<'\n';
        deep[s] = dd;
        order[s] = ++indx;
        for(int p=pre[s];p!=-1;p=edge[p].next)
        {
            int v = edge[p].to;
            if(v == fa) continue;
            //cerr<<"EDGE : "<<s<<' '<<v<<' '<<edge[p].cost<<'\n';
            _dfs(v,s,dd+1);
            dp[v][0] = s;
            dpw[v][0] = edge[p].cost;
            ////cerr<<"WAY : "<<v<<' '<<0<<' '<<parw[v]<<'\n';
            par[v]=s;
        }
    }
    
    void _init()
    {
        for(int j=1;(1<<j)<=_n;j++)
        {
            for(int i=1;i<=_n;i++)
            {
				//////cerr<<i<<' '<<j<<endl;
                if(dp[i][j-1]!=-1) 
                {
					dp[i][j] = dp[ dp[i][j-1] ][j-1];
					dpw[i][j] = max(dpw[i][j-1], dpw[dp[i][j-1]][j-1]);
				}
				else dpw[i][j]=dpw[i][j-1];
            }
        }
    }
    void lca_init(int n)
    {
        _n = n;
        memset(dp,-1,sizeof(dp));
        //_dfs(firstid,-1,0);
        indx = 0;
        _dfs(0,-1,0);
        //////cerr<<"HERE"<<endl;
        _init();
    }
    
    int lca_query(int a,int b)
    {
        if(deep[a]>deep[b]) swap(a,b);
        //ba
        for(int i=LN-1;deep[b]>deep[a];i--)
            if(deep[b]-(1<<i) >= deep[a]) b = dp[b][i];
        if(a == b) return a;
        for(int i=LN-1;i>=0;i--)
        {
            if(dp[a][i]!=dp[b][i]) a = dp[a][i],b = dp[b][i];
        }
        return dp[a][0];
    }
    int get_max(int a, int b)
    {
		if(deep[a]>deep[b]) swap(a,b);
		int oria=a; int orib=b;
		//cerr<<"QUERY "<<a<<' '<<b<<'\n';
        //ba
        int ans=0;
        for(int i=LN-1;deep[b]>deep[a];i--)
        {
            if(deep[b]-(1<<i) >= deep[a]) 
            {
				ans=max(dpw[b][i],ans); b = dp[b][i];
			}
		}
		
        if(a == b) 
        {
			//cerr<<"GET ANS : "<<oria<<' '<<orib<<' '<<ans<<'\n';
			return ans;
		}
        for(int i=LN-1;i>=0;i--)
        {
            if(dp[a][i]!=dp[b][i]) 
            {
				ans=max(ans,max(dpw[i][a],dpw[i][b]));
				a = dp[a][i],b = dp[b][i];
			}
        }
        ans = max(ans, max(dpw[0][a], dpw[0][b]));
        //cerr<<"GET ANS : "<<oria<<' '<<orib<<' '<<ans<<'\n';
        return ans;
	}
}lca;

int stk[N],top;
int mark[N];//
vector<int>tree[N];//
vector<int>treew[N];//

void tree_add(int u,int v,int w)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
    treew[u].push_back(w);
    treew[v].push_back(w);
}

// lca.lca_init(n); 
//,
int build_vtree(vector<int> &vp,int vn)//dfs(dfs)
{
    if(vn == 0) return -1;
    top = 0;
    
    stk[top++] = vp[0];
    tree[ vp[0] ].clear();
    treew[ vp[0] ].clear();
    mark[ vp[0] ]=1;
    for(int i=1;i<vn;i++)
    {
        int v = vp[i];
        
        int plca = lca.lca_query(stk[top-1], v);//
        if(plca == stk[top-1]) ;//
        else
        {
            int pos=top-1;
            while(pos>=0 && deep[ stk[pos] ]>deep[plca])
                pos--;
            pos++;
            for(int j=pos;j<top-1;j++)
            {
                tree_add(stk[j],stk[j+1],lca.get_max(stk[j],stk[j+1]));
            }
            int prepos = stk[pos];
            if(pos == 0)
            {
                tree[plca].clear(),treew[plca].clear(),stk[0]=plca,top=1;
                mark[plca] = 0;
            }
            else if(stk[pos-1] != plca)
            {
                tree[plca].clear(),treew[plca].clear(),stk[pos]=plca,top=pos+1;
                mark[plca] = 0;
            }
            else top = pos;
            tree_add(prepos,plca,lca.get_max(prepos,plca));
            
        }
        tree[v].clear();
        treew[v].clear();
        stk[top++] = v;
        mark[v] = 1;
    }
    for(int i=0;i<top-1;i++)
    {
		tree_add(stk[i],stk[i+1],lca.get_max(stk[i],stk[i+1]));
        //tree_add(stk[i], stk[i+1], deep[stk[i+1]]-deep[stk[i]]);
    }

    return vp[0];
}

//////////////----//////////////////////
struct vnode
{
    int order,id;
}vg[N];
int vcmp(vnode t1,vnode t2)
{
    return t1.order<t2.order;
}
int vsort(vector<int> &vp,int vn)//.
{
    for(int i=0;i<vn;i++) vg[i].id = vp[i],vg[i].order = order[ vp[i] ];
    sort(vg,vg+vn,vcmp);
    for(int i=0;i<vn;i++) vp[i]=vg[i].id;
    
    return build_vtree(vp, vn);
}

ll res;
bool good[500101];
vector<pair<ll,ii> > smalle;
void dfs(int u, int p)
{
	/*
	vi child;
	ll sum=0; int mn=int(1e9);
	////cerr<<"TREE : "<<u<<' '<<p<<' '<<gd<<'\n';
	for(int i=0;i<tree[u].size();i++)
	{
		int v=tree[u][i];
		if(v==p) continue;
		dfs(v,u,(treew[u][i]==1));
		if(treew[u][i]==2)
		{
			int mid = par[v];
			if(good[u]&&good[v]&&!good[mid])
			{
				res += max(parw[v], parw[mid]);
			}
		}
		else if(treew[u][i]==1&&good[v])
		{
			mn=min(mn,parw[v]);
			sum+=parw[v];
		}
	}
	if(good[u])
	{
		for(int i=0;i<tree[u].size();i++)
		{
			int v=tree[u][i];
			if(v==p) continue;
			if(treew[u][i]==1) res+=parw[v];
		}
	}
	else
	{
		if(gd&&good[p])
		{
			sum+=parw[u]; mn=min(mn,parw[u]);
			if(mn<int(1e9))
			{
				res+=sum-mn;
			}
		}
	}
	*/
	for(int i=0;i<tree[u].size();i++)
	{
		int v=tree[u][i];
		if(v==p) continue;
		////cerr<<"P : "<<u<<' '<<v<<' '<<treew[u][i]<<'\n';
		smalle.pb(mp(treew[u][i],mp(u,v)));
		res+=treew[u][i];
		dfs(v,u);
	}
}


int dsu2[500001];
int rt2(int u)
{
	if(dsu2[u]<0) return u;
	else return (dsu2[u]=rt2(dsu2[u]));
}
void merge2(int u, int v)
{
	u=rt2(u); v=rt2(v);
	if(u==v) return ;
	if(dsu2[u]>dsu2[v]) swap(u,v);
	dsu2[u]+=dsu2[v]; dsu2[v]=u;
}

ll solve(vector<int> &vec)
{
	int rt = vsort(vec,vec.size()); //not sure if need to reinitialize
	res=0;
	if(rt!=-1)
	{
		smalle.clear();
		dfs(rt,-1);
		sort(smalle.begin(),smalle.end());

		for(int i=0;i+1<vec.size();i++)
		{
			merge2(vec[i],vec[i+1]);
		}
		for(int i=0;i<smalle.size();i++)
		{
			int u=smalle[i].se.fi; int v=smalle[i].se.se;
			if(rt2(u)!=rt2(v))
			{
				res-=smalle[i].fi;
				merge2(u,v);
			}
		}
		for(int i=0;i<smalle.size();i++)
		{
			dsu2[smalle[i].se.fi]=dsu2[smalle[i].se.se]=-1;
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(pre,-1,sizeof(pre));
	cin>>n>>m;
	memset(dsu2,-1,sizeof(dsu2));
	vector<pair<ll,ii> > edges;
	memset(dsupar,-1,sizeof(dsupar));
	for(int i=0;i<m;i++)
	{
		int u,v,w; cin>>u>>v>>w;
		u--; v--;
		E[i]=mp(w,mp(u,v));
		edges.pb(E[i]);
	}
	sort(edges.begin(),edges.end());
	for(int i=0;i<m;i++)
	{
		int u=edges[i].se.fi; int v=edges[i].se.se; int w=edges[i].fi;
		if(rt(u)!=rt(v))
		{
			T[u].pb(mp(v,w)); T[v].pb(mp(u,w));
			add_edge(u,v,w); add_edge(v,u,w);
			merge(u,v);
		}
	}
	//precomp_par(0,-1);
	lca.lca_init(n);

	memset(dsupar,-1,sizeof(dsupar));
	int q; cin>>q;
	for(int i=0;i<q;i++)
	{
		int k; cin>>k;
		vi involve;
		bool pos=1;
		ll ans=0;
		for(int j=0;j<k;j++)
		{
			int x; cin>>x;
			x--;
			int u=E[x].se.fi; int v=E[x].se.se; int w=E[x].fi;
			ans+=w;
			involve.pb(u); involve.pb(v);
			//cerr<<"MERGE : "<<u<<' '<<v<<' '<<(rt(u)==rt(v))<<'\n';
			if(rt(u)==rt(v))
			{
				pos=0;
			}
			else
			{
				merge(u,v);
			}
		}
		
		if(!pos)
		{
			cout<<"NO\n";
		}
		else
		{
			sort(involve.begin(),involve.end());
			involve.erase(unique(involve.begin(),involve.end()),involve.end());
			for(int j=0;j<involve.size();j++)
			{
				int u=involve[j]; good[u]=1;
				V[rt(u)].pb(u);
			}
			for(int j=0;j<involve.size();j++)
			{
				int u=involve[j];
				if(u==rt(u))
				{
					////cerr<<"SPECIAL : "<<i<<' '<<u<<' '<<V[u].size()<<'\n';
					ans-=solve(V[u]);
				}
			}
			for(int j=0;j<involve.size();j++)
			{
				int u=involve[j]; good[u]=0;
				if(u==rt(u)) V[u].clear();
			}
			if(ans==0)
			{
				cout<<"YES\n";
			}
			else
			{
				cout<<"NO\n";
			}
		}
		
		for(int j=0;j<involve.size();j++) dsupar[involve[j]]=-1;
	}
}