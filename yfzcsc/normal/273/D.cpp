#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=160;
int dp[N][N][N][2][2],s[2][2][N][N],n,m;
void upd(int& x,int y){
	x=(x+y)%mod;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		for(int j=i;j<=m;++j)
			dp[1][i][j][0][0]=1;
	for(int i=2;i<=n;++i){
		memset(s,0,sizeof(s));
		for(int a=0;a<2;++a)
			for(int b=0;b<2;++b)
				for(int j=1;j<=m;++j)
					for(int k=1;k<=m;++k)
						s[a][b][j][k]=(1ll*s[a][b][j-1][k]+s[a][b][j][k-1]-s[a][b][j-1][k-1]+dp[i-1][j][k][a][b])%mod;
		for(int a=0;a<2;++a)
			for(int b=0;b<2;++b)
				for(int l=1;l<=m;++l)
					for(int r=l;r<=m;++r){
//						if(a==1&&r>k)continue;
//						if(b==1&&l<j)continue;
						function<int(int,int,int,int)> qry=[&](int lx,int rx,int ly,int ry){
							if(lx>rx||ly>ry)return 0;
							int ret=(1ll*s[a][b][rx][ry]-(lx?s[a][b][lx-1][ry]:0)-(ly?s[a][b][rx][ly-1]:0)+(lx&&ly?s[a][b][lx-1][ly-1]:0))%mod;
							return ret;
						};
						// 0:(r>=k) 1: r<k 0:[1,r] 1:[r+1,m]
						// 0:[l,m]  1:[1,l-1]
						// L<=r,R>=l
						if(a==0&&b==0)upd(dp[i][l][r][a|0][b|0],qry(l,r,l,r));
						if(a==0)upd(dp[i][l][r][a|0][b|1],qry(l,r,r+(b==0),m));
						if(b==0)upd(dp[i][l][r][a|1][b|0],qry(1,l-(a==0),l,r));
						upd(dp[i][l][r][a|1][b|1],qry(1,l-(a==0),r+(b==0),m));
					}
	}
	int ans=0;
//	printf("[%d]",dp[2][1][2][0][0]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			for(int k=j;k<=m;++k)
				for(int a=0;a<2;++a)
					for(int b=0;b<2;++b)
						ans=(ans+1ll*(n-i+1)*dp[i][j][k][a][b])%mod;
	ans=(ans%mod+mod)%mod;
	printf("%d",ans);
}