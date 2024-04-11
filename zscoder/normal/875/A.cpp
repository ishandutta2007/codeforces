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

ll sod(ll x)
{
	if(x==0) return 0;
	ll ans=0;
	while(x)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);	
	ll n; cin>>n;
	vector<int> vec;
	for(ll i=0;i<=10000;i++)
	{
		if(n>=i)
		{
			if(sod(n-i)==i)
			{
				vec.pb(n-i);
			}
		}
	}
	sort(vec.begin(),vec.end());
	cout<<vec.size()<<'\n';
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i];
		if(i+1<vec.size()) cout<<' ';
	}
	if(!vec.empty()) cout<<'\n';
}