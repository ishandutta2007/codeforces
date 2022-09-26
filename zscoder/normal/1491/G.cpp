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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[222222];
int pos[222222];
int col[222222];

vector<ii> moves;

void sw(int u, int v)
{
	moves.pb({u,v});
	swap(a[u],a[v]);
	pos[a[u]]=u;
	pos[a[v]]=v;
	col[a[u]]^=1; col[a[v]]^=1;
}

void swp(int u, int v)
{
	sw(pos[u],pos[v]);
}

vector<vi> cyc;
bool vis[222222];

void dfs(int u)
{
	vis[u]=1;
	cyc.back().pb(u);
	if(vis[pos[u]]) return ;
	dfs(pos[u]);
}

const bool DEBUG=0;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(NULL));
	for(int cc=1;;cc++)
	{
		moves.clear(); cyc.clear();
		int n;
		if(DEBUG) n=rand()%10+3;
		else cin>>n;
		for(int i=0;i<n;i++)
		{
			vis[i]=0;
			if(!DEBUG) cin>>a[i]; 
			a[i]--;
		}
		if(DEBUG)
		{
			for(int i=0;i<n;i++) a[i]=i;
			random_shuffle(a,a+n);
			/*
			cerr<<n<<'\n';
			for(int i=0;i<n;i++)
			{
				cerr<<a[i]+1<<' ';
			}
			cerr<<'\n';
			*/
		}
		for(int i=0;i<n;i++)
		{
			pos[a[i]]=i;
		}
		for(int i=0;i<n;i++)
		{
			if(vis[i]) continue;
			cyc.pb(vi());
			dfs(i);
			if(cyc.back().size()==1) cyc.pop_back();
		}
		//we handle pairs of cycles simultaneously
		while(cyc.size()>=2)
		{
			vi x = cyc[int(cyc.size())-2];
			vi y = cyc[int(cyc.size())-1];
			cyc.pop_back(); cyc.pop_back();
			swp(x[0],y[0]);
			for(int i=int(x.size())-1;i>=1;i--)
			{
				swp(x[i],x[(i+1)%int(x.size())]);
			}
			for(int i=int(y.size())-1;i>=1;i--)
			{
				swp(y[i],y[(i+1)%int(y.size())]);
			}
			swp(x[1],y[1]);
			for(int z:x)
			{
				assert(a[z]==z);
				assert(col[z]==0);
			}
			for(int z:y)
			{
				assert(a[z]==z);
				assert(col[z]==0);
			}
		}
		if(cyc.size()>0)
		{
			//last cycle, solve it
			vi c = cyc[0];
			if(c.size()==2)
			{
				vi fixed;
				for(int i=0;i<n;i++)
				{
					if(a[i]==i) fixed.pb(i);
				}
				swp(fixed[0],c[0]);
				swp(c[1],c[0]);
				swp(c[1],fixed[0]);
			}
			else
			{
				swp(c[0],c[1]);
				for(int i=int(c.size())-1;i>=3;i--)
				{
					swp(c[i],c[(i+1)%int(c.size())]);
				}
				int v = c[3%int(c.size())];
				int u = c[2];
				int w = c[1];
				//v and w are bad, v<->u, w solo
				swp(u,w);
				//now u,v are bad
				swp(w,v);
				swp(w,u);
			}
		}
		assert(int(moves.size())<=n+1);
		if(!DEBUG)
		{
			cout<<moves.size()<<'\n';
			for(auto X:moves)
			{
				cout<<X.fi+1<<' '<<X.se+1<<'\n';
			}
		}
		for(int i=0;i<n;i++)
		{
			assert(a[i]==i); assert(col[i]==0);
		}
		if(!DEBUG) return 0;
		cerr<<"Case #"<<cc<<" complete\n";
	}
}