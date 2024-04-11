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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
	string s; cin>>s;
	int c[10]={};
	int sum=0;
	for(int i=0;i<s.length();i++)
	{
		c[s[i]-'0']++;
		sum+=s[i]-'0';
	}
	if(sum%3==0&&c[0]>0)
	{
		c[0]--;int ans=0;
		for(int i=0;i<10;i+=2)
		{
			if(c[i]>0) ans++;
		}
		if(ans) cout<<"red\n";
		else cout<<"cyan\n";
		return ;
	}
	cout<<"cyan\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}