#include<stdio.h>
int n,m,s,l,ans=~0;
int main(){
	l=scanf("%d%d",&n,&m)!=0;
	for(int i=1;i<=n||i<=m;i++)l+=(s^=l^=s^=l),l%=1000000007,i==n?ans+=l:0,i==m?ans+=l:0;
	printf("%lld",2ll*ans%1000000007);
}