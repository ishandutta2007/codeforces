#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=998244353,MX=262145;

int N,K,X=1,invX,rev[MX],w[MX],T;
int fac[MX],ifa[MX];
int a[MX],b[MX];
LL M;

inline int Pow(int a,int b)
{
	if(a%mod==0)return 0;
	int ans=1;
	for(;b;b>>=1,a=(LL)a*a%mod)if(b&1)ans=(LL)ans*a%mod;
	return ans;
}
inline void DFT(int* A,int r)
{
	static int tmp;
	for(int i=0;i<X;i++)if(i<rev[i])swap(A[i],A[rev[i]]);
	w[0]=1;
	for(int i=1,j,k;i<X;i<<=1)
	{
		w[1]=Pow(3,r?mod-1-499122176/i:499122176/i);
		for(j=2;j<i;j++)w[j]=(LL)w[j-1]*w[1]%mod;
		for(j=0;j<X;j+=i<<1)for(k=0;k<i;k++)
			tmp=(LL)A[i+j+k]*w[k]%mod,A[i+j+k]=(A[j+k]-tmp+mod)%mod,A[j+k]=(A[j+k]+tmp)%mod;
	}
	if(r)for(int i=0;i<X;i++)A[i]=(LL)A[i]*invX%mod;
}

int main()
{
	scanf("%d%lld",&N,&M),M%=mod-1;
	fac[0]=1;
	for(int i=1;i<=N;i++)fac[i]=(LL)fac[i-1]*i%mod;
	ifa[N]=Pow(fac[N],mod-2);
	for(int i=N;i;i--)ifa[i-1]=(LL)ifa[i]*i%mod;
	for(int i=0;i<=N;i++)scanf("%d",a+i),a[i]=(LL)a[i]*fac[i]%mod;
	for(;X<=N;X<<=1,K++);X<<=1;
	T=(mod-1)/X,invX=Pow(X,mod-2);
	for(int i=0;i<X;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<K);
	for(int i=0;i<=N;i++)b[i]=ifa[N-i];
	DFT(a,0),DFT(b,0);
	for(int i=0;i<X;i++)a[i]=(LL)a[i]*b[i]%mod;
	DFT(a,1);
	for(int i=0;i<=N;i++)a[i]=(LL)a[i+N]*ifa[i]%mod*Pow(i+1,mod-1-M)%mod;
	for(int i=N+1;i<X;i++)a[i]=0;
	
	for(int i=0;i<=N;i++)a[i]=(LL)a[i]*fac[i]%mod;
	for(int i=0;i<=N;i++)b[i]=(N-i)&1?mod-ifa[N-i]:ifa[N-i];
	for(int i=N+1;i<X;i++)b[i]=0;
	
	
	DFT(a,0),DFT(b,0);
	for(int i=0;i<X;i++)a[i]=(LL)a[i]*b[i]%mod;
	DFT(a,1);
	for(int i=0;i<=N;i++)printf("%d ",(LL)a[i+N]*ifa[i]%mod);
}