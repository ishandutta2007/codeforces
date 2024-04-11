#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++) 
using namespace std;
#define ll long long
const int N=65540;
const int mo=1000000007;
ll cnt,g[16];
int n,m,inv[N];
int a[N],b[N],c[N],f[N];
void mul(int *a,int *b,int *c,int n){
	if (n<=8){
		memset(g,0,sizeof(g));
		For(i,0,n-1) For(j,0,n-1)
			g[i+j]+=1ll*a[i]*b[j];
		For(i,0,n*2-1) c[i]=g[i]%mo;
		return;
	}
	int mid=n/2;
	mul(a,b,c,mid);
	mul(a+mid,b+mid,c+n,mid);
	int x[mid],y[mid],z[n];
	For(i,0,mid-1){
		x[i]=(a[i]+a[i+mid])%mo;
		y[i]=(b[i]+b[i+mid])%mo;
	}
	mul(x,y,z,mid);
	For(i,0,n-1) z[i]=(z[i]+2ll*mo-c[i]-c[i+n])%mo;
	For(i,0,n-1) c[i+mid]=(c[i+mid]+z[i])%mo;
}
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	//f[i+j]+=f[i]*(2^i)*C(n-i,j);
	//f[i+j]+=f[i]*(2^i)*(n-i)!/(j!)/(n-i-j)!
	scanf("%lld%d",&cnt,&n);
	if (cnt>n) return puts("0"),0;
	int m=1;
	for (;m<=n;m<<=1);
	inv[0]=inv[1]=1;
	For(i,2,n) inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	For(i,1,n) inv[i]=1ll*inv[i]*inv[i-1]%mo;
	For(i,1,n) a[i]=inv[i];
	f[0]=1;
	for (int k=1;k<=cnt;k<<=1){
		if (k>1){
			int x=1,y=power(2,k/2);
			For(i,0,n){
				b[i]=1ll*a[i]*x%mo;
				x=1ll*x*y%mo;
			}
			mul(a,b,c,m);
			For(i,0,n) a[i]=c[i];
		}
		if (cnt&k){
			int x=1,y=power(2,cnt&(k-1));
			For(i,0,n){
				b[i]=1ll*a[i]*x%mo;
				x=1ll*x*y%mo;
			}
			mul(f,b,c,m);
			For(i,0,n) f[i]=c[i];
		}
	}
	int ans=0;
	For(i,0,n) ans=(ans+1ll*f[i]*inv[n-i])%mo;
	For(i,1,n) ans=1ll*ans*i%mo;
	printf("%d",ans);
}