#include<bits/stdc++.h>
using namespace std;
const int mo=998244353,N=7e4,K=19;
inline void red(int&x){
	x+=x>>31&mo;
}
inline void add(int&a,int b){
	red(a+=b-mo);
}
inline int poww(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
int n,k,c,i,j,l,p,a,cf,aa[N],bo[N];
int vf[K],fac[K],inv[K];
struct poly{
	int a[K];
	inline poly operator-(const poly&rhs){
		static poly ret;
		for(int i=0;i<=k;++i)red(ret.a[i]=a[i]-rhs.a[i]);
		return ret;
	}
	inline poly operator+(const poly&rhs){
		static poly ret;
		for(int i=0;i<=k;++i)red(ret.a[i]=a[i]+rhs.a[i]-mo);
		return ret;
	}
	inline poly operator*(const poly&rhs){
		static poly ret;int i,j;
		memset(ret.a,0,k+1<<2);
		for(i=0;i<=k;++i)for(j=0;i+j<=k;++j)ret.a[i+j]=(ret.a[i+j]+1ll*a[i]*rhs.a[j])%mo;
		return ret;
	}
	inline poly ln(){
		static poly ret;int i,j,x;
		for(i=0;i<k;++i){
			x=1ll*(i+1)*a[i+1]%mo;for(j=1;j<=i;++j)x=(x+1ll*a[j]*ret.a[i-j+1]%mo*(mo-(i-j+1)))%mo;
			ret.a[i+1]=1ll*inv[i+1]*x%mo;
		}
		return ret;
	}
	inline poly exp(){
		static poly ret;int i,j,x;ret.a[0]=1;
		for(i=0;i<k;++i){
			x=0;for(j=0;j<=i;++j)x=(x+1ll*ret.a[j]*a[i-j+1]%mo*(i-j+1))%mo;
			ret.a[i+1]=1ll*inv[i+1]*x%mo;
		}
		return ret;
	}
	inline void operator*=(int c){
		for(int i=0;i<=k;++i)a[i]=1ll*a[i]*c%mo;
	}
	inline void operator*=(const poly&rhs){
		*this=*this*rhs;
	}
	inline void operator+=(const poly&rhs){
		*this=*this+rhs;
	}
}A[N],B[N],C[K][N],D[N],I;int ww[K][N],w2[N];
inline void FWT(poly*a,int l){
	int i,j,k,m;poly x,y;
	for(i=2;i<=1<<l;i<<=1)for(j=0,m=i>>1;j<1<<l;j+=i)for(k=0;k<m;++k){
		x=a[j+k];y=a[j+k+m];
		a[j+k]=x+y;a[j+k+m]=x-y;
	}
}
int main(){
	I.a[0]=1;
	for(i=*vf=*fac=1;i<K;++i)
		inv[i]=i==1?1:1ll*(mo-mo/i)*inv[mo%i]%mo,
		vf[i]=1ll*vf[i-1]*inv[i]%mo,
		fac[i]=1ll*fac[i-1]*i%mo;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k>>c;
	for(j=1;j<=n;++j)cin>>a,aa[a]=1;
	for(i=0;i<=c;++i)if(1<<i>k){
		for(j=0;j<k && j<1<<i-1;++j)if(j+(1<<i-1)>=k){
			memset(C[j],0,(sizeof A[0])<<i);
			for(l=0;l<=k;++l)C[j][j+(1<<i-1)-l].a[l]=vf[l];
			FWT(C[j],i);
			for(l=0;l<1<<i;++l)ww[j][l]=C[j][l].a[0]%mo,C[j][l]*=C[j][l].a[0],C[j][l]=C[j][l].ln();
		}
		memcpy(B,A,(sizeof A[0])<<c);
		for(j=0;j<1<<c;j+=1<<i){
			for(l=0;l<1<<i-1;++l)if(bo[j+l] || bo[j+l+(1<<i-1)]){
				bool bb=0;
				if(!bo[j+l])A[j+l]=B[j+l]=I;
				if(!bo[j+l+(1<<i-1)])A[j+l+(1<<i-1)]=B[j+l+(1<<i-1)]=I;
				A[j+l]*=B[j+l+(1<<i-1)],A[j+l+(1<<i-1)]*=B[j+l];
				if(bo[j+l+(1<<i-1)]&1)A[j+l+(1<<i-1)]*=mo-1;
				bo[j+l]+=bo[j+l+(1<<i-1)];bo[j+l+(1<<i-1)]=bo[j+l];
			}
			memset(D,0,(sizeof A[0])<<i);for(l=0;l<1<<i;++l)w2[l]=1;int fl=0;
			for(p=0;p<k && p<1<<i-1;++p)if(p+(1<<i-1)>=k && aa[j+p+(1<<i-1)])
				for(l=0,++fl;l<1<<i;++l)D[l]+=C[p][l],w2[l]=1ll*w2[l]*ww[p][l]%mo;
			if(fl)for(l=0;l<1<<i;++l){
				if(!bo[j+l])A[j+l]=I;bo[j+l]+=fl;
				D[l]=D[l].exp(),D[l]*=w2[l],A[j+l]*=D[l];
			}
		}
	}
	cf=1ll*poww(1<<c,mo-2)*fac[k]%mo*poww(poww(n,k),mo-2)%mo;
	FWT(A,c);
	for(i=0;i<1<<c;++i)cout<<1ll*cf*A[i].a[k]%mo<<' ';cout<<endl;
}