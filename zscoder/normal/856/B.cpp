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
typedef long double ld; 
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;
const int MAXN = 2000011, sigma = 26;
 
int term[2][MAXN], to[MAXN][sigma], sz = 1;
int cnt;
int par[MAXN+111];
vi adj[MAXN+111];

int rt(int u)
{
	if(par[u]<0) return u;
	else return (par[u]=rt(par[u]));
}

void merge(int u, int v)
{
	u=rt(u); v=rt(v);
	if(u==v) return ;
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
bool used[2000111];
void add_str(string &s, bool type)
{
    int cur = 0;
    for(auto c: s)
    {
        if(!to[cur][c - 'a'])
        {
            to[cur][c - 'a'] = sz++;
        }
        cur = to[cur][c - 'a'];
        cnt++;
        if(!type)
        {
			used[cnt]=1;
			if(term[type][cur])
			{
				//cerr<<"MERGE : "<<term[type][cur]<<' '<<cnt<<'\n';
				merge(term[type][cur],cnt);
			}
			else
			{
				term[type][cur]=cnt;
			}
		}
		else
		{
			if(term[0][cur])
			{
				//cerr<<"ADJ : "<<rt(term[0][cur])<<' '<<rt(cnt)<<'\n';
				adj[rt(term[0][cur])].pb(rt(cnt)); //maybe add backward edge just to be safe?
				adj[rt(cnt)].pb(rt(term[0][cur]));
			}
		}
    }
}
bool vis[2000111];
ii dfs(int u, int p)
{
	vis[u]=1;
	ii tmp = mp(0,1);
	for(int i=0;i<adj[u].size();i++)
	{
		int v=adj[u][i];
		if(vis[v]||v==p) continue;
		ii z = dfs(v,u);
		tmp.se+=z.fi;
		tmp.fi+=max(z.fi,z.se);
	}
	return tmp;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	memset(par,-1,sizeof(par));
	while(t--)
	{
		int n; cin>>n;
		sz=1;
		int tot=0;
		cnt=0;
		vector<pair<string,int> > V;
		for(int i=0;i<n;i++)
		{
			string s; cin>>s;
			tot+=2*int(s.length());
			int cur = cnt;
			add_str(s,0);
			string t = s.substr(1,int(s.length()) - 1);
			V.pb(mp(t,cur+1));
			//add_str(t,1);
		}
		for(int i=0;i<n;i++)
		{
			cnt=V[i].se;
			add_str(V[i].fi,1);
		}
		int ans=0;
		for(int i=0;i<=tot+5;i++)
		{
			if(used[i]&&rt(i)==i&&!vis[i])
			{
				//cerr<<i<<'\n';
				ii tmp = dfs(i,-1);
				//cerr<<i<<' '<<tmp.fi<<' '<<tmp.se<<'\n';
				ans+=max(tmp.fi,tmp.se);
			}
		}
		cout<<ans<<'\n';
		for(int i=0;i<=tot+5;i++) 
		{
			used[i]=0;par[i]=-1;vis[i]=0;
		}
		for(int i=0;i<=tot+5;i++) adj[i].clear();
		for(int i=0;i<=sz;i++)
		{
			term[0][i]=term[1][i]=0;
			for(int j=0;j<sigma;j++) to[i][j]=0;
		}
	}
}