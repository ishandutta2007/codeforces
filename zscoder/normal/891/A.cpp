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
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int a[2111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) cnt++;
	}
	if(cnt==0)
	{
		cout<<0<<'\n';
		return 0;
	}
	int g=a[0];
	for(int i=1;i<n;i++) g=__gcd(a[i],g);
	if(g>1)
	{
		cout<<-1<<'\n';
		return 0;
	}
	int ans=100000;
	for(int i=0;i<n;i++)
	{
		int gc=a[i];
		for(int j=i+1;j<n;j++)
		{
			gc=__gcd(gc,a[j]);
			if(gc==1)
			{
				ans=min(ans,j-i-1);
				break;
			}
		}
	}
	cout<<cnt+ans<<'\n';
}