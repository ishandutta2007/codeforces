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

int pos[222222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vi a(n),b(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; a[i]--;
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];b[i]--; pos[b[i]]=i;
	}
	for(int i=0;i<n;i++) a[i]=pos[a[i]];
	int lo=0; int hi=n-1;
	int ans=0;
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		bool pos=1;
		for(int i=1;i<=mid;i++)
		{
			if(a[i]<a[i-1]) pos=0;
		}
		if(pos)
		{
			ans=mid; lo=mid+1;
		}
		else
		{
			hi=mid-1;
		}
	}
	cout<<n-1-ans<<'\n';
}