#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=55;
const int mod=998244353;
int n,t;
int ans;
struct point{int x,y;}p[maxn];
int tim[maxn*maxn],cnt;
namespace scanning
{
	struct rec{int x1,y1,x2,y2;}p[maxn];
	struct line{int x,y1,y2,v;const bool operator <(const line &a)const{return x<a.x;}}l[maxn<<1];int cnt;
	struct segment
	{
		#define L(u) t[u].ls
		#define R(u) t[u].rs
		struct node{int ls,rs,sum,len;}t[maxn*100];int cnt,rt;
		void update(int u,int l,int r)
		{
			if(t[u].sum)t[u].len=r-l+1;
			else t[u].len=t[L(u)].len+t[R(u)].len;
		}
		void change(int &u,int l,int r,int nl,int nr,int x)
		{
			if(!u){u=++cnt;t[u].len=t[u].ls=t[u].rs=t[u].sum=0;}
			if(l>=nl&&r<=nr){t[u].sum+=x;update(u,l,r);return;}
			int mid=(l+r)>>1;
			if(mid>=nl)change(L(u),l,mid,nl,nr,x);
			if(mid+1<=nr)change(R(u),mid+1,r,nl,nr,x);
			update(u,l,r);
		}
	}tr;
	int solve()
	{
		int ret=0;cnt=0;
		for(int i=1;i<=n;i++)l[++cnt]={p[i].x1,p[i].y1,p[i].y2-1,1},l[++cnt]={p[i].x2,p[i].y1,p[i].y2-1,-1};
		sort(l+1,l+cnt+1);tr.cnt=0;tr.rt=0;
		for(int i=1;i<cnt;i++)
		{
			tr.change(tr.rt,-1e9,1e9,l[i].y1,l[i].y2,l[i].v);
			ret=(ret+(ll)tr.t[tr.rt].len*(l[i+1].x-l[i].x)%mod)%mod;
		}
		return ret;
	}
}
namespace lagrange
{
	point p[5];
	int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
	int calc(int x)
	{
		int ret=0;
		for(int i=0;i<5;i++)
		{
			int sum=p[i].y;
			for(int j=0;j<5;j++)if(i!=j)sum=(ll)sum*((x-p[j].x+mod)%mod)%mod*qpow((p[i].x-p[j].x+mod)%mod,mod-2)%mod;
			ret=(ret+sum)%mod;
		}
		return ret;
	}
}
int main()
{
	n=read();t=read();
	for(int i=1;i<=n;i++)p[i].x=read(),p[i].y=read();	
	tim[++cnt]=0;tim[++cnt]=t;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			int nt=(max(abs(p[i].x-p[j].x),abs(p[i].y-p[j].y))+1)>>1;
			if(nt<t)tim[++cnt]=nt;
		}
	sort(tim+1,tim+cnt+1);cnt=unique(tim+1,tim+cnt+1)-(tim+1);
	for(int i=1;i<cnt;i++)
	{
		for(int j=tim[i];j<=tim[i]+4;j++)
		{
			for(int k=1;k<=n;k++)scanning::p[k]={p[k].x-j,p[k].y-j,p[k].x+j+1,p[k].y+j+1};
			lagrange::p[j-tim[i]]={j,scanning::solve()};
		}
		for(int j=1;j<=4;j++)lagrange::p[j].y=(lagrange::p[j].y+lagrange::p[j-1].y)%mod;
		ans=((ll)ans+lagrange::calc(tim[i+1]-1))%mod;
	}
	for(int i=1;i<=n;i++)scanning::p[i]={p[i].x-t,p[i].y-t,p[i].x+t+1,p[i].y+t+1};
	ans=mod-ans;
	ans=(ans+(ll)scanning::solve()*t%mod)%mod;
	printf("%d\n",ans);
	return 0;
}