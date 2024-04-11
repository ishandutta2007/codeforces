#include<stdio.h>
#define mod 998244353
char c[4002],d[4002];
int n,m,f[4002][4002],ans=0;
int main(){
	scanf("%s%s",c+1,d+1);
	for(n=1;c[n];n++);n--;
	for(m=1;d[m];m++);m--;
	for(int i=1;i<=n;i++)if(d[i]==c[1]||!d[i])f[i][i]=2;
	if(m==1)ans+=f[1][1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(c[i]==d[j]||!d[j])f[j][j+i-1]+=f[j+1][j+i-1];
			if(c[i]==d[j+i-1]||!d[j+i-1])f[j][j+i-1]+=f[j][j+i-2];
			if(f[j][j+i-1]>=mod)f[j][j+i-1]-=mod;
		}if(i>=m)ans+=f[1][i],ans-=ans>=mod?mod:0;
	}printf("%d",ans);
}