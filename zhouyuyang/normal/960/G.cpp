#include<bits/stdc++.h>
#define mo 998244353
#define N 500005
using namespace std;
int a[N],b[N],R[N],C[N*40];
int n,k1,k2,tot,fac[N];
struct range{
	int l,r;
};
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void FFT(int *a,int L,int f){
	int n=(1<<L);
	for (int i=1;i<n;i++)
		R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
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
range solve(int l,int r){
	if (l>r){
		C[++tot]=1;
		return (range){tot,tot};
	}
	if (l==r){
		C[++tot]=l; C[++tot]=1;
		return (range){tot-1,tot};
	}
	int mid=(l+r)/2;
	range k1=solve(l,mid);
	range k2=solve(mid+1,r);
	int n=max(mid-l+1,r-mid),L=1;
	for (;(1<<L)<=n*2;L++);
	for (int i=0;i<1<<L;i++) a[i]=b[i]=0;
	for (int i=k1.l;i<=k1.r;i++) a[i-k1.l]=C[i];
	for (int i=k2.l;i<=k2.r;i++) b[i-k2.l]=C[i];
	FFT(a,L,1); FFT(b,L,1);
	for (int i=0;i<1<<L;i++)
		a[i]=1ll*a[i]*b[i]%mo;
	FFT(a,L,-1);
	range ans; ans.l=tot+1;
	for (int i=0;i<=r-l+1;i++)
		C[++tot]=a[i];
	ans.r=tot;
	return ans;
} 
int main(){
	scanf("%d%d%d",&n,&k1,&k2);
	n--;
	if (k1==0||k2==0||k1+k2-2>n)
		return puts("0"),0;
	if (!n)
		return puts("1"),0;
	k1--; k2--;
	range szb=solve(1,n-1);
	int ans=C[szb.l+k1+k2-1];
	fac[0]=1;
	for (int i=1;i<=k1+k2;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
	ans=1ll*ans*fac[k1+k2]%mo*power(1ll*fac[k1]*fac[k2]%mo,mo-2)%mo;
	printf("%d\n",ans);
}
//f[i][j]:ij
//f[i][j]=
//       For(k,1,j)
//              f[k][j-1]*(i-1)!/(k-1)!