#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=200,mod=1e9+7;
LL dp[M][M];
int tot,n,w[M],k;
LL c[M][M],f[M],t[M][M],g[M];
LL fast(LL x,LL p){
	LL res=1;
	for (;p;p>>=1,x=x*x%mod)
	if (p&1) res=res*x%mod;
	return res;
}
void ms(){
	memset(t,0,sizeof t);
	for (int i=0;i<=tot;i++)
	for (int j=0;j<=tot;j++)
	for (int k=0;k<=tot;k++)
	t[i][j]=(t[i][j]+c[i][k]*c[k][j])%mod;
	memcpy(c,t,sizeof t);
}
void mo(){
	memset(g,0,sizeof g);
	for (int j=0;j<=tot;j++)
	for (int k=0;k<=tot;k++)
	g[j]=(g[j]+f[k]*c[k][j])%mod;
	memcpy(f,g,sizeof g);
}
int main(){
	n=read(); k=read();
	for (int i=1;i<=n;i++) {
		w[i]=read();
		if (!w[i]) ++tot;
	}
	int u=0;
	for (int i=1;i<=tot;i++){
		if (!w[i]) u++;
	}
	for (int j=0;j<=tot;j++){
		if (j-1>=0){
			c[j-1][j]=(tot-j+1)*(tot-j+1);
		}
		c[j][j]=(j*(tot-j)+(n-2*tot+j)*(tot-j)+tot*(tot-1)/2+(n-tot)*(n-tot-1)/2);
		if (j+1<=tot){
			c[j+1][j]=(j+1)*(n-2*tot+j+1);
		}
	}
	f[u]=1;
	for (;k;k>>=1,ms()) if (k&1) mo();
	LL temp=0;
	for (int i=0;i<=tot;i++){
		temp+=f[i];
	}
//	cout<<f[tot]<<" / "<<temp<<"\n";
	temp%=mod;
	cout<<fast(temp,mod-2)*f[tot]%mod<<"\n";
	/*
	for (int i=1;i<=k;i++){
		for (int j=0;j<=tot;j++){
			dp[i][j]=(dp[i][j]+dp[i-1][j-1]*(tot-j+1)*(tot-j+1))%mod;
			dp[i][j]=(dp[i][j]+dp[i-1][j]*(j*(tot-j)+(n-2*tot+j)*(tot-j)+tot*(tot-1)/2+(n-tot)*(n-tot-1)/2))%mod;
			dp[i][j]=(dp[i][j]+dp[i-1][j+1]*(j+1)*(n-2*tot+j+1))%mod;
			cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
		}
	}
	*/
    return 0;
}