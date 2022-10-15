#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=3007,mod=1e9+7;
int n,m,f[N][N];
char str[N][N];
inline void dp(int x,int y){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)f[i][j]=0;
	f[1][1]=1;
	for(int i=x;i<=n;i++)
		for(int j=y;j<=m;j++)
			if(str[i][j]=='.')f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),m=read();
	for(int i=1;i<=n;i++)scanf("%s",str[i]+1);
	dp(1,2);int a=f[n-1][m],b=f[n][m-1];
	dp(2,1);int c=f[n-1][m],d=f[n][m-1];
	int ans=((ll)a*d+mod-(ll)b*c%mod)%mod;
	printf("%d\n",ans);
	return 0;
}