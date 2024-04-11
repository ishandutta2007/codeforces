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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int h[311111];
ll a[311111];
ll dp[311111];
const ll INF = ll(1e18);
struct node
{
	ll lazy,mx,basemx;
	node(){lazy=INF; mx=-INF; basemx=-INF;}
};

node st[311111*4];

void combine(int id)
{
	st[id].mx=max(st[id*2].mx,st[id*2+1].mx);
	st[id].basemx=max(st[id*2].basemx,st[id*2+1].basemx);
}

void push(int id, int l, int r)
{
	if(st[id].lazy!=INF)
	{
		st[id].mx=st[id].basemx+st[id].lazy;
		if(r-l>=2)
		{
			st[id*2].lazy=st[id*2+1].lazy=st[id].lazy;
		}
		st[id].lazy=INF;
	}
}

void setrange(int id, int l, int r, int ql, int qr, ll v)
{
	push(id,l,r);
	if(ql>=r||l>=qr) return ;
	if(ql<=l&&r<=qr)
	{
		st[id].lazy=v;
		push(id,l,r);
		return ;
	}
	int mid=(l+r)>>1;
	setrange(id*2,l,mid,ql,qr,v); setrange(id*2+1,mid,r,ql,qr,v);
	combine(id);
}
void updatebase(int id, int l, int r, int pos, ll v, ll v2)
{
	push(id,l,r);
	if(pos>=r||pos<l) return ;
	if(r-l<2)
	{
		st[id].basemx=v;
		st[id].mx=v+v2;
		return ;
	}
	int mid=(l+r)>>1;
	updatebase(id*2,l,mid,pos,v,v2); updatebase(id*2+1,mid,r,pos,v,v2);
	combine(id);
}

ll query(int id, int l, int r, int ql, int qr)
{
	push(id,l,r);
	if(ql>=r||l>=qr) return -INF;
	if(ql<=l&&r<=qr)
	{
		return st[id].mx;
	}
	int mid=(l+r)>>1;
	return max(query(id*2,l,mid,ql,qr),query(id*2+1,mid,r,ql,qr));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>h[i]; h[i]--;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<ii> monotone;
	for(int i=0;i<n;i++)
	{
		while(!monotone.empty()&&monotone.back().fi>h[i]) monotone.pop_back();
		int l=-1;
		if(!monotone.empty()) l=monotone.back().se;
		//update from [l,i)
		monotone.pb({h[i],i});
		ll ans = a[monotone.front().se];
		//cerr<<"SET RANGE: "<<l<<' '<<i-1<<'\n';
		//can we make it larger
		setrange(1,0,n,l,i,a[i]);
		dp[i] = max(ans, query(1,0,n,0,i));
		//cerr<<i<<' '<<dp[i]<<'\n';
		updatebase(1,0,n,i,dp[i],0); //next guy will set it anyway
	}
	cout<<dp[n-1]<<'\n';
}