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
const int M=4040;
int n,m,a[M],sz[M];
LL dp[M][M];
int solve(int l,int r){
	if (l>r) return 0;
	int x=l;
	F(i,l,r) if (a[i]<a[x]) x=i;
	int lc=solve(l,x-1),rc=solve(x+1,r);
	sz[x]=sz[lc]+sz[rc]+1;
	F(i,0,sz[lc]){
		F(j,0,sz[rc]){
			dp[x][i+j]=max(dp[x][i+j],dp[lc][i]+dp[rc][j]-1ll*2*i*j*a[x]);
		}
	}
	DF(i,sz[x]-1,0){
		dp[x][i+1]=max(dp[x][i+1],dp[x][i]+1ll*(m-2*i-1)*a[x]);
	}
	return x;
}
int main(){
	ms(dp,~1);
	dp[0][0]=0;
	n=read(); m=read();
	F(i,1,n) a[i]=read();
	int rt=solve(1,n);
//	cout<<dp[2][1]<<" "<<dp[1][2]<<"\n";
	cout<<dp[rt][m]<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
2 2
666 888
*/