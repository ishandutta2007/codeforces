#include<bits/stdc++.h>
const int N=21,mo=998244353,S=27e4;
int g[N][S],h[S][N],f[S][N],n,m,i,j,a,b,z,cnt[S],val[N],inv[N],ans,C[N][N];
bool bb[N][N];
inline void FMT(int*a){
	for(int i=2,j,k,m;i<=1<<n;i<<=1)
		for(j=0,m=i>>1;j<1<<n;j+=i)
			for(k=0;k<m;++k)a[j+k+m]+=a[j+k];
}
inline void mul(int*a,int*b){
	static unsigned long long c[N];int i,j;memset(c,0,sizeof c);
	for(i=0;i<=n;++i)for(j=0;j<=n-i;++j)c[i+j]+=1ull*a[i]*b[j];
	for(i=0;i<=n;++i)a[i]=c[i]%mo;
}
int main(){
	for(i=1;i<S;++i)cnt[i]=cnt[i>>1]+(i&1);for(i=2,inv[1]=1;i<N;++i)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	for(i=**C=1;i<N;++i)for(j=*C[i]=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;++i)scanf("%d%d",&a,&b),bb[a][b]=bb[b][a]=1;
	for(i=1;i<1<<n;++i){
		z=0;
		for(a=0;a<n;++a)if(i>>a&1)for(b=0;b<n;++b)z+=(i>>b&1) && bb[a+1][b+1];
		if(!z)g[cnt[i]][i]=1;
	}
	for(i=0;i<=n;++i)for(FMT(g[i]),j=0;j<1<<n;++j)f[j][i]=g[i][j];
	memcpy(h,f,sizeof f);
	for(i=1;i<=n+1;++i){
		for(j=0;j<1<<n;++j,val[i]+=val[i]>>31&mo)if((n-cnt[j])&1)val[i]-=h[j][n];else val[i]+=h[j][n]-mo;
		for(j=0;j<1<<n;++j)mul(h[j],f[j]);
	}
	for(i=1;i<=n+1;++i,ans=(ans+a)%mo){
		for(a=0,j=1;j<=i;++j)a=(a+1ll*C[i][j]*val[j])%mo;
		for(j=1;j<=n+1;++j)if(i!=j)a=1ll*(j<i?mo-inv[i-j]:inv[j-i])*(j+1)%mo*a%mo;
	}
	if(n&1)ans=mo-ans;
	ans=1ll*ans*inv[2]%mo*m%mo;
	printf("%d\n",ans);
	return 0;
}