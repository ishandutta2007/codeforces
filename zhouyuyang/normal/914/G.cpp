#include<bits/stdc++.h>
#define ll long long
#define mo 1000000007
#define inv 500000004
#define N 265000
using namespace std;
ll a[N],b[N],f[N],fib[N];
int n,ans;
void FWT(ll *a,int tp){
	for (int d=1;d<n;d*=2)
		for (int m=d*2,i=0;i<n;i+=m)
			for (int j=i;j<i+d;j++){
				ll x=a[j],y=a[j+d];
				if (tp==1) a[j]=(x+y)%mo,a[j+d]=(x-y+mo)%mo;
				if (tp==0) a[j]=(x+y)%mo;
			}
}
void UFWT(ll *a,int tp){
	for (int d=1;d<n;d*=2)
		for (int m=d*2,i=0;i<n;i+=m)
			for (int j=i;j<i+d;j++){
				ll x=a[j],y=a[j+d];
				if (tp==1) a[j]=1ll*(x+y)*inv%mo,a[j+d]=(1ll*(x-y)*inv%mo+mo)%mo;
				if (tp==0) a[j]=(x+mo-y)%mo;
			}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		a[x]++; b[x]++;
	}
	n=(1<<17)-1;
	fib[1]=1;
	for (int i=2;i<=n;i++)
		fib[i]=(fib[i-1]+fib[i-2])%mo;
	for (int i=0;i<=n;i++){
		for (int j=i;;j=(j-1)&i){
			f[i]+=a[j]*a[i^j];
			if (j==0) break;
		}
		f[i]%=mo;
	}
	FWT(b,1);
	for (int i=0;i<=n;i++)
		b[i]=b[i]*b[i]%mo;
	UFWT(b,1);
	for (int i=0;i<=n;i++)
		f[i]=fib[i]*f[i]%mo;
	for (int i=0;i<=n;i++)
		a[i]=fib[i]*a[i]%mo;
	for (int i=0;i<=n;i++)
		b[i]=fib[i]*b[i]%mo;
	FWT(f,0);
	FWT(a,0);
	FWT(b,0);
	for (int i=0;i<=n;i++)
		f[i]=f[i]*a[i]%mo*b[i]%mo;
	UFWT(f,0);
	for (int i=1;i<n;i*=2)
		ans=(ans+f[i])%mo;
	printf("%d",ans);
}