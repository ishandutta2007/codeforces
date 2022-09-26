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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

string a[11];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin>>s;
	for(int i=0;i<5;i++)
	{
		cin>>a[i];
	}
	bool pos=0;
	for(int i=0;i<5;i++)
	{
		if(a[i][0]==s[0]||a[i][1]==s[1]) pos=1;
	}
	if(pos) cout<<"YES\n";
	else cout<<"NO\n";
}