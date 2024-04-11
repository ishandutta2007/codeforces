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

struct node
{
	int lazy;
	int mn;
	ll sum;
};

int a[222222];

node st[888888];

void combine(int id)
{
	st[id].mn=min(st[id*2].mn,st[id*2+1].mn);
	st[id].sum=st[id*2].sum+st[id*2+1].sum;
}

void push(int id, int l, int r)
{
	if(st[id].lazy!=0)
	{
		st[id].mn=st[id].lazy;
		st[id].sum=st[id].lazy*1LL*(r-l);
		if(r-l>=2)
		{
			st[id*2].lazy=st[id*2+1].lazy=st[id].lazy;
		}
		st[id].lazy=0;
	}
}

void build(int id, int l, int r)
{
	st[id].lazy=0;
	if(r-l<2)
	{
		st[id].mn=st[id].sum=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(id*2,l,mid); build(id*2+1,mid,r);
	combine(id);
}

void update(int id, int l, int r, int ql, int qr, int v)
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
	update(id*2,l,mid,ql,qr,v);
	update(id*2+1,mid,r,ql,qr,v);
	combine(id);
}

int queryleft(int id, int l, int r, int minbound, int v) //leftmost value < v
{
	push(id,l,r);
	//cerr<<"L = "<<l<<" R = "<<r<<" V = "<<v<<'\n';
	if(r-l<2)
	{
		if(st[id].mn<v&&l>=minbound) return l;
		return -1;
	}
	int mid=(l+r)>>1;
	//cerr<<"LEFT MIN = "<<l<<' '<<mid<<' '<<st[id*2].mn<<'\n';
	if(st[id*2].mn<v&&minbound<mid)
	{
		return queryleft(id*2,l,mid,minbound,v);
	}
	else
	{
		return queryleft(id*2+1,mid,r,minbound,v);
	}
}

int query(int id, int l, int r, int pos)
{
	push(id,l,r);
	if(pos>=r||pos<l) return int(1e9);
	if(r-l<2) 
	{
		return st[id].mn;
	}
	int mid=(l+r)>>1;
	if(pos<mid) return query(id*2,l,mid,pos);
	else return query(id*2+1,mid,r,pos);
}

ll sumq(int id, int l, int r, int ql, int qr)
{
	push(id,l,r);
	if(ql>=r||l>=qr) return 0;
	if(ql<=l&&r<=qr)
	{
		return st[id].sum;
	}
	int mid=(l+r)>>1;
	return sumq(id*2,l,mid,ql,qr)+sumq(id*2+1,mid,r,ql,qr);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,q; cin>>n>>q;
	for(int i=0;i<n;i++) cin>>a[i];
	build(1,0,n);
	for(int i=0;i<q;i++)
	{
		int u,v,w; cin>>u>>v>>w;
		v--;
		if(u==1)
		{
			int lmost = queryleft(1,0,n,0,w);
			if(lmost>-1&&lmost<=v)
			{
				update(1,0,n,lmost,v+1,w);
			}
		}
		else
		{
			int cur=v; //start from v
			int ans=0;
			while(cur!=-1&&cur<n&&w>0)
			{
				//cerr<<"CUR: "<<cur<<" ANS: "<<ans<<" W: "<<w<<'\n';
				int nxtpos = queryleft(1,0,n,cur,w+1);
				//cerr<<"NEXT POS = "<<nxtpos<<'\n';
				cur=nxtpos;
				if(cur==-1) break;
				//start from here, how far can i go?
				int curval = query(1,0,n,cur);
				int atleastthismany = min(w/curval, n-cur); //including this guy
				ans+=atleastthismany;
				w-=sumq(1,0,n,cur,cur+atleastthismany);
				assert(w>=0);
				cur+=atleastthismany;
			}
			cout<<ans<<'\n';
		}
	}
}