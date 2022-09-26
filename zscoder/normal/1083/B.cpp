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

const ll INF = ll(2e9);

ll add(ll a, ll b)
{
	a+=b;
	if(a>=INF) a=INF;
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,k; cin>>n>>k;
	string s,t; cin>>s>>t;
	ll diff = 0;
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]!=t[i])
		{
			if(s[i]=='a')
			{
				diff=add(diff,diff+1);
			}
			else
			{
				diff=add(diff,diff-1);
			}
		}
		else diff=add(diff,diff);
		ans += min(k, diff+1);
	}
	cout<<ans<<'\n';
}