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

string getnxt(const string &s)
{
	int n=s.length();
	string ans(n,'0');
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='1') ans[i]='1';
		int cnt=0;
		if(i>0&&s[i-1]=='1') cnt++;
		if(i+1<s.length()&&s[i+1]=='1') cnt++;
		if(cnt==1) ans[i]='1';
	}
	return ans;
}

void solve()
{
	int n,m; cin>>n>>m;
	string s; cin>>s;
	for(int i=0;i<m;i++)
	{
		string t = getnxt(s);
		if(s==t){cout<<s<<'\n'; return ;}
		s=t;
	}
	cout<<s<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}