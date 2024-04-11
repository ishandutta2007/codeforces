#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo=998244353,N=2e5+5,M=59,S=32771;
inline int poww(int x,int y){int ans=1;for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;return ans;}
int n,m,i,j,k,mi[N],C[M][M],ct[M];ll a[M],x,val[2][S];
bool bb[M];
vector<ll>ve;
inline void solve1(){
	int p1=0,p2=min(15,(int)ve.size()),p3=ve.size();
	for(i=0;i<1<<p2-p1;++i)for(j=0;j<p2-p1;++j)if(i>>j&1)val[0][i]^=ve[j];
	for(i=0;i<1<<p3-p2;++i)for(j=0;j<p3-p2;++j)if(i>>j&1)val[1][i]^=ve[j+p2];
	int s1=(1<<p2)-1,s2=((1<<p3)-1)^s1;
	for(i=0;i<1<<p3;++i)++ct[__builtin_popcountll(val[0][i&s1]^val[1][(i&s2)>>p2])];
}
inline void FWT(int*a,int l){
	int i,j,k,m,x,y;
	for(i=2;i<=1<<l;i<<=1)for(j=0,m=i>>1;j<1<<l;j+=i)
		for(k=0;k<m;++k)x=a[j+k],y=a[j+k+m],a[j+k]=(x+y)%mo,a[j+k+m]=(x+mo-y)%mo;
}
int f[40][N],g[N],id[M],cnt[N];int xb=0,zz=0;
inline void solve2(){
	for(i=0;i<m;++i)if(!bb[i])id[i]=xb++;
	f[0][0]=1;FWT(f[0],xb);
	for(i=0;i<m;++i)if(a[i]){
		int x=0;for(j=0;j<m;++j)if((a[i]>>j&1) && !bb[j])x|=1<<id[j];
		memset(g,0,4<<xb);g[x]=1;FWT(g,xb);
		++zz;for(j=zz;j;--j)for(k=0;k<1<<xb;++k)f[j][k]=(f[j][k]+1ll*g[k]*f[j-1][k])%mo;
	}
	for(i=1;i<N;++i)cnt[i]=cnt[i>>1]+(i&1);
	int invl=poww(1<<xb,mo-2);
	for(i=0;i<=zz;++i){
		FWT(f[i],xb);
		for(j=0;j<1<<xb;++j)f[i][j]=1ll*f[i][j]*invl%mo;
		for(j=0;j<1<<xb;++j)ct[cnt[j]+i]=(ct[cnt[j]+i]+f[i][j])%mo;
	}
}
int main(){
//	freopen("1","r",stdin);
	for(i=**C=1;i<M;++i)for(j=*C[i]=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	for(i=*mi=1;i<N;++i)mi[i]=2*mi[i-1]%mo;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%lld",&x);
		for(j=m-1;j>=0;--j)if(x>>j&1){if(!a[j]){a[j]=x;break;}x^=a[j];}
	}
	for(i=0;i<m;++i)if(a[i])for(j=i+1;j<m;++j)if(a[j]>>i&1)a[j]^=a[i];
	for(i=0;i<m;++i)if(a[i])ve.push_back(a[i]),bb[i]=1;
	if(ve.size()<=18)solve1();else solve2();
	for(i=0;i<=m;++i)ct[i]=1ll*ct[i]*mi[n-ve.size()]%mo;
	for(i=0;i<=m;++i)printf("%d%c",ct[i],i==m?'\n':' ');
}