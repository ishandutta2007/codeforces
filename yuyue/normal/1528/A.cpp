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
int L[M],R[M];
LL dp[M][2];
vector<int> v[M];
void dfs(int x,int fa){
	dp[x][0]=dp[x][1]=0;
	for (int y:v[x]){
		if (y^fa){
			dfs(y,x);
			dp[x][0]+=max(dp[y][0]+abs(L[x]-L[y]),dp[y][1]+abs(L[x]-R[y]));
			dp[x][1]+=max(dp[y][0]+abs(R[x]-L[y]),dp[y][1]+abs(R[x]-R[y]));
		} 
	}
	v[x].clear();
}
int n;
void work(){
	n=read();
	F(i,1,n) L[i]=read(),R[i]=read();
	F(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y);
		v[y].pb(x);	
	}
	dfs(1,0); 
	cout<<max(dp[1][0],dp[1][1])<<"\n";
}
int main(){
	int T=read();
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/