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
const int M=5e5+10,inf=1e9;
vector<int> v[M];
int dp[M],n,de[M];
int q[M<<2];
bool vis[M];
void work(){
	int l=M,r=M-1;
	n=read();
	F(i,1,n) v[i].clear();
	F(i,1,n){
		int x=read();
		F(j,1,x){
			int y=read();
			v[y].pb(i);
		}
		de[i]=x;
		if (!de[i]){
			q[++r]=i;
			dp[i]=1;
		}
		else dp[i]=-inf;
		vis[i]=0;
	}
	int ans=0;
	while (l<=r){
		int x=q[l++];
		if (vis[x]) continue;
//		cout<<x<<"  vis \n";
		vis[x]=1; ans=max(ans,dp[x]);
		for (int y:v[x]){
			de[y]--;
			dp[y]=max(dp[y],dp[x]+(x>y)); 
			if (!de[y]){
				q[++r]=y;
			}
		}
	}
	F(i,1,n){
		if (!vis[i]){
			puts("-1");
			return ;
		}
	}
	cout<<ans<<"\n";
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
1
5
1 2
1 3
1 4
1 5
0
*/