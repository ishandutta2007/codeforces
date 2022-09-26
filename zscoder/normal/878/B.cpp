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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll a[111111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	deque<ii> vec;
	ll n; ll k,m; cin>>n>>k>>m;
	ll TOTAL = n*m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	deque<int> res;
	ll ans = 0;
	stack<int> SS;
	stack<int> CN;
	
	for(int i=0;i<n;i++)
	{
		if(!SS.empty()&&SS.top()==a[i])
		{
			CN.top()++;
		}
		else
		{
			CN.push(1);
		}
		SS.push(a[i]);
		if(CN.top()>=k)
		{
			for(int j=0;j<k;j++)
			{
				SS.pop();
			}
			CN.top()-=k;
			if(CN.top()==0) CN.pop();
			ans+=k*m;
		}
	}
	
	while(!SS.empty())
	{
		res.push_front(SS.top());
		SS.pop();
	}
	
	int run=0;
	for(int i=0;i<res.size();i++)
	{
		if(i==0)
		{
			run++;
		}
		else
		{
			if(res[i]==res[i-1]) run++;
			else
			{
				vec.pb(mp(res[i-1],run));
				run=1;
			}
		}
	}
	if(!res.empty()) vec.pb(mp(res.back(),run));
	
	deque<int> P; deque<int> S;
	bool pos=1;
	while(!vec.empty())
	{
		if(vec.size()==1)
		{
			ll total = vec[0].se*m;
			ans += (total/k)*k;
			for(int j=0;j<total%k;j++) P.pb(vec[0].fi);
			break;
		}
		if(vec[0].fi!=vec.back().fi) 
		{
			pos=0;
			break;
		}
		ll tot = vec[0].se+vec.back().se;
		if(tot<k) 
		{
			pos=0;
			break;
		}
		if(tot>k)
		{
			ans+=(m-1)*k;
			pos=0;
			break;
		}
		else
		{
			ans+=(m-1)*k;
			for(int j=0;j<vec[0].se;j++) P.pb(vec[0].fi);
			for(int j=0;j<vec.back().se;j++) S.push_front(vec.back().fi);
			vec.pop_front();
			vec.pop_back();
		}
	}
	if(pos)
	{
		for(int i=0;i<S.size();i++)
		{
			P.pb(S[i]);
		}
		
		while(!CN.empty()) CN.pop();
		while(!SS.empty()) SS.pop();
		for(int i=0;i<P.size();i++)
		{
			if(!SS.empty()&&P[i]==SS.top())
			{
				CN.top()++;
			}
			else
			{
				CN.push(1);
			}
			SS.push(P[i]);
			if(CN.top()>=k)
			{
				for(int j=0;j<k;j++)
				{
					SS.pop();
				}
				ans+=k;
				CN.top()-=k;
				if(CN.top()==0) CN.pop();
			}
		}
	}
	ans = TOTAL - ans;
	cout<<ans<<'\n';
}