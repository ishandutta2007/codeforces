#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1,D=998244353;
long long t,n,m,P[N],a[N],b[N],p,q,f[N],g[N],l,r[N],w[N],W,x,y,V;
int Q(long long a,long long b)
{
	t=1;
	while(b)
	{
		if(b&1)
			(t*=a)%=D;
		(a*=a)%=D,b/=2;
	}
	return t;
}
void S(long long *a,int t)
{
	for(int i=0;i<p;i++)
		if(i<r[i])
			swap(a[i],a[r[i]]);
	for(int i=1;i<p;i<<=1)
	{
		W=Q(3,(D-1)/(i<<1)),w[0]=1;
		if(t<0)
			W=Q(W,D-2);
		for(int j=1;j<i;j++)
			w[j]=w[j-1]*W%D;
		for(int j=0;j<p;j+=2*i)
			for(int k=0;k<i;k++)
				x=a[j+k],y=w[k]*a[i+j+k]%D,a[j+k]=(x+y)%D,a[i+j+k]=(x-y+D)%D;
	}
}
void T()
{
	p=1,l=-1;
	while(p<=q)
		p*=2,l++;
	for(int i=0;i<p;i++)
		r[i]=(r[i>>1]>>1)|((i&1)<<l);
	S(f,1),S(g,1);
	for(int i=0;i<p;i++)
		(f[i]*=g[i])%=D;
	S(f,-1),V=Q(p,D-2);
	for(int i=0;i<p;i++)
		(f[i]*=V)%=D;
}
int main()
{
	cin>>n>>m,a[0]=1;
	for(int i=0;i<=n;i++)
		cin>>P[i];
	for(int i=1;i<=n;i++)
		a[i]=a[i-1]*i%D;
	b[n]=Q(a[n],D-2);
	for(int j=n;j>0;j--)
		b[j-1]=b[j]*j%D;
	for(int i=0;i<=n;i++)
		f[i]=b[i],g[n-i]=a[i]*P[i]%D;
	q=2*n,T();
	for(int i=n+1;i<p;i++)
		f[i]=g[i]=0;
	for(int i=0;i<=n;i++)
		(f[n-i]*=Q(Q(i+1,m),D-2))%=D,g[i]=Q(-1,i)*b[i];
    q=2*n,T();
	for(int i=0;i<=n;i++)
		cout<<b[i]*f[n-i]%D<<' ';
	return 0;
}