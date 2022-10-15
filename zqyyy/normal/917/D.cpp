#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=107,mod=1e9+7;
inline int qpow(int a,int b){
    int res=1;
    for(;b;b>>=1,a=1ll*a*a%mod)
	if(b&1)res=1ll*res*a%mod;
    return res;
}
int n,a[N][N];
bool v[N][N];
struct Matrix{
    int a[N][N];
    int* operator [](int i){return a[i];}
    void Gauss(){
	for(int i=1;i<=n;i++){
	    for(int j=i;j<=n;j++)
		if(a[j][i]){swap(a[i],a[j]);break;}
	    int inv=qpow(a[i][i],mod-2);
	    for(int j=1;j<=n;j++){
		if(i==j)continue;
		int t=1ll*a[j][i]*inv%mod;
		for(int k=i;k<=n+1;k++)a[j][k]=(a[j][k]+1ll*(mod-t)*a[i][k])%mod;
	    }
	}
	for(int i=1;i<=n;i++)printf("%lld\n",1ll*a[i][n+1]*qpow(a[i][i],mod-2)%mod);
    }
}A;
inline int det(){
    int ans=1;bool fl=0;
    for(int i=1;i<n;i++){
	int p=i;
	for(int j=i;j<n;j++)
	    if(a[j][i]){p=j;break;}
	if(!a[p][i])return 0;
	if(i^p)swap(a[p],a[i]),fl^=1;
	int inv=qpow(a[i][i],mod-2);
	for(int j=i+1;j<n;j++){
	    int t=1ll*inv*a[j][i]%mod;
	    for(int k=i;k<n;k++)a[j][k]=(a[j][k]+1ll*a[i][k]*(mod-t))%mod;
	}
	ans=1ll*ans*a[i][i]%mod;
    }
    if(fl)ans=(mod+1-ans)%mod;
    return ans;
}
inline int solve(int x){
    for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)a[i][j]=0;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		int y=v[i][j]?x:1;
		a[i][i]=(a[i][i]+y)%mod;
		a[i][j]=(a[i][j]+mod-y)%mod;
	    }
    return det();
}
int main(){
    n=read();
    for(int i=1;i<n;i++){
	int x=read(),y=read();
	v[x][y]=v[y][x]=1;
    }
    for(int x=1;x<=n;x++){
	int pw=1;
	for(int i=1;i<=n;i++)A[x][i]=pw,pw=1ll*pw*x%mod;
	A[x][n+1]=solve(x);
    }
    A.Gauss();
    return 0;
}