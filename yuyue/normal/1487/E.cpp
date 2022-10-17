#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10;
int m[10],n[10],a[5][M],p[5][M];
LL dp[5][M];
vector<int> v[5][M];
bool cmp3(int x,int y){
	return dp[3][x]==dp[3][y] ? x<y : dp[3][x]<dp[3][y] ;
}
bool cmp2(int x,int y){
	return dp[2][x]==dp[2][y] ? x<y : dp[2][x]<dp[2][y] ;
}
bool cmp1(int x,int y){
	return dp[1][x]==dp[1][y] ? x<y : dp[1][x]<dp[1][y] ;
}
bool cmp4(int x,int y){
	return dp[4][x]==dp[4][y] ? x<y : dp[4][x]<dp[4][y] ;
}
int main(){
	F(i,1,4) n[i]=read();
	F(i,1,4){
		F(j,1,n[i]){
			a[i][j]=read();
			p[i][j]=j;
		}
	}
	
	
	
	F(o,1,3){
		m[o]=read();
		F(i,1,m[o]){
			int x=read(),y=read();
			v[o][x].pb(y);
		}
	}
	
	
	
	
	ms(dp,1); LL inf=dp[0][0]; 
	F(i,1,n[4]) dp[4][i]=a[4][i];
	DF(i,3,1){
		if (i==3) sort(p[4]+1,p[4]+n[4]+1,cmp4);
		if (i==2) sort(p[3]+1,p[3]+n[3]+1,cmp3);
		if (i==1) sort(p[2]+1,p[2]+n[2]+1,cmp2);
		if (i==3) F(j,1,n[3]) sort(v[3][j].begin(),v[3][j].end(),cmp4);
		if (i==1) F(j,1,n[1]) sort(v[1][j].begin(),v[1][j].end(),cmp2);
		if (i==2) F(j,1,n[2]) sort(v[2][j].begin(),v[2][j].end(),cmp3);
		F(j,1,n[i]){
			int pos=1;
			for (auto y:v[i][j]){
				while (pos<=n[i+1] && p[i+1][pos]==y) pos++;
			}
			if (pos<=n[i+1]) dp[i][j]=dp[i+1][p[i+1][pos]]+a[i][j];
		}
	}
	LL ans=inf;
	F(i,1,n[1]) ans=min(ans,dp[1][i]);
	cout<<(ans>=inf ? -1 : ans);
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/