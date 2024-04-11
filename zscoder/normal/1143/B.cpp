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

int f(string s)
{
	int r=0;
	for(int i=0;i<s.length();i++)
	{
		r*=10; r+=s[i]-'0';
	}
	return r;
}

ll prod(int n)
{
	if(n==0) return 1;
	ll ans=1;
	while(n)
	{
		ans*=(n%10);
		n/=10;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	ll ans=prod(f(s));
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		string pref = s.substr(0,n-i);
		ll prefront = prod(f(pref)-1);
		for(int j=0;j<i;j++) prefront*=9;
		ans=max(ans,prefront);
	}
	cout<<ans<<'\n';
}