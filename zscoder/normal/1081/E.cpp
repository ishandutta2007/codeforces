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

ll a[222222];
vector<ll> divi[222222];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=2;i<=n;i+=2)
	{
		cin>>a[i];
	}
	for(int i=1;i<=201111;i++)
	{
		for(int j=i;j<=201111;j+=i)
		{
			divi[j].pb(i);
		}
	}
	a[0]=0;
	ll z = 0;
	for(int i=1;i<=n;i+=2)
	{
		ll minY=ll(1e18);
		for(ll d:divi[a[i+1]])
		{
			//Y+X=d
			//Y-X=a[i+1]/d
			if((d+(a[i+1]/d))%2==0)
			{
				ll Y = (d+(a[i+1]/d))/2;
				ll X = (d-(a[i+1]/d))/2;
				if(X>z&&Y>X)
				{
					minY=min(minY,Y);
				}
			}
		}
		if(minY>ll(1e17)){cout<<"No\n"; return 0;}
		a[i] = minY*minY - a[i+1] - z*z;
		z=minY;
	}
	cout<<"Yes\n";
	for(int i=1;i<=n;i++)
	{
		cout<<a[i];
		if(i+1<=n) cout<<' ';
	}
	cout<<'\n';
}