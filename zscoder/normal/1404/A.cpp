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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[333333];

void solve()
{
	int n,k; cin>>n>>k;
	string s; cin>>s;
	for(int i=0;i<n;i++)
	{
		a[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='?') continue;
		if(a[i%k]!=-1&&a[i%k]!=s[i]-'0'){cout<<"NO\n"; return ;}
		a[i%k]=s[i]-'0';
	}
	int cnt[2]={0,0};
	for(int i=0;i<k;i++)
	{
		if(a[i]>=0) cnt[a[i]]++;
	}
	if(cnt[0]>k/2||cnt[1]>k/2) cout<<"NO\n";
	else cout<<"YES\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t; while(t--) solve();
}