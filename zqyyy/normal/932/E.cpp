#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=5007,mod=1e9+7,inv2=mod+1>>1;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int n,K,s[N][N];
int main(){
	n=read(),K=read(),s[0][0]=1;
	for(int i=1;i<=K;i++)
		for(int j=1;j<=i;j++)
			s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j)%mod;
	int ans=0,res=1,pw=qpow(2,n);
	for(int i=1;i<=K;i++)res=1ll*res*(n-i+1)%mod,pw=1ll*pw*inv2%mod,(ans+=1ll*s[K][i]*res%mod*pw%mod)%=mod;
	return cout<<ans,0;
}