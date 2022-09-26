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
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[333333];
int pos[333333];
vector<ii> moves;

void sp(int x, int y)
{
	moves.pb({x,y});
	swap(pos[a[x]],pos[a[y]]);
	swap(a[x],a[y]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n; cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]; a[i]--; pos[a[i]]=i;
	}
	for(int i=n/2-1;i>=0;i--)
	{
		int l=i; int r=n-1-i;
		int posl=pos[l];
		while(posl!=l)
		{
			if(posl==n-1)
			{
				sp(posl,l); posl=pos[l];continue;
			}
			if(posl<l)
			{
				sp(posl,n-1);posl=pos[l]; continue;
			}
			if(posl>=r)
			{
				sp(posl,0);posl=pos[l]; continue;
			}
			
		}
		int posr=pos[r];
		while(posr!=r)
		{
			if(posr==0)
			{
				sp(posr,r); posr=pos[r];continue;
			}
			if(posr<=l)
			{
				sp(posr,n-1); posr=pos[r];continue;
			}
			if(posr>r)
			{
				sp(posr,0); posr=pos[r];continue;
			}			
		}
	}
	cout<<moves.size()<<'\n';
	for(int i=0;i<n;i++) assert(a[i]==i);
	for(ii x:moves)
	{
		cout<<x.fi+1<<' '<<x.se+1<<'\n';
	}
}