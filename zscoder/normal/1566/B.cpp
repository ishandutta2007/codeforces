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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

void solve()
{
	string s; cin>>s;
	bool ex=0;
	for(char c:s)
	{
		if(c=='0') ex=1;
	}
	if(!ex){cout<<0<<'\n'; return ;}
	//check if answer is 1
	//if exist 0 1 0 as a subsequence, lose
	int lefmost = int(1e9);
	int rimost = -1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='0')
		{
			lefmost=min(lefmost,i);
			rimost=max(rimost,i);
		}
	}
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='1')
		{
			if(lefmost<i&&i<rimost)
			{
				cout<<2<<'\n'; return ;
			}
		}
	}
	cout<<1<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}