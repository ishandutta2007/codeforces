#include <bits/stdc++.h>
using namespace std;
const int N=10005,mod=1e9+7;
int n,x,y;
char s[5][N];
int check(int dx,int dy){
	for (int i=1;i<=2;i++)
		if (s[x+dx*i][y+dy*i]!='.')
			return 0;
	return 1;
}
void cover(int dx,int dy){
	for (int i=1;i<=2;i++)
		s[x+dx*i][y+dy*i]='*';
}
void uncover(int dx,int dy){
	for (int i=1;i<=2;i++)
		s[x+dx*i][y+dy*i]='.';
}
int dp[N][8];
int solve(){
	memset(dp,0,sizeof dp);
	dp[0][7]=1;
	for (int i=1;i<=n;i++){
		int k=0;
		for (int x=1;x<=3;x++)
			k|=(s[x][i]!='.')<<(x-1);
		for (int j=0;j<8;j++){
			if (j&k)
				continue;
			int _j=j|k;
			dp[i][_j]=dp[i-1][j^7];
			if (j==3||j==6)//001 100
				dp[i][_j]=(1LL*dp[i][_j]+dp[i-1][7])%mod;
			else if (j==7)//111
				dp[i][_j]=(1LL*dp[i][_j]+dp[i-1][6]+dp[i-1][3])%mod;
		}
	}
	return dp[n][7];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=3;i++)
		scanf("%s",s[i]+1);
	for (int i=1;i<=3;i++)
		for (int j=1;j<=n;j++)
			if (s[i][j]=='O')
				x=i,y=j;
	if (x==3)
		swap(s[1],s[3]),x=1;
	int ans=0;
	#define A 1,0
	#define B 0,1
	#define C 0,-1
	#define ck check
	#define cv cover
	#define uc uncover
	#define up ans=(ans+solve())%mod
	#define um ans=(ans-solve())%mod
	if (ck(A))
		cv(A),up,uc(A);
	if (ck(B))
		cv(B),up,uc(B);
	if (ck(C))
		cv(C),up,uc(C);
	if (ck(A)*ck(B))
		cv(A),cv(B),um,uc(A),uc(B);
	if (ck(A)*ck(C))
		cv(A),cv(C),um,uc(A),uc(C);
	if (ck(C)*ck(B))
		cv(C),cv(B),um,uc(C),uc(B);
	if (ck(A)*ck(B)*ck(C))
		cv(A),cv(B),cv(C),up,uc(A),uc(B),uc(C);
	printf("%d",(ans+mod)%mod);
	return 0;
}