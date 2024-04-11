#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
#define pii pair<int,int>
#define fi first
#define se second
const int N=2e5+7;
int n;
ll ans;
struct Trie{
	int tot,ch[N*30][2];
	inline void insert(int val){
		int x=0;
		for(int i=29;~i;i--){
			int c=val>>i&1;
			if(!ch[x][c])ch[x][c]=++tot;
			x=ch[x][c];
		}
	}
	int dfs(int x,int y,int d){
		if(d<0)return 0;
		int ans=2e9;
		if(ch[x][0] && ch[y][0])ans=min(ans,dfs(ch[x][0],ch[y][0],d-1));
		if(ch[x][1] && ch[y][1])ans=min(ans,dfs(ch[x][1],ch[y][1],d-1));
		if(ans<2e9)return ans;
		if(ch[x][0])return 1<<d|dfs(ch[x][0],ch[y][1],d-1);
		else return 1<<d|dfs(ch[x][1],ch[y][0],d-1);
	}
	inline void bfs(){
		queue<pii>q;q.push({0,30});
		while(!q.empty()){
			int x=q.front().fi,d=q.front().se;q.pop();
			if(!d)continue;
			if(ch[x][0] && ch[x][1])ans+=(1<<d-1)+dfs(ch[x][0],ch[x][1],d-2);
			if(ch[x][0])q.push({ch[x][0],d-1});
			if(ch[x][1])q.push({ch[x][1],d-1});
		}
	}
}T;
int main(){
	n=read();
	for(int i=1;i<=n;i++)T.insert(read());
	T.bfs();
	printf("%lld\n",ans);
	return 0;
}