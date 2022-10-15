#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=407;
int n,mod,f[N][N],C[N][N],pw[N];
int main(){
	n=read(),mod=read();
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=n;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=(pw[i-1]<<1)%mod;
	f[0][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			for(int k=1;i+k<=n;k++)
				f[i+k+1][j+k]=(f[i+k+1][j+k]+1ll*f[i][j]*pw[k-1]%mod*C[j+k][k])%mod;
	int ans=0;
	for(int i=0;i<=n;i++)ans=(ans+f[n+1][i])%mod;
	printf("%d\n",ans);
	return 0;
}