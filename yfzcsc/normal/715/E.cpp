#include<bits/stdc++.h>
#define maxn 2010
#define mod 998244353
using namespace std;
int dg[maxn],a[maxn],b[maxn],n,dp[maxn][maxn];
int va[maxn],vb[maxn],v[maxn],vs[maxn],f[maxn],g[maxn],h[maxn];
int A,B,X,C,D,fac[maxn],inv[maxn];
int gmod(int x){return x>=mod?x-mod:x;}
void mul(int a[],int b[],int c[]){
	for(int i=0;i<=n;++i)h[i]=0;
	for(int i=0;i<=n;++i)
		for(int j=0;i+j<=n;++j)
			h[i+j]=(h[i+j]+1ll*a[i]*b[j])%mod;
	for(int i=0;i<=n;++i)c[i]=h[i];
}
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	scanf("%d",&n);
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=1;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]?va[a[i]]=i:0;
	for(int i=1;i<=n;++i)scanf("%d",&b[i]),b[i]?vb[b[i]]=i:0;
	for(int i=1;i<=n;++i)if(a[i]&&b[i])dg[a[i]]++,dg[b[i]]++;
	int N=n,X=0;
	for(int i=1,j;i<=n;++i)if(!vs[i]&&dg[i]==1){
		if(va[i]){
			int x=va[i];
			vs[i]=1;
			while(x){
				int y=b[x];
				vs[y]=1,x=va[y];
			}
		} else {
			int x=vb[i];
			vs[i]=1;
			while(x){
				int y=a[x];
				vs[y]=1,x=vb[y];
			}
		}
	}
	for(int i=1,j;i<=n;++i)if(!vs[i]&&dg[i]==2){
		for(j=i;!vs[j];){
			int nxt=b[va[j]];
			vs[j]=1,j=nxt;
		}
		X++;
	}
	for(int i=1;i<=n;++i)if(va[i]&&vb[i])N--;
	for(int i=1;i<=n;++i)if(((!!va[i])^(!!vb[i]))){
//		printf("[%d]",i);
		if(va[i]){
			int x=va[i];
			while(1){
				int y=b[x];
				if(!y){A++;break;}	
				if(!va[y]){C++;break;}
				x=va[y];
			}
		} else {
			int x=vb[i];
			while(1){
				int y=a[x];
				if(!y){B++;break;}	
				if(!vb[y]){C++;break;}
				x=vb[y];
			}
		}
	}
	C/=2;
	D=N-A-B-C;
	g[X]=1;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=A;++i)
		for(int j=0;j<=i;++j)
			dp[i][j]=((j?dp[i-1][j-1]:0)+1ll*dp[i-1][j]*(A+D-i))%mod;
	mul(dp[A],g,g);
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=B;++i)
		for(int j=0;j<=i;++j)
			dp[i][j]=((j?dp[i-1][j-1]:0)+1ll*dp[i-1][j]*(B+D-i))%mod;
	mul(dp[B],g,g);
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=C;++i)
		for(int j=0,x=D-i+1;j<=i;++j)
			dp[i][j]=((j?1ll*dp[i-1][j-1]*x:0)+1ll*dp[i-1][j]*x*(x-1))%mod;
	mul(dp[C],g,g);
	D-=C;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=D;++i)
		for(int j=0;j<=i;++j)
			dp[i][j]=((j?1ll*dp[i-1][j-1]*i:0)+1ll*dp[i-1][j]*(D-i)*i)%mod;
	mul(dp[D],g,g);
//	printf("{%d,%d,%d,%d}",A,B,C,D);
	for(int i=1;i<=n;++i)printf("%d ",g[n-i+1]);
}