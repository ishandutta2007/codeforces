#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
char s[maxn],vs[100];
int lstp[100],a[100];
int Q,g[maxn],f[maxn][30],nxt[maxn][30],pre[maxn][30],n,dp[50];
// f[l][a]: [l,nxt[l][a])
int cal(int l,int r,int c,int tg){
	if(l>r)return 0;
	if(~dp[c])return dp[c];
//	printf("{%d,%d(%d[%d,%d])}",l,r,c,nxt[l][0],pre[r][0]);
	int st=0;
	
	for(int i=0;i<26;++i){
		int _l=nxt[l][i],_r=pre[r][i];
		if(_l<r)st|=1<<((tg?f[l][i]:cal(l,_l,i,0))^g[_l]^g[_r]^(!tg?f[_r+1][c]:cal(_r+1,r,i,1)));
	}
	return dp[c]=__builtin_ctz(~st);
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int j=n+1;j>=0;--j)
		for(int i=0;i<26;++i)
			nxt[j][i]=(s[j]=='a'+i||j>n?j:nxt[j+1][i]);
	for(int j=0;j<=n+1;++j)
		for(int i=0;i<26;++i)
			pre[j][i]=(s[j]=='a'+i||j<1?j:pre[j-1][i]);
	for(int i=n;i>=1;--i){
		memset(dp,-1,sizeof(dp));
		g[i]=f[i+1][s[i]-'a']^g[nxt[i+1][s[i]-'a']];
		for(int j=0;j<26;++j)
			f[i][j]=cal(i,nxt[i][j],j,0);
	}
	scanf("%d",&Q);
	for(int i=1,l,r;i<=Q;++i){
		scanf("%d%d",&l,&r);
		memset(dp,-1,sizeof(dp));
		if(cal(l,r+1,26,1))puts("Alice");
		else puts("Bob");
	}
}