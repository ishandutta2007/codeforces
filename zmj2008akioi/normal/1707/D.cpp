#include <cstdio>
#include <vector>
typedef long long LL;
const int N=4e3+10;
int n,P,dnt,prd[N],nprd[N],inv[N],head[N],to[N],next[N],dp[N][N],ds[N][N],ivs[N][N];bool vis[N];
namespace IO{
	int lt,nw,res,dig[30];char c;
	int read(){
		res=0;for(;c<'0'||c>'9';c=getchar());
		for(;!(c<'0'||c>'9');c=getchar())res=(res<<1)+(res<<3)+(c^48);
		return res;
	}
	void write(int x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);putchar(' ');
	}
}using IO::read;using IO::write;
int C(int n,int m){return (LL)prd[n]*inv[m]%P*inv[n-m]%P;}
void ad(int u,int v){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v;}
int qpow(int b,int p){
	int pw=1,rs=1,nw=b,rm=p;
	for(;rm;pw<<=1,nw=(LL)nw*nw%P)if(rm&pw)rm^=pw,rs=(LL)rs*nw%P;
	return rs;
}
void ginv(int *a,int *iv){
	nprd[0]=1;for(int i=1;i<n;++i)nprd[i]=(LL)nprd[i-1]*(a[i]?a[i]:1)%P;
	for(int i=n-1,niv=qpow(nprd[n-1],P-2);i;--i)if(a[i])iv[i]=(LL)niv*nprd[i-1]%P,niv=(LL)niv*a[i]%P;
}
void dfs(int u){
	vis[u]=true;int c[N],rat[N];
	for(int i=1;i<n;++i)c[i]=0,rat[i]=1;
	for(int i=head[u];i;i=next[i]){
		if(vis[to[i]])continue;dfs(to[i]);
		for(int j=1;j<n;++j){
			if(ds[to[i]][j])rat[j]=(LL)rat[j]*ds[to[i]][j]%P;
			else ++c[j];
		}
	}
	for(int i=1;i<n;++i)dp[u][i]=rat[i]*(!c[i]);if(u==1)return;
	for(int i=head[u];i;i=next[i]){
		if(vis[to[i]])continue;
		for(int ns=0,j=2;j<n;++j){
			if(!c[j-1])ns=(ns+(LL)rat[j-1]*ivs[to[i]][j-1])%P;
			else if(c[j-1]==1&&!ds[to[i]][j-1])ns=(ns+rat[j-1])%P;
			dp[u][j]=(dp[u][j]+(LL)ns*dp[to[i]][j])%P;
		}
	}
	for(int i=1;i<n;++i)ds[u][i]=(ds[u][i-1]+dp[u][i])%P;
	ginv(ds[u],ivs[u]),vis[u]=false;
}
int main(){
	n=read(),P=read(),prd[0]=1;
	for(int i=1;i<n;++i)prd[i]=(LL)prd[i-1]*i%P;ginv(prd,inv);
	for(int u,v,i=1;i<n;++i)u=read(),v=read(),ad(u,v),ad(v,u);dfs(1);
	for(int i=1;i<n;++i){
		for(int j=1;j<i;++j)dp[1][i]=(dp[1][i]+P-(LL)dp[1][j]*C(i,j)%P)%P;
		write(dp[1][i]);
	}
	return 0;
}