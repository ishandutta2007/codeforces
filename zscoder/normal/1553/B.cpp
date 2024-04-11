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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

void solve()
{
	string s,t; cin>>s>>t;
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;i+j<s.length();j++)
		{
			//[i,i+j] then [i+j-1 -> i+j-k]
			string cur = s.substr(i,j+1); //[i,i+j];
			int pos=i+j;
			int rem = t.length()-cur.length();
			for(int k=0;k<rem;k++)
			{
				pos--;
				if(pos<0) break;
				cur.pb(s[pos]);
			}
			if(cur==t){cout<<"YES\n"; return ;}
		}
	}
	cout<<"NO\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}