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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = (1e9 + 7);
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}
int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
int choose(int a, int b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
}
int inverse(int a)
{
	return modpow(a,MOD-2);
}
void init(int _n)
{
	fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
	fact.resize(_n+1);
	ifact.resize(_n+1);
	inv.resize(_n+1);
	pow2.resize(_n+1);
	pow2[0]=1;
	ifact[0]=1;
	fact[0]=1;
	for(int i=1;i<=_n;i++)
	{
		pow2[i]=add(pow2[i-1],pow2[i-1]);
		fact[i]=mult(fact[i-1],i);
		//ifact[i]=mult(ifact[i-1],inv[i]);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--)
	{
		ifact[i] = mult(ifact[i + 1], i + 1);
	}
	for(int i=1;i<=_n;i++)
	{
		inv[i] = mult(fact[i-1],ifact[i]);
	}
}
	
vector<ii> adj[1299999];

void add(int u, int v, int d)
{
	adj[u].pb({v,d});
}

int dist[1299999];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	int cur=n;
	for(int i=1;i<=m;i++)
	{
		int u,v; cin>>u>>v;
		u--; v--;
		int d=i;
		vi dig;
		while(d>0)
		{
			dig.pb(d%10); d/=10;
		}
		reverse(dig.begin(),dig.end());
		{
			vi chain;
			chain.pb(u); 
			for(int k=0;k<int(dig.size())-1;k++)
			{
				chain.pb(cur++);
			}
			chain.pb(v);
			for(int k=0;k+1<chain.size();k++)
			{
				add(chain[k],chain[k+1],dig[k]);
			}
		}
		{
			swap(u,v);
			vi chain;
			chain.pb(u); 
			for(int k=0;k<int(dig.size())-1;k++)
			{
				chain.pb(cur++);
			}
			chain.pb(v);
			for(int k=0;k+1<chain.size();k++)
			{
				add(chain[k],chain[k+1],dig[k]);
			}
		}
	}
	deque<vi> Q;
	Q.pb({0});
	memset(dist,-1,sizeof(dist));
	dist[0]=0;
	while(!Q.empty())
	{
		deque<vi> newQ;
		while(!Q.empty())
		{
			vi vv = Q.front(); Q.pop_front();
			for(int d=0;d<10;d++)
			{
				vi emp;
				for(int x:vv)
				{
					for(ii e:adj[x])
					{
						if(dist[e.fi]<0&&e.se==d)
						{
							dist[e.fi]=add(mult(dist[x],10),d);
							//cerr<<x<<' '<<e.fi<<' '<<dist[e.fi]<<'\n';
							emp.pb(e.fi);
						}
					}
				}
				if(!emp.empty())
				{
					newQ.pb(emp);
				}
			}			
		}
		Q=newQ;
	}
	for(int i=1;i<n;i++)
	{
		cout<<dist[i]<<'\n';
	}
}