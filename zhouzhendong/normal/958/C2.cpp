#include <bits/stdc++.h>
using namespace std;
const int N=20005,K=55,P=105;
int n,m,p,a[N],dp[2][K][P];
int cccc;
int pplus(int a,int b){
	cccc=a+b;
	if (cccc>=p)
		cccc-=p;
	return cccc;
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]%=p;
	for (int i=0;i<K;i++)
		for (int j=0;j<P;j++)
			dp[0][i][j]=dp[1][i][j]=-1e7;
	int T0=1,T1=0;
	dp[0][0][0]=0;
	for (int i=1;i<=n;i++){
		swap(T0,T1);
		for (int j=0;j<m;j++)
			for (int k=0;k<p;k++)
				dp[T1][j][k]=-1e7;
		for (int j=0;j<m;j++)
			for (int k=0;k<p;k++){
				dp[T1][j+1][a[i]]=max(dp[T1][j+1][a[i]],dp[T0][j][k]+k);
				int xxx=pplus(k,a[i]);
				dp[T1][j][xxx]=max(dp[T1][j][xxx],dp[T0][j][k]);
			}
	}
	int ans=0;
	for (int i=0;i<p;i++)
		ans=max(ans,dp[T1][m-1][i]+i);
	printf("%d",ans);
/*	int ans=0,now=0;
	for (int i=1;i<=n;i++){
		if (now+a[i]>=p&&m>1)
			ans+=now,now=a[i],m--;
		else
			now=(now+a[i])%p;
	}
	printf("%d",ans+now);*/
	return 0;
}