#include<bits/stdc++.h>
#define vi vector<int>
#define pa pair<int,int>
#define N 200005
using namespace std;
vi tmp,e[N];
pa pre[N];
int dep[N],fa[N];
int vis[N],n,m,T;
void out(vi a){
	printf("%d ",a.size());
	for (int i=0;i<a.size();i++)
		printf("%d ",a[i]);
	puts("");
}
vi rev(vi a){
	if (!a.size()) return a;
	vi b; b.clear();
	for (int i=a.size()-1;i>=0;i--)
		b.push_back(a[i]);
	return b;
}
vi add(vi a,vi b){
	for (int i=0;i<b.size();i++)
		a.push_back(b[i]);
	return a;
}
vi work(int x,int y){
	vi a; a.clear();
	if (dep[x]<dep[y]) swap(x,y);
	for (;x!=y;x=fa[x]) a.push_back(x);
	a.push_back(y);
	return a;
}
void findans(int s1,int t1,int s2,int t2,int x){
	puts("YES");
	if (dep[s1]<dep[s2])
		swap(s1,s2),swap(t1,t2);
	if (dep[t1]>dep[t2])
		swap(s1,s2),swap(t1,t2);
	tmp=work(x,t2); out(tmp);
	tmp=rev(work(s2,x));
	tmp.push_back(t2); out(tmp);
	tmp=add(rev(work(s1,x)),rev(work(t2,t1)));
	out(tmp); exit(0);
}
void up(int S,int T){
	int x=S;
	for (;x!=T;){
		if (pre[x].first)
			findans(pre[x].first,pre[x].second,S,T,x);
		pre[x]=pa(S,T); x=fa[x];
	}
}
void dfs(int x,int f){
	vis[x]=++T; fa[x]=f;
	dep[x]=dep[f]+1;
	for (int i=-0;i<e[x].size();i++)
		if (e[x][i]!=f){
			if (!vis[e[x][i]]) dfs(e[x][i],x);
			else if (vis[e[x][i]]<vis[x]) up(x,e[x][i]);
		}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]) dfs(i,0);
	puts("NO");
}