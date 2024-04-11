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
typedef bitset<1500> b100;

ll a[555];
ll b[555];
int n,k; 

bool possible(int i, int r)
{
	ll R = a[i]; ll B = b[i];
	int rsum = (R+B)%k;
	if(rsum<0) rsum+=k;
	rsum-=r;
	while(rsum<0) rsum+=k;
	//cerr<<r<<' '<<R<<' '<<rsum<<' '<<B<<'\n';
	return (R>=r&&B>=rsum);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>k;
	ll S=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		S+=a[i]+b[i];
	}
	b100 dp; dp.reset();
	dp.set(0,1);
	for(int i=0;i<n;i++)
	{
		b100 nw; nw.reset();
		for(int j=0;j<k;j++)
		{
			if(possible(i,j))
			{
				//cerr<<"POSSIBLE "<<i<<' '<<j<<'\n';
				nw|=(dp<<j);
			}
		}
		for(int j=k;j<1500;j++)
		{
			if(nw[j]) nw.set(j%k,1);
		}
		dp=nw;
	}
	ll minr=ll(1e9);
	ll Smod = S%k;
	if(Smod<0) Smod+=k;
	for(int i=0;i<k;i++)
	{
		if(dp[i])
		{
			minr=min(minr,i+(Smod-i+100*k)%k);
		}
	}
	//cerr<<S<<' '<<minr<<'\n';
	assert((S-minr)%k==0);
	cout<<(S-minr)/k<<'\n';
}