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
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll cnt[1111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,m; cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cnt[i] = n/m;
		if(i<n%m) cnt[i]++;
	}
	for(int i=m;i>=1;i--)
	{
		cnt[i]=cnt[i-1];
	}
	cnt[0]=cnt[m];
	ll ans = 0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if((i*i+j*j)%m==0) 
			{
				ans+=cnt[i]*cnt[j];
			}
		}
	}
	cout<<ans<<'\n';
}