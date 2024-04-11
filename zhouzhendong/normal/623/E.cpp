#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!('0'<=ch&&ch<='9'))
		ch=getchar();
	while ('0'<=ch&&ch<='9')
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x; 
}
const int N=1<<17;
const LL mod=1e9+7;
double PI=acos(-1.0);
int n,m;
int s,d,R[N];
LL Fac[N],Inv[N];
LL Pow(LL x,LL y){
	if (!y)
		return 1LL;
	LL xx=Pow(x,y/2);
	xx=xx*xx%mod;
	if (y&1LL)
		xx=xx*x%mod;
	return xx;
}
struct C{
	double r,i;
	C(){}
	C(double a,double b){r=a,i=b;}
	C operator + (C x){return C(r+x.r,i+x.i);}
	C operator - (C x){return C(r-x.r,i-x.i);}
	C operator * (C x){return C(r*x.r-i*x.i,r*x.i+i*x.r);}
}w[N],A[N],B[N];
LL tot[N],dp[N],now[N],D[N],E[N];
void FFT(C a[],int n){
	for (int i=0;i<n;i++)
		if (i<R[i])
			swap(a[i],a[R[i]]);
	for (int t=n>>1,d=1;d<n;d<<=1,t>>=1)
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				C tmp=w[t*j]*a[i+j+d];
				a[i+j+d]=a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp;
			}
}
void FFT_mul(LL a[],LL b[],LL c[],int n){
	for (int i=0;i<n;i++)
		c[i]=0,A[i]=C(a[i]>>15,0),B[i]=C(b[i]>>15,0);
	FFT(A,n),FFT(B,n);
	for (int i=0;i<n;i++)
		A[i]=A[i]*B[i],w[i].i*=-1.0;
	FFT(A,n);
	for (int i=0;i<n;i++){
		tot[i]=((LL)(A[i].r/n+0.5))%mod;
		c[i]=(c[i]+tot[i]*(1LL<<30))%mod;
		w[i].i*=-1.0;
	}
	for (int i=0;i<n;i++)
		A[i]=C(a[i]&32767,0),B[i]=C(b[i]&32767,0);
	FFT(A,n),FFT(B,n);
	for (int i=0;i<n;i++)
		A[i]=A[i]*B[i],w[i].i*=-1.0;
	FFT(A,n);
	for (int i=0;i<n;i++){
		tot[i]=(tot[i]+((LL)(A[i].r/n+0.5)))%mod;
		c[i]=(c[i]+((LL)(A[i].r/n+0.5)))%mod;
		w[i].i*=-1.0;
	}
	for (int i=0;i<n;i++){
		A[i]=C((a[i]>>15)+(a[i]&32767),0);
		B[i]=C((b[i]>>15)+(b[i]&32767),0);
	}
	FFT(A,n),FFT(B,n);
	for (int i=0;i<n;i++)
		A[i]=A[i]*B[i],w[i].i*=-1.0;
	FFT(A,n);
	for (int i=0;i<n;i++){
		LL v=((LL)(A[i].r/n+0.5))%mod;
		c[i]=(c[i]+(v-tot[i]+mod)%mod*(1LL<<15))%mod;
		w[i].i*=-1.0;
	}
}
void DP_mul(LL a[],LL b[],LL c[],int &x,int &y){
	for (int i=0;i<s;i++)
		D[i]=E[i]=0;
	for (int i=0;i<=m;i++){
		D[i]=a[i]*Inv[i]%mod*Pow(2,1LL*y*i%(mod-1))%mod;
		E[i]=b[i]*Inv[i]%mod;
	}
	FFT_mul(D,E,c,s);
	for (int i=0;i<s;i++)
		c[i]=c[i]*(i<=m?Fac[i]:0)%mod;
	x+=y;
}
void reads(){
	LL nn=read();
	scanf("%d",&m);
	n=(nn>m)?-1:(int)nn;
}
int main(){
	reads();
	if (n==-1){
		puts("0");
		return 0;
	}
	Fac[0]=1;
	for (int i=1;i<=m;i++)
		Fac[i]=Fac[i-1]*i%mod;
	Inv[m]=Pow(Fac[m],mod-2);
	for (int i=m-1;i>=0;i--)
		Inv[i]=Inv[i+1]*(i+1)%mod;
	for (s=1,d=0;s<m*2+2;s<<=1,d++);
	for (int i=0;i<s;i++){
		R[i]=(R[i>>1]>>1)|((i&1)<<(d-1));
		w[i]=C(cos(2*i*PI/s),sin(2*i*PI/s));
	}
	dp[0]=1;
	for (int i=1;i<=m;i++)
		now[i]=1;
	int x,y;
	for (x=0,y=1;y<=n;){
		if (n&y)
			DP_mul(dp,now,dp,x,y);
		DP_mul(now,now,now,y,y);
	}
	LL ans=0;
	for (int i=0;i<=m;i++)
		ans=(ans+dp[i]*Fac[m]%mod*Inv[i]%mod*Inv[m-i])%mod;
	printf("%I64d",ans);
	return 0;
}