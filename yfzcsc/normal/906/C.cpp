#include<bits/stdc++.h>
using namespace std;
struct data{
	int pre,man,dp;
	data(){}
	data(int pre,int man,int dp):pre(pre),man(man),dp(dp){}
	int operator<(const data& d)const{return dp<d.dp;} 
}dp[1<<22];
int g[30],n,m;
int main(){
	scanf("%d%d",&n,&m);
	if(m==n*(n-1)/2)return puts("0"),0;
	for(int i=1;i<=n;++i)
		g[i]=1<<i-1;
	for(int i=0;i<(1<<n);++i)dp[i].dp=1<<30;
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),g[u]|=1<<v-1,g[v]|=1<<u-1,dp[(1<<u-1)|(1<<v-1)]=data(0,0,0);
	for(int i=1;i<=n;++i)dp[1<<i-1]=data(0,0,0);
	for(int i=1;i<(1<<n);++i)
		for(int j=1;j<=n;++j)if(i&(1<<j-1)){
			data d(i,j,dp[i].dp+1); 
			dp[i|g[j]]=min(d,dp[i|g[j]]);
		}
	printf("%d\n",dp[(1<<n)-1].dp);
	for(int i=(1<<n)-1;dp[i].man;i=dp[i].pre)
		printf("%d ",dp[i].man);
}