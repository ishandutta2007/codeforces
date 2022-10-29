#include<bits/stdc++.h>
#define maxn 501000
using namespace std;
int n,m,q,wn[20],f[1<<12],dp[1<<12],anses[1<<12][110];
char S[100],T[100]; 
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;++i)
		scanf("%d",&wn[i]);
	for(int i=1;i<=m;++i){
		scanf("%s",S);
		int ss=0;
		for(int j=0;j<n;++j)
			ss|=S[j]-'0'<<j;
		f[ss]++;
	}
	for(int s=1;s<(1<<n);++s)
		dp[s]=wn[__builtin_ctz(s)]+dp[s^(s&-s)];
	for(int s=0;s<(1<<n);++s){
		for(int t=0;t<(1<<n);++t){
			int sum=dp[s^((~t)&(1<<n)-1)];
			if(sum<=100)anses[s][sum]+=f[t];
		}
		for(int t=1;t<=100;++t)anses[s][t]+=anses[s][t-1];
	}
	for(int i=1,k;i<=q;++i){
		scanf("%s%d",S,&k);
		int ss=0;
		for(int j=0;j<n;++j)
			ss|=S[j]-'0'<<j;
		printf("%d\n",anses[ss][k]);
	}
}