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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll a[100011];
vector<ll> powk;

ll absll(ll x)
{
	if(x<0) return -x;
	else return x;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ll k;
	cin>>n>>k;
//	n=100000;k=-2;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		//a[i]=2;
		a[i]+=a[i-1];
	}
	if(k==1)
	{
		powk.pb(1);
	}
	else if(k==-1)
	{
		powk.pb(-1); powk.pb(1);
	}
	else
	{
		ll cur = 1;
		for(int i = 0; absll(cur)<=ll(1e16); i++)
		{
			powk.pb(cur);
			cur*=k;
		}
	}
	ll ans=0;
	map<ll,ll> ma;

	ma[0]++;

	for(int j = 1; j <= n; j++)
	{
	    for(int i = 0; i < powk.size(); i++)
    	{
    		ll tmp = powk[i];
	    	ans+=ma[a[j]-tmp];
    	}
		ma[a[j]]++;
	}
	
	cout<<ans;
}