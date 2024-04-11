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

int ans[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	vi a(m);
	for(int i=0;i<m;i++) cin>>a[i];
	int cur=0;
	for(int i=m-1;i>=0;i--)
	{
		int len = a[i];
		int maxl=min(n-len+1,cur+1);
		maxl=min(maxl,n-i-len+1);
		if(maxl<=0){cout<<-1<<'\n'; return 0;}
		ans[i]=maxl;
		cur=maxl+len-1;
	}
	if(cur>=n)
	{
		for(int i=0;i<m;i++)
		{
			cout<<ans[i];
			if(i+1<m) cout<<' ';
		}
		cout<<'\n';
	}
	else cout<<-1<<'\n';
}