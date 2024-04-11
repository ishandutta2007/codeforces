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

int x[100001];
int r[100001];
int f[100001];
vector<ii> interval[10100];

vi st[400001];
vector<ii> reduce;

void combine(int id)
{
	st[id].clear();
	st[id].resize(st[id*2].size()+st[id*2+1].size());
	merge(st[id*2].begin(),st[id*2].end(),st[id*2+1].begin(),st[id*2+1].end(),st[id].begin());
}

void build(int id, int l, int r, bool mode)
{
	if(r-l<2)
	{
		st[id].clear();
		if(mode == 0) st[id].pb(reduce[l].fi);
		else st[id].pb(reduce[l].se);
		return ;
	}
	int mid = (l+r)>>1;
	build(id*2,l,mid,mode);
	build(id*2+1,mid,r,mode);
	combine(id);
}

int query(int id, int l, int r, int ql, int qr, int x) //# in [ql, qr] that is < x
{
	if(ql>=r||l>=qr) return 0;
	if(ql<=l&&r<=qr)
	{
		int z = lower_bound(st[id].begin(),st[id].end(),x)-st[id].begin();
		return z;
	}
	int mid = (l+r)>>1;
	return (query(id*2,l,mid,ql,qr,x)+query(id*2+1,mid,r,ql,qr,x));
}

bool cmp(const pair<ii,bool> &a, const pair<ii,bool> &b)
{
	return ((a.fi.fi+a.fi.se)>>1 < (b.fi.fi+b.fi.se)>>1);
}

ll getans(vector<pair<ii,bool> > &vec)
{
	int n = vec.size();
	if(n==0) return 0;
	sort(vec.begin(),vec.end(),cmp);
	reduce.clear();
	pbds t;
	for(int i = 0; i < n; i++)
	{
		int L = vec[i].fi.fi; int R = vec[i].fi.se;
		int mid = (L+R)>>1;
		t.insert(mid);
	}
	for(int i = 0; i < n; i++)
	{
		int L = vec[i].fi.fi; int R = vec[i].fi.se;
		int mid = (L+R)>>1;
		int l = i - (t.order_of_key(mid)-t.order_of_key(L));
		int r = i + (t.order_of_key(R+1) - t.order_of_key(mid+1));
		//cerr<<L<<' '<<R<<' '<<mid<<' '<<l<<' '<<r<<'\n';
		reduce.pb(mp(l,r));
	}	
	vector<int> ans(n);
	for(int i = 0; i < n; i++)
	{
		ans[i]=reduce[i].se-reduce[i].fi;
	}
	build(1,0,n,0);
	for(int i = 0; i < n; i++)
	{
		if(!vec[i].se) continue;
		ans[i]-=(reduce[i].se-reduce[i].fi+1 - query(1,0,n,reduce[i].fi,reduce[i].se+1,i+1));
		//cerr<<query(1,0,n,reduce[i].fi,reduce[i].se+1,mid+1)<<'\n';
		//cerr<<ans[i]<<'\n';
	}
	build(1,0,n,1);
	ll res = 0;
	for(int i = 0; i < n; i++)
	{
		if(!vec[i].se) continue;
		ans[i] -= query(1,0,n,reduce[i].fi,reduce[i].se+1,i);
		res+=ans[i];
		//cerr<<ans[i]<<'\n';
	}	
	//cerr<<"RES : "<<res<<'\n';
	return res;
}

ll solve(int l, int r)
{
	if(interval[l].empty()) return 0;
	vector<pair<ii,bool> > intervals;
	for(int i = l; i <= r; i++)
	{
		for(int j = 0; j < interval[i].size(); j++)
		{
			if(i==l) intervals.pb(mp(interval[i][j],1));
			else intervals.pb(mp(interval[i][j],0));
		}
	}
	ll ans = getans(intervals);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin>>n>>k;
	for(int i = 0; i < n; i++)
	{
		cin>>x[i]>>r[i]>>f[i];
		interval[f[i]].pb(mp(x[i]-r[i],x[i]+r[i]));
	}
	ll ans = 0;
	for(int i = 1; i <= 10000; i++)
	{
		ans += solve(i,i+k);
	}
	for(int i = 1; i <= 10000; i++)
	{
		ans -= (solve(i,i)>>1);
	}
	cout<<ans;
}