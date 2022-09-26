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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ii x[333333];
int used[2][333333];

int solve(deque<int> &v, deque<int> &sq, int st)
{
	if(v.empty()) return 0;
	int n=v.size();
	int ans=int(1e9);
	int startp=n;
	//cerr<<"SOLVE "<<v.size()<<' '<<sq.size()<<' '<<st<<'\n';
	for(int z=0;z<2;z++)
	{
		int mx[2] = {-1,-1};
		mx[z]=v[0];
		used[z][v[0]]=1;
		int ptr=st;
		while(used[z][ptr]) ptr++; 
		//ptr pints to first place not covered
		int res=0;
		if(sq[0]^z) res++; //in general, check if sq[i]^current place you want to go
		if(v[0]==st) {ans=0; startp=1; break;}
		for(int i=1;i<n;i++)
		{
			while(used[z][ptr]) ptr++; 
			vi pos;
			for(int j=0;j<2;j++)
			{
				if(v[i]>mx[j]) 
				{
					pos.pb(j);
				}
			}
			if(pos.size()>=2&&v[i]!=ptr)
			{
				if(mx[0]>mx[1]) pos={0};
				else pos={1}; //put at the higher place
			}
			if(pos.empty()) return -1;
			else if(pos.size()==1)
			{
				mx[pos[0]]=v[i];
				if(pos[0]^sq[i]) res++;
			}
			else
			{
				assert(int(pos.size())==2);
				startp = i; break;
			}
			used[z][v[i]]=1;
			while(used[z][ptr]) ptr++; 
			if(ptr==st+i+1) 
			{
				startp=i+1; break;
			}
		}
		ans=min(ans,res);
	}
	for(int i=0;i<startp;i++) 
	{
		v.pop_front(); sq.pop_front();
	}
	int newres = solve(v,sq,st+startp);
	if(newres==-1) return -1;
	return ans+newres;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i].fi>>x[i].se;
		x[i].fi--; x[i].se--;
		if(min(x[i].fi,x[i].se)>=n) //>= half
		{
			cout<<-1<<'\n'; return 0;
		}
	}
	deque<int> p(n);
	deque<int> sq(n,0);
	for(int i=0;i<n;i++)
	{
		int mn=min(x[i].fi,x[i].se);
		int mx=max(x[i].fi,x[i].se);
		p[mn]=n-1-(mx-n); //reverse liao, now i want find 2 LISes
		if(x[i].fi==mx) sq[mn]=1; //flipped
	}
	/*
	for(int x:p)
	{
		cerr<<x<<' ';
	}
	cerr<<'\n';
	for(int x:sq)
	{
		cerr<<x<<' ';
	}
	cerr<<'\n';
	*/
	int res = solve(p,sq,0);
	cout<<res<<'\n';
}