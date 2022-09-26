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
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll a[222222];

struct node
{
	ll mx;
	ll mn;
	ll sum;
};

node combine(node a, node b)
{
	node c;
	c.sum=a.sum+b.sum;
	c.mn = min(a.mn, a.sum+b.mn);
	c.mx = max(a.mx, a.sum+b.mx);
	return c;
}

node st[555555];

void combine(int id)
{
	st[id]=combine(st[id*2],st[id*2+1]);
}

void build(int id, int l, int r)
{
	if(r-l<2)
	{
		st[id].sum=a[l];
		st[id].mn=min(0LL,a[l]);
		st[id].mx=max(0LL,a[l]);
		return ;
	}
	int mid=(l+r)>>1;
	build(id*2,l,mid); build(id*2+1,mid,r);
	combine(id);
}

node query(int id, int l, int r, int ql, int qr)
{
	if(ql>=r||l>=qr)
	{
		node emp;
		emp.sum=emp.mn=emp.mx=0;
		return emp;
	}
	if(ql<=l&&r<=qr) return st[id];
	int mid=(l+r)>>1;
	return combine(query(id*2,l,mid,ql,qr),query(id*2+1,mid,r,ql,qr));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,q; cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x;
		a[i]=x-a[i];
	}
	build(1,0,n);
	for(int i=0;i<q;i++)
	{
		int l,r; cin>>l>>r;
		l--; r--;
		node tmp = query(1,0,n,l,r+1);
		if(tmp.sum!=0) 
		{
			cout<<-1<<'\n'; continue;
		}
		if(tmp.mn<0) 
		{
			cout<<-1<<'\n'; continue;
		}
		cout<<tmp.mx<<'\n';
	}	
}