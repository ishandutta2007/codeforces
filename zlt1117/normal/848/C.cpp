#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define pb push_back
#define rd (rand()<<16^rand())
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=7e5+5;
int n,m,a[maxn];
struct queries
{
	int t,typ,l,r,val;///t->time
	inline bool operator < (const queries &b)const
	{///< is the order of pre_x
		if(l==b.l)return typ<b.typ;///the modify first
		else return l>b.l;///the bigger first
	}
}q[maxn],temp[maxn];
int tot;
set<int>s[maxn];
int pre[maxn];
ll ans[maxn];
bool vis[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)a[i]=gi(),s[a[i]].insert(i);
	FOR(i,1,n)s[i].insert(0);
	FOR(i,1,n)
	{
		pre[i]=*(--s[a[i]].lower_bound(i));
		q[++tot]={0,1,pre[i],i,i-pre[i]};
	}
	FOR(i,1,m)
	{
		int typ=gi();
		if(typ==1)
		{
			int x=gi(),c=gi();
			q[++tot]={i,1,pre[x],x,pre[x]-x};
			auto it=s[a[x]].upper_bound(x);
			if(it!=s[a[x]].end())
			{
				int y=*it;
				q[++tot]={i,1,x,y,x-y};
				q[++tot]={i,1,pre[x],y,y-pre[x]};
				pre[y]=pre[x];
			}
			s[a[x]].erase(x);
			a[x]=c;
			it=s[a[x]].upper_bound(x);
			if(it!=s[a[x]].end())
			{
				int y=*it;
				q[++tot]={i,1,pre[y],y,pre[y]-y};
				q[++tot]={i,1,x,y,y-x};
				pre[y]=x;
			}
			s[a[x]].insert(x);
			pre[x]=*(--s[a[x]].lower_bound(x));
			q[++tot]={i,1,pre[x],x,x-pre[x]};
		}
		else
		{
			int l=gi(),r=gi();
			q[++tot]={i,2,l,r,0};
			vis[i]=1;
		}
	}
}
int c[maxn];
inline void update(int x,int v)
{
	while(x<=n)c[x]+=v,x+=x&-x;
}
inline int query(int x)
{
	int ret=0;
	while(x)ret+=c[x],x-=x&-x;
	return ret;
}
inline void cdq(int l,int r)
{
	if(l==r)return ;
	int mid=(l+r)>>1;
	cdq(l,mid);
	cdq(mid+1,r);
	int cnt=l-1;
	int pos1=l,pos2=mid+1;
	while(pos1<=mid&&pos2<=r)
	{
		if(q[pos1]<q[pos2])
		{
			if(q[pos1].typ==1)update(q[pos1].r,q[pos1].val);
			temp[++cnt]=q[pos1++];
		} 
		else
		{
			if(q[pos2].typ==2)ans[q[pos2].t]+=query(q[pos2].r)-query(q[pos2].l-1);
			temp[++cnt]=q[pos2++];
		}
	}
	while(pos1<=mid)
	{
		if(q[pos1].typ==1)update(q[pos1].r,q[pos1].val);
		temp[++cnt]=q[pos1++];
	}
	while(pos2<=r)
	{
		if(q[pos2].typ==2)ans[q[pos2].t]+=query(q[pos2].r)-query(q[pos2].l-1);
		temp[++cnt]=q[pos2++];
	}
	FOR(i,l,mid)
	{
		if(q[i].typ==1)update(q[i].r,-q[i].val);
	}
	FOR(i,l,r)q[i]=temp[i];
}
inline void solve()
{
	cdq(1,tot);
	FOR(i,1,m)if(vis[i])printf("%lld\n",ans[i]);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}
/*
3 1
1 1 1
2 1 3
*/