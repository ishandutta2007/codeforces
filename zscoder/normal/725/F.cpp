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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int a1, b1, a2, b2;
	ll fa = 0; ll fb = 0;
	vector<ll> vec;
	for(int i = 0; i < n; i++)
	{
		cin>>a1>>b1>>a2>>b2;
		if(a1<=b2&&b1<=a2) continue;
		if(a1+b1<=a2+b2)
		{
			if(a1>b2)
			{
				fa+=a1;
				fb+=b2;
			}
			else
			{
				fb+=b1;
				fa+=a2;
			}
		}
		else
		{
			fa += (a1+a2);
			vec.pb(a1+b1);
			vec.pb(a2+b2);
		}
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	for(int i = 0; i < vec.size(); i++)
	{
		if(i&1)
		{
			fb += vec[i];
		}
	}
	cout<<fa-fb;
}