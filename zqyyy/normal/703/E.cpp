#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1007,M=6727,INF=1e9;
inline ll qmul(ll a,ll b,ll mod){
	return (__int128)a*b%mod;
}
inline ll qpow(ll a,ll b,ll mod){
	ll res=1;
	for(;b;b>>=1,a=qmul(a,a,mod))
		if(b&1)res=qmul(res,a,mod);
	return res;
}
inline bool mr(ll x,ll p){
	for(ll b=x-1;b;b>>=1){
		ll k=qpow(p,b,x);
		if(k!=1 && k!=x-1)return 0;
		if(k==x-1 || (b&1))return 1;
	}
	return 1;
}
inline bool MR(ll x){
	if(x<=1)return 0;
	if(x==2 || x==3 || x==5 || x==7 || x==131 || x==65537)return 1;
	return mr(x,2) && mr(x,3) && mr(x,5) && mr(x,7) && mr(x,131) && mr(x,65537);
}
inline bool isp(ll x){
	if(x<=1)return 0;
	for(ll i=2;i*i<=x;i++)
		if(x%i==0)return 0;
	return 1;
}
int n,cnt,tot,p[15],f[N][M],pre[N][M],k[M][17];
bool v[N][M];
ll K,a[N],b[N],num[M],g[N][M],pw[M][55];
unordered_map<ll,int>id;
inline ll mul(ll x,ll y){
	if(y>=(K+x-1)/x)return K;
	return x*y;
}
inline ll gcd(ll x,ll y){
	int xx=id[x],yy=id[y];ll g=1;
	for(int i=1;i<=cnt;i++)g*=pw[i][min(k[xx][i],k[yy][i])];
	return g;
}
void out(int i,int j){
	if(!i || !j)return;
	if(v[i][j])printf("%d ",i);
	out(i-1,pre[i][j]);
}
int main(){
	n=read(),K=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=__gcd(K,a[i]);
	for(ll i=1;i*i<=K;i++)
		if(K%i==0){
			num[++tot]=i,id[i]=tot;
			if(i*i!=K)num[++tot]=K/i,id[K/i]=tot;
		}
	for(int i=1;i<=tot;i++)
		if(MR(num[i]))p[++cnt]=num[i];
	for(int i=1;i<=tot;i++){
		ll x=num[i];
		for(int j=1;j<=cnt;j++)
			while(x%p[j]==0)x/=p[j],k[i][j]++;
	}
	for(int i=1;i<=cnt;i++){
		pw[i][0]=1;
		for(int j=1;j<=50;j++)pw[i][j]=mul(pw[i][j-1],p[i]);
	}
	for(int i=1;i<=tot;i++)f[0][i]=INF,pre[0][i]=i;
	f[0][1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=tot;j++)f[i][j]=f[i-1][j],g[i][j]=g[i-1][j],pre[i][j]=j;
		for(int j=1;j<=tot;j++){
			if(f[i-1][j]==INF)continue;
			int k=id[mul(num[j],gcd(K/num[j],b[i]))],val=f[i-1][j]+1;ll sum=g[i-1][j]+a[i];
			if(f[i][k]>val || (f[i][k]==val && g[i][k]>sum))v[i][k]=1,f[i][k]=val,g[i][k]=sum,pre[i][k]=j;
		}
	}
	if(f[n][id[K]]>=INF)puts("-1"),exit(0);
	if(!f[n][id[K]]){
		puts("1");int pos=1;
		for(int i=2;i<=n;i++)
			if(a[i]<a[pos])pos=i;
		printf("%d\n",pos);
		return 0;
	}
	printf("%d\n",f[n][id[K]]),out(n,id[K]);
	return 0;
}