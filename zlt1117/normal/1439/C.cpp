#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
#define sz(x) (int)(x.size())
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2e5+5;
int n,q,a[maxn],t,x,y;
inline void init()
{

}
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=8e5+5;
	ll sum[maxn],tag[maxn],minv[maxn];
	inline void pushup(int u)
	{
		sum[u]=sum[ls]+sum[rs];
		minv[u]=min(minv[ls],minv[rs]);
	}
	inline void pushdown(int u,int l,int r)
	{
		if(tag[u])
		{
			int mid=(l+r)>>1;
			sum[ls]=tag[u]*(mid-l+1);
			sum[rs]=tag[u]*(r-mid);
			tag[ls]=tag[rs]=tag[u];
			minv[ls]=minv[rs]=tag[u];
			tag[u]=0;
		}
	}
	inline void build(int u,int l,int r)
	{
		if(l==r)return minv[u]=sum[u]=a[l],void();
		else
		{
			int mid=(l+r)>>1;
			build(ls,l,mid);
			build(rs,mid+1,r);
			pushup(u);
		}
	}
	inline void update(int u,int l,int r,int x,int y,int v)
	{
		if(x<=l&&y>=r)
		{
			sum[u]=1LL*(r-l+1)*v;
			minv[u]=v;
			tag[u]=v;
			return ;
		}
		pushdown(u,l,r);
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,y,v);
		if(y>mid)update(rs,mid+1,r,x,y,v);
		pushup(u);
	}
	inline ll query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return sum[u];
		pushdown(u,l,r);
		ll ret=0;
		int mid=(l+r)>>1;
		if(x<=mid)ret+=query(ls,l,mid,x,y);
		if(y>mid)ret+=query(rs,mid+1,r,x,y);
		return ret;
	}
	inline int query2(int u,int l,int r,int x,int &val)
	{
		if(l==r)
		{
			if(val<sum[u])return -1;
			val-=sum[u];
			return l;
		}
		else
		{
			pushdown(u,l,r);
			int mid=(l+r)>>1;
			if(x<=mid)
			{
				int val1=query2(ls,l,mid,x,val);
				if(val1==mid)
				{
					if(val>=sum[rs]){val-=sum[rs];return r;}
					else 
					{
						int val2=query2(rs,mid+1,r,x,val);
						if(val2==-1)return mid;
						else return val2;
					} 
				}
				else return val1;
			}
			else
			{
				return query2(rs,mid+1,r,x,val);
			}
		}
	}
	inline int query3(int u,int l,int r,int val)
	{
		if(l==r)
		{
			if(val>=minv[u])return l;
			else return -1;
		}
		pushdown(u,l,r);
		int mid=(l+r)>>1;
		if(minv[ls]<=val)return query3(ls,l,mid,val);
		else return query3(rs,mid+1,r,val);
	}
}tree;
inline void input()
{
	n=gi(),q=gi();
	FOR(i,1,n)a[i]=gi();
	tree.build(1,1,n);
}
inline void update(int x,int y)
{
	int ans=tree.query3(1,1,n,y);
	if(ans>x||ans==-1)return ;
	tree.update(1,1,n,ans,x,y);
}
inline int erfen(int x,int y)
{
	int ans=tree.query3(1,1,n,y);
	if(ans==-1)return n+1;
	else return max(x,ans);
}
inline void d()
{
	FOR(i,1,n)
	a[i]=tree.query(1,1,n,i,i);
}
inline void solve()
{
	int counter=0;
	FOR(i,1,q)
	{
		t=gi(),x=gi(),y=gi();
//	 	d();
		if(t==1)
		{
			if(tree.query(1,1,n,x,x)>=y)continue;
			else update(x,y);
		}
		else
		{
//			++counter;
//			if(counter==11)
//			{
//				cerr<<1<<endl;
//				d();
//			}
			int now=x;
			int cnt=0;
			while(1)
			{
				now=erfen(now,y);
				if(now==n+1)break;
				else 
				{
					int pos=tree.query2(1,1,n,now,y);
					cnt+=pos-now+1;
					//cerr<<tree.query(1,1,n,now,pos)<<endl;
					now=pos+1;
				}
			}
			printf("%d\n",cnt);
		}
	}
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	init();
	input();
	solve();
	return 0;
}