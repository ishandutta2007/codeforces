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
typedef tree<pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll a[351111];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	multiset<ll> used,unused;
	const ll INF = int(1e9);
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ll m1,m2;
		m1=m2=INF;
		ll x=a[i];
		if(!used.empty()) m2=(*used.begin());
		if(!unused.empty()) m1=(*unused.begin());
		if(m1<m2)
		{
			if(x>m1)
			{
				ans+=x-m1;
				used.insert(x);
				unused.erase(unused.begin());
			}
			else unused.insert(x);
		}
		else
		{
			if(x>m2)
			{
				ans+=x-m2;
				used.erase(used.begin()); used.insert(x); unused.insert(m2);
			}
			else unused.insert(x);
		}
	}
	cout<<ans<<'\n';	
}