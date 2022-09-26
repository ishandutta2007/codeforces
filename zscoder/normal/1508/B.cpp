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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const ll INF = ll(2e18);

ll pow2[222222];

void solve()
{
	int n; ll k; cin>>n>>k;
	vi ans;
	if(k>pow2[n-1])
	{
		cout<<-1<<'\n'; return ;
	}
	int cur=0;
	while(cur<n)
	{
		int remsize = n-1-ans.size();
		int siz = 1;
		while(remsize>=1)
		{
			if(k<=pow2[remsize-1])
			{
				break; //use this size jiu dui le
			}
			k-=pow2[remsize-1]; remsize--; siz++;
		}
		for(int i=siz-1;i>=0;i--)
		{
			ans.pb(i+cur+1);
		}
		cur+=siz;
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i];
		if(i+1<ans.size()) cout<<' ';
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	pow2[0]=1;
	for(int i=1;i<=200011;i++)
	{
		pow2[i]=pow2[i-1]*2;
		if(pow2[i]>=INF) pow2[i]=INF;
	}
	int t; cin>>t;
	while(t--) solve();
}