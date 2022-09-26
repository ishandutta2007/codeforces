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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;
typedef vector<ll>::iterator vit;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	string t = "heidi";
	int cur=0;
	for(int i=0;i<s.length();i++)
	{
		if(cur>=t.length()) break;
		if(s[i]==t[cur])
		{
			cur++;
		}
	}
	if(cur==int(t.length())) cout<<"YES\n";
	else cout<<"NO\n";
}