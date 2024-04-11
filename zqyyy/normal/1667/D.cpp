#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,a[N],fa[N];
vector<int>G[N];
bool ok;
void dfs(int x){
	int cnt[2]={0};
	for(int y:G[x])
		if(y^fa[x])fa[y]=x,dfs(y),cnt[a[y]]++;
	int to0=G[x].size()/2,to1=G[x].size()-to0;
	if(cnt[0]>to0 || cnt[1]>to1)ok=false;
	a[x]=cnt[1]<to1;
}
void solve(int x){
	vector<int>v[2];
	for(int y:G[x]){
		int z=y^fa[x]?y:x;
		v[a[z]].push_back(z);
	}
	for(int i=0,sz=G[x].size(),o=sz&1;i<sz;i++,o^=1){
		int y=v[o].back();v[o].pop_back();
		if(y==x)printf("%d %d\n",x,fa[x]);
		else solve(y);
	}
}
inline void clear(){
	for(int i=1;i<=n;i++)G[i].clear();
}
inline void work(){
	n=read(),ok=true;
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		G[x].push_back(y),G[y].push_back(x);
	}
	dfs(1);
	if(!ok){puts("NO");return;}
	puts("YES"),solve(1);
}
int main(){
	int test=read();
	while(test--)work(),clear();
	return 0;
}