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

void solve()
{
	int n; cin>>n;
	string s;
	cin>>s;
	string t;
	int l=-1;
	int r=n;
	while(l+1<n&&s[l+1]=='0') l++;
	while(r-1>=0&&s[r-1]=='1') r--;
	//s[l] is max 0, s[r] is min 1
	if(l==n-1||r==0)
	{
		cout<<s<<'\n'; return ;
	}
	if(r==l+1)
	{
		cout<<s<<'\n'; return ;
	}
	for(int i=0;i<=l;i++) cout<<0;
	cout<<0;
	for(int i=r;i<n;i++) cout<<1;
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}