#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define pi acos(-1.0)
using namespace std;
const int maxn=20010;
typedef double db;
struct cp
{
	db x,y;
	cp() {}
	cp(db a,db b) {x=a,y=b;}
	cp operator + (const cp &a) const {return cp(x+a.x,y+a.y);}
	cp operator - (const cp &a) const {return cp(x-a.x,y-a.y);}
	cp operator * (const cp &a) const {return cp(x*a.x-y*a.y,x*a.y+y*a.x);}
}l1[100010],l2[100010];
int head[60],next[110],to[110],pa[110],pb[110],pc[110],vis[60],dis[60];
db p[110][20010],F,f[60][20010],g[110][20010],sp[110][20010];
int n,m,T;
inline void FFT(cp *a,int len,int f)
{
	int i,j,k,h;
	cp t;
	for(i=k=0;i<len;i++)
	{
		if(i>k)	swap(a[i],a[k]);
		for(j=len>>1;(k^=j)<j;j>>=1);
	}
	for(h=2;h<=len;h<<=1)
	{
		cp wn(cos(2*pi*f/h),sin(2*pi*f/h));
		for(i=0;i<len;i+=h)
		{
			cp w(1,0);
			for(j=i;j<i+h/2;j++)	t=w*a[j+h/2],a[j+h/2]=a[j]-t,a[j]=a[j]+t,w=w*wn;
		}
	}
	if(f==-1)	for(i=0;i<len;i++)	a[i].x/=len;
}
inline int rd()
{
	int ret=0,f=1;	char gc=getchar();
	while(gc<'0'||gc>'9')	{if(gc=='-')	f=-f;	gc=getchar();}
	while(gc>='0'&&gc<='9')	ret=ret*10+(gc^'0'),gc=getchar();
	return ret*f;
}
void solve(int l,int r)
{
	if(l==r)
	{
		for(int i=1;i<n;i++)	f[i][l]=1e9;
		for(int i=1;i<=m;i++)
		{
			g[i][l]+=sp[i][T-l+1]*(dis[pb[i]]+F);
			f[pa[i]][l]=min(f[pa[i]][l],g[i][l]+pc[i]);
		}
		return ;
	}
	int mid=(l+r)>>1,i,j,len;
	for(len=1;len<r-l+r-mid;len<<=1);
	solve(mid+1,r);
	for(j=1;j<=m;j++)
	{
		memset(l1,0,sizeof(l1[0])*len),memset(l2,0,sizeof(l2[0])*len);
		for(i=1;i<=r-l;i++)	l1[r-l-i].x=p[j][i];
		for(i=mid+1;i<=r;i++)	l2[i-mid-1].x=f[pb[j]][i];
		FFT(l1,len,1),FFT(l2,len,1);
		for(i=0;i<len;i++)	l1[i]=l1[i]*l2[i];
		FFT(l1,len,-1);
		for(i=0;i<mid-l+1;i++)	g[j][l+i]+=l1[r-mid-1+i].x;
	}
	solve(l,mid);
}
int main()
{
	//freopen("cf553E.in","r",stdin);
	n=rd(),m=rd(),T=rd(),F=rd();
	int i,j;
	for(i=1;i<=m;i++)
	{
		pa[i]=rd(),pb[i]=rd(),pc[i]=rd();
		for(j=1;j<=T;j++)	p[i][j]=rd()*0.00001;
		for(j=T;j;j--)	sp[i][j]=sp[i][j+1]+p[i][j];
	}
	memset(dis,0x3f,sizeof(dis));
	dis[n]=0;
	for(i=1;i<=n;i++)
	{
		int k=0;
		for(j=1;j<=n;j++)	if(!vis[j]&&dis[j]<dis[k])	k=j;
		vis[k]=1;
		for(j=1;j<=m;j++)	if(pb[j]==k)	dis[pa[j]]=min(dis[pa[j]],dis[k]+pc[j]);
	}
	solve(0,T);
	printf("%.10lf",f[1][0]);
	return 0;
}