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

ll c[200001];
int d[200001];
const ll INF = ll(1e12);

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>c[i]>>d[i];
	}
	ll l = -INF; ll r = INF;
	ll cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(d[i]==1)
		{
			l=max(l,1900LL-cnt);
		}
		else
		{
			r=min(r,1899LL-cnt);
		}
		cnt+=c[i];
	}
	if(l>r)
	{
		cout<<"Impossible";
		return 0;
	}
	else if(r>=INF)
	{
		cout<<"Infinity";
		return 0;
	}
	else
	{
		cout<<r+cnt;
		return 0;
	}
}