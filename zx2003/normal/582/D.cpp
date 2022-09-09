#include<bits/stdc++.h>
const int N=4000,mo=1e9+7;
int p,b,a[N],i,j,k,l,f[N][N][2][2],w,v[N],ans;
char c[N];
inline int C2(int x){return x>0?(1ll*x*(x+1)>>1)%mo:0;}
int main(){
	scanf("%d%d%s",&p,&b,c+1);
	l=strlen(c+1);for(i=1;i<=l;++i)a[i]=c[l-i+1]-'0';
	for(;l;){
		++w;
		long long t=0;
		for(i=l;i;--i){
			v[w]=(10ll*v[w]+a[i])%p;
			t=10*t+a[i];a[i]=t/p;t-=1ll*a[i]*p;
		}
		for(;l && !a[l];--l);
	}
	f[0][0][1][1]=1;
	for(i=0;i<w;++i)for(j=0;j<=i;++j){
		f[i+1][j+1][0][0]=(
			1ll*f[i][j][0][0]*C2(p-v[i+1])+
			1ll*(f[i][j][0][1]+f[i][j][1][0])*C2(p-v[i+1]-1)+
			1ll*f[i][j][1][1]*C2(p-v[i+1]-2))%mo;
		f[i+1][j+1][0][1]=(
			1ll*f[i][j][0][0]*(v[i+1]>=1?C2(p)+mo-C2(p-v[i+1]):0)+
			1ll*f[i][j][0][1]*(v[i+1]>=-1?C2(p)+mo-C2(p-v[i+1]-1):0)+
			1ll*f[i][j][1][0]*(v[i+1]>=-1?C2(p-1)+mo-C2(p-v[i+1]-1):0)+
			1ll*f[i][j][1][1]*(v[i+1]>=-2?C2(p-1)+mo-C2(p-v[i+1]-2):0))%mo;
		f[i+1][j][1][0]=(
			1ll*f[i][j][0][0]*(p>=v[i+1]?C2(p-1)+mo-C2(v[i+1]-1):0)+
			1ll*f[i][j][0][1]*(p>=v[i+1]+1?C2(p-1)+mo-C2(v[i+1]):0)+
			1ll*f[i][j][1][0]*(p>=v[i+1]?C2(p)+mo-C2(v[i+1]):0)+
			1ll*f[i][j][1][1]*(p>=v[i+1]+1?C2(p)+mo-C2(v[i+1]+1):0))%mo;
		f[i+1][j][1][1]=(
			1ll*f[i][j][0][0]*C2(v[i+1]-1)+
			1ll*(f[i][j][0][1]+f[i][j][1][0])*C2(v[i+1])+
			1ll*f[i][j][1][1]*C2(v[i+1]+1))%mo;
	}
	for(i=b;i<=w;++i)ans=(ans+f[w][i][1][1])%mo;
	printf("%d\n",ans);
	return 0;
}