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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll p[222222];
vector<ii> parents[222222];
int cur_node;ll ans;

void get_par(int h) //vertex u get a parent of height h
{
	p[++cur_node] = parents[h].back().fi;
	parents[h].back().se--;
	if(parents[h].back().se==0) parents[h].pop_back();
	parents[h+1].pb(mp(cur_node,ans));
}

vi adj[222222];

ll s[222222];
void dfs(int u, int p)
{
	s[u]=1;
	for(int v:adj[u])
	{
		dfs(v,u); s[u]+=s[v];
	}
}

void check(int n, ll SS)
{
	for(int i=1;i<n;i++)
	{
		adj[p[i]].pb(i);
	}
	for(int i=0;i<n;i++) assert(int(adj[i].size())<=ans);
	dfs(0,-1);
	ll S=0;
	for(int i=0;i<n;i++) S+=s[i];
	assert(S==SS);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,s; cin>>n>>s;
	if(s>=2*n-1&&s<=(n*(n+1))/2)
	{
		cout<<"Yes\n";
		if(s==(n*(n+1))/2)
		{
			for(int i=1;i<n;i++)
			{
				cout<<i;
				if(i+1<n) cout<<' ';
			}
			cout<<'\n';
			return 0;
		}
		ll lo = 2; ll hi = n-1; 
		while(lo<=hi)
		{
			ll mid=(lo+hi)>>1;
			//min achievable with branching = mid
			ll res=1; ll rem=n-1; ll avi=1; 
			for(ll h=2;;h++)
			{
				avi*=mid;
				if(rem<=avi)
				{
					res+=h*rem; break;
				}
				rem-=avi; res+=avi*h; 
			}
			if(s>=res)
			{
				ans=mid; hi=mid-1;
			}
			else
			{
				lo=mid+1;
			}
		}
		//ans is the branching factor
		ll sori=s;
		parents[1].pb(mp(0,ans)); cur_node=0; ll rem=n-1; s--; ll pre=1;
		for(ll h=2;;h++)
		{
			if(rem==0) break;
			ll lo = 1; ll hi = min(rem,ans*pre);
			ll res = -1;
			//at most how many child?
			while(lo<=hi)
			{
				ll mid=(lo+hi)>>1;
				//if mid children
				ll S = mid*h+h*(rem-mid)+((rem-mid)*(rem-mid+1))/2;
				//cerr<<mid<<' '<<S<<' '<<s<<'\n';
				/*
				ll avi=1; ll rm = rem-mid;
				for(ll h2=h+1;;h2++)
				{
					avi*=mid;
					if(rm<=avi)
					{
						S-=h2*rm; break;
					}
					rm-=avi; S-=avi*h2; 
				}
				*/
				if(S<s)
				{
					hi=mid-1;
				}
				else
				{
					res=mid; lo=mid+1;
				}
			}
			//cerr<<"H : "<<h<<' '<<res<<'\n';
			for(int j=0;j<res;j++) get_par(h-1);
			rem-=res; s-=res*h; pre=res;
		}
		
		for(int i=1;i<n;i++)
		{
			cout<<p[i]+1;
			if(i+1<n) cout<<' ';
		}
		cout<<'\n';
		
		check(n,sori);
	}
	else
	{
		cout<<"No\n";
	}
}