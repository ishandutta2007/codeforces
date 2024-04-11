#include<bits/stdc++.h>
#pragma GCC optimize("Ofast") 
#pragma GCC target("avx,avx2,sse,sse2,sse3")

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
const int M=111;
int n,m,k,mod;
bool vis[M][M][M];
int dp[M][M][M];
int C[M][M]; 
LL fac[M];
void init(){
	F(i,0,n){
		C[i][0]=1;
		F(j,1,i){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	fac[0]=1;
	F(i,1,n) fac[i]=fac[i-1]*i%mod;
}
int dfs(int le,int x,int y){//len,nx,num
	
	if (!le) return (!y);
	if (le==1){
		if (x==1 && y==1) return 1;
		if (x!=1 && !y) return 1;
		return 0;
	}
	if (x==1){
		if (y==1) return fac[le];
		return 0;
	}
	if (y>le) return 0;
	if (x>le){
		if (!y) return fac[le]; 
		else return 0;
	}
	if (vis[le][x][y]) return dp[le][x][y];
	LL ret=0; vis[le][x][y]=1;
	F(i,0,le-1){
		F(l,max(0,y-le+i+1),min(y,i)){
			ret=(ret+1ll*dfs(i,x-1,l)*dfs(le-1-i,x-1,y-l)%mod*C[le-1][i])%mod;
		}
	}
//	if (x>le || y>le){
//		cout<<le<<" "<<x<<" "<<y<<" "<<ret<<"\n";
//	}
	return dp[le][x][y]=ret;
}
int main(){
	n=read(); m=read(); k=read(); mod=read(); init();
	
//	F(le,1,n){
//		
//	}
	cout<<dfs(n,m,k)%mod<<"\n";
//	cout<<dp[3][2][2]<<"   ???\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
100 10 20 1000000007
*/