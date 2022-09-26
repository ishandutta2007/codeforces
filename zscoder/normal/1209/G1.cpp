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

int a[222222];
vi v[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,q; cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; a[i]--;
		v[a[i]].pb(i);
	}
	int curmx=-1;
	int ans=n;
	int pos=-1;
	map<int,int> freq;
	for(int i=0;i<n;i++)
	{
		if(i>curmx)
		{
			int mm=0;
			for(ii x:freq)
			{
				mm=max(mm,x.se);
			}
			ans-=mm;
			freq.clear();
			pos=a[i];
			int mx=v[pos].back();
			curmx=mx;
			freq[a[i]]++;
			continue;
		}
		curmx=max(curmx,v[a[i]].back());
		freq[a[i]]++;
	}
	int mm=0;
	for(ii x:freq)
	{
		mm=max(mm,x.se);
	}
	ans-=mm;
	cout<<ans<<'\n';
}