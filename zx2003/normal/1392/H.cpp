#include<bits/stdc++.h>
using namespace std;
const int N=42e5,mo=998244353;
inline int poww(int x,int y){int ans=1;for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;return ans;}
inline void red(int&x){x+=x>>31&mo;}
int c[N],w[N];
struct NTT{
	int b[N],wn[N],l,invl;
	inline void ini(int n){
		for(l=1;l<n;l<<=1);invl=poww(l,mo-2);int i;
		for(i=1;i<l;++i)b[i]=b[i>>1]>>1|(i&1?l>>1:0);
		for(i=2,wn[*wn=1]=poww(3,(mo-1)/l);i<=l;++i)wn[i]=1ll*wn[1]*wn[i-1]%mo;
	}
	inline void DFT(int*a,int key){
		int i,j,k,m,u;
		memcpy(c,a,l<<2);for(i=0;i<l;++i)a[b[i]]=c[i];
		for(i=2;i<=l;i<<=1){
			for(m=i>>1,j=k=0;k<m;++k,j+=l/i)w[k]=wn[j];
			for(j=0;j<l;j+=i)for(k=0;k<m;++k)u=1ll*w[k]*a[j+k+m]%mo,
				red(a[j+k+m]=a[j+k]-u),red(a[j+k]+=u-mo);
		}
		if(key==-1)for(i=0,std::reverse(a+1,a+l);i<l;++i)a[i]=1ll*a[i]*invl%mo;
	}
}F;
int vf[N],fac[N],inv[N];
inline int C(int n,int m){return 1ll*vf[m]*vf[n-m]%mo*fac[n]%mo;}
int main(){
	static int n,m,l,i,ans,p,w,a[N],b[N],iv;
	for(i=*vf=*fac=1;i<N;++i)
		inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo,
		vf[i]=1ll*vf[i-1]*inv[i]%mo,
		fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%d%d",&n,&m);iv=poww(C(m+n,m),mo-2);
	for(i=0;i<n;++i)a[i]=1ll*vf[i]*poww(C(n,i),mo-2)%mo*C(m-1+n-i,m-1)%mo,b[i]=vf[i];
	F.ini(n*2);F.DFT(a,1);F.DFT(b,1);for(i=0;i<F.l;++i)a[i]=1ll*a[i]*b[i]%mo;F.DFT(a,-1);
	for(l=n-1;l>=0;--l){
		p=1ll*fac[l]*a[l]%mo*iv%mo;
		ans=(ans+1ll*poww(1+mo-p,mo-2)*((n-l)&1?C(n,l):mo-C(n,l)))%mo;
	}
	for(i=0;i<=n;++i)w=(w+1ll*C(m-1+n-i,m-1)*(i+1))%mo;
	w=1ll*w*iv%mo;ans=1ll*ans*w%mo;printf("%d\n",ans);
}