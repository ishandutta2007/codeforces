#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
int n;
vector<int> v[M];
LL L[M],R[M],dp[M],tl[M],tr[M];
void dfs(int x,int fa){
	LL sm=0;
	R[x]=0; dp[x]=0;
	for (int y:v[x]){
		dfs(y,x);
		R[x]+=R[y];
		dp[x]+=dp[y];
	}
	if (R[x]<tl[x]){
		dp[x]++;
		R[x]=tr[x]; 
	}
	R[x]=min(R[x],tr[x]);
}
void work(){
	n=read();
	F(i,1,n) v[i].clear();
	F(i,2,n) v[read()].pb(i);
	F(i,1,n) tl[i]=read(),tr[i]=read();
	dfs(1,0);
	cout<<dp[1]<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
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