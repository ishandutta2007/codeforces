#include<bits/stdc++.h>
const int N=3005,mo=998244353;
inline void add(int&a,const int&b){a+=b-mo;a+=a>>31&mo;}
inline int poww(int x,int y){int ans=1;for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;return ans;}
int n,c,a[N],i,j,k,ans[N],vv[N],iv[N];
namespace T1{
int f[2][N],w[N][N],cn[N],nw;
inline void mai(){
	for(i=n;i;--i){
		int z=c-1,x=1;memset(cn+1,0,c<<2);
		for(j=i-1;j && z;--j)if(a[j]!=a[i])z-=!cn[a[j]],++cn[a[j]];
		if(z)break;
		for(k=1;k<=c;++k)if(k!=a[i])x=1ll*vv[cn[k]]*x%mo;w[i][j]=x;
		for(;j;){
			if(a[j]!=a[i])x=1ll*x*iv[cn[a[j]]]%mo,x=1ll*x*vv[++cn[a[j]]]%mo;
			w[i][--j]=x;
		}
	}
	f[0][0]=1;
	for(k=1;;++k){
		nw^=1;memset(f[nw],0,n+1<<2);
		for(i=1;i<=n;++i){
			for(j=i-1;j-7>=0;j-=8)
				f[nw][i]=(f[nw][i]+
				1ll*f[!nw][j]*w[i][j]+
				1ll*f[!nw][j-1]*w[i][j-1]+
				1ll*f[!nw][j-2]*w[i][j-2]+
				1ll*f[!nw][j-3]*w[i][j-3]+
				1ll*f[!nw][j-4]*w[i][j-4]+
				1ll*f[!nw][j-5]*w[i][j-5]+
				1ll*f[!nw][j-6]*w[i][j-6]+
				1ll*f[!nw][j-7]*w[i][j-7])%mo;
			for(;j>=0;--j)f[nw][i]=(f[nw][i]+1ll*f[!nw][j]*w[i][j])%mo;
			ans[k]=(ans[k]+1ll*f[nw][i]*(vv[n-i]+1))%mo;
		}
		if(!ans[k])break;
	}
}
}
namespace T2{
int f[2][N],nw,g[N][519];
inline void mai(){
	f[0][0]=1;
	for(k=1;;++k){
		g[0][0]=f[nw][0];nw^=1;memset(f[nw],0,n+1<<2);
		for(i=0;i<n;++i){
			memcpy(g[i+1],g[i],4<<c);add(g[i+1][0],f[!nw][i+1]);
			for(j=0;j+1<1<<c;++j){
				int s=j|1<<a[i+1]-1;
				add(s+1==1<<c?f[nw][i+1]:g[i+1][s],g[i][j]);
			}
		}
		for(i=1;i<=n;++i)ans[k]=(ans[k]+1ll*f[nw][i]*(vv[n-i]+1))%mo;
		if(!ans[k])break;
	}
}
}
int main(){
	vv[1]=iv[1]=1;for(i=2;i<N;++i)vv[i]=(2*vv[i-1]+1)%mo,iv[i]=poww(vv[i],mo-2);
	scanf("%d%d",&n,&c);for(i=1;i<=n;++i)scanf("%d",a+i);ans[0]=vv[n];
	if(c<=9)T2::mai();else T1::mai();
	for(i=0;i<=n;++i)add(ans[i],mo-ans[i+1]),printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}