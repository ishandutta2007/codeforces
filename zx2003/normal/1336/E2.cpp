#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo=998244353,N=2e5+5,M=59,S=32771;
inline int poww(int x,int y){int ans=1;for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;return ans;}
int n,m,i,j,k,mi[N],C[M][M],ct[M];ll a[M],x,val[2][S];
vector<ll>ve;
bool bb[M];
inline void solve1(vector<ll>ve){
	int p1=0,p2=min(15,(int)ve.size()),p3=ve.size();
	for(i=0;i<1<<p2-p1;++i)for(j=0;j<p2-p1;++j)if(i>>j&1)val[0][i]^=ve[j];
	for(i=0;i<1<<p3-p2;++i)for(j=0;j<p3-p2;++j)if(i>>j&1)val[1][i]^=ve[j+p2];
	int s1=(1<<p2)-1,s2=((1<<p3)-1)^s1;
	for(i=0;i<1<<p3;++i)++ct[__builtin_popcountll(val[0][i&s1]^val[1][(i&s2)>>p2])];
}
int id[M],xb;
inline void solve2(){
	for(i=0;i<m;++i)if(!bb[i])id[xb++]=i;
	vector<ll>v2;
	for(i=0;i<xb;++i){
		ll x=1<<i;
		for(j=0;j<ve.size();++j)if(ve[j]>>id[i]&1)x|=1ll<<j+xb;
		v2.push_back(x);
	}
	solve1(v2);
	static int cc[M],dd[M];
	for(i=0;i<=m;++i)dd[i]=((ll)ct[i]<<ve.size())%mo;
	for(i=0;i<=m;++i)for(j=0;j<=m;++j)for(k=0;k<=i;++k)
		if(k<=j && i-k<=m-j)cc[i]=(cc[i]+1ll*C[j][k]*C[m-j][i-k]%mo*(k&1?mo-dd[j]:dd[j]))%mo;
	for(i=0;i<=m;++i)cc[i]=1ll*cc[i]*poww((1ll<<m)%mo,mo-2)%mo;
	memcpy(ct,cc,sizeof cc);
}
int main(){
	for(i=**C=1;i<M;++i)for(j=*C[i]=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	for(i=*mi=1;i<N;++i)mi[i]=2*mi[i-1]%mo;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%lld",&x);
		for(j=m-1;j>=0;--j)if(x>>j&1){if(!a[j]){a[j]=x;break;}x^=a[j];}
	}
	for(i=0;i<m;++i)if(a[i])for(j=i+1;j<m;++j)if(a[j]>>i&1)a[j]^=a[i];
	for(i=0;i<m;++i)if(a[i])ve.push_back(a[i]),bb[i]=1;
	if(ve.size()<=26)solve1(ve);else solve2();
	for(i=0;i<=m;++i)ct[i]=1ll*ct[i]*mi[n-ve.size()]%mo;
	for(i=0;i<=m;++i)printf("%d%c",ct[i],i==m?'\n':' ');
}