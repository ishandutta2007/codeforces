#include<bits/stdc++.h>
using namespace std;
const int D=23,C=7*17,mod=C*(1<<D)+1,G=3,N=262200;
inline int power(int x,int y)
{
	int t=1;
	for(; y; y>>=1,x=x*1ll*x%mod)
		if(y&1) t=t*1ll*x%mod;
	return t;
}
struct FFT_transform
{
	int n,l,g;
	void setl(int len)
	{
		for(l=0; (1<<l)<len*2; ++l)
			;
		n=1<<l;
		g=power(G,C*(1<<(D-l)));
	}
	int rebit(int x)
	{
		int y=0;
		for(int i=0;i<l;++i)
			if(x&(1<<i)) y|=1<<(l-1-i);
		return y;
	}
	void DFT_inplace(int *t,int sign)
	{
		for(int i=0;i<n;++i)
			if(i<rebit(i))
				swap(t[i],t[rebit(i)]);
		for(int i=1;i<=l;++i)
		{
			int d=1<<i,g1=power(sign==1 ? g : power(g,n-1) , 1<<(l-i));
			for(int j=0;j<n;j+=d)
				for(int k=j,w=1;k<j+d/2;++k)
				{
					int t1=t[k],t2=t[k+d/2]*1ll*w%mod;
					t[k]=(t1+t2)%mod;
					t[k+d/2]=(t1-t2+mod)%mod;
					w=w*1ll*g1%mod;
				}
		}
		if(sign==-1)
		{
			int rn=power(n,mod-2);
			for(int i=0;i<n;++i)
				t[i]=t[i]*1ll*rn%mod;
		}
	}
	void FFT1(int *a,int *b,int *c,int h)
	{
		DFT_inplace(a,1);
		DFT_inplace(b,1);
		DFT_inplace(c,1);
		for(int i=0;i<n;++i)
			a[i]=a[i]*1ll*b[i]%mod*1ll*c[i]%mod;
		DFT_inplace(a,-1);
		for(int i=h;i<n;++i)
			a[i]=0;
		fill(b,b+n,0);
		fill(c,c+n,0);
	}
}calc;
int n,m,f[N]={},g[N]={},a[N]={},b[N]={},c[N]={};
void work(int l,int r)
{
	if(l==r)
		return;
	int mid=(l+r)>>1;
	work(l,mid);
	calc.setl(r-l+1);
	copy(f+l,f+mid+1,a);
	if(l)
	{
		copy(f,f+r-l+1,b);
		for(int i=0;i<=r-l;++i)
			b[i]=b[i]*2%mod;
	}
	else
		copy(f,f+mid-l+1,b);
	copy(g,g+r-l+1,c);
	calc.FFT1(a,b,c,r-l+1);
	for(int i=mid+1;i<=r;++i)
		f[i]=(f[i]+a[i-l])%mod;
	fill(a,a+r-l+1,0);
	work(mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		++g[x];
	}
	f[0]=1;
	work(0,m);
	for(int i=1;i<=m;++i)
		printf("%d\n",f[i]);
	return 0;
}