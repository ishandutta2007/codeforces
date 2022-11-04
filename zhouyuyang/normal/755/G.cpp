#include<bits/stdc++.h>
#define mo 998244353
#define N 131100
using namespace std;
int R[N],f[N],g[N];
int n,k;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void FFT(int *a,int n,int f){
	for (int i=1;i<n;i++)
		R[i]=(R[i>>1]>>1)|((i&1)?(n>>1):0);
	for (int i=1;i<n;i++)
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
void plus1(){
	for (int i=k;i;i--){
		f[i]=g[i];
		g[i]=(1ll*g[i]+g[i-1]+f[i-1])%mo;
	}
	f[0]=g[0];
}
void mul2(){
	int l=1;
	for (;l<=k*2;l<<=1);
	FFT(f,l,1); FFT(g,l,1);
	int w=1,wn=power(3,(mo-1)/l);
	for (int i=0;i<l;i++){
		int F=(2ll*f[i]*g[i]%mo-1ll*f[i]*f[i]%mo*(w+1)%mo+mo)%mo;
		int G=(1ll*g[i]*g[i]%mo+1ll*f[i]*f[i]%mo*w%mo)%mo;
		f[i]=F; g[i]=G; w=1ll*w*wn%mo;
	}
	FFT(f,l,-1); FFT(g,l,-1);
	for (int i=k+1;i<l;i++)
		f[i]=g[i]=0;
}
int main(){
	scanf("%d%d",&n,&k);
	g[0]=1;
	for (int i=1<<29,s=0;i;i>>=1){
		if (s) mul2(),s<<=1;
		if (n&i) plus1();s=1;
	}
	for (int i=1;i<=k;i++)
		printf("%d ",g[i]);
}