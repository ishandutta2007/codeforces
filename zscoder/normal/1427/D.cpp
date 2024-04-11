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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve(const vi &a, int l, int r, vector<ii> &comps)
{
	int R=int(1e9);
	for(int i=r;i>=l;i--)
	{
		if(a[i]==i) R=i;
		else break;
	}
	int L=-1;
	for(int i=l;i<=r;i++)
	{
		if(a[i]==i) L=i;
		else break;
	}
	//cerr<<"LR: "<<L<<' '<<R<<' '<<l<<' '<<r<<'\n';
	if(R==l) return ; //ok le
	if(L>=0&&R<int(1e9)) //recursion needed
	{
		solve(a,L+1,R-1,comps);
		comps.pb({l,L});
		comps.pb({R,r});
		return ;
	}
	if(R>=int(1e9))
	{
		int pos=-1;
		for(int i=l;i<=r;i++)
		{
			if(a[i]==a[r]+1) pos=i;
		}
		assert(pos!=-1);
		int las=r;
		for(int i=r-1;i>=l;i--)
		{
			if(a[i]+1==a[i+1]) las=i;
			else break;
		}
		comps.pb({las,r});
		comps.pb({pos,las-1});
		comps.pb({l,pos-1});
	}
	else
	{
		int pos=-1;
		for(int i=l;i<=r;i++)
		{
			if(a[i]==a[l]-1) pos=i;
		}
		assert(pos!=-1);
		int las=l;
		for(int i=l+1;i<=r;i++)
		{
			if(a[i-1]+1==a[i]) las=i;
			else break;
		}
		comps.pb({l,las});
		comps.pb({las+1,pos});
		comps.pb({pos+1,r});
	}
	return ;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vi a;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; x--; a.pb(x);
	}
	vector<vi> ans;
	for(int z=0;z<n;z++)
	{
		vector<ii> cmps;
		solve(a,0,n-1,cmps);
		if(cmps.empty()) break;
		vector<ii> sorted;
		for(ii x:cmps)
		{
			if(x.fi>x.se) continue;
			sorted.pb({x.fi,x.se});
		}
		sort(sorted.begin(),sorted.end());
		vi nw;
		for(int z=int(sorted.size())-1;z>=0;z--)
		{
			int l=sorted[z].fi; int r=sorted[z].se;
			for(int i=l;i<=r;i++)
			{
				nw.pb(a[i]);
			}
		}
		vi lul;
		for(ii x:sorted)
		{
			lul.pb(x.se-x.fi+1);
		}
		ans.pb(lul);
		a=nw;
		
	}
	/*
	for(int x:a)
	{
		cerr<<x<<' ';
	}
	cerr<<'\n';
	*/
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].size()<<' ';
		for(int v:ans[i]) cout<<v<<' ';
		cout<<'\n';
	}
}