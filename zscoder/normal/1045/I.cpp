#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

map<int,int> a;
int B[1111111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		int bit=0;
		for(int j=0;j<s.length();j++)
		{
			bit^=(1<<(s[j]-'a'));
		}
		a[bit]++; B[i]=bit;
	}
	ll ans = 0;
	for(int i=0;i<n;i++)
	{
		ans--;
		ans += a[B[i]];
		for(int j=0;j<26;j++)
		{
			if(a.find(B[i]^(1<<j))!=a.end()) ans += a[B[i]^(1<<j)];
		}
	}
	cout<<ans/2<<'\n';
}