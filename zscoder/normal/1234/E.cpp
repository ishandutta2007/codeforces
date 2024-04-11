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

int a[222222];
ll res[222222];

void add(int l, int r, ll v)
{
	if(l>r) return ;
	res[l]+=v;
	res[r+1]-=v;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	ll ans=0;
	for(int i=0;i<m;i++)
	{
		cin>>a[i]; a[i]--;
		if(i>0) ans+=abs(a[i]-a[i-1]);
	}
	add(0,n-1,ans);
	for(int i=0;i+1<m;i++)
	{
		if(a[i]==a[i+1]) continue;
		int l=a[i];
		int r=a[i+1];
		if(l>r) swap(l,r);
		{
			add(l+1,r-1,-1);
			add(l,l,l);
			add(r,r,-abs(l-r));
			add(r,r,l+1);
		}
	}
	for(int i=1;i<=211111;i++)
	{
		res[i]+=res[i-1];
	}
	for(int i=0;i<n;i++)
	{
		cout<<res[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}