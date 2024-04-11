#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ctod(c) ((c)<='9'?(c)-'0':(c)-'a'+10)
#define dtoc(c) ((c)<10?'0'+(c):'a'+(c)-10)
char s[15];
int n,tot,d[15];
int sum[(1<<13)+233];
int bit[(1<<13)+233];
ll dp[(1<<13)+233];
int tg[(1<<13)+233];
ll ans=8e18;
void solve(int T){
	sum[0]=d[n-1];
	for (int i=1;i<(1<<(n-1));i++)
		sum[i]=sum[i-(i&(-i))]+d[bit[i&(-i)]];
	dp[0]=0; tg[0]=T;
	if (sum[0]<0||sum[0]>15) return;
	for (int i=1;i<(1<<(n-1));i++){
		if (sum[i]<0||sum[i]>15) continue;
		dp[i]=8e18; tg[i]=T;
		for (int j=0;j<n;j++)
			if (((i>>j)&1)&&tg[i-(1<<j)]==T)
				dp[i]=min(dp[i],dp[i-(1<<j)]+((1ll*sum[i-(1<<j)])<<(j<<2)));
	}
	if (tg[(1<<(n-1))-1]==T)
		ans=min(ans,dp[(1<<(n-1))-1]);
}
void dfs(int x,int cnt){
	if (x==n-1){
		if (!cnt) solve(++tot);
		return;
	}
	dfs(x+1,cnt);
	if (cnt){
		d[x]-=16; d[x+1]++;
		dfs(x+1,cnt-1);
		d[x]+=16; d[x+1]--;
	}
}
int main(){
	for (int i=0;i<=13;i++)
		bit[1<<i]=i;
	scanf("%s",s);
	n=strlen(s);
	int cnt=0;
	for (int i=0;i<n;i++)
		cnt+=(d[i]=ctod(s[n-i-1]));
	if (cnt%15)
		return puts("NO"),0;
	dfs(0,cnt/=15);
	if (ans>7e18) puts("NO");
	else
		for (int i=n-1;i>=0;i--)
			putchar(dtoc((ans>>(i<<2))&15));
}