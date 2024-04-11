#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
const int N=105;
int dp[N][N][N];
int P[N],n,x;
char s[N];
void upd(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int main(){
	scanf("%d%d%s",&n,&x,s+1);
	for (int i=1;i<=n;i++) dp[s[i]-'0'][i][i]=1;
	P[0]=P[1]=2;
	for (int i=2;i<=x;i++){
		P[i]=1ll*P[i-1]*P[i-2]%mo;
		for (int l=1;l<=n;l++)
			for (int r=l;r<=n;r++){
				upd(dp[i][l][r],1ll*dp[i-1][l][r]*(r==n?P[i-2]:1)%mo);
				upd(dp[i][l][r],1ll*dp[i-2][l][r]*(l==1?P[i-1]:1)%mo);
				for (int m=l;m<r;m++)
					upd(dp[i][l][r],1ll*dp[i-1][l][m]*dp[i-2][m+1][r]%mo);
			}
	}
	printf("%d\n",dp[x][1][n]);
}