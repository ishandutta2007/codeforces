#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=5005,mod=998244353;
inline int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
int n,m,k,p,pw,val,ans,S[N][N];
int main(){
	n=read(),m=read(),k=read(),p=qpow(m,mod-2);
	pw=val=S[0][0]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=i;j++)
			S[i][j]=(1ll*S[i-1][j]*j%mod+S[i-1][j-1])%mod;
	for(int i=1;i<=k;i++){
		pw=1ll*pw*p%mod,val=1ll*val*(n-i+1)%mod;
		(ans+=1ll*pw*val%mod*S[k][i]%mod)%=mod;
	}
	return cout<<ans,0;
}