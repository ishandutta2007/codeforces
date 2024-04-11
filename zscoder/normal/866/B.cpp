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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

deque<ii> pos;
deque<ii> neg;

ll CEIL(ll x, ll y)
{
	return (x+y-1)/y;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ll k; cin>>n>>k;
	ll ans = 0;
	ll sum=0;
	ll cur=0;
	ll best=0;
	ll poscount = 0;
	for(int i=0;i<n;i++)
	{
		ll q,v1,v2;
		cin>>q>>v1>>v2;
		ans+=q*v1;
		sum+=q;
		if(v2>v1)
		{
			pos.pb(mp(v2-v1,q));
			cur+=q*(v2-v1);
			poscount+=q;
		}
		else
		{
			neg.pb(mp(v1-v2,q));
		}
	}
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end());
	if(CEIL(poscount,k)+CEIL(sum-poscount,k)==CEIL(sum,k))
	{
		best = max(best, cur);
	}
	ll tmpposcount = poscount;
	ll tmpcur=cur;
	for(int i=0;i<=k;i++)
	{
		if(pos.empty()) break;
		while(!pos.empty()&&pos.front().se<=0) pos.pop_front();
		cur-=pos[0].fi;
		poscount--;
		if(CEIL(poscount,k)+CEIL(sum-poscount,k)==CEIL(sum,k))
		{
			best = max(best, cur);
		}
		pos[0].se--;
		while(!pos.empty()&&pos.front().se<=0) pos.pop_front();
	}
	poscount=tmpposcount;
	cur=tmpcur;
	for(int i=0;i<=k;i++)
	{
		if(neg.empty()) break;
		while(!neg.empty()&&neg.front().se<=0) neg.pop_front();
		cur-=neg[0].fi;
		poscount++;
		if(CEIL(poscount,k)+CEIL(sum-poscount,k)==CEIL(sum,k))
		{
			best = max(best, cur);
		}
		neg[0].se--;
		while(!neg.empty()&&neg.front().se<=0) neg.pop_front();
	}
	cout<<ans+best<<'\n';
}