#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int N=200005;
int n,ans;
struct Trie{
	int ch[N*30][2],tot,root;
	Trie(){
		tot=1,root=1;
	}
	void insert(int x){
		int now=1;
		for(int i=30;i>=0;i--){
			if(!ch[now][x>>i&1]) ch[now][x>>i&1]=(++tot);
			now=ch[now][x>>i&1];
		}
	}
	int find(int rt1,int rt2,int dep){
		if(dep<0) return 0;
		int a1=-1,a2=-1;
		if(ch[rt1][0]&&ch[rt2][0]) a1=find(ch[rt1][0],ch[rt2][0],dep-1);
		if(ch[rt1][1]&&ch[rt2][1]) a2=find(ch[rt1][1],ch[rt2][1],dep-1);
		if((~a1)&&(~a2)) return min(a1,a2);
		if(~a1) return a1;
		if(~a2) return a2;
		if(ch[rt1][0]&&ch[rt2][1]) a1=find(ch[rt1][0],ch[rt2][1],dep-1)+(1<<dep);
		if(ch[rt1][1]&&ch[rt2][0]) a2=find(ch[rt1][1],ch[rt2][0],dep-1)+(1<<dep);
		if((~a1)&&(~a2)) return min(a1,a2);
		if(~a1) return a1;
		if(~a2) return a2;
	}
}trie;

void dfs(int x,int dep){
	if(dep<0) return;
	if(trie.ch[x][0]&&trie.ch[x][1]) ans+=trie.find(trie.ch[x][0],trie.ch[x][1],dep-1)+(1<<dep);
	if(trie.ch[x][0]) dfs(trie.ch[x][0],dep-1);
	if(trie.ch[x][1]) dfs(trie.ch[x][1],dep-1);
}

signed main(){
// 	freopen("c.in","r",stdin);
// 	freopen("c.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		int x;scanf("%lld",&x);
		trie.insert(x);
	}
	dfs(trie.root,30);
	cout<<ans<<endl;
	return 0;
}