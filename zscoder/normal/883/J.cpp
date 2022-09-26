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

ll a[111111];
ll b[111111];
ll p[111111];

/*

struct Fenwick
{
	vector<ll> t;
    Fenwick(int n)
    {
        t.assign(n+1,0);
    }
    void reset(int n)
    {
		t.assign(n+1, 0);
	}
    void update(int p, ll v)
    {
        for (; p < (int)t.size(); p += (p&(-p))) t[p] += v;
    }
    ll query(int r) //finds [1, r] sum
    {                     
        ll sum = 0;
        for (; r; r -= (r&(-r))) sum += t[r];
        return sum;
    }
    ll query(int l, int r) //finds [l, r] sum
    {
		if(l == 0) return query(r);
		return query(r) - query(l-1);
	}
};

Fenwick fen(1);
*/
struct node
{
	ll val,lazy;
};

node st[411111];

void push(int id, int l, int r)
{
	if(st[id].lazy!=-1)
	{
		st[id].val = ll(r-l)*st[id].lazy;
		if(r-l>=2)
		{
			st[id*2].lazy = st[id*2+1].lazy = st[id].lazy;
		}
		st[id].lazy = -1;
	}
}

void update(int id, int l, int r, int ql, int qr, ll v)
{
	push(id,l,r);
	//cerr<<"UPDATE : "<<id<<' '<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<v<<' '<<st[id].val<<'\n';
	if(ql>=r||l>=qr) return ;
	if(ql<=l&&r<=qr)
	{
		st[id].lazy=v;
		push(id,l,r);
		//cerr<<"LAZY : "<<id<<' '<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<v<<' '<<st[id].val<<'\n';
		return ;
	}
	int mid=(l+r)>>1;
	update(id*2,l,mid,ql,qr,v);
	update(id*2+1,mid,r,ql,qr,v);
	st[id].val=st[id*2].val+st[id*2+1].val;
	//cerr<<"UPDATE FINAL : "<<id<<' '<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<v<<' '<<st[id].val<<'\n';
}

ll query(int id, int l, int r, int ql, int qr)
{
	push(id,l,r);
	//cerr<<id<<' '<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<st[id].val<<'\n';
	if(ql>=r||l>=qr) return 0;
	if(ql<=l&&r<=qr)
	{
		return st[id].val;
	}
	int mid=(l+r)>>1;
	return query(id*2,l,mid,ql,qr)+query(id*2+1,mid,r,ql,qr);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=0;i<411111;i++) st[i].val=0,st[i].lazy=-1;
	int n,m; cin>>n>>m;
	vector<ii> vv;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		vv.pb(mp(a[i],i));
		update(1,1,n+1,i,i+1,a[i]);
	}
	vector<ii> vec;
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
		vec.pb(mp(b[i],i));
	}
	sort(vec.rbegin(),vec.rend());
	sort(vv.rbegin(),vv.rend());
	int ptr=0;
	int idx=-1;
	for(int i=0;i<m;i++)
	{
		while(ptr<vv.size()&&vec[i].fi<=vv[ptr].fi)
		{
			idx=max(idx,vv[ptr].se);
			ptr++;
		}
		b[vec[i].se] = idx;
		//cerr<<i<<' '<<vec[i].fi<<' '<<vec[i].se<<' '<<ptr<<' '<<idx<<'\n';
	}
	vector<ii> buildings;
	for(int i=0;i<m;i++)
	{
		cin>>p[i];
		buildings.pb(mp(p[i],b[i]));
		////cerr<<"ID : "<<i<<' '<<p[i]<<' '<<b[i]<<'\n';
	}
	sort(buildings.begin(),buildings.end());
	int cnt=0;
	for(int i=0;i<m;i++)
	{
		int id=buildings[i].se;
		if(id<0) continue;
		ll price = buildings[i].fi;
		ll money = query(1,1,n+1,1,id+1);
		if(money>=price)
		{
			cnt++;
			ll cur = query(1,1,n+1,id,id+1);
			////cerr<<cur<<' '<<price<<' '<<cur-price<<'\n';
			update(1,1,n+1,id,id+1,cur-price);
			ll moneyleft = money - price;
			if(cur-price<0)
			{
				int lo = 1; int hi = id - 1;
				int ans=0;
				while(lo<=hi)
				{
					int mid=(lo+hi)>>1;
					ll tmp = query(1,1,n+1,1,mid+1);
					if(tmp<=moneyleft)
					{
						ans=mid;
						lo=mid+1;
					}
					else
					{
						hi=mid-1;
					}
				}
				//cerr<<i<<' '<<id<<' '<<money<<' '<<price<<' '<<moneyleft<<'\n';
				ll curr = query(1,1,n+1,1,ans+1);
				moneyleft -= curr;
				//cerr<<moneyleft<<'\n';
				//ll Q = query(1,1,n+1,ans+1,ans+2);
				update(1,1,n+1,ans+1,ans+2,moneyleft);
				update(1,1,n+1,ans+2,id+1,0);
				//cerr<<ans+1<<' '<<ans+2<<' '<<moneyleft<<'\n';
				//cerr<<ans+2<<' '<<id+1<<' '<<0<<'\n';
			}
		}
	}
	cout<<cnt<<'\n';
}