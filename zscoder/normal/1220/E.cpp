#include <bits/stdc++.h>

using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 

const int N = 222222;
const int M = 222222;

vi tree[N]; // The bridge edge tree formed from the given graph
vi graph[N];int U[M],V[M];  //edge list representation of the graph. 
bool isbridge[M]; // if i'th edge is a bridge edge or not 
int visited[N];int arr[N],T; //supporting arrays
int cmpno;
queue<int> Q[N];

int adj(int u,int e){
    return U[e]==u?V[e]:U[e];
}
int dfs0(int u,int edge)    //marks all the bridges
{
    visited[u]=1;
    arr[u]=T++;
    int dbe = arr[u];
    for(int i=0;i<(int)graph[u].size();i++)
    {
        int e = graph[u][i];
        int w = adj(u,e);
        if(!visited[w])
            dbe = min(dbe,dfs0(w,e));
        else if(e!=edge)
            dbe = min(dbe,arr[w]);
    }
    if(dbe == arr[u] && edge!=-1)
        isbridge[edge]=true;
    return dbe;
}

ll a[233333];
ll val[233333];
int siz[233333];
void dfs1(int v) //Builds the tree with each edge a bridge from original graph
{
    int currcmp = cmpno;    // current component no.
    Q[currcmp].push(v);    // A different queue for each component, coz   during bfs we shall go to another component (step of dfs) and then come   back to this one and continue our bfs
    visited[v]=1;
    val[currcmp]+=a[v];
    siz[currcmp]++;
    //cerr<<currcmp<<' '<<v<<'\n';
    while(!Q[currcmp].empty())    //bfs. Exploring all nodes of this  component
    {
        int u = Q[currcmp].front();    
        Q[currcmp].pop();    
        for(int i=0;i<(int)graph[u].size();i++)
        {
            int e = graph[u][i];
            int w = adj(u,e);
            if(visited[w])continue;
            //if the edge under consideration is bridge and
            //other side is not yet explored, go there (step of dfs)
            if(isbridge[e])
            {
                cmpno++;
                tree[currcmp].push_back(cmpno);
                tree[cmpno].push_back(currcmp);
                dfs1(w);
            }
            else     //else continue with our bfs
            {
                Q[currcmp].push(w);
                siz[currcmp]++;
                // cerr<<currcmp<<' '<<w<<'\n';
                val[currcmp]+=a[w];
                visited[w]=1;
            }
        }
    }
}

ll dp[2][333333];

void dfs_dp(int u, int p=-1)
{
	for(int v:tree[u])
	{
		if(v==p) continue;
		dfs_dp(v,u);
		siz[u]+=siz[v];
	}
	ll S=0;
	for(int v:tree[u])
	{
		if(v==p) continue;
		if(siz[v]>0)
		{
			dp[0][u]+=dp[0][v];
			S+=dp[0][v];
		}
	}
	for(int v:tree[u])
	{
		if(v==p) continue;
		if(siz[v]>0)
		{
			dp[1][u]=max(dp[1][u],S-dp[0][v]+dp[1][v]);
		}
		else
		{
			dp[1][u]=max(dp[1][u],S+dp[1][v]);
		}
	}
	dp[1][u]=max(dp[1][u],dp[0][u]);
	dp[0][u]+=val[u];
	dp[1][u]+=val[u];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; 
	cin>>n>>m;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		int u,v; 
		cin>>u>>v; u--; v--; 
		U[i]=u; V[i]=v;
		graph[u].pb(i); graph[v].pb(i);
	}
	int s; cin>>s; s--;
	dfs0(s,-1);
	memset(visited,0,sizeof(visited));
	dfs1(s);
	for(int i=0;i<N;i++)
	{
		if(siz[i]>0) siz[i]--;
	}
	/*
	for(int i=0;i<N;i++)
	{
		if(val[i]>0)
		{
			cerr<<"V: "<<i<<' '<<val[i]<<' '<<siz[i]<<'\n';
		}
	}
	*/
	dfs_dp(0,-1); //from node 0 
	cout<<max(dp[0][0],dp[1][0])<<'\n';
}