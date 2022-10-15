#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1007,mod=1e9+7;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int K,pa,pb,f[N<<1][N<<1];
int A,B,C;
int main(){
	K=read(),pa=read(),pb=read();
	A=1ll*pa*qpow(pa+pb,mod-2)%mod,B=(1-A+mod)%mod,C=1ll*pa*qpow(pb,mod-2)%mod;
	for(int i=K;i;i--)
		for(int j=K;~j;j--)
			f[i][j]=i+j>=K?(i+j+C)%mod:(1ll*A*f[i+1][j]%mod+1ll*B*f[i][j+i]%mod)%mod;
	return cout<<f[1][0],0;
}