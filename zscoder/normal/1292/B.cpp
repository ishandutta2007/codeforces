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

const ll INF = ll(1e18);
ll mult(ll a, ll b)
{
	if(a==0||b==0) return 0;
	if(a>INF/b) return INF;
	return a*b;
}

ll add(ll a, ll b)
{
	a+=b; 
	if(a>=INF) a=INF;
	return a;
}

vector<ii> vec;

ll d(ii a, ii b)
{
	return abs(a.fi-b.fi)+abs(a.se-b.se);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll x[2],a[2],b[2];
	cin>>x[0]>>x[1]>>a[0]>>a[1]>>b[0]>>b[1];
	ll X,Y,T; cin>>X>>Y>>T;
	while(x[0]<INF&&x[1]<INF)
	{
		vec.pb({x[0],x[1]});
		x[0]=mult(x[0],a[0]); x[0]+=b[0];
		x[1]=mult(x[1],a[1]); x[1]+=b[1];
	}
	int n=vec.size();
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ll curt=T;
		curt-=d({X,Y},vec[i]);
		if(curt>=0)
		{
			int cnt=1;
			for(int l=0;l<=i;l++)
			{
				for(int r=i;r<n;r++)
				{
					ll addD = min(add(d(vec[i],vec[r]),d(vec[l],vec[r])),add(d(vec[i],vec[l]),d(vec[l],vec[r])));
					if(addD<=curt)
					{
						ans=max(ans,r-l+1);
					}
				}
			}
		}
	}
	cout<<ans<<'\n';
}