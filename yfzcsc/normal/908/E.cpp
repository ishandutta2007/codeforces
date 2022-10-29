#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
char s[60][1010];
int n,g[1010],f[1010],c[10000],C[1010][1010],m;
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;++i)
		for(int j=*C[i]=1;j<=i;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	g[0]=1;
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			g[i]=(g[i]+1ll*g[i-j]*C[i-1][j-1])%mod;
	for(int i=1;i<=m;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)if(find(i)!=find(j)){
			for(int k=1;k<=m;++k)if(s[k][i]!=s[k][j])goto nxt;
			f[find(i)]=find(j);
			nxt:;
		}
	int ans=1;
	for(int i=1;i<=n;++i)c[find(i)]++;
	for(int i=1;i<=n;++i)if(find(i)==i)ans=1ll*ans*g[c[i]]%mod;
	printf("%d",ans);
}