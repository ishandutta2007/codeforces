#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
const int N=5005;
int n,k,a[N],dp[2][N/2][3];
// 0 : normal
// 1 :  
// 2 :  
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	k=(n+1)/2;
	int T1=1,T0=0;
	memset(dp[T1],63,sizeof dp[T1]);
	dp[T1][0][0]=0;
	dp[T1][1][2]=0;
	for (int i=2;i<=n;i++){
		T0^=1,T1^=1;
		memset(dp[T1],63,sizeof dp[T1]);
		// 0  =  dp[0]=min(dp[1],dp[0])
		// 1  =  dp[1]=dp[2]+max(0,a[i]-a[i-1]+1)
		// 2  =  dp[2]=min(dp[0]+max(0,a[i-1]-a[i]+1),
		//				   dp[1]+max(0,min(a[i-2]-1,a[i-1])-a[i]+1)
		//					)
		int A=max(0,a[i]-a[i-1]+1);
		int B=max(0,a[i-1]-a[i]+1);
		int C=max(0,min(a[i-2]-1,a[i-1])-a[i]+1);
		for (int j=0;j<=k;j++){
			int v0=dp[T0][j][0],v1=dp[T0][j][1];
			dp[T1][j][0]=min(v0,v1);
			dp[T1][j][1]=dp[T0][j][2]+A;
			dp[T1][j+1][2]=min(v0+B,v1+C);
		}
	}
	for (int i=1;i<=k;i++)
		printf("%d ",min(min(dp[T1][i][0],dp[T1][i][1]),dp[T1][i][2]));
	return 0;
}