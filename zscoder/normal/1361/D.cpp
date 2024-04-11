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

ii gradient(ii pt)
{
	int gd=__gcd(abs(pt.fi),abs(pt.se));
	if(pt.fi==0) gd=abs(pt.se);
	if(pt.se==0) gd=abs(pt.fi);
	pt.fi/=gd; pt.se/=gd;
	return pt;
}

vector<ld> vec[511111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k; cin>>n>>k;
	map<ii,int> ma; ld sum=0;
	for(int i=0;i<n;i++)
	{
		ll x,y; cin>>x>>y;
		if(x==0&&y==0) continue;
		ii grad = gradient({x,y});
		if(!ma.count(grad))
		{
			int siz=ma.size();
			ma[grad]=siz;
		}
		int id=ma[grad];
		vec[id].pb(sqrtl(ld(x*x+y*y)));
	}
	ld ans=0;
	vector<ld> V;
	for(int i=0;i<ma.size();i++)
	{
		sort(vec[i].begin(),vec[i].end());
		int cur=k-1;
		int r=int(vec[i].size())-1; int l=0;
		while(r>=l&&cur>=0)
		{
			V.pb(vec[i][r]*ld(cur));
			cur-=2;
			r--;
		}
		ld pref=0;
		while(l<=r)
		{
			V.pb(vec[i][l]*ld(cur)-pref*ld(2));
			pref+=vec[i][l];
			l++;
		}
	}
	ld res=0;
	sort(V.rbegin(),V.rend());
	for(int i=0;i<k-1;i++)
	{
		res+=V[i];
	}
	if(V.size()>=k) res=max(res,res+V[k-1]);
	ans=res;
	cout<<fixed<<setprecision(13)<<ans<<'\n';
}