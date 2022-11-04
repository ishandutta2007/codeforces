#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define inf 1e18
#define sqr(x) ((x)*(x))
using namespace std;
const int N=(1<<19)+5;
const int mo=998244353;
int R[N],B[N],n,m,LEN;
int A[N],Sqrt[N],Inv[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void FFTinit(int n){
	LEN=1; int L=0;
	for (;LEN<n;LEN<<=1,L++);
	For(i,0,LEN-1) R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
}
void FFT(int *a,int n,int f){
	For(i,0,n-1) if (i<R[i]) swap(a[i],a[R[i]]);
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
		For(i,0,n-1) a[i]=1ll*a[i]*v%mo;
	}
}
void getINV(int n){
	if (n==1){
		Inv[0]=power(Sqrt[0],mo-2);
		Inv[1]=0;
		return;
	}
	getINV((n+1)/2);
	FFTinit(n*2);
	For(i,0,LEN-1)
		if (i<n) B[i]=Sqrt[i];
		else B[i]=Inv[i]=0;
	FFT(B,LEN,1); FFT(Inv,LEN,1); 
	For(i,0,LEN-1) Inv[i]=1ll*Inv[i]*(2+mo-1ll*B[i]*Inv[i]%mo)%mo;
	FFT(Inv,LEN,-1);
	For(i,n,LEN-1) Inv[i]=0;
}
void getSQRT(int n){
	if (n==1){
		Sqrt[0]=1;
		return;
	}
	getSQRT((n+1)/2);
	getINV(n);
	FFTinit(n*2);
	For(i,0,LEN-1) B[i]=(i<n?A[i]:0);
	FFT(B,LEN,1); FFT(Inv,LEN,1); 
	For(i,0,LEN-1) B[i]=1ll*B[i]*Inv[i]%mo;
	FFT(B,LEN,-1);
	For(i,0,n-1) Sqrt[i]=1ll*(Sqrt[i]+B[i])*(mo+1)/2%mo;
}
int main(){
	scanf("%d%d",&n,&m); m++;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		A[x]=(A[x]+mo-4)%mo;
	}
	A[0]=1; getSQRT(m);
	Sqrt[0]++; getINV(m);
	For(i,1,m-1) printf("%d\n",Inv[i]*2%mo);
}