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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int cnt[222222];

void solve()
{
	int n,l,r; cin>>n>>l>>r;
	for(int i=0;i<=n;i++) cnt[i]=0;
	for(int i=0;i<l;i++)
	{
		int x; cin>>x; x--;
		cnt[x]++;
	}	
	for(int i=0;i<r;i++)
	{
		int x; cin>>x; x--;
		cnt[x]--;
	}
	int tot = 0;
	int abstot = 0;
	for(int i=0;i<=n;i++)
	{
		abstot+=abs(cnt[i]);
		tot+=cnt[i];
	}
	assert(abstot%2==0);
	int ans = abstot/2;
	if(tot>0)
	{
		//choose tot from positive ones
		int mxchoose = 0;
		for(int i=0;i<=n;i++)
		{
			if(cnt[i]>0)
			{
				mxchoose+=cnt[i]/2;
			}
		}
		assert(tot%2==0);
		ans+=max(0,tot/2-mxchoose);
	}
	else
	{
		int mxchoose = 0;
		for(int i=0;i<=n;i++)
		{
			if(cnt[i]<0)
			{
				mxchoose+=abs(cnt[i])/2;
			}
		}
		assert(abs(tot)%2==0);
		ans+=max(0,abs(tot)/2-mxchoose);
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}