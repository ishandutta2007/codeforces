#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAM=1e4+3;
const int MAN=1e2+3;
struct milk
{
	int to,next;
}a[MAM];
int dui[MAN];
int h[MAN];
int f[MAN];
LL s[MAN];
LL ss[MAN];
int n,m;
inline void add(int x,int y,int i){a[i].to=y;a[i].next=h[x];h[x]=i;}
inline void bfs()
{
	f[1]=0;
	int head=1,tail=0;
	int x;
	dui[++tail]=1;
	for(;head<=tail;)
	{
		x=dui[head++];
		for(int i=h[x];i>0;i=a[i].next)if(f[x]+1<f[a[i].to]){f[a[i].to]=f[x]+1;dui[++tail]=a[i].to;}
	}
}
inline void dfs(int x)
{
	int head=1,tail=0;
	dui[++tail]=x;s[x]=1;
	for(;head<=tail;)
	{
		x=dui[head];head++;
		for(int i=h[x];i>0;i=a[i].next)
		if(f[x]==f[a[i].to]+1)
		{
		if(s[a[i].to]==0)dui[++tail]=a[i].to;
		s[a[i].to]+=s[x];
		}
	}
	
	head=1;tail=0;
	dui[++tail]=1;ss[x]=1;
	for(;head<=tail;)
	{
		x=dui[head];head++;
		for(int i=h[x];i>0;i=a[i].next)
		if(f[x]+1==f[a[i].to])
		{
		if(ss[a[i].to]==0)dui[++tail]=a[i].to;
		ss[a[i].to]+=ss[x];
		}
	}
}
LL rin()
{
	LL s=0;
	char c=getchar();
	bool bj=0;
	for(;(c>'9'||c<'0')&&c!='-';c=getchar());
	if(c=='-')bj=1,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
	if(bj)return -s;
	return s;
}
int main()
{
	memset(f,0x3f,sizeof(f));
	int i,j;
	n=rin();m=rin();
	int x,y;
	for(i=1;i<=m;i++)x=rin(),y=rin(),add(x,y,i),add(y,x,i+m);
	bfs();
    dfs(n);
	LL nam;
	nam=s[1];
	for(i=2;i<n;i++)nam=max(nam,s[i]*ss[i]*2);
    double ans=nam;
	ans/=s[1];
	printf("%.6lf",ans);
	return 0;
}