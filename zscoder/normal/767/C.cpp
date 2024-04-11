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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int dp[1000001];
int rt;
vi adj[1000001];
int sum;
int target;

int a[1000001];
int cntgood[1000001];
int pargood[1000001];
void prep(int u, int p)
{
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		prep(v,u);
		dp[u]+=dp[v];
		cntgood[u]+=cntgood[v];
	}
	dp[u]+=a[u];
	if(dp[u]==target) cntgood[u]++;
}


void thepargood(int u, int p)
{
    if(p!=-1&&dp[p]==target) pargood[u]++;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        pargood[v]+=pargood[u];
        //cout<<v<<' '<<dp[u]<<' '<<pargood[v]<<'\n';
        thepargood(v,u);
    }
}
int dfs(int u, int p)
{
	int ret=-1;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		int r=dfs(v,u);
		if(r!=-1) ret=r;
	}
	if(u!=rt&&dp[u]==target*2)
	{
		if(ret!=-1)
		{
			printf("%d %d\n", u+1,ret+1);
			exit(0);
		}
	}
	if(dp[u]==target)
	{
		return u;
	}
	return ret;
}

int s[1000001];
int e[1000001];
int t;
void calcse(int u, int p)
{
	s[u]=++t;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		calcse(v,u);
	}
	e[u]=++t;
}

bool insub(int u, int v)
{
	return (s[u]<=s[v]&&e[v]<=e[u]);
}
int n; 

void dfs2(int u, int p)
{
	int rem = cntgood[rt] - cntgood[u] - pargood[u];
	//cerr<<u<<' '<<cntgood[u]<<' '<<pargood[u]<<'\n';
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		dfs2(v,u);
	}
	if(u!=rt&&dp[u]==target)
	{
		//cerr<<u+1<<' '<<rem<<'\n';
		if(rem>0)
		{
			for(int i = 0; i < n; i++)
			{
				if(i==rt) continue;
				if(!insub(u, i)&&!insub(i,u)&&dp[i]==target)
				{
					printf("%d %d\n", u+1, i+1);
					exit(0);
				}
			}
		}
	}
}

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	scanf("%d",&n);
	//n=1000000;
	rt=0;
	for(int i = 0; i < n; i++)
	{
		int p, q;
		scanf("%d %d",&p,&q);
		/*
    	p=i;
    	if(i==0) q=2;
    	else if(i==n-1) q=1;
    	else q=0;
    	*/
		//p=i;q=0;
		p--;
		if(p>=0) adj[p].pb(i);
		else rt=i;
		a[i] = q;
		sum+=q;
	}
	if(abs(sum)%3!=0)
	{
		cout<<-1;
		return 0;
	}
	target = sum/3;
	prep(rt,-1);
	thepargood(rt,-1);
	dfs(rt,-1);
	calcse(rt,-1);
	//cerr<<"GG";
	dfs2(rt,-1);
	cout<<-1;
}