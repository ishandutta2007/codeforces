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

int a[2222];
int cnt[111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vi v;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		v.pb(a[i]);
	}
	sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<n;i++)
	{
		a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();
	}
	int ans=n;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=3000;j++) cnt[j]=0;
		bool pos=1;
		for(int j=0;j<i;j++)
		{
			cnt[a[j]]++;
			if(cnt[a[j]]>1)
			{
				pos=0; break;
			}
		}
		if(!pos) continue;
		int c=i;
		for(int j=n-1;j>=0;j--)
		{
			cnt[a[j]]++;
			if(cnt[a[j]]>1)
			{
				pos=0; break;
			}
			else c++;
		}
		ans=min(ans,n-c);
	}
	cout<<ans<<'\n';
}