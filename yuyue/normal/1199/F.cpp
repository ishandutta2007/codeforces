#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=55;
int dp[M][M][M][M],n,inf;
char ch[M][M];
int solve(int x0,int y0,int x1,int y1){
	if (dp[x0][y0][x1][y1]!=inf) return dp[x0][y0][x1][y1];
	if (x0==x1 && y0==y1) return dp[x0][y0][x1][y1]=ch[x0][y0]=='#';
//	cout<<x0<<" "<<x1<<" "<<y0<<" "<<y1<<"\n";
	int ret= (x1-x0==y1-y0) ? x1-x0+1 : inf;
	F(i,x0,x1-1){
		ret=min(ret,solve(x0,y0,i,y1)+solve(i+1,y0,x1,y1));
	}
	F(i,y0,y1-1){
		ret=min(ret,solve(x0,y0,x1,i)+solve(x0,i+1,x1,y1));
	}
	return dp[x0][y0][x1][y1]=ret;
}
int main(){
	n=read();
	ms(dp,1); inf=dp[0][0][0][0];
	F(i,1,n){
		scanf("%s",ch[i]+1);
	}
	cout<<solve(1,1,n,n)<<"\n";	
//	cout<<dp[1][1][1][1]<<" "<<dp[4][1][4][1]<<"\n";

	return 0;
}