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

const bool DEBUG = 0;
int a[1111];
int query(vi v)
{
	if(v.size()==1) return 1;
	if(DEBUG)
	{
		int sum=0;
		for(int x:v)
		{
			sum+=a[x];
		}
		return (sum%int(v.size())==0);
	}
	cout<<"? "<<v.size()<<' ';
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i];
		if(i+1<v.size()) cout<<' ';
	}
	cout<<'\n';
	fflush(stdout);
	int x; cin>>x; return x;
}

const int N = 888;

int p[N];
int ps[N];
int currem[N];
int n; 
int mod;

void solve(int l, int r)
{
	vi pos;
	for(int i=1;i<=n;i++)
	{
		if(p[i]==0) pos.pb(i);
	}
	random_shuffle(pos.begin(),pos.end());
	if(l==1)
	{
		vi cand;
		for(int v:pos)
		{
			vi V;
			for(int x:pos)
			{
				if(x==v) continue;
				V.pb(x);
			}
			if(query(V)) cand.pb(v);
			if(cand.size()>=2) break;
		}	
		assert(cand.size()==2);
		ps[1]=cand[0];
		p[cand[0]]=1;
		ps[n]=cand[1];
		p[cand[1]]=n;
		//cerr<<cand[0]<<' '<<cand[1]<<'\n';
		return ;
	}
	for(int v:pos)
	{
		if(currem[v]%mod==l%mod)
		{
			vi V;
			for(int x:pos)
			{
				if(x==v) continue;
				V.pb(x);
			}
			if(query(V))
			{
				//cerr<<l<<' '<<v<<'\n';
				ps[l]=v;
				p[v]=l;
				break;
			}
		}
	}
	swap(l,r);
	for(int v:pos)
	{
		if(currem[v]%mod==l%mod)
		{
			vi V;
			for(int x:pos)
			{
				if(x==v) continue;
				V.pb(x);
			}
			if(query(V))
			{
				//cerr<<l<<' '<<v<<'\n';
				ps[l]=v;
				p[v]=l;
				break;
			}
		}
	}
}

int main()
{
	cin>>n;
	if(DEBUG)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
	}
	solve(1,n);
	for(int i=1;i<=n;i++)
	{
		if(p[i]==0)
		{
			if(query({ps[1],i})) currem[i]=1;
			else currem[i]=0;
			//cerr<<i<<' '<<currem[i]<<'\n';
		}
	}
	mod=2;
	for(int i=2;i<=n/2;i++)
	{
		solve(i,n+1-i);
		if(i==mod*2)
		{
			vi pos;
			for(int j=1;j<=n;j++)
			{
				if(p[j]==0) pos.pb(j);
			}
			for(int v:pos)
			{
				int r=currem[v]; int r2=currem[v]+mod;
				if(r2>n) continue;
				int x = (mod+r2-1)%(2*mod)+1;
				vi V;
				for(int j=1;j<=2*mod;j++)
				{
					if(j==x) continue;
					V.pb(ps[j]);
				}
				V.pb(v);
				if(query(V)) 
				{
					currem[v]=r2;
				}
				//cerr<<v<<' '<<currem[v]<<'\n';
			}
			mod*=2;
		}
	}
	if(p[1]>n/2)
	{
		for(int i=1;i<=n;i++)
		{
			p[i]=n+1-p[i];
		}
	}	
	cout<<"! ";
	for(int i=1;i<=n;i++)
	{
		cout<<p[i];
		if(i+1<=n) cout<<' ';
	}
	cout<<'\n'; fflush(stdout);
}