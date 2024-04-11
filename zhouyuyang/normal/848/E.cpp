#include<bits/stdc++.h>
#define mo 998244353
#define ll long long
#define M 132000
#define N 50005
using namespace std;
int n;
int g[N];
int g0[N],g1[N],g2[N];
int f0[N],f1[N],f2[N];
int A[M],B[M],R[M];
int ans;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void FFT(int *a,int n,int f){
	for (int i=0;i<n;i++)
		if (i<R[i]) swap(a[i],a[R[i]]);
	for (int d=1;d<n;d<<=1){
		int wn=power(3,(mo-1)/(d<<1));
		if (f==-1) wn=power(wn,mo-2);
		for (int i=0;i<n;i+=(d<<1))
			for (int j=i,w=1;j<i+d;j++){
				int y=1ll*a[j+d]*w%mo;
				a[j+d]=(a[j]+mo-y)%mo;
				a[j]=(a[j]+y)%mo;
				w=1ll*w*wn%mo;
			}
	}
	if (f==-1){
		int v=power(n,mo-2);
		for (int i=0;i<n;i++)
			a[i]=1ll*a[i]*v%mo;
	}
}
void push(int *a,int asz,int *b,int bsz,int *c,int cl,int cr){
	int L=0;
	for (;(1<<L)<=asz+bsz;L++);
	int n=(1<<L);
	for (int i=1;i<n;i++)
		R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	for (int i=0;i<n;i++){
		A[i]=(i<asz?a[i]:0);
		B[i]=(i<bsz?b[i]:0);
	}
	FFT(A,n,1); FFT(B,n,1);
	for (int i=0;i<n;i++)
		A[i]=1ll*A[i]*B[i]%mo;
	FFT(A,n,-1);
	for (int i=cl;i<=cr;i++)
		c[i]=(c[i]+A[i])%mo;
}
void solve(int l,int r){
	if (r-l<=500){
		for (int i=l;i<=r;i++){
			for (int j=l;j<i;j++){
				f0[i]=(f0[i]+1ll*f0[j]*g0[i-j]+1ll*f1[j]*g1[i-j])%mo;
				f1[i]=(f1[i]+1ll*f0[j]*g1[i-j]+1ll*f1[j]*g2[i-j])%mo;
				f2[i]=(f2[i]+1ll*f2[j]*g2[i-j]+1ll*f1[j]*g1[i-j])%mo;
			}
			f0[i]=(f0[i]+g0[i])%mo;
			f1[i]=(f1[i]+g1[i])%mo;
			f2[i]=(f2[i]+g2[i])%mo;
		}
		return;
	}
	int m=(l+r)/2;
	solve(l,m);
	push(f0+l,m-l+1,g0,r-l+1,f0+l,m-l+1,r-l);
	push(f1+l,m-l+1,g1,r-l+1,f0+l,m-l+1,r-l);
	push(f0+l,m-l+1,g1,r-l+1,f1+l,m-l+1,r-l);
	push(f1+l,m-l+1,g2,r-l+1,f1+l,m-l+1,r-l);
	push(f2+l,m-l+1,g2,r-l+1,f2+l,m-l+1,r-l);
	push(f1+l,m-l+1,g1,r-l+1,f2+l,m-l+1,r-l);
	solve(m+1,r);
}
int main(){
	scanf("%d",&n);
	g[0]=g[2]=1;
	for (int i=4;i<=n;i+=2)
		g[i]=(g[i-4]+g[i-2])%mo;
	for (int i=1;i<=n;i++){
		g0[i+1]=1ll*g[i]*i*i%mo;
		g1[i+1]=1ll*g[i-1]*i*i%mo;
		if (i>=2) g2[i+1]=1ll*g[i-2]*i*i%mo;
	}
	solve(0,n);
	ans=1ll*(g[n-1]+g[n-3])*(n-1)*(n-1)%mo*n%mo;
	for (int i=2;i<=n-2;i++){
		ans=(ans+1ll*g[i-1]*(i-1)*(i-1)%mo*f0[n-i]%mo*i)%mo;
		ans=(ans+1ll*g[i-2]*(i-1)*(i-1)%mo*f1[n-i]%mo*2*i)%mo;
		if (i>=3&&i<=n-3)
			ans=(ans+1ll*g[i-3]*(i-1)*(i-1)%mo*f2[n-i]%mo*i)%mo;
	}
	printf("%d",ans%mo);
}