#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int mod=1e9+7,inv2=(mod+1)>>1;
int n,m,K,f[2007][2007];
inline void work(){
	n=read(),n-=m=read(),K=read();
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++){
			if(!j)f[i][j]=0;
			else if(!i)f[i][j]=j;
			else f[i][j]=1ll*(f[i-1][j]+f[i][j-1])*inv2%mod;
		}
	printf("%lld\n",1ll*f[n][m]*K%mod);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work();
	return 0;
}