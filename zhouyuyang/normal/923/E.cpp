#include<bits/stdc++.h>
#define mo 998244353
#define N 265000
using namespace std;
int a[N],b[N],R[N];
int fac[N],inv[N];
long long m;
int n;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void FFT(int *a,int n,int f){
	for (int i=0;i<n;i++)
		if (i<R[i]) swap(a[i],a[R[i]]);
	for (int i=1;i<n;i<<=1){
		int wn=power(3,(mo-1)/(i<<1));
		if (f==-1) wn=power(wn,mo-2);
		for (int j=0;j<n;j+=(i<<1))
			for (int k=j,w=1;k<j+i;k++){
				int y=1ll*a[k+i]*w%mo;
				a[k+i]=(a[k]+mo-y)%mo;
				a[k]=(a[k]+y)%mo;
				w=1ll*w*wn%mo;
			}
	}
	if (f==-1){
		int v=power(n,mo-2);
		for (int i=0;i<n;i++)
			a[i]=1ll*a[i]*v%mo;
	}
}
int main(){
	fac[0]=1;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
	inv[N-1]=power(fac[N-1],mo-2);
	for (int i=N-1;i;i--)
		inv[i-1]=1ll*inv[i]*i%mo;
	scanf("%d%lld",&n,&m); n++;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int c=1,L=0;
	for (;c<=2*n;c<<=1,L++);
	for (int i=0;i<c;i++)
		R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	
	for (int i=1;i<=n;i++)
		a[i]=1ll*a[i]*fac[i-1]%mo;
	
	reverse(a+1,a+n+1);
	for (int i=0;i<=n;i++) b[i]=inv[i];
	FFT(a,c,1); FFT(b,c,1);
	for (int i=0;i<c;i++)
		a[i]=1ll*a[i]*b[i]%mo;
	FFT(a,c,-1);
	for (int i=n+1;i<c;i++) a[i]=0;
	reverse(a+1,a+n+1);
	
	for (int i=1;i<=n;i++)
		a[i]=1ll*a[i]*power(i,mo-1-m%(mo-1))%mo;
		
	reverse(a+1,a+n+1);
	memset(b,0,sizeof(b));
	for (int i=0;i<=n;i++)
		b[i]=(i&1?mo-inv[i]:inv[i]);
	FFT(a,c,1); FFT(b,c,1);
	for (int i=0;i<c;i++)
		a[i]=1ll*a[i]*b[i]%mo;
	FFT(a,c,-1);
	for (int i=n+1;i<c;i++) a[i]=0;
	reverse(a+1,a+n+1);

	for (int i=1;i<=n;i++)
		printf("%d ",1ll*a[i]*inv[i-1]%mo);
}