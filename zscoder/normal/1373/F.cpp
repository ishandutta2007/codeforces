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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<ll> a,b;
int n; 
int go(int id)
{
	ll used=min(b[id],a[id]);
	ll otherside=a[id]-used;
	ll rem = b[id]-used;
	//cerr<<rem<<' '<<otherside<<'\n';
	for(int i=id+1;i<id+n;i++)
	{
		ll hp = a[i];
		hp-=min(hp,rem);
		//cerr<<hp<<' '<<b[i]<<'\n';
		if(b[i]<hp)
		{
			return i;
		}
		rem = b[i]-hp;
	}
	if(rem<otherside)
	{
		return id+n-1;
	}
	return -1;
}

void solve()
{
	scanf("%d",&n);
	a.clear(); b.clear();
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		a.pb(x);
	}
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		b.pb(x);
	}
	for(int i=0;i<n;i++) a.pb(a[i]);
	for(int i=0;i<n;i++) b.pb(b[i]);
	int st = 0;
	int sumdist = 0;
	while(1)
	{
		int nw = go(st);
		if(nw==-1)
		{
			cout<<"YES\n";
			return ;
		}
		//cerr<<"NW = "<<nw<<'\n';
		sumdist+=nw-st+1;
		if(sumdist>=4*n) break;
		st=nw%n;
	}
	cout<<"NO\n";
}

int main()
{
	int t; scanf("%d",&t);
	while(t--) solve();
}