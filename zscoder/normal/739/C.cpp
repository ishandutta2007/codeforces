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

int a[300001];

struct node
{
	int adp;
	int ads;
	int ans;
	int as;
	int dp;
	ll lef, ri;
	//ll shift;
	ll lazy;
};

node st[1211111];

void amax(int &a, int b)
{
	a = max(a,b);
}

void push(int id, int l, int r)
{
	if(st[id].lazy > 0)
	{
		//st[id].shift += st[id].lazy;
		st[id].lef += st[id].lazy;
		st[id].ri += st[id].lazy;
		if(r-l>=2)
		{
			st[2*id].lazy+=st[id].lazy;
			st[2*id+1].lazy+=st[id].lazy;
		}
		st[id].lazy = 0;
	}
}

void combine(int id, int rl, int rr)
{
	int x = id*2; int y = (x^1);
	//push(x,st[x].l,st[x].r+1);
	//push(y,st[y].l,st[y].r+1);
	//ll L = a[st[x].r] + st[x].shift;
	//ll R = a[st[y].l] + st[y].shift;
	ll L = st[x].ri+st[x].lazy; ll R = st[y].lef+st[y].lazy;
	//cerr<<L<<' '<<R<<'\n';
	st[id].ans = max(st[x].ans, st[y].ans);
	st[id].lef = st[x].lef;
	st[id].ri = st[y].ri;
	if(L > R)
	{
		//amax(st[id].ans, st[x].as + st[y].adp);
		amax(st[id].ans, st[x].ads + st[y].dp);
	}	
	if(L < R)
	{
		amax(st[id].ans, st[x].as + st[y].adp);
	}
	st[id].as = st[y].as;
	if(st[y].as == rr) //Ascend suffix 4ever
	{
		if(L < R)
		{
			st[id].as = st[y].as + st[x].as;
		}
	}
	st[id].dp = st[x].dp;
	if(st[x].dp == rl) //Descend prefix 4ever
	{
		if(L > R)
		{
			st[id].dp = st[y].dp + st[x].dp;
		}
	}
	st[id].adp = st[x].adp;
	if(st[x].adp == rl)
	{
		if(L < R)
		{
			if(st[x].as == st[x].adp)
			{
				st[id].adp = st[x].adp + st[y].adp;
			}
		}
		else if(L > R)
		{
			st[id].adp = st[x].adp + st[y].dp;
		}
	}
	st[id].ads = st[y].ads;
	if(st[y].ads == rr)
	{
		if(L > R)
		{
			if(st[y].dp == st[y].ads)
			{
				st[id].ads = st[x].ads + st[y].ads;
			}
		}
		else if(L < R)
		{
			st[id].ads = st[x].as + st[y].ads;
		}
	}
	amax(st[id].adp, st[id].dp);
	amax(st[id].ads, st[id].as);
	//cerr<<"NODE : "<<id<<' '<<st[id].l<<' '<<st[id].r<<' '<<st[id].ans<<' '<<st[id].adp<<' '<<st[id].ads<<' '<<st[id].dp<<' '<<st[id].as<<'\n';
}

void build(int id, int l, int r)
{
	if(r - l < 2)
	{	//	l + 1 == r
		st[id].adp = 1;
		st[id].ads = 1;
		st[id].as = 1;
		st[id].ans = 1;
		st[id].dp = 1;
		st[id].lef = st[id].ri = a[l];
		st[id].lazy = 0;
		//st[id].shift = 0;
		return ;
	}
	int mid = (l+r)/2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	combine(id,mid-l,r-mid);
}

void update(int id, int l, int r, int ql, int qr, ll v)
{
	push(id,l,r);
	if(l >= qr || ql >= r)	return ;
	if(ql <= l && r <= qr)
	{
		st[id].lazy += v;
		push(id,l,r);
		return ;
	}
	int mid = (l+r)/2;
	update(id*2,l,mid,ql,qr,v);
	update(id*2+1,mid,r,ql,qr,v);
	combine(id,mid-l,r-mid);
}

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	//emp.l=-1;
	int n; scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", a+i);
	build(1,0,n);
	int q;scanf("%d", &q);
	while(q--)
	{
		int l, r;
		int w;
		scanf("%d %d %d", &l,&r,&w);
		l--; r--;
		update(1,0,n,l,r+1,w);
		printf("%d\n",st[1].ans);
	}
}