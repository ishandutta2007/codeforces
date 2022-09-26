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

void solve()
{
	int n,x; cin>>n>>x;
	vi a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	int s=0;
	for(int x:a) s+=x;
	if(s==x){cout<<"NO\n"; return ;}
	int cur=0;
	for(int i=0;i<n;i++)
	{
		cur+=a[i];
		if(cur==x)
		{
			swap(a[i],a[i+1]);
			cout<<"YES\n";
			for(int i=0;i<n;i++)
			{
				cout<<a[i];
				if(i+1<n) cout<<' ';
			}
			cout<<'\n'; return ;
		}
	}
	cout<<"YES\n";
			for(int i=0;i<n;i++)
			{
				cout<<a[i];
				if(i+1<n) cout<<' ';
			}
			cout<<'\n'; return ;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}