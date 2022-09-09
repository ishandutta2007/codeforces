#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=27e4,V=20;
int n,i,j,k,mu[N],cnt[N];
ll f[N][V],g[V][N],h[V][N],ff[N],fff[N];
char c[V][V];
inline void FMT(ll*a,int n){
	int i,j,k,m;
	for(i=2;i<=1<<n;i<<=1)for(j=0,m=i>>1;j<1<<n;j+=i)
		for(k=0;k<m;++k)a[j+k+m]+=a[j+k];
}
inline void UFMT(ll*a,int n){
	int i,j,k,m;
	for(i=2;i<=1<<n;i<<=1)for(j=0,m=i>>1;j<1<<n;j+=i)
		for(k=0;k<m;++k)a[j+k]-=a[j+k+m];
}
inline ll calc(ll*a,int n){
	ll tot=0;
	for(int i=0;i<1<<n;++i)tot+=mu[i]*a[i];
	return tot;
}
inline void getf(){
	for(i=0;i<n;++i)f[1<<i][i]=1;
	for(i=1;i<1<<n;++i)for(j=0;j<n;++j)if(i>>j&1)
		for(k=0;k<n;++k)if(c[j][k]=='1' && !(i>>k&1))f[i|(1<<k)][k]+=f[i][j];
}
inline void getg(){
	for(i=1;i<1<<n;++i)for(j=0;j<n;++j)g[cnt[i]][i]+=f[i][j];
	for(i=1;i<=n;++i)FMT(g[i],n);
}
int aa[V],xb;
void dfs(int d,int s){
	int oxb=xb;
	if(d==1){
		static ll hh[N];memcpy(hh,h[d],8<<n);
		for(;s--;){
			for(int j=0;j<1<<n;++j)hh[j]*=g[d][j];
			aa[++xb]=1;
		}
		int s1=0,s2=0;for(int i=xb;i>1;--i)s1+=aa[i],s2|=1<<s1-1;
		ff[s2]+=calc(hh,n);
		xb=oxb;
		return;
	}
	memcpy(h[d-1],h[d],8<<n);
	for(int i=0;;){
		dfs(d-1,s-i*d);
		++i;if(s<i*d)break;
		aa[++xb]=d;
		for(int j=0;j<1<<n;++j)h[d-1][j]*=g[d][j];
	}
	xb=oxb;
}
int main(){
	for(i=1;i<N;++i)cnt[i]=cnt[i>>1]+(i&1);
	scanf("%d",&n);
	for(i=0;i<1<<n;++i)mu[i]=n-cnt[i]&1?-1:1;
	for(i=0;i<n;++i)scanf("%s",c[i]);
	getf();getg();
	h[n][0]=1;FMT(h[n],n);
	dfs(n,n);
	for(i=0;i<1<<n-1;++i){
		xb=0;
		for(j=0;j<n-1;++j)if(!(i>>j&1))aa[++xb]=j+1;aa[++xb]=n;
		for(j=xb;j;--j)aa[j]-=aa[j-1];
		std::sort(aa+1,aa+xb+1);
		int s1=0,s2=0;for(int i=1;i<xb;++i)s1+=aa[i],s2|=1<<s1-1;
		fff[i]=ff[s2];
	}
	UFMT(fff,n-1);
	for(i=0;i<1<<n-1;++i)printf("%llu%c",fff[i],i+1==1<<n-1?'\n':' ');
}