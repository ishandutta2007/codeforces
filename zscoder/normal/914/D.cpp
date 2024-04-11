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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int a[501111];
int st[2212222];

void combine(int id)
{
	st[id]=__gcd(st[id*2],st[id*2+1]);
}

void build(int id, int l, int r)
{	
	if(r-l<2)
	{
		st[id]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(id*2,l,mid); build(id*2+1,mid,r);
	combine(id);
}

void update(int id, int l, int r, int pos, int v)
{
	if(pos>=r||pos<l) return ;
	if(r-l<2)
	{
		st[id]=v;
		return ;
	}
	int mid=(l+r)>>1;
	update(id*2,l,mid,pos,v); update(id*2+1,mid,r,pos,v);
	combine(id);
}

int query(int id, int l, int r, int ql, int qr)
{
	if(ql>=r||l>=qr) return 0;
	if(ql<=l&&r<=qr)
	{
		return st[id];
	}
	int mid=(l+r)>>1;
	return __gcd(query(id*2,l,mid,ql,qr), query(id*2+1,mid,r,ql,qr));
}

int query2(int id, int l, int r, int ql, int gd)
{
	if(r-l<2)
	{
		if(st[id]%gd==0) return l;
		else return -1;
	}
	int mid=(l+r)>>1;
	//[l,mid), [mid,r)
	if(ql>=mid)
	{
		return query2(id*2+1,mid,r,ql,gd);
	}
	else if(ql<=l)
	{
		if(st[id*2]%gd==0) return max(mid-1, query2(id*2+1,mid,r,ql,gd));
		else return query2(id*2,l,mid,ql,gd);
	}
	else //ql is in (l, mid)
	{
		int LB = query2(id*2,l,mid,ql,gd);
		if(LB==mid-1)
		{
			return max(LB, query2(id*2+1,mid,r,ql,gd));
		}
		else
		{
			return LB;
		}
	}
}

int main()
{
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++) 
	{
		scanf("%d", a+i);
	}
	build(1,0,n);
	//cerr<<query(1,0,n,0,1)<<endl;
	int q; scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int ty,l,r,x;
		scanf("%d %d %d",&ty,&l,&r);
		if(ty==1)
		{
			scanf("%d",&x);
			l--; r--;
			//[l,r] x
			/*
			int lo = l; int hi = r + 1; int ans = l;
			while(lo<=hi)
			{
				int mid=(lo+hi)>>1;
				int gd = query(1,0,n,l,mid);
				//cerr<<mid<<' '<<l<<' '<<mid-1<<' '<<gd<<'\n';
				if(gd%x==0)
				{
					ans=mid; lo=mid+1;
				}
				else
				{
					hi=mid-1;
				}
			}
			ans--;
			*/
			int ans = max(l - 1, query2(1,0,n,l,x));
			//[lo, ans] works
			int gd2 = query(1,0,n,ans+2,r+1);
			//cerr<<ans<<' '<<gd2<<'\n';
			if(gd2%x==0)
			{
				puts("YES");
			}
			else
			{
				puts("NO");
			}
		}
		else
		{
			l--;
			update(1,0,n,l,r);
		}
	}
}