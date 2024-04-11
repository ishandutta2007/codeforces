#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

int a[1111111];
int suf[1111111];
int threshold[1111111];
vi V[1111111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; a[i]--;
		V[a[i]].pb(i);
	}
	for(int i=n-1;i>=0;i--)
	{
		suf[i]=a[i];
		if(i<n-1) suf[i]=min(suf[i],suf[i+1]);
	}
	ll ans=0;
	for(int i=0;i<m;i++) threshold[i]=n;
	if(V[0].empty()) threshold[0]=-1;
	else threshold[0]=V[0].back();
	int absmax=0;
	for(int i=1;i<m;i++)
	{
		if(V[i].empty()) 
		{
			absmax=i;threshold[i]=threshold[i-1];
		}
		else
		{
			if(V[i][0]>threshold[i-1])
			{
				threshold[i]=V[i].back(); absmax=i;
			}
			else 
			{
				break;
			}
		}
	}
	int curmx = n;
	suf[n]=m-1;
	for(int r=m-1;r>=0;r--)
	{
		if(!V[r+1].empty())
		{
			if(V[r+1].back()>=curmx) break;
			curmx=V[r+1][0];
		}
		int maxl=min(r-1,min(absmax,suf[curmx]-1));
		ans+=maxl+2;
		//cerr<<r<<' '<<maxl<<'\n';
	}
	cout<<ans<<'\n';
}