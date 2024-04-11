#include<bits/stdc++.h>
const int N=3005,mo=998244353;
int n,m,i,j,f[N][N],ans;
char s[N],t[N];
int main(){
	scanf("%s%s",s+1,t+1);n=strlen(s+1);m=strlen(t+1);
	for(i=1;i<=n+1;++i)f[i][i-1]=1;
	for(i=0;i<n;++i)for(j=1;j+i<=n;++j)
		f[j][j+i]=((j>m || s[i+1]==t[j]?f[j+1][j+i]:0)+(j+i>m || s[i+1]==t[j+i]?f[j][j+i-1]:0))%mo;	
	for(i=m;i<=n;++i)ans=(ans+f[1][i])%mo;
	printf("%d\n",ans);
}