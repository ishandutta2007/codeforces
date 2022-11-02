#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=2100000,C=7*17,D=23,mod=(C<<D)+1,G=3;
int n,m,a[N]={},b[N]={},ans[N]={},tot=0;
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		++a[x],++b[x];
	}
	a[0]=b[0]=1;
}
inline int power(int x,int y)
{
	int t=1;
	for(; y; y>>=1,x=x*1ll*x%mod)
		if(y&1) t=t*1ll*x%mod;
	return t;
}
void DFT_inplace(int *t,int l,int sign)
{
	int n=1<<l,g=power(G,C<<(D-l));
	for(int i=0,x=0,d=0;i<n;++i)
	{
		if(i<x) swap(t[i],t[x]);
		for(d=0; i&(1<<d); ++d) x^=1<<(l-1-d);
		if(l-1-d>=0) x^=1<<(l-1-d);
	}
	for(int i=1,d=2;i<=l;++i,d<<=1)
	{
		int g1=power(sign==1 ? g : power(g,n-1),1<<(l-i));
		for(int j=0;j<n;j+=d)
			for(int k=j,w=1;k<j+d/2;++k,w=w*1ll*g1%mod)
			{
				int t1=t[k],t2=t[k+d/2]*1ll*w%mod;
				t[k]=(t1+t2)%mod,t[k+d/2]=(t1+mod-t2)%mod;
			}
	}
	if(sign==-1)
		for(int i=0;i<n;++i)
			t[i]=t[i]*1ll*power(n,mod-2)%mod;
}
void work()
{
	int l=1;
	while((1<<l)<((m+1)<<1))
		++l;
	DFT_inplace(a,l,1);
	for(int i=0;i<(1<<l);++i)
		a[i]=a[i]*1ll*a[i]%mod;
	DFT_inplace(a,l,-1);
	for(int i=0;i<=m;++i)
		if(a[i] && !b[i])
		{
			puts("NO");
			return;
		}
	for(int i=1;i<=m;++i)
		if(a[i]==2)
			ans[++tot]=i;
	puts("YES");
	printf("%d\n",tot);
	for(int i=1;i<=tot;++i)
		printf("%d%c",ans[i]," \n"[i==tot]);
}
int main()
{	
	init();
	work();
	return 0;
}