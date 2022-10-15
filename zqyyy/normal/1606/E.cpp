#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=507,mod=998244353;
inline void add(int &x,int y){x=(x+y)%mod;}
int n,x,pw[N][N],f[N][N],C[N][N];
inline void work(){
	n=read(),x=read();
//	if(x==1)puts("1"),exit(0);
	for(int i=0;i<=x;i++){
		pw[i][0]=1;
		for(int j=1;j<=n;j++)pw[i][j]=1ll*pw[i][j-1]*i%mod;
	}
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;	
	}
	for(int i=2;i<=n;i++)
		for(int j=1;j<=min(i-1,x);j++)f[i][j]=(pw[j][i]-pw[j-1][i]+mod)%mod;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=x;j++)
			for(int k=0;k<=n-i;k++)
				if(i+j+k-1<=x)add(f[i+k][i+j+k-1],1ll*f[i][j]*C[i+k][i]%mod*pw[i+k-1][k]%mod);
	int ans=0;
	for(int i=1;i<=x;i++)add(ans,f[n][i]);//,cout<<f[n][i]<<" ";cout<<endl;
	printf("%d\n",ans);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
    int test=1;
    while(test--)work();
    return 0;
}