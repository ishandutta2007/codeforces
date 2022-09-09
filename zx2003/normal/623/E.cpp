#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
const int N=70005,mo=1000000007;
const double pi=acos(-1.0);
struct comp{
	double x,y;
	comp(double _x=0,double _y=0):x(_x),y(_y){}
	comp operator+(const comp&a)const{
		return comp(x+a.x,y+a.y);
	}
	comp operator-(const comp&a)const{
		return comp(x-a.x,y-a.y);
	}
	comp operator*(const comp&a)const{
		return comp(x*a.x-y*a.y,x*a.y+y*a.x);
	}
};
int n,k,i,j,ans,x,l,mi[N],inv[N],vf[N],fac[N],f[20][N],b[N],c[N];
long long nn;
struct FFT{
	int l,c[N],d[N];
	comp b[N],e[N],f[N],g[N],h[N],o[N],p[N],q[N],w0[20][N],w1[20][N];
	inline void init(int n){
		register int i,j,m,k,z=0;
		for(l=2;l<=n;l<<=1,++z)
			for(i=0;i<l>>1;++i){
				w0[z][i]=comp(cos(2*pi*i/l),sin(2*pi*i/l));
				w1[z][i]=comp(cos(2*pi*i/l),sin(-2*pi*i/l));
			}
		for(i=0;i<l>>1;++i){
			w0[z][i]=comp(cos(2*pi*i/l),sin(2*pi*i/l));
			w1[z][i]=comp(cos(2*pi*i/l),sin(-2*pi*i/l));
		}
		for(i=0;i<l;++i)c[i]=i;
		for(i=l;i>1;i>>=1)
			for(j=0,m=i>>1,memcpy(d,c,l<<2);j<l;j+=i)
				for(k=0;k<m;++k)c[j+k]=d[j+(k<<1)],c[j+k+m]=d[j+(k<<1|1)];
	}
	inline void DFT(comp*a,int key){
		register int i,j,n,k,z=0;memcpy(b,a,l<<4);
		for(i=0;i<l;++i)a[i]=b[c[i]];
		for(i=2;i<=l;i<<=1,++z)
			for(j=0,n=i>>1;j<l;j+=i)
				for(k=0;k<n;++k){
					register comp u=a[j+k],v=a[j+k+n]*(key==1?w0[z][k]:w1[z][k]);
					a[j+k]=u+v;
					a[j+k+n]=u-v;
				}
		if(key==-1)for(i=0;i<l;++i)a[i].x/=l;
	}
	inline void mul(int*a,int*b,int*c){
		register int i;e[0]=f[0]=g[0]=h[0]=comp(0,0);
		for(i=1;i<l;++i){
			e[i]=comp(a[i]>>15,0);
			f[i]=comp(a[i]&32767,0);
			g[i]=comp(b[i]>>15,0);
			h[i]=comp(b[i]&32767,0);
		}
		DFT(e,1),DFT(f,1),DFT(g,1),DFT(h,1);
		for(i=0;i<l;++i){
			o[i]=e[i]*g[i];
			p[i]=e[i]*h[i]+f[i]*g[i];
			q[i]=f[i]*h[i];
		}
		DFT(o,-1),DFT(p,-1),DFT(q,-1);
		for(i=1;i<=k;++i){
			register long long u=o[i].x+0.5,v=p[i].x+0.5,w=q[i].x+0.5;u%=mo,v%=mo,w%=mo;
			c[i]=((u<<30ll)%mo+(v<<15ll)%mo+w)%mo;
		}
	}
}F;
inline int C(int x,int y){
	return 1ll*fac[x]*vf[y]%mo*vf[x-y]%mo;
}
inline int pow(int x,int y){
	register int ans=1,i=x;
	for(;y;y>>=1,i=1ll*i*i%mo)if(y&1)ans=1ll*ans*i%mo;
	return ans;
}
void solve(int d,int l){
	if(l==1){
		for(i=1;i<=k;++i)f[d][i]=1;
		return;
	}
	solve(d+1,l>>1);
	register int i=1;
	for(;i<=k;++i)b[i]=1ll*f[d+1][i]*vf[i]%mo,c[i]=1ll*b[i]*pow(2,(l>>1)*i)%mo;
	F.mul(b,c,f[d]);
	if(l&1){
		for(i=1;i<=k;++i)f[d][i]=1ll*f[d][i]*mi[i]%mo;
		F.mul(f[d],vf,c);
		memcpy(f+d,c,(k+1)<<2);
		for(i=1;i<=k;++i)f[d][i]=1ll*f[d][i]*fac[i]%mo;
	}else for(i=1;i<=k;++i)f[d][i]=1ll*f[d][i]*fac[i]%mo;
}
int main(){
	std::cin>>nn>>k;
	if(nn>k)return puts("0"),0;n=nn;
	F.init(k*2);
	//int tt=clock();
	for(i=*mi=1;i<=k;++i)mi[i]=(mi[i-1]<<1)%mo;
	*fac=fac[1]=*vf=vf[1]=*inv=inv[1]=1;
	for(i=2;i<=k;++i){
		inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
		vf[i]=1ll*vf[i-1]*inv[i]%mo;
		fac[i]=1ll*fac[i-1]*i%mo;
	}
	solve(0,n);
	for(i=n;i<=k;++i)ans=(ans+1ll*C(k,i)*f[0][i]%mo)%mo;
	printf("%d\n",ans);
	//printf("%d\n",tt-(int)clock());
	return 0;
}