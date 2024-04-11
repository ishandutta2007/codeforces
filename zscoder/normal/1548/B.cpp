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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;


ll st[19][222222];
const int LG=19;

ll query(int l, int r)
{
	int k = 31 - __builtin_clz(r-l);
	if(l==r) k=0;
	return __gcd(st[k][l], st[k][r - (1<<k) + 1]);
}

void solve()
{
	int n; cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<ll> d(n-1);
	for(int i=0;i<n-1;i++)
	{
		d[i]=a[i+1]-a[i];
	}
	for(int i=0;i<LG;i++)
	{
		for(int j=0;j<n;j++)
		{
			st[i][j]=0;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		st[0][i]=d[i];
	}
	for(int i=1;i<LG;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			st[i][j]=st[i-1][j];
			if(j+(1<<(i-1))<n-1)
			{
				st[i][j]=__gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
			}
		}
	}
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		int lo=i; int hi=n-2;
		int res=i-1;
		//[i,ans] has gcd > 1
		while(lo<=hi)
		{
			int mid=(lo+hi)>>1;
			ll ggd = query(i,mid);
			if(ggd==0) ggd=ll(1e10);
			if(abs(ggd)>1)
			{
				res=mid; lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
		//cerr<<i<<' '<<res<<'\n';
		ans=max(ans,res-i);
	}
	cout<<min(n,ans+2)<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}