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

int cnt[26];

void solve()
{
	string s; cin>>s;
	memset(cnt,0,sizeof(cnt));
	for(char c:s) cnt[c-'a']++;
	int m; cin>>m;
	vi vec(m);
	for(int i=0;i<m;i++) cin>>vec[i];
	int curchar = 25;
	string ans(m,'$');
	while(curchar>=0)
	{
		vi bad;
		for(int i=0;i<m;i++)
		{
			if(ans[i]!='$') continue;
			if(vec[i]==0) bad.pb(i);
		}
		if(cnt[curchar]<bad.size())
		{
			curchar--; continue;
		}
		for(int v:bad) ans[v]=curchar+'a';
		curchar--;
		for(int i=0;i<m;i++)
		{
			if(ans[i]!='$') continue;
			for(int v:bad)
			{
				vec[i]-=abs(v-i);
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