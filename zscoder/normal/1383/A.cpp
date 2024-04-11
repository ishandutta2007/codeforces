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

int a[26][26];
int dp[26][26];
vi pre[26];
void solve()
{
	int n; cin>>n;
	string s,t; cin>>s>>t;
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	for(int i=0;i<26;i++) pre[i].clear();
	for(int i=0;i<n;i++)
	{
		if(s[i]>t[i])
		{
			cout<<-1<<'\n'; return ;
		}
		if(s[i]!=t[i])
		{
			a[s[i]-'a'][t[i]-'a']=1;
			pre[t[i]-'a'].pb(s[i]-'a');
		}
	}
	int ans=0;
	for(int i=0;i<21;i++)
	{
		int nxt=22;
		for(int j=i+1;j<21;j++)
		{
			if(a[i][j])
			{
				ans++; nxt=j; break;
			}
		}
		for(int j=nxt+1;j<21;j++)
		{
			if(a[i][j])
			{
				a[nxt][j]=1;
			}
		}
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}