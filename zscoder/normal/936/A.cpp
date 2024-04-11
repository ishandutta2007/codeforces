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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;
ll k,d,t; 

ll maxon(ll x)
{
	ll tmp = k/d;
	ll cur = d*tmp;
	while(cur<k) cur+=d;
	//cur is the period
	//every cur mins, I have k mins of good time
	ll cur2 = cur*2LL; ll k2 = k*2LL;
	tmp = x/cur2;
	ll ans = tmp*k2 + min(k2, x%cur2);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>k>>d>>t;
	/*
	ll lo=0; ll hi=ll(1e18)*2LL+5;
	ll ans=0;
	while(lo<=hi)
	{
		ll mid=(lo+hi)>>1;
		ll rhs = 4LL*t - mid;
		ll lhs = maxon(mid);
		if(lhs>=rhs)
		{
			ans=mid;
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}
	cout<<fixed<<setprecision(10)<<ans*ld(0.5)<<'\n';
	*/
	ll cur = d*(k/d);
	while(cur<k) cur+=d;
	ll tmp = (2*t)/(cur+k);
	ld timetaken = ld(cur)*ld(tmp);
	ll rem = 2*t - tmp*(cur+k);
	if(2*k>=rem)
	{
		timetaken += ld(rem)/2;
	}
	else
	{
		rem-=2*k;
		timetaken += k;
		timetaken += rem;
	}
	cout<<fixed<<setprecision(10)<<timetaken<<'\n';
}