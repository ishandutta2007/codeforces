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

const int C = 6;
map<ii,int> dp[C+2];
//1 is P1 win, 0 is draw

int p3[C+11];
const int N = 500111;
vi adj[N];

int solve_small(int n, int bit, int player)
{
	if(dp[n].find(mp(bit,player))!=dp[n].end()) return dp[n][mp(bit,player)];
	//cerr<<n<<' '<<bit<<' '<<player<<'\n';
	bool exmove=0;
	int playercolor=1;
	if(!player) playercolor=2;
	for(int i=0;i<n;i++)
	{
		int mode = (bit/p3[i])%3;
		if(mode==0)
		{
			exmove=1;
			int tmp = solve_small(n, bit+p3[i]*playercolor, player^1);
			if(tmp==player) return (dp[n][mp(bit,player)]=player);
		}
	}
	if(!exmove)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<adj[i].size();j++)
			{
				for(int k=j+1;k<adj[i].size();k++)
				{
					int u=i; int v=adj[i][j]; int w=adj[i][k];
					if((bit/p3[u])%3==1&&(bit/p3[v])%3==1&&(bit/p3[w])%3==1) return (dp[n][mp(bit,player)]=1);
				}
			}
		}
		return (dp[n][mp(bit,player)]=0);
	}
	return (dp[n][mp(bit,player)]=player^1);
}
int n; 
void solve_case()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v); adj[v].pb(u);
	}
	string s; cin>>s;
	for(int i=0;i<=C;i++) dp[i].clear();
	if(n<=C)
	{
		int bit = 0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='W') bit+=p3[i];
		}
		int res = solve_small(n,bit,1);
		if(res==1) cout<<"White\n";
		else cout<<"Draw\n";
	}
	else
	{
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(adj[i].size()>=4){cout<<"White\n"; return ;}
			if(adj[i].size()>=3) cnt++;
		}
		if(cnt>=3){cout<<"White\n"; return ;}
		if(cnt==0)
		{
int g=0;
			for(int i=0;i<n;i++)
			{
				if(s[i]=='W'&&adj[i].size()>=2){cout<<"White\n"; return ;}
g+=(s[i]=='W');
			}
if(g==2&&n%2==1) cout<<"White"<<endl;
			else cout<<"Draw\n"; 
			return ;
		}
		int r=0;
		for(int i=0;i<n;i++)
		{
			if(adj[i].size()==3) r=i;
		}
		vi nonempty;
		if(s[r]=='W'){cout<<"White\n"; return ;}
		for(int v:adj[r])
		{
			if(s[v]=='W'){cout<<"White\n"; return ;}
			if(adj[v].size()>1)
			{
				nonempty.pb(v);
			}
		}
		if(nonempty.size()>=2){cout<<"White\n"; return ;}
		int u = nonempty[0];
		int p = r;
		while(adj[u].size()==2)
		{
			int nw=-1;
			for(int v:adj[u])
			{
				if(v==p) continue;
				nw=v;
			}
			p=u; u=nw;
		}
		if(adj[u].size()==1)
		{
			//which set of initial does white win
			bool ex=0;
			for(int i=0;i<n;i++)
			{
				if(s[i]=='W'&&adj[i].size()>=2){cout<<"White\n"; return ;}
				if(s[i]=='W') ex=1;
			}
			if(ex)
			{
				if(n%2==0){cout<<"White\n"; return ;}
			}
			cout<<"Draw\n"; 
			return ;
		}
		for(int v:adj[u])
		{
			if(v!=p)
			{
				if(adj[v].size()>1){cout<<"White\n"; return ;}
				if(s[v]=='W'){cout<<"White\n"; return ;}
			}
		}
		//which set of initial does white win
		for(int i=0;i<n;i++)
		{
			if(s[i]=='W'){cout<<"White\n"; return ;}
		}
		if(n%2==1){cout<<"White\n"; return ;}
		cout<<"Draw\n"; return ;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	p3[0]=1;
	for(int i=1;i<=15;i++) p3[i]=p3[i-1]*3;
	while(t--)
	{
		solve_case();
		for(int i=0;i<n;i++) adj[i].clear();
	}
}