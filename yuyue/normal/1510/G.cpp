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
const int M=111;
int n,k;
vector<int> v[M];
int len[M],son[M];
void dfs(int x){
	len[x]=1; son[x]=0;
	for (int y:v[x]){
		dfs(y);
		len[x]=max(len[x],len[y]+1);
		if (len[y]>len[son[x]]) son[x]=y;
	}
}
bool vis[M];
vector<int> ans;
void ga(int x){
	k-=(!vis[x]);
	ans.pb(x);
	for (int y:v[x]){
		if (!vis[y] && k){
			ga(y);
			ans.pb(x);
		} 
	}
	for (int y:v[x]){
		if (vis[y]){
			ga(y);
		} 
	}
}
void work(){
	F(i,1,n) v[i].clear(); ms(vis,0);
	n=read(); k=read();
	F(i,2,n){
		int x=read();
		v[x].pb(i);
	}
	dfs(1);
	for (int x=1;x && k;x=son[x]){
		vis[x]=1; k--;
//		cout<<x<<" "<<k<<"\n";
		if (!k) break;
	}
	ans.clear();
	ga(1);
	cout<<SZ(ans)<<"\n";
	for (int x:ans) cout<<x<<" ";
	cout<<"\n";
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