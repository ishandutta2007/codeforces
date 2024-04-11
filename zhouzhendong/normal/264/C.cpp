#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
const LL INF=1LL<<56;
LL read(){
	int x;
	scanf("%d",&x);
	return 1LL*x;
}
int n,q,c[N];
LL v[N],dp[N];
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
		v[i]=read();
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	while (q--){
		LL a=read(),b=read();
		LL ans=0;
		int Max=0,Nxt=0;
		for (int i=0;i<=n;i++)
			dp[i]=-INF;
		for (int i=1;i<=n;i++){
			int color=c[i];
			LL now=max(dp[color]+a*v[i],b*v[i]);
			if (color!=Max)
				now=max(now,dp[Max]+b*v[i]);
			else/* if (color!=Nxt)*/
				now=max(now,dp[Nxt]+b*v[i]);
			if (now>dp[Max]){
				if (Max!=color)
					Nxt=Max,Max=color;
			}
			else if (now>dp[Nxt]&&color!=Max)
				Nxt=color;
			dp[color]=max(dp[color],now);
			ans=max(ans,now);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}