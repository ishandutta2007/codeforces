#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
namespace sgt
{
	int rt1[100010];
	int rt2[100010];
	struct node
	{
		int lc,rc;
		int s;
		node()
		{
			lc=rc=s=0;
		}
	};
	node a[10000010];
	int cnt=0;
	int insert(int p1,int x,int l,int r)
	{
		int p=++cnt;
		a[p]=a[p1];
		a[p].s++;
		if(l==r)
			return p;
		int mid=(l+r)>>1;
		if(x<=mid)
			a[p].lc=insert(a[p].lc,x,l,mid);
		else
			a[p].rc=insert(a[p].rc,x,mid+1,r);
		return p;
	}
	int suf(int p1,int p2,int p3,int p4,int x,int l,int r)//p1+p3-p2-p4
	{
		int s=a[p1].s+a[p3].s-a[p4].s-a[p2].s;
		if(!s)
			return 0x3fffffff;
		if(l==r)
			return l;
		int mid=(l+r)>>1;
		int ls=a[a[p1].lc].s+a[a[p3].lc].s-a[a[p4].lc].s-a[a[p2].lc].s;
		if(x<=mid&&ls)
		{
			int lans=suf(a[p1].lc,a[p2].lc,a[p3].lc,a[p4].lc,x,l,mid);
			if(lans!=0x3fffffff)
				return lans;
		}
		return suf(a[p1].rc,a[p2].rc,a[p3].rc,a[p4].rc,x,mid+1,r);
	}
	int pre(int p1,int p2,int p3,int p4,int x,int l,int r)
	{
		int s=a[p1].s+a[p3].s-a[p4].s-a[p2].s;
		if(!s)
			return 0;
		if(l==r)
			return l;
		int mid=(l+r)>>1;
		int rs=a[a[p1].rc].s+a[a[p3].rc].s-a[a[p4].rc].s-a[a[p2].rc].s;
		if(x>mid&&rs)
		{
			int rans=pre(a[p1].rc,a[p2].rc,a[p3].rc,a[p4].rc,x,mid+1,r);
			if(rans)
				return rans;
		}
		return pre(a[p1].lc,a[p2].lc,a[p3].lc,a[p4].lc,x,l,mid);
	}
	int getmax(int p1,int p2,int p3,int p4,int l,int r)
	{
		int s=a[p1].s+a[p3].s-a[p4].s-a[p2].s;
		if(!s)
			return 0;
		if(l==r)
			return l;
		int mid=(l+r)>>1;
		int rs=a[a[p1].rc].s+a[a[p3].rc].s-a[a[p4].rc].s-a[a[p2].rc].s;
		if(rs)
			return getmax(a[p1].rc,a[p2].rc,a[p3].rc,a[p4].rc,mid+1,r);
		return getmax(a[p1].lc,a[p2].lc,a[p3].lc,a[p4].lc,l,mid);
	}
	int getmin(int p1,int p2,int p3,int p4,int l,int r)
	{
		int s=a[p1].s+a[p3].s-a[p4].s-a[p2].s;
		if(!s)
			return 0x3fffffff;
		if(l==r)
			return l;
		int mid=(l+r)>>1;
		int ls=a[a[p1].lc].s+a[a[p3].lc].s-a[a[p4].lc].s-a[a[p2].lc].s;
		if(ls)
			return getmin(a[p1].lc,a[p2].lc,a[p3].lc,a[p4].lc,l,mid);			
		return getmin(a[p1].rc,a[p2].rc,a[p3].rc,a[p4].rc,mid+1,r);
	}
}
using sgt::rt1;
using sgt::rt2;
using sgt::insert;
using sgt::suf;
using sgt::pre;
using sgt::getmax;
using sgt::getmin;
list<int> l[100010];
int f[100010];
int st[100010];
int ed[100010];
int s[100010];
int w[100010];
int ti;
int n;
void dfs1(int x)
{
	st[x]=++ti;
	w[ti]=x;
	s[x]=1;
	for(auto v:l[x])
	{
		dfs1(v);
		s[x]+=s[v];
	}
	ed[x]=ti;
}
int update(int &a,int &b,int &c)
{
	if(c>=a)
	{
		b=a;
		a=c;
		return 1;
	}
	else
	{
		b=max(b,c);
		return 2;
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	int rt,x,y;
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if(x)
		{
			l[x].push_back(y);
			f[y]=x;
		}
		else
			rt=y;
	}
	dfs1(rt);
	for(i=1;i<=n;i++)
	{
		x=w[i];
		rt2[x]=insert(rt2[f[x]],s[x],1,n);
		rt1[i]=insert(rt1[i-1],s[x],1,n);
	}
	for(i=1;i<=n;i++)
	{
		int mx=0,sec=0,mi=0x7fffffff;
		int s1,s2,s3,s4,ans;
		int mv;
		
		for(auto v:l[i])
		{
			s1=s[v];
			if(update(mx,sec,s1)==1)
			{
				s4=1;
				mv=v;
			}
			mi=min(mi,s1);
		}
		s1=n-s[i];
		if(s1)
		{
			if(update(mx,sec,s1)==1)
				s4=2;
			mi=min(mi,s1);
		}
//		s1=getmax(rt1[ed[i]],rt1[st[i]],0,0,1,n);
//		s2=pre(rt1[ed[i]],rt1[st[i]],0,0,s1,1,n);
//		s3=getmin(rt1[ed[i]],rt1[st[i]],0,0,1,n);
//		if(update(mx,sec,s1)==1)
//			s4=1;
//		update(mx,sec,s2);
//		mi=min(mi,s3);
//		
//		s1=getmax(rt2[f[i]],0,0,0,1,n);
//		s2=pre(rt2[f[i]],0,0,0,s1,1,n);
//		s3=getmin(rt2[f[i]],0,0,0,1,n);
//		if(update(mx,sec,s1)==1)
//			s4=2;
//		update(mx,sec,s2);
//		mi=min(mi,s3);
//		
//		s1=getmax(rt1[st[i]-1],rt1[ed[i]],rt1[n],rt2[f[i]],1,n);
//		s2=pre(rt1[st[i]-1],rt1[ed[i]],rt1[n],rt2[f[i]],s1,1,n);
//		s3=getmin(rt1[st[i]-1],rt1[ed[i]],rt1[n],rt2[f[i]],1,n);
//		s1-=s[i];
//		s2-=s[i];
//		s3-=s[i];
//		if(update(mx,sec,s1)==1)
//			s4=3;
//		update(mx,sec,s2);
//		mi=min(mi,s3);
		
		ans=0x7fffffff;
		int mid=(mi+mx+1)>>1;
		int s5=mx-mid;
		if(i==1)
			int xxx=1;
		ans=min(ans,mx);
		if(s4==1)
		{
			s1=pre(rt1[ed[mv]],rt1[st[mv]-1],0,0,s5,1,n);
			s2=suf(rt1[ed[mv]],rt1[st[mv]-1],0,0,s5,1,n);
			ans=min(ans,max(sec,max(mi+s1,mx-s1)));
			ans=min(ans,max(sec,max(mi+s2,mx-s2)));
		}
		else if(s4==2)
		{
			s1=pre(rt2[f[i]],0,0,0,s5+s[i],1,n);
			s2=suf(rt2[f[i]],0,0,0,s5+s[i],1,n);
			if(s1)
				s1-=s[i];
			if(s2!=0x3fffffff)
				s2-=s[i];
			ans=min(ans,max(sec,max(mi+s1,mx-s1)));
			ans=min(ans,max(sec,max(mi+s2,mx-s2)));
			s1=pre(rt1[st[i]-1],rt1[ed[i]],rt1[n],rt2[f[i]],s5,1,n);
			s2=suf(rt1[st[i]-1],rt1[ed[i]],rt1[n],rt2[f[i]],s5,1,n);
			ans=min(ans,max(sec,max(mi+s1,mx-s1)));
			ans=min(ans,max(sec,max(mi+s2,mx-s2)));
		}
		printf("%d\n",ans);
	}
	return 0;
}